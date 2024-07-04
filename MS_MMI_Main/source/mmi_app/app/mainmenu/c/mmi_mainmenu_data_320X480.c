/*****************************************************************************
** File Name:      mmi_mainmenu_data.c                                       *
** Author:                                                                   *
** Date:           07/18/2012                                                *
** Copyright:      2004 Spreatrum, Incoporated. All Rights Reserved.         *
** Description:    This file is used to describe punctuation                 *
******************************************************************************
**                         Important Edit History                            *
** --------------------------------------------------------------------------*
** DATE           NAME             DESCRIPTION                               *
** 07/2012      hua.fang              Creat
******************************************************************************/

/**--------------------------------------------------------------------------*
 **                         Include Files                                    *
 **--------------------------------------------------------------------------*/

#include "mmi_text.h"
#include "mmi_image.h"
#include "mmiset_text.h"
#include "guimenu.h"
#include "mmi_menutable.h"
#include "mmimms_text.h"
#ifdef GAME_SUPPORT
#include "mmigame_menutable.h"
#include "mmigame_link_text.h"
#ifdef GAME_BOXMAN_SUPPORT
#include "mmigame_boxman_text.h"
#endif
#ifdef GAME_SNAKE_SUPPORT
#include "mmigame_snake_text.h"
#endif
#ifdef GAME_TETRIS_SUPPORT
#include "mmigame_square_text.h"
#endif
#endif
#include "mmimp3_text.h"
#include "mmicc_text.h"
//#include "mmipicview_text.h"
#include "mmiconnection_text.h"
#include "mmisms_text.h"

#ifdef CMMB_SUPPORT
#include "mmimtv_text.h"
#endif

#ifdef JAVA_SUPPORT
#include "java_mmi_text.h"
#endif

#ifdef KURO_SUPPORT
#include "mmikuro_text.h"
#endif

#ifdef DYNAMIC_MODULE_SUPPORT
#include "mmidyna_text.h"
#endif

#ifdef SXH_APPLE_SUPPORT
#include "apple_export.h"
#endif
#ifdef PIM_SUPPORT
#include "mmipim_export.h"
#include "Mmipim_text.h"
#endif

#ifdef GPS_SUPPORT
#include "mmigps_text.h"
#endif

#if defined (GPS_SUPPORT) || defined (MMI_WIFI_SUPPORT)
#include "mmiconnection_menutable.h"
#endif

#ifdef DL_SUPPORT
#include "mmidl_text.h"
#include "mmidl_image.h"
#endif

#ifdef STREAMING_HS_SUPPORT // chenxiang 20100203 
#include "mmismp_text.h"
#endif

#ifdef ASP_SUPPORT
#include "mmiasp_text.h"
#endif

#ifdef PUSH_EMAIL_SUPPORT
#include "mmimail_text.h"
#include "mmimail_image.h"
#endif /* PUSH_EMAIL_SUPPORT  */

#ifdef ATV_SUPPORT
#include "mmiatv_text.h"
#endif

#ifdef WRE_SUPPORT
#include "mmiwre_text.h"
#endif

#ifdef GAME_TETRIS_SUPPORT
#include "mmigame_square_internal.h"
#endif

#ifdef MMI_KING_MOVIE_SUPPORT
#include "mmikm_text.h"
#endif
//============== MET MEX start ===================
#ifdef MET_MEX_SUPPORT
#include "met_mex_text.h"
#include "met_mex_image.h"
#endif // MET_MEX_SUPPORT
//============== MET MEX start ===================

#ifdef QBTHEME_SUPPORT
#include "mmiqbtheme_text.h"
#include "mmiqbtheme_export.h"
#endif

/**--------------------------------------------------------------------------*
 **                         STATIC DEFINITION                                *
 **--------------------------------------------------------------------------*/

