/*****************************************************************************
** File Name:      mmialarm_id.h                                             *
** Author:                                                                   *
** Date:           2006/09/12                                                *
** Copyright:      2006 Spreadtrum, Incoporated. All Rights Reserved.         *
** Description:    This file is used to describe alarm win and control id    *
******************************************************************************
**                         Important Edit History                            *
** --------------------------------------------------------------------------*
** DATE           NAME             DESCRIPTION                               *
** 2006/09/12     liqing.peng      Create                                    *
******************************************************************************/

#ifndef _MMIALARM_ID_H_
#define _MMIALARM_ID_H_ 

/**--------------------------------------------------------------------------*
 **                         Include Files                                    *
 **--------------------------------------------------------------------------*/
#include "sci_types.h"
#include "os_api.h"
#include "mmk_type.h"
#include "mmi_module.h"

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


/**--------------------------------------------------------------------------*
 **                         TYPE AND CONSTANT                                *
 **--------------------------------------------------------------------------*/
 
#define WIN_ID_DEF(win_id)          win_id

// window ID
typedef enum
{
    ALARM_WIN_ID_START = (MMI_MODULE_ALARM << 16),

#include "mmialarm_id.def"

    ALARM_MAX_WIN_ID
}ALARM_WINDOW_ID_E;

#undef WIN_ID_DEF

