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

#ifndef _SYSMAIL_H_
#define _SYSMAIL_H_

// Auto generated by dtools(see dtools.txt for its version).
// Don't edit it manually!
typedef unsigned int uint32_t;

#define REG_MAILBOX_BASE (0x51506000)

typedef volatile struct
{
    uint32_t intgr0;    // 0x00000000
    uint32_t intstr0;   // 0x00000004
    uint32_t intcr0;    // 0x00000008
    uint32_t intmr0;    // 0x0000000c
    uint32_t intsr0;    // 0x00000010
    uint32_t intmsr0;   // 0x00000014
    uint32_t __24[2];   // 0x00000018
    uint32_t intgr1;    // 0x00000020
    uint32_t intstr1;   // 0x00000024
    uint32_t intcr1;    // 0x00000028
    uint32_t intmr1;    // 0x0000002c
    uint32_t intsr1;    // 0x00000030
    uint32_t intmsr1;   // 0x00000034
    uint32_t __56[2];   // 0x00000038
    uint32_t intgr2;    // 0x00000040
    uint32_t intstr2;   // 0x00000044
    uint32_t intcr2;    // 0x00000048
    uint32_t intmr2;    // 0x0000004c
    uint32_t intsr2;    // 0x00000050
    uint32_t intmsr2;   // 0x00000054
    uint32_t __88[2];   // 0x00000058
    uint32_t intgr3;    // 0x00000060
    uint32_t intstr3;   // 0x00000064
    uint32_t intcr3;    // 0x00000068
    uint32_t intmr3;    // 0x0000006c
    uint32_t intsr3;    // 0x00000070
    uint32_t intmsr3;   // 0x00000074
    uint32_t __120[2];  // 0x00000078
    uint32_t intgr4;    // 0x00000080
    uint32_t intstr4;   // 0x00000084
    uint32_t intcr4;    // 0x00000088
    uint32_t intmr4;    // 0x0000008c
    uint32_t intsr4;    // 0x00000090
    uint32_t intmsr4;   // 0x00000094
    uint32_t __152[2];  // 0x00000098
    uint32_t intgr5;    // 0x000000a0
    uint32_t intstr5;   // 0x000000a4
    uint32_t intcr5;    // 0x000000a8
    uint32_t intmr5;    // 0x000000ac
    uint32_t intsr5;    // 0x000000b0
    uint32_t intmsr5;   // 0x000000b4
    uint32_t __184[18]; // 0x000000b8
    uint32_t sysmail0;  // 0x00000100
    uint32_t sysmail1;  // 0x00000104
    uint32_t sysmail2;  // 0x00000108
    uint32_t sysmail3;  // 0x0000010c
    uint32_t sysmail4;  // 0x00000110
    uint32_t sysmail5;  // 0x00000114
    uint32_t sysmail6;  // 0x00000118
    uint32_t sysmail7;  // 0x0000011c
    uint32_t sysmail8;  // 0x00000120
    uint32_t sysmail9;  // 0x00000124
    uint32_t sysmail10; // 0x00000128
    uint32_t sysmail11; // 0x0000012c
    uint32_t sysmail12; // 0x00000130
    uint32_t sysmail13; // 0x00000134
    uint32_t sysmail14; // 0x00000138
    uint32_t sysmail15; // 0x0000013c
    uint32_t sysmail16; // 0x00000140
    uint32_t sysmail17; // 0x00000144
    uint32_t sysmail18; // 0x00000148
    uint32_t sysmail19; // 0x0000014c
    uint32_t sysmail20; // 0x00000150
    uint32_t sysmail21; // 0x00000154
    uint32_t sysmail22; // 0x00000158
    uint32_t sysmail23; // 0x0000015c
    uint32_t sysmail24; // 0x00000160
    uint32_t sysmail25; // 0x00000164
    uint32_t sysmail26; // 0x00000168
    uint32_t sysmail27; // 0x0000016c
    uint32_t sysmail28; // 0x00000170
    uint32_t sysmail29; // 0x00000174
    uint32_t sysmail30; // 0x00000178
    uint32_t sysmail31; // 0x0000017c
    uint32_t __384[32]; // 0x00000180
    uint32_t sysmail32; // 0x00000200
    uint32_t sysmail33; // 0x00000204
    uint32_t sysmail34; // 0x00000208
    uint32_t sysmail35; // 0x0000020c
    uint32_t sysmail36; // 0x00000210
    uint32_t sysmail37; // 0x00000214
    uint32_t sysmail38; // 0x00000218
    uint32_t sysmail39; // 0x0000021c
    uint32_t sysmail40; // 0x00000220
    uint32_t sysmail41; // 0x00000224
    uint32_t sysmail42; // 0x00000228
    uint32_t sysmail43; // 0x0000022c
    uint32_t sysmail44; // 0x00000230
    uint32_t sysmail45; // 0x00000234
    uint32_t sysmail46; // 0x00000238
    uint32_t sysmail47; // 0x0000023c
    uint32_t sysmail48; // 0x00000240
    uint32_t sysmail49; // 0x00000244
    uint32_t sysmail50; // 0x00000248
    uint32_t sysmail51; // 0x0000024c
    uint32_t sysmail52; // 0x00000250
    uint32_t sysmail53; // 0x00000254
    uint32_t sysmail54; // 0x00000258
    uint32_t sysmail55; // 0x0000025c
    uint32_t sysmail56; // 0x00000260
    uint32_t sysmail57; // 0x00000264
    uint32_t sysmail58; // 0x00000268
    uint32_t sysmail59; // 0x0000026c
    uint32_t sysmail60; // 0x00000270
    uint32_t sysmail61; // 0x00000274
    uint32_t sysmail62; // 0x00000278
    uint32_t sysmail63; // 0x0000027c
    uint32_t __640[32]; // 0x00000280
    uint32_t sysmail64; // 0x00000300
    uint32_t sysmail65; // 0x00000304
    uint32_t sysmail66; // 0x00000308
    uint32_t sysmail67; // 0x0000030c
    uint32_t sysmail68; // 0x00000310
    uint32_t sysmail69; // 0x00000314
    uint32_t sysmail70; // 0x00000318
    uint32_t sysmail71; // 0x0000031c
    uint32_t sysmail72; // 0x00000320
    uint32_t sysmail73; // 0x00000324
    uint32_t sysmail74; // 0x00000328
    uint32_t sysmail75; // 0x0000032c
    uint32_t sysmail76; // 0x00000330
    uint32_t sysmail77; // 0x00000334
    uint32_t sysmail78; // 0x00000338
    uint32_t sysmail79; // 0x0000033c
    uint32_t sysmail80; // 0x00000340
    uint32_t sysmail81; // 0x00000344
    uint32_t sysmail82; // 0x00000348
    uint32_t sysmail83; // 0x0000034c
    uint32_t sysmail84; // 0x00000350
    uint32_t sysmail85; // 0x00000354
    uint32_t sysmail86; // 0x00000358
    uint32_t sysmail87; // 0x0000035c
    uint32_t sysmail88; // 0x00000360
    uint32_t sysmail89; // 0x00000364
    uint32_t sysmail90; // 0x00000368
    uint32_t sysmail91; // 0x0000036c
    uint32_t sysmail92; // 0x00000370
    uint32_t sysmail93; // 0x00000374
    uint32_t sysmail94; // 0x00000378
    uint32_t sysmail95; // 0x0000037c
} HWP_CP_MAILBOX_T;

#define hwp_mailbox ((HWP_CP_MAILBOX_T *)REG_ACCESS_ADDRESS(REG_MAILBOX_BASE))

#endif // _SYSMAIL_H_