/* Copyright (C) 2018 RDA Technologies Limited and/or its affiliates("RDA").
 * All rights reserved.
 *
 * This software is supplied "AS IS" without any warranties.
 * RDA assumes no responsibility or liability for the use of the software,
 * conveys no license or title under any patent, copyright, or mask work
 * right to the product. RDA reserves the right to make changes in the
 * software without notification.  RDA also make no representation or
 * warranty that such application will be suitable for the specified use
 * without further testing or modification.
 */

#ifndef _AP_CLK_H_
#define _AP_CLK_H_

//typedef unsigned int uint32_t;
#include "sci_types.h"
#undef uint32_t
#define uint32_t uint32

// Auto generated by dtools(see dtools.txt for its version).
// Don't edit it manually!

#define REG_AP_CLK_BASE (0x0480a000)

typedef volatile struct
{
    uint32_t __0[9];                         // 0x00000000
    uint32_t cgm_ap_a5_div_cfg;              // 0x00000024
    uint32_t cgm_ap_a5_sel_cfg;              // 0x00000028
    uint32_t __44[1];                        // 0x0000002c
    uint32_t cgm_ap_bus_div_cfg;             // 0x00000030
    uint32_t __52[3];                        // 0x00000034
    uint32_t cgm_uart4_bf_div_sel_cfg;       // 0x00000040
    uint32_t __68[2];                        // 0x00000044
    uint32_t cgm_uart5_bf_div_sel_cfg;       // 0x0000004c
    uint32_t __80[2];                        // 0x00000050
    uint32_t cgm_uart6_bf_div_sel_cfg;       // 0x00000058
    uint32_t __92[2];                        // 0x0000005c
    uint32_t cgm_spiflash1_sel_cfg;          // 0x00000064
    uint32_t __104[2];                       // 0x00000068
    uint32_t cgm_spiflash2_sel_cfg;          // 0x00000070
    uint32_t __116[1];                       // 0x00000074
    uint32_t cgm_camera_pix_div_cfg;         // 0x00000078
    uint32_t cgm_camera_pix_sel_cfg;         // 0x0000007c
    uint32_t __128[1];                       // 0x00000080
    uint32_t cgm_camera_ref_div_cfg;         // 0x00000084
    uint32_t cgm_camera_ref_sel_cfg;         // 0x00000088
    uint32_t __140[1];                       // 0x0000008c
    uint32_t cgm_camera_csi_div_cfg;         // 0x00000090
    uint32_t cgm_camera_csi_sel_cfg;         // 0x00000094
    uint32_t __152[2];                       // 0x00000098
    uint32_t cgm_camera_csi_data_hs_sel_cfg; // 0x000000a0
    uint32_t __164[2];                       // 0x000000a4
    uint32_t cgm_spi1_sel_cfg;               // 0x000000ac
    uint32_t __176[2];                       // 0x000000b0
    uint32_t cgm_i2c1_sel_cfg;               // 0x000000b8
    uint32_t __188[2];                       // 0x000000bc
    uint32_t cgm_i2c2_sel_cfg;               // 0x000000c4
    uint32_t __200[2];                       // 0x000000c8
    uint32_t cgm_gpt3_sel_cfg;               // 0x000000d0
    uint32_t __212[5];                       // 0x000000d4
    uint32_t cgm_26m_sel_cfg;                // 0x000000e8
    uint32_t __236[3];                       // 0x000000ec
    uint32_t cgm_busy_src_monitor_cfg0;      // 0x000000f8
    uint32_t cgm_busy_src_monitor_cfg1;      // 0x000000fc
    uint32_t cgm_busy_src_monitor_cfg2;      // 0x00000100
} HWP_AP_CLK_T;

#define hwp_apClk ((HWP_AP_CLK_T *)REG_ACCESS_ADDRESS(REG_AP_CLK_BASE))

// cgm_ap_a5_div_cfg
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cgm_ap_a5_div : 2; // [1:0]
        uint32_t __31_2 : 30;       // [31:2]
    } b;
} REG_AP_CLK_CGM_AP_A5_DIV_CFG_T;

// cgm_ap_a5_sel_cfg
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cgm_ap_a5_sel : 3; // [2:0]
        uint32_t __31_3 : 29;       // [31:3]
    } b;
} REG_AP_CLK_CGM_AP_A5_SEL_CFG_T;

