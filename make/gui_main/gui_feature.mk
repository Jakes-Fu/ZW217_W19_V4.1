################################################################################
# Ŀ¼ʽ�ܿأ��ж�һ���ؼ��Ƿ�֧��
# �����ؼ�����֧�ֵģ�������ؼ�Ҳ������֧�ֵ�
# ����һЩ��ѡ֧�ֵ�����ؼ�
# ��Ϊ��֧�ֿ��Ʊ���������������;�������ú��ͬ����������ʶ
# GUIF_XXXX - GUI F(eature) (controller name)
# Ŀǰ���ǵĿؼ���û�зֲ�Σ���δ�л����ؼ�����չ�ؼ�֮��(2012-6-20 11:11:28)
################################################################################
GUIF_ANIM = TRUE
GUIF_BUTTON = TRUE
GUIF_DROPDOWNLIST = TRUE
GUIF_EDITBOX = TRUE
GUIF_FORM = TRUE

# ---- ICONFOLDER ----
GUIF_ICONFOLDER = TRUE

ifeq ($(strip $(LOW_MEMORY_SUPPORT)), 16X16)
	GUIF_ICONFOLDER = FALSE
endif

ifeq ($(strip $(LOW_MEMORY_SUPPORT)), 32X16)
	GUIF_ICONFOLDER = FALSE
endif

# ---- ICONLIST ----
ifneq ($(strip $(LOW_MEMORY_SUPPORT)), 16X16)
	GUIF_ICONLIST = TRUE
endif

GUIF_IM = TRUE
GUIF_LABEL = TRUE
GUIF_LIST = TRUE
GUIF_MENU = TRUE
GUIF_MSGBOX = TRUE
GUIF_OWNDRAW = TRUE
GUIF_PRGBOX = TRUE
GUIF_RICHTEXT = TRUE

# ---- SCROLLKEY ----
ifneq ($(strip $(TOUCHPANEL_TYPE)), NONE)
	ifneq ($(strip $(MMI_RES_ORIENT)), LANDSCAPE) 
		GUIF_SCROLLKEY = TRUE
	endif
endif

GUIF_SETLIST = TRUE
GUIF_SOFTKEY = TRUE
GUIF_STATUSBAR = TRUE
GUIF_TAB = TRUE
GUIF_TEXTBOX = TRUE
GUIF_TIPS = TRUE
GUIF_TITLE = TRUE

# ---- TOOLBAR ----
ifeq ($(strip $(LOW_MEMORY_SUPPORT)), 64X64)
	GUIF_TOOLBAR = TRUE
endif

ifeq ($(strip $(LOW_MEMORY_SUPPORT)), 128X64)
	GUIF_TOOLBAR = TRUE
endif

# ---- COMBOX ----
GUIF_COMBOX = TRUE

################################################################################
# ����һ���ֹ��ܺ�������ϵͳ��صģ���������ĳһ���ؼ���������а�
# GUIF_YYYY - GUI F(eature) (feature name)
################################################################################
# ---- CLIPBOARD ----
ifneq ($(strip $(TOUCHPANEL_TYPE)), NONE)
	GUIF_CLIPBOARD = FALSE
endif




#================= value ============ split ============ marco ================#


################################################################################
# ϵͳ���ܺ궨��
# GUIF_YYYY - GUI F(eature) (feature name)
################################################################################
# ---- CLIPBOARD ----
ifeq ($(strip $(GUIF_CLIPBOARD)), TRUE)
	MCFLAG_OPT += -DGUIF_CLIPBOARD
endif



################################################################################
# ���£����ÿ���ؼ������书���Ƿ�֧��
# ����һ�������Ƿ�֧�֣�������ֱ��ָ��֧�ֻ��߲�֧�ֵģ�����������ϵͳ�����趨
# ���Ŀǰ��һЩ���ܶ�����Ӧ�����������Ǳ������¶���������
# GUIF_XXXX_YYYY - GUI F(eature) (controller name) (feature name)
################################################################################
# ---- ANIM ----
ifeq ($(strip $(GUIF_ANIM)), TRUE)
	MCFLAG_OPT += -DGUIF_ANIM
	
#	ifneq ($(strip $(LOW_MEMORY_SUPPORT)), 16X16)
		MCFLAG_OPT += -DGUIF_ANIM_ROTATE
		MCFLAG_OPT += -DGUIF_ANIM_ZOOM
#	endif
endif

# ---- BUTTON ----
ifeq ($(strip $(GUIF_BUTTON)), TRUE)
	MCFLAG_OPT += -DGUIF_BUTTON
endif

