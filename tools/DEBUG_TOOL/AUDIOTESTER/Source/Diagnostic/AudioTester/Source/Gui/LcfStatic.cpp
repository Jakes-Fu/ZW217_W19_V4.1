// LcfStatic.cpp : implementation file
//

#include "stdafx.h"
#include "audiotester.h"
#include "LcfStatic.h"
#include <math.h>
#include "ConvertFunc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLcfStatic

CLcfStatic::CLcfStatic()
{
	m_iYMax = 18;
    m_iYMin = -72;
	
    m_pBKBitmap = NULL;
    m_iXAxisLength = 0;
    m_iYAxisLength = 0;
    
    m_pOldBitmap = NULL;

	m_nF1fp = 0;
	m_nF2fp = 0;
	m_fF1g0 = 0.0;
	m_fF1g1 = 0.0;
	m_fF2g0 = 0.0;
	m_fF2g1 = 0.0;
	m_nLcfSw = 0;
	m_nFilterType = 0;
}

CLcfStatic::~CLcfStatic()
{
	m_pOldBitmap = NULL;
    m_pBKBitmap = NULL;
}


BEGIN_MESSAGE_MAP(CLcfStatic, CStatic)
	//{{AFX_MSG_MAP(CLcfStatic)
	ON_WM_PAINT()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLcfStatic message handlers

void CLcfStatic::OnPaint() 
{
//	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	m_dMaxXValue = CLcfStatic::m_nSampleRate / 2;
	CRect rect;
    this->GetClientRect( rect );
    m_ptOrg.x = rect.left + LEFT_EDGE_WITH;
    m_ptOrg.y = rect.bottom - BOTTOM_EDGE_WITH;
    CPaintDC paintdc(this);
    if(m_memDC.GetSafeHdc() != NULL)
    {
        paintdc.BitBlt(0,0,rect.Width(),rect.Height(),&m_memDC,0,0,SRCCOPY);
    }
    CClientDC dc( this );
    dc.SelectObject(this->GetFont());
	dc.FillSolidRect(&rect,RGB(0,0,0));
    DrawCoordinateAxis( &dc );
    DrawFreqCurves( &dc );
	
	// Do not call CStatic::OnPaint() for painting messages
}

void CLcfStatic::OnDestroy() 
{
	CStatic::OnDestroy();
	
	// TODO: Add your message handler code here
	if( m_pBKBitmap )
    {
        delete m_pBKBitmap;
        m_pBKBitmap = NULL;
    }
}

void CLcfStatic::EraseBK()
{   
    if(m_memDC.GetSafeHdc() == NULL)
    {
        CRect rect;
        this->GetClientRect( rect );
        rect.bottom += 6;
        rect.right += 6;
        
        CClientDC dc( this );
        m_memDC.CreateCompatibleDC(&dc);
        if((m_pBKBitmap = new CBitmap()) == NULL) return ;
        m_pBKBitmap->CreateCompatibleBitmap(&dc,rect.Width(),rect.Height());
        m_pOldBitmap = m_memDC.SelectObject(m_pBKBitmap);        
        m_memDC.SetBkMode(TRANSPARENT);
        //draw background 
        m_memDC.FillSolidRect(&rect,RGB(0,0,0));
    }    
    //force to call onpaint
    Invalidate(FALSE);  
}

void CLcfStatic::DrawFreqCurves(CClientDC* pDC)
{
	CalculateFreqGraphyData();

    CPen greenPen( PS_SOLID,0, RGB(0,0,255) );

    if( m_vAllLcfFreqItem.size() != 0 )
    {
        DrawFreqCurve( pDC,&greenPen,m_vAllLcfFreqItem );
    }
}

