#ifndef _MMIFORMULA_ID_H_
#define _MMIFORMULA_ID_H_ 

#include "sci_types.h"
#include "os_api.h"
#include "mmk_type.h"
#include "mmi_module.h"


PUBLIC void MMIFORMULA_CreateIconlistWin(void);
//MMI_APPLICATION_T   		mmi_mp_formula_app;
#ifdef __cplusplus
    extern   "C"
    {
#endif

#define WIN_ID_DEF(win_id, win_id_name)        win_id,
 
// window ID
typedef enum
{
    MMI_FORMULA_WIN_ID_START = (MMI_MODULE_FORMULA_WIN_ID << 16),

    FORMULA_MNEMONIC_WIN_ID,
    FORMULA_WIN_ID,
    FORMULA_TABLE_WIN_ID,
    
    MMI_FORMULA_MAX_WIN_ID
}MMIFORMULA_ID_E;


#define WIN_ID_DEF(win_id)          win_id

// window ID

typedef enum {
    FORMULA_CTRL_ID_START = MMI_FORMULA_MAX_WIN_ID,

    FORMULA_MNEMONIC_LIST_CTRL_ID,
    FORMULA_BUTTON_PLAY_CTRL_ID,
    FORMULA_BUTTON_STOP_CTRL_ID,
    FORMULA_BUTTON_RESET_CTRL_ID,
    
    FORMULA_FORM_CTRL_ID,
    
    FORMULA_FORM_CHILD_1_CTRL_ID,
    FORMULA_FORM_CHILD_2_CTRL_ID,
    FORMULA_FORM_CHILD_3_CTRL_ID,
    FORMULA_FORM_CHILD_4_CTRL_ID,

    FORMULA_FORM_CHILD_1_LIST_1_CTRL_ID,
    FORMULA_FORM_CHILD_1_LIST_2_CTRL_ID,
    
    FORMULA_FORM_CHILD_2_LIST_1_CTRL_ID,
    FORMULA_FORM_CHILD_2_LIST_2_CTRL_ID,
    
    FORMULA_FORM_CHILD_3_LIST_1_CTRL_ID,
    FORMULA_FORM_CHILD_3_LIST_2_CTRL_ID,
    
    FORMULA_FORM_CHILD_4_LIST_1_CTRL_ID,
    FORMULA_FORM_CHILD_4_LIST_2_CTRL_ID,
    
    FORMULA_MAX_CTRL_ID
} FORMULA_CONTROL_ID_E;
#undef WIN_ID_DEF

// control ID

#undef WIN_ID_DEF

#ifdef   __cplusplus
    }
#endif

#endif //_MMIFORMULA_ID_H_
