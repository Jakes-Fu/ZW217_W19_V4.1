/******************************************************************************
 ** File Name:      dc_preview.h                                                        *
 ** Author:         Jing.Li                                                             *
 ** DATE:           2008/12/01                                                          *
 ** Copyright:      2008 Spreatrum, Incoporated. All Rights Reserved.                   *
 ** Description:                                                                        *
 *******************************************************************************

 ******************************************************************************
 **                        Edit History                                                *
 ** ----------------------------------------------------------------------------------- *
 ** DATE           NAME             DESCRIPTION                                        *
 ** 2008/12/01     Jing.Li          Create.                                            *
 ******************************************************************************/

#ifndef DC_PREVIEW_H
#define DC_PREVIEW_H
/**---------------------------------------------------------------------------*
 **                         Dependencies                                      *
 **---------------------------------------------------------------------------*/
#include "dal_dcamera.h"

/**---------------------------------------------------------------------------*
 **                         Debugging Flag                                    *
 **---------------------------------------------------------------------------*/

/**---------------------------------------------------------------------------*
 **                         Compiler Flag                                     *
 **---------------------------------------------------------------------------*/

#ifdef   __cplusplus
    extern   "C" 
    {
#endif

/**---------------------------------------------------------------------------*
 **                         Macro define         	                          *
 **---------------------------------------------------------------------------*/

/**---------------------------------------------------------------------------*
 **                         Data Structures                                   *
 **---------------------------------------------------------------------------*/
typedef struct preview_ops_handler{
    int32 (*check_status)(void);
    int32 (*check_param)(DCAMERA_PREVIEW_PARAM_T * param_ptr);
    int32 (*set_param)(DCAMERA_PREVIEW_PARAM_T * param_ptr);
    int32 (*start)(void);
    int32 (*stop)(void);
}PREVIEW_OPS_HANDLER_T;

/**----------------------------------------------------------------------------*
**                             Data Prototype                                 **
**----------------------------------------------------------------------------*/

/**----------------------------------------------------------------------------*
**                           Function Prototype                               **
**----------------------------------------------------------------------------*/

/******************************************************************************
// Description: 	get preview operation handlers
// Author:     		jing.li
// Input:      		none
// Output:		    none
// Return:          preview operation handler struct pointer
// Note:       		
******************************************************************************/
PUBLIC PREVIEW_OPS_HANDLER_T* DC_Preview_GetOpsHandler(void);

#ifdef __cplusplus
    }
#endif


#endif  /*#ifndef DC_PREVIEW_H*/