;--------------------------------------------------------------------------------------------------------------------------------------------------------------
; AutoUpdate.ini�ļ�˵��
;   1����AutoUpdate.exe�͸�ini�ļ�������ĳ�����ĸ�Ŀ¼��
;   2��Ŀǰ��ʵ�����������Ĺ��߰���EngineeringUtility��ArmTracer��DspTracer,RDAAudioCalibrator  
;   3����ini�ļ���Audio Calibrator ���ߵ����������ļ���
;   4���ֹ��������ļ��е�AudioCalibrator �滻����Ӧ���߼���ʵ��
;      EngineeringUtility��DspTracer���߻��������⹤�ߵ���������
;--------------------------------------------------------------------------- ---------------------------------------------------------------------------------

[SoftwareInfo] 

;��������                    
SoftName=ExportBSD

;����ִ���ļ���
SoftEntryPoint=ExportBSD.exe

;�����ڷ������ϵĸ�Ŀ¼
SoftRootDir=/tools/ExportBSD

;�����汾��Ϣ�����ļ�
SoftVerListConfigFile=SoftVerList.xml

;����������Ϣ�����ļ�
SoftUpdateConfigFile=Update.xml

;��������˵���ļ�
SoftReadme=readme.txt

;��ǰ���ص������汾����������
CurVer=V1.2.3
CurDate=2019-01-24


[WinControl]
;��־��ʹ�ܿ���
Output=0

;ʹ����������
EnableUpdate=1

;���°汾,�Ƿ񵯳�ȷ�ϴ���
TipWnd=1

;��������������ǰ�����������󵯳�����ȷ�ϴ���
BeforeSoftStart=0

;��������������ʽ,1:������������0���ӹ���������
StartMode=0

[ServerList]
;������̨����IP����
ServerNums=1
0=http://10.41.208.82
1=http://10.41.208.81





