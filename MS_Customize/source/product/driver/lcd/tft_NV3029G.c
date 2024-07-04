/******************************************************************************
 ** File Name:     tft_NV3029G.c                                             *
 ** Description:															  *
 **    This file contains driver for color LCD.(CSTN)						  *
 ** Author:         sky.wang                                                 *
 ** DATE:           20/07/2018                                                *
 ** Copyright:      2004 Spreatrum, Incoporated. All Rights Reserved.         *
 ** Description:                                                              *
 ******************************************************************************

 ******************************************************************************
 **                        Edit History                                       *
 ** ------------------------------------------------------------------------- *
 ** DATE           NAME             DESCRIPTION                               *
 ** 02/102010      lichd    	    Create.
 ******************************************************************************/

#include "ms_customize_trc.h"
#include "os_api.h"
#include "dal_lcd.h"
#include "lcd_cfg.h"
#include "lcm_drvapi.h"
#include "spi_drvapi.h"
#include "timer_drvapi.h"

#include "hal_gouda.h"
#include "ldo_drvapi.h"
#include "lcm_cfg.h"

/**---------------------------------------------------------------------------*
 **                            Macro Define
 **---------------------------------------------------------------------------*/

#ifdef   __cplusplus
    extern   "C" 
    {
#endif

#define SCI_TraceLow_Test SCI_TraceLow

LOCAL uint16 nv3029g_line_mode = 0;
LOCAL uint16 nv3029g_farmk = 0;


/*lint -save -e767 -e718*/
//#define LCD_CtrlWrite_NV3029G( _cmd ) LCD_SendCmd( (_cmd ), 0 );

//#define LCD_DataWrite_NV3029G( _data ) LCD_SendData( (_data), 0 );



#define LCM_WR_REG(Addr, Data)                              \
    {                                                       \
        while (hal_GoudaWriteReg(Addr, Data) != HAL_ERR_NO) \
            ;                                               \
    }
#define LCD_DataWrite_NV3029G(Data)                               \
    {                                                  \
        while (hal_GoudaWriteData(Data) != HAL_ERR_NO) \
            ;                                          \
    }
#define LCD_CtrlWrite_NV3029G(Cmd)                              \
    {                                                \
        while (hal_GoudaWriteCmd(Cmd) != HAL_ERR_NO) \
            ;                                        \
    }

//#define LCD_CtrlData_NV3029G(cmd, data)  LCD_CtrlWrite_NV3029G( cmd ); LCD_DataWrite_NV3029G( data );

/*lint -restore*/

#ifdef CHIP_ENDIAN_LITTLE
typedef union {
	struct {
		unsigned int resv   :2;
		unsigned int mh    :1;	// display data latch order
		unsigned int rgb    :1;	// rgb order
		unsigned int ml    :1;		// line address order
		unsigned int mv    :1;	// x/y exchanged
		unsigned int mx    :1;	// horizontal mirror
		unsigned int my    :1;	// vertical mirror 
	} bitsval;
	unsigned int dataval;
} MEM_DATA_ACCESS_CTRL_U;
#else
typedef union {
	struct {
		unsigned int my    :1;	// vertical mirror 
		unsigned int mx    :1;	// horizontal mirror
		unsigned int mv    :1;	// x/y exchanged
		unsigned int ml    :1;		// line address order
		unsigned int rgb    :1;	// rgb order
		unsigned int mh    :1;	// display data latch order
		unsigned int resv   :2;
	} bitsval;
	unsigned int dataval;
} MEM_DATA_ACCESS_CTRL_U;
#endif // CHIP_ENDIAN_LITTLE

extern void hal_LcdDelay (int ms_delay);

LOCAL MEM_DATA_ACCESS_CTRL_U s_lcd_madc;

extern void hal_GoudatResetLcdPin(void);

/******************************************************************************/
//  Description:   Close the lcd.(include sub lcd.)
//	Global resource dependence: 
//  Author:         Jim.zhang
//	Note:
/******************************************************************************/
LOCAL void NV3029G_Close(void);

/******************************************************************************/
//  Description:   Enter/Exit sleep mode .
//	Global resource dependence: 
//  Author:         Jim.zhang
//	Note:
/******************************************************************************/
LOCAL ERR_LCD_E  NV3029G_EnterSleep(BOOLEAN is_sleep);

/*********************************************************************/
//  Description:   Initialize color LCD : GC9304
//  Input:
//      None.
//  Return:
//      None.
//	Note:           
/*********************************************************************/
LOCAL ERR_LCD_E NV3029G_Init(void);

LOCAL ERR_LCD_E NV3029G_Invalidate(void);
/******************************************************************************/
//  Description:   Copy a retangle data from clcd_buffer to display RAM.
//                     then the rectangle display is to be refreshed
//	Global resource dependence: 
//  Author:         Jim.zhang
//	Note:       
//     To improve speed, lcd is operate in HIGH SPEED RAM WRITE MODE(4
//     uint16 are write continuously always.) So, some dummy uint16 
//     should be inserted to satisfy this mode.   Please refer to spec.
/******************************************************************************/
LOCAL ERR_LCD_E NV3029G_InvalidateRect(
    uint16 left, //the left value of the rectangel
    uint16 top, //top of the rectangle
    uint16 right, //right of the rectangle
    uint16 bottom //bottom of the rectangle
    );

/******************************************************************************/
//  Description:   Set the windows address to display, in this windows
//                 color is  refreshed.
//	Global resource dependence: 
//  Author:         Jim.zhang
//	Note:
/******************************************************************************/
LOCAL void NV3029G_set_display_window(
    uint16 left, // start Horizon address
    uint16 right, // end Horizon address
    uint16 top, // start Vertical address
    uint16 bottom // end Vertical address
    );

LOCAL uint32 NV3029G_ReadID(uint16 lcd_cs, uint16 lcd_cd, uint16 lcd_id);

/**---------------------------------------------------------------------------*
 **                      Function  Definitions
 **---------------------------------------------------------------------------*/
LOCAL void NV3029G_Reset(void)
{
    hal_GoudatResetLcdPin();
    hal_LcdDelay(120);
}

LOCAL ERR_LCD_E NV3029G_SetDirection(LCD_DIRECT_E direct_type)
{
   //gouda_event(0x90001101);
    //SCI_TraceLow_Test("NV3029G_SetDirection = %d",direct_type);

    switch(direct_type)
    {
        case LCD_DIRECT_NORMAL:
            s_lcd_madc.bitsval.mx = 0;
            s_lcd_madc.bitsval.my = 0;
            s_lcd_madc.bitsval.mv = 0;
            break;
        case LCD_DIRECT_ROT_90:
            s_lcd_madc.bitsval.mx = 1;
            s_lcd_madc.bitsval.my = 0;
            s_lcd_madc.bitsval.mv = 1;
            break;
        case LCD_DIRECT_ROT_180:
            s_lcd_madc.bitsval.mx = 1;
            s_lcd_madc.bitsval.my = 1;
            s_lcd_madc.bitsval.mv = 0;
            break;
        case LCD_DIRECT_ROT_270:
            s_lcd_madc.bitsval.mx = 0;
            s_lcd_madc.bitsval.my = 1;
            s_lcd_madc.bitsval.mv = 1;
            break;
        case LCD_DIRECT_MIR_H:
            s_lcd_madc.bitsval.mx = 1;
            s_lcd_madc.bitsval.my = 0;
            s_lcd_madc.bitsval.mv = 0;
            break;
        case LCD_DIRECT_MIR_V:
            s_lcd_madc.bitsval.mx = 0;
            s_lcd_madc.bitsval.my = 1;
            s_lcd_madc.bitsval.mv = 0;
            break;
        case LCD_DIRECT_MIR_HV:
            s_lcd_madc.bitsval.mx = 1;
            s_lcd_madc.bitsval.my = 1;
            s_lcd_madc.bitsval.mv = 0;
            break;
        default:
            s_lcd_madc.bitsval.mx = 0;
            s_lcd_madc.bitsval.my = 0;
            s_lcd_madc.bitsval.mv = 0;
            break;
    }

    s_lcd_madc.bitsval.mx = ~s_lcd_madc.bitsval.mx;
    s_lcd_madc.bitsval.rgb = 1;
    LCD_CtrlWrite_NV3029G(0x36);
    LCD_DataWrite_NV3029G(s_lcd_madc.dataval);
    LCD_CtrlWrite_NV3029G(0x2c);
    return ERR_LCD_NONE;

}

/******************************************************************************/
//  Description:   Set the windows address to display, in this windows
//                 color is  refreshed.
//	Global resource dependence: 
//	Note:
/******************************************************************************/
LOCAL void NV3029G_set_display_window(
    uint16 left, // start Horizon address
    uint16 top, // start Vertical address
    uint16 right, // end Horizon address
    uint16 bottom // end Vertical address
    )
{   
    uint16 newleft   = left;
    uint16 newtop    = top;
    uint16 newright  = right;
    uint16 newbottom = bottom;
    ////SCI_TraceLow_Test("lcd: [DRV_LCD]NV3029G_set_display_window L = %d, top = %d, R = %d, bottom = %d",left,top,right,bottom);
   //gouda_event(0x90001102);
//hal_GoudaChangeSerialMode(HAL_GOUDA_SPI_LINE_3);
    LCD_CtrlWrite_NV3029G(0x2a);	// set hori start , end (left, right)
    LCD_DataWrite_NV3029G((newleft>>8)&0xff); // left high 8 b
    LCD_DataWrite_NV3029G(newleft&0xff); // left low 8 b
    LCD_DataWrite_NV3029G((newright>>8)&0xff); // right high 8 b
    LCD_DataWrite_NV3029G(newright&0xff); // right low 8 b

    LCD_CtrlWrite_NV3029G(0x2b);	// set vert start , end (top, bot)
    LCD_DataWrite_NV3029G((newtop>>8)&0xff); // top high 8 b
    LCD_DataWrite_NV3029G(newtop&0xff); // top low 8 b
    LCD_DataWrite_NV3029G((newbottom>>8)&0xff); // bot high 8 b
    LCD_DataWrite_NV3029G(newbottom&0xff); // bot low 8 b
    LCD_CtrlWrite_NV3029G(0x2c);	 // recover memory write mode
//hal_GoudaChangeSerialMode(HAL_GOUDA_SPI_LINE_3_2_LANE);

}

LOCAL void NV3029G_clear_all_window(void)
{   
    uint16 i = 0;
    uint16 j = 0;
    NV3029G_set_display_window(0,0,239,319);
    for(i = 0; i < 320; i++)
    {
        for(j = 0; j < 240; j++)
        {
            LCD_DataWrite_NV3029G(0);
        }
    }
}
/**************************************************************************************/
// Description: initialize all LCD with LCDC MCU MODE and LCDC mcu mode
// Global resource dependence:
// Author: Jianping.wang
// Note:
/**************************************************************************************/

LOCAL ERR_LCD_E NV3029G_Init(void)
{
    uint16 i = 0;
#if 0
    hal_LcdDelay(120);
    LCD_CtrlWrite_NV3029G(0x11);
    hal_LcdDelay(120); //Delay 120ms
    //------------------------------display and color format setting--------------------------------//
    LCD_CtrlWrite_NV3029G(0x36);
    LCD_DataWrite_NV3029G(0x00);
#if defined(MAIN_LCD_18BIT_MODE)    
    LCD_CtrlWrite_NV3029G(0x3a);
    LCD_DataWrite_NV3029G(0x66);
#else
    LCD_CtrlWrite_NV3029G(0x3a);
    LCD_DataWrite_NV3029G(0x55);
#endif

    LCD_CtrlWrite_NV3029G(0x35);
    LCD_DataWrite_NV3029G(0x00);
	 LCD_CtrlWrite_NV3029G(0x44);
    LCD_DataWrite_NV3029G(0x00);
     LCD_DataWrite_NV3029G(0x20);
	 
    LCD_CtrlWrite_NV3029G(0xc7);
    LCD_DataWrite_NV3029G(0x00);   
    
    LCD_CtrlWrite_NV3029G(0xcc);
    LCD_DataWrite_NV3029G(0x09);     
    //--------------------------------NV3029G Frame rate setting----------------------------------//
    LCD_CtrlWrite_NV3029G(0xb2);
    LCD_DataWrite_NV3029G(0x0c);
    LCD_DataWrite_NV3029G(0x0c);
    LCD_DataWrite_NV3029G(0x00);
    LCD_DataWrite_NV3029G(0x33);
    LCD_DataWrite_NV3029G(0x33);
    LCD_CtrlWrite_NV3029G(0xb7);
    LCD_DataWrite_NV3029G(0x35);
    //---------------------------------NV3029G Power setting--------------------------------------//
    LCD_CtrlWrite_NV3029G(0xbb);
    LCD_DataWrite_NV3029G(0x25); ///0x36 
	//aa++;
	
    LCD_CtrlWrite_NV3029G(0xc0);
    LCD_DataWrite_NV3029G(0x2c);

    LCD_CtrlWrite_NV3029G(0xc2);
    LCD_DataWrite_NV3029G(0x01);

    LCD_CtrlWrite_NV3029G(0xc3);
    LCD_DataWrite_NV3029G(0x0d);

    LCD_CtrlWrite_NV3029G(0xc4);
    LCD_DataWrite_NV3029G(0x20);

    LCD_CtrlWrite_NV3029G(0xc6);
    LCD_DataWrite_NV3029G(0x0f);

    LCD_CtrlWrite_NV3029G(0xd0);
    LCD_DataWrite_NV3029G(0xa4);//0xa4
   // power += 1;
    LCD_DataWrite_NV3029G(0xa1);//0xa1

    //--------------------------------NV3029G gamma setting---------------------------------------//
    LCD_CtrlWrite_NV3029G(0xe0);
    LCD_DataWrite_NV3029G(0xd0);
    LCD_DataWrite_NV3029G(0x17);
    LCD_DataWrite_NV3029G(0x19);
    LCD_DataWrite_NV3029G(0x04);
    LCD_DataWrite_NV3029G(0x03);
    LCD_DataWrite_NV3029G(0x04);
    LCD_DataWrite_NV3029G(0x32);
    LCD_DataWrite_NV3029G(0x41);
    LCD_DataWrite_NV3029G(0x43);
    LCD_DataWrite_NV3029G(0x09);
    LCD_DataWrite_NV3029G(0x14);
    LCD_DataWrite_NV3029G(0x12);
    LCD_DataWrite_NV3029G(0x33);
    LCD_DataWrite_NV3029G(0x2c);

    LCD_CtrlWrite_NV3029G(0xe1);
    LCD_DataWrite_NV3029G(0xd0);
    LCD_DataWrite_NV3029G(0x18);
    LCD_DataWrite_NV3029G(0x17);
    LCD_DataWrite_NV3029G(0x04);
    LCD_DataWrite_NV3029G(0x03);
    LCD_DataWrite_NV3029G(0x04);
    LCD_DataWrite_NV3029G(0x31);
    LCD_DataWrite_NV3029G(0x46);
    LCD_DataWrite_NV3029G(0x43);
    LCD_DataWrite_NV3029G(0x09);
    LCD_DataWrite_NV3029G(0x14);
    LCD_DataWrite_NV3029G(0x13);
    LCD_DataWrite_NV3029G(0x31);
    LCD_DataWrite_NV3029G(0x2d);
    
	//ENABLE_LCD_SERIAL0_2PIN;
	//SET_LCD_SERIAL0_IF_2PIN_SIZE(LCD_SCNF_IF_2PIN_WIDTH_16);

   // LCD_CtrlWrite_NV3029G(0x2C);
   // LCD_ClearAll_NV3029G(0);
  //  hal_LcdDelay(30);
  
    LCD_CtrlWrite_NV3029G(0xe7); //2 data lane interface enable
    LCD_DataWrite_NV3029G(0x10); // 0x10


    LCD_CtrlWrite_NV3029G(0x29);
    hal_LcdDelay(120);
    LCD_CtrlWrite_NV3029G(0x2C);
    NV3029G_clear_all_window();
#else
    hal_LcdDelay(120);
    //----------------Star Initial Sequence-------//
    LCD_CtrlWrite_NV3029G(0x01);
    hal_LcdDelay(300);
    LCD_CtrlWrite_NV3029G(0xfd); //enter
    LCD_DataWrite_NV3029G(0x06);
    LCD_DataWrite_NV3029G(0x07);
    LCD_CtrlWrite_NV3029G(0x66);
    LCD_DataWrite_NV3029G(0x80);
    LCD_CtrlWrite_NV3029G(0x80);
    LCD_DataWrite_NV3029G(0x05);
    hal_LcdDelay(5);
    LCD_CtrlWrite_NV3029G(0x80);
    LCD_DataWrite_NV3029G(0x01);
    hal_LcdDelay(100);
    LCD_CtrlWrite_NV3029G(0xb6);
    LCD_DataWrite_NV3029G(0x02);//rev,gs,ss,sm
    LCD_DataWrite_NV3029G(0xa2);
    LCD_CtrlWrite_NV3029G(0x60);
    LCD_DataWrite_NV3029G(0x26);//vrh
    LCD_CtrlWrite_NV3029G(0x63);
    LCD_DataWrite_NV3029G(0x08);
    LCD_CtrlWrite_NV3029G(0x64);
    LCD_DataWrite_NV3029G(0x0c);
    LCD_CtrlWrite_NV3029G(0x68);
    LCD_DataWrite_NV3029G(0x70);
    LCD_CtrlWrite_NV3029G(0x69);
    LCD_DataWrite_NV3029G(0x1f);
    LCD_CtrlWrite_NV3029G(0x6a);
    LCD_DataWrite_NV3029G(0xc4);
    LCD_CtrlWrite_NV3029G(0x6b); //VCM5-0
    LCD_DataWrite_NV3029G(0x15); //0x28 2C 1E
    LCD_CtrlWrite_NV3029G(0x6c); //VDV4-0
    LCD_DataWrite_NV3029G(0x1a);
    LCD_CtrlWrite_NV3029G(0x6d);
    LCD_DataWrite_NV3029G(0x77);
    LCD_CtrlWrite_NV3029G(0x6e);
    LCD_DataWrite_NV3029G(0x84);
    LCD_CtrlWrite_NV3029G(0x6f);
    LCD_DataWrite_NV3029G(0x48);
    LCD_CtrlWrite_NV3029G(0xf7); //frc_en
    LCD_DataWrite_NV3029G(0x10);
    LCD_CtrlWrite_NV3029G(0x70);
    LCD_DataWrite_NV3029G(0x44);
    LCD_CtrlWrite_NV3029G(0x71);
    LCD_DataWrite_NV3029G(0x05);
    LCD_CtrlWrite_NV3029G(0xed);
    LCD_DataWrite_NV3029G(0xf9);
    LCD_DataWrite_NV3029G(0xf9);
    LCD_DataWrite_NV3029G(0x00);
    LCD_DataWrite_NV3029G(0x00);
    LCD_DataWrite_NV3029G(0x11);
    LCD_DataWrite_NV3029G(0x00);
    LCD_CtrlWrite_NV3029G(0xe0); //gmama set 2.4
    LCD_DataWrite_NV3029G(0x10); //PKP0[4:0]
    LCD_DataWrite_NV3029G(0x19); //PKP1[4:0]
    LCD_DataWrite_NV3029G(0x0d); //PKP2[4:0]
    LCD_DataWrite_NV3029G(0x1a); //PKP3[4:0]
    LCD_DataWrite_NV3029G(0x07); //PKP4[4:0]
    LCD_DataWrite_NV3029G(0x13); //PKP5[4:0]
    LCD_DataWrite_NV3029G(0x14); //PKP6[4:0]
    LCD_CtrlWrite_NV3029G(0xe1);
    LCD_DataWrite_NV3029G(0x2b); //PRP0[6:0]
    LCD_DataWrite_NV3029G(0x5f); //PRP1[6:0]
    LCD_CtrlWrite_NV3029G(0xe2);
    LCD_DataWrite_NV3029G(0x1b); //VRP0[5:0]
    LCD_DataWrite_NV3029G(0x28); //VRP1[5:0]
    LCD_DataWrite_NV3029G(0x28); //VRP2[5:0]
    LCD_DataWrite_NV3029G(0x18); //VRP3[5:0]
    LCD_DataWrite_NV3029G(0x15); //VRP4[5:0]
    LCD_DataWrite_NV3029G(0x17); //VRP5[5:0]
    LCD_CtrlWrite_NV3029G(0xe3);
    LCD_DataWrite_NV3029G(0x10); //PKN0[4:0]
    LCD_DataWrite_NV3029G(0x17); //PKN1[4:0]
    LCD_DataWrite_NV3029G(0x05); //PKN2[4:0]
    LCD_DataWrite_NV3029G(0x13); //PKN3[4:0]
    LCD_DataWrite_NV3029G(0x08); //PKN4[4:0]
    LCD_DataWrite_NV3029G(0x13); //PKN5[4:0]
    LCD_DataWrite_NV3029G(0x06); //PKN6[4:0]
    LCD_CtrlWrite_NV3029G(0xe4);
    LCD_DataWrite_NV3029G(0x0b); //PRN0[6:0]
    LCD_DataWrite_NV3029G(0x50); //PRN1[6:0]
    LCD_CtrlWrite_NV3029G(0xe5);
    LCD_DataWrite_NV3029G(0x17); //VRN0[5:0]
    LCD_DataWrite_NV3029G(0x24); //VRN1[5:0]
    LCD_DataWrite_NV3029G(0x15); //VRN2[5:0]
    LCD_DataWrite_NV3029G(0x17); //VRN3[5:0]
    LCD_DataWrite_NV3029G(0x17); //VRN4[5:0]
    LCD_DataWrite_NV3029G(0x1f); //VRN5[5:0]
    LCD_CtrlWrite_NV3029G(0x66); //OSC trim
    LCD_DataWrite_NV3029G(0x9c);
    LCD_CtrlWrite_NV3029G(0x67); //i_trim
    LCD_DataWrite_NV3029G(0x07);
    LCD_CtrlWrite_NV3029G(0xb1); //frame rate
    LCD_DataWrite_NV3029G(0x00);
    LCD_DataWrite_NV3029G(0x12);
    LCD_CtrlWrite_NV3029G(0xec);
    LCD_DataWrite_NV3029G(0x33);
    LCD_DataWrite_NV3029G(0x11);
    LCD_DataWrite_NV3029G(0x11);
    LCD_DataWrite_NV3029G(0x00);
    LCD_DataWrite_NV3029G(0x18);
    LCD_DataWrite_NV3029G(0x18);
    LCD_CtrlWrite_NV3029G(0xf6);
    LCD_DataWrite_NV3029G(0x01);
    LCD_DataWrite_NV3029G(0x10);
    LCD_DataWrite_NV3029G(0x00); //0x80 2-lane
    LCD_CtrlWrite_NV3029G(0xfd); //exit
    LCD_DataWrite_NV3029G(0xfa);
    LCD_DataWrite_NV3029G(0xfb);
    LCD_CtrlWrite_NV3029G(0x11); // exit sleep
    hal_LcdDelay(300);
    LCD_CtrlWrite_NV3029G(0x36);
    LCD_DataWrite_NV3029G(0x08); //0x08
    LCD_CtrlWrite_NV3029G(0x3a);
    LCD_DataWrite_NV3029G(0x65);
    LCD_CtrlWrite_NV3029G(0x29); // display on
    hal_LcdDelay(120);
    LCD_CtrlWrite_NV3029G(0x2C);
#endif

	return ERR_LCD_NONE;
}


/******************************************************************************/
//  Description:   Enter/Exit sleep mode .
//	Global resource dependence: 
//  Author:         Jim.zhang
//	Note:
/******************************************************************************/
LOCAL ERR_LCD_E  NV3029G_EnterSleep(
    BOOLEAN is_sleep //SCI_TRUE: enter sleep mode;SCI_FALSE:exit sleep mode.
    )
{
     //SCI_TraceLow("lcd: NV3029G_EnterSleep, is_sleep = %d", is_sleep);
   //gouda_event(0x90001104);

    if(is_sleep)
    {
        //gouda_event(0x900f2dc4);
        LCD_CtrlWrite_NV3029G(0x28); //display off
        hal_LcdDelay(20);
        LCD_CtrlWrite_NV3029G(0x10); // enter sleep mode
        hal_LcdDelay(120);
        //_GoudaClkDisable();
       //  LDO_TurnOffLDO(LDO_LDO_LCD);
        
    }
    else
    {
        //gouda_event(0x9f0f2dd4);
#if 0
        hal_LcdDelay(10);
        LCD_CtrlWrite_NV3029G(0x11); // sleep out mode
        hal_LcdDelay(20);
        LCD_CtrlWrite_NV3029G(0x29); // display on
        hal_LcdDelay(10);
#else
        NV3029G_Init();
#endif
    }

    return ERR_LCD_NONE;
}

/******************************************************************************/
//  Description:   Close the lcd.(include sub lcd.)
//	Global resource dependence: 
//  Author:         Jim.zhang
//	Note:
/******************************************************************************/
LOCAL void NV3029G_Close(void)
{
     //SCI_TraceLow("lcd: LCD: in GC9304_Close");
	   //gouda_event(0x90001105);

    NV3029G_EnterSleep( SCI_TRUE );
}

/******************************************************************************/
//  Description:   invalidate a rectang of in LCD
//	Global resource dependence: 
//  Author:         Jim.zhang
//	Note:
/******************************************************************************/
LOCAL ERR_LCD_E NV3029G_Invalidate(void)
{
   //gouda_event(0x90001106);

    NV3029G_set_display_window (0x0, 0x0, LCD_WIDTH - 1, LCD_HEIGHT -1);
    return ERR_LCD_NONE;
}

/******************************************************************************/
//  Description:   Copy a retangle data from clcd_buffer to display RAM.
//                     then the rectangle display is to be refreshed
//	Global resource dependence: 
//  Author:         Jim.zhang
//	Note:       
//     To improve speed, lcd is operate in HIGH SPEED RAM WRITE MODE(4
//     uint16 are write continuously always.) So, some dummy uint16 
//     should be inserted to satisfy this mode.   Please refer to spec.
/******************************************************************************/
PUBLIC ERR_LCD_E NV3029G_InvalidateRect(
    uint16 left, //the left value of the rectangel
    uint16 top, //top of the rectangle
    uint16 right, //right of the rectangle
    uint16 bottom //bottom of the rectangle
    )
{
   //gouda_event(0x90001107);

    left = (left >=LCD_WIDTH) ? LCD_WIDTH-1 : left;
    right = (right >= LCD_WIDTH) ? LCD_WIDTH-1 : right;
    top = (top >= LCD_HEIGHT) ? LCD_HEIGHT-1 : top;
    bottom = (bottom >= LCD_HEIGHT) ? LCD_HEIGHT-1 : bottom;

    if ( ( right < left ) || ( bottom < top ) )
    {
        return ERR_LCD_OPERATE_FAIL;
    }     

    NV3029G_set_display_window(left, top, right, bottom);
    return ERR_LCD_NONE;
}

LOCAL ERR_LCD_E NV3029G_RotationInvalidateRect(uint16 left,uint16 top,uint16 right,uint16 bottom,LCD_ANGLE_E angle)
{
   //gouda_event(0x90001108);

    //SCI_TraceLow_Test(" NV3029G_RotationInvalidateRect");
    switch(angle)
    {
        case LCD_ANGLE_0:
            NV3029G_set_display_window(left, top, right, bottom);
            break;
        case LCD_ANGLE_90:
            NV3029G_set_display_window(left, top, bottom,right);
            break;
        case LCD_ANGLE_180:
            NV3029G_set_display_window(left, top, right, bottom);
            break;
        case LCD_ANGLE_270:
            NV3029G_set_display_window(left, top, bottom,right);
            break;
        default:
            NV3029G_set_display_window(left, top, right, bottom);
            break;
    }
    return ERR_LCD_NONE;
}

LOCAL ERR_LCD_E   NV3029G_SetContrast(uint16  contrast)
{
   //gouda_event(0x90001109);

    //SCI_TraceLow_Test(" NV3029G_SetContrast");
    return ERR_LCD_FUNC_NOT_SUPPORT;
} 
/*****************************************************************************/
LOCAL ERR_LCD_E   NV3029G_SetBrightness(uint16 brightness)
{
    //SCI_TraceLow_Test(" NV3029G_SetBrightness");
	   //gouda_event(0x9000110a);

    return ERR_LCD_FUNC_NOT_SUPPORT;
}

//  Description:    Enable lcd to partial display mode, so can save power.
//	Global resource dependence: 
//  Author:         Jim.zhang
//  Return:         SCI_TRUE:SUCCESS ,SCI_FALSE:failed.
//	Note:           If all input parameters are 0, exit partial display mode.
/*****************************************************************************/
LOCAL ERR_LCD_E NV3029G_SetDisplayWindow(
    uint16 left, //left of the window
    uint16 top, //top of the window
    uint16 right, //right of the window
    uint16 bottom //bottom of the window
    )
{
   //gouda_event(0x9000110b);

    //SCI_TraceLow_Test(" NV3029G_SetDisplayWindow");
    NV3029G_set_display_window(left, top, right, bottom);
    return ERR_LCD_NONE;
}

LOCAL void NV3029G_InvalidatePixel(uint16 x, uint16 y, uint32 data)
{
    //SCI_TraceLow_Test(" NV3029G_InvalidatePixel");
	   //gouda_event(0x9000110c);

    NV3029G_InvalidateRect(x,y,x,y);
    LCD_DataWrite_NV3029G(data);
}

LOCAL void NV3029G_GetConfig(void)
{
	uint32 count,k;
	LCM_CFG_INFO_T_PTR cfg_ptr = PNULL;
	cfg_ptr = LCM_GetCfgInfo(0,&count);
	for(k=0;k<count;k++)
	{
		if(cfg_ptr[k].dev_id==LCD_DRV_ID_NV3029G)
		{
			nv3029g_line_mode = cfg_ptr[k].adc_min;
			nv3029g_farmk = cfg_ptr[k].adc_max;
			
			break;
		}
	}
    //SCI_TraceLow("lcd: NV3029G_GetConfig LCM: g_two_date = %d , fmark =%d\n",nv3029g_line_mode,nv3029g_farmk);  //0x80,0xf5,0x3e
}

LOCAL uint32 NV3029G_ReadID(uint16 lcd_cs, uint16 lcd_cd, uint16 lcd_id)
{
    uint8 id[4] = {0};
    uint32 idlcd=0;
    
    NV3029G_GetConfig();
    
    hal_gouda_sim_init(nv3029g_line_mode,nv3029g_farmk,0x10000);

    hal_LcdDelay(120);
    hwp_analogReg->pad_spi_lcd_cfg2 |= ANALOG_REG_PAD_SPI_LCD_SIO_SPU;
    hal_LcdDelay(10);
    hal_GoudaReadData(0x04,id,4);
    hwp_analogReg->pad_spi_lcd_cfg2 =  hwp_analogReg->pad_spi_lcd_cfg2&(~ANALOG_REG_PAD_SPI_LCD_SIO_SPU);
    hal_LcdDelay(10);
    idlcd = ((id[3]<<16)|((id[2] <<8)| id[1]));
    hal_gouda_term();
    
    return idlcd;
}

const LCD_OPERATIONS_T NV3029G_operations = 
{
    NV3029G_Init,
    NV3029G_EnterSleep,
    NV3029G_SetContrast,
    NV3029G_SetBrightness,
    NV3029G_SetDisplayWindow,
    NV3029G_InvalidateRect,
    NV3029G_Invalidate,
    NV3029G_Close,
    NV3029G_RotationInvalidateRect,
    NV3029G_SetDirection,
    NV3029G_Reset, 
    NV3029G_ReadID	
};

LOCAL const LCD_TIMING_U s_NV3029G_lcmtiming =
{
    // LCM_CYCLE_U start(ns)
    5,  // CS setup time for LCM read (optional)  
    150, // low pulse width for LCM read (according spec)	
    150, // high pulse width for LCM read (according spec)
    10,   // CS setup time for LCM write  (optional) 	
    50,  // low pulse width for LCM write (according spec)
    50,  // high pulse width for LCM write (according spec)	
    // LCM_CYCLE_U end(ns)
};

LOCAL const LCD_TIMING_U s_NV3029G_spitiming =
{
#ifdef FPGA_VERIFICATION
    39000000,
#else
    52000000,
#endif
    0,0,
/*    SPI_CLK_52MHZ,        // clk frequency support (unit:MHz)
    SPI_CLK_IDLE_LOW,     // CPOL: 0--SPI_CLK_IDLE_LOW, 1--SPI_CLK_IDLE_HIGH
    SPI_SAMPLING_RISING,  // CPHA: 0--SPI_SAMPLING_RISING,  1--SPI_SAMPLING_FALLING 
*/
    8,                    // tx bit length: 8/16bits refer to lcm driver ic 
    0,
    0
};

#ifdef MAINLCM_INTERFACE_SPI
const LCD_SPEC_T g_lcd_NV3029G = 
{
    LCD_WIDTH, 
    LCD_HEIGHT, 
    SCI_NULL, 
    SCI_NULL,
    WIDTH_8,
    (LCD_TIMING_U*)&s_NV3029G_spitiming, 
    (LCD_OPERATIONS_T*)&NV3029G_operations,
    1,
    0
};
#else // not verify lcm
const LCD_SPEC_T g_lcd_NV3029G = 
{
    LCD_WIDTH, 
    LCD_HEIGHT, 
    LCD_MCU, 
    BUS_MODE_8080,
    WIDTH_8,
    (LCD_TIMING_U*)&s_NV3029G_lcmtiming, 
    (LCD_OPERATIONS_T*)&NV3029G_operations,
    1,
    0
};
#endif

/**---------------------------------------------------------------------------*
 **                         Compiler Flag                                     *
 **---------------------------------------------------------------------------*/
#ifdef   __cplusplus
    }
#endif 
