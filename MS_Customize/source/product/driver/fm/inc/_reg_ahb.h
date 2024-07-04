/**---------------------------------------------------------------------------**
 ** Copyright:    2014 Spreadtrum, Incoporated. All Rights Reserved.          **
 ** Description:  Automately generated by perl script                         **
------------------------------------------------------------------------------**/


/**---------------------------------------------------------------------------**
 **                    Edit    History                                        **
 ** ------------------------------------------------------------------------  **
 ** DATE          NAME               DESCRIPTION                              **
 ** 2014/01/13    BaseBand_Driver    Create by Trout3 AHB Control             **
 **                                  Register.xls                             **
------------------------------------------------------------------------------**/


#ifndef _AHB_REG_H
#define _AHB_REG_H


#define    REG_AHB_RST0                         ( CTL_BASE_AHB + 0x0040 )
//#define    REG_AHB_EB0                          ( CTL_BASE_AHB + 0x0004 )
#define    REG_AHB_EB0                          ( CTL_BASE_AHB + 0x0080 )
#define    REG_ARCH_EB_REG                      ( CTL_BASE_AHB + 0x0084 )
#define    REG_AHB_BUS_CTL0                     ( CTL_BASE_AHB + 0x00A0 )
#define    REG_AHB_BUS_CTL1                     ( CTL_BASE_AHB + 0x00A4 )
#define    REG_AHB_BUS_CTL2                     ( CTL_BASE_AHB + 0x00A8 )
#define    REG_AHB_SYS_CTL0                     ( CTL_BASE_AHB + 0x00B0 )
#define    REG_AHB_SYS_CTL1                     ( CTL_BASE_AHB + 0x00B4 )
#define    REG_AHB_SYS_CTL3                     ( CTL_BASE_AHB + 0x00BC )
#define    REG_AHB_SLP_CTL0                     ( CTL_BASE_AHB + 0x00D0 )
#define    REG_AHB_SLP_CTL1                     ( CTL_BASE_AHB + 0x00D4 )
#define    REG_AHB_SLP_CTL2                     ( CTL_BASE_AHB + 0x00D8 )
#define    REG_AHB_SYS_CTL6                     ( CTL_BASE_AHB + 0x00E0 )
#define    REG_AHB_SLP_STS0                     ( CTL_BASE_AHB + 0x0100 )
#define    REG_AHB_MTX_CTL0                     ( CTL_BASE_AHB + 0x0110 )
#define    REG_AHB_MTX_CTL1                     ( CTL_BASE_AHB + 0x0114 )
#define    REG_AHB_MTX_CTL2                     ( CTL_BASE_AHB + 0x0118 )
#define    REG_AHB_MTX_CTL3                     ( CTL_BASE_AHB + 0x011C )
#define    REG_AHB_MTX_CTL4                     ( CTL_BASE_AHB + 0x0120 )
#define    REG_AHB_MTX_CTL5                     ( CTL_BASE_AHB + 0x0124 )
#define    REG_AHB_MTX_CTL6                     ( CTL_BASE_AHB + 0x0128 )
#define    REG_AHB_ARCH_PORT                    ( CTL_BASE_AHB + 0x0130 )
#define    REG_AHB_SDIO_CTL                     ( CTL_BASE_AHB + 0x0134 )
#define    REG_AHB_SMC_CTL                      ( CTL_BASE_AHB + 0x0138 )
#define    REG_FPGA_DEBUG_CFG                   ( CTL_BASE_AHB + 0x03F0 )
#define    REG_AHB_CHIP_ID                      ( CTL_BASE_AHB + 0x03FC )


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_RST0                                        **
 ** Register Offset     : 0x0000                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_DAP_SOFT_RST                               (BIT_(4))
#define    BIT_AHB_SDIO_SOFT_RST                              (BIT_(3))
#define    BIT_AHB_RFSBI_SOFT_RST                             (BIT_(2))
#define    BIT_AHB_BUSM_SOFT_RST                              (BIT_(1))
#define    BIT_AHB_DMA_SOFT_RST                               (BIT_(0))


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_EB0                                         **
 ** Register Offset     : 0x0004                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_BUSMON1_EB                                 (BIT_(3))
