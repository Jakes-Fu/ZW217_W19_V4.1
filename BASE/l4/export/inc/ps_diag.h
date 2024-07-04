/******************************************************************************
 ** File Name:      Layer1_diag.h                                             *
 ** Author:                                                      		      *
 ** DATE:                                                                     *
 ** Copyright:      2001 Spreadtrum, Incoporated. All Rights Reserved.        *
 ** Description:                                                              *
 ******************************************************************************

 ******************************************************************************
 **                        Edit History                                       *
 ** ------------------------------------------------------------------------- *
 ** DATE           NAME             DESCRIPTION                               *
 ******************************************************************************/
 
#ifndef _PS_DIAG_H
#define _PS_DIAG_H

/**---------------------------------------------------------------------------*
 **                         Dependencies                                      *
 **---------------------------------------------------------------------------*/
#include "os_api.h"

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
 **                         Global variables                                  *
 **---------------------------------------------------------------------------*/

/**---------------------------------------------------------------------------*
 **                     Function Prototypes                             *
 **---------------------------------------------------------------------------*/

/*****************************************************************************/
// 	Description : handle diag ps cmd  
//	Global resource dependence : none
//  Author: shijun
//	Note:
/*****************************************************************************/
extern uint32 ENG_HandleDiagCmdRoutine( uint8 **dest_ptr,       // Pointer of the response message.
            uint16 *dest_len_ptr,   // Pointer of size of the response message in uin8.
            const uint8 *src_ptr,   // Pointer of the input message. 
            uint16 src_len );
/**---------------------------------------------------------------------------*
 **                         Compiler Flag                                     *
 **---------------------------------------------------------------------------*/
#ifdef   __cplusplus
    }
#endif

#endif	//_LAYER1_DIAG_H