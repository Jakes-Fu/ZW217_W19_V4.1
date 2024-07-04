/******************************************************************************
**
**
**
**  С���㲥ģ��
**
**
**
**
**
**
*******************************************************************************/
#if defined(MMI_SMSCB_SUPPORT)

#ifndef  _MMISMSCB_INTERNAL_H_    
#define  _MMISMSCB_INTERNAL_H_   
/**--------------------------------------------------------------------------*
 **                         Include Files                                    *
 **--------------------------------------------------------------------------*/
#include "mmk_type.h"
#include "mn_type.h"

/**--------------------------------------------------------------------------*
 **                         Compiler Flag                                    *
 **--------------------------------------------------------------------------*/
#ifdef __cplusplus
    extern "C"
    {
#endif


#define MMI_MAX_CB_LANGUAGE_NUM (MN_CB_LANGUAGE_ID_MAX_NUM + 1)               //���������
#ifdef MMI_ETWS_SUPPORT
#define MMI_CB_CHANNEL_NAME_LEN 30               //����ŵ��б���
#else
#define MMI_CB_CHANNEL_NAME_LEN 10               //����ŵ��б���
#endif
#define MMI_MAX_CB_CHANNEL_NUM  MN_CB_MSG_ID_MAX_NUM               //����ŵ���

#ifdef MMI_ETWS_SUPPORT
#define MMI_MAX_CB_MSG_NUM      10     //���㲥��Ϣ�洢��
#else
#define MMI_MAX_CB_MSG_NUM      (10 * MMI_DUAL_SYS_MAX)     //���㲥��Ϣ�洢��
#endif
//------------------------------------------------------------------------------------------
//
// С���㲥����ѡ���б��ṹ
//
//------------------------------------------------------------------------------------------
typedef struct{

    BOOLEAN selected_arr[MMI_MAX_CB_LANGUAGE_NUM];                       //����ѡ���б�����

}MMISMS_CB_LANGUAGE_T;


//------------------------------------------------------------------------------------------
//
// С���㲥�ŵ����ƽṹ
//
//------------------------------------------------------------------------------------------
typedef struct{

        wchar    wstr[MMI_CB_CHANNEL_NAME_LEN + 1];                           //�ŵ������ַ�������
        uint16   wstr_len;                                                //�ŵ����Ƴ���
}MMISMS_CB_CHANNEL_NAME_T;

//------------------------------------------------------------------------------------------
//
// С���㲥�ŵ�ѡ��ṹ
//
//------------------------------------------------------------------------------------------
typedef struct{

        MN_CB_MSG_ID_T           msg_id;                                 //�ŵ�������
        MMISMS_CB_CHANNEL_NAME_T name;                                   //�ŵ���������
        BOOLEAN is_enabled;                                              //�Ƿ���       

}MMISMS_CB_CHANNEL_ITEM_T;

//------------------------------------------------------------------------------------------
//
// С���㲥�ŵ��б��ṹ
//
//------------------------------------------------------------------------------------------
typedef struct{

        uint16 num;                                                      //�ŵ�����
        MMISMS_CB_CHANNEL_ITEM_T channel_arr[MMI_MAX_CB_CHANNEL_NUM];    //�ŵ�ѡ������

}MMISMS_CB_CHANNEL_T;


/******************************************************************************************************************/
//
//
//                        С���㲥ģ�����ӿں�������
//
//
/******************************************************************************************************************/

//----------------------------------------------------------------------------------------------------------------
//
//  ��������         MMISMSCB_Init
//  ��������:        ��ʼ��С���㲥�ӿں���(���ֻ���ʼ��ʱ����, MMIMAIN.c �е���)
//  ȫ�ֱ���ʹ��:    ��
//  ����ֵ:          MN_RETURN_SUCCESS ��ʼ���ɹ���MN_RETURN_FAILURE ��ʼ��ʧ��
//  ����:            Ф��
//
//----------------------------------------------------------------------------------------------------------------
MN_RETURN_RESULT_E MMISMSCB_Init(MN_DUAL_SYS_E dual_sys);

/*****************************************************************************/
//     Description : open SMSCB main menu window      
//    Global resource dependence : 
//  Author: Tracy Zhang
//    Note: 
/*****************************************************************************/
void MMISMSCB_OpenMainMenu(void);

//----------------------------------------------------------------------------------------------------------------
//
//  ��������         MMISMSCB_SwitchSmsCBStatus
//  ��������:        �л�С���㲥����״̬
//  ȫ�ֱ���ʹ��:    ��
//  ����ֵ:          ��
//  ����:            Ф��
//
//----------------------------------------------------------------------------------------------------------------
void MMISMSCB_SwitchSmsCBStatus(
                                BOOLEAN cb_enabled      //Ҫ�л���״̬ (�������)
                                );

/*****************************************************************************/
//  Description : open SMSCB setting window      
//  Global resource dependence : 
//  Author: fengming.huang
//  Note: 
/*****************************************************************************/
void MMISMSCB_OpenSettingWin(void);

/**--------------------------------------------------------------------------*
 **                         Compiler Flag                                    *
 **--------------------------------------------------------------------------*/
#ifdef __cplusplus
    }
#endif

#endif
#endif //#if defined(MMI_SMSCB_SUPPORT)
