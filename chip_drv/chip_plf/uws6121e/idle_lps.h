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

#ifndef _IDLE_LPS_H_
#define _IDLE_LPS_H_

#undef uint32_t
#define uint32_t uint32

// Auto generated by dtools(see dtools.txt for its version).
// Don't edit it manually!

#define REG_IDLE_LPS_SET_OFFSET (352)
#define REG_IDLE_LPS_CLR_OFFSET (528)

#define REG_IDLE_LPS_BASE (0x51702000)

typedef volatile struct
{
    uint32_t lps_ctrl_ap;      // 0x00000000
    uint32_t ap_sig_en;        // 0x00000004
    uint32_t ap_lps_sig_time;  // 0x00000008
    uint32_t lps_ctrl_cp;      // 0x0000000c
    uint32_t cp_pm2_sta;       // 0x00000010
    uint32_t cp_sig_en;        // 0x00000014
    uint32_t cp_lps_sig_time;  // 0x00000018
    uint32_t pm2_off_time;     // 0x0000001c
    uint32_t pm2_on_time;      // 0x00000020
    uint32_t pm2_on_off_time;  // 0x00000024
    uint32_t ap_pm2_sta;       // 0x00000028
    uint32_t ap_pm2_mode_en;   // 0x0000002c
    uint32_t aon_sig_en;       // 0x00000030
    uint32_t sleep_prot_time;  // 0x00000034
    uint32_t eliminate_jitter; // 0x00000038
    uint32_t ap_lps_sta;       // 0x0000003c
    uint32_t cp_inten;         // 0x00000040
    uint32_t __68[2];          // 0x00000044
    uint32_t cp_int_sta;       // 0x0000004c
    uint32_t ap_inten;         // 0x00000050
    uint32_t __84[2];          // 0x00000054
    uint32_t ap_int_sta;       // 0x0000005c
    uint32_t ap_awk_en;        // 0x00000060
    uint32_t __100[2];         // 0x00000064
    uint32_t ap_awk_st;        // 0x0000006c
    uint32_t cp_awk_en;        // 0x00000070
    uint32_t __116[2];         // 0x00000074
    uint32_t cp_awk_st;        // 0x0000007c
    uint32_t cp_lps_sta;       // 0x00000080
    uint32_t __132[1];         // 0x00000084
    uint32_t cp_p1_time;       // 0x00000088
    uint32_t cp_p2_time;       // 0x0000008c
    uint32_t lps_t_time1;      // 0x00000090
    uint32_t lps_t_time2;      // 0x00000094
    uint32_t lps_t_time3;      // 0x00000098
    uint32_t lps_t_time4;      // 0x0000009c
    uint32_t lps_t_time5;      // 0x000000a0
    uint32_t lps_t_time6;      // 0x000000a4
    uint32_t load_en;          // 0x000000a8
    uint32_t lps_32k_ref;      // 0x000000ac
    uint32_t ref_32k_fnl;      // 0x000000b0
    uint32_t lps_tpctrl;       // 0x000000b4
    uint32_t lps_tp_sta;       // 0x000000b8
    uint32_t load_time;        // 0x000000bc
    uint32_t mon_sel;          // 0x000000c0
    uint32_t __196[2];         // 0x000000c4
    uint32_t lps_res0;         // 0x000000cc
    uint32_t lps_res1;         // 0x000000d0
    uint32_t lps_res2;         // 0x000000d4
    uint32_t lps_res3;         // 0x000000d8
    uint32_t lps_res4;         // 0x000000dc
    uint32_t lps_res5;         // 0x000000e0
    uint32_t lps_res6;         // 0x000000e4
    uint32_t lps_res7;         // 0x000000e8
    uint32_t lps_res8;         // 0x000000ec
    uint32_t lps_res9;         // 0x000000f0
    uint32_t lps_res10;        // 0x000000f4
    uint32_t lps_res11;        // 0x000000f8
    uint32_t cp_p1_en;         // 0x000000fc
    uint32_t cp_p2_en;         // 0x00000100
    uint32_t lps_t1_en;        // 0x00000104
    uint32_t lps_t2_en;        // 0x00000108
    uint32_t lps_t3_en;        // 0x0000010c
    uint32_t lps_t4_en;        // 0x00000110
    uint32_t lps_t5_en;        // 0x00000114
    uint32_t lps_t6_en;        // 0x00000118
    uint32_t ap_awk_en1;       // 0x0000011c
    uint32_t __288[2];         // 0x00000120
    uint32_t ap_awk_st1;       // 0x00000128
    uint32_t cp_awk_en1;       // 0x0000012c
    uint32_t __304[2];         // 0x00000130
    uint32_t cp_awk_st1;       // 0x00000138
    uint32_t lps_t_time7;      // 0x0000013c
    uint32_t lps_t_time8;      // 0x00000140
    uint32_t lps_t_time9;      // 0x00000144
    uint32_t lps_t7_en;        // 0x00000148
    uint32_t lps_t8_en;        // 0x0000014c
    uint32_t lps_t9_en;        // 0x00000150
    uint32_t cp_pm2_mode_en;   // 0x00000154
    uint32_t __344[18];        // 0x00000158
    uint32_t cp_inten_set;     // 0x000001a0
    uint32_t __420[3];         // 0x000001a4
    uint32_t ap_inten_set;     // 0x000001b0
    uint32_t __436[3];         // 0x000001b4
    uint32_t ap_awk_en_set;    // 0x000001c0
    uint32_t __452[3];         // 0x000001c4
    uint32_t cp_awk_en_set;    // 0x000001d0
    uint32_t __468[19];        // 0x000001d4
    uint32_t mon_sel_set;      // 0x00000220
    uint32_t __548[11];        // 0x00000224
    uint32_t cp_inten_clr;     // 0x00000250
    uint32_t __596[3];         // 0x00000254
    uint32_t ap_inten_clr;     // 0x00000260
    uint32_t __612[3];         // 0x00000264
    uint32_t ap_awk_en_clr;    // 0x00000270
    uint32_t __628[2];         // 0x00000274
    uint32_t ap_awk_en1_set;   // 0x0000027c
    uint32_t cp_awk_en_clr;    // 0x00000280
    uint32_t __644[2];         // 0x00000284
    uint32_t cp_awk_en1_set;   // 0x0000028c
    uint32_t __656[16];        // 0x00000290
    uint32_t mon_sel_clr;      // 0x000002d0
    uint32_t __724[22];        // 0x000002d4
    uint32_t ap_awk_en1_clr;   // 0x0000032c
    uint32_t __816[3];         // 0x00000330
    uint32_t cp_awk_en1_clr;   // 0x0000033c
} HWP_IDLE_LPS_T;

