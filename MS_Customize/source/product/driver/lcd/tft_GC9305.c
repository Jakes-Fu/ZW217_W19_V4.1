/******************************************************************************
 ** File Name:     tft_GC9305.c                                             *
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
//#include "iomux_6121e.h"
#include "pinmap.h"


/**---------------------------------------------------------------------------*
 **                            Macro Define
 **---------------------------------------------------------------------------*/

#define SCI_TraceLow_Test SCI_TraceLow

LOCAL uint16 gc9305_line_mode = 0;
LOCAL uint16 gc9305_farmk = 0;


#define LCM_WR_REG(Addr, Data)                              \
{                                                       \
    while (hal_GoudaWriteReg(Addr, Data) != HAL_ERR_NO) \
    ;                                               \
}
#define LCD_DataWrite_GC9305(Data)                               \
{                                                  \
    while (hal_GoudaWriteData(Data) != HAL_ERR_NO) \
    ;                                          \
}
#define LCD_CtrlWrite_GC9305(Cmd)                              \
{                                                \
    while (hal_GoudaWriteCmd(Cmd) != HAL_ERR_NO) \
    ;                                        \
}

//#define LCD_CtrlData_GC9305(cmd, data)  LCD_CtrlWrite_GC9305( cmd ); LCD_DataWrite_GC9305( data );

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

LOCAL MEM_DATA_ACCESS_CTRL_U s_lcd_madc;


/******************************************************************************/
//  Description:   Close the lcd.(include sub lcd.)
//	Global resource dependence: 
//  Author:         Jim.zhang
//	Note:
/******************************************************************************/
LOCAL void GC9305_Close(void);

/******************************************************************************/
//  Description:   Enter/Exit sleep mode .
//	Global resource dependence: 
//  Author:         Jim.zhang
//	Note:
/******************************************************************************/
LOCAL ERR_LCD_E  GC9305_EnterSleep(BOOLEAN is_sleep);

/*********************************************************************/
//  Description:   Initialize color LCD : GC9304
//  Input:
//      None.
//  Return:
//      None.
//	Note:           
/*********************************************************************/
LOCAL ERR_LCD_E GC9305_Init(void);