# ---- DROPDOWNLIST ----
ifeq ($(strip $(GUIF_DROPDOWNLIST)), TRUE)
	MCFLAG_OPT += -DGUIF_DROPDOWNLIST
endif

# ---- EDITBOX ----
ifeq ($(strip $(GUIF_EDITBOX)), TRUE)
	MCFLAG_OPT += -DGUIF_EDITBOX

	ifeq ($(strip $(MMI_PDA_SUPPORT)), TRUE)
		MCFLAG_OPT += -DGUIF_EDIT_PDASTYLE
	endif
endif

# ---- FORM ----
ifeq ($(strip $(GUIF_FORM)), TRUE)
	MCFLAG_OPT += -DGUIF_FORM

	# GUIF_FORM_DOCKABLE
	GUIF_FORM_DOCKABLE = TRUE

	ifeq ($(strip $(LOW_MEMORY_SUPPORT)), 16X16)
		GUIF_FORM_DOCKABLE = FALSE;
	endif

	ifeq ($(strip $(LOW_MEMORY_SUPPORT)), 32X16)
		GUIF_FORM_DOCKABLE = FALSE;
	endif

	ifeq ($(strip $(GUIF_FORM_DOCKABLE)), TRUE)
		MCFLAG_OPT += -DGUIF_FORM_DOCKABLE
	endif	
endif

# ---- ICONFOLDER ----
ifeq ($(strip $(GUIF_ICONFOLDER)), TRUE)
	MCFLAG_OPT += -DGUIF_ICONFOLDER
endif

# ---- ICONLIST ----
ifeq ($(strip $(GUIF_ICONLIST)), TRUE)
	MCFLAG_OPT += -DGUIF_ICONLIST
	
	MCFLAG_OPT += -DGUIF_ICONLIST_DELIMITER

	ifeq ($(strip $(MMI_PDA_SUPPORT)), TRUE)
		MCFLAG_OPT += -DGUIF_ICONLIST_PDASTYLE
		MCFLAG_OPT += -DGUIF_ICONLIST_STUNT
	endif
endif

# ---- IM ----
ifeq ($(strip $(GUIF_IM)), TRUE)
	MCFLAG_OPT += -DGUIF_IM
	
	# �����е�"\r\n"����"\n"��Ŀǰsogou���뷨�����
	ifeq ($(strip $(IM_ENGINE)), SOGOU)
		MCFLAG_OPT += -DGUIF_IM_NEWLINE_ENTER
	endif

endif

# ---- LABEL ----
ifeq ($(strip $(GUIF_LABEL)), TRUE)
	MCFLAG_OPT += -DGUIF_LABEL
endif

# ---- LIST ----
ifeq ($(strip $(GUIF_LIST)), TRUE)
	MCFLAG_OPT += -DGUIF_LIST

	ifeq ($(strip $(MMI_PDA_SUPPORT)), TRUE)
		MCFLAG_OPT += -DGUIF_LIST_PDASTYLE
	endif

	ifeq ($(strip $(CMCC_UI_STYLE)), TRUE)
		MCFLAG_OPT += -DGUIF_LIST_PDASTYLE
	endif

	# CUSTOMITEMSTYLE
#	ifeq ($(strip $(LOW_MEMORY_SUPPORT)), 16X16)
#		MCFLAG_OPT += -DGUIF_LIST_CUSTOMITEMSTYLE
#	endif
	
#	ifeq ($(strip $(LOW_MEMORY_SUPPORT)), 32X16)
#		MCFLAG_OPT += -DGUIF_LIST_CUSTOMITEMSTYLE
#	endif
	
#	ifeq ($(strip $(LOW_MEMORY_SUPPORT)), 32X64)
#		MCFLAG_OPT += -DGUIF_LIST_CUSTOMITEMSTYLE
#	endif
	
#	ifeq ($(strip $(LOW_MEMORY_SUPPORT)), 64X64)
#		MCFLAG_OPT += -DGUIF_LIST_CUSTOMITEMSTYLE
#	endif
	
#	ifeq ($(strip $(LOW_MEMORY_SUPPORT)), NONE)
#		MCFLAG_OPT += -DGUIF_LIST_CUSTOMITEMSTYLE
#	endif
endif

# ---- MENU ----
ifeq ($(strip $(GUIF_MENU)), TRUE)
	MCFLAG_OPT += -DGUIF_MENU
endif

# ---- MSGBOX ----
ifeq ($(strip $(GUIF_MSGBOX)), TRUE)
	MCFLAG_OPT += -DGUIF_MSGBOX
endif

# ---- OWNDRAW ----
ifeq ($(strip $(GUIF_OWNDRAW)), TRUE)
	MCFLAG_OPT += -DGUIF_OWNDRAW