#define hwp_idleLps ((HWP_IDLE_LPS_T *)REG_ACCESS_ADDRESS(REG_IDLE_LPS_BASE))


// lps_ctrl_ap
typedef union {
    uint32_t v;
    struct
    {
        uint32_t idct_ap : 1; // [0]
        uint32_t __31_1 : 31; // [31:1]
    } b;
} REG_IDLE_LPS_LPS_CTRL_AP_T;

// ap_sig_en
typedef union {
    uint32_t v;
    struct
    {
        uint32_t ap_chip_pd_en : 1; // [0]
        uint32_t ap_pd_xtal_en : 1; // [1]
        uint32_t ap_pd_pll_en : 1;  // [2]
        uint32_t ap_cg_en : 1;      // [3]
        uint32_t ap_pow_on_en : 1;  // [4]
        uint32_t ap_dis_val : 1;    // [5]
        uint32_t __31_6 : 26;       // [31:6]
    } b;
} REG_IDLE_LPS_AP_SIG_EN_T;

// ap_lps_sig_time
typedef union {
    uint32_t v;
    struct
    {
        uint32_t ap_t1 : 8; // [7:0]
        uint32_t ap_t2 : 8; // [15:8]
        uint32_t ap_t3 : 8; // [23:16]
        uint32_t ap_t4 : 8; // [31:24]
    } b;
} REG_IDLE_LPS_AP_LPS_SIG_TIME_T;

// lps_ctrl_cp
typedef union {
    uint32_t v;
    struct
    {
        uint32_t idct_cp : 1; // [0]
        uint32_t __31_1 : 31; // [31:1]
    } b;
} REG_IDLE_LPS_LPS_CTRL_CP_T;

// cp_pm2_sta
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cp_pm2_sta : 1; // [0]
        uint32_t __31_1 : 31;    // [31:1]
    } b;
} REG_IDLE_LPS_CP_PM2_STA_T;

// cp_sig_en
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cp_chip_pd_en : 1; // [0]
        uint32_t cp_pd_xtal_en : 1; // [1]
        uint32_t cp_pd_pll_en : 1;  // [2]
        uint32_t cp_cg_en : 1;      // [3]
        uint32_t cp_pow_on_en : 1;  // [4]
        uint32_t cp_dis_val : 1;    // [5]
        uint32_t __31_6 : 26;       // [31:6]
    } b;
} REG_IDLE_LPS_CP_SIG_EN_T;

// cp_lps_sig_time
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cp_t1 : 8; // [7:0]
        uint32_t cp_t2 : 8; // [15:8]
        uint32_t cp_t3 : 8; // [23:16]
        uint32_t cp_t4 : 8; // [31:24]
    } b;
} REG_IDLE_LPS_CP_LPS_SIG_TIME_T;

// pm2_off_time
typedef union {
    uint32_t v;
    struct
    {
        uint32_t n1 : 8; // [7:0]
        uint32_t n2 : 8; // [15:8]
        uint32_t n3 : 8; // [23:16]
        uint32_t n4 : 8; // [31:24]
    } b;
} REG_IDLE_LPS_PM2_OFF_TIME_T;

// pm2_on_time
typedef union {
    uint32_t v;
    struct
    {
        uint32_t __7_0 : 8; // [7:0]
        uint32_t p2 : 8;    // [15:8]
        uint32_t p3 : 8;    // [23:16]
        uint32_t p4 : 8;    // [31:24]
    } b;
} REG_IDLE_LPS_PM2_ON_TIME_T;

// pm2_on_off_time
typedef union {
    uint32_t v;
    struct
    {
        uint32_t n5 : 8; // [7:0]
        uint32_t n6 : 8; // [15:8]
        uint32_t p5 : 8; // [23:16]
        uint32_t p6 : 8; // [31:24]
    } b;
} REG_IDLE_LPS_PM2_ON_OFF_TIME_T;