LOCAL ERR_LCD_E GC9305_Invalidate(void);
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
LOCAL ERR_LCD_E GC9305_InvalidateRect(
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
LOCAL void GC9305_set_display_window(
        uint16 left, // start Horizon address
        uint16 right, // end Horizon address
        uint16 top, // start Vertical address
        uint16 bottom // end Vertical address
        );

LOCAL uint32 GC9305_ReadID(uint16 lcd_cs, uint16 lcd_cd, uint16 lcd_id);

/**---------------------------------------------------------------------------*
 **                      Function  Definitions
 **---------------------------------------------------------------------------*/

LOCAL ERR_LCD_E GC9305_SetDirection(LCD_DIRECT_E direct_type)
{
    gouda_event(0x90001101);

    SCI_TraceLow_Test("lcd: GC9305_SetDirection = %d",direct_type);

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
    LCD_CtrlWrite_GC9305(0x36);
    LCD_DataWrite_GC9305(s_lcd_madc.dataval);
    LCD_CtrlWrite_GC9305(0x2c);
    return ERR_LCD_NONE;

}

/******************************************************************************/
//  Description:   Set the windows address to display, in this windows
//                 color is  refreshed.
//	Global resource dependence: 
//	Note:
/******************************************************************************/
LOCAL void GC9305_set_display_window(
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
    // SCI_TraceLow_Test("[DRV_LCD]GC9305_set_display_window L = %d, top = %d, R = %d, bottom = %d",left,top,right,bottom);
    gouda_event(0x90001102);
    //hal_GoudaChangeSerialMode(HAL_GOUDA_SPI_LINE_3);
    LCD_CtrlWrite_GC9305(0x2a);	// set hori start , end (left, right)
    LCD_DataWrite_GC9305((newleft>>8)&0xff); // left high 8 b
    LCD_DataWrite_GC9305(newleft&0xff); // left low 8 b
    LCD_DataWrite_GC9305((newright>>8)&0xff); // right high 8 b
    LCD_DataWrite_GC9305(newright&0xff); // right low 8 b

    LCD_CtrlWrite_GC9305(0x2b);	// set vert start , end (top, bot)
    LCD_DataWrite_GC9305((newtop>>8)&0xff); // top high 8 b
    LCD_DataWrite_GC9305(newtop&0xff); // top low 8 b
    LCD_DataWrite_GC9305((newbottom>>8)&0xff); // bot high 8 b
    LCD_DataWrite_GC9305(newbottom&0xff); // bot low 8 b
    LCD_CtrlWrite_GC9305(0x2c);	 // recover memory write mode
    //hal_GoudaChangeSerialMode(HAL_GOUDA_SPI_LINE_3_2_LANE);

}

/**************************************************************************************/
// Description: initialize all LCD with LCDC MCU MODE and LCDC mcu mode
// Global resource dependence:
// Author: Jianping.wang
// Note:
/**************************************************************************************/
extern void hal_GoudatResetLcdPin(void);
LOCAL ERR_LCD_E GC9305_Init(void)
{
    SCI_TraceLow_Test("lcd: GC9305_Init here");

    mon_Event(0x55555555);

		hal_GoudatResetLcdPin();
		hal_LcdDelay(10);
		//--------------------------------display control setting----------------------------------------//
		LCD_CtrlWrite_GC9305 (0xfe);
		LCD_CtrlWrite_GC9305 (0xef);
		LCD_CtrlWrite_GC9305 (0x36);
		LCD_DataWrite_GC9305 (0x48);
		LCD_CtrlWrite_GC9305 (0x3a);
		LCD_DataWrite_GC9305 (0x05);
		LCD_CtrlWrite_GC9305 (0xa4);
		LCD_DataWrite_GC9305 (0x44);
		LCD_DataWrite_GC9305 (0x44);
		LCD_CtrlWrite_GC9305 (0xa5);
		LCD_DataWrite_GC9305 (0x42);
		LCD_DataWrite_GC9305 (0x42);
		LCD_CtrlWrite_GC9305 (0xaa);
		LCD_DataWrite_GC9305 (0x88);
		LCD_DataWrite_GC9305 (0x88);
		LCD_CtrlWrite_GC9305 (0xe8);
		//LCD_DataWrite_GC9305 (0x08);//0x11~60//0x13~47//0x14~41.3//0x17~30.5 HZ
		//LCDataWrite_GC9305 (0x40);//0x72~60//0x40~47//0x40~41.3//0x40~30.5 HZ

		//LCD_DataWrite_GC9305 (0x13);//0x11~60//0x13~47//0x14~41.3//0x17~30.5 HZ//0x02~54HZ
		//LCD_DataWrite_GC9305 (0x40);//0x72~60//0x40~47//0x40~41.3//0x40~30.5 HZ//0x40~54HZ
		LCD_DataWrite_GC9305 (0x02);//0x02 0x40 54HZ
		LCD_DataWrite_GC9305 (0x40);
		LCD_CtrlWrite_GC9305 (0xe3);
		LCD_DataWrite_GC9305 (0x01);
		LCD_DataWrite_GC9305 (0x18);
		LCD_CtrlWrite_GC9305 (0xe1);
		LCD_DataWrite_GC9305 (0x10);
		LCD_DataWrite_GC9305 (0x0a);
		LCD_CtrlWrite_GC9305 (0xAC);
		LCD_DataWrite_GC9305 (0x00);
		LCD_CtrlWrite_GC9305 (0xAe);
		LCD_DataWrite_GC9305 (0x2b);
		LCD_CtrlWrite_GC9305 (0xAf);
		LCD_DataWrite_GC9305 (0x55);
		LCD_CtrlWrite_GC9305 (0xAd);
		LCD_DataWrite_GC9305 (0x33);
		LCD_CtrlWrite_GC9305 (0xA6);
		LCD_DataWrite_GC9305 (0x29);
		LCD_DataWrite_GC9305 (0x29);
		LCD_CtrlWrite_GC9305 (0xA7);
		LCD_DataWrite_GC9305 (0x27);
		LCD_DataWrite_GC9305 (0x27);
		LCD_CtrlWrite_GC9305 (0xA8);
		LCD_DataWrite_GC9305 (0x17);
		LCD_DataWrite_GC9305 (0x17);
		LCD_CtrlWrite_GC9305 (0xA9);
		LCD_DataWrite_GC9305 (0x26);
		LCD_DataWrite_GC9305 (0x26);
		//---display window 240X320-----//
		LCD_CtrlWrite_GC9305 (0x2a);
		LCD_DataWrite_GC9305 (0x00);
		LCD_DataWrite_GC9305 (0x00);
		LCD_DataWrite_GC9305 (0x00);
		LCD_DataWrite_GC9305 (0xef);
		LCD_CtrlWrite_GC9305 (0x2b);
		LCD_DataWrite_GC9305 (0x00);
		LCD_DataWrite_GC9305 (0x00);
		LCD_DataWrite_GC9305 (0x01);
		LCD_DataWrite_GC9305 (0x3f);
		LCD_CtrlWrite_GC9305 (0x2c);
		LCD_CtrlWrite_GC9305 (0x44);
		LCD_DataWrite_GC9305 (0x00);
		LCD_DataWrite_GC9305 (0x60);
		//------end display window -----//
		LCD_CtrlWrite_GC9305 (0x35);   //te on
		LCD_DataWrite_GC9305 (0x00);
		LCD_CtrlWrite_GC9305 (0x38);
		//------gamma setting----------//
		LCD_CtrlWrite_GC9305 (0xf0);
		LCD_DataWrite_GC9305 (0x02);
		LCD_DataWrite_GC9305 (0x02);
		LCD_DataWrite_GC9305 (0x00);
		LCD_DataWrite_GC9305 (0x03);
		LCD_DataWrite_GC9305 (0x09);
		LCD_DataWrite_GC9305 (0x0C);
		LCD_CtrlWrite_GC9305 (0xf1);
		LCD_DataWrite_GC9305 (0x01);
		LCD_DataWrite_GC9305 (0x03);
		LCD_DataWrite_GC9305 (0x00);
		LCD_DataWrite_GC9305 (0x04);
		LCD_DataWrite_GC9305 (0x12);
		LCD_DataWrite_GC9305 (0x13);
		LCD_CtrlWrite_GC9305 (0xf2);
		LCD_DataWrite_GC9305 (0x0C);
		LCD_DataWrite_GC9305 (0x07);
		LCD_DataWrite_GC9305 (0x34);
		LCD_DataWrite_GC9305 (0x03);
		LCD_DataWrite_GC9305 (0x04);
		LCD_DataWrite_GC9305 (0x46);
		LCD_CtrlWrite_GC9305 (0xf3);
		LCD_DataWrite_GC9305 (0x14);
		LCD_DataWrite_GC9305 (0x0B);
		LCD_DataWrite_GC9305 (0x42);
		LCD_DataWrite_GC9305 (0x04);
		LCD_DataWrite_GC9305 (0x05);
		LCD_DataWrite_GC9305 (0x50);
		LCD_CtrlWrite_GC9305 (0xf4);
		LCD_DataWrite_GC9305 (0x09);
		LCD_DataWrite_GC9305 (0x13);
		LCD_DataWrite_GC9305 (0x13);
		LCD_DataWrite_GC9305 (0x1E);
		LCD_DataWrite_GC9305 (0x22);
		LCD_DataWrite_GC9305 (0x0F);
		LCD_CtrlWrite_GC9305 (0xf5);
		LCD_DataWrite_GC9305 (0x08);
		LCD_DataWrite_GC9305 (0x0E);
		LCD_DataWrite_GC9305 (0x0E);
		LCD_DataWrite_GC9305 (0x22);
		LCD_DataWrite_GC9305 (0x2B);
		LCD_DataWrite_GC9305 (0x0F);
		//-------end gamma setting----//

    LCD_CtrlWrite_GC9305(0x11);
    hal_LcdDelay(120);
    LCD_CtrlWrite_GC9305(0x29);
    hal_LcdDelay(20);
    LCD_CtrlWrite_GC9305(0x2c);

    if(hal_gouda_is_2_date_line() == SCI_TRUE)
    {
        //open two lane mode
        LCD_CtrlWrite_GC9305(0xe9);
        LCD_DataWrite_GC9305(0x08);
    }

    return ERR_LCD_NONE;
}

/******************************************************************************/
//  Description:   Enter/Exit sleep mode .
//	Global resource dependence: 
//  Author:         Jim.zhang
//	Note:
/******************************************************************************/
LOCAL ERR_LCD_E  GC9305_EnterSleep(
        BOOLEAN is_sleep //SCI_TRUE: enter sleep mode;SCI_FALSE:exit sleep mode.
        )
{
    SCI_TraceLow("lcd: GC9305_EnterSleep, is_sleep = %d", is_sleep);
    gouda_event(0x90001104);

    if(is_sleep)
    {
        gouda_event(0x900f2dc4);
        LCD_CtrlWrite_GC9305(0x28); //display off
        hal_LcdDelay(120);
        LCD_CtrlWrite_GC9305(0x10); // enter sleep mode
    }
    else
    {

        gouda_event(0x9f0f2ddf);
#if 0
        LCD_CtrlWrite_GC9305(0x11); // sleep out mode
        hal_LcdDelay(120);
        LCD_CtrlWrite_GC9305(0x29); // display on
#endif
        GC9305_Init();
    }

    return ERR_LCD_NONE;
}

/******************************************************************************/
//  Description:   Close the lcd.(include sub lcd.)
//	Global resource dependence: 
//  Author:         Jim.zhang
//	Note:
/******************************************************************************/
LOCAL void GC9305_Close(void)
{
    SCI_TraceLow("lcd:  in GC9304_Close");
    gouda_event(0x90001105);

    GC9305_EnterSleep( SCI_TRUE );
}

/******************************************************************************/
//  Description:   invalidate a rectang of in LCD
//	Global resource dependence: 
//  Author:         Jim.zhang
//	Note:
/******************************************************************************/
LOCAL ERR_LCD_E GC9305_Invalidate(void)
{
    gouda_event(0x90001106);

    GC9305_set_display_window (0x0, 0x0, LCD_WIDTH - 1, LCD_HEIGHT -1);
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
PUBLIC ERR_LCD_E GC9305_InvalidateRect(
        uint16 left, //the left value of the rectangel
        uint16 top, //top of the rectangle
        uint16 right, //right of the rectangle
        uint16 bottom //bottom of the rectangle
        )
{
    gouda_event(0x90001107);

    left = (left >=LCD_WIDTH) ? LCD_WIDTH-1 : left;
    right = (right >= LCD_WIDTH) ? LCD_WIDTH-1 : right;
    top = (top >= LCD_HEIGHT) ? LCD_HEIGHT-1 : top;
    bottom = (bottom >= LCD_HEIGHT) ? LCD_HEIGHT-1 : bottom;

    if ( ( right < left ) || ( bottom < top ) )
    {
        return ERR_LCD_OPERATE_FAIL;
    }     

    GC9305_set_display_window(left, top, right, bottom);
    return ERR_LCD_NONE;
}

LOCAL ERR_LCD_E GC9305_RotationInvalidateRect(uint16 left,uint16 top,uint16 right,uint16 bottom,LCD_ANGLE_E angle)
{
    gouda_event(0x90001108);

    SCI_TraceLow("lcd:  GC9305_RotationInvalidateRect");
    switch(angle)
    {
        case LCD_ANGLE_0:
            GC9305_set_display_window(left, top, right, bottom);
            break;
        case LCD_ANGLE_90:
            GC9305_set_display_window(left, top, bottom,right);
            break;
        case LCD_ANGLE_180:
            GC9305_set_display_window(left, top, right, bottom);
            break;
        case LCD_ANGLE_270:
            GC9305_set_display_window(left, top, bottom,right);
            break;
        default:
            GC9305_set_display_window(left, top, right, bottom);
            break;
    }
    return ERR_LCD_NONE;
}

extern void hal_GoudatResetLcdPin(void);

#define LCD_DEFAULT_STATUS_09H 0xa4530000

LOCAL void GcCheckDisplayStatus(void)
{
    uint8 id[4] = {0};
    uint32 lcdstatus =0;

    hal_GoudaReadData(0x09, id, 4);

    lcdstatus = ((id[3]<<24) | (id[2]<<16));
	
    SCI_TraceLow("lcd: GC9305 09=0x%x\n",lcdstatus);
    if(LCD_DEFAULT_STATUS_09H != lcdstatus)
    {
        hal_GoudatResetLcdPin();
        hal_LcdDelay(120);
        GC9305_Init();
        SCI_TraceLow("lcd: GC9305 ReadDisplayStatus: RESET  \n");
    }
    else
    {
        SCI_TraceLow("lcd: GC9305 LCD_DEFAULT_STATUS_09H   \n");
        LCD_CtrlWrite_GC9305(0xfe);
        LCD_CtrlWrite_GC9305(0xef);

        LCD_CtrlWrite_GC9305(0x11);
        LCD_CtrlWrite_GC9305(0x38);
        LCD_CtrlWrite_GC9305(0x20);

        LCD_CtrlWrite_GC9305(0x3a);
        LCD_DataWrite_GC9305(0x05);

        LCD_CtrlWrite_GC9305(0x35);
        LCD_DataWrite_GC9305(0x00);
	LCD_CtrlWrite_GC9305 (0x44);
	LCD_DataWrite_GC9305 (0x00);
	LCD_DataWrite_GC9305 (0x60);

        LCD_CtrlWrite_GC9305(0x36);
        LCD_DataWrite_GC9305(0x48);

        LCD_CtrlWrite_GC9305(0x29);
    }
}


LOCAL ERR_LCD_E   GC9305_SetContrast(uint16  contrast)
{
    gouda_event(0x90001109);

    SCI_TraceLow("lcd: GC9305_SetContrast");
    GcCheckDisplayStatus();
    return ERR_LCD_FUNC_NOT_SUPPORT;
} 
/*****************************************************************************/
LOCAL ERR_LCD_E   GC9305_SetBrightness(uint16 brightness)
{
    SCI_TraceLow("lcd:  GC9305_SetBrightness");
    gouda_event(0x9000110a);

    return ERR_LCD_FUNC_NOT_SUPPORT;
}

//  Description:    Enable lcd to partial display mode, so can save power.
//	Global resource dependence: 
//  Author:         Jim.zhang
//  Return:         SCI_TRUE:SUCCESS ,SCI_FALSE:failed.
//	Note:           If all input parameters are 0, exit partial display mode.
/*****************************************************************************/
LOCAL ERR_LCD_E GC9305_SetDisplayWindow(
        uint16 left, //left of the window
        uint16 top, //top of the window
        uint16 right, //right of the window
        uint16 bottom //bottom of the window
        )
{
    gouda_event(0x9000110b);

    SCI_TraceLow("lcd:  GC9305_SetDisplayWindow");
    GC9305_set_display_window(left, top, right, bottom);
    return ERR_LCD_NONE;
}

LOCAL void GC9305_InvalidatePixel(uint16 x, uint16 y, uint32 data)
{
    SCI_TraceLow("lcd:  GC9305_InvalidatePixel");
    gouda_event(0x9000110c);

    GC9305_InvalidateRect(x,y,x,y);
    LCD_DataWrite_GC9305(data);
}

LOCAL void GC9305_GetConfig(void)
{
    uint32 count,k;
    LCM_CFG_INFO_T_PTR cfg_ptr = PNULL;
    cfg_ptr = LCM_GetCfgInfo(0,&count);
    for(k=0;k<count;k++)
    {
        if(cfg_ptr[k].dev_id==LCD_DRV_ID_GC9305)
        {
            gc9305_line_mode = cfg_ptr[k].adc_min;
            gc9305_farmk = cfg_ptr[k].adc_max;

            break;
        }
    }
    SCI_TraceLow("lcd: GC9305_GetConfig: gc9305_line_mode = %d , gc9305_farmk =%d\n",gc9305_line_mode,gc9305_farmk);  //0x80,0xf5,0x3e
}

uint32 _Read_9305_ID(void)
{
    HAL_ERR_T r_err;
    uint8 id[4] = {0};

    hal_LcdDelay(140);
    hwp_iomux_6121e->pad_spi_lcd_sio |= (1<<12);
    hal_LcdDelay(10);
    r_err = hal_GoudaReadData(0x04,id,4);
    hwp_iomux_6121e->pad_spi_lcd_sio &= ~(1<<12);
    hal_LcdDelay(10);
    SCI_TraceLow("lcd: GC9305_ReadID LCM: 0x%0x, 0x%x, 0x%0x (read return : %d)\n", id[2], id[1], id[3], r_err);
    return ((id[3]<<16)|(id[2] <<8)| id[1]);
}


LOCAL uint32 GC9305_ReadID(uint16 lcd_cs, uint16 lcd_cd, uint16 lcd_id)
{
    uint32 ret_id = LCD_DRV_ID_GC9305;

    GC9305_GetConfig();

//    hal_gouda_sim_init(gc9305_line_mode,gc9305_farmk,0x2a000);
    hal_gouda_sim_init(gc9305_line_mode,gc9305_farmk,0x0);
	ret_id = _Read_9305_ID();

    hal_gouda_term();

    return ret_id;
    //return LCD_DRV_ID_GC9305;
}


const LCD_OPERATIONS_T GC9305_operations = 
{
    GC9305_Init,
    GC9305_EnterSleep,
    GC9305_SetContrast,
    GC9305_SetBrightness,
    GC9305_SetDisplayWindow,
    GC9305_InvalidateRect,
    GC9305_Invalidate,
    GC9305_Close,
    GC9305_RotationInvalidateRect,
    GC9305_SetDirection,
    NULL, 
    GC9305_ReadID	
};

LOCAL const LCD_TIMING_U s_GC9305_lcmtiming =
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

LOCAL const LCD_TIMING_U s_GC9305_spitiming =
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
const LCD_SPEC_T g_lcd_GC9305 = 
{
    LCD_WIDTH, 
    LCD_HEIGHT, 
    SCI_NULL, 
    SCI_NULL,
    WIDTH_8,
    (LCD_TIMING_U*)&s_GC9305_spitiming, 
    (LCD_OPERATIONS_T*)&GC9305_operations,
    1,
    0
};
#else // not verify lcm
const LCD_SPEC_T g_lcd_GC9305 = 
{
    LCD_WIDTH, 
    LCD_HEIGHT, 
    LCD_MCU, 
    BUS_MODE_8080,
    WIDTH_8,
    (LCD_TIMING_U*)&s_GC9305_lcmtiming, 
    (LCD_OPERATIONS_T*)&GC9305_operations,
    1,
    0
};
#endif