#define    BIT_AHB_BUSMON0_EB                                 (BIT_(2))
#define    BIT_AHB_SDIO_EB                                    (BIT_(1))
#define    BIT_AHB_DMA_EB                                     (BIT_(0))


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_ARCH_EB_REG                                     **
 ** Register Offset     : 0x0084                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_ARCH_EB                                    (BIT_(0))


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_BUS_CTL0                                    **
 ** Register Offset     : 0x00A0                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_M5_PAUSE_HW0_EN                            (BIT_(5))
#define    BIT_AHB_M4_PAUSE_HW0_EN                            (BIT_(4))
#define    BIT_AHB_M3_PAUSE_HW0_EN                            (BIT_(3))
#define    BIT_AHB_M2_PAUSE_HW0_EN                            (BIT_(2))
#define    BIT_AHB_M1_PAUSE_HW0_EN                            (BIT_(1))
#define    BIT_AHB_M0_PAUSE_HW0_EN                            (BIT_(0))


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_BUS_CTL1                                    **
 ** Register Offset     : 0x00A4                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_M5_PAUSE_HW1_EN                            (BIT_(5))
#define    BIT_AHB_M4_PAUSE_HW1_EN                            (BIT_(4))
#define    BIT_AHB_M3_PAUSE_HW1_EN                            (BIT_(3))
#define    BIT_AHB_M2_PAUSE_HW1_EN                            (BIT_(2))
#define    BIT_AHB_M1_PAUSE_HW1_EN                            (BIT_(1))
#define    BIT_AHB_M0_PAUSE_HW1_EN                            (BIT_(0))


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_BUS_CTL2                                    **
 ** Register Offset     : 0x00A8                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_M5_PAUSE_SW                                (BIT_(5))
#define    BIT_AHB_M4_PAUSE_SW                                (BIT_(4))
#define    BIT_AHB_M3_PAUSE_SW                                (BIT_(3))
#define    BIT_AHB_M2_PAUSE_SW                                (BIT_(2))
#define    BIT_AHB_M1_PAUSE_SW                                (BIT_(1))
#define    BIT_AHB_M0_PAUSE_SW                                (BIT_(0))


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_SYS_CTL0                                    **
 ** Register Offset     : 0x00B0                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_WIFI_MON_OUT(x)                            (((x) & 0x1FF) << 8)
#define    BIT_GET_AHB_WIFI_MON_OUT(x)                        (((x) >> 8)& 0x1FF )
#define    BIT_AHB_BUSMON1_CHN_SEL(x)                         (((x) & 0x3) << 6)
#define    BIT_GET_AHB_BUSMON1_CHN_SEL(x)                     (((x) >> 6)& 0x3 )
#define    BIT_AHB_BUSMON0_CHN_SEL(x)                         (((x) & 0x3) << 4)
#define    BIT_GET_AHB_BUSMON0_CHN_SEL(x)                     (((x) >> 4)& 0x3 )
#define    BIT_AHB_WIFI_MON_SEL(x)                            ((x) & 0xF)
#define    BIT_GET_AHB_WIFI_MON_SEL(x)                        ((x) & 0xF)


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_SYS_CTL1                                    **
 ** Register Offset     : 0x00B4                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_REMAP                                      (BIT_(0))


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_SYS_CTL3                                    **
 ** Register Offset     : 0x00BC                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_DMA_REQ_HW_SEL(x)                          ((x) & 0x7FFFFFFF)
#define    BIT_GET_AHB_DMA_REQ_HW_SEL(x)                      ((x) & 0x7FFFFFFF)


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_SLP_CTL0                                    **
 ** Register Offset     : 0x00D0                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_APB_STOP                                   (BIT_(5))
#define    BIT_AHB_MCU_CORE_SLP                               (BIT_(1))
#define    BIT_AHB_MCU_FORCE_SYS_SLP                          (BIT_(0))


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_SLP_CTL1                                    **
 ** Register Offset     : 0x00D4                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_MCU_LIGHT_SLEEP_EN                         (BIT_(8))
#define    BIT_AHB_DMA_ACT_LIGHT_EN                           (BIT_(7))
#define    BIT_AHB_DMA_SLP_MODE                               (BIT_(6))
#define    BIT_AHB_MCU_DEEP_SLP_EN                            (BIT_(4))
#define    BIT_AHB_MCU_SYS_SLP_EN                             (BIT_(3))
#define    BIT_AHB_MCU_DMA_WAKE_UP_EN                         (BIT_(2))


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_SLP_CTL2                                    **
 ** Register Offset     : 0x00D8                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_DMA_REQ_WAKE_EN(x)                         ((x) & 0x7FFFFFFF)