// ap_pm2_sta
typedef union {
    uint32_t v;
    struct
    {
        uint32_t ap_pm2_sta : 1; // [0]
        uint32_t __31_1 : 31;    // [31:1]
    } b;
} REG_IDLE_LPS_AP_PM2_STA_T;

// ap_pm2_mode_en
typedef union {
    uint32_t v;
    struct
    {
        uint32_t ap_pm2_mode_en : 1; // [0]
        uint32_t __31_1 : 31;        // [31:1]
    } b;
} REG_IDLE_LPS_AP_PM2_MODE_EN_T;

// aon_sig_en
typedef union {
    uint32_t v;
    struct
    {
        uint32_t clk_en_aon_en : 1;          // [0]
        uint32_t pd_aon_iso : 1;             // [1]
        uint32_t rst_aon_n_en : 1;           // [2]
        uint32_t pd_aon_mem : 1;             // [3]
        uint32_t pd_aon_shutdown_m_b_en : 1; // [4]
        uint32_t pd_aon_shutdown_d_b_en : 1; // [5]
        uint32_t dis_val : 1;                // [6]
        uint32_t __31_7 : 25;                // [31:7]
    } b;
} REG_IDLE_LPS_AON_SIG_EN_T;

// sleep_prot_time
typedef union {
    uint32_t v;
    struct
    {
        uint32_t sleep_prot_time : 8; // [7:0]
        uint32_t __31_8 : 24;         // [31:8]
    } b;
} REG_IDLE_LPS_SLEEP_PROT_TIME_T;

// eliminate_jitter
typedef union {
    uint32_t v;
    struct
    {
        uint32_t eliminate_en : 24;  // [23:0]
        uint32_t eliminate_time : 8; // [31:24]
    } b;
} REG_IDLE_LPS_ELIMINATE_JITTER_T;

// ap_lps_sta
typedef union {
    uint32_t v;
    struct
    {
        uint32_t ap_lps_stat : 1;       // [0], read only
        uint32_t ap_lps_end_stat : 1;   // [1]
        uint32_t ap_pow_ack_stat : 1;   // [2]
        uint32_t ap_perip_awk_stat : 1; // [3]
        uint32_t __31_4 : 28;           // [31:4]
    } b;
} REG_IDLE_LPS_AP_LPS_STA_T;

// cp_inten
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cp_p1_irq_en : 1;            // [0]
        uint32_t cp_p2_irq_en : 1;            // [1]
        uint32_t cp_t1_irq_en : 1;            // [2]
        uint32_t cp_t2_irq_en : 1;            // [3]
        uint32_t cp_t3_irq_en : 1;            // [4]
        uint32_t cp_t4_irq_en : 1;            // [5]
        uint32_t cp_t5_irq_en : 1;            // [6]
        uint32_t cp_t6_irq_en : 1;            // [7]
        uint32_t cp_tstamp_irq_en : 1;        // [8]
        uint32_t cp_sys_awk_irq_to_cp_en : 1; // [9]
        uint32_t ap_sys_awk_irq_to_cp_en : 1; // [10]
        uint32_t cp_load_irq_en : 1;          // [11]
        uint32_t cp_t7_irq_en : 1;            // [12]
        uint32_t cp_t8_irq_en : 1;            // [13]
        uint32_t cp_t9_irq_en : 1;            // [14]
        uint32_t __31_15 : 17;                // [31:15]
    } b;
} REG_IDLE_LPS_CP_INTEN_T;

// cp_int_sta
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cp_int_sta : 15; // [14:0]
        uint32_t __31_15 : 17;    // [31:15]
    } b;
} REG_IDLE_LPS_CP_INT_STA_T;

// ap_inten
typedef union {
    uint32_t v;
    struct
    {
        uint32_t ap_p1_irq_en : 1;            // [0]
        uint32_t ap_p2_irq_en : 1;            // [1]
        uint32_t ap_t1_irq_en : 1;            // [2]
        uint32_t ap_t2_irq_en : 1;            // [3]
        uint32_t ap_t3_irq_en : 1;            // [4]
        uint32_t ap_t4_irq_en : 1;            // [5]
        uint32_t ap_t5_irq_en : 1;            // [6]
        uint32_t ap_t6_irq_en : 1;            // [7]
        uint32_t cp_sys_awk_irq_to_ap_en : 1; // [8]
        uint32_t ap_sys_awk_irq_to_ap_en : 1; // [9]
        uint32_t ap_load_irq_en : 1;          // [10]
        uint32_t ap_tstamp_irq_en : 1;        // [11]
        uint32_t ap_t7_irq_en : 1;            // [12]
        uint32_t ap_t8_irq_en : 1;            // [13]
        uint32_t ap_t9_irq_en : 1;            // [14]
        uint32_t __31_15 : 17;                // [31:15]
    } b;
} REG_IDLE_LPS_AP_INTEN_T;

// ap_int_sta
typedef union {
    uint32_t v;
    struct
    {
        uint32_t ap_int_sta : 15; // [14:0]
        uint32_t __31_15 : 17;    // [31:15]
    } b;
} REG_IDLE_LPS_AP_INT_STA_T;

