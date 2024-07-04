/****************************************************************************
** File Name:      mmieng_menutable.h	                                    *
** Author:         allen				                                    *
** Date:           2004.09.09												*
** Copyright:      2003 Spreadtrum, Incoporated. All Rights Reserved. 		*
** Description:    									               			*
*****************************************************************************
**                         Important Edit History                        							*
** -------------------------------------------------------------------------*
** DATE           NAME             DESCRIPTION                             						*
** 09/2004        allen            Create
** 
****************************************************************************/

#ifndef _MMIENG_MENUTABLE_H_
#define _MMIENG_MENUTABLE_H_

#include "mmi_module.h"

/**---------------------------------------------------------------------------*
 **                         Compiler Flag                                     *
 **---------------------------------------------------------------------------*/
#ifdef __cplusplus
    extern   "C"
    {
#endif

/*-------------------------------------------------------------------------*/
/*                         TYPES/CONSTANTS                                 */
/*-------------------------------------------------------------------------*/

#define TIP_NULL 0

//˵ID
typedef enum
{
    MMIENG_MENU_ID_MIN = (MMI_MODULE_ENG << 16),
    ID_ENG_HELPINFO,
    ID_ENG_VERSIONINFO,
#ifdef WRE_SUPPORT
    ID_ENG_WRE_VERSIONINFO,
#endif
    ID_ENG_3RDPARTY_VERSIONINFO,    
    ID_ENG_NETINFO,
    ID_ENG_PHONEINFO,
    ID_ENG_ADC_CALIBRATE_INFO,    
    ID_ENG_RESTOREENG,
    ID_ENG_PARASET,
	ID_ENG_APPSET,
    ID_ENG_LAYER1MONITOR,
    ID_ENG_CARDLOG,
    ID_ENG_IQ_MODE,    
/*[START] Jerry Liang for ENG MODE powersweep 2008/07/31*/
//    ID_ENG_POWERSWEEP_INFO, //modify by mary
/*[END] Jerry Liang for ENG MODE powersweep 2008/07/31*/
    ID_ENG_BTINFO,
    ID_ENG_BT_ADDRESS,
    ID_ENG_ENTER_EUT_MODE,
    ID_ENG_LEAVE_EUT_MODE,
    ID_ENG_BT_SSP_DEBUG_MODE,
    ID_ENG_BT_BQB_MODE,
    ID_ENG_BT_PS_BQB_TEST,
    ID_ENG_BT_VER_INFO,
    ID_ENG_ENTER_NOSIGNAL_MODE,
    ID_ENG_ENTER_NOSIGNAL_MODE_TX,
    ID_ENG_ENTER_NOSIGNAL_MODE_RX,
    ID_ENG_ENTER_NOSIGNAL_MODE_BLE_TX,
    ID_ENG_ENTER_NOSIGNAL_MODE_BLE__RX,
    ID_ENG_CONNECTIVITY_ALL,
    ID_ENG_BLE_TEST,
    ID_ENG_BT_VISIBLITY_SET,
    ID_ENG_BT_LOCAL_NAME_SET,
    ID_ENG_BT_ROLE_TEST,
    ID_ENG_TELEPHONY_ALL,
    ID_ENG_DEBUG_LOG_ALL,
    ID_ENG_DEB_GPRS_ATTACH_SERVICE,
    ID_ENG_DEB_THERMAL_SWITCH,
    ID_ENG_DEB_APR_SET,
    ID_ENG_HARDWARE_ALL,
    ID_ENG_VIBRATE_TEST_INFO,
    ID_ENG_CAMERA_LCD_INFO,
    ID_ENG_CAM_POW_TEST_MODE,
    ID_ENG_CON_FM_INFO,
    ID_ENG_FM_REG_MODE,
    ID_ENG_FM_OBSERVE_STATE,
    ID_ENG_FM_DATA_CAPTURE,
    ID_ENG_FM_CHANNEL_SET,
    ID_ENG_POWERKEY,
#ifdef DSP_USB_LOG
    ID_ENG_DSPCARD_LOG_ENABLE,//xuefangjiang 20110729
#endif
    ID_ENG_VOICEPARAM,
    ID_ENG_LCDPARAM,
    ID_ENG_DEBUGPARAM,
    ID_ENG_RFPARAM,
    ID_ENG_HWPARAM,
    ID_ENG_ARMLOG,
    ID_ENG_ARMLOG_POWER,
    ID_ENG_MTV_LOG,
    ID_ENG_MTV_LOG_SWITCH,
    ID_ENG_MTV_LOG_TO_BB_SWITCH,
    ID_ENG_MTV_LOG_STORAGE,
    ID_ENG_SLEEPMODE,
    ID_ENG_AUTOPOWERON,
    ID_ENG_DSPLOG,
    ID_ENG_GPRS,
    ID_ENG_SENSOR_MODE,
    ID_ENG_TCPIP_DEBUG, 
    //MS00216980 cheney
    ID_ENG_CMCC_TEST_FLAG,
    //MS00216980 cheney
    ID_ENG_XSR_DEBUG,   
    ID_ENG_DV_FRAME_FRE,
    ID_ENG_HIDDEN_PARTITION_VISIBLE,
    ID_ENG_CALLFORWARD_QUERY,
	ID_ENG_UA,
	ID_ENG_WAPDEBUG,
    ID_ENG_SMS_RETRY,
    ID_ENG_VOICEPARAM_HDSTTONE,
    ID_ENG_VOICEPARAM_CLOSE_HDSTTONE,
    ID_ENG_VOICEPARAM_EARPHTONE,
    ID_ENG_VOICEPARAM_CLOSE_EARPHTONE,
    ID_ENG_VOICEPARAM_HDSTDGT,
    ID_ENG_VOICEPARAM_HDFREDGT,
    ID_ENG_VOICEPARAM_EARPHDGT,
    ID_ENG_VOICEPARAM_HDSTPGA,
    ID_ENG_VOICEPARAM_HDFREPGA,
    ID_ENG_VOICEPARAM_EARPHPGA,
    ID_ENG_VOICEPARAM_HDSTSCL,
    ID_ENG_VOICEPARAM_HDFRESCL,
    ID_ENG_VOICEPARAM_EARPHSCL,
    ID_ENG_LCDPARAM_CON,
    ID_ENG_LCDPARAM_CON_MAIN,
    ID_ENG_LCDPARAM_CON_SUB,
    ID_ENG_LCDPARAM_BRT,
    ID_ENG_LCDPARAM_BRT_MAIN,
    ID_ENG_LCDPARAM_BRT_SUB,
    ID_ENG_DEBUGPARAM_SMSASSERT,
    ID_ENG_DEBUGPARAM_SMSASSERT_OPEN,
    ID_ENG_DEBUGPARAM_SMSASSERT_CLOSE,
    ID_ENG_DEBUGPARAM_BAND,
    ID_ENG_DEBUGPARAM_PORT,
    ID_ENG_DEBUGPARAM_PORT_DATA,
    ID_ENG_DEBUGPARAM_PORT_AT,
    ID_ENG_DEBUGPARAM_PORT_MIX,
    ID_ENG_DEBUGPARAM_PORT_CLOSE,
    ID_ENG_DEBUGPARAM_ASSERTMODE,
    ID_ENG_DEBUGPARAM_ASSERTMODE_DEBUG,
    ID_ENG_DEBUGPARAM_ASSERTMODE_REL,
    ID_ENG_DEBUGPARAM_ASSERTTARGET,
    ID_ENG_DEBUGPARAM_MANUALASSERT,
    ID_ENG_DEBUGPARAM_MANUALASSERT_RESTART,
    ID_ENG_DEBUGPARAM_MANUALASSERT_INFO,
    ID_ENG_DEBUGPARAM_WCN_ASSERT,
    ID_ENG_DEBUGPARAM_FORBID_PLMN,
    ID_ENG_DEBUGPARAM_PLMN_SELECT,
    ID_ENG_DEBUGPARAM_SIM1_PLMN_SELECT,
    ID_ENG_DEBUGPARAM_SIM2_PLMN_SELECT,
    ID_ENG_DEBUGPARAM_SIM3_PLMN_SELECT,
    ID_ENG_DEBUGPARAM_SIM4_PLMN_SELECT,
          
    ID_ENG_RFPARAM_SEND,
    ID_ENG_RFPARAM_SEND_OPEN,
    ID_ENG_RFPARAM_SEND_CLOSE,
    ID_ENG_HWPARAM_NETLOST,
    ID_ENG_HWPARAM_TCV,
    ID_ENG_HWPARAM_AFC,
    ID_ENG_HWPARAM_PA,
    ID_ENG_HWPARAM_AGC,
    ID_ENG_HWPARAM_RATE,
    ID_ENG_ARMLOG_ON,
    ID_ENG_ARMLOG_OFF,
    ID_ENG_SLEEPMODE_ON,
    ID_ENG_SLEEPMODE_OFF,
    ID_ENG_AUTOPOWERON_ON,
    ID_ENG_AUTOPOWERON_OFF,
    ID_ENG_CAP_OUTPUT, 
    ID_ENG_GPRS_ON,
    ID_ENG_GPRS_OFF,
    ID_ENG_HIDDEN_PARTITION_VISIBLE_ON,
    ID_ENG_HIDDEN_PARTITION_VISIBLE_OFF,
    ID_ENG_CALLFORWARD_QUERY_ON,
    ID_ENG_CALLFORWARD_QUERY_OFF,
    ID_ENG_USER_AGENT,
    ID_ENG_UA_PROFILE,
    ID_ENG_UA_DEFAULT,
    ID_ENG_DCD_SETTING,
    ID_ENG_DCD_NET_SETTING,
    ID_ENG_DCD_UPDATE_NOTE,
    ID_ENG_DCD_UPDATE_NOTE_ON,
    ID_ENG_DCD_UPDATE_NOTE_OFF,	
    ID_ENG_WAP_LOG_ON,
    ID_ENG_WAP_LOG_OFF,
    ID_ENG_WAPMMS_SAS_TEST_MODE,
    ID_ENG_CHIP_TEST,
    ID_ENG_CHIP_TEST_SETTING,
    ID_ENG_CMMB_FACTORY_TEST,
    ID_ENG_CMMB_RD_TEST,
    ID_ENG_CMMB_FACTORY_HAVE_SIGNAL,
    ID_ENG_CMMB_FACTORY_NO_SIGNAL,
    ID_ENG_CMMB_SN,
    ID_ENG_CMMB_RF_TEST,
    ID_ENG_CMMB_PLAY,
    ID_ENG_CMMB_DISPLAY,
    ID_ENG_CMMB_SET,
    ID_ENG_GPS,
    ID_ENG_IQ_DATA_ONOFF,
    ID_ENG_IQ_DATA,
    ID_ENG_IQ_DATA_ENABLE,
    ID_ENG_IQ_DATA_DISABLE,
    ID_ENG_IQ_DATA_SETTINGS,
    ID_ENG_IQ_DATA_MODES_SETTINGS,
    ID_ENG_IQ_DATA_POWER_ON_START,
    ID_ENG_IQ_DATA_MODE_SETTING_ENABLE,
    ID_ENG_IQ_DATA_MODE_SETTING,
    ID_ENG_IQ_DATA_MODE_SETTING_FORMAT,
    ID_ENG_IQ_DATA_MODE_SETTING_CHANNEL,
    ID_ENG_IQ_DATA_MODE_SETTING_TIME_LIMIT,
    ID_ENG_IQ_DATA_MODE_SETTING_FRAME_LENGTH,
    ID_ENG_IQ_DATA_MODE_SETTING_BLOCK_COUNT,
/*[START] Jerry Liang for IQ MODE 2008/07/31*/        
    ID_ENG_IQ_DATA_MODE_SETTING_ARFCN,	
/*[END] Jerry Liang for IQ MODE 2008/07/31*/            
    ID_ENG_MMS_RESPONCE,
    ID_ENG_MMS_RESPONCE_ON,
    ID_ENG_MMS_RESPONCE_OFF,
	ID_ENG_MMS_MAXSIZE,
	ID_ENG_MMS_MAXSIZE_ON,
	ID_ENG_MMS_MAXSIZE_OFF,
	ID_ENG_PCLINK,
	ID_ENG_PCLINK_ENABLE,
	ID_ENG_PCLINK_IP,
	ID_ENG_PCLINK_DNS,
	ID_ENG_PCLINK_GATEWAY,
	ID_ENG_PCLINK_SUBNET_MAS,
	ID_ENG_PCLINK_TEST,
	ID_ENG_PCLINK_TEST_ADDRESS,
	ID_ENG_PCLINK_TEST_PING,
	ID_ENG_DC_PARAM,
	ID_ENG_DC_PARAM_SCREEN_SIZE,
	ID_ENG_DC_PARAM_SCREEN_SWITCH,
	ID_ENG_DC_PARAM_PREV_SET,
	ID_ENG_DC_PARAM_SENSOR_ANGLE,
	ID_ENG_UA_AGENT_SET,
	ID_ENG_UA_PROFILE_SET,
    ID_ENG_AUTO_ANSWER_CALL_SET,
    ID_ENG_PIM_DEBUG_SET,
    ID_ENG_DM_PRAR_SET,
    ID_MBBMS_GBA_TEST,
    ID_MBBMS_SMD_COUNTER,
    ID_MBBMS_AUDIO,
    ID_MBBMS_LOG_CONTROL,
    ID_MBBMS_MSK_TEST,
    ID_MBBMS_INTERFACE_TEST,
       ID_ENG_AUDIO_SETTING,
       ID_ENG_AUDIO_HANDSET,
       ID_ENG_AUDIO_HEADSET,
       ID_ENG_AUDIO_HANDSFREE,
       ID_ENG_AUDIO_MP4HFTP,
       ID_ENG_AUDIO_MP4HFTR,
       ID_ENG_AUDIO_MP4HEADSET,
       ID_ENG_AUDIO_RECORD,
       ID_ENG_AUDIO_BT,
       ID_ENG_AUDIO_MP3_LOUDSPK,
       ID_ENG_AUDIO_MP3_EARPHONE,
       ID_ENG_AUDIO_HANDSET_SIDETONE,
       ID_ENG_AUDIO_HANDSET_RECEIVER,
       ID_ENG_AUDIO_HANDSET_MIC,
       ID_ENG_AUDIO_HEADSET_EAR,
       ID_ENG_AUDIO_HEADSET_MIC,
       ID_ENG_AUDIO_HANDSFREE_SPEAKER,
       ID_ENG_AUDIO_HANDSFREE_MIC,
       ID_ENG_AUDIO_MP4HFTP_SPEAKER,
       ID_ENG_AUDIO_MP4HFTR_MIC,
       ID_ENG_AUDIO_MP4HEADSET_EAR,
       ID_ENG_AUDIO_RECORD_MIC,
       ID_ENG_AUDIO_BT_EAR,
       ID_ENG_AUDIO_BT_MIC,
       ID_ENG_AUDIO_MP3_LOUDSPK_SPEAKER,
       ID_ENG_AUDIO_MP3_EARPHONE_EAR,
       ID_ENG_AUDIO_MP3_HEADFREE,
       //ID_ENG_AUDIO_MP3_HEADFREE_EAR,    //ÔÝÎ´Ê¹ÓÃ
       ID_ENG_AUDIO_MP3_HEADFREE_SPEAKER,

       ID_ENG_CALL_BARRING,//MS00186848
       ID_ENG_SET_ANGLE,

#ifdef  JAVA_SUPPORT_IA
	ID_ENG_JAVA_AUTO_TCK_MODE,
	ID_ENG_JAVA_AUTO_TCK_MODE_ON,
	ID_ENG_JAVA_AUTO_TCK_MODE_OFF,
#endif
	ID_ENG_TEST_FULLTEST,		//MS00193068
	ID_ENG_TEST_VIEWRESULT,	//MS00193068
	ID_ENG_TEST_ITEMTEST,
	ID_ENG_TEST_ADC_CALIBRATE_INFO,
	ID_ENG_TEST_PHONEINFO,   //MS00746952// 
	ID_ENG_TEST_FACTORYRESET,
	ID_ENG_TEST_RESET,
	ID_ENG_TEST_FACTORYITEM,
	ID_ENG_TEST_SETMODE,
	ID_ENG_TEST_SETWIFIPARAM,
	ID_ENG_TEST_SOCKETCONN,
#ifdef MEDIA_DEMO_SUPPORT
    ID_ENG_AUDIO_AAC_STRING_DEMO,
    ID_ENG_AUDIO_AMR_STRING_PLAY_DEMO,
    ID_ENG_AUDIO_MP3_STRING_DEMO,
    ID_ENG_AUDIO_WAV_STRING_DEMO,
    ID_ENG_AUDIO_AMR_STRING_RECORD_DEMO,
    ID_ENG_AUDIO_EXPRESS_DEMO,
    ID_ENG_AUDIO_CAT_MVOICE_DEMO,
    ID_ENG_AUDIO_MIC_SAMPLE_DEMO,

    ID_ENG_VIDEO_DC_DEMO,  //  DC demo
    ID_ENG_VIDEO_YUV_DEMO, // YUV demo
    ID_ENG_VIDEO_YUV422_2P,
    ID_ENG_VIDEO_YUV420_2P,
    ID_ENG_VIDEO_YUV420_3P,

    ID_ENG_MEDIA_DEMO,
    ID_ENG_MEDIA_VIDEO_DEMO,
    ID_ENG_MEDIA_AUDIO_DEMO,
#endif
     ID_ENG_MONKEY_TEST_SET, 
     ID_ENG_MEM_PRESS_TEST,
     ID_ENG_FLIGHT_MODE,
     ID_ENG_PASSWORD_SET,
	 ID_ENG_TEST_KEY, 
	 ID_ENG_TEST_MAINLCD, 
	 ID_ENG_TEST_RTC, 
	 ID_ENG_TEST_VIBRATER, 
	 ID_ENG_TEST_BACKLIGHT,	
	 ID_ENG_TEST_LOOPBACK,
#if defined TOUCH_PANEL_SUPPORT && !defined TOUCHPANEL_TYPE_MULTITP
     ID_ENG_TEST_TPTEST,
#endif
#ifdef TOUCH_PANEL_SUPPORT
     ID_ENG_TEST_PRESS_TEST,
#endif
	 ID_ENG_TEST_CAMERA, 
	 ID_ENG_TEST_VIDEO,
	 ID_ENG_TEST_BLUETOOTH,	 
	 ID_ENG_TEST_HEADSET,
	 ID_ENG_TEST_MELODY,
	 ID_ENG_TEST_SDCARD,
        ID_ENG_TEST_COM, 
        ID_ENG_TEST_FM, 
        ID_ENG_TEST_GPS, 
        ID_ENG_TEST_WIFI,         
        ID_ENG_TEST_MOTION_SENSOR,
        ID_ENG_TEST_ATV,
		ID_ENG_TEST_CHARGING,
		ID_ENG_TEST_VERSION,
       ID_ENG_TEST_SIM,
#ifdef SENSORHUB_SUPPORT
#ifndef UAL_FACTORY_TEST_SUPPORT
       ID_ENG_SENSORHUB_TEST,
#endif
#endif
#ifdef AUDIOPLAYER_DEMOAPP_SUPPORT
        ID_ENG_AUDIOPLAYER,   //audioplayer demoapp
#endif
#ifdef MMI_RF_AM_SUPPORT
    ID_ENG_RF_AM_TEST,
    ID_ENG_RF_AM_TEST_MENU_ID,
#ifdef GPS_SUPPORT
    ID_ENG_RF_AM_TEST_BACKGROUND,
    ID_ENG_RF_AM_TEST_SPORT,
#endif
    ID_ENG_RF_AM_TEST_COMMUNICATION,
#endif
    ID_ENG_AUTO_POWERONOFF,

	ID_ENG_NVCOUNT,
    ID_ENG_BROWSER_LOG,
    ID_ENG_BROWSER_Change_URL,
    ID_ENG_SCREEN_LOG,
    ID_ENG_PRINTSCREEN,
    //eng: auto test setting menu id.
    ID_ENG_AUTO_TEST_SET,
    ID_ENG_AT_ALL_SET,// @CR247145 renwei add
    ID_ENG_AT_IMAGE_ID,
    ID_ENG_AT_TEXT,
    ID_ENG_AT_WIN_MSG,
    ID_ENG_AT_TP,
    ID_ENG_AT_KEY,
    ID_ENG_AT_MSG,
    ID_ENG_AT_SOFTKEY,
    ID_ENG_AT_TITLE,
    ID_ENG_AT_POINTER_STATE,
    ID_ENG_AT_BACKLIGHT,
    ID_ENG_WIFI_IPERF,    
    ID_ENG_STANDBY_TIME,    
    ID_ENG_SHOW_STANDBY_TIME,
    ID_ENG_STANDBY_SET,
    ID_ENG_GET_FLASH_INFO,
    ID_ENG_UPDATE_IMEI,
    //eng:wlan
    ID_ENG_WLAN_SET,
    ID_ENG_WLAN_PERFORMANCE_MODE,
    ID_ENG_WLAN_IPERF,
    ID_ENG_WLAN_RADIO_FREQUENCY,
#ifdef MMI_ENG_WIFI_SUPPORT
    ID_ENG_WIFI_LOCATION,
    ID_ENG_WIFI_LOCATION_SCAN,
#endif

    ID_ENG_UA_SET_ONOFF,
    ID_ENG_UA_SET,
    ID_ENG_UA_SET_EDIT,
    ID_ENG_UA_SET_LIST,
    ID_ENG_UA_SET_SHOW,
#ifdef MMISRV_AUDIO_TEST_SUPPORT
    ID_ENG_AUDIO_SELF_TEST,
    ID_ENG_AUDIO_SELF_TEST_PLAY,
    ID_ENG_AUDIO_SELF_TEST_DISPLAY_INFO,
#endif
#ifdef MMI_DUALMODE_ENABLE
    ID_ENG_NETWORK_TYPE,
#endif
    ID_ENG_FROCE_CELL,
    ID_ENG_CANCEL_FORCE_CELL,
 #ifdef TP_TEST_SUPPORT
    ID_ENG_TP_TEST,
#endif
#ifdef MP3_SUPPORT
    ID_ENG_MP3_PLAY_TEST,
#endif
    //bug1330266
    ID_ENG_LIGHT_SLEEP_TEST,

    ID_ENG_STK_TEST,

    //bug 746951
    ID_ENG_EMCC_TEST,
    //bug 746951

    ID_ENG_SCREN_ALWAYS_ON,
    ID_ENG_BAND_SELECT,
    ID_ENG_TEL_NETWORK_MODE_ALL,
    ID_ENG_TEL_SIM_TRACE_ALL,
    //netinfo start
    ID_ENG_TEL_NETINFO,
    ID_ENG_SERVINGCELL,
    ID_ENG_ADJACENTCELL,
    ID_ENG_BETWEEN_ADJACENTCELL_2G,
    ID_ENG_OUTFIELD_NETWORK_INFORMATION,
    ID_ENG_NETINFO_STATISTICS,
    ID_ENG_NETINFO_RESELECT,
    ID_ENG_NETINFO_HANDOVER,
    ID_ENG_NETINFO_ATTACHTIME,
    ID_ENG_NETINFO_DROPTIMES,
//netinfo end
    ID_ENG_TEL_VOLTE_SETTINGS_ALL,
    ID_ENG_TEL_VOLTE_IMS_SET_ALL,
#ifdef MMI_VOLTE_SUPPORT
    ID_ENG_TEL_VOLTE_ONOFF,
    ID_ENG_TEL_IMS_PDN,
#endif
    ID_ENG_TEL_PLMN_WHITE_LIST_ALL,
    ID_ENG_TEL_CSFBGSM_DELAY,
    ID_ENG_RESTORE_FACTORY_RESET,
    ID_ENG_EDIT_SMS_CENTER_NUMBER,
    ID_ENG_FAST_DORMANCY,
    ID_ENG_QOS_SWTICH,
#ifdef MMI_ENG_WIFI_SUPPORT
//wifi begin
    ID_ENG_CON_WIFI_INFO,
    ID_ENG_CON_WIFI_TX,
    ID_ENG_CON_WIFI_RX,
    ID_ENG_CON_WIFI_REGWR,
    ID_ENG_CON_WIFI_SAVEMODE,
    ID_ENG_CON_WIFI_PACKETMODE,
    ID_ENG_CON_WIFI_PACKETSWITCHMODE,
    ID_ENG_CON_WIFI_PACKETITEMMODE,
    ID_ENG_CON_WIFI_FLIGHTMODE,
//wifi end
#endif
    ID_ENG_ADD_CONTACT,
#if (defined GPS_SUPPORT) && (defined MMI_ENG_WIFI_SUPPORT)
    ID_ENG_GPS_OTA,
#endif
#if defined(GPS_SUPPORT)
    ID_ENG_GPS_TEST,
    ID_ENG_GPS_TEST_MENU_ID,
    ID_ENG_GPS_TEST_GNSSMODE,
    ID_ENG_GPS_TEST_GNSSMODE_LIST_BOX_CTRL_ID,
    ID_ENG_GPS_TEST_SATELLITECN,
    ID_ENG_GPS_TEST_SATELLITECN_LIST_CTRL_ID,
    ID_ENG_GPS_TEST_GPSINFO,
    ID_ENG_GPS_TEST_GPSNMEALOG,
    //gps circle test ctrl
    ID_ENG_GPS_TEST_CIRCLETEST,
    ID_ENG_GPS_TEST_CIRCLETEST_LIST_BOX_ID,
    ID_ENG_GPS_TEST_CIRCLETEST_FORM_CTRL_ID,
    ID_ENG_GPS_TEST_CIRCLETEST_TIME_LABEL_CTRL_ID,
    ID_ENG_GPS_TEST_CIRCLETEST_TIME_EDIT_CTRL_ID,
    ID_ENG_GPS_TEST_CIRCLETEST_INTERVAL_LABEL_CTRL_ID,
    ID_ENG_GPS_TEST_CIRCLETEST_INTERVAL_EDIT_CTRL_ID,
    ID_ENG_GPS_TEST_CIRCLETEST_TRANSFERINTERVAL_LABEL_CTRL_ID,
    ID_ENG_GPS_TEST_CIRCLETEST_TRANSFERINTERVAL_EDIT_CTRL_ID,
    ID_ENG_GPS_TEST_CIRCLETEST_TTFFTIMEOUT_LABEL_CTRL_ID,
    ID_ENG_GPS_TEST_CIRCLETEST_TTFFTIMEOUT_EDIT_CTRL_ID,
    ID_ENG_GPS_TEST_STARTMODE_LIST_BOX_CTRL_ID,
    //gps latlong set win ctrl
    ID_ENG_GPS_TEST_LATLONGSET,
    ID_ENG_GPS_TEST_LATLONGSET_FORM_CTRL_ID,
    ID_ENG_GPS_TEST_LATLONGSET_LATITUDE_FORM_CTRL_ID,
    ID_ENG_GPS_TEST_LATLONGSET_LATITUDE_LABEL_CTRL_ID,
    ID_ENG_GPS_TEST_LATLONGSET_LATITUDE_EDITBOX_CTRL_ID,
    ID_ENG_GPS_TEST_LATLONGSET_LONGTITUDE_FORM_CTRL_ID,
    ID_ENG_GPS_TEST_LATLONGSET_LONGTITUDE_LABEL_CTRL_ID,
    ID_ENG_GPS_TEST_LATLONGSET_LONGTITUDE_EDITBOX_CTRL_ID,
    //gps nmea log win ctrl
    ID_ENG_GPS_TEST_NMEA_LOG_SAVE_PATH_CTRL_ID,
    ID_ENG_GPS_TEST_NMEA_LOG_LABEL_CTRL_ID,
    ID_ENG_GPS_TEST_NMEA_LOG_TEXTBOX_CTRL_ID,
#endif
/*log switch begin*/
    ID_ENG_LOG_SET,
    ID_ENG_LOG_SWITCH,
    ID_ENG_LOG_TOPC,
    ID_ENG_LOG_CLEAR_ALL,
    ID_ENG_LOG_UART_LOG,
    ID_ENG_LOG_SWITCH_AP,
    ID_ENG_LOG_SWITCH_MODEM,
    ID_ENG_LOG_SWITCH_WCN,
    ID_ENG_LOG_SWITCH_GNSS,
    ID_ENG_LOG_TOPC_AP,
    ID_ENG_LOG_TOPC_MODEM,
    ID_ENG_LOG_TOPC_WCN,
/*log switch end*/

    ID_ENG_GPRS_TEST,
    ID_ENG_MEM_TESTER,
    ID_ENG_REGISTER_PS_SERVICE,
    ID_ENG_TRACKING_TEST_OPT_START_MODE_SET,
    ID_ENG_MEMCHECK_TEST,
#ifdef SENSORHUB_SUPPORT
    ID_ENG_SENSOR_INFO_TEST,
    ID_ENG_SENSOR_FIRMWARE_DL,
    ID_ENG_SENSOR_PRODUCTTEST_DL,
    ID_ENG_SENSOR_VERSION,
    ID_ENG_SENSOR_HEARTRATE_ID,
    ID_ENG_SENSOR_ACC_ID,
    ID_ENG_SENSOR_ACC_CALIBRATION,
    ID_ENG_SENSOR_BLE_BROADCAST,
#endif
#ifdef ADULT_WATCH_SUPPORT
    ID_ENG_OLD_MAINMENU_ENTER,
    ID_ENG_CALL_FORWARD_VIEW_TEST,//307 call forward
    ID_ENG_BBM_VIEW_TEST,//307 BT BLE Manage
#endif
    ID_ENG_PHONE_START_USB_PORT,
#ifdef ESIM_SUPPORT_HB
    ID_ESIM_INFORMATION_ENTER,
#endif
    ID_ENG_TEL_GPRS_POWER_SAVE_MODE,
    ID_ENG_NTC_TEST,
#ifdef DATA_ROAMING_SUPPORT    
    ID_ENG_GPRS_ROAMING_MODE_SET,    
#endif    
    ID_ENG_CSCON_STATUS_INFO, // 2022-04-08��307 ���� CSCON״̬��ʾ
    ID_ENG_IMS_NV_PARAM_ID,
    ID_ENG_SET_LTE_OPERATION_MODE,
    ID_ENG_FORBID_ALL_DATA,
    ID_ENG_FLOWRETE_INFO,
#if defined ENG_BAND_FREQ_SUPPORT
     ID_ENG_BAND_FREQ_SET,
     ID_ENG_SET_BAND,
     ID_ENG_SET_FREQ,
     ID_ENG_SET_LTE_FREQ,
     ID_ENG_SET_GSM_FREQ,
     ID_ENG_SET_LTE_BAND,
     ID_ENG_SET_GSM_BAND,
#endif
    MMIENG_MENU_ID_MAX
}MMIENG_MENU_ID_E;

#define MENU_DEF(_TABLEID, _ITEMPTR, _STYLE, _TITLESTR, _TITLE_ICON, _TITLE_NUMICON, _TITLE_BACKGROUND, \
	_ITEMCOUNT) \
     _TABLEID,

typedef enum
{
    MMIENG_MENU_TABEL_MIN = (MMI_MODULE_ENG << 16),
    #include "mmieng_menutable.def"
    MMIENG_MENU_TABLE_MAX
} MMIENG_MENU_TABEL_E;

#undef MENU_DEF

/*****************************************************************************/
// 	Description : Register eng menu group
//	Global resource dependence : none
//  Author: songbin.zeng
//	Note:
/*****************************************************************************/
PUBLIC void MMIENG_RegMenuGroup(void);

/**---------------------------------------------------------------------------*
 **                         Compiler Flag                                     *
 **---------------------------------------------------------------------------*/
#ifdef   __cplusplus
    }
#endif
/*-------------------------------------------------------------------------*/

#endif /* _MMIENG_MENUTABLE_H_ */

