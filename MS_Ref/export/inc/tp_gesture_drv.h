
/******************************************************************************
 ** File Name:      tp_gesture_drv.h                                            *
 ** DATE:           2012.03.19                                                *
 ** Copyright:      2012 Spreatrum, Incoporated. All Rights Reserved.         *
 ** Description:                                                              *
 **                                                                           *
 **                                                                           *
 ******************************************************************************
 ******************************************************************************
 **                               Edit History                                *
 ** ------------------------------------------------------------------------- *
 **     DATE          NAME             DESCRIPTION                            *
 **  2012.03.19                         Create.                               *
 ******************************************************************************/
/******************************************************************************/
#ifndef _TP_GESTURE_DRV_H_
#define _TP_GESTURE_DRV_H_

/**---------------------------------------------------------------------------*
 **                             Dependencies                                  *
 **---------------------------------------------------------------------------*/
#include "tp_srv.h"
/**---------------------------------------------------------------------------*
 **                            Compiler Flag                                  *
 **---------------------------------------------------------------------------*/
#ifdef __cplusplus
extern   "C" 
{
#endif

/**---------------------------------------------------------------------------*
 **                           Macros & Enums                                  *
 **---------------------------------------------------------------------------*/


/**---------------------------------------------------------------------------*
 **                           Data Structures                                 *
 **---------------------------------------------------------------------------*/

/**---------------------------------------------------------------------------*
 **                             Variables                                     *
 **---------------------------------------------------------------------------*/

/**---------------------------------------------------------------------------*
 **                         Function Prototypes                               *
 **---------------------------------------------------------------------------*/
/*****************************************************************************/
//  FUNCTION:     TP_SetGesture_Reset
//  Description:  Reset after pen down
//	Note:
/*****************************************************************************/
PUBLIC void TP_SetGesture_Reset(TPDSVR_SIG_T *sig);

/*****************************************************************************/
//  FUNCTION:     TP_Gesture_Read
//  Description:  the function is verifying gesture
//	Note:
/*****************************************************************************/
PUBLIC void TP_Gesture_Read(TPDSVR_SIG_T *sig);

/*****************************************************************************/
//  Function name:	TP_Gesture_Init
//  Description:
//  Global resource dependence: 
//  Note:
/*****************************************************************************/
PUBLIC void TP_Gesture_Init(void);

/*****************************************************************************/
//  Function name:	TP_Gesture_Uninit
//  Description:
//  Global resource dependence: 
//  Note:
/*****************************************************************************/
PUBLIC void TP_Gesture_Uninit(void);

/*****************************************************************************/
//  Function name:	TP_Ioctl
//  Description:
//  Global resource dependence: 
//  Note:
/*****************************************************************************/
PUBLIC void TP_Ioctl(uint32 cmd, void *arg);

#ifdef __cplusplus
}
#endif

/******************************************************************************/
#endif //#ifndef _TP_GESTURE_DRV_H_