/*****************************************************************************
** File Name:      mic_sample_demo.h                                         *
** Author:                                                                   *
** Date:           11/12/2010                                                *
** Copyright:      2010 Spreadtrum, Incoporated. All Rights Reserved.        *
** Description:    This file is used to mic sample  demo                     *
*****************************************************************************
**                         Important Edit History                            *
** --------------------------------------------------------------------------*
** DATE           NAME             DESCRIPTION                               *
** 12/2010        hai.li           Create
******************************************************************************/

#ifndef _H263_STREAM_DEMO_H_
#define _H263_STREAM_DEMO_H_

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
 **                         FUNCTION DEFINITION                              *
 **--------------------------------------------------------------------------*/


/*****************************************************************************/
//  Description : API of start demo
//  Global resource dependence : none
//  Author: hai.li
//  Note: 
/*****************************************************************************/
PUBLIC void MIC_Sample_Demo_Start(void);

/*****************************************************************************/
//  Description : API of stop demo
//  Global resource dependence : none
//  Author: hai.li
//  Note: 
/*****************************************************************************/
PUBLIC void MIC_Sample_Demo_Stop(void);
/**--------------------------------------------------------------------------*
 **                         Compiler Flag                                    *
 **--------------------------------------------------------------------------*/
#ifdef   __cplusplus
    }
#endif

#endif
