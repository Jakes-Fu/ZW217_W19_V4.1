/**----------------------------------------------------------------------------*
 ** File Name:    sc6531efm_reg_aon.h                                          *
 ** Author:       Tiger.Han                                                   *
 ** DATE:         2016-7-22                                                    *
 ** Copyright:    2016 Spreadtrum, Incoporated. All Rights Reserved.           *
 ** Description:  Automately generated by perl script                          *
 **----------------------------------------------------------------------------*/

/**----------------------------------------------------------------------------*
 **                   Edit    History                                          *
 **----------------------------------------------------------------------------*
 ** DATE          NAME                 DESCRIPTION                             *
 ** 2016-7-22     Tiger.Han           Create.                                 *
 **               base on the "NemoG CLK Control Register.xls"  *
 **----------------------------------------------------------------------------*/


#ifndef _SC6531EFM_REG_AON_H_
#define _SC6531EFM_REG_AON_H_


/**----------------------------------------------------------------------------*
 **                      Compiler Flag                                         *
 **----------------------------------------------------------------------------*/
#ifdef __cplusplus
extern   "C"
{
#endif

#define    CGM_ARM_CFG					(AON_REG_BASE + 0x0020)
#define    CGM_AHB_2X_CFG				(AON_REG_BASE + 0x0024)
#define    CGM_AHB_1X_CFG				(AON_REG_BASE + 0x0028)
#define    CGM_SFC_2X_CFG				(AON_REG_BASE + 0x002C)
#define    CGM_SFC_1X_CFG				(AON_REG_BASE + 0x0030)
#define    CGM_APB_CFG					(AON_REG_BASE + 0x0034)
#define    CGM_SENSOR_CFG				(AON_REG_BASE + 0x0038)
#define    CGM_CCIR_CFG					(AON_REG_BASE + 0x003C)
#define    CGM_DCAM_CFG					(AON_REG_BASE + 0x0040)
#define    CGM_SDIO_CFG					(AON_REG_BASE + 0x0044)
#define    CGM_SD_SLV1_LOOP_CFG		(AON_REG_BASE + 0x0048)
#define    CGM_SD_SLV2_LOOP_CFG		(AON_REG_BASE + 0x004C)
#define    CGM_UART0_CFG				(AON_REG_BASE + 0x0050)
#define    CGM_SPI0_CFG					(AON_REG_BASE + 0x0054)
#define    CGM_SPI1_CFG					(AON_REG_BASE + 0x0058)
#define    CGM_AUX_CFG					(AON_REG_BASE + 0x005C)
#define    CGM_PWM_CFG					(AON_REG_BASE + 0x0060)
#define    CGM_USB48_CFG				(AON_REG_BASE + 0x0064)
#define    CGM_USB12_CFG				(AON_REG_BASE + 0x0068)
#define    CGM_32K_BT_CFG				(AON_REG_BASE + 0x006C)
#define    CGM_32K_STC_CFG				(AON_REG_BASE + 0x0070)
#define    CGM_32K_OUT_CFG				(AON_REG_BASE + 0x0074)
#define    CGM_1K_OUT_CFG				(AON_REG_BASE + 0x0078)
#define    CGM_I2C0_CFG					(AON_REG_BASE + 0x007C)
#define    CGM_I2C1_CFG					(AON_REG_BASE + 0x0080)
#define    CGM_I2C2_CFG					(AON_REG_BASE + 0x0084)
#define    CGM_ZIP0_CFG					(AON_REG_BASE + 0x0088)
#define    CGM_FUNCDMA_CFG				(AON_REG_BASE + 0x008C)
#define    CGM_EFS_CFG					(AON_REG_BASE + 0x0090)
#define    CGM_CM4_ASYNC_CFG			(AON_REG_BASE + 0x0094)
#define    CGM_CM4_APB_CFG				(AON_REG_BASE + 0x0098)
#define    CGM_FM_CFG					(AON_REG_BASE + 0x009C)
#define    CGM_FM_ADC_CFG				(AON_REG_BASE + 0x00A0)
#define    CGM_FM_RF_CTRL_CFG			(AON_REG_BASE + 0x00A4)
#define    CGM_DAP_CFG					(AON_REG_BASE + 0x00A8)
#define    CGM_DSP_CFG					(AON_REG_BASE + 0x00AC)
#define    CGM_IIS0_CFG					(AON_REG_BASE + 0x00B0)
#define    CGM_UART1_CFG				(AON_REG_BASE + 0x00B4)
#define    CGM_AUD_CFG					(AON_REG_BASE + 0x00B8)
#define    CGM_AUDIF_CFG				(AON_REG_BASE + 0x00BC)
#define    CGM_ADI_CFG					(AON_REG_BASE + 0x00C0)
#define    CGM_RF_FM_26M_CFG			(AON_REG_BASE + 0x00C4)
#define    CGM_RF_BT_26M_CFG			(AON_REG_BASE + 0x00C8)
#define    CGM_PTCK_CFG					(AON_REG_BASE + 0x00CC)
#define    CGM_PTCKN_CFG				(AON_REG_BASE + 0x00D0)
#define    CGM_BT_64M_CFG				(AON_REG_BASE + 0x00D4)
#define    CGM_BT_32M_CFG				(AON_REG_BASE + 0x00D8)
#define    CGM_BT_16M_CFG				(AON_REG_BASE + 0x00DC)
#define    CGM_BT_8M_CFG				(AON_REG_BASE + 0x00E0)
#define    CGM_BT_4M_CFG				(AON_REG_BASE + 0x00E4)
#define    CGM_BT_24M_CFG				(AON_REG_BASE + 0x00E8)
#define    CGM_BT_ADC_CFG				(AON_REG_BASE + 0x00EC)
#define    CGM_BT_DAC_CFG				(AON_REG_BASE + 0x00F0)
#define    CGM_BT_RSSI_ADC_ANA_CFG		(AON_REG_BASE + 0x00F4)
#define    CGM_BT_LPO_CFG				(AON_REG_BASE + 0x00F8) 
#define    CGM_BT_RF_CTRL_CFG			(AON_REG_BASE + 0x00FC)
#define    CGM_PMU_CFG					(AON_REG_BASE + 0x0100)

/*******************************************************************************
 ** Register Name: 	CGM_ARM_CFG
 ** Register Offset: 	0x0020
 ** Description: 		cgm arm register
 ** Reserved			[31:3]
 ** cgm_arm_sel		[2 :0 ] clk_arm source, 3'b000: 26m_tuned 3'b001: 26M 3'b010:104m
 										3'b011:208m 3'b100:208m_apll 
 										default: 3'h000
 ** cgm_arm_sel: clk_arm source --Removed,ARM9 apb reg 8b00_004c[1:0] ���Ƹ�clockѡ��										
 ******************************* Field definition ******************************/
#define	CGM_ARM_SEL_SHIFT       (0)
#define	CGM_ARM_SEL_MSK         (0x7 << CGM_ARM_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_AHB_2X_CFG
 ** Register Offset: 	0x0024
 ** Description: 		cgm ahb 2x register
 ** Reserved			[31:0]
 ******************************* Field definition ******************************/

/*******************************************************************************
 ** Register Name: 	CGM_AHB_1X_CFG
 ** Register Offset: 	0x0028
 ** Description: 		cgm ahb 1x register
 ** Reserved			[31:0]
 ******************************* Field definition ******************************/

/*******************************************************************************
 ** Register Name: 	CGM_SFC_2X_CFG
 ** Register Offset: 	0x002C
 ** Description: 		cgm sfc 2x register
 ** Reserved			[31:3]
 ** cgm_sfc_2x_sel	[2 :0 ] clk_sfc_2x source, 3'b000: 26m_tuned 3'b001: 26M 3'b010:156m
 										3'b011:166_4m 3'b100:208m_apll 3'b101:208m 
 										default: 3'h000
 ******************************* Field definition ******************************/
#define	CGM_SFC_2X_SEL_SHIFT       (0)
#define	CGM_SFC_2X_SEL_MSK         (0x7 << CGM_SFC_2X_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_SFC_1X_CFG
 ** Register Offset: 	0x0030
 ** Description: 		cgm sfc 1x register
 ** Reserved			[31:10]
 ** cgm_sfc_1x_div	[9 :8 ] clk_sfc_1x = clk_src/(div +1)
 										default: 2'h01
 ** Reserved			[7:0] 										
 ******************************* Field definition ******************************/
#define	CGM_SFC_1X_DIV_SHIFT       (8)
#define	CGM_SFC_1X_DIV_MSK         (0x3 << CGM_SFC_1X_DIV_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_APB_CFG
 ** Register Offset: 	0x0034
 ** Description: 		cgm apb register
 ** Reserved			[31:2]
 ** cgm_apb_sel		[1 :0 ] clk_apb source, 2'b00: 26m_tuned 2'b01: 26M 3'b10:24m
 										default: 2'h01
 ******************************* Field definition ******************************/
#define	CGM_APB_SEL_SHIFT       (0)
#define	CGM_APB_SEL_MSK         (0x3 << CGM_APB_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_SENSOR_CFG
 ** Register Offset: 	0x0038
 ** Description: 		cgm sensor register
 ** Reserved			[31:11]
 ** cgm_sensor_div	[10 :8 ] clk_sensor = clk_src/(div +1)
 										default: 3'h000
 ** Reserved			[7:3]
 ** cgm_sensor_sel	[2 :0 ] clk_apb source, 3'b000: 26m_tuned 3'b001: 26M 3'b010:48m
  										3'b011:64m 3'b100:83_2m										
 										default: 3'h000
 ******************************* Field definition ******************************/
#define	CGM_SENSOR_DIV_SHIFT       (8)
#define	CGM_SENSOR_DIV_MSK         (0x7 << CGM_SENSOR_DIV_SHIFT)
#define	CGM_SENSOR_SEL_SHIFT       (0)
#define	CGM_SENSOR_SEL_MSK         (0x7 << CGM_SENSOR_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_CCIR_CFG
 ** Register Offset: 	0x003C
 ** Description: 		cgm ccir register
 ** Reserved			[31:10]
 ** cgm_ccir_pad_sel	[16] clock source from pad, high active
 										default: 1'h0
 ** Reserved			[15:0] 										
 ******************************* Field definition ******************************/
#define	CGM_CCIR_PAD_SEL_SHIFT       (16)
#define	CGM_CCIR_PAD_SEL_MSK         (0x1 << CGM_CCIR_PAD_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_DCAM_CFG
 ** Register Offset: 	0x0040
 ** Description: 		cgm dcam register
 ** Reserved			[31:3]
 ** cgm_dcam_sel		[2 :0 ] clk_dcam source, 3'b000: 26m_tuned 3'b001: 26M 3'b010:83_2m
 										3'b011:104m 3'b100:138_6m 
 										default: 3'h000
 ******************************* Field definition ******************************/
#define	CGM_DCAM_SEL_SHIFT       (0)
#define	CGM_DCAM_SEL_MSK         (0x7 << CGM_DCAM_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_SDIO_CFG
 ** Register Offset: 	0x0044
 ** Description: 		cgm sdio register
 ** Reserved			[31:3]
 ** cgm_sdio_sel		[2 :0 ] clk_sdio source, 3'b000: 26m_tuned 3'b001: 26M 3'b010:48m
 										3'b011:75_6m 3'b100:104m 3'b101:104m_apll 
 										default: 3'h000
 ******************************* Field definition ******************************/
#define	CGM_SDIO_SEL_SHIFT       (0)
#define	CGM_SDIO_SEL_MSK         (0x7 << CGM_SDIO_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_SD_SLV1_LOOP_CFG
 ** Register Offset: 	0x0048
 ** Description: 		cgm sd slv1 loop register
 ** Reserved			[31:10]
 ** cgm_sd_slv1_loop_pad_sel	[16] clock source from pad, high active
 										default: 1'h0
 ** Reserved			[15:0] 										
 ******************************* Field definition ******************************/
#define	CGM_SD_SLV1_LOOP_PAD_SEL_SHIFT       (16)
#define	CGM_SD_SLV1_LOOP_PAD_SEL_MSK         (0x1 << CGM_SD_SLV1_LOOP_PAD_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_SD_SLV2_LOOP_CFG
 ** Register Offset: 	0x004C
 ** Description: 		cgm sd slv2 loop register
 ** Reserved			[31:10]
 ** cgm_sd_slv2_loop_pad_sel	[16] clock source from pad, high active
 										default: 1'h0
 ** Reserved			[15:0] 										
 ******************************* Field definition ******************************/
#define	CGM_SD_SLV2_LOOP_PAD_SEL_SHIFT       (16)
#define	CGM_SD_SLV2_LOOP_PAD_SEL_MSK         (0x1 << CGM_SD_SLV2_LOOP_PAD_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_UART0_CFG
 ** Register Offset: 	0x0050
 ** Description: 		cgm uart0 register
 ** Reserved			[31:2]
 ** cgm_uart0_sel		[1 :0 ] clk_uart0 source, 2'b00: 26m_tuned 2'b01: 26M 3'b10:104m
 										2'b11:104m_apll 
 										default: 2'h00
 ******************************* Field definition ******************************/
#define	CGM_UART0_SEL_SHIFT       (0)
#define	CGM_UART0_SEL_MSK         (0x3 << CGM_UART0_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_SPI0_CFG
 ** Register Offset: 	0x0054
 ** Description: 		cgm spi0 register
 ** Reserved			[31:10]
 ** cgm_spi0_div		[9 :8 ] clk_spi0 = clk_src/(div +1)
 										default: 2'h00
 ** Reserved			[7:3]
 ** cgm_spi0_sel		[2 :0 ] clk_spi0 source, 3'b000: 26m_tuned 3'b001: 26M 3'b010:46_2m
  										3'b011:75_6m 3'b100:104m 3'b101:104m_apll									
 										default: 3'h011
 ******************************* Field definition ******************************/
#define	CGM_SPI0_DIV_SHIFT       (8)
#define	CGM_SPI0_DIV_MSK         (0x3 << CGM_SPI0_DIV_SHIFT)
#define	CGM_SPI0_SEL_SHIFT       (0)
#define	CGM_SPI0_SEL_MSK         (0x7 << CGM_SPI0_SEL_SHIFT)


/*******************************************************************************
 ** Register Name: 	CGM_SPI1_CFG
 ** Register Offset: 	0x0058
 ** Description: 		cgm spi1 register
 ** Reserved			[31:10]
 ** cgm_spi1_div		[9 :8 ] clk_spi1 = clk_src/(div +1)
 										default: 2'h00
 ** Reserved			[7:3]
 ** cgm_spi1_sel		[2 :0 ] clk_spi1 source, 3'b000: 26m_tuned 3'b001: 26M 3'b010:46_2m
  										3'b011:48m 3'b100:75_6m 3'b101:104m 3'b110:104m_apll									
 										default: 3'h100
 ******************************* Field definition ******************************/
#define	CGM_SPI1_DIV_SHIFT       (8)
#define	CGM_SPI1_DIV_MSK         (0x3 << CGM_SPI1_DIV_SHIFT)
#define	CGM_SPI1_SEL_SHIFT       (0)
#define	CGM_SPI1_SEL_MSK         (0x7 << CGM_SPI1_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_AUX_CFG
 ** Register Offset: 	0x005C
 ** Description: 		cgm aux register
 ** Reserved			[31:10]
 ** cgm_aux_div		[9 :8 ] clk_aux = clk_src/(div +1)
 										default: 2'h00
 ** Reserved			[7:3]
 ** cgm_aux_sel		[2 :0 ] clk_aux source, 3'b000: 32k 3'b001: 26M_raw 3'b010:26m_tuned
  										3'b011:26m 3'b100:46_2m 3'b101:48m								
 										default: 3'h101
 ******************************* Field definition ******************************/
#define	CGM_AUX_DIV_SHIFT       (8)
#define	CGM_AUX_DIV_MSK         (0x3 << CGM_AUX_DIV_SHIFT)
#define	CGM_AUX_SEL_SHIFT       (0)
#define	CGM_AUX_SEL_MSK         (0x7 << CGM_AUX_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_PWM_CFG
 ** Register Offset: 	0x0060
 ** Description: 		cgm pwm register
 ** Reserved			[31:2]
 ** cgm_pwm_sel		[1 :0 ] clk_pwm source, 2'b00: 32K 2'b01: 26M_tuned 2'b10:26m
 										default: 2'h00
 ******************************* Field definition ******************************/
#define	CGM_PWM_SEL_SHIFT       (0)
#define	CGM_PWM_SEL_MSK         (0x3 << CGM_PWM_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_USB48_CFG
 ** Register Offset: 	0x0064
 ** Description: 		cgm usb48 register
 ** Reserved			[31:1]
 ** cgm_usb48_sel		[0] clk_usb48 source, 1'b0: 48m
 										default: 1'h0
 ******************************* Field definition ******************************/
#define	CGM_USB48_SEL_SHIFT       (0)
#define	CGM_USB48_SEL_MSK         (0x1 << CGM_USB48_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_USB12_CFG
 ** Register Offset: 	0x0068
 ** Description: 		cgm usb12 register
 ** Reserved			[31:1]
 ** cgm_usb12_sel		[0] clk_usb12 source, 1'b0: 12m
 										default: 1'h0
 ******************************* Field definition ******************************/
#define	CGM_USB12_SEL_SHIFT       (0)
#define	CGM_USB12_SEL_MSK         (0x1 << CGM_USB12_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_32K_BT_CFG
 ** Register Offset: 	0x006C
 ** Description: 		cgm 32k bt register
 ** Reserved			[31:1]
 ** cgm_32k_bt_sel	[0] clk_32k_bt source, 1'b0: 32k 1'b1: 32_768k
 										default: 1'h0
 ******************************* Field definition ******************************/
#define	CGM_32K_BT_SEL_SHIFT       (0)
#define	CGM_32K_BT_SEL_MSK         (0x1 << CGM_32K_BT_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_32K_STC_CFG
 ** Register Offset: 	0x0070
 ** Description: 		cgm 32k stc register
 ** Reserved			[31:1]
 ** cgm_32k_stc_sel	[0] clk_32k_stc source, 1'b0: 32k 1'b1: 32_768k
 										default: 1'h0
 ******************************* Field definition ******************************/
#define	CGM_32K_STC_SEL_SHIFT       (0)
#define	CGM_32K_STC_SEL_MSK         (0x1 << CGM_32K_STC_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_32K_OUT_CFG
 ** Register Offset: 	0x0074
 ** Description: 		cgm 32k out register
 ** Reserved			[31:1]
 ** cgm_32k_out_sel	[0] clk_32k_out source, 1'b0: 32k
 										default: 1'h0
 ******************************* Field definition ******************************/
#define	CGM_32K_OUT_SEL_SHIFT       (0)
#define	CGM_32K_OUT_SEL_MSK         (0x1 << CGM_32K_OUT_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_1K_OUT_CFG
 ** Register Offset: 	0x0078
 ** Description: 		cgm 1k out register
 ** Reserved			[31:1]
 ** cgm_1k_out_sel	[0] clk_1k_out source, 1'b0: 1k
 										default: 1'h0
 ******************************* Field definition ******************************/
#define	CGM_1K_OUT_SEL_SHIFT       (0)
#define	CGM_1K_OUT_SEL_MSK         (0x1 << CGM_1K_OUT_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_I2C0_CFG
 ** Register Offset: 	0x007C
 ** Description: 		cgm i2c0 register
 ** Reserved			[31:2]
 ** cgm_i2c0_sel		[1 :0 ] clk_i2c0 source, 2'b00: 26M_tuned 2'b01:26m 2'b10:48m
 										default: 2'h00
 ******************************* Field definition ******************************/
#define	CGM_I2C0_SEL_SHIFT       (0)
#define	CGM_I2C0_SEL_MSK         (0x3 << CGM_I2C0_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_I2C1_CFG
 ** Register Offset: 	0x0080
 ** Description: 		cgm i2c1 register
 ** Reserved			[31:2]
 ** cgm_i2c1_sel		[1 :0 ] clk_i2c1 source, 2'b00: 26M_tuned 2'b01:26m 2'b10:48m
 										default: 2'h00
 ******************************* Field definition ******************************/
#define	CGM_I2C1_SEL_SHIFT       (0)
#define	CGM_I2C1_SEL_MSK         (0x3 << CGM_I2C1_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_I2C2_CFG
 ** Register Offset: 	0x0084
 ** Description: 		cgm i2c2 register
 ** Reserved			[31:2]
 ** cgm_i2c2_sel		[1 :0 ] clk_i2c2 source, 2'b00: 26M_tuned 2'b01:26m 2'b10:48m
 										default: 2'h00
 ******************************* Field definition ******************************/
#define	CGM_I2C2_SEL_SHIFT       (0)
#define	CGM_I2C2_SEL_MSK         (0x3 << CGM_I2C2_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_ZIP0_CFG
 ** Register Offset: 	0x0088
 ** Description: 		cgm zip0 register
 ** Reserved			[31:2]
 ** cgm_zip0_sel		[1 :0 ] clk_zip0 source, 2'b00: 26M_tuned 2'b01:26m 2'b10:104m_apll
  										2'b11:208m_apll
 										default: 2'h00
 ******************************* Field definition ******************************/
#define	CGM_ZIP0_SEL_SHIFT       (0)
#define	CGM_ZIP0_SEL_MSK         (0x3 << CGM_ZIP0_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_FUNCDMA_CFG
 ** Register Offset: 	0x008C
 ** Description: 		cgm funcdma register
 ** Reserved			[31:10]
 ** cgm_funcdma_pad_sel	[16] clock source from pad, high active
 										default: 1'h0
 ** Reserved			[15:0] 										
 ******************************* Field definition ******************************/
#define	CGM_FUNCDMA_PAD_SEL_SHIFT       (16)
#define	CGM_FUNCDMA_PAD_SEL_MSK         (0x1 << CGM_FUNCDMA_PAD_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_EFS_CFG
 ** Register Offset: 	0x0090
 ** Description: 		cgm efs register
 ** Reserved			[31:2]
 ** cgm_efs_sel		[1 :0 ] clk_efs source, 2'b00: 13m 2'b01: 26M_tuned 2'b10:26m
 										default: 2'h01
 ******************************* Field definition ******************************/
#define	CGM_EFS_SEL_SHIFT       (0)
#define	CGM_EFS_SEL_MSK         (0x3 << CGM_EFS_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_CM4_ASYNC_CFG
 ** Register Offset: 	0x0094
 ** Description: 		cgm cm4 async register
 ** Reserved			[31:10]
 ** cgm_cm4_async_div		[9 :8 ] clk_cm4_async = clk_src/(div +1)
 										default: 2'h00
 ** Reserved			[7:3]
 ** cgm_cm4_async_sel		[2 :0 ] clk_cm4_async source, 3'b000: 1m_raw 3'b001: 26m_tuned 3'b010:26m
  										3'b011:64m 3'b100:104m 3'b101:104m_apll								
 										default: 3'h001
 ******************************* Field definition ******************************/
#define	CGM_CM4_ASYNC_DIV_SHIFT       (8)
#define	CGM_CM4_ASYNC_DIV_MSK         (0x3 << CGM_CM4_ASYNC_DIV_SHIFT)
#define	CGM_CM4_ASYNC_SEL_SHIFT       (0)
#define	CGM_CM4_ASYNC_SEL_MSK         (0x7 << CGM_CM4_ASYNC_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_CM4_APB_CFG
 ** Register Offset: 	0x0098
 ** Description: 		cgm cm4 apb register
 ** Reserved			[31:1]
 ** cgm_cm4_apb_sel	[0] clk_cm4_apb source, 1'b0: 26m_tuned 1'b1: 26m
 										default: 1'h0
 ******************************* Field definition ******************************/
#define	CGM_CM4_APB_SEL_SHIFT       (0)
#define	CGM_CM4_APB_SEL_MSK         (0x1 << CGM_CM4_APB_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_FM_CFG
 ** Register Offset: 	0x009C
 ** Description: 		cgm fm register
 ** Reserved			[31:1]
 ** cgm_fm_sel		[0] clk_fm source, 1'b0: 64m_fm 1'b1: 64m_fm_inv
 										default: 1'h0
 ******************************* Field definition ******************************/
#define	CGM_FM_SEL_SHIFT       (0)
#define	CGM_FM_SEL_MSK         (0x1 << CGM_FM_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_FM_ADC_CFG
 ** Register Offset: 	0x00A0
 ** Description: 		cgm fm adc register
 ** Reserved			[31:10]
 ** cgm_fm_adc_pad_sel	[16] clock source from pad, high active
 										default: 1'h0
 ** Reserved			[15:0] 										
 ******************************* Field definition ******************************/
#define	CGM_FM_ADC_PAD_SEL_SHIFT       (16)
#define	CGM_FM_ADC_PAD_SEL_MSK         (0x1 << CGM_FM_ADC_PAD_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_FM_RF_CTRL_CFG
 ** Register Offset: 	0x00A4
 ** Description: 		cgm fm rf ctrl register
 ** Reserved			[31:3]
 ** cgm_fm_rf_ctrl_sel		[2 :0 ] clk_fm_rf_ctrl source, 3'b000: 26m_tuned 3'b001: 26M 3'b010:64m_fm
 										3'b011:64m_fm_inv 3'b100:83_2m 
 										default: 3'h010
 ******************************* Field definition ******************************/
#define	CGM_FM_RF_CTRL_SEL_SHIFT       (0)
#define	CGM_FM_RF_CTRL_SEL_MSK         (0x7 << CGM_FM_RF_CTRL_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_DAP_CFG
 ** Register Offset: 	0x00A8
 ** Description: 		cgm dap register
 ** Reserved			[31:3]
 ** cgm_dap_sel		[2 :0 ] clk_dap source, 3'b000: 13m 3'b001: 26m_tuned 3'b010: 26M 
 										3'b011:64m_fm 3'b100:83_2m 
 										default: 3'h010
 ******************************* Field definition ******************************/
#define	CGM_DAP_SEL_SHIFT       (0)
#define	CGM_DAP_SEL_MSK         (0x7 << CGM_DAP_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_DSP_CFG
 ** Register Offset: 	0x00AC
 ** Description: 		cgm dsp register
 ** Reserved			[31:3]
 ** cgm_dsp_sel		[2 :0 ] clk_dsp source, 3'b000: 26m_tuned 3'b001: 26m 3'b010: 75_6M 
 										3'b011:104m 3'b100:104m_apll 
 										default: 3'h000
 ******************************* Field definition ******************************/
#define	CGM_DSP_SEL_SHIFT       (0)
#define	CGM_DSP_SEL_MSK         (0x7 << CGM_DSP_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_IIS0_CFG
 ** Register Offset: 	0x00B0
 ** Description: 		cgm iis0 register
 ** Reserved			[31:17]
 ** cgm_iis0_pad_sel	[16] clock source from pad, high active 
 										default: 1'h0
 ** Reserved			[15:14]
 ** cgm_iis0_div		[13 :8 ] clk_iis0 = clk_src/(div +1)
 										default: 6'h000000
 ** Reserved			[7:3]
 ** cgm_iis0_sel		[2 :0 ] clk_iis0 source, 3'b000: 26m_tuned 3'b001:26m 3'b010:64m_fm
  										3'b011:83_2m 3'b100:124_8m								
 										default: 3'h011
 ******************************* Field definition ******************************/
#define	CGM_IIS0_PAD_SEL_SHIFT       (16)
#define	CGM_IIS0_PAD_SEL_MSK         (0x1 << CGM_IIS0_PAD_SEL_SHIFT)
#define	CGM_IIS0_DIV_SHIFT       (8)
#define	CGM_IIS0_DIV_MSK         (0x3F << CGM_IIS0_DIV_SHIFT)
#define	CGM_IIS0_SEL_SHIFT       (0)
#define	CGM_IIS0_SEL_MSK         (0x7 << CGM_IIS0_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_UART1_CFG
 ** Register Offset: 	0x00B4
 ** Description: 		cgm uart1 register
 ** Reserved			[31:2]
 ** cgm_uart1_sel		[1 :0 ] clk_uart1 source, 2'b00: 26M_tuned 2'b01:26m 2'b10:104m
  										2'b11:104m_apll
 										default: 2'h00
 ******************************* Field definition ******************************/
#define	CGM_UART1_SEL_SHIFT       (0)
#define	CGM_UART1_SEL_MSK         (0x3 << CGM_UART1_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_AUD_CFG
 ** Register Offset: 	0x00B8
 ** Description: 		cgm aud register
 ** Reserved			[31:2]
 ** cgm_aud_sel		[1 :0 ] clk_aud source, 2'b00: 26M_raw 2'b01:26M_raw_inv 2'b10:26M_tuned
  										2'b11:26M_tuned_inv
 										default: 2'h00
 ******************************* Field definition ******************************/
#define	CGM_AUD_SEL_SHIFT       (0)
#define	CGM_AUD_SEL_MSK         (0x3 << CGM_AUD_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_AUDIF_CFG
 ** Register Offset: 	0x00BC
 ** Description: 		cgm audif register
 ** Reserved			[31:3]
 ** cgm_audif_sel		[2 :0 ] clk_audif source, 3'b000: 26M_raw 3'b001: 26M_raw_inv 3'b010: 26M_tuned 
 										3'b011:37_8m 3'b100:46_2m 3'b101:48m 
 										default: 3'h000
 ******************************* Field definition ******************************/
#define	CGM_AUDIF_SEL_SHIFT       (0)
#define	CGM_AUDIF_SEL_MSK         (0x7 << CGM_AUDIF_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_ADI_CFG
 ** Register Offset: 	0x00C0
 ** Description: 		cgm adi register
 ** Reserved			[31:2]
 ** cgm_adi_sel		[1 :0 ] clk_adi source, 2'b00: 26M_raw 2'b01:48m 2'b10:75_6m
 										default: 2'h00
 ******************************* Field definition ******************************/
#define	CGM_ADI_SEL_SHIFT       (0)
#define	CGM_ADI_SEL_MSK         (0x3 << CGM_ADI_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_RF_FM_26M_CFG
 ** Register Offset: 	0x00C4
 ** Description: 		cgm rf fm 26m register
 ** Reserved			[31:1]
 ** cgm_rf_fm_26m_sel		[0] clk_rf_fm_26m source, 1'b0: 26m_tuned 1'b1: 26m
 										default: 1'h0
 ******************************* Field definition ******************************/
#define	CGM_RF_FM_26M_SEL_SHIFT       (0)
#define	CGM_RF_FM_26M_SEL_MSK         (0x1 << CGM_RF_FM_26M_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_RF_BT_26M_CFG
 ** Register Offset: 	0x00C8
 ** Description: 		cgm rf bt 26m register
 ** Reserved			[31:1]
 ** cgm_rf_bt_26m_sel		[0] clk_rf_bt_26m source, 1'b0: 26m_tuned 1'b1: 26m
 										default: 1'h0
 ******************************* Field definition ******************************/
#define	CGM_RF_BT_26M_SEL_SHIFT       (0)
#define	CGM_RF_BT_26M_SEL_MSK         (0x1 << CGM_RF_BT_26M_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_PTCK_CFG
 ** Register Offset: 	0x00CC
 ** Description: 		cgm ptck register
 ** Reserved			[31:0]
 ******************************* Field definition ******************************/

/*******************************************************************************
 ** Register Name: 	CGM_PTCKN_CFG
 ** Register Offset: 	0x00D0
 ** Description: 		cgm ptckn register
 ** Reserved			[31:0]
 ******************************* Field definition ******************************/

/*******************************************************************************
 ** Register Name: 	CGM_BT_64M_CFG
 ** Register Offset: 	0x00D4
 ** Description: 		cgm bt 64m register
 ** Reserved			[31:1]
 ** cgm_bt_64m_sel	[0] clk_bt_64m source, 1'b0: 64M
 										default: 1'h0
 ******************************* Field definition ******************************/
#define	CGM_BT_64M_SEL_SHIFT       (0)
#define	CGM_BT_64M_SEL_MSK         (0x1 << CGM_BT_64M_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_BT_32M_CFG
 ** Register Offset: 	0x00D8
 ** Description: 		cgm bt 32m register
 ** Reserved			[31:12]
 ** cgm_bt_32m_div	[11 :8 ] clk_bt_32m= clk_src/(div +1)
 										default: 4'h0001
 ** Reserved			[7:0]
 ******************************* Field definition ******************************/
#define	CGM_BT_32M_DIV_SHIFT       (8)
#define	CGM_BT_32M_DIV_MSK         (0xF << CGM_BT_32M_DIV_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_BT_16M_CFG
 ** Register Offset: 	0x00DC
 ** Description: 		cgm bt 16m register
 ** Reserved			[31:12]
 ** cgm_bt_16m_div	[11 :8 ] clk_bt_16m= clk_src/(div +1)
 										default: 4'h0011
 ** Reserved			[7:0]
 ******************************* Field definition ******************************/
#define	CGM_BT_16M_DIV_SHIFT       (8)
#define	CGM_BT_16M_DIV_MSK         (0xF << CGM_BT_16M_DIV_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_BT_8M_CFG
 ** Register Offset: 	0x00E0
 ** Description: 		cgm bt 8m register
 ** Reserved			[31:12]
 ** cgm_bt_8m_div	[11 :8 ] clk_bt_8m= clk_src/(div +1)
 										default: 4'h0111
 ** Reserved			[7:0]
 ******************************* Field definition ******************************/
#define	CGM_BT_8M_DIV_SHIFT       (8)
#define	CGM_BT_8M_DIV_MSK         (0xF << CGM_BT_8M_DIV_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_BT_4M_CFG
 ** Register Offset: 	0x00E4
 ** Description: 		cgm bt 4m register
 ** Reserved			[31:12]
 ** cgm_bt_4m_div	[11 :8 ] clk_bt_4m= clk_src/(div +1)
 										default: 4'h1111
 ** Reserved			[7:0]
 ******************************* Field definition ******************************/
#define	CGM_BT_4M_DIV_SHIFT       (8)
#define	CGM_BT_4M_DIV_MSK         (0xF << CGM_BT_4M_DIV_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_BT_24M_CFG
 ** Register Offset: 	0x00E8
 ** Description: 		cgm bt 24m register
 ** Reserved			[31:1]
 ** cgm_bt_24m_sel	[0] clk_bt_24m source, 1'b0: 64M
 										default: 1'h0
 ******************************* Field definition ******************************/
#define	CGM_BT_24M_SEL_SHIFT       (0)
#define	CGM_BT_24M_SEL_MSK         (0x1 << CGM_BT_24M_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_BT_ADC_CFG
 ** Register Offset: 	0x00EC
 ** Description: 		cgm bt adc register
 ** Reserved			[31:10]
 ** cgm_bt_adc_pad_sel	[16] clock source from pad, high active
 										default: 1'h0
 ** Reserved			[15:0] 										
 ******************************* Field definition ******************************/
#define	CGM_BT_ADC_PAD_SEL_SHIFT       (16)
#define	CGM_BT_ADC_PAD_SEL_MSK         (0x1 << CGM_BT_ADC_PAD_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_BT_DAC_CFG
 ** Register Offset: 	0x00F0
 ** Description: 		cgm bt dac register
 ** Reserved			[31:10]
 ** cgm_bt_dac_pad_sel	[16] clock source from pad, high active
 										default: 1'h0
 ** Reserved			[15:0] 										
 ******************************* Field definition ******************************/
#define	CGM_BT_DAC_PAD_SEL_SHIFT       (16)
#define	CGM_BT_DAC_PAD_SEL_MSK         (0x1 << CGM_BT_DAC_PAD_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_BT_RSSI_ADC_ANA_CFG
 ** Register Offset: 	0x00F4
 ** Description: 		cgm bt rssi adc ana register
 ** Reserved			[31:10]
 ** cgm_bt_rssi_adc_ana_pad_sel	[16] clock source from pad, high active
 										default: 1'h0
 ** Reserved			[15:0] 										
 ******************************* Field definition ******************************/
#define	CGM_BT_RSSI_ADC_ANA_PAD_SEL_SHIFT       (16)
#define	CGM_BT_RSSI_ADC_ANA_PAD_SEL_MSK         (0x1 << CGM_BT_RSSI_ADC_ANA_PAD_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_BT_LPO_CFG
 ** Register Offset: 	0x00F8
 ** Description: 		cgm bt lpo register
 ** Reserved			[31:1]
 ** cgm_bt_lpo_sel	[0]	clk_bt_lpo source, 1'b0: 32k 1'b1: 32_768k 
 										default: 1'h0
 ******************************* Field definition ******************************/
#define	CGM_BT_LPO_SEL_SHIFT       (0)
#define	CGM_BT_LPO_SEL_MSK         (0x1 << CGM_BT_LPO_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_BT_RF_CTRL_CFG
 ** Register Offset: 	0x00FC
 ** Description: 		cgm bt rf ctrl register
 ** Reserved			[31:2]
 ** cgm_bt_rf_ctrl_sel		[1 :0 ] clk_bt_rf_ctrl source, 2'b00: 26m_tuned 2'b01:26m 2'b10:64m
  										2'b11:83_2m
 										default: 2'h10
 ******************************* Field definition ******************************/
#define	CGM_BT_RF_CTRL_SEL_SHIFT       (0)
#define	CGM_BT_RF_CTRL_SEL_MSK         (0x3 << CGM_BT_RF_CTRL_SEL_SHIFT)

/*******************************************************************************
 ** Register Name: 	CGM_PMU_CFG
 ** Register Offset: 	0x0100
 ** Description: 		cgm pmu register
 ** Reserved			[31:1]
 ** cgm_pmu_sel	[0]	clk_pmu source, 1'b0: 32k 1'b1: 26M
 										default: 1'h0
 ******************************* Field definition ******************************/
#define	CGM_PMU_SEL_SHIFT       (0)
#define	CGM_PMU_SEL_MSK         (0x1 << CGM_PMU_SEL_SHIFT)

/**----------------------------------------------------------------------------*
 **                      Compiler Flag                                         *
 **----------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif //_SC6531EFM_REG_AON_H_
