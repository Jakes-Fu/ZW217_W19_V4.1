/*****************************************************************************
** File Name:      watchface_config_adapter.h                                *
** Author:         yifan.yang                                                *
** Date:           10/08/2021                                                *
** Copyright:      2004 Spreadtrum, Incoporated. All Rights Reserved.        *
** Description:    This file is used to define json adaptation.              *
******************************************************************************
**                         Important Edit History                            *
** --------------------------------------------------------------------------*
** DATE           NAME             DESCRIPTION                               *
** 10/2021       chunjuan.liang        Create                                *
******************************************************************************/

/**--------------------------------------------------------------------------*
**                         Include Files                                     *
**---------------------------------------------------------------------------*/

#include "json_parser_common.h"
#include "ctrlwf_export.h"

/**--------------------------------------------------------------------------*
**                         MACRO DEFINITION                                  *
**---------------------------------------------------------------------------*/



/**--------------------------------------------------------------------------*
**                         TYPE AND CONSTANT                                 *
**---------------------------------------------------------------------------*/

typedef enum
{
    ADAPTER_SUCCESS,//�����ɹ�
    ADAPTER_PROCESS_FINISHED,//layout���ڣ�����Ҫ��ȡconfig��Ϣ
    ADAPTER_OPERATION_FAILED,//layout���ڣ�ɾ��configʧ��
    ADAPTER_PARAM_ERROR,//����ʧ��
    ADAPTER_MAX
}WF_CONFIG_ADAPTER_RESULT_E;
/**--------------------------------------------------------------------------*
**                          LOCAL VARIABLES                                  *
**---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*
**                          LOCAL FUNCTION                                   *
**---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*
**                          GLOBAL FUNCTION                                  *
**---------------------------------------------------------------------------*/
/*****************************************************************************/
//  Description :JSONPARSER_ParseAdaptation:С��JSON�ļ�����
//  Parameter: [In] p_wf_id:����id
//  Author: yifan.yang
//  Note:
/*****************************************************************************/
PUBLIC BOOLEAN JSONPARSER_Adaptation(char* p_wf_id);
