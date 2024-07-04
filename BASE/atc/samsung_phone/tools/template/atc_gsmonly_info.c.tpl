/*******************************************************************************
 ** File Name:      atc_info.c                                                 *
 ** Author:         Steven.Yao                                                 *
 ** Date:           05/24/2002                                                 *
 ** Copyright:      2001 Spreatrum, Incoporated. All Rights Reserved.          *
 ** Description:    This file contains infomation structs definitions of ATC.  *
 **                 It is generated by atpgen program.                         *
 *******************************************************************************
                                                                               *
 *******************************************************************************
 **                        Edit History                                        *
 ** -------------------------------------------------------------------------- *
 ** DATE           NAME             DESCRIPTION                                *
 ** 05/24/2002     Steven.Yao       Create.                                    *
 ** 07/09/2002     Ivan.Yin         start to edit and modity                   *  
 ** 05/20/2002     Xueli Lv         Modify & Add
 ******************************************************************************/

/*******************************************************************************
 **                        Common Header Files                                 *
 ******************************************************************************/
#include "sci_types.h"

/*******************************************************************************
 **                        ATC Header Files                                    *
 ******************************************************************************/
#include "atc.h"

#include "atc_basic_cmd.h"
#include "atc_gsm.h"
#include "atc_gsm_ss.h"
#include "atc_gsm_sms.h"
#include "atc_samsung_prod.h"
#include "atc_gsm_stk.h"
#include "atc_phonebook.h"

/*lint -e651*/

###atcbegin
const ATC_PARAM_STRING_T    atc_cmd_name_##atcnamenoplus###atcend

###atcbegin
const ATC_PARAM_NUMERIC_T   atc_param_numeric_##atcnamenoplus###atcend

###atcbegin
const ATC_PARAM_STRING_T    atc_param_string_##atcnamenoplus###atcend

###atcbegin
const ATC_PARAM_INFO_T      atc_param_info_##atcnamenoplus###atcend


/*lint +e651*/

const ATC_INFO_T            g_atc_info_table[] =
{
###atcbegin
###atcend
};

ATC_Func_Handle_F g_atc_handle_table[] =
{
###atcbegin
    ATC_Process##atcnamenoplus,###atcend
};

const uint8    * g_atc_result_code_text[] = 
{
    (const uint8 *)"OK",
    (const uint8 *)"CONNECT",
    (const uint8 *)"RING",
    (const uint8 *)"NO CARRIER",
    (const uint8 *)"ERROR",
    (const uint8 *)NULL,
    (const uint8 *)"NO DIALTONE",
    (const uint8 *)"BUSY",
    (const uint8 *)"NO ANSWER"
};