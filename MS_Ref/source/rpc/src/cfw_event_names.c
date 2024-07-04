/* Copyright (C) 2018 RDA Technologies Limited and/or its affiliates("RDA").
 * All rights reserved.
 *
 * This software is supplied "AS IS" without any warranties.
 * RDA assumes no responsibility or liability for the use of the software,
 * conveys no license or title under any patent, copyright, or mask work
 * right to the product. RDA reserves the right to make changes in the
 * software without notification.  RDA also make no representation or
 * warranty that such application will be suitable for the specified use
 * without further testing or modification.
 */
#include "cfw.h"
#include "cfw_event.h"
#include <stdint.h>
#include <stdlib.h>

#define CONFIG_EVENT_NAME_ENABLED

#ifdef CONFIG_EVENT_NAME_ENABLED
#define DECL_EVENT_NAME(event) event, #event

static const struct id2name
{
    uint32_t id;
    const char *name;
} gCfwEventNames[] = {
    {DECL_EVENT_NAME(EV_DM_POWER_ON_IND)},
    {DECL_EVENT_NAME(EV_DM_POWER_OFF_IND)},
    {DECL_EVENT_NAME(EV_TIM_ALRAM_IND)},
    {DECL_EVENT_NAME(EV_DM_UART_RECEIVE_DATA_IND)},
    {DECL_EVENT_NAME(EV_DM_EXTI_IND)},
    {DECL_EVENT_NAME(EV_DM_GPIO_IND)},
    {DECL_EVENT_NAME(EV_DM_RECORD_END_IND)},
    {DECL_EVENT_NAME(EV_DM_STREAM_END_IND)},
    {DECL_EVENT_NAME(EV_DM_GPADC_IND)},
    {DECL_EVENT_NAME(EV_TIM_SET_TIME_IND)},
    {DECL_EVENT_NAME(EV_DM_SPEECH_IND)},

    {DECL_EVENT_NAME(EV_DM_AUDIO_CONTROL_IND)},
    {DECL_EVENT_NAME(EV_DM_SET_AUDIO_VOLUME_IND)},
    {DECL_EVENT_NAME(EV_DM_SET_MIC_GAIN_IND)},
    {DECL_EVENT_NAME(EV_DM_SET_AUDIO_MODE_IND)},

    {DECL_EVENT_NAME(EV_DM_AUD_SETUP_IND)},
    {DECL_EVENT_NAME(EV_DM_AUD_STREAM_START_IND)},
    {DECL_EVENT_NAME(EV_DM_AUD_STREAM_STOP_IND)},
    {DECL_EVENT_NAME(EV_DM_AUD_STREAM_PAUSE_IND)},
    {DECL_EVENT_NAME(EV_DM_AUD_STREAM_RECORD_IND)},
    {DECL_EVENT_NAME(EV_DM_AUD_TEST_MODE_SETUP_IND)},
    {DECL_EVENT_NAME(EV_DM_AUD_FORCE_RECV_MIC_SEL_IND)},
    {DECL_EVENT_NAME(EV_DM_AUD_SET_CUR_OUTPUT_DEVICE_IND)},
    {DECL_EVENT_NAME(EV_DM_AUD_MUTE_OUTPUT_DEVICE_IND)},
    {DECL_EVENT_NAME(EV_DM_AUD_LOUDSPK_WITH_EP_IND)},

    {DECL_EVENT_NAME(EV_DM_VOIS_RECORD_START_IND)},
    {DECL_EVENT_NAME(EV_DM_VOIS_RECORD_STOP_IND)},

    {DECL_EVENT_NAME(EV_DM_ARS_SETUP_IND)},
    {DECL_EVENT_NAME(EV_DM_ARS_RECORD_IND)},
    {DECL_EVENT_NAME(EV_DM_ARS_PAUSE_IND)},
    {DECL_EVENT_NAME(EV_DM_ARS_STOP_IND)},

    {DECL_EVENT_NAME(EV_KEY_DOWN)},
    {DECL_EVENT_NAME(EV_KEY_PRESS)},
    {DECL_EVENT_NAME(EV_KEY_UP)},
    {DECL_EVENT_NAME(EV_TIMER)},
    {DECL_EVENT_NAME(EV_DOUBLE_KEY_DOWN)},
    {DECL_EVENT_NAME(EV_DOUBLE_KEY_UP)},
    {DECL_EVENT_NAME(EV_DM_UART_MUX_RECEIVE_DATA_IND)},
    {DECL_EVENT_NAME(EV_DM_READ_UART_DATA_IND)},

    {DECL_EVENT_NAME(EV_PM_BC_IND)},

    {DECL_EVENT_NAME(EV_CFW_NW_SET_BAND_RSP)},
    {DECL_EVENT_NAME(EV_CFW_NW_GET_IMEI_RSP)},
    {DECL_EVENT_NAME(EV_CFW_NW_GET_SIGNAL_QUALITY_RSP)},
    {DECL_EVENT_NAME(EV_CFW_NW_SET_REGISTRATION_RSP)},
    {DECL_EVENT_NAME(EV_CFW_NW_DEREGISTER_RSP)},
    {DECL_EVENT_NAME(EV_CFW_NW_GET_AVAIL_OPERATOR_RSP)},
    {DECL_EVENT_NAME(EV_CFW_NW_ABORT_LIST_OPERATORS_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SET_COMM_RSP)},
    {DECL_EVENT_NAME(EV_CFW_NW_STORELIST_IND)},
    {DECL_EVENT_NAME(EV_CFW_XCPU_TEST_RSP)},
    {DECL_EVENT_NAME(EV_CFW_WCPU_TEST_RSP)},
    {DECL_EVENT_NAME(EV_CFW_CHANGE_RAT_RSP)},

    {DECL_EVENT_NAME(EV_CFW_CC_ACCEPT_SPEECH_CALL_RSP)},
    {DECL_EVENT_NAME(EV_CFW_CC_CALL_HOLD_MULTIPARTY_RSP)},
    {DECL_EVENT_NAME(EV_CFW_CC_INITIATE_SPEECH_CALL_RSP)},
    {DECL_EVENT_NAME(EV_CFW_CC_RELEASE_CALL_RSP)},
    {DECL_EVENT_NAME(EV_CFW_CC_CALL_SWAP_RSP)},
    {DECL_EVENT_NAME(EV_CFW_CC_RELEASE_CALL_IND)},
    {DECL_EVENT_NAME(EV_CFW_CC_ERROR_IND)},
    {DECL_EVENT_NAME(EV_CFW_CC_SPEECH_CALL_IND)},
    {DECL_EVENT_NAME(EV_CFW_CC_CRSSINFO_IND)},
    {DECL_EVENT_NAME(EV_CFW_CC_PROGRESS_IND)},
    {DECL_EVENT_NAME(EV_CFW_CC_CALL_INFO_IND)},
    {DECL_EVENT_NAME(EV_CFW_CC_AUDIOON_IND)},
    {DECL_EVENT_NAME(EV_CFW_CC_ALERT_IND)},
    {DECL_EVENT_NAME(EV_CFW_IMS_STATE_IND)},
    {DECL_EVENT_NAME(EV_CFW_CC_CALL_PATH_IND)},
    {DECL_EVENT_NAME(EV_CFW_CC_CALL_TI_ASSIGNED_IND)},
    {DECL_EVENT_NAME(EV_CFW_CC_AUDIO_RESTART_IND)},

    {DECL_EVENT_NAME(EV_CFW_SS_QUERY_CLIP_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SS_SET_CALL_WAITING_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SS_QUERY_CALL_WAITING_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SS_SET_CALL_FORWARDING_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SS_QUERY_CALL_FORWARDING_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SS_SET_FACILITY_LOCK_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SS_GET_FACILITY_LOCK_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SS_CHANGE_PWD_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SS_QUERY_FACILITY_LOCK_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SS_QUERY_CLIR_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SS_QUERY_COLP_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SS_SEND_USSD_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SS_TERMINATE_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SS_QUERY_COLR_RSP)},

    {DECL_EVENT_NAME(EV_CFW_SIM_ADD_PBK_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_DELETE_PBK_ENTRY_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_GET_PBK_ENTRY_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_LIST_PBK_ENTRY_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_GET_PBK_STRORAGE_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_GET_PBK_STRORAGE_INFO_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_GET_PROVIDER_ID_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_CHANGE_PWD_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_GET_AUTH_STATUS_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_ENTER_AUTH_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_SET_FACILITY_LOCK_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_GET_FACILITY_LOCK_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_DELETE_MESSAGE_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_WRITE_MESSAGE_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_READ_MESSAGE_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_LIST_MESSAGE_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_GET_SMS_STORAGE_INFO_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_READ_BINARY_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_UPDATE_BINARY_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_GET_SMS_PARAMETERS_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_SET_SMS_PARAMETERS_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_GET_MR_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_SET_MR_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_COMPOSE_PDU_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SAT_ACTIVATION_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SAT_GET_STATUS_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SAT_RESPONSE_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SAT_GET_INFORMATION_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_SET_PREF_OPERATOR_LIST_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_GET_PREF_OPERATOR_LIST_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_GET_PREF_OPT_LIST_MAXNUM_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_SET_PBKMODE_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_GET_PBKMODE_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_INIT_SMS_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_LIST_COUNT_PBK_ENTRY_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_RESET_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_GET_PUCT_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_SET_PUCT_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_GET_ACMMAX_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_SET_ACMMAX_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_SET_ACM_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_GET_ACM_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_READ_EF_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_GET_FILE_STATUS_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_READ_RECORD_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_UPDATE_RECORD_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_GET_SPN_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_GET_SMS_TOTAL_NUM_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_GET_ICCID_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_CLOSE_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_READ_FILES_RSP)},

    {DECL_EVENT_NAME(EV_CFW_SMS_DELETE_MESSAGE_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SMS_GET_STORAGE_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SMS_SET_STORAGE_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SMS_LIST_MESSAGE_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SMS_READ_MESSAGE_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SMS_SEND_MESSAGE_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SMS_SET_CENTER_ADDR_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SMS_GET_CENTER_ADDR_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SMS_SET_TEXT_MODE_PARAM_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SMS_GET_TEXT_MODE_PARAM_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SMS_WRITE_MESSAGE_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SMS_LIST_MESSAGE_HRD_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SMS_COPY_MESSAGE_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SMS_SET_UNREAD2READ_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SMS_SET_UNSENT2SENT_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SMS_SET_READ2UNREAD_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SMS_SET_PARAM_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_PATCH_RSP)},
    {DECL_EVENT_NAME(EV_CFW_CB_READ_SIM_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SMS_MOVE_RSP)},
    {DECL_EVENT_NAME(EV_CFW_CB_SET_MID_SIM_RSP)},
    {DECL_EVENT_NAME(EV_CFW_SIM_PATCHEX_RSP)},

    {DECL_EVENT_NAME(EV_CFW_PBK_ADD_RSP)},
    {DECL_EVENT_NAME(EV_CFW_PBK_UPDATE_ENTRY_RSP)},
    {DECL_EVENT_NAME(EV_CFW_PBK_DELETE_RSP)},
    {DECL_EVENT_NAME(EV_CFW_PBK_DELETE_BATCH_ENTRIES_RSP)},
    {DECL_EVENT_NAME(EV_CFW_PBK_FIND_ENTRY_RSP)},
    {DECL_EVENT_NAME(EV_CFW_PBK_LIST_ENTRIES_RSP)},
    {DECL_EVENT_NAME(EV_CFW_PBK_GET_ENTRY_RSP)},
    {DECL_EVENT_NAME(EV_CFW_PBK_COPY_ENTRIES_RSP)},
    {DECL_EVENT_NAME(EV_CFW_PBK_ADD_ENTRY_ITEM_RSP)},
    {DECL_EVENT_NAME(EV_CFW_PBK_GET_ENTRY_ITEMS_RSP)},
    {DECL_EVENT_NAME(EV_CFW_PBK_DELETE_ENTRY_ITEM_RSP)},
    {DECL_EVENT_NAME(EV_CFW_PBK_ADD_CALLLOG_ENTTRY_RSP)},
    {DECL_EVENT_NAME(EV_CFW_PBK_GET_CALLLOG_ENTRY_RSP)},
    {DECL_EVENT_NAME(EV_CFW_PBK_LIST_CALLLOG_ENTRIES_RSP)},
    {DECL_EVENT_NAME(EV_CFW_PBK_DELETE_CALLLOG_ALL_ENTRIES_RSP)},
    {DECL_EVENT_NAME(EV_CFW_PBK_CANCEL_RSP)},
    {DECL_EVENT_NAME(EV_CFW_PBK_DELETE_CALLLOG_OLDEST_ENTRY_RSP)},

    {DECL_EVENT_NAME(EV_CFW_GPRS_CTX_MODIFY_ACC_RSP)},
    {DECL_EVENT_NAME(EV_CFW_GPRS_ATT_RSP)},
    {DECL_EVENT_NAME(EV_CFW_GPRS_ACT_RSP)},
    {DECL_EVENT_NAME(EV_CFW_GPRS_CXT_ACTIVE_RSP)},
    {DECL_EVENT_NAME(EV_CFW_GPRS_MOD_RSP)},
    {DECL_EVENT_NAME(EV_CFW_WIFI_CONNECTED_RSP)},

    {DECL_EVENT_NAME(EV_CFW_TCPIP_SOCKET_CONNECT_RSP)},
    {DECL_EVENT_NAME(EV_CFW_TCPIP_SOCKET_CLOSE_RSP)},
    {DECL_EVENT_NAME(EV_CFW_TCPIP_SOCKET_SEND_RSP)},

    {DECL_EVENT_NAME(EV_CFW_FTP_LONGIN_RSP)},
    {DECL_EVENT_NAME(EV_CFW_FTP_FILE_DOWNLOAD_RSP)},
    {DECL_EVENT_NAME(EV_CFW_FTP_LIST_RSP)},
    {DECL_EVENT_NAME(EV_CFW_FTP_CHANGEDIR_RSP)},
    {DECL_EVENT_NAME(EV_CFW_FTP_REC_DATA_IND)},

    {DECL_EVENT_NAME(EV_CFW_ME_SET_FACILITY_LOCK_RSP)},
    {DECL_EVENT_NAME(EV_CFW_ME_GET_FACILITY_LOCK_RSP)},
    {DECL_EVENT_NAME(EV_CFW_ME_CHANGE_PWD_RSP)},

    {DECL_EVENT_NAME(EV_CFW_TSM_INFO_IND)},
    {DECL_EVENT_NAME(EV_CFW_TSM_INFO_END_RSP)},
    {DECL_EVENT_NAME(EV_CFW_TSM_SYNC_INFO_IND)},
    {DECL_EVENT_NAME(EV_CFW_TSM_SYNC_INFO_END_RSP)},
    {DECL_EVENT_NAME(EV_RMT_STTPC_REQ)},
    {DECL_EVENT_NAME(EV_RMT_STTPC_RSP)},

    {DECL_EVENT_NAME(EV_RMT_APP_REQ)},
    {DECL_EVENT_NAME(EV_RMT_APP_RSP)},

    {DECL_EVENT_NAME(EV_DIAG_RECEIVE_DATA)},

    {DECL_EVENT_NAME(EV_CFW_WIFI_INIT_RSP)},
    {DECL_EVENT_NAME(EV_CFW_WIFI_DEINIT_RSP)},

#ifdef BT_TETHER_SUPPORT
    {DECL_EVENT_NAME(EV_BT_TETHER_DATA_IND)},
#endif
    {DECL_EVENT_NAME(EV_CFW_SAT_REFRESH_FILE_CHG_RSP)},
    {DECL_EVENT_NAME(EV_CFW_INIT_IND)},
    {DECL_EVENT_NAME(EV_CFW_SRV_STATUS_IND)},
    {DECL_EVENT_NAME(EV_CFW_NW_SIGNAL_QUALITY_IND)},
    {DECL_EVENT_NAME(EV_CFW_NW_REG_STATUS_IND)},
    {DECL_EVENT_NAME(EV_CFW_NEW_SMS_IND)},
    {DECL_EVENT_NAME(EV_CFW_SMS_INFO_IND)},
    {DECL_EVENT_NAME(EV_CFW_SIM_STATUS_IND)},
    {DECL_EVENT_NAME(EV_CFW_SS_USSD_IND)},

    {DECL_EVENT_NAME(EV_CFW_SAT_CMDTYPE_IND)},
    {DECL_EVENT_NAME(EV_CFW_PBK_IND)},
    {DECL_EVENT_NAME(EV_CFW_NW_NETWORKINFO_IND)},
    {DECL_EVENT_NAME(EV_CFW_GPRS_CXT_ACTIVE_IND)},
    {DECL_EVENT_NAME(EV_CFW_GPRS_CXT_DEACTIVE_IND)},
    {DECL_EVENT_NAME(EV_CFW_GPRS_MOD_IND)},
    {DECL_EVENT_NAME(EV_CFW_GPRS_STATUS_IND)},
    {DECL_EVENT_NAME(EV_CFW_GPRS_DATA_IND)},
    {DECL_EVENT_NAME(EV_CFW_GPRS_CTRL_RELEASE_IND)},

    {DECL_EVENT_NAME(EV_CFW_TCPIP_REV_DATA_IND)},
    {DECL_EVENT_NAME(EV_CFW_TCPIP_CLOSE_IND)},
    {DECL_EVENT_NAME(EV_CFW_TCPIP_ERR_IND)},
    {DECL_EVENT_NAME(EV_CFW_TCPIP_ACCEPT_IND)},
    {DECL_EVENT_NAME(EV_CFW_ICMP_DATA_IND)},

    {DECL_EVENT_NAME(EV_CFW_DNS_RESOLV_SUC_IND)},
    {DECL_EVENT_NAME(EV_CFW_DNS_RESOLV_ERR_IND)},
    {DECL_EVENT_NAME(EV_CFW_PPP_DATA_IND)},
    {DECL_EVENT_NAME(EV_CFW_PPP_TERMINATE_IND)},

    //Frank)},
    {DECL_EVENT_NAME(EV_CFW_NEW_EMS_IND)},
    {DECL_EVENT_NAME(EV_CFW_ATT_STATUS_IND)},
    {DECL_EVENT_NAME(EV_CFW_CC_STATUS_IND)},
    {DECL_EVENT_NAME(EV_CFW_CC_PROGRESS_IND)},

    {DECL_EVENT_NAME(EV_CFW_CB_MSG_IND)},
    {DECL_EVENT_NAME(EV_CFW_CB_PAGE_IND)},

    {DECL_EVENT_NAME(EV_CFW_BLUETOOTH_DATA_IND)},
    {DECL_EVENT_NAME(EV_CFW_BLUETOOTH_WAKEUP_IND)},

    {DECL_EVENT_NAME(EV_CFW_REG_UPDATE_IND)},

#ifdef __SUPPORT_SMSCLASS__
    {DECL_EVENT_NAME(EV_CFW_NEW_SMS_PDU_IND)},
#endif
    {DECL_EVENT_NAME(EV_CFW_ICMPV4_DATA_REQ)},
    {DECL_EVENT_NAME(EV_CFW_ICMPV4_DATA_RPY)},

    {DECL_EVENT_NAME(EV_CFW_EXIT_IND)},
#if (defined LTE_NBIOT_SUPPORT) || (defined LTE_SUPPORT)
    {DECL_EVENT_NAME(EV_CFW_ERRC_CONNSTATUS_IND)},
#endif

//#ifdef LTE_SUPPORT
    {DECL_EVENT_NAME(EV_CFW_GPRS_PDN_CTX_ACTIVE_IND)},
    {DECL_EVENT_NAME(EV_CFW_GPRS_SEC_CTX_ACTIVE_IND)},
    {DECL_EVENT_NAME(EV_CFW_GPRS_SEC_CTX_DEACTIVE_IND)},
    {DECL_EVENT_NAME(EV_CFW_GPRS_CTX_MODIFY_IND)},
//#endif

#ifdef CFW_VOLTE_SUPPORT
    {DECL_EVENT_NAME(EV_CFW_EMC_NUM_LIST_IND)},
#endif

    {DECL_EVENT_NAME(EV_EMU_SCM_REQ)},
    {DECL_EVENT_NAME(EV_EMU_SCL_RSP)},
    {DECL_EVENT_NAME(EV_EMU_SCL_REQ)},
    {DECL_EVENT_NAME(EV_EMU_SCL_TST)},
    {DECL_EVENT_NAME(EV_EMU_TRACE)},
    {DECL_EVENT_NAME(EV_EMU_SYSTEM)},
    {DECL_EVENT_NAME(EV_EMU_EXIT)},
    {DECL_EVENT_NAME(EV_EMU_SCL_AUDIO)},
    {DECL_EVENT_NAME(EV_EMU_LCD)},
    {DECL_EVENT_NAME(EV_EMU_INPUT)},
};

static int _idcmp(const void *key, const void *p)
{
    uint32_t ik = *(const uint32_t *)key;
    uint32_t ip = *(const uint32_t *)p;
    return (ik > ip) ? 1 : (ik < ip) ? -1 : 0;
}
#endif

const char *CFW_EventName(uint32_t id)
{
#ifdef CONFIG_EVENT_NAME_ENABLED
    
    struct id2name *p;
    const size_t count = sizeof(gCfwEventNames) / sizeof(gCfwEventNames[0]);

#if 0 // When new event names are added, open this piece of code to check order
    int n;
    for (n = 1; n < count; n++)
    {
        if (gCfwEventNames[n].id <= gCfwEventNames[n - 1].id)
            SCI_TraceLow("EVENT names not in order: %d", gCfwEventNames[n].id);
    }
#endif

    p = bsearch(
        &id, gCfwEventNames, count,
        sizeof(gCfwEventNames[0]), _idcmp);

    if (p != NULL)
        return p->name;
#endif
    return "";
}