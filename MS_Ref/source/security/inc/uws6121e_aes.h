/*
 * Copyright (c) 2011 The Chromium OS Authors.
 * (C) Copyright 2010 - 2011 NVIDIA Corporation <www.nvidia.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef _AES_REF_H_
#define _AES_REF_H_

/*
 * AES encryption library, with small code size, supporting only 128-bit AES
 *
 * AES is a stream cipher which works a block at a time, with each block
 * in this case being AES_KEY_LENGTH bytes.
 */

enum {
	AES_STATECOLS	= 4,	/* columns in the state & expanded key */
	AES_KEYCOLS	= 4,	/* columns in a key */
	AES_ROUNDS	= 10,	/* rounds in encryption */

	AES_KEY_LENGTH	= 128 / 8,
	AES_EXPAND_KEY_LENGTH	= 4 * AES_STATECOLS * (AES_ROUNDS + 1),
};


#define RDA_EFUSE_PUBKEY_START	(48)
#define RDA_PUBKEY0_EFUSE_BLOCK_INDEX (48)
#define RDA_PUBKEY1_EFUSE_BLOCK_INDEX (49)
#define RDA_PUBKEY2_EFUSE_BLOCK_INDEX (50)
#define RDA_PUBKEY3_EFUSE_BLOCK_INDEX (51)
#define RDA_PUBKEY4_EFUSE_BLOCK_INDEX (52)
#define RDA_PUBKEY5_EFUSE_BLOCK_INDEX (53)
#define RDA_PUBKEY6_EFUSE_BLOCK_INDEX (54)
#define RDA_PUBKEY7_EFUSE_BLOCK_INDEX (55)


#define RDA_EFUSE_SINGLE_BLOCK_LOCK_3 (3) //bit 0~15 =0xffff
#define RDA_EFUSE_SECURITY_CFG_INDEX (89) //bringup_tmp, for secureBoot, refer to 8850 rom
#define RDA_EFUSE_UNIQUE_ID_LOW_INDEX (190)
#define RDA_EFUSE_UNIQUE_ID_HIGH_INDEX (191)
#define RDA_SE_CFG_SECURITY_ENABLE_BIT0			(1<<0)
#define RDA_SE_CFG_SECURITY_ENABLE_BIT1			(1<<23)
#define RDA_SE_CFG_SECURITY_ENABLE_BIT2			(1<<25)

#define ENCRYPT_OFF 0x1000
#define ENCRYPT_LEN 0x400
void rda_encrypt_obj(unsigned char * buf, int len);
#endif /* _AES_REF_H_ */