// control ID
typedef enum
{
    ALARM_CTRL_ID_ID_START = ALARM_MAX_WIN_ID,//(MMI_MODULE_ALARM << 16),

  	MMIALM_LISTALL_CTRL_ID,
	MMIALM_SETNAME_CTRL_ID,  	
  	MMIALM_SETTIME_CTRL_ID,
  	MMIALM_MODSEL_CTRL_ID,
    MMIALM_MODELIST_CTRL_ID,
    MMIALM_RINGLIST_CTRL_ID,
    MMIALM_FIXEDRINGLIST_CTRL_ID,
  	MMIALM_TEXTEDIT_CTRL_ID,
    MMIALM_MODE_MENU_CTRL_ID,
//    MMIALM_OPT_MENU_CTRL_ID,
	MMI_EDITWIN_FORM_CTRL_ID,
	MMIALM_EDIT_MODE_SETLIST_CTRL_ID,
	MMIALM_EDIT_SELECT_WEEK_LABEL_CTRL_ID,
	MMIALM_EDIT_NAME_FORM_CTRL_ID,
	MMIALM_EDIT_NAME_LABEL_CTRL_ID,
    MMIALM_EDIT_NAME_EDIT_LABEL_CTRL_ID,
	MMIALM_EDIT_NAME_EDITBOX_CTRL_ID,
    MMIALM_EDIT_TIME_FORM_CTRL_ID,
	MMIALM_EDIT_TITLE_LABEL_CTRL_ID,
    MMIALM_EDIT_TITLE_EDIT_LABEL_CTRL_ID,
	MMIALM_EDIT_TITLE_EDITBOX_CTRL_ID,
    MMIALM_EDIT_RING_FORM_CTRL_ID,
    MMIALM_EDIT_RING_TITLE_FORM_CTRL_ID,
    MMIALM_EDIT_RING_BUTTON_CTRL_ID,
	MMIALM_EDIT_RING_LABEL_CTRL_ID,
	MMIALM_EDIT_RING_TEXT_CTRL_ID,
	MMIALM_EDIT_RING_TYPE_CTRL_ID,
    MMIALM_EDIT_MODE_FORM_CTRL_ID,
#ifdef MMI_GUI_STYLE_MINISCREEN
    MMIALM_EDIT_MODE_FORM2_CTRL_ID,
#endif
	MMIALM_EDIT_MODE_BUTTON_CTRL_ID,
	MMIALM_EDIT_MODE_LABEL_CTRL_ID,
//	MMIALM_EDIT_MODE_LIST1_CTRL_ID,
//	MMIALM_EDIT_MODE_LIST2_CTRL_ID,
//	MMIALM_EDIT_MODE_LIST3_CTRL_ID,
#ifdef CMCC_UI_STYLE
    MMIALM_EDIT_RING_DUR_FORM_CTRL_ID,
    MMIALM_EDIT_RING_DUR_LABLE_CTRL_ID,
    MMIALM_EDIT_RING_DUR_SETLIST_CTRL_ID,
    MMISCH_REMIND_FORM_CTRL_ID,
    MMISCH_REMIND_TITLE_LABLE_CTRL_ID,
    MMISCH_REMIND_SETLIST_CTRL_ID,
    MMIALM_EDIT_VIBRATE_FORM_CTRL_ID,
    MMIALM_EDIT_VIBRATE_LABLE_CTRL_ID,
    MMIALM_EDIT_VIBRATE_SWICTH_CTRL_ID,
#endif

#ifdef MMI_ALARM_DEL_ADD_SUPPORT
	MMIALM_OPT_MENU_CTRL_ID,
#endif
  	MMI_EDITWIN_CHILD_FORM_CTRL_ID,
  	MMI_EDITWIN_BUTTON0_CTRL_ID,
  	MMI_EDITWIN_BUTTON1_CTRL_ID,
  	MMI_EDITWIN_BUTTON2_CTRL_ID,
  	MMI_EDITWIN_BUTTON3_CTRL_ID,
  	MMI_EDITWIN_BUTTON4_CTRL_ID,
  	MMI_EDITWIN_BUTTON5_CTRL_ID,
  	MMI_EDITWIN_BUTTON6_CTRL_ID,
  	MMI_FM_EDITWIN_FORM_CTRL_ID,
    MMI_FM_EDITWIN_LIST_FORM_CTRL_ID,
  	MMI_FM_EDITWIN_LIST_LABEL_CTRL_ID,
    MMI_FM_EDITWIN_FRE_FORM_CTRL_ID,
  	MMI_FM_EDITWIN_FRE_LABEL_CTRL_ID,
  	MMI_FM_EDITWIN_FRE_EDIT_CTRL_ID,
  	
    MMIALM_EDIT_MODE_BUT0_CTRL_ID,
    MMIALM_EDIT_MODE_BUT1_CTRL_ID,
    MMIALM_EDIT_MODE_BUT2_CTRL_ID,
    MMIALM_EDIT_MODE_BUT3_CTRL_ID,
    MMIALM_EDIT_MODE_BUT4_CTRL_ID,
    MMIALM_EDIT_MODE_BUT5_CTRL_ID,
    MMIALM_EDIT_MODE_BUT6_CTRL_ID,

    MMIALM_EDIT_RING_MENU_CTRL_ID,
    MMIALM_EDIT_RING_LIST_CTRL_ID,

    MMIALM_AUTOPOWER_LIST_CTRL_ID,
    MMIALM_AUTO_POWERON_MSGBOX_CTRL_ID,
    MMIALM_AUTO_POWEROFF_MSGBOX_CTRL_ID,

    MMICALENDAR_OPT_MENU_CTRL_ID,
    MMICALENDAR_QUERY_DATE_LABEL_CTRL_ID,
    MMICALENDAR_QUERY_DATEEDITBOX_CTRL_ID,
    MMICALENDAR_LUNAR_DETAIL_TEXT_CTRL_ID,
    
    MMISCH_VIEW_LIST_CTRL_ID,
    MMISCH_VIEW_ALL_LIST_CTRL_ID,
    MMISCH_VIEW_UNREAD_LIST_CTRL_ID,
    
    MMISCH_VIEW_DETAIL_TEXT_CTRL_ID,
    /*MMISCH_VIEW_NAME_TITLE_LABEL_CTRL_ID,
    MMISCH_VIEW_NAME_LABEL_CTRL_ID,  
    MMISCH_VIEW_DATE_TITLE_LABEL_CTRL_ID,
    MMISCH_VIEW_DATE_LABEL_CTRL_ID,    
    MMISCH_VIEW_TIME_TITLE_LABEL_CTRL_ID,
    MMISCH_VIEW_TIME_LABEL_CTRL_ID,
    MMISCH_VIEW_RING_TITLE_LABEL_CTRL_ID,
    MMISCH_VIEW_RING_LABEL_CTRL_ID,
    MMISCH_VIEW_FREQ_TITLE_LABEL_CTRL_ID,
    MMISCH_VIEW_FREQ_LABEL_CTRL_ID,
    MMISCH_VIEW_DEADLINE_TITLE_LABEL_CTRL_ID,
    MMISCH_VIEW_DEADLINE_LABEL_CTRL_ID,*/

    MMISCH_VCALENDAR_DETAIL_TEXT_CTRL_ID,
    
    MMISCH_EDIT_WIN_FORM_CTRL_ID,
    MMISCH_WEEK_LIST_LABEL_CTRL_ID,
    MMISCH_EDITWIN_WEEKS_LIST_CTRL_ID,
    MMISCH_NAME_FORM_CTRL_ID,
    MMISCH_NAME_TITLE_LABEL_CTRL_ID,
    MMISCH_NAME_EDIT_CTRL_ID,
    MMISCH_NAME_EDIT_LABEL_CTRL_ID,
    MMISCH_DATE_FORM_CTRL_ID,
    MMISCH_DATE_TITLE_LABEL_CTRL_ID,
    MMISCH_DATE_EDIT_CTRL_ID,
    MMISCH_DATE_EDIT_LABEL_CTRL_ID,
    MMISCH_TIME_FORM_CTRL_ID,
    MMISCH_TIME_TITLE_LABEL_CTRL_ID,
    MMISCH_TIME_EDIT_CTRL_ID,
	MMISCH_EDIT_RING_BUTTON_CTRL_ID,
	MMISCH_EDIT_RING_FORM_CTRL_ID,
    MMISCH_TIME_EDIT_LABEL_CTRL_ID,
    MMISCH_RING_FORM_CTRL_ID,
    MMISCH_RING_TITLE_LABEL_CTRL_ID,
    MMISCH_RING_LABEL_CTRL_ID,
    MMISCH_FREQ_FORM_CTRL_ID,
    MMISCH_FREQ_TITLE_LABEL_CTRL_ID,
    MMISCH_FREQ_TYPE_FORM_CTRL_ID,
    MMISCH_FREQ_SETLIST_CTRL_ID,
    MMISCH_DEADLINE_FORM_CTRL_ID,
    MMISCH_DEADLINE_TITLE_LABEL_CTRL_ID,
    MMISCH_DEADLINE_EDIT_CTRL_ID,
    MMISCH_DEADLINE_EDIT_LABEL_CTRL_ID,
    MMISCH_EDITWIN_CHILD_FORM_CTRL_ID,
    MMISCH_EDITWIN_BUTTON0_CTRL_ID,
    MMISCH_EDITWIN_BUTTON1_CTRL_ID,
    MMISCH_EDITWIN_BUTTON2_CTRL_ID,
    MMISCH_EDITWIN_BUTTON3_CTRL_ID,
    MMISCH_EDITWIN_BUTTON4_CTRL_ID,
    MMISCH_EDITWIN_BUTTON5_CTRL_ID,
    MMISCH_EDITWIN_BUTTON6_CTRL_ID,
    MMISCH_TEXT_FORM_CTRL_ID,
    MMISCH_TEXT_TITLE_LABEL_CTRL_ID,
    MMISCH_TEXT_EDIT_CTRL_ID,
    
	MMISCH_EDIT_LIST_CTRL_ID,
	MMISCH_CONTENT_LABEL_CTRL_ID,
	MMISCH_OPTION_MENU_CTRL_ID,
	MMISCH_LIST_OPTION_MENU_CTRL_ID,
	MMISCH_ALL_LIST_OPTION_MENU_CTRL_ID,
	MMISCH_LIST_MARK_OPTION_DYNAMIC_MENU_CTRL_ID,
	MMISCH_RINGLIST_CTRL_ID,
	MMISCH_FIXEDRINGLIST_CTRL_ID,
	MMISCH_DELETE_ANIM_WIN_ID,


    MMIFEAST_ALL_LIST_CTRL_ID,
    MMIFEAST_OPTION_MENU_CTRL_ID,
    MMIFEAST_INQUIRETEXT_CTRL_ID,
    MMIFEAST_INQUIRELIST_CTRL_ID,
    MMIFEAST_EDITNAME_CTRL_ID,
    MMIFEAST_EDITDATE_LABEL_CTRL_ID,
    MMIFEAST_EDITDATE_CTRL_ID,
    MMIFEAST_VIEW_DATETYPE_LABEL_CTRL_ID,
    MMIFEAST_VIEW_DATE_LABEL_CTRL_ID,
    MMIFEAST_VIEW_NAMETITLE_LABEL_CTRL_ID,
    MMICALENDAR_TAB_CTRL_ID,
    MMIALM_TIME_FORM_CTRL_ID,
    MMISCH_EDIT_TIME_FORM_CTRL_ID,
    MMISCH_EDIT_DATE_FORM_CTRL_ID,
    MMISCH_EDIT_DEADLINE_FORM_CTRL_ID,
    MMICALENDAR_EDIT_DATE_FORM_CTRL_ID,
    MMIALM_SELECT_FM_LIST_CTRL_ID,
    MMISCH_POP_ALERT_FORM_CTRL_ID,
    MMISCH_POP_ALERT_LIST_CTRL_ID,
    MMISCH_POP_ALERT_ANIM_CTRL_ID,
    MMISCH_POP_ALERT_LABEL_CTRL_ID,
    MMISCH_RECORD_RING_FORM_CTRL_ID,
    MMISCH_RECORD_RING_BUTTON_CTRL_ID,
    MMISCH_FREQ_TYPE_BUTTON_CTRL_ID,
#ifdef TOUCH_PANEL_SUPPORT
    MMICALENDAR_WEEK_LEFT_BUTTON_CTRL_ID,
    MMICALENDAR_WEEK_RIGHT_BUTTON_CTRL_ID,
#endif
    MMICALENDAR_LEFT_BUTTON_CTRL_ID,
    MMICALENDAR_RIGHT_BUTTON_CTRL_ID,
    MMICALENDAR_DAILY_OPT_MENU_CTRL_ID,

#ifdef CMCC_UI_STYLE
    MMISCH_DATE_STOP_FORM_CTRL_ID,
    MMISCH_DATE_STOP_TITLE_LABEL_CTRL_ID,
    MMISCH_DATE_STOP_EDIT_CTRL_ID,
    MMISCH_TIME_STOP_EDIT_CTRL_ID,
#endif    
#ifdef SCREEN_SHAPE_CIRCULAR
    //watch alarm main list win
    MMIALM_NO_ALARM_ICON_LABEL_CTRL_ID,
    MMIALM_MAIN_LIST_CTRL_ID,
    MMIALM_ADD_ALARM_BTN_CTRL_ID,
    //watch alarm edit win
    MMIALM_EDIT_ALARM_TIME_CTRL_ID,
    MMIALM_EDIT_ALARM_TIME_NEXT_BTN_CTRL_ID,
    //watch alarm repeat win
    MMIALM_REPEAT_LIST_CTRL_ID,
    MMIALM_REPEAT_FIXED_CTRL_ID,

    POWERONOFF_REPEAT_LIST_CTRL_ID,
    MMIALM_EDIT_MODE_SELECT_LABEL_CTRL_ID,
 #endif
    ALARM_MAX_CTRL_ID
}ALARM_CONTROL_ID_E;

/**--------------------------------------------------------------------------*
 **                         FUNCTION DEFINITION                              *
 **--------------------------------------------------------------------------*/



/**--------------------------------------------------------------------------*
 **                         Compiler Flag                                    *
 **--------------------------------------------------------------------------*/
#ifdef   __cplusplus
    }
#endif

#endif //_MMIALARM_ID_H_