// ap_awk_en
typedef union {
    uint32_t v;
    struct
    {
        uint32_t ap_awk0_en : 1;   // [0]
        uint32_t ap_awk1_en : 1;   // [1]
        uint32_t ap_awk2_en : 1;   // [2]
        uint32_t ap_awk3_en : 1;   // [3]
        uint32_t ap_awk4_en : 1;   // [4]
        uint32_t ap_awk5_en : 1;   // [5]
        uint32_t ap_awk6_en : 1;   // [6]
        uint32_t ap_awk7_en : 1;   // [7]
        uint32_t ap_awk8_en : 1;   // [8]
        uint32_t ap_awk9_en : 1;   // [9]
        uint32_t ap_awk10_en : 1;  // [10]
        uint32_t ap_awk11_en : 1;  // [11]
        uint32_t ap_awk12_en : 1;  // [12]
        uint32_t ap_awk13_en : 1;  // [13]
        uint32_t ap_awk14_en : 1;  // [14]
        uint32_t ap_awk15_en : 1;  // [15]
        uint32_t ap_awk16_en : 1;  // [16]
        uint32_t ap_awk17_en : 1;  // [17]
        uint32_t ap_awk18_en : 1;  // [18]
        uint32_t ap_awk19_en : 1;  // [19]
        uint32_t ap_awk20_en : 1;  // [20]
        uint32_t ap_awk21_en : 1;  // [21]
        uint32_t ap_awk22_en : 1;  // [22]
        uint32_t ap_awk23_en : 1;  // [23]
        uint32_t ap_p1_awk_en : 1; // [24]
        uint32_t ap_t1_awk_en : 1; // [25]
        uint32_t ap_t2_awk_en : 1; // [26]
        uint32_t ap_t3_awk_en : 1; // [27]
        uint32_t ap_t4_awk_en : 1; // [28]
        uint32_t ap_t5_awk_en : 1; // [29]
        uint32_t ap_t6_awk_en : 1; // [30]
        uint32_t ap_p2_awk_en : 1; // [31]
    } b;
} REG_IDLE_LPS_AP_AWK_EN_T;

// cp_awk_en
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cp_awk0_en : 1;   // [0]
        uint32_t cp_awk1_en : 1;   // [1]
        uint32_t cp_awk2_en : 1;   // [2]
        uint32_t cp_awk3_en : 1;   // [3]
        uint32_t cp_awk4_en : 1;   // [4]
        uint32_t cp_awk5_en : 1;   // [5]
        uint32_t cp_awk6_en : 1;   // [6]
        uint32_t cp_awk7_en : 1;   // [7]
        uint32_t cp_awk8_en : 1;   // [8]
        uint32_t cp_awk9_en : 1;   // [9]
        uint32_t cp_awk10_en : 1;  // [10]
        uint32_t cp_awk11_en : 1;  // [11]
        uint32_t cp_awk12_en : 1;  // [12]
        uint32_t cp_awk13_en : 1;  // [13]
        uint32_t cp_awk14_en : 1;  // [14]
        uint32_t cp_awk15_en : 1;  // [15]
        uint32_t cp_awk16_en : 1;  // [16]
        uint32_t cp_awk17_en : 1;  // [17]
        uint32_t cp_awk18_en : 1;  // [18]
        uint32_t cp_awk19_en : 1;  // [19]
        uint32_t cp_awk20_en : 1;  // [20]
        uint32_t cp_awk21_en : 1;  // [21]
        uint32_t cp_awk22_en : 1;  // [22]
        uint32_t cp_awk23_en : 1;  // [23]
        uint32_t cp_p1_awk_en : 1; // [24]
        uint32_t cp_t1_awk_en : 1; // [25]
        uint32_t cp_t2_awk_en : 1; // [26]
        uint32_t cp_t3_awk_en : 1; // [27]
        uint32_t cp_t4_awk_en : 1; // [28]
        uint32_t cp_t5_awk_en : 1; // [29]
        uint32_t cp_t6_awk_en : 1; // [30]
        uint32_t cp_p2_awk_en : 1; // [31]
    } b;
} REG_IDLE_LPS_CP_AWK_EN_T;

// cp_lps_sta
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cp_lps_stat : 1;       // [0]
        uint32_t cp_awk_up_stat : 1;    // [1]
        uint32_t cp_lps_end_stat : 1;   // [2]
        uint32_t cp_pow_ack_stat : 1;   // [3]
        uint32_t cp_perip_awk_stat : 1; // [4]
        uint32_t __31_5 : 27;           // [31:5]
    } b;
} REG_IDLE_LPS_CP_LPS_STA_T;

// load_en
typedef union {
    uint32_t v;
    struct
    {
        uint32_t load_en : 1; // [0]
        uint32_t __31_1 : 31; // [31:1]
    } b;
} REG_IDLE_LPS_LOAD_EN_T;

// lps_tpctrl
typedef union {
    uint32_t v;
    struct
    {
        uint32_t tstamp_en : 1;    // [0]
        uint32_t tstamp_confg : 1; // [1]
        uint32_t __31_2 : 30;      // [31:2]
    } b;
} REG_IDLE_LPS_LPS_TPCTRL_T;

// lps_tp_sta
typedef union {
    uint32_t v;
    struct
    {
        uint32_t tp_sta0 : 1; // [0]
        uint32_t __31_1 : 31; // [31:1]
    } b;
} REG_IDLE_LPS_LPS_TP_STA_T;

