/******************************************************************************
 ** File Name:    pwm_reg_v1.h                                            *
 ** Author:       hao.liu                                                 *
 ** DATE:         06/11/2010                                                  *
 ** Copyright:    2010 Spreadtrum, Incoporated. All Rights Reserved.           *
 ** Description:                                                              *
 ******************************************************************************/
/******************************************************************************
 **                   Edit    History                                         *
 **---------------------------------------------------------------------------*
 ** DATE          NAME            DESCRIPTION                                 *
 ** 06/11/2010    hao.liu      Create.                                     *
 ******************************************************************************/
#ifndef _PWM_REG_V1_H_
#define _PWM_REG_V1_H_
/*----------------------------------------------------------------------------*
 **                         Dependencies                                      *
 **------------------------------------------------------------------------- */

/**---------------------------------------------------------------------------*
 **                             Compiler Flag                                 *
 **--------------------------------------------------------------------------*/
#ifdef   __cplusplus
extern   "C"
{
#endif
/**---------------------------------------------------------------------------*
**                               Micro Define                                **
**---------------------------------------------------------------------------*/
typedef struct pwm_tag
{
    VOLATILE uint32     prescale;
    VOLATILE uint32     cnt_duty;
    VOLATILE uint32     tone;
    VOLATILE uint32     pattern_low;
    VOLATILE uint32     pattern_high;
} pwm_s;
/**----------------------------------------------------------------------------*
**                             Data Prototype                                 **
**----------------------------------------------------------------------------*/

/**----------------------------------------------------------------------------*
**                         Local Function Prototype                           **
**----------------------------------------------------------------------------*/

/**----------------------------------------------------------------------------*
**                           Function Prototype                               **
**----------------------------------------------------------------------------*/


/**----------------------------------------------------------------------------*
**                         Compiler Flag                                      **
**----------------------------------------------------------------------------*/

#ifdef   __cplusplus
}
#endif
/**---------------------------------------------------------------------------*/
#endif
// End