// cgm_ap_bus_div_cfg
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cgm_ap_bus_div : 2; // [1:0]
        uint32_t __31_2 : 30;        // [31:2]
    } b;
} REG_AP_CLK_CGM_AP_BUS_DIV_CFG_T;

// cgm_uart4_bf_div_sel_cfg
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cgm_uart4_bf_div_sel : 3; // [2:0]
        uint32_t __31_3 : 29;              // [31:3]
    } b;
} REG_AP_CLK_CGM_UART4_BF_DIV_SEL_CFG_T;

// cgm_uart5_bf_div_sel_cfg
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cgm_uart5_bf_div_sel : 3; // [2:0]
        uint32_t __31_3 : 29;              // [31:3]
    } b;
} REG_AP_CLK_CGM_UART5_BF_DIV_SEL_CFG_T;

// cgm_uart6_bf_div_sel_cfg
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cgm_uart6_bf_div_sel : 3; // [2:0]
        uint32_t __31_3 : 29;              // [31:3]
    } b;
} REG_AP_CLK_CGM_UART6_BF_DIV_SEL_CFG_T;

// cgm_spiflash1_sel_cfg
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cgm_spiflash1_sel : 3; // [2:0]
        uint32_t __31_3 : 29;           // [31:3]
    } b;
} REG_AP_CLK_CGM_SPIFLASH1_SEL_CFG_T;

// cgm_spiflash2_sel_cfg
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cgm_spiflash2_sel : 3; // [2:0]
        uint32_t __31_3 : 29;           // [31:3]
    } b;
} REG_AP_CLK_CGM_SPIFLASH2_SEL_CFG_T;

// cgm_camera_pix_div_cfg
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cgm_camera_pix_div : 11; // [10:0]
        uint32_t __31_11 : 21;            // [31:11]
    } b;
} REG_AP_CLK_CGM_CAMERA_PIX_DIV_CFG_T;

// cgm_camera_pix_sel_cfg
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cgm_camera_pix_sel : 3; // [2:0]
        uint32_t __31_3 : 29;            // [31:3]
    } b;
} REG_AP_CLK_CGM_CAMERA_PIX_SEL_CFG_T;

// cgm_camera_ref_div_cfg
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cgm_camera_ref_div : 11; // [10:0]
        uint32_t __31_11 : 21;            // [31:11]
    } b;
} REG_AP_CLK_CGM_CAMERA_REF_DIV_CFG_T;

// cgm_camera_ref_sel_cfg
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cgm_camera_ref_sel : 3; // [2:0]
        uint32_t __31_3 : 29;            // [31:3]
    } b;
} REG_AP_CLK_CGM_CAMERA_REF_SEL_CFG_T;

// cgm_camera_csi_div_cfg
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cgm_camera_csi_div : 11; // [10:0]
        uint32_t __31_11 : 21;            // [31:11]
    } b;
} REG_AP_CLK_CGM_CAMERA_CSI_DIV_CFG_T;

// cgm_camera_csi_sel_cfg
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cgm_camera_csi_sel : 3; // [2:0]
        uint32_t __31_3 : 29;            // [31:3]
    } b;
} REG_AP_CLK_CGM_CAMERA_CSI_SEL_CFG_T;

// cgm_camera_csi_data_hs_sel_cfg
typedef union {
    uint32_t v;
    struct
    {
        uint32_t __15_0 : 16;                        // [15:0]
        uint32_t cgm_camera_csi_data_hs_pad_sel : 1; // [16]
        uint32_t __31_17 : 15;                       // [31:17]
    } b;
} REG_AP_CLK_CGM_CAMERA_CSI_DATA_HS_SEL_CFG_T;

// cgm_spi1_sel_cfg
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cgm_spi1_sel : 3; // [2:0]
        uint32_t __31_3 : 29;      // [31:3]
    } b;
} REG_AP_CLK_CGM_SPI1_SEL_CFG_T;

// cgm_i2c1_sel_cfg
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cgm_i2c1_sel : 3; // [2:0]
        uint32_t __31_3 : 29;      // [31:3]
    } b;
} REG_AP_CLK_CGM_I2C1_SEL_CFG_T;