#define    BIT_GET_AHB_DMA_REQ_WAKE_EN(x)                     ((x) & 0x7FFFFFFF)


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_SYS_CTL6                                    **
 ** Register Offset     : 0x00E0                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_PTEST                                      (BIT_(0))


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_SLP_STS0                                    **
 ** Register Offset     : 0x0100                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_MTX_M5_STOP                                (BIT_(5))
#define    BIT_AHB_MTX_M4_STOP                                (BIT_(4))
#define    BIT_AHB_MTX_M3_STOP                                (BIT_(3))
#define    BIT_AHB_MTX_M2_STOP                                (BIT_(2))
#define    BIT_AHB_MTX_M1_STOP                                (BIT_(1))
#define    BIT_AHB_MTX_M0_STOP                                (BIT_(0))


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_MTX_CTL0                                    **
 ** Register Offset     : 0x0110                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_MATRIX_CTRL0(x)                            (x)
#define    BIT_GET_AHB_MATRIX_CTRL0(x)                        (x)


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_MTX_CTL1                                    **
 ** Register Offset     : 0x0114                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_MATRIX_CTRL1(x)                            (x)
#define    BIT_GET_AHB_MATRIX_CTRL1(x)                        (x)


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_MTX_CTL2                                    **
 ** Register Offset     : 0x0118                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_MATRIX_CTRL2(x)                            (x)
#define    BIT_GET_AHB_MATRIX_CTRL2(x)                        (x)


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_MTX_CTL3                                    **
 ** Register Offset     : 0x011C                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_MATRIX_CTRL3(x)                            (x)
#define    BIT_GET_AHB_MATRIX_CTRL3(x)                        (x)


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_MTX_CTL4                                    **
 ** Register Offset     : 0x0120                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_MATRIX_CTRL4(x)                            (x)
#define    BIT_GET_AHB_MATRIX_CTRL4(x)                        (x)


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_MTX_CTL5                                    **
 ** Register Offset     : 0x0124                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_MATRIX_CTRL5(x)                            (x)
#define    BIT_GET_AHB_MATRIX_CTRL5(x)                        (x)


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_MTX_CTL6                                    **
 ** Register Offset     : 0x0128                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_MATRIX_CTRL6(x)                            (x)
#define    BIT_GET_AHB_MATRIX_CTRL6(x)                        (x)


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_ARCH_PORT                                   **
 ** Register Offset     : 0x0130                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_MCU_PROT                                   (BIT_(16))
#define    BIT_AHB_ARCH_PROT_VAL(x)                           ((x) & 0xFFFF)
#define    BIT_GET_AHB_ARCH_PROT_VAL(x)                       ((x) & 0xFFFF)


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_SDIO_CTL                                    **
 ** Register Offset     : 0x0134                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_SDIO_SLOT_SEL(x)                           ((x) & 0x3)
#define    BIT_GET_AHB_SDIO_SLOT_SEL(x)                       ((x) & 0x3)


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_SMC_CTL                                     **
 ** Register Offset     : 0x0138                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_SMC_SLEEP_READY                            (BIT_(3))
#define    BIT_AHB_SMC_PAUSE_READY                            (BIT_(2))
#define    BIT_AHB_SMC_SLEEP_REQ                              (BIT_(1))
#define    BIT_AHB_SMC_PAUSE_REQ                              (BIT_(0))


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_FPGA_DEBUG_CFG                                  **
 ** Register Offset     : 0x03F0                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_FPGA_DEBUG_SIG(x)                          (x)
#define    BIT_GET_AHB_FPGA_DEBUG_SIG(x)                      (x)


/**---------------------------------------------------------------------------**
 ** Register Name       : REG_AHB_CHIP_ID                                     **
 ** Register Offset     : 0x03FC                                              **
 ** Description         :                                                     **
------------------------------------------------------------------------------**/
#define    BIT_AHB_ID_BASE(x)                                 (((x) & 0xFFFFFF) << 8)
#define    BIT_GET_AHB_ID_BASE(x)                             (((x) >> 8)& 0xFFFFFF )
#define    BIT_AHB_MX_REG(x)                                  ((x) & 0xFF)
#define    BIT_GET_AHB_MX_REG(x)                              ((x) & 0xFF)


#endif //_AHB_REG_H