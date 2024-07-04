/*****************************************************************************
** File Name:      mmiuzone_id.h                                             *
** Author:                                                                   *
** Date:           21/12/2011                                                *
** Copyright:      2003 Spreadtrum, Incoporated. All Rights Reserved.        *
** Description:    This file is used to register uzone module                *
*****************************************************************************
**                         Important Edit History                            *
** --------------------------------------------------------------------------*
** DATE           NAME             DESCRIPTION                               *
** 12/2011       Jessica             Create
******************************************************************************/

#ifndef _MMIUZONE_ID_H_
#define _MMIUZONE_ID_H_ 

/**--------------------------------------------------------------------------*
 **                         Include Files                                    *
 **--------------------------------------------------------------------------*/

/**--------------------------------------------------------------------------*
 **                         Compiler Flag                                    *
 **--------------------------------------------------------------------------*/
#ifdef __cplusplus
    extern   "C"
    {
#endif
/**--------------------------------------------------------------------------*
 **                         MACRO DEFINITION                                 *
 **--------------------------------------------------------------------------*/
        
/**--------------------------------------------------------------------------*
 **                         TYPE AND CONSTANT                                *
 **--------------------------------------------------------------------------*/
#define WIN_ID_DEF(win_id)          win_id
//window id
typedef enum
{
    MMIUZONE_WIN_ID_START = (MMI_MODULE_UZONE << 16),

#include "mmiuzone_id.def"

    MMIUZONE_MAX_WIN_ID
} MMIUZONE_WINDOW_ID_E;
#undef WIN_ID_DEF

//control id
typedef enum
{
    MMIUZONE_MAX_CTRL_ID
} MMIUZONE_CONTROL_ID_E;

/**--------------------------------------------------------------------------*
 **                         FUNCTION DEFINITION                              *
 **--------------------------------------------------------------------------*/
/*****************************************************************************/
//  Description : Register UZONE menu group
//  Global resource dependence : none
//  Author:
//  Note:
/*****************************************************************************/
PUBLIC void MMIUZONE_RegWinIdNameArr(void);

/**--------------------------------------------------------------------------*
 **                         Compiler Flag                                    *
 **--------------------------------------------------------------------------*/
#ifdef   __cplusplus
    }
#endif

#endif //_MMIUZONE_ID_H_