// cgm_i2c2_sel_cfg
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cgm_i2c2_sel : 3; // [2:0]
        uint32_t __31_3 : 29;      // [31:3]
    } b;
} REG_AP_CLK_CGM_I2C2_SEL_CFG_T;

// cgm_gpt3_sel_cfg
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cgm_gpt3_sel : 3; // [2:0]
        uint32_t __31_3 : 29;      // [31:3]
    } b;
} REG_AP_CLK_CGM_GPT3_SEL_CFG_T;

// cgm_26m_sel_cfg
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cgm_26m_sel : 2; // [1:0]
        uint32_t __31_2 : 30;     // [31:2]
    } b;
} REG_AP_CLK_CGM_26M_SEL_CFG_T;

// cgm_busy_src_monitor_cfg2
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cgm_busy_src_monitor2 : 17; // [16:0], read only
        uint32_t __31_17 : 15;               // [31:17]
    } b;
} REG_AP_CLK_CGM_BUSY_SRC_MONITOR_CFG2_T;

// cgm_ap_a5_div_cfg
#define AP_CLK_CGM_AP_A5_DIV(n) (((n)&0x3) << 0)

// cgm_ap_a5_sel_cfg
#define AP_CLK_CGM_AP_A5_SEL(n) (((n)&0x7) << 0)

// cgm_ap_bus_div_cfg
#define AP_CLK_CGM_AP_BUS_DIV(n) (((n)&0x3) << 0)

// cgm_uart4_bf_div_sel_cfg
#define AP_CLK_CGM_UART4_BF_DIV_SEL(n) (((n)&0x7) << 0)

// cgm_uart5_bf_div_sel_cfg
#define AP_CLK_CGM_UART5_BF_DIV_SEL(n) (((n)&0x7) << 0)

// cgm_uart6_bf_div_sel_cfg
#define AP_CLK_CGM_UART6_BF_DIV_SEL(n) (((n)&0x7) << 0)

// cgm_spiflash1_sel_cfg
#define AP_CLK_CGM_SPIFLASH1_SEL(n) (((n)&0x7) << 0)

// cgm_spiflash2_sel_cfg
#define AP_CLK_CGM_SPIFLASH2_SEL(n) (((n)&0x7) << 0)

// cgm_camera_pix_div_cfg
#define AP_CLK_CGM_CAMERA_PIX_DIV(n) (((n)&0x7ff) << 0)

// cgm_camera_pix_sel_cfg
#define AP_CLK_CGM_CAMERA_PIX_SEL(n) (((n)&0x7) << 0)

// cgm_camera_ref_div_cfg
#define AP_CLK_CGM_CAMERA_REF_DIV(n) (((n)&0x7ff) << 0)

// cgm_camera_ref_sel_cfg
#define AP_CLK_CGM_CAMERA_REF_SEL(n) (((n)&0x7) << 0)

// cgm_camera_csi_div_cfg
#define AP_CLK_CGM_CAMERA_CSI_DIV(n) (((n)&0x7ff) << 0)

// cgm_camera_csi_sel_cfg
#define AP_CLK_CGM_CAMERA_CSI_SEL(n) (((n)&0x7) << 0)

// cgm_camera_csi_data_hs_sel_cfg
#define AP_CLK_CGM_CAMERA_CSI_DATA_HS_PAD_SEL (1 << 16)

// cgm_spi1_sel_cfg
#define AP_CLK_CGM_SPI1_SEL(n) (((n)&0x7) << 0)

// cgm_i2c1_sel_cfg
#define AP_CLK_CGM_I2C1_SEL(n) (((n)&0x7) << 0)

// cgm_i2c2_sel_cfg
#define AP_CLK_CGM_I2C2_SEL(n) (((n)&0x7) << 0)

// cgm_gpt3_sel_cfg
#define AP_CLK_CGM_GPT3_SEL(n) (((n)&0x7) << 0)

// cgm_26m_sel_cfg
#define AP_CLK_CGM_26M_SEL(n) (((n)&0x3) << 0)

// cgm_busy_src_monitor_cfg2
#define AP_CLK_CGM_BUSY_SRC_MONITOR2(n) (((n)&0x1ffff) << 0)

#undef uint32_t

#endif // _AP_CLK_H_