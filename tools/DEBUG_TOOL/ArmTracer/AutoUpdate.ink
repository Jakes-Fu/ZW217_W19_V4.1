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
SoftName=ArmTracer

;����ִ���ļ���
SoftEntryPoint=ArmTracer.exe

;�����ڷ������ϵĸ�Ŀ¼
SoftRootDir=/ArmTracer

;�����汾��Ϣ�����ļ�
SoftVerListConfigFile=SoftVerList.xml

;����������Ϣ�����ļ�
SoftUpdateConfigFile=Update.xml

;��������˵���ļ�
SoftReadme=readme.txt

;��ǰ���ص������汾����������
CurVer=V6.0.5
CurDate=2019-06-26


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

DelayToNext=4000

[ServerList]
;������̨����IP����
ServerNums=2
0=http://10.41.208.81
1=http://10.41.208.82


Server0=10.41.208.81
User0=hongyuntan
Pass0=969594949596

Server1=10.41.208.82
User1=hongyuntan
Pass1=cfde8991949f93929f9f9f





