/******************************************************************************
 ** File Name:      TF_lcmprod.h                                                 *
 ** Author:         Liangwen.Zhen                                             *
 ** DATE:           01/15/2008                                                *
 ** Copyright:      2007 Spreadtrum, Incoporated. All Rights Reserved.        *
 ** Description:    This file defines the basic operation interfaces of LCM   *
 **					about product
 **                                                                           *
 ******************************************************************************

 ******************************************************************************
 **                        Edit History                                       *
 ** ------------------------------------------------------------------------- *
 ** DATE           NAME             DESCRIPTION                               *
 ** 01/15/2008     Liangwen.Zhen    Create.                         *
 ******************************************************************************/

/**---------------------------------------------------------------------------*
 **                         Dependencies                                      *
 **---------------------------------------------------------------------------*/ 


/**---------------------------------------------------------------------------*
 **                         Debugging Flag                                    *
 **---------------------------------------------------------------------------*/

#ifndef _LCM_PROD_H_
#define _LCM_PROD_H_

#include "lcm_cfg.h"
/**---------------------------------------------------------------------------*
 **                         Compiler Flag                                     *
 **---------------------------------------------------------------------------*/
#ifdef   __cplusplus
    extern   "C" 
    {
#endif
/**---------------------------------------------------------------------------*
 **                         Macro Definition                                   *
 **---------------------------------------------------------------------------*/

/**---------------------------------------------------------------------------*
 **                      DATA STRUCTURE Definition                            *
 **---------------------------------------------------------------------------*/


/**---------------------------------------------------------------------------*
 **                         Constant Variables                                *
 **---------------------------------------------------------------------------*/

/**---------------------------------------------------------------------------*
 **                     Local Function Prototypes                             *
 **---------------------------------------------------------------------------*/
/**---------------------------------------------------------------------------*
 **                     PUBLIC Function Prototypes                            *
 **---------------------------------------------------------------------------*/
/*****************************************************************************/
//  Description:    This function is used to get LCD spec information
//  Author:         Liangwen.Zhen
//  Note:           
/*****************************************************************************/
PUBLIC LCD_SPEC_INFO_T_PTR TF_GetLcdSpecInfo(uint32 lcd_id);

/*****************************************************************************/
//  Description:    This function is used to get lcd back light information
//  Author:         Liangwen.Zhen
//  Note:           
/*****************************************************************************/
PUBLIC LCD_BACKLIGHT_INFO_T_PTR TF_GetBackLightInfo(uint32 lcd_id);

/**---------------------------------------------------------------------------*
 **                         Compiler Flag                                     *
 **---------------------------------------------------------------------------*/
#ifdef   __cplusplus
    }
    
#endif  // End of lcm_prod.c

#endif  // End of _LCM_PROD_H_