// mon_sel
typedef union {
    uint32_t v;
    struct
    {
        uint32_t mon0_sel : 2;  // [1:0]
        uint32_t mon1_sel : 2;  // [3:2]
        uint32_t mon2_sel : 2;  // [5:4]
        uint32_t mon3_sel : 2;  // [7:6]
        uint32_t mon4_sel : 2;  // [9:8]
        uint32_t mon5_sel : 2;  // [11:10]
        uint32_t mon6_sel : 2;  // [13:12]
        uint32_t mon7_sel : 2;  // [15:14]
        uint32_t mon8_sel : 2;  // [17:16]
        uint32_t mon9_sel : 2;  // [19:18]
        uint32_t mon10_sel : 2; // [21:20]
        uint32_t mon11_sel : 2; // [23:22]
        uint32_t mon12_sel : 2; // [25:24]
        uint32_t mon13_sel : 2; // [27:26]
        uint32_t mon14_sel : 2; // [29:28]
        uint32_t mon15_sel : 2; // [31:30]
    } b;
} REG_IDLE_LPS_MON_SEL_T;

// cp_p1_en
typedef union {
    uint32_t v;
    struct
    {
        uint32_t lps_p1_en : 1; // [0]
        uint32_t __31_1 : 31;   // [31:1]
    } b;
} REG_IDLE_LPS_CP_P1_EN_T;

// cp_p2_en
typedef union {
    uint32_t v;
    struct
    {
        uint32_t lps_p2_en : 1; // [0]
        uint32_t __31_1 : 31;   // [31:1]
    } b;
} REG_IDLE_LPS_CP_P2_EN_T;

// lps_t1_en
typedef union {
    uint32_t v;
    struct
    {
        uint32_t lps_t1_en : 1; // [0]
        uint32_t __31_1 : 31;   // [31:1]
    } b;
} REG_IDLE_LPS_LPS_T1_EN_T;

// lps_t2_en
typedef union {
    uint32_t v;
    struct
    {
        uint32_t lps_t2_en : 1; // [0]
        uint32_t __31_1 : 31;   // [31:1]
    } b;
} REG_IDLE_LPS_LPS_T2_EN_T;

// lps_t3_en
typedef union {
    uint32_t v;
    struct
    {
        uint32_t lps_t3_en : 1; // [0]
        uint32_t __31_1 : 31;   // [31:1]
    } b;
} REG_IDLE_LPS_LPS_T3_EN_T;

// lps_t4_en
typedef union {
    uint32_t v;
    struct
    {
        uint32_t lps_t4_en : 1; // [0]
        uint32_t __31_1 : 31;   // [31:1]
    } b;
} REG_IDLE_LPS_LPS_T4_EN_T;

// lps_t5_en
typedef union {
    uint32_t v;
    struct
    {
        uint32_t lps_t5_en : 1; // [0]
        uint32_t __31_1 : 31;   // [31:1]
    } b;
} REG_IDLE_LPS_LPS_T5_EN_T;

// lps_t6_en
typedef union {
    uint32_t v;
    struct
    {
        uint32_t lps_t6_en : 1; // [0]
        uint32_t __31_1 : 31;   // [31:1]
    } b;
} REG_IDLE_LPS_LPS_T6_EN_T;

// ap_awk_en1
typedef union {
    uint32_t v;
    struct
    {
        uint32_t ap_t7_awk_en : 1; // [0]
        uint32_t ap_t8_awk_en : 1; // [1]
        uint32_t ap_t9_awk_en : 1; // [2]
        uint32_t __31_3 : 29;      // [31:3]
    } b;
} REG_IDLE_LPS_AP_AWK_EN1_T;

// ap_awk_st1
typedef union {
    uint32_t v;
    struct
    {
        uint32_t ap_awk_sta1 : 3; // [2:0]
        uint32_t __31_3 : 29;     // [31:3]
    } b;
} REG_IDLE_LPS_AP_AWK_ST1_T;

// cp_awk_en1
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cp_t7_awk_en : 1; // [0]
        uint32_t cp_t8_awk_en : 1; // [1]
        uint32_t cp_t9_awk_en : 1; // [2]
        uint32_t __31_3 : 29;      // [31:3]
    } b;
} REG_IDLE_LPS_CP_AWK_EN1_T;

// cp_awk_st1
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cp_awk_sta1 : 3; // [2:0]
        uint32_t __31_3 : 29;     // [31:3]
    } b;
} REG_IDLE_LPS_CP_AWK_ST1_T;

// lps_t7_en
typedef union {
    uint32_t v;
    struct
    {
        uint32_t lps_t7_en : 1; // [0]
        uint32_t __31_1 : 31;   // [31:1]
    } b;
} REG_IDLE_LPS_LPS_T7_EN_T;

// lps_t8_en
typedef union {
    uint32_t v;
    struct
    {
        uint32_t lps_t8_en : 1; // [0]
        uint32_t __31_1 : 31;   // [31:1]
    } b;
} REG_IDLE_LPS_LPS_T8_EN_T;

// lps_t9_en
typedef union {
    uint32_t v;
    struct
    {
        uint32_t lps_t9_en : 1; // [0]
        uint32_t __31_1 : 31;   // [31:1]
    } b;
} REG_IDLE_LPS_LPS_T9_EN_T;

// cp_pm2_mode_en
typedef union {
    uint32_t v;
    struct
    {
        uint32_t cp_pm2_mode_en : 1; // [0]
        uint32_t __31_1 : 31;        // [31:1]
    } b;
} REG_IDLE_LPS_CP_PM2_MODE_EN_T;

