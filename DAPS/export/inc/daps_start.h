/*****************************************************************************
** File Name:     daps_start.h                                               *
** Author:        li.li                                                      *
** Date:          2008/05/07                                                 *
** Copyright:     2008 Spreadtrum, Incorporated. All Rights Reserved.        *
** Description:   DAPS modules start, for external call                      *
******************************************************************************
**                         Important Edit History                            *
** --------------------------------------------------------------------------*
** DATE           NAME             DESCRIPTION                               *
** 2008/05/07     li.li            Create	                                 *
******************************************************************************/

#ifndef _DAPS_START_H_
#define _DAPS_START_H_

/**--------------------------------------------------------------------------*
 **                         Include Files                                    *
 **--------------------------------------------------------------------------*/
#include "sci_types.h"

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
 **                         FUNCTION DEFINITION                              *
 **--------------------------------------------------------------------------*/
/*****************************************************************************/
// 	Description : start DAPS modules
//	Global resource dependence :
//  Author: li.li
//	Note:
/*****************************************************************************/
PUBLIC void DAPS_Start( void );

/**--------------------------------------------------------------------------*
 **                         Compiler Flag                                    *
 **--------------------------------------------------------------------------*/
#ifdef   __cplusplus
    }
#endif

#endif /* _DAPS_START_H_ */