/*****************************************************************************
** File Name:      xxx_mmi_image.h                                           *
** Author:                                                                   *
** Date:           07/2007                                                   *
** Copyright:      2007 Spreadtrum, Incoporated. All Rights Reserved.        *
** Description:    This file is used to describe call log                    *
******************************************************************************
**                         Important Edit History                            *
** --------------------------------------------------------------------------*
** Create by Spreadtrum Resource Editor tool                                 *
******************************************************************************/

#ifndef FMM_MMI_IMAGE_H_
#define FMM_MMI_IMAGE_H_

#include "sci_types.h"
#include "mmi_imagefun.h"
#include "mmi_module.h"

#ifdef __cplusplus
extern   "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
// Image Resource ID
///////////////////////////////////////////////////////////////////////////////

#define MACRO_MDU_TYPE  MACRO_MDU_IMAGE
#include "macro_mdu_def.h"

#ifdef CODE_MATCH_RES_CHECK
#include "files_manager_mdu_def.h"
#endif

typedef enum FMM_MMI_IMAGE_ID_E
{
	FMM_IMAGE_NULL = ( MMI_MODULE_FMM << 16 ) | MMI_SYS_RES_FLAG,
#ifndef CODE_MATCH_RES_CHECK
#include "files_manager_mdu_def.h"
#endif
	FMM_IMAGE_MAX_ID
} FMM_MMI_IMAGE_ID_E;

#undef MACRO_MDU_TYPE

#ifdef __cplusplus
}
#endif

#endif //FMM_MMI_IMAGE_H_