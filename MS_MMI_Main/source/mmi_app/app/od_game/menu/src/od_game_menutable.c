#if defined(OD_GAME_SUPPORT)
#define _OD_GAME_MENUTABLE_C
#ifdef WIN32
#include "std_header.h"
#endif
#include "window_parse.h"
#include "guimenu.h"
#include "mmi_image.h"
#include "mmi_modu_main.h"
#include "mmi_module.h"
#include "od_game_menutable.h"
#include "od_game_res_id_def.h"

#ifndef TIP_NULL
#define TIP_NULL 0
#endif

#ifdef OD_DOODLE_JUMP_SUPPORT
const GUIMENU_ITEM_T  od_game_doodle_jump[] =
{
    {MENU_ID_OD_GAME_NEW,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_CLASSIC_NEW_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_NEW_2,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_JUNGLE_NEW_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_NEW_3,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_SPACE_NEW_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_RESUME,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_RESUME_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_HIGH_SCORES,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_HIGH_SCORE_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_SOUND,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_SOUND_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_HELP,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_HELP_TEXT,  	0, 0, 0, 0},
};
#endif

#ifdef OD_CROSSY_ROAD_SUPPORT
const GUIMENU_ITEM_T  od_game_crossy_road[] =
{
    {MENU_ID_OD_GAME_NEW,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_COCK_NEW_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_NEW_2,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_CAT_NEW_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_NEW_3,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_ROBOT_NEW_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_RESUME,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_RESUME_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_HIGH_SCORES,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_HIGH_SCORE_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_SOUND,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_SOUND_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_HELP,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_HELP_TEXT,  	0, 0, 0, 0},
};
#endif

#ifdef OD_STICK_HERO_SUPPORT
const GUIMENU_ITEM_T  od_game_stick_hero[] =
{
    {MENU_ID_OD_GAME_NEW,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_STICK_HERO_CLASSIC_NEW_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_NEW_2,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_STICK_HERO_ATHLETIC_NEW_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_NEW_3,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_STICK_HERO_FUNKY_NEW_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_RESUME,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_RESUME_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_HIGH_SCORES,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_HIGH_SCORE_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_SOUND,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_SOUND_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_HELP,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_HELP_TEXT,  	0, 0, 0, 0},
};
#endif

#ifdef OD_BUBBLE_PARTY_MIX_SUPPORT
const GUIMENU_ITEM_T  od_game_bubble_party_mix[] =
{
    {MENU_ID_OD_GAME_NEW,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_BUBBLE_PARTY_MIX_NEW_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_NEW_2,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_BUBBLE_PARTY_MIX_NEW2_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_RESUME,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_RESUME_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_HIGH_SCORES,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_HIGH_SCORE_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_SOUND,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_SOUND_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_HELP,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_HELP_TEXT,  	0, 0, 0, 0},
};
#endif

#ifdef OD_SUPER_PET_SUPPORT
const GUIMENU_ITEM_T  od_game_super_pet[] =
{
    {MENU_ID_OD_GAME_NEW,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_SUPER_PET_NEW_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_NEW_2,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_SUPER_PET_NEW2_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_RESUME,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_RESUME_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_HIGH_SCORES,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_HIGH_SCORE_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_SOUND,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_SOUND_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_HELP,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_HELP_TEXT,  	0, 0, 0, 0},
};
#endif

#ifdef OD_RUNNER_SUPPORT
const GUIMENU_ITEM_T  od_game_runner[] =
{
    {MENU_ID_OD_GAME_NEW,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_RUNNER_NEW_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_RESUME,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_RESUME_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_HIGH_SCORES,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_HIGH_SCORE_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_SOUND,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_SOUND_TEXT,  	0, 0, 0, 0},
    {MENU_ID_OD_GAME_HELP,   	TIP_NULL, 	{OD_GAME_OK_TEXT, TXT_NULL, OD_GAME_BACK_TEXT},   OD_GAME_HELP_TEXT,  	0, 0, 0, 0},
};
#endif

    
#define MENU_DEF(_TABLEID, _ITEMPTR, _STYLE, _TITLESTR, _TITLE_ICON, _TITLE_NUMICON, _TITLE_BACKGROUND, \
    _ITEMCOUNT) \
_ITEMPTR, _STYLE, _TITLESTR, _TITLE_ICON, _TITLE_NUMICON, _TITLE_BACKGROUND, _ITEMCOUNT, 

const GUIMENU_GROUP_T od_game_menu_table[] = 
{
{NULL},
#include "od_game_menutable.def"
};
#undef  MENU_DEF

PUBLIC void od_game_RegMenuGroup(void)
{
    MMI_RegMenuGroup(MMI_MODULE_OD_GAME, od_game_menu_table);
}
#endif
