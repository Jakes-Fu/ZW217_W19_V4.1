/******************************************************************************
 ** File Name:      rtos_cfg.h                                                *
 ** Author:         Xueliang.Wang                                             *
 ** DATE:           07/08/2002                                                *
 ** Copyright:      2002 Spreatrum, Incoporated. All Rights Reserved.         *
 ** Description:    This file contain some config information on RTOS.        *
 **                 User can modify it.                                       *
 ******************************************************************************

 ******************************************************************************
 **                        Edit History                                       *
 ** ------------------------------------------------------------------------- *
 ** DATE           NAME             DESCRIPTION                               *
 ** 07/08/2002     Xueliang.Wang    Create.                                   *
 ******************************************************************************/

#ifndef _RTOS_CFG_H
#define _RTOS_CFG_H

/**---------------------------------------------------------------------------*
 **                         Dependencies                                      *
 **---------------------------------------------------------------------------*/

/**---------------------------------------------------------------------------*
 **                         Compiler Flag                                     *
 **---------------------------------------------------------------------------*/
#ifdef __cplusplus
    extern   "C"
    {
#endif

/**---------------------------------------------------------------------------*
 **                         Defines                                           *
 **---------------------------------------------------------------------------*/
// Use memory debug code.
#define SCI_MEMORY_DEBUG

// Trace out log message.
#define SCI_TRACE_MODE

/**---------------------------------------------------------------------------*
 **                         Compiler Flag                                     *
 **---------------------------------------------------------------------------*/
#ifdef __cplusplus
    }
#endif

#endif /* End rtos_cfg.h*/