// static menu item data
static const MMI_MAINMENU_ITEM_T s_mainmenu_item_data[] =
{
    // page 1 in slide page
#ifdef  TOUCH_PANEL_SUPPORT
    // ������   ͨѶ¼  ͨ����¼    ��������
    {ID_COMMUNICATION_DIAL, TXT_COMM_DIALPAD, IMAGE_MAINMENU_ICON_DIAL, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartDial, 0},
#endif

#ifdef WRE_SUPPORT  // wre appstore
    {ID_TOOLS_WRE, TXT_WRE_ENTERTAINMENT, IMAGE_MAINMENU_ICON_STORE, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartWRE, 0},
#endif

    {ID_COMMUNICATION_PB, STXT_MAIN_PB, IMAGE_MAINMENU_ICON_PB, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartPB, 0},
    {ID_COMMUNICATION_CL, STXT_MAIN_CL, IMAGE_MAINMENU_ICON_CL, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartCL, 0},
    {ID_SETTINGS_PHONE, STXT_MAIN_SETTING, IMAGE_MAINMENU_ICON_SET, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartPhoneSetting, 0},
#ifdef BT_DIALER_SUPPORT
    {ID_TOOLS_BTPHONE, TXT_TOOLS_BTPHONE, IMAGE_MAINMENU_ICON_BTPHONE, IMAGE_MAINMENU_ICON_SELECT, MMIAPIBT_OpenBtPhoneWin, 0},
#endif
#ifdef GO_MENU_ONE_ICON_CHANGE_STYLE
    {ID_MAINMENU_STYLE_SET, TXT_SET_MAINMENU_STYLE, IMAGE_MAINMENU_ICON_MAINMENU_SET, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMainmenuStyle, 0},
#endif
#ifdef GO_MENU_ONE_ICON_CHANGE_STYLE
    {ID_GOMENU_CHANGE_STYLE, TXT_SET_MAINMENU_GO, IMAGE_MAINMENU_ICON_GO, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_GoMenuChangeStyle, 0},
#endif

#ifndef MMI_RES_LOW_COST
#if defined MMI_KEY_LOCK_EFFECT_SUPPORT && !defined MMI_RES_SLIM_SUPPORT
    {ID_MAINMENU_LOCK_SET, TXT_SET_KEY_LOCK_EFFECT_TITLE, IMAGE_MAINMENU_ICON_LOCK, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartLockStyle, 0},
#endif
#endif

    // �����   ��Ϣ���� ��� �龰ģʽ
#ifdef BROWSER_SUPPORT
    {ID_COMMUNICATION_BROWSER, TXT_COMMUNICATION_BROWSER, IMAGE_MAINMENU_ICON_BROWSER, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartCommunicationBrowser, 0},
#endif

    {ID_COMMUNICATION_MESSAGE, TXT_COMMUNICATION_MESSAGE, IMAGE_MAINMENU_ICON_MESSAGE, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMessage, 0},

#ifdef MMIEMAIL_SUPPORT
    {ID_COMMUNICATION_EMAIL, TXT_EMAIL, IMAGE_MAINMENU_ICON_EMAIL, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartIEmail, 0},
#endif

#ifdef  CAMERA_SUPPORT
    {ID_ENTERTAIMENT_CAMERA, TXT_ENTERTAIMENT_CAMERA, IMAGE_MAINMENU_ICON_CAMERA, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartDCPhoto, 0},
    {ID_ENTERTAIMENT_DV, TXT_ENTERTAIMENT_DV, IMAGE_MAINMENU_ICON_DV, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartDCVideo, 0},
#endif

#ifdef MMIUZONE_SUPPORT
    {ID_ENTERTAIMENT_UZONE, TXT_UZONE, IMAGE_MAINMENU_ICON_UZONE, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartUzone, 0},
#endif

    {ID_SETTINGS_ENVIONMENT, TXT_SETTINGS_ENVIONMENT, IMAGE_MAINMENU_ICON_ENV, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartEnvSetting, 0},

    // ���� �ճ� ��Ƶ ��Ƶ
    {ID_TOOLS_CALENDAR, TXT_TOOLS_CALENDAR, IMAGE_MAINMENU_ICON_CALENDAR, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartCalendar, 0},
#ifdef MMI_AUDIO_PLAYER_SUPPORT
    {ID_ENTERTAIMENT_MP3, TXT_AUDIO, IMAGE_MAINMENU_ICON_AUDIO_PLAYER, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMp3, 0},
#endif
#ifdef VIDEO_PLAYER_SUPPORT
#ifndef MMI_VIDEOPLAYER_MINI_FUNCTION
    {ID_ENTERTAIMENT_VIDEO, TXT_VIDEO, IMAGE_MAINMENU_ICON_VIDEO_PLAYER, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartIVP, 0},
#endif
#endif
#ifdef MMI_KING_MOVIE_SUPPORT
    {ID_MENU_KING_MOVIE, TXT_KM, IMAGE_MAINMENU_ICON_KING_MOVIE, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartKM, 0},
#endif
    //-----------------start SXH_APPLE_SUPPORT-------------------------------
#ifdef SXH_APPLE_UMVCHAT
    {ID_SXH_UMVCHAT, TXT_SXH_UMVCHAT, IMAGE_MAINMENU_ICON_UMCHAT, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartSXHUmvchat, 0},
#endif
#ifdef SXH_APPLE_VP
    {ID_SXH_TV, TXT_SXH_TV1, IMAGE_MAINMENU_ICON_APPLETV, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartSXHTV, 0},
#endif
#ifdef SXH_APPLE_UMPLAY
    {ID_SXH_UMPLAYER, TXT_SXH_UMPLAYER, IMAGE_MAINMENU_ICON_UMPLAYER, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartSXHUmplayer, 0},
#endif

    //-----------------end SXH_APPLE_SUPPORT-------------------------------

    //-----------------start SXH_APPLE_SUPPORT-------------------------------
#ifdef SXH_APPLE_APP
    {ID_SXH_APPLE, TXT_SXH_APPLE, IMAGE_MAINMENU_ICON_APPLE, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartSXHApple, 0},
#endif

#ifdef SXH_APPLE_BOOK
    {ID_SXH_BOOK, TXT_SXH_BOOK, IMAGE_MAINMENU_ICON_BOOK, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartSXHBook, 0},
#endif

#ifdef SXH_APPLE_ONLINEGAME
#if defined MAINLCD_SIZE_240X400 || defined MAINLCD_SIZE_240X320
    {ID_SXH_Games, TXT_SXH_Games, IMAGE_MAINMENU_ICON_ONGAME, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartSXHGames, 0},
#endif
#endif
    //-----------------end SXH_APPLE_SUPPORT-------------------------------
    // ������  �ļ����� ����  WIFI=WLAN
#ifdef EBOOK_SUPPORT
    {ID_EBOOK, TXT_COMM_EBOOK, IMAGE_MAINMENU_ICON_EBOOK, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartEBOOK, 0},
#endif

    {ID_ENTERTAIMENT_FAVORITE, TXT_EXPLORER, IMAGE_MAINMENU_ICON_FAVORITE, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartFavorite, 0},

#ifdef BLUETOOTH_SUPPORT
    {ID_MAINMENU_BT, TXT_BLUETOOTH, IMAGE_MAINMENU_ICON_BT, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartBT, 0},
#endif

#ifdef MMI_WIFI_SUPPORT
    {ID_CONNECTION_WIFI, TXT_WIFI, IMAGE_MAINMENU_ICON_WIFI, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartWIFI, 0},
#endif

    // page 2 in slide page
    // JAVA  ͼƬ���    FM������  ������
#ifdef JAVA_SUPPORT
    {ID_ENTERTAIMENT_GOLDHOUSE, TXT_JAVA, IMAGE_MAINMENU_ICON_GOLDHOUSE, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartJava, 0},
#endif
#ifdef PIC_VIEWER_SUPPORT
    {ID_PIC_VIEWER, TXT_COMMON_PIC, IMAGE_MAINMENU_ICON_PIC, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartPicViewer, 0},
#endif
#ifdef FM_SUPPORT
    {ID_ENTERTAIMENT_FM, TXT_FM, IMAGE_MAINMENU_ICON_FM, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartFM, 0},
#endif
#ifdef CALCULATOR_SUPPORT
    {ID_TOOLS_CALCULATOR, TXT_TOOLS_CALCULATOR, IMAGE_MAINMENU_ICON_CALCULATOR, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartPicalc, 0},
#endif

#ifdef MMI_RECORD_SUPPORT
    // ¼�� ��Ѷ TV ���(δ��)
    {ID_TOOLS_RECORD, TXT_RECORDER, IMAGE_MAINMENU_ICON_RECORD, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartRecord, 0},
 #endif
#ifdef DCD_SUPPORT
    {ID_TOOLS_DCD, TXT_DCD_QUICK_INFO, IMAGE_MAINMENU_ICON_DCD, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartDCD, 0},
#endif
#ifdef ATV_SUPPORT
    {ID_ENTERTAIMENT_ATV, TXT_ATV_ANALOGTV, IMAGE_MAINMENU_ICON_ATV, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartATV, 0},
#elif defined CMMB_SUPPORT
    {ID_ENTERTAIMENT_MTV, TXT_MTV_MOBILETV, IMAGE_MAINMENU_ICON_TV, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMTV, 0},
#endif

#ifdef WRE_SUPPORT  // wre appstore
#ifdef WRE_CONTRA_SUPPORT  // �궷��
    {ID_WRE_CONTRA, TXT_WRE_CONTRA, IMAGE_MAINMENU_ICON_CONTRA, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartWreApp, WRE_FIX_ID_CONTRA},
#endif

#ifdef WRE_SUPERMARIO_SUPPORT  // ��������
    {ID_WRE_SUPERMARIO, TXT_WRE_SUPERMARIO, IMAGE_MAINMENU_ICON_SUPERMARIO, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartWreApp, WRE_FIX_ID_SUPERMARIO},
#endif

#ifdef WRE_TSLAND_SUPPORT  // ð�յ�
    {ID_WRE_TSLAND, TXT_WRE_TSLAND, IMAGE_MAINMENU_ICON_TSLAND, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartWreApp, WRE_FIX_ID_TSLAND},
#endif

#ifdef WRE_FRUIT_SUPPORT  // qie shuiguo
    {ID_MAINMENU_FRUIT, TXT_MAINMENU_FRUIT, IMAGE_MAINMENU_ICON_FRUIT, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartWreFixApp, WRE_FIX_ID_FRUIT},
#endif
#endif

    // ��Ϸ ����ʱ��  ����ʱ �������
#ifdef GAME_SUPPORT
    {ID_ENTERTAIMENT_GAME, TXT_ENTERTAIMENT_GAME, IMAGE_MAINMENU_ICON_GAME, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartGame, 0},
#endif

#if 0//def WORLD_CLOCK_SUPPORT
    {ID_WORLDTIME, TXT_TOOLS_WORLDTIME, IMAGE_MAINMENU_ICON_WORLDTIME, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartWordTime, 0},
#endif//WORLD_CLOCK_SUPPORT

#if (!defined MMI_ALARM_MINI_SUPPORT) && (!defined MMI_WORLDCLOCK_MINI_SUPPORT) && (!defined MMI_COUNTEDTIME_MINI_SUPPORT)
    {ID_CLOCK, TXT_TOOLS_CLOCK, IMAGE_MAINMENU_ICON_COUNTEDTIME, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartTimer, ID_CLOCK},
#endif

#if defined(HOME_LOCATION_INQUIRE_SUPPORT) && (defined IM_SIMP_CHINESE_SUPPORT|| defined IM_TRAD_CHINESE_SUPPORT)
    {
        ID_PHONESEARCH, TXT_GUISHUDI, IMAGE_MAINMENU_ICON_LOCATION, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartPhoneSearch, 0
    },
#endif

    // ��¼�� �������� ��λ���� ��������(δ��)
#ifdef ASP_SUPPORT
    {ID_TOOLS_ASP, TXT_MMIASP_ANSWER_PHONE, IMAGE_MAINMENU_ICON_CALL_RECORD, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartASP, 0},
#endif
#ifdef SEARCH_SUPPORT
    {ID_MAINMENU_SEARCH, TXT_SEARCH, IMAGE_MAINMENU_ICON_SEARCH, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartSearch, 0},
#endif /* SEARCH_SUPPORT */

#ifdef MMI_UNITCONVERSION_SUPPORT
    {ID_TOOLS_UNIT_CONVERSION, TXT_UC_UNIT_CONVERSION, IMAGE_MAINMENU_ICON_UNITCONVERSION, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartUnitConv, 0},
#endif//MMI_UNITCONVERSION_SUPPORT
#ifdef IKEYBACKUP_SUPPORT
    {ID_MAINMENU_IKEYBACKUP, TXT_IKB_ONEKEY_BACKUP, IMAGE_MAINMENU_ICON_IKEYBACKUP, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartKB, 0},
#endif

#ifdef MMI_AZAN_SUPPORT
    {ID_AZAN, STR_AZAN_ALARM, IMAGE_MAINMENU_ICON_AZAN, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMuSiLinPray, 0},
#endif

    // �������� ��ʾ����    ��ȫ����    GPS
#ifdef GPS_SUPPORT
    {ID_CONNECTION_GPS, TXT_GPS, IMAGE_MAINMENU_ICON_GPS, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartGPS, 0},
#endif

#if 0 // Ų�����ò˵���
#if defined (MMI_TVOUT_ENABLE) || defined (MMI_GPRS_SUPPORT)
    {
        ID_SETTINGS_LINK, TXT_SETTINGS_LINK, IMAGE_MAINMENU_ICON_LINK, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartConnection, 0
    },
#endif
    {ID_SETTINGS_DISPLAY, TXT_SETTINGS_DISPLAY, IMAGE_MAINMENU_ICON_DISPLAY, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartDisplaySetting, 0},
    {ID_SETTINGS_SECURITY, TXT_COMM_SECURITY_SETTING, IMAGE_MAINMENU_ICON_SECURITY, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartSecuritySetting, 0},
    {ID_SETTINGS_CALL, TXT_SETTINGS_CALL, IMAGE_MAINMENU_ICON_CALL, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartCallSettings, 0},
#endif // 0


#ifdef MV_SUPPORT
    {ID_MAINMENU_MAGIC_VOICE, TXT_CC_MAGICVOICE, IMAGE_MAINMENU_ICON_MAGIC_VOICE, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMagicVoice, 0},
#endif

#ifdef PUSH_EMAIL_SUPPORT
    {ID_MAINMENU_PUSHMAIL, TXT_MAIL_PUSHMAIL, IMAGE_MAINMENU_ICON_PUSHMAIL, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartPushMail, 0},
#endif /* PUSH_EMAIL_SUPPORT  */

    // STK
    {ID_COMMUNICATION_STK, TXT_COMMON_MAIN_STK, IMAGE_MAINMENU_ICON_STK, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartSTK, 0},
#ifdef PIM_SUPPORT //Added by wangxiaolin  2009.9.7
    {ID_MAINMENU_PIM, TXT_PIM, IMAGE_MAINMENU_ICON_PBM, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartPIM, 0},
#endif /* PIM_SUPPORT */

#ifdef MMI_TASK_MANAGER
    {ID_APP_MANAGER, TXT_APPLICATION_MANAGER, IMAGE_MAINMENU_ICON_APP, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartAppletManager, 0},
#endif/*MMI_TASK_MANAGER*/
#ifdef MMI_MEMO_SUPPORT
    {ID_APP_MEMO, TXT_MEMO, IMAGE_MAINMENU_ICON_NOTE, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMemo, 0},
#endif

    // page 4 in slide page
#ifdef MMI_GPRS_SUPPORT
#ifdef WEATHER_SUPPORT
    {ID_MAINMENU_WEATHER, TXT_MAINMENU_ICON_WEATHER, IMAGE_MAINMENU_ICON_WEATHER, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartWeather, 0},
#endif
#ifdef MCARE_V31_SUPPORT
#ifdef MCARE_MENU_ICON_NONE
    {ID_BRW_APP_SUPPORT, TXT_BRW_APP, 0, 0, MMIMAINMENU_StartMCareV31QQBrowser, 0},
    {ID_TMC_APP_SUPPORT, TXT_TMC_APP, 0, 0, MMIMAINMENU_StartMCareV31, 0},
#else
    {ID_BRW_APP_SUPPORT, TXT_BRW_APP, IMAGE_MAINMENU_ICON_BRW, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMCareV31QQBrowser, 0},
    {ID_TMC_APP_SUPPORT, TXT_TMC_APP, IMAGE_MAINMENU_ICON_TMC, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMCareV31, 0},
#endif
#endif
#ifdef QQ_SUPPORT
    {ID_MAINMENU_QQ, TXT_SPREADTRUM_QQ_SUPPORT, IMAGE_MAINMENU_ICON_QQ, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartQQ, 0},
#endif

#if 0
    {ID_MAINMENU_SINA, TXT_MAINMENU_ICON_SINA, IMAGE_MAINMENU_ICON_SINA, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartBrowerURL, BROWSER_URL_TYPE_SINA},
    {ID_MAINMENU_CTRIP, TXT_MAINMENU_ICON_CTRIP, IMAGE_MAINMENU_ICON_CTRIP, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartBrowerURL, BROWSER_URL_TYPE_CTRIP},
    {ID_MAINMENU_YOUKU, TXT_MAINMENU_ICON_YOUKU, IMAGE_MAINMENU_ICON_YOUKU, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartBrowerURL, BROWSER_URL_TYPE_YOUKU},
#endif
#ifndef MMI_RES_SLIM_SUPPORT
    {ID_MAINMENU_SOSO, TXT_WWW_SOSO, IMAGE_MAINMENU_ICON_SOSO, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartBrowerURL, BROWSER_URL_TYPE_SOSO},
    {ID_MAINMENU_BAIDU, TXT_MAINMENU_ICON_BAIDU, IMAGE_MAINMENU_ICON_BAIDU, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartBrowerURL, BROWSER_URL_TYPE_BAIDU},
    {ID_MAINMENU_DIANPING, TXT_MAINMENU_ICON_DIANPING, IMAGE_MAINMENU_ICON_DIANPING, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartBrowerURL, BROWSER_URL_TYPE_DIANPING},
    {ID_MAINMENU_KAIXIN, TXT_MAINMENU_ICON_KAIXIN, IMAGE_MAINMENU_ICON_KAIXIN, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartBrowerURL, BROWSER_URL_TYPE_KAIXIN},
    {ID_MAINMENU_TAOBAO, TXT_MAINMENU_ICON_TAOBAO, IMAGE_MAINMENU_ICON_TAOBAO, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartBrowerURL, BROWSER_URL_TYPE_TAOBAO},
    {ID_MAINMENU_RENREN, TXT_MAINMENU_ICON_RENREN, IMAGE_MAINMENU_ICON_RENREN, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartBrowerURL, BROWSER_URL_TYPE_RENREN},
    {ID_MAINMENU_QIDIAN, TXT_MAINMENU_ICON_QIDIAN, IMAGE_MAINMENU_ICON_QIDIAN, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartBrowerURL, BROWSER_URL_TYPE_QIDIAN},
    {ID_MAINMENU_PALMREAD, TXT_MAINMENU_ICON_PALMREAD, IMAGE_MAINMENU_ICON_PALMREAD, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartBrowerURL, BROWSER_URL_TYPE_PALMREAD},
    {ID_MAINMENU_AMUSEBOX, TXT_MAINMENU_ICON_AMUSEBOX, IMAGE_MAINMENU_ICON_AMUSEBOX, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartBrowerURL, BROWSER_URL_TYPE_AMUSEBOX},
    {ID_MAINMENU_MOBILESOHU, TXT_MAINMENU_ICON_MOBILESOHU, IMAGE_MAINMENU_ICON_MOBILESOHU, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartBrowerURL, BROWSER_URL_TYPE_MOBILESOHU},
    {ID_MAINMENU_COOLSTATION, TXT_MAINMENU_ICON_COOLSTATION, IMAGE_MAINMENU_ICON_COOLSTATION, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartBrowerURL, BROWSER_URL_TYPE_COOLSTATION},
    {ID_MAINMENU_COLORWORLD, TXT_MAINMENU_ICON_COLORWORLD, IMAGE_MAINMENU_ICON_COLORWORLD, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartBrowerURL, BROWSER_URL_TYPE_COLORWORLD},
    {ID_MAINMENU_ZHIFUBAO, TXT_MAINMENU_ICON_ZHIFUBAO, IMAGE_MAINMENU_ICON_ZHIFUBAO, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartBrowerURL, BROWSER_URL_TYPE_ZHIFUBAO},
    {ID_MAINMENU_TUDOU, TXT_MAINMENU_ICON_TUDOU, IMAGE_MAINMENU_ICON_TUDOU, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartBrowerURL, BROWSER_URL_TYPE_TUDOU},
#endif

#ifdef BROWSER_SUPPORT
#if ((defined(BROWSER_SUPPORT_DORADO) && defined(BROWSER_SUPPORT_NETFRONT)) || (defined(BROWSER_SUPPORT_DORADO) && defined(OPERA_MINI_SUPPORT)) || (defined(BROWSER_SUPPORT_NETFRONT) && defined(OPERA_MINI_SUPPORT)))
#ifdef OPERA_MINI_SUPPORT
    {ID_MAINMENU_OPERAMINI, TXT_COMMON_BROWSER_OPERAMINI, IMAGE_MAINMENU_ICON_OPERAMINI, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartOperaMinBrowser, 0},
#endif
#ifdef BROWSER_SUPPORT_NETFRONT
    {ID_MAINMENU_NF, TXT_COMMON_BROWSER_NF, IMAGE_MAINMENU_ICON_NF, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartNetFrontBrowser, 0},
#endif
#ifdef BROWSER_SUPPORT_DORADO
    {ID_MAINMENU_DORADO, TXT_COMMON_BROWSER_DORADO, IMAGE_MAINMENU_ICON_DORADO, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartDoradoBrowser, 0},
#endif
#endif//the browser type number >= 2
#endif

#if defined(MOBILE_VIDEO_SUPPORT)
    {
        ID_ENTERTAIMENT_MOBILE_VIDEO, TXT_ENTERTAIMENT_MV, IMAGE_MAINMENU_ICON_MOBILE_VIDEO, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMV, 0
    },
#endif

#endif

#ifdef MMI_PDA_SUPPORT
#if defined(MMI_ANDROID_SUPPORT) && (defined MMI_ISTYLE_SUPPORT || defined MMI_GRID_IDLE_SUPPORT || defined MMI_SMART_IDLE_SUPPORT)
    {
        ID_MAINMENU_IDLE_STYLE, TXT_IDLE_SWITH, IMAGE_MAINMENU_ICON_IDLE_STYLE, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartIdleStyle, 0
    },
#endif
#endif

#ifdef MMIDC_F_U_CAMERA
    {ID_ENTERTAIMENT_UCAMERA, TXT_ENTERTAIMENT_UCAMERA, IMAGE_MAINMENU_ICON_UCAMERA, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartDCUCameraPhoto, 0},
#endif


#ifdef WRE_SUPPORT
    //FaceBook    Twitter     SinaBlog
#ifdef WRE_FACEBOOK_SUPPORT
    {ID_MAINMENU_FACEBOOK, TXT_MAINMENU_FACEBOOK, IMAGE_MAINMENU_ICON_FACEBOOK, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartWreApp, WRE_FIX_ID_FACEBOOK},
#endif

#ifdef WRE_TWITTER_SUPPORT
    {ID_MAINMENU_TWITTER, TXT_MAINMENU_TWITTER, IMAGE_MAINMENU_ICON_TWITTER, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartWreApp, WRE_FIX_ID_TWITTER},
#endif

#ifdef WRE_WEIBO_SUPPORT
    {ID_MAINMENU_SINA_BOLG, TXT_MAINMENU_ICON_SINABLOG, IMAGE_MAINMENU_ICON_SINA_BLOG, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartWreApp, WRE_FIX_ID_SINA},
#endif
#endif


#ifdef MRAPP_SUPPORT
#ifdef MRAPP_NETGAME_OPEN
    {ID_MRAPP_NETGAME, TXT_MRAPP_NETGAME, IMG_MRAPP_MAINMENU_NETGAME, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMRAPP, MRAPP_NETGAME},
#endif

#ifdef MRAPP_COOKIE_OPEN
    {ID_MRAPP_COOKIE, TXT_MRAPP_GAMEC, IMG_MRAPP_MAINMENU_MAOPAO, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMRAPP, MRAPP_COOKIE},
#endif

#ifdef MRAPP_MRPSTORE_OPEN
    {ID_MRAPP_MRPSTORE, TXT_MRAPP_MRPSTORE, IMG_MRAPP_MRPSTORE, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMRAPP, MRAPP_MRPSTORE},
#endif

#ifdef MRAPP_SKYBUDDY_OPEN
    {ID_MRAPP_SKYBUDDY, TXT_MRAPP_SKYBUDDY, IMG_MRAPP_SKYBUDDY, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMRAPP, MRAPP_SKYBUDDY},
#endif

#ifdef MRAPP_EBOOK_OPEN
    {ID_MRAPP_BOOKS, TXT_MRAPP_BOOKS, IMG_MRAPP_MAINMENU_SKYREAD, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMRAPP, MRAPP_EBOOK},
#endif

#ifdef MRAPP_FETION_OPEN
    {ID_MRAPP_FETION, TXT_MRAPP_FETION, IMG_MRAPP_MAINMENU_FETION, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMRAPP, MRAPP_FETION},
#endif

#ifdef MRAPP_XLWB_OPEN
    {ID_MRAPP_XLWB, TXT_MRAPP_XLWB, IMG_MRAPP_MAINMENU_SINA, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMRAPP, MRAPP_XLWB},
#endif

#ifdef MRAPP_KAIXIN_OPEN
    {ID_MRAPP_KAIXIN, TXT_MRAPP_KAIXIN, IMG_MRAPP_MAINMENU_KAIXIN, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMRAPP, MRAPP_KAIXIN},
#endif

#ifdef MRAPP_FARM_OPEN
    {ID_MRAPP_FARM, TXT_MRAPP_FARM, IMG_MRAPP_MAINMENU_FARM, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMRAPP, MRAPP_FARM},
#endif

#ifdef MRAPP_SIMUGAME_OPEN
    {ID_MRAPP_NESGAME, TXT_MRAPP_NESGAME, IMG_MRAPP_MAINMENU_NETGAME, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMRAPP, MRAPP_NESGAME},
#endif

#ifdef MRAPP_SDKQQ_OPEN
    {ID_MRAPP_QQ, TXT_MRAPP_QQ, IMG_MRAPP_MAINMENU_QQ, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMRAPP, MRAPP_SDKQQ},
#endif

#ifdef MRAPP_MSN_OPEN
    {ID_MRAPP_MSN, TXT_MRAPP_MSN, IMG_MRAPP_MAINMENU_MSN, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMRAPP, MRAPP_MSN},
#endif

#ifdef MRAPP_FACEBOOK_OPEN
    {ID_MRAPP_FACEBOOK, TXT_MRAPP_FBOOK, IMG_MRAPP_MAINMENU_MAOPAO, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMRAPP, MRAPP_FACEBOOK},
#endif

#ifdef MRAPP_YAHOO_OPEN
    {ID_MRAPP_YAHOO, TXT_MRAPP_YAHOO, IMG_MRAPP_MAINMENU_MAOPAO, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMRAPP, MRAPP_YAHOO},
#endif

#ifdef MRAPP_SKYPE_OPEN
    {ID_MRAPP_SKYPE, TXT_MRAPP_SKYPE, IMG_MRAPP_MAINMENU_MAOPAO, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMRAPP, MRAPP_SKYPE},
#endif

#ifdef MRAPP_TWITTER_OPEN
    {ID_MRAPP_TWITTER, TXT_MRAPP_TWITTER, IMG_MRAPP_MAINMENU_MAOPAO, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMRAPP, MRAPP_TWITTER},
#endif

#ifdef MRAPP_CLOCK_OPEN
    {ID_MRAPP_CLOCK, TXT_MRAPP_CLOCK, IMG_MRAPP_MAINMENU_CLOCK, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMRAPP, MRAPP_CLOCK},
#endif

#ifdef MRAPP_TIANQI_OPEN
    {ID_MRAPP_TIANQI, TXT_MRAPP_TIANQI, IMG_MRAPP_MAINMENU_WEATHER, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMRAPP, MRAPP_TIANQI},
#endif

#ifdef MRAPP_TOOL_OPEN
    {ID_MRAPP_TOOL, TXT_MRAPP_TOOL, IMG_MRAPP_MAINMENU_TOOL, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMRAPP, MRAPP_TOOL},
#endif

#ifdef MRAPP_ENDICT_OPEN
    {ID_MRAPP_ENDICT, TXT_MRAPP_ENDICT, IMG_MRAPP_MAINMENU_ENDICT, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMRAPP, MRAPP_ENDICT},
#endif

#ifdef MRAPP_CHDICT_OPEN
    {ID_MRAPP_CHDICT, TXT_MRAPP_CHDICT, IMG_MRAPP_MAINMENU_CHDICT, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMRAPP, MRAPP_CHDICT},
#endif
#endif


    //============== MET MEX start ===================
#ifdef MET_MEX_MERIG_SUPPORT
#ifndef MEX_G7_UI_SUPPORT
    {ID_MAINMENU_MET_MEX_ITEM_ID, TXT_MET_MEX, IMG_MET_MEX_A, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMetMex, 0},
#endif // MET_MEX_MERIG_SUPPORT
#endif

#ifdef MET_MEX_QQ_SUPPORT
    {ID_MAINMENU_MET_MEX_QQ_ITEM_ID, TXT_MET_MEX_QQ, IMG_MET_MEX_ICON_QQ_ONLINE_A, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMetMexQQ, 0},
#endif

#ifdef MET_MEX_TB_SUPPORT
    {ID_MAINMENU_MET_MEX_TB_ITEM_ID, TXT_MET_MEX_TB, IMG_MET_MEX_TB_A, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMetMexTB, 0},
#endif

#ifdef MET_MEX_AQ_SUPPORT
    {ID_MAINMENU_MET_MEX_AQ_ITEM_ID, TXT_MET_MEX_AQ, IMG_MET_MEX_AQ_A, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMetMexAQ, 0},
#endif

#ifdef MET_MEX_ZT_SUPPORT
    {ID_MAINMENU_MET_MEX_ZT_ITEM_ID, TXT_MET_MEX_ZT, IMG_MET_MEX_ZT_A, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMetMexZT, 0},
#endif

#ifdef MET_MEX_FRUITNINJA_SUPPORT
    {ID_MAINMENU_MET_MEX_FRUITNINJA_ITEM_ID, TXT_MET_MEX_FRUITNINJA, IMG_MET_MEX_FRUITNINJA_A, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMetMexFruitNinja, 0},
#endif

#ifdef MET_MEX_WEIBO_SUPPORT
    {ID_MAINMENU_MET_MEX_WEIBO_ITEM_ID, TXT_MET_MEX_WEIBO, IMG_MET_MEX_WEIBO_A, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMetMexWeibo, 0},
#endif

#ifdef MET_MEX_WEATHER_SUPPORT
    {ID_MAINMENU_MET_MEX_WEATHER_ITEM_ID, TXT_MET_MEX_WEATHER, IMG_MET_MEX_WEATHER_A, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMetMexWeather, 0},
#endif

#ifdef MET_MEX_WOMIVIDEO_SUPPORT
    {ID_MAINMENU_MET_MEX_WOMIVIDEO_ITEM_ID, TXT_MET_MEX_WOMIVIDEO, IMG_MET_MEX_WOMIVIDEO_A, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMetMexWomiVideo, 0},
#endif

#ifdef MET_MEX_DOUBLE_QQ_SUPPORT
    {ID_MAINMENU_MET_MEX_QQ1_ITEM_ID, TXT_MET_MEX_QQ, IMG_MET_MEX_ICON_QQ_ONLINE_A, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMetMexQQ1, 0},
    {ID_MAINMENU_MET_MEX_QQ2_ITEM_ID, TXT_MET_MEX_QQ, IMG_MET_MEX_ICON_QQ_ONLINE_A, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMetMexQQ2, 0},
#endif

#ifdef MET_MEX_MSN_SUPPORT
    {ID_MAINMENU_MET_MEX_MSN_ITEM_ID, TXT_MET_MEX_MSN, IMG_MET_MEX_MSN_A, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMetMexMSN, 0},
#endif

#ifdef MET_MEX_FETION_SUPPORT
    {ID_MAINMENU_MET_MEX_FETION_ITEM_ID, TXT_MET_MEX_FETION, IMG_MET_MEX_FETION_A, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMetMexFetion, 0},
#endif

#ifdef MET_MEX_AB_SUPPORT
    {ID_MAINMENU_MET_MEX_AB_ITEM_ID, TXT_MET_MEX_AB, IMG_MET_MEX_AB_A, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMetMexAB, 0},
#endif

#ifdef MET_MEX_CQZ_SUPPORT
    {ID_MAINMENU_MET_MEX_CQZ_ITEM_ID, TXT_MET_MEX_CQZ, IMG_MET_MEX_CQZ_A, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMetMexCQZ, 0},
#endif

#ifdef MET_MEX_JSCB_SUPPORT
    {ID_MAINMENU_MET_MEX_JSCB_ITEM_ID, TXT_MET_MEX_JSCB, IMG_MET_MEX_JSCB_A, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMetMexJSCB, 0},
#endif

#ifdef MET_MEX_TOMCAT_SUPPORT
    {ID_MAINMENU_MET_MEX_TOMCAT_ITEM_ID, TXT_MET_MEX_TOMCAT, IMG_MET_MEX_TOMCAT_A, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartMetMexTomCat, 0},
#endif
    //============== MET MEX end ===================

#ifdef QBTHEME_SUPPORT
    {ID_MAINMENU_QBTHEMEAPP, TXT_QB_THEME_STYLES, IMAGE_MAINMENU_ICON_QBTHEME, IMAGE_MAINMENU_ICON_SELECT, MMIAPIQBTHEME_OpenMainWin, 0},
    {ID_MAINMENU_QBTHEMEMORE, TXT_QB_MORE_THEME, IMAGE_MAINMENU_ICON_MORE_THEME, IMAGE_MAINMENU_ICON_SELECT, MMIAPIQBTHEME_OpenDownLoadUrl, 0},
#endif
#if defined(MMI_INDIAN_SOS_SUPPORT) && defined(MMI_PDA_SUPPORT)
    {ID_SETTINGS_SOS, TXT_SETTINGS_SOS, IMAGE_MAINMENU_ICON_SOS, IMAGE_MAINMENU_ICON_SELECT, MMIMAINMENU_StartSOSSetting, 0},
#endif
};