void CLcfStatic::DrawFreqCurve( CClientDC* pDC,CPen* pPen,const std::vector<FreqItem>& vAllFreqItems )
{
	CGdiObject* pOldPen = pDC->SelectObject( pPen );
    
    double dYScale = m_iYAxisLength / (m_iYMax - m_iYMin );    
    double dXScale = m_iXAxisLength / (log10(m_dMaxXValue) 
        -log10(m_dMinXValue)) ;
    
    int iSize = vAllFreqItems.size();
    
    if( iSize <=0 )
        return;
    double dYValue = vAllFreqItems[0].second ;
    dYValue -= m_iYMin;
    if( dYValue < 0.0 )
    {
        dYValue = 0.0;
    }
    else if( dYValue > m_iYMax - m_iYMin )
    {
        dYValue = m_iYMax - m_iYMin;
    }
    CPoint ptFirst((int)((vAllFreqItems[0].first -log10(m_dMinXValue) )* dXScale ), (int)(dYValue * dYScale)  );
    if( ptFirst.y < 0 )
    {
        ptFirst.y =  m_ptOrg.y;
    }
    ptFirst.x += m_ptOrg.x;
    ptFirst.y = m_ptOrg.y - ptFirst.y;
    pDC->MoveTo( ptFirst );
    for( int i=1; i<iSize; ++i )
    {              
        dYValue = vAllFreqItems[i].second;
        dYValue -= m_iYMin;
        
        if( dYValue < 0.0 )
        {
            dYValue = 0.0;
        }
        else if( dYValue >m_iYMax - m_iYMin )
        {
            dYValue = m_iYMax - m_iYMin;
        }
        
        CPoint ptSecond((int)((vAllFreqItems[i].first -log10(m_dMinXValue) )* dXScale) , (int)(dYValue * dYScale) );   
        
        ptSecond.x += m_ptOrg.x;
        ptSecond.y = m_ptOrg.y - ptSecond.y;
        
        if( ptSecond.y < m_ptYMaxScalePoint.y )
        {
            ptSecond.y = m_ptYMaxScalePoint.y ;
        }
        pDC->LineTo( ptSecond );
    }    
    pDC->SelectObject( pOldPen );
}