// lps_ctrl_ap
#define IDLE_LPS_IDCT_AP (1 << 0)

// ap_sig_en
#define IDLE_LPS_AP_CHIP_PD_EN (1 << 0)
#define IDLE_LPS_AP_PD_XTAL_EN (1 << 1)
#define IDLE_LPS_AP_PD_PLL_EN (1 << 2)
#define IDLE_LPS_AP_CG_EN (1 << 3)
#define IDLE_LPS_AP_POW_ON_EN (1 << 4)
#define IDLE_LPS_AP_DIS_VAL (1 << 5)

// ap_lps_sig_time
#define IDLE_LPS_AP_T1(n) (((n)&0xff) << 0)
#define IDLE_LPS_AP_T2(n) (((n)&0xff) << 8)
#define IDLE_LPS_AP_T3(n) (((n)&0xff) << 16)
#define IDLE_LPS_AP_T4(n) (((n)&0xff) << 24)

// lps_ctrl_cp
#define IDLE_LPS_IDCT_CP (1 << 0)

// cp_pm2_sta
#define IDLE_LPS_CP_PM2_STA (1 << 0)

// cp_sig_en
#define IDLE_LPS_CP_CHIP_PD_EN (1 << 0)
#define IDLE_LPS_CP_PD_XTAL_EN (1 << 1)
#define IDLE_LPS_CP_PD_PLL_EN (1 << 2)
#define IDLE_LPS_CP_CG_EN (1 << 3)
#define IDLE_LPS_CP_POW_ON_EN (1 << 4)
#define IDLE_LPS_CP_DIS_VAL (1 << 5)

// cp_lps_sig_time
#define IDLE_LPS_CP_T1(n) (((n)&0xff) << 0)
#define IDLE_LPS_CP_T2(n) (((n)&0xff) << 8)
#define IDLE_LPS_CP_T3(n) (((n)&0xff) << 16)
#define IDLE_LPS_CP_T4(n) (((n)&0xff) << 24)

// pm2_off_time
#define IDLE_LPS_N1(n) (((n)&0xff) << 0)
#define IDLE_LPS_N2(n) (((n)&0xff) << 8)
#define IDLE_LPS_N3(n) (((n)&0xff) << 16)
#define IDLE_LPS_N4(n) (((n)&0xff) << 24)

// pm2_on_time
#define IDLE_LPS_P2(n) (((n)&0xff) << 8)
#define IDLE_LPS_P3(n) (((n)&0xff) << 16)
#define IDLE_LPS_P4(n) (((n)&0xff) << 24)

// pm2_on_off_time
#define IDLE_LPS_N5(n) (((n)&0xff) << 0)
#define IDLE_LPS_N6(n) (((n)&0xff) << 8)
#define IDLE_LPS_P5(n) (((n)&0xff) << 16)
#define IDLE_LPS_P6(n) (((n)&0xff) << 24)

// ap_pm2_sta
#define IDLE_LPS_AP_PM2_STA (1 << 0)

// ap_pm2_mode_en
#define IDLE_LPS_AP_PM2_MODE_EN (1 << 0)

// aon_sig_en
#define IDLE_LPS_CLK_EN_AON_EN (1 << 0)
#define IDLE_LPS_PD_AON_ISO (1 << 1)
#define IDLE_LPS_RST_AON_N_EN (1 << 2)
#define IDLE_LPS_PD_AON_MEM (1 << 3)
#define IDLE_LPS_PD_AON_SHUTDOWN_M_B_EN (1 << 4)
#define IDLE_LPS_PD_AON_SHUTDOWN_D_B_EN (1 << 5)
#define IDLE_LPS_DIS_VAL (1 << 6)

// sleep_prot_time
#define IDLE_LPS_SLEEP_PROT_TIME(n) (((n)&0xff) << 0)

// eliminate_jitter
#define IDLE_LPS_ELIMINATE_EN(n) (((n)&0xffffff) << 0)
#define IDLE_LPS_ELIMINATE_TIME(n) (((n)&0xff) << 24)

// ap_lps_sta
#define IDLE_LPS_AP_LPS_STAT (1 << 0)
#define IDLE_LPS_AP_LPS_END_STAT (1 << 1)
#define IDLE_LPS_AP_POW_ACK_STAT (1 << 2)
#define IDLE_LPS_AP_PERIP_AWK_STAT (1 << 3)

// cp_inten
#define IDLE_LPS_CP_P1_IRQ_EN (1 << 0)
#define IDLE_LPS_CP_P2_IRQ_EN (1 << 1)
#define IDLE_LPS_CP_T1_IRQ_EN (1 << 2)
#define IDLE_LPS_CP_T2_IRQ_EN (1 << 3)
#define IDLE_LPS_CP_T3_IRQ_EN (1 << 4)
#define IDLE_LPS_CP_T4_IRQ_EN (1 << 5)
#define IDLE_LPS_CP_T5_IRQ_EN (1 << 6)
#define IDLE_LPS_CP_T6_IRQ_EN (1 << 7)
#define IDLE_LPS_CP_TSTAMP_IRQ_EN (1 << 8)
#define IDLE_LPS_CP_SYS_AWK_IRQ_TO_CP_EN (1 << 9)
#define IDLE_LPS_AP_SYS_AWK_IRQ_TO_CP_EN (1 << 10)
#define IDLE_LPS_CP_LOAD_IRQ_EN (1 << 11)
#define IDLE_LPS_CP_T7_IRQ_EN (1 << 12)
#define IDLE_LPS_CP_T8_IRQ_EN (1 << 13)
#define IDLE_LPS_CP_T9_IRQ_EN (1 << 14)

