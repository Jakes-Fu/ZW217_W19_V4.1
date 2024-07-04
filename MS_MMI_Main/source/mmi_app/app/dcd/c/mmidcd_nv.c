
/*************************************************************************
 ** File Name:      mmidcd_nv.c                                          *
 ** Author:         violent.wei                                          *
 ** Date:           2007/09/30                                           *
 ** Copyright:      2007 Spreadtrum, Incorporated. All Rights Reserved.  *
 ** Description:             											 *
 *************************************************************************
 *************************************************************************
 **                        Edit History                                  *
 ** ---------------------------------------------------------------------*
 ** DATE           NAME             DESCRIPTION                          *
 ** 2007/09/30     violent.wei      Create.                              *
*************************************************************************/


/**--------------------------------------------------------------------------*
 **                         Include Files                                    *
 **--------------------------------------------------------------------------*/
#ifdef WIN32
#include "std_header.h"
#endif
#include "mmi_modu_main.h"

#ifdef MMI_ENABLE_DCD	//!�궨�忪ͷ
#include "mmidcd_main.h"

/**--------------------------------------------------------------------------*
 **                         MACRO DEFINITION                                 *
 **--------------------------------------------------------------------------*/

/**--------------------------------------------------------------------------*
 **                         LOCAL DEFINITION                                 *
 **--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                          TYPE AND CONSTANT                                */
/*---------------------------------------------------------------------------*/

/**--------------------------------------------------------------------------*
 **                         EXTERNAL DECLARE                                 *
 **--------------------------------------------------------------------------*/

/**--------------------------------------------------------------------------*
 **                         GLOBAL DEFINITION                                *
 **--------------------------------------------------------------------------*/
/*the length of dcd nv*/
uint16 mmidcd_nv_len[] =
{
    sizeof(MMIDCD_NV_SETTING_T)
};

/*---------------------------------------------------------------------------*/
/*                          LOCAL FUNCTION DECLARE                           */
/*---------------------------------------------------------------------------*/

/**--------------------------------------------------------------------------*
 **                         FUNCTION DEFINITION                              *
 **--------------------------------------------------------------------------*/
/*****************************************************************************/
// 	Description :
//	Global resource dependence : 
//  Author:violent.wei
//	Note: 
/*****************************************************************************/
PUBLIC void MMIDCD_RegNv(void)
{
    MMI_RegModuleNv(MMI_MODULE_DCD,mmidcd_nv_len,sizeof(mmidcd_nv_len)/sizeof(uint16));
}

#endif /*#ifdef MMI_ENABLE_DCD*/