void CLcfStatic::DrawCoordinateAxis( CClientDC* pDC )
{
    CRect rect;
    this->GetClientRect( rect );
    pDC->MoveTo(m_ptOrg);
    CPoint ptLine( m_ptOrg );
    
    CBrush redBrush(RGB(255,0,0));
    CBrush* pOldBrush = pDC->SelectObject( &redBrush );
    //x axis
	CPen pen(PS_SOLID, 0, RGB(0,128,0));
	CGdiObject* pOldPen = pDC->SelectObject( &pen );
    ptLine.Offset(rect.right - RIGHT_EDGE_WITH - LEFT_EDGE_WITH ,0 );
    pDC->LineTo( ptLine );   
#define ARROW_X_LENGTH 15
#define ARROW_X_WIDTH 3
#define SCALE_X_OFFSET 5
#define SCALE_Y_OFFSET 5
#define SCALE_Y_COUNT 19
    // x arrow
    CPoint arrow[3];
    arrow[0] = ptLine;
    ptLine.Offset(-ARROW_X_LENGTH,-ARROW_X_WIDTH );
    arrow[1] = ptLine;
    ptLine.Offset(0,ARROW_X_WIDTH*2 );
    arrow[2] = ptLine;
    pDC->Polygon(arrow,3 );
    
    pDC->SetBkMode(TRANSPARENT);
    ptLine =arrow[0];
    ptLine.Offset(3,-8 );
	pDC->SetTextColor(RGB(192,0,0));
    pDC->TextOut(ptLine.x-10, ptLine.y+10, "Hz" );


    m_iXAxisLength = rect.right - RIGHT_EDGE_WITH - LEFT_EDGE_WITH - ARROW_X_LENGTH - SCALE_X_OFFSET;
    m_iYAxisLength = rect.bottom - BOTTOM_EDGE_WITH - TOP_EDGE_WITH - ARROW_X_LENGTH - SCALE_Y_OFFSET;
	
    CPoint xScale(m_ptOrg);

    CPen dotPen(PS_DOT,0,RGB(192,192,192));    
    pOldPen =  pDC->SelectObject( &dotPen );

    //draw text in x axis
    double dXScale = m_iXAxisLength / 
                    (log10(m_dMaxXValue) -log10(m_dMinXValue)) ;
	
    for( int i=0; i< X_SCALE_MODE_COUNT; ++i )
    {        
        int ix =  (int)(m_dXScale[i] * m_dMaxXValue + 0.5);
		int iXScale =0;
		iXScale = (int)((log10(ix) -log10( m_dMinXValue) ) * dXScale);
        
        xScale.x = m_ptOrg.x + iXScale;
		if(xScale.x < m_ptOrg.x)
		{
			xScale.x = m_ptOrg.x;
		}
        CPoint ptXTextPos( xScale );
        pDC->MoveTo( xScale );    

        ptXTextPos.Offset(8,5);
        
        CString strXText;
        strXText.Format(_T("%d"),ix);
		//
		LOGFONT logfont;
		HFONT hFont, hOldFont;
		strcpy((LPSTR)logfont.lfFaceName,(LPSTR)"Courier");   
		logfont.lfWeight=12;   
		logfont.lfWidth=6;   
		logfont.lfHeight=15;   
		logfont.lfEscapement=-900;   
		logfont.lfUnderline=FALSE;   
		logfont.lfItalic=FALSE;   
		logfont.lfStrikeOut=FALSE;   
		logfont.lfCharSet=GB2312_CHARSET;   
		CFont myFont;
		myFont.CreateFontIndirect(&logfont);   
		hFont = myFont;   
		
		hOldFont=(HFONT__ *)pDC->SelectObject(hFont);   
		CRect rtText(ptXTextPos.x,ptXTextPos.y,ptXTextPos.x+20,ptXTextPos.y+60);
		
		//
		pDC->SetTextColor(RGB(192,0,0));
        pDC->TextOut(ptXTextPos.x, ptXTextPos.y,strXText );
		pDC->SelectObject(hOldFont);

        CPoint ptDot(xScale);
        ptDot.Offset(0,(int)(-m_iYAxisLength-10));
        pDC->LineTo( ptDot );
        
        pDC->MoveTo( xScale );    
        pDC->LineTo( xScale.x,xScale.y - 5 );
        pDC->MoveTo( xScale );    
        pDC->LineTo( xScale.x,xScale.y + 5 ); 
    }   
     pDC->SelectObject( pOldPen );
	 pOldPen = pDC->SelectObject( &pen );
    
    //y axis
    ptLine = m_ptOrg;
    pDC->MoveTo( m_ptOrg );
    ptLine.Offset(0, -( rect.bottom - TOP_EDGE_WITH - BOTTOM_EDGE_WITH ) );
    pDC->LineTo( ptLine );

    //y Arrow
    arrow[0] = ptLine;
    ptLine.Offset(-3,15 );
    arrow[1] = ptLine;
    ptLine.Offset(6,0 );
    arrow[2] = ptLine;
    pDC->Polygon(arrow,3 );

    ptLine =arrow[0];
    ptLine.Offset(-8,-12 );
	pDC->SetTextColor(RGB(192,0,0));
    pDC->TextOut(ptLine.x, ptLine.y, "dB" );
    
    // text in y axis    
    xScale = m_ptOrg;
    double y = m_ptOrg.y;
    double dYValueStep = m_iYAxisLength / ((m_iYMax - m_iYMin)/3 -0.00000001);
    for( i=0; i<(m_iYMax - m_iYMin)/3 +1; ++i )
    {  
		if(i % 2 == 0)
		{
			pDC->MoveTo( xScale );    
			m_ptYMaxScalePoint= xScale;
			CGdiObject* pOldPen1 =  pDC->SelectObject( &dotPen );
			CPoint ptDot(xScale);
			ptDot.Offset((int)(m_iXAxisLength+10),0);
			pDC->LineTo( ptDot );
			pDC->SelectObject( pOldPen1 );
			
			pDC->MoveTo( xScale );
			pDC->LineTo( xScale.x -5 ,xScale.y );
			pDC->MoveTo( xScale );    
			pDC->LineTo( xScale.x + 5,xScale.y );
			
			CString strYValue;
			strYValue.Format(_T("%d"), (i*3)+m_iYMin );
			pDC->SetTextColor(RGB(192,0,0));
			pDC->TextOut(xScale.x-LEFT_EDGE_WITH, xScale.y-5 ,strYValue);
		}
		else
		{
			pDC->MoveTo( xScale );
			pDC->LineTo( xScale.x -3 ,xScale.y );
			pDC->MoveTo( xScale );    
			pDC->LineTo( xScale.x + 3,xScale.y );
		}
		
        y -= dYValueStep;
        xScale.y = (long)y;   
    }    
    pDC->SelectObject( pOldBrush );
}

