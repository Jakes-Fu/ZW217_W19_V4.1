/*****************************************************************************
** File Name:      rtp_test.h                                                *
** Author:         kelly.li                                                  *
** Date:           04/24/2009                                                *
** Copyright:      2007 Spreadtrum, Incorporated. All Rights Reserved.       *
** Description:    This file is used to describe the rtp test                *
*****************************************************************************/

#ifndef _RTP_TEST_H_
#define _RTP_TEST_H_ 

/**--------------------------------------------------------------------------*
 **                         Include Files                                    *
 **--------------------------------------------------------------------------*/
#include "sci_types.h"
#include "os_api.h"
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

        
/*---------------------------------------------------------------------------*/
/*                          TYPE AND CONSTANT                                */
/*---------------------------------------------------------------------------*/

typedef struct 
{
    _SIGNAL_VARS    
    uint16  rtp_port;
    uint16  rtcp_port;
}RTPTEST_SESSION_RESULT_SIG_T;
/**--------------------------------------------------------------------------*
 **                         FUNCTION DEFINITION                              *
 **--------------------------------------------------------------------------*/
/*****************************************************************************/
//  Description : 
//  Global resource dependence : 
//  Author: kelly.li
//  Note: 
/*****************************************************************************/
PUBLIC uint32 RTPTEST_CreateTask(void);

/****************************************************************************/
// 	Description : send data with rtp protocol
//	Global resource dependence : 
//  Author: kelly.li
//	Note:	
/****************************************************************************/
PUBLIC BOOLEAN RTPTEST_SendRtpData(void);

/****************************************************************************/
// 	Description : send rtcp
//	Global resource dependence : 
//  Author: kelly.li
//	Note:	
/****************************************************************************/
PUBLIC BOOLEAN RTPTEST_SendRtcp(void);

/****************************************************************************/
// 	Description : close rtp session
//	Global resource dependence : 
//  Author: kelly.li
//	Note:	
/****************************************************************************/
PUBLIC BOOLEAN RTPTEST_Close(void);

/****************************************************************************/
// 	Description : send rtcp app
//	Global resource dependence : 
//  Author: kelly.li
//	Note:	
/****************************************************************************/
PUBLIC BOOLEAN RTPTEST_SendRtcpApp(void);

/**--------------------------------------------------------------------------*
 **                         Compiler Flag                                    *
 **--------------------------------------------------------------------------*/
#ifdef   __cplusplus
    }
#endif

#endif