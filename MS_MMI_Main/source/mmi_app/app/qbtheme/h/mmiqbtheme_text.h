/*****************************************************************************
** File Name:      xxx_mmi_text.h                                            *
** Author:                                                                   *
** Date:           05/2006                                                   *
** Copyright:      2006 Spreadtrum, Incoporated. All Rights Reserved.         *
** Description:    This file is used to describe call log                    *
******************************************************************************
**                         Important Edit History                            *
** --------------------------------------------------------------------------*
** DATE           NAME             DESCRIPTION                              *
** 2011/09/16			cheng.luo			  created					                      *
******************************************************************************/

#ifndef QBTHEME_MMI_TEXT_H_
#define QBTHEME_MMI_TEXT_H_

#include "sci_types.h"
#include "mmi_module.h"

#ifdef __cplusplus
extern   "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
// ������ԴID
///////////////////////////////////////////////////////////////////////////////

#define MACRO_MDU_TYPE  MACRO_MDU_TEXT
#include "macro_mdu_def.h"

#ifdef CODE_MATCH_RES_CHECK
#include "qbtheme_mdu_def.h"
#endif

typedef enum QBTHEME_MMI_TEXT_ID_E
{
	QBTHEME_TXT_NULL = ( MMI_MODULE_QBTHEME << 16 ) | MMI_SYS_RES_FLAG,
#ifndef CODE_MATCH_RES_CHECK
#include "qbtheme_mdu_def.h"
#endif
	QBTHEME_TXT_MAX
} QBTHEME_MMI_TEXT_ID_E;

#undef MACRO_MDU_TYPE

#ifdef __cplusplus
}
#endif

#endif // QBTHEME_MMI_TEXT_H_