double CLcfStatic::m_dMinXValue = 1;

double CLcfStatic::m_dXScale[X_SCALE_MODE_COUNT] =
{
	0.00004535, 0.000907, 0.00227,   0.004535 , 0.00907   , 0.01814   , 0.0272   , 0.0363   , 0.04535   , 0.11337   , 0.1814   , 0.2721   , 0.72564    , 1
};

void CLcfStatic::CalculateFreqGraphyData( int nXScaleCount /*=4410*/ )
{	
    double dx = pow( m_dMaxXValue / m_dMinXValue   , 1.0 / nXScaleCount );
    double x = m_dMinXValue;
	FILTER_LCF_CALC_PARA_T inputPara;
	memset(&inputPara, 0, sizeof(FILTER_LCF_CALC_PARA_T));
	inputPara.isFilterOn = (BOOL)m_nLcfSw;
	inputPara.eLcfParaType = (FILTER_LCFPARA_TYPE_E)m_nFilterType;
	if(inputPara.eLcfParaType == FILTER_LCFPARA_F1F1)
	{
		inputPara.unlcfPara.lcfPara.f1_fp = m_nF1fp;
		inputPara.unlcfPara.lcfPara.f1_g0 = m_fF1g0*10;
		inputPara.unlcfPara.lcfPara.f1_g1 = m_fF1g1*10;
		inputPara.unlcfPara.lcfPara.f2_fp = m_nF2fp;
		inputPara.unlcfPara.lcfPara.f2_g0 = m_fF2g0*10;
		inputPara.unlcfPara.lcfPara.f2_g1 = m_fF2g1*10;
		
	}
	else
	{
		inputPara.unlcfPara.fp = m_nFp;
	}
	
	IIR_FILTER_PARA_T filter_para_lcf;
	memset(&filter_para_lcf, 0, sizeof(IIR_FILTER_PARA_T));
	SHORT sgain = 0;
	Filter_CalcLCF_Para(&inputPara, m_nSampleRate, &filter_para_lcf, &sgain);
	m_vAllLcfFreqItem.clear();
    for( int i=0;i<nXScaleCount;i++ )
    {
        FreqItem tempItem;
        double treble   , bass   , lcf = 0;
		tempItem.first = log10(x);
		
		
		lcf = ::CalcFrequencyResponse(filter_para_lcf.A0,
			filter_para_lcf.A1,
			filter_para_lcf.A2,
			filter_para_lcf.B0,
			filter_para_lcf.B1,
			filter_para_lcf.B2,
			x,
			sgain);
        
        tempItem.second = lcf;
        m_vAllLcfFreqItem.push_back( tempItem );
		
        x *= dx;
    }
}

void CLcfStatic::SetValue(SHORT nF1fp, SHORT nF2fp, float fF1g0, float fF1g1, float fF2g0, float fF2g1, int nLcfSw, int nFiltertype, int nFp)
{
	m_nF1fp = nF1fp;
	m_nF2fp = nF2fp;
	m_fF1g0 = fF1g0;
	m_fF1g1 = fF1g1;
	m_fF2g0 = fF2g0;
	m_fF2g1 = fF2g1;
	m_nLcfSw = nLcfSw;
	m_nFilterType = nFiltertype;
	m_nFp = nFp;
}