endif

# ---- PRGBOX ----
ifeq ($(strip $(GUIF_PRGBOX)), TRUE)
	MCFLAG_OPT += -DGUIF_PRGBOX

	# LETTERSCROLL support
	ifeq ($(strip $(LOW_MEMORY_SUPPORT)), 32X64)
		MCFLAG_OPT += -DGUIF_PRGBOX_LETTERSCROLL
	endif
	
	ifeq ($(strip $(LOW_MEMORY_SUPPORT)), 64X64)
		MCFLAG_OPT += -DGUIF_PRGBOX_LETTERSCROLL
	endif
	
	ifeq ($(strip $(LOW_MEMORY_SUPPORT)), 128X64)
		MCFLAG_OPT += -DGUIF_PRGBOX_LETTERSCROLL
	endif
	
	ifeq ($(strip $(LOW_MEMORY_SUPPORT)), NONE)
		MCFLAG_OPT += -DGUIF_PRGBOX_LETTERSCROLL
	endif
	
	# auto hide
	ifeq ($(strip $(MMI_PDA_SUPPORT)), TRUE)
		MCFLAG_OPT += -DGUIF_PRGBOX_AUTOHIDE
	endif

endif

# ---- RICHTEXT ----
ifeq ($(strip $(GUIF_RICHTEXT)), TRUE)
	MCFLAG_OPT += -DGUIF_RICHTEXT
endif

# ---- SCROLLKEY ----
ifeq ($(strip $(GUIF_SCROLLKEY)), TRUE)
	MCFLAG_OPT += -DGUIF_SCROLLKEY
endif

# ---- SETLIST ----
ifeq ($(strip $(GUIF_SETLIST)), TRUE)
	MCFLAG_OPT += -DGUIF_SETLIST
endif

# ---- SOFTKEY ----
ifeq ($(strip $(GUIF_SOFTKEY)), TRUE)
	MCFLAG_OPT += -DGUIF_SOFTKEY

	ifeq ($(strip $(MMI_PDA_SUPPORT)), TRUE)
		MCFLAG_OPT += -DGUIF_SOFTKEY_PDASTYLE
	endif

	ifeq ($(strip $(MID_SOFTKEY_USE_IMG_SUPPORT)),TRUE)
		MCFLAG_OPT += -DGUIF_SOFTKEY_MID_USE_IMG
	endif
endif

# ---- STATUSBAR ----
ifeq ($(strip $(GUIF_STATUSBAR)), TRUE)
	MCFLAG_OPT += -DGUIF_STATUSBAR

	# STB_SCROLL_SUPPORT
	GUIF_STATUSBAR_SCROLL = TRUE

	ifeq ($(strip $(LOW_MEMORY_SUPPORT)), 16X16)
		GUIF_STATUSBAR_SCROLL = FALSE;
	endif

	ifeq ($(strip $(LOW_MEMORY_SUPPORT)), 32X16)
		GUIF_STATUSBAR_SCROLL = FALSE;
	endif

	ifeq ($(strip $(GUIF_STATUSBAR_SCROLL)), TRUE)
		MCFLAG_OPT += -DGUIF_STATUSBAR_SCROLL
	endif	
	
	ifeq ($(strip $(DUAL_BATTERY_SUPPORT)), TRUE)
		MCFLAG_OPT += -DGUIF_STATUSBAR_DUAL_BATTERY
	endif
endif

# ---- TAB ----
ifeq ($(strip $(GUIF_TAB)), TRUE)
	MCFLAG_OPT += -DGUIF_TAB
endif

# ---- TEXTBOX ----
ifeq ($(strip $(GUIF_TEXTBOX)), TRUE)
	MCFLAG_OPT += -DGUIF_TEXTBOX
endif

# ---- TIPS ----
ifeq ($(strip $(GUIF_TIPS)), TRUE)
	MCFLAG_OPT += -DGUIF_TIPS
endif

# ---- TITLE ----
ifeq ($(strip $(GUIF_TITLE)), TRUE)
	MCFLAG_OPT += -DGUIF_TITLE

	ifeq ($(strip $(MMI_PDA_SUPPORT)), TRUE)
		MCFLAG_OPT += -DGUIF_TITLE_PDASTYLE
	endif
endif

# ---- TOOLBAR ----
ifeq ($(strip $(GUIF_TOOLBAR)), TRUE)
	MCFLAG_OPT += -DGUIF_TOOLBAR
endif

# ---- COMBOX ----
ifeq ($(strip $(GUIF_COMBOX)), TRUE)
	MCFLAG_OPT += -DGUIF_COMBOX
endif