// cp_int_sta
#define IDLE_LPS_CP_INT_STA(n) (((n)&0x7fff) << 0)

// ap_inten
#define IDLE_LPS_AP_P1_IRQ_EN (1 << 0)
#define IDLE_LPS_AP_P2_IRQ_EN (1 << 1)
#define IDLE_LPS_AP_T1_IRQ_EN (1 << 2)
#define IDLE_LPS_AP_T2_IRQ_EN (1 << 3)
#define IDLE_LPS_AP_T3_IRQ_EN (1 << 4)
#define IDLE_LPS_AP_T4_IRQ_EN (1 << 5)
#define IDLE_LPS_AP_T5_IRQ_EN (1 << 6)
#define IDLE_LPS_AP_T6_IRQ_EN (1 << 7)
#define IDLE_LPS_CP_SYS_AWK_IRQ_TO_AP_EN (1 << 8)
#define IDLE_LPS_AP_SYS_AWK_IRQ_TO_AP_EN (1 << 9)
#define IDLE_LPS_AP_LOAD_IRQ_EN (1 << 10)
#define IDLE_LPS_AP_TSTAMP_IRQ_EN (1 << 11)
#define IDLE_LPS_AP_T7_IRQ_EN (1 << 12)
#define IDLE_LPS_AP_T8_IRQ_EN (1 << 13)
#define IDLE_LPS_AP_T9_IRQ_EN (1 << 14)

// ap_int_sta
#define IDLE_LPS_AP_INT_STA(n) (((n)&0x7fff) << 0)

// ap_awk_en
#define IDLE_LPS_AP_AWK0_EN (1 << 0)
#define IDLE_LPS_AP_AWK1_EN (1 << 1)
#define IDLE_LPS_AP_AWK2_EN (1 << 2)
#define IDLE_LPS_AP_AWK3_EN (1 << 3)
#define IDLE_LPS_AP_AWK4_EN (1 << 4)
#define IDLE_LPS_AP_AWK5_EN (1 << 5)
#define IDLE_LPS_AP_AWK6_EN (1 << 6)
#define IDLE_LPS_AP_AWK7_EN (1 << 7)
#define IDLE_LPS_AP_AWK8_EN (1 << 8)
#define IDLE_LPS_AP_AWK9_EN (1 << 9)
#define IDLE_LPS_AP_AWK10_EN (1 << 10)
#define IDLE_LPS_AP_AWK11_EN (1 << 11)
#define IDLE_LPS_AP_AWK12_EN (1 << 12)
#define IDLE_LPS_AP_AWK13_EN (1 << 13)
#define IDLE_LPS_AP_AWK14_EN (1 << 14)
#define IDLE_LPS_AP_AWK15_EN (1 << 15)
#define IDLE_LPS_AP_AWK16_EN (1 << 16)
#define IDLE_LPS_AP_AWK17_EN (1 << 17)
#define IDLE_LPS_AP_AWK18_EN (1 << 18)
#define IDLE_LPS_AP_AWK19_EN (1 << 19)
#define IDLE_LPS_AP_AWK20_EN (1 << 20)
#define IDLE_LPS_AP_AWK21_EN (1 << 21)
#define IDLE_LPS_AP_AWK22_EN (1 << 22)
#define IDLE_LPS_AP_AWK23_EN (1 << 23)
#define IDLE_LPS_AP_P1_AWK_EN (1 << 24)
#define IDLE_LPS_AP_T1_AWK_EN (1 << 25)
#define IDLE_LPS_AP_T2_AWK_EN (1 << 26)
#define IDLE_LPS_AP_T3_AWK_EN (1 << 27)
#define IDLE_LPS_AP_T4_AWK_EN (1 << 28)
#define IDLE_LPS_AP_T5_AWK_EN (1 << 29)
#define IDLE_LPS_AP_T6_AWK_EN (1 << 30)
#define IDLE_LPS_AP_P2_AWK_EN (1 << 31)

