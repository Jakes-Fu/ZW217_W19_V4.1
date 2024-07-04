/******************************************************************************
                                   ����WCDMA  ����ҵ��ģ��
        ����3G  ������𽥳��죬������ҵ�������Ϊ������
        �ƶ��ն˵����㣬�𽥳�Ϊ���ɻ�ȱ��һ���֡���
        ģ����ƻ���OMA  ��������Ļ���syncml Э������ݺ���
        �˹�����ʵ���ڶ�ƽ̨�������ϵͳ�е�PIMҵ��Ŀ��
        ��Ҫ�ﵽ����ƽ̨�Ŀ���ֲ�����õĹ����ȶ���ģ�顣
        ��ģ���ʵ�ַ�Ϊ��������:
        1.ʵ��Data sync����
        2.ʵ��Device Management����
        3.ʵ�ֶ�ƽ̨��ƽ����ֲ
        ģ�鿪���ο�OMA��Ա��ͬ������SRT_c��
        Ŀǰģ��ƻ�����֧��OMA syncML Э��1.1


        ��Ȩ����:��������Ȩ���ں���ͨ�ţ�����һ�з���Ȩ��
        ������Ա:����
        ��������:2005��4��11�ա�
******************************************************************************/


/******************************************************************************
�ļ�����:PIMCommobex.h
�ļ�����:OBEXͨѶ��ʽ��֧��
�ļ�˵��:�ṩOBEXͨѶ��ʽ�İ󶨣�ʵ����OBEX�µ�ͨѶ��
������Ա:����
�״ο�������:2005-7-9
******************************************************************************/


/******************************************************************************
                                                            �޸ļ�¼
  ����                   ����                �޸�ԭ��
  -----------------------------------------------------------------------------
  2004-7-9              ����                ��һ�ο������롣
  -----------------------------------------------------------------------------
  *****************************************************************************/
  /*�����FEATURE��ֹͷ�ļ��ظ�����*/
  #ifndef   HEADER_FILE_COMM_OBEX
  #define HEADER_FILE_COMM_OBEX

  /*  ����ͷ�ļ�*/
  #include "PIMComdef.h"
  #ifdef HS_FEATURE_COMM_OBEX_SUPPORT

  /*  ���ݽṹ����*/
  
  /*  ȫ�ֱ�������*/

  /*  ���ܺ�������*/

  /******************************************************************* 
  ** ������:HS_OBEX_Prepare
  ** ������������ʼ��WSP ������ݡ�
  ** ��  ��: ���ز���״̬
  ** ��  ��:����
  ** ��  ��:2005-11-14
  ** �汾: ver 1.0
  *******************************************************************/
  short  HS_OBEX_Prepare();

  /******************************************************************* 
  ** ������:HS_OBEX_Release
  ** �����������ͷ�OBEX �������.
  ** ��  ��: ���ز���״̬
  ** ��  ��:����
  ** ��  ��:2005-11-14
  ** �汾: ver 1.0
  *******************************************************************/
  short  HS_OBEX_Release();

  /******************************************************************* 
  ** ������:HS_OBEX_SendData
  ** �����������������ݡ�
  ** ��  ��: ���ز���״̬
  ** ��  ��:����
  ** ��  ��:2005-11-14
  ** �汾: ver 1.0
  *******************************************************************/
  short  HS_OBEX_SendData(short id,char* sendcache, uint32 sendlength, void*information);

  /******************************************************************* 
  ** ������:HS_OBEX_RecData
  ** �����������������ݡ�
  ** ��  ��: ���ز���״̬
  ** ��  ��:����
  ** ��  ��:2005-11-14
  ** �汾: ver 1.0
  *******************************************************************/
  short  HS_OBEX_RecData(short id,char* receivecache, uint32 recevielength, void*information, CPim* pMe);

  #endif

  #endif