// cp_awk_en
#define IDLE_LPS_CP_AWK0_EN (1 << 0)
#define IDLE_LPS_CP_AWK1_EN (1 << 1)
#define IDLE_LPS_CP_AWK2_EN (1 << 2)
#define IDLE_LPS_CP_AWK3_EN (1 << 3)
#define IDLE_LPS_CP_AWK4_EN (1 << 4)
#define IDLE_LPS_CP_AWK5_EN (1 << 5)
#define IDLE_LPS_CP_AWK6_EN (1 << 6)
#define IDLE_LPS_CP_AWK7_EN (1 << 7)
#define IDLE_LPS_CP_AWK8_EN (1 << 8)
#define IDLE_LPS_CP_AWK9_EN (1 << 9)
#define IDLE_LPS_CP_AWK10_EN (1 << 10)
#define IDLE_LPS_CP_AWK11_EN (1 << 11)
#define IDLE_LPS_CP_AWK12_EN (1 << 12)
#define IDLE_LPS_CP_AWK13_EN (1 << 13)
#define IDLE_LPS_CP_AWK14_EN (1 << 14)
#define IDLE_LPS_CP_AWK15_EN (1 << 15)
#define IDLE_LPS_CP_AWK16_EN (1 << 16)
#define IDLE_LPS_CP_AWK17_EN (1 << 17)
#define IDLE_LPS_CP_AWK18_EN (1 << 18)
#define IDLE_LPS_CP_AWK19_EN (1 << 19)
#define IDLE_LPS_CP_AWK20_EN (1 << 20)
#define IDLE_LPS_CP_AWK21_EN (1 << 21)
#define IDLE_LPS_CP_AWK22_EN (1 << 22)
#define IDLE_LPS_CP_AWK23_EN (1 << 23)
#define IDLE_LPS_CP_P1_AWK_EN (1 << 24)
#define IDLE_LPS_CP_T1_AWK_EN (1 << 25)
#define IDLE_LPS_CP_T2_AWK_EN (1 << 26)
#define IDLE_LPS_CP_T3_AWK_EN (1 << 27)
#define IDLE_LPS_CP_T4_AWK_EN (1 << 28)
#define IDLE_LPS_CP_T5_AWK_EN (1 << 29)
#define IDLE_LPS_CP_T6_AWK_EN (1 << 30)
#define IDLE_LPS_CP_P2_AWK_EN (1 << 31)

// cp_lps_sta
#define IDLE_LPS_CP_LPS_STAT (1 << 0)
#define IDLE_LPS_CP_AWK_UP_STAT (1 << 1)
#define IDLE_LPS_CP_LPS_END_STAT (1 << 2)
#define IDLE_LPS_CP_POW_ACK_STAT (1 << 3)
#define IDLE_LPS_CP_PERIP_AWK_STAT (1 << 4)

// load_en
#define IDLE_LPS_LOAD_EN (1 << 0)

// lps_tpctrl
#define IDLE_LPS_TSTAMP_EN (1 << 0)
#define IDLE_LPS_TSTAMP_CONFG (1 << 1)

// lps_tp_sta
#define IDLE_LPS_TP_STA0 (1 << 0)

// mon_sel
#define IDLE_LPS_MON0_SEL(n) (((n)&0x3) << 0)
#define IDLE_LPS_MON1_SEL(n) (((n)&0x3) << 2)
#define IDLE_LPS_MON2_SEL(n) (((n)&0x3) << 4)
#define IDLE_LPS_MON3_SEL(n) (((n)&0x3) << 6)
#define IDLE_LPS_MON4_SEL(n) (((n)&0x3) << 8)
#define IDLE_LPS_MON5_SEL(n) (((n)&0x3) << 10)
#define IDLE_LPS_MON6_SEL(n) (((n)&0x3) << 12)
#define IDLE_LPS_MON7_SEL(n) (((n)&0x3) << 14)
#define IDLE_LPS_MON8_SEL(n) (((n)&0x3) << 16)
#define IDLE_LPS_MON9_SEL(n) (((n)&0x3) << 18)
#define IDLE_LPS_MON10_SEL(n) (((n)&0x3) << 20)
#define IDLE_LPS_MON11_SEL(n) (((n)&0x3) << 22)
#define IDLE_LPS_MON12_SEL(n) (((n)&0x3) << 24)
#define IDLE_LPS_MON13_SEL(n) (((n)&0x3) << 26)
#define IDLE_LPS_MON14_SEL(n) (((n)&0x3) << 28)
#define IDLE_LPS_MON15_SEL(n) (((n)&0x3) << 30)

// cp_p1_en
#define IDLE_LPS_LPS_P1_EN (1 << 0)

// cp_p2_en
#define IDLE_LPS_LPS_P2_EN (1 << 0)

// lps_t1_en
#define IDLE_LPS_LPS_T1_EN (1 << 0)

// lps_t2_en
#define IDLE_LPS_LPS_T2_EN (1 << 0)

// lps_t3_en
#define IDLE_LPS_LPS_T3_EN (1 << 0)

// lps_t4_en
#define IDLE_LPS_LPS_T4_EN (1 << 0)

// lps_t5_en
#define IDLE_LPS_LPS_T5_EN (1 << 0)

// lps_t6_en
#define IDLE_LPS_LPS_T6_EN (1 << 0)

// ap_awk_en1
#define IDLE_LPS_AP_T7_AWK_EN (1 << 0)
#define IDLE_LPS_AP_T8_AWK_EN (1 << 1)
#define IDLE_LPS_AP_T9_AWK_EN (1 << 2)

// ap_awk_st1
#define IDLE_LPS_AP_AWK_STA1(n) (((n)&0x7) << 0)

// cp_awk_en1
#define IDLE_LPS_CP_T7_AWK_EN (1 << 0)
#define IDLE_LPS_CP_T8_AWK_EN (1 << 1)
#define IDLE_LPS_CP_T9_AWK_EN (1 << 2)

// cp_awk_st1
#define IDLE_LPS_CP_AWK_STA1(n) (((n)&0x7) << 0)

// lps_t7_en
#define IDLE_LPS_LPS_T7_EN (1 << 0)

// lps_t8_en
#define IDLE_LPS_LPS_T8_EN (1 << 0)

// lps_t9_en
#define IDLE_LPS_LPS_T9_EN (1 << 0)

// cp_pm2_mode_en
#define IDLE_LPS_CP_PM2_MODE_EN (1 << 0)

#undef uint32_t


#endif // _IDLE_LPS_H_
