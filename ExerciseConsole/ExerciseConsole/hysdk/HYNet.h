/************************************************************
  Copyright (C), 1988-1999, Haoyun Tech. Co., Ltd.
  FileName: HYNet.h  
  Author:        Version :          Date:
  ��˫ȫ         1.0                11-04-09
  Description:     ��¼��־     
  Version:         1.0
  Function List:   // ��Ҫ�������书��
    1. -------
  History:         // ��ʷ�޸ļ�¼
      <author>  <time>   <version >   <desc>
      Lsq       11/04/09 1.0          build this moudle 
***********************************************************/

#ifndef _HY_NET_
#define _HY_NET_

#ifndef HY_ERROR
#define HY_ERROR

enum{
	E_OK = 0,               //�ɹ�
	E_UNKNOWN,              //δ֪����
	E_SDK_BASE = 100,       //sdk���������ʼ��
	E_NOABILITY,            //��������
	E_ALREADYEXIST,         //�Ѿ�����
	E_CREATESOCKET,         //����socketʧ��
	E_SOCKETFAILED,         //socket����
	E_NORESPONSE,           //û��Ӧ��
	E_MALLOCMEM,            //�ڴ����ʧ��
	E_NOTFIND,              //�Ҳ�����Ӧ���豸
	E_INIT,                 //û�г�ʼ���ò���
	E_PARAM,                //��������
	E_RELOG,                //�豸����
	E_INVALIDSOCKET,        //��Чsocket���
	E_PORTINUSE,            //�˿ڱ�ռ��
	E_UNSUPPORT_RESOLUTION, //��֧�ֵķֱ���
	E_NOT_OPEN,             //�򿪲����ļ�
	E_SOCKET_TIMEOUT,       //socket��ʱ
	E_SYSTEM_BUSY,			//ϵͳæ

	E_DEV_BASE = 1000,      //�豸��ʼ��
    E_STARTCODE,            //��ʼ�����
    E_ALREADY_LOGIN,        //�ѵ�¼
    E_LOGIN_FAIL,           //��¼ʧ��
    E_VERSION,              //�汾������
    E_SEQ,                  //��������
    E_MEM,                  //�ڴ����ʧ��
    E_AUTH,                 //Ȩ�޲���
    E_VIDEOFULL,            //��Ƶ����ͻ���������
    E_THREADCREAT,          //�̴߳���ʧ��
    E_ADMIN_NOT_DELETED,    //admin����ɾ��
    E_MULOPEN,              //��δ���Ƶ
    E_FAULT_VAL,            //��ֵ������Χ	
	E_RESOL_WRONG,          //�����ֱ��ʲ�֧��
    E_BIG_LOGNUM,           //������־��̫�����50��
	E_NOTREADY,             //�ɼ����������δ����
	E_NO_VIDEO_CLOSE,       //û�пɹرյ���Ƶ
	E_NO_OSD_DATA,          //û��OSD�������ݷ��͹���
	E_BUSY,                 //ϵͳ��æ�ڴ����ϴ�ͬ����ָ��
	E_PASSWD,               //�������
	E_NOTFOUND,             //�û���������
	E_WRONG_IMG_TYPE,		//�����ļ��������Ͳ����� 
	E_ERASEFLASH,			//��flash�� 
	E_WRITEFLASH,			//дflash�� 
	E_CRC,					//CRCУ��� 
	E_AUDIOFULL,			//ͬʱ������������ 
	E_NO_LISTENER_STOP,		//û�п�ֹͣ�ļ��� 
	E_NOSPACE,				//û�ж���ռ������û� 
	E_NAMERR,				//���Ǳ��豸�������ļ�
	E_UNSUPPORT,			//�Ƿ�����
	E_NO_LOGIN,				//�ƹ���¼����
    E_NO_FILE_FOUND,		//���������ļ�
    E_SEARCHING,			//���ڼ���
    E_SEARCH_OVER,			//��������
    E_SEARCH_FAIL,			//��������
	E_LOGIN_USER_FULL,		//��¼�û�������
	E_INVALID_UPDATE_FILE,	//�Ƿ������ļ� 
	E_UNSUPPORT_FUNC,		//���ܲ�֧�� 
	E_NO_LOG_FOUND,			//û����־
	E_UPDATE_FILE_TOO_BIG,	//�����ļ������޷�����
};

#endif

#ifndef HY_PUBLIC
#define HY_PUBLIC

//Frame Info
typedef struct{
	int nType;									//��������
	UINT nStamp;							//ʱ���
	int nWidth;								//�������λ������
	int nHeight;								//����ߣ���λ������		
	int nFrameRate;						//֡��
	BYTE byRes1[8];						//�����ֽ�
	int nChannels;							//������
	int nBitPerSample;					//����λ��
	int nSamplesPerSec;				//����Ƶ��
	BYTE byRes2[8];						//�����ֽ�
}HY_FRAME_INFO;

//������������
enum{
	FRAME_AUDIO	= 0,       //��������
	FRAME_HEADER,	       //����ͷ
	FRAME_VIDEO_I,	       //��ƵI֡
	FRAME_VIDEO_P,	       //��ƵP֡
	FRAME_VIDEO_B,	       //��ƵB֡
	NO_VIDEO		       //����������
};

//��������ݵ�֡����
#define FRAME_TYPE_YUV420 0
#define FRAME_TYPE_AUDIO 100

#endif

enum{CONFIG_BASE = 0x0000, CONFIG_REQ_BASE = 0x1000, CTL_BASE = 0x2000, ALARM_BASE = 0x3000};

enum{DEVICE_PARAM = CONFIG_BASE | 0x1, OSD_PARAM, SOUND_PARAM, VIDEO_PARAM, MOTION_DETECT_PARAM, DETECTOR_PARAM, 
     NETWORK_ALARM_PARAM, NETWORK_CONFIG_PARAM, WIRELESS_CONFIG_PARAM, DDNS_CONFIG_PARAM, PPPOE_CONFIG_PARAM,
     SHADE_ALARM_PARAM, USER_CONFIG_PARAM, ALARMCENTER_CONFIG_PARAM, TIME_PARAM};

enum{DEVICE_REQ = CONFIG_REQ_BASE | 0x1, OSD_REQ, SOUND_REQ, VIDEO_REQ, MOTION_DETECT_REQ, DETECTOR_REQ, 
     NETWORK_ALARM_REQ, NETWORK_CONFIG_REQ, WIRELESS_CONFIG_REQ, DDNS_CONFIG_REQ, PPPOE_CONFIG_REQ, SHADE_ALARM_REQ,
     USER_CONFIG_REQ, ALARMCENTER_CONFIG_REQ, USER_LOG_REQ, ALARM_LOG_REQ, TIME_REQ, VER_REQ};

enum{RESTORE_DEF = CTL_BASE | 0x3, REBOOT, SHUTDOWN, LENS_CTL, POSITION_CTL, IMG_ADJUST, LENS_ADJUST, 
     DETECTOR_ALARM_START = CTL_BASE | 0xD, DETECTOR_ALARM_STOP, MOTION_DETECT_START, MOTION_DETECT_STOP, 
	 NETWORK_ALARM_START, NETWORK_ALARM_STOP, USER_DEL, SHADE_ALARM_START = CTL_BASE | 0x16, SHADE_ALARM_STOP, 
	 PTZ_CTL = CTL_BASE | 0x1A};

enum{SYS_ALARM = ALARM_BASE | 0x1, DEV_ALARM, SOUND_ALARM, VIDEO_ALARM, MOTION_ALARM, DETECTOR_ALARM};
//enum{FRAME_AUDIO, FRAME_HEADER, FRAME_VIDEO_I, FRAME_VIDEO_P, FRAME_VIDEO_B};

#define MAX_USER			20			//�豸֧�ֵ�����û���
#define MAX_CHAN_NUM		64			//���ͨ����
#define MAX_STREAM_NUM		2			//�����������,����������
#define MAX_DISKNUM			35			//���Ӳ����

//��������
#define CONFIG_SYS_DEVICE			(CONFIG_BASE | 0x1)		//�豸��������
#define CONFIG_OSD					(CONFIG_BASE | 0x2)		//OSD��������
#define CONFIG_SOUND				(CONFIG_BASE | 0x3)		//��Ƶ��������
#define CONFIG_VEDIO				(CONFIG_BASE | 0x4)		//��Ƶ��������
#define CONFIG_ALARM_MOVE			(CONFIG_BASE | 0x5)		//�ƶ���ⱨ������
#define CONFIG_ALARM_PROBE			(CONFIG_BASE | 0x6)		//̽ͷ��������
#define CONFIG_ALARM_NET			(CONFIG_BASE | 0x7)		//������ϱ�������
#define CONFIG_NETWORK				(CONFIG_BASE | 0x8)		//�����������
#define CONFIG_WIRELESS				(CONFIG_BASE | 0x9)		//���������������
#define CONFIG_DDNS					(CONFIG_BASE | 0xA)		//DDNS��������
#define CONFIG_PPPOE				(CONFIG_BASE | 0xB)		//PPPOE��������
#define CONFIG_BLOCK				(CONFIG_BASE | 0xC)		//�ڵ���������
#define CONFIG_USER					(CONFIG_BASE | 0xD)		//�û���������
#define CONFIG_ALARM_CENTER			(CONFIG_BASE | 0xE)		//������������
#define CONFIG_SYS_TIME				(CONFIG_BASE | 0xF)		//ϵͳʱ������
//									(CONFIG_BASE | 0x10)
#define CONFIG_LOW_LIGHT			(CONFIG_BASE | 0x11)	//���ն�����
#define CONFIG_BACK_LIGHT			(CONFIG_BASE | 0x12)	//���ⲹ������
#define CONFIG_VIDEO_EX				(CONFIG_BASE | 0x13)	//��̬����
#define CONFIG_IMAGE_EX				(CONFIG_BASE | 0x14)	//ͼ����չ
#define CONFIG_SCENE				(CONFIG_BASE | 0x15)	//ͼ�񳡾�
#define CONFIG_NETWORK_EX			(CONFIG_BASE | 0x16)	//�����������(��չ)
#define CONFIG_IR_EXPOSURE_PROTECT	(CONFIG_BASE | 0x17)	//���ú��������
#define CONFIG_IMAGE				(CONFIG_BASE | 0x18)	//����ͼ��Ч��(ע��ԭ��CONTROL_IMAGE)
#define CONFIG_CHANNEL_NAME			(CONFIG_BASE | 0x19)	//����ͨ������
#define CONFIG_SYS_TIME_EX			(CONFIG_BASE | 0x1A)	//ϵͳʱ������(��չ)
#define CONFIG_VIDEO_ENC_INFO		(CONFIG_BASE | 0x1B)	//��Ƶ�����������
#define CONFIG_HIDE_AREAS			(CONFIG_BASE | 0x1C)	//��Ƶ�ڸ���������
#define CONFIG_RECORD_STATE			(CONFIG_BASE | 0x1D)	//�ֶ�����¼��״̬
#define	CONFIG_IO_ALARMOUT_STATE	(CONFIG_BASE | 0x1E)	//����IO�������
#define CONFIG_FACE_AREAS			(CONFIG_BASE | 0x1F)	//����������������
#define CONFIG_FACE_EFFECT			(CONFIG_BASE | 0x20)	//��������Ч��
#define	CONFIG_CASH_READER_TYPE				(CONFIG_BASE | 0x21)	//���õ�ǰ�㳮���ͺ�
#define	CONFIG_CARD_READER_BAUDRATE			(CONFIG_BASE | 0x22)	//����ˢ����������
#define	CONFIG_CHAR_OVERLAY_CFG				(CONFIG_BASE | 0x23)	//�����ַ�������ʾ����
#define	CONFIG_VGA_CFG						(CONFIG_BASE | 0x24)	//����VGA����
#define	CONFIG_ALARMIN_CFG					(CONFIG_BASE | 0x25)	//����IO�����������

//��ȡ����
#define REQUEST_SYS_DEVICE			(CONFIG_REQ_BASE | 0x1)		//�豸��������
#define	REQUEST_OSD					(CONFIG_REQ_BASE | 0x2)		//OSD��������
#define	REQUEST_SOND				(CONFIG_REQ_BASE | 0x3)		//������������
#define	REQUEST_VIDEO				(CONFIG_REQ_BASE | 0x4)		//��Ƶ��������
#define	REQUEST_MOVING_ALARM		(CONFIG_REQ_BASE | 0x5)		//�ƶ���ⱨ����������
#define	REQUEST_GROPING_ALARM		(CONFIG_REQ_BASE | 0x6)		//̽ͷ������������
#define	REQUEST_NET_ALARM			(CONFIG_REQ_BASE | 0x7)		//������ϱ�����������
#define	REQUEST_NETWORK				(CONFIG_REQ_BASE | 0x8)		//�����������
#define	REQUEST_WIRELESS			(CONFIG_REQ_BASE | 0x9)		//���߲�������
#define	REQUEST_DDNS				(CONFIG_REQ_BASE | 0xA)		//DDNS��������
#define	REQUEST_PPPOE				(CONFIG_REQ_BASE | 0xB)		//PPPOE��������
#define	REQUEST_BLOCK				(CONFIG_REQ_BASE | 0xC)		//�ڵ���������
#define	REQUEST_USER				(CONFIG_REQ_BASE | 0xD)		//�û���������
#define	REQUEST_ALARM_CENTER		(CONFIG_REQ_BASE | 0xE)		//������������
#define	REQUEST_USERS_LOG			(CONFIG_REQ_BASE | 0xF)		//�û���־����
#define	REQUEST_ALARM_LOG			(CONFIG_REQ_BASE | 0x10)	//������־����
#define	REQUEST_SYS_TIME			(CONFIG_REQ_BASE | 0x11)	//ϵͳʱ������
#define	REQUEST_SYS_VERSION			(CONFIG_REQ_BASE | 0x12)	//ϵͳ�汾����
#define	REQUEST_IMAGE				(CONFIG_REQ_BASE | 0x13)	//ͼ��Ч������
//									(CONFIG_REQ_BASE | 0x14)
#define	REQUEST_LOW_LIGHT			(CONFIG_REQ_BASE | 0x15)	//���ն�����
#define	REQUEST_BACK_LIGHT			(CONFIG_REQ_BASE | 0x16)	//���ⲹ������
#define	REQUEST_VIDEO_EX			(CONFIG_REQ_BASE | 0x17)	//��̬����
#define	REQUEST_IMAGE_EX			(CONFIG_REQ_BASE | 0x18)	//ͼ��Ч����չ����
#define	REQUEST_SCENE				(CONFIG_REQ_BASE | 0x19)	//ͼ�񳡾�����
#define REQUEST_CHANS_INFO			(CONFIG_REQ_BASE | 0x1A)	//��ȡͨ����Ϣ
#define REQUEST_SCENE_SUPPORT		(CONFIG_REQ_BASE | 0x1B)	//��ȡ����֧�ָ�������
#define REQUEST_RESOLUTION_SUPPORT	(CONFIG_REQ_BASE | 0x1C)	//�ֱ���֧����������
#define	REQUEST_NETWORK_EX			(CONFIG_REQ_BASE | 0x1D)	//�����������(��չ)
#define REQUEST_IR_EXPOSURE_PROTECT	(CONFIG_REQ_BASE | 0x1E)	//��ȡ�������������
#define	REQUEST_DISK_INFO			(CONFIG_REQ_BASE | 0x1F)	//��ȡӲ����Ϣ
#define REQUEST_SYS_TIME_EX			(CONFIG_REQ_BASE | 0x20)	//ϵͳʱ������(��չ)
#define REQUEST_RECORD_STATUS		(CONFIG_REQ_BASE | 0x21)	//¼��״̬����
#define	REQUEST_VIDEO_ENC_INFO		(CONFIG_REQ_BASE | 0x22)	//��Ƶ�����������
#define	REQUEST_PTZ_PRESET			(CONFIG_REQ_BASE | 0x23)	//Ԥ�õ��ѯ
#define	REQUEST_HIDE_AREAS			(CONFIG_REQ_BASE | 0x24)	//��Ƶ�ڸ���������
#define	REQUEST_IO_ALARMIN_STATE	(CONFIG_REQ_BASE | 0x25)	//IO��������״̬
#define	REQUEST_IO_ALARMOUT_STATE	(CONFIG_REQ_BASE | 0x26)	//IO�������״̬
#define	REQUEST_FACE_AREAS			(CONFIG_REQ_BASE | 0x27)	//��ȡ������������
#define	REQUEST_FACE_EFFECT			(CONFIG_REQ_BASE | 0x28)	//��ȡ��������Ч��
#define	REQUEST_CASH_READER_TYPE				(CONFIG_REQ_BASE | 0x29)	//��ȡ��ǰ�㳮���ͺ�
#define	REQUEST_CARD_READER_BAUDRATE			(CONFIG_REQ_BASE | 0x2A)	//��ȡˢ����������
#define	REQUEST_CHAR_OVERLAY_CFG				(CONFIG_REQ_BASE | 0x2B)	//��ȡ�ַ�������ʾ����
#define	REQUEST_CASH_READER_TYPE_LIST			(CONFIG_REQ_BASE | 0x2C)	//��ȡ�㳮���ͺ�֧���б�
#define	REQUEST_VGA_CFG							(CONFIG_REQ_BASE | 0x2D)	//��ȡVGA����
#define	REQUEST_ALARMIN_CFG						(CONFIG_REQ_BASE | 0x2E)	//��ȡIO�����������


//�ؼ�����
#define CONTROL_LOGIN							(CTL_BASE | 0x1)	//�û���¼
#define CONTROL_LOGOUT							(CTL_BASE | 0x2)	//�û��˳�
#define CONTROL_RECOVER							(CTL_BASE | 0x3)	//�ָ���������
#define CONTROL_REBOOT							(CTL_BASE | 0x4)	//�����豸
#define CONTROL_SHUTDOWN						(CTL_BASE | 0x5)	//�ر��豸
#define CONTROL_LENS_CONTROL					(CTL_BASE | 0x6)	//��ͷ����
#define CONTROL_OSD_POSITION					(CTL_BASE | 0x7)	//osdλ�õ���
#define CONTROL_IMAGE							(CTL_BASE | 0x8)	//ͼ��
#define CONTROL_LENS_ADJUST						(CTL_BASE | 0x9)	//��ͷ����
#define CONTROL_OPEN_VIDOE						(CTL_BASE | 0xA)	//����Ƶ
#define CONTROL_CLOSE_VIDOE						(CTL_BASE | 0xB)	//�ر���Ƶ
#define CONTROL_GET_IFRAME						(CTL_BASE | 0xC)	//��ȡI֡
#define CONTROL_GROPING_ALARM_ENABLE			(CTL_BASE | 0xD)	//����̽ͷ����
#define CONTROL_GROPING_ALARM_UNENABLE			(CTL_BASE | 0xE)	//�ر�̽ͷ����
#define CONTROL_MOVING_ALARM_ENABLE				(CTL_BASE | 0xF)	//�����ƶ���ⱨ��
#define CONTROL_MOVING_ALARM_UNENABLE			(CTL_BASE | 0x10)	//�ر��ƶ���ⱨ��
#define CONTROL_NET_ALARM_ENABLE				(CTL_BASE | 0x11)	//��������ϱ���
#define CONTROL_NET_ALARM_UNENABLE				(CTL_BASE | 0x12)	//�ر�������ϱ���
#define CONTROL_DEL_USER						(CTL_BASE | 0x13)	//ɾ���û�
#define CONTROL_UNLOCK_PANNEL					(CTL_BASE | 0x14)	//�������
#define CONTROL_HEARTBEAT						(CTL_BASE | 0x15)	//����
#define CONTROL_BLOCKALARM_OPEN					(CTL_BASE | 0x16)	//�����ڵ�����
#define CONTROL_BLOCKALARM_CLOSE				(CTL_BASE | 0x17)	//�ر��ڵ�����
#define CONTROL_UPDATE							(CTL_BASE | 0x18)	//����(���;����ļ�ͷ)
#define CONTROL_SEND_FILE						(CTL_BASE | 0x19)	//�����ļ�(���;����ļ�����)
#define CONTROL_PTZ								(CTL_BASE | 0x1A)	//��̨����
#define CONTROL_SND_MATRIX_HEAD					(CTL_BASE | 0x1B)	//���͵�������ͷ
#define CONTROL_SND_MATRIX_DATA					(CTL_BASE | 0x1C)	//���͵�������
#define CONTROL_CAP_RAW							(CTL_BASE | 0x1D)	//ץ�Ĳɼ�ͼƬ
#define CONTROL_BEGIN_LISTEN					(CTL_BASE | 0x1E)	//��������
#define CONTROL_STOP_LISTEN						(CTL_BASE | 0x1F)	//ֹͣ����
#define CONTROL_RESET_SCENE						(CTL_BASE | 0x20)	//��λָ������������
#define CONTROL_DEV_CHECK_A						(CTL_BASE | 0x21)	//�豸���Aģʽ
#define CONTROL_DEV_CHECK_B						(CTL_BASE | 0x22)	//�豸���Bģʽ
#define CONTROL_REMOTE_FIND_FILE				(CTL_BASE | 0x23)	//�����豸¼���ļ�
#define CONTROL_REMOTE_FIND_NEXT_FILE			(CTL_BASE | 0x24)	//�����ȡ���ҵ����ļ���Ϣ
#define CONTROL_REMOTE_FIND_CLOSE				(CTL_BASE | 0x25)	//�ر��ļ����ң��ͷ���Դ
#define CONTROL_REMOTE_PLAY_BACK_OPEN			(CTL_BASE | 0x26)	//��Զ�̻ط�
#define CONTROL_REMOTE_PLAY_BACK_CONTROL		(CTL_BASE | 0x27)	//Զ�̻طſ���
#define CONTROL_REMOTE_PLAY_BACK_CLOSE			(CTL_BASE | 0x28)	//�ر�Զ�̻ط�
#define CONTROL_DETECT_TIMEOUT					(CTL_BASE | 0x29)	//���socket�Ƿ�ʱ
#define CONTROL_PTZ_PRESET						(CTL_BASE | 0x2A)	//��̨Ԥ�õ����
#define CONTROL_SNAPSHOT						(CTL_BASE | 0x2B)	//ץͼ(��Ԥ��)
#define CONTROL_FIND_LOG						(CTL_BASE | 0x2C)	//�����豸��־
#define CONTROL_FIND_NEXT_LOG					(CTL_BASE | 0x2D)	//������ȡ���ҵ�����־��Ϣ
#define CONTROL_FIND_LOG_CLOSE					(CTL_BASE | 0x2E)	//�ر���־���ң��ͷ���Դ
#define CONTROL_VOICE_COMM_START				(CTL_BASE | 0x2F)	//�����Խ�����
#define CONTROL_VOICE_COMM_STOP					(CTL_BASE | 0x30)	//�����Խ�ֹͣ
#define CONTROL_RESET_FACE_EFFECT				(CTL_BASE | 0x31)	//�ָ�����Ч��Ĭ��ֵ

#define CONTROL_REMOTE_GET_FILE					(CTL_BASE | 0xFFF)	//����Զ��¼���ļ�


#define APERTURE_LOVER		1	//�����Զ���Ȧ��ƽ
#define APERTURE_LIFT		0   //�����Զ���Ȧ��ƽ
#define	LENS_FOCUS			0   //����
#define	LENS_APERTURE		1   //��Ȧ
#define	LENS_LIGHT			2   //�ƹ�
#define	LENS_WIPER			3   //���


#define	ALARM_PROBE_OPEN			0   //̽ͷ�澯��
#define	ALARM_PROBE_CLOSE			1   //̽ͷ�澯�ر�
#define ALARM_MOVE_OPEN				2   //�ƶ��澯��
#define ALARM_MOVE_CLOSE			3   //�ƶ��澯�ر�
#define ALARM_NET_OPEN				4   //����澯��
#define ALARM_NET_CLOSE				5   //����澯�ر�
#define SYSTEM_RESET				0   //ϵͳ��������
#define SYSTEM_REBOOT				1   //ϵͳ����
#define SYSTEM_SHUT					2  	//ϵͳ����

//OSD����
#define OSD_TYPE_DATE				0  	//����ʱ��
#define OSD_TYPE_USER				1  	//�Զ����ַ���

#define STATUS_CLOSE				0  	//�ر��豸
#define STATUE_OPEN					1  	//���豸

#define OSD_LEFT					1  	//osd����
#define OSD_RIGHT					2  	//osd����
#define OSD_UP						3  	//osd����
#define OSD_DOWN					4  	//osd����

//ϵͳ��Ϣ����
#define SYSTEMINFO_YEAR_BITS_BEGIN				0
#define SYSTEMINFO_YEAR_BITS_LAST				23
#define SYSTEMINFO_MONTH_BITS_BEGIN				23
#define SYSTEMINFO_MONTH_BITS_LAST				4
#define SYSTEMINFO_DAY_BITS_BEGIN				27
#define SYSTEMINFO_DAY_BITS_LAST				5
#define SYSTEMINFO_HOUR_BITS_BEGIN				12
#define SYSTEMINFO_HOUR_BITS_LAST				5
#define SYSTEMINFO_MINUTE_BITS_BEGIN			6
#define SYSTEMINFO_MINUTE_BITS_LAST				6
#define SYSTEMINFO_SECOND_BITS_BEGIN			0
#define SYSTEMINFO_SECOND_BITS_LAST				6

//�������볣��
#define	SOUND_SAMPLING_RATE_BEGIN				4 //�����ʵڣ�λ��ʼ
#define	SOUND_SAMPLING_RATE_LAST				4 //������ռ4λ
#define	SAMPLING_RATE_8K						0 //������Ϊ8k
#define	SAMPLING_RATE_32K						1 //������Ϊ32k
#define SOUND_COMPRESSION_FORMAT_BEGIN			0 // ѹ����ʽ��0λ��ʼ
#define	SOUND_COMPRESSION_FORMAT_LAST			4 //ѹ����ʽռ4λ
#define COMPRESSION_FORMAT_G726					0 //ѹ����ʽΪG726
#define COMPRESSION_FORMAT_G711A				1 //ѹ����ʽΪG711A
#define COMPRESSION_FORMAT_G711U				2 //ѹ����ʽΪG711U
#define SOUND_SWITCH_BEGIN						1 //�������ص�1λ��ʼ
#define SOUND_SWITCH_LAST						1 //��������ռ1λ
#define SOUND_INPUT_TYPE_BEGIN					0 //�������뷽ʽ��0λ��ʼ
#define SOUND_INPUT_TYPE_LAST					1 //�������뷽ʽռ1λ
#define SOUND_INPUT_TYPE_MICROPHONE				0 //��˷�����
#define SOUND_INPUT_TYPE_CIRCUIT				1 //��·����
#define SOUND_INPUT_VOLUME_BEGIN				4 //����������4λ��ʼ
#define SOUND_INPUT_VOLUME_LAST					4 //��������ռ4λ
#define SOUND_OUTPUT_VOLUME_BEGIN				0 //���������0λ��ʼ
#define SOUND_OUTPUT_VOLUME_LAST				4 //�������ռ4λ

//��������
#define	STREAM_VIDEO_EFFECTS_BEST				0 //��ƵЧ�����
#define STREAM_VIDEO_EFFECTS_GOOD				1 //��ƵЧ����
#define STREAM_VIDEO_EFFECTS_COMMON				2 //��ƵЧ��һ��
#define STREAM_CONTROL_BITS_BEGIN				4 //��������λ�ӵ�4λ��ʼ
#define STREAM_CONTROL_BITS_LAST				4 //��������λռ4λ
#define STREAM_IMAGE_EFFECTS_BEGIN				0 //ͼ��Ч���ӵ�0λ��ʼ
#define STREAM_IMAGE_EFFECTS_LAST				4 //ͼ��Ч��ռ4λ
#define STREAM_CONTROL_VARIABLE					0 //�����ɱ�
#define STREAM_CONTROL_FIXED					1 //�����̶�

enum{
	RESOLUTION_MIN_VAL = 0,	//�ֱ�����Сֵ
	RESOLUTION_DCIF = 0,	//DCIF�ֱ��� ע��DCIF�滻ԭQCIF
	RESOLUTION_CIF,			//CIF�ֱ���
	RESOLUTION_VGA,			//VGA
	RESOLUTION_D1,			//D1
	RESOLUTION_SVGA,		//SVGA
	RESOLUTION_720P,		//720p
	RESOLUTION_960P,		//960p
	RESOLUTION_1080P,		//1080p
	RESOLUTION_1200P,		//1200p
	RESOLUTION_2048_1536,	//2048*1536 
	RESOLUTION_2560_1920,	//2560*1920
	RESOLUTION_2304_1296,	//2304*1296
	RESOLUTION_ADAPTATION,	//����Ӧ
	RESOLUTION_MAX_VAL,	//�ֱ������ֵ
};

//��Ƶ����
#define  VIDEO_FONT_COLOR_BITS_BEGIN		4	//������ɫ�ӵ�4λ��ʼ
#define  VIDEO_FONT_COLOR_BITS_LAST			4	//������ɫռ4λ
#define  VIDEO_FONT_COLOR_WHITE				0	//������ɫ��ɫ
#define  VIDEO_FONT_COLOR_BLACK				1	//������ɫ��ɫ
#define  VIDEO_FONT_COLOR_YELLOW			2	//������ɫ��ɫ
#define  VIDEO_FONT_COLOR_RED				3	//������ɫ��ɫ
#define  VIDEO_FONT_COLOR_BLUE				4	//������ɫ��ɫ
#define  VIDEO_DATE_FORMAT_BITS_BEGIN		0	//���ڸ�ʽ�ӵ�0λ��ʼ
#define  VIDEO_DATE_FORMAT_BITS_LAST		4	//���ڸ�ʽռ4λ
#define  VIDEO_DATE_FORMAT_YYYY_MM_DD		0
#define  VIDEO_DATE_FORMAT_MM_DD_YYYY		1
#define  VIDEO_DATE_FORMAT_DD_MM_YYYY		2
#define  VIDEO_LEN_BITS_BEGIN				7	//�ƹ�ӵ�7λ��ʼ
#define  VIDEO_LEN_BITS_LAST				1	//�ƹ�ռ1λ
#define  VIDEO_MIRROR_BITS_BEGIN			6	//����ӵ�6λ��ʼ
#define  VIDEO_MIRROR_BITS_LAST				1	//����ռ1λ
#define  VIDEO_TRUN_BITS_BEGIN				5	//����ת�ӵ�5λ��ʼ
#define  VIDEO_TRUN_BITS_LAST				1	//����תռ1λ
#define  VIDEO_SHIELDING_BITS_BEGIN			4	//��Ƶ���δӵ�4λ��ʼ
#define  VIDEO_SHIELDING_BITS_LAST			1	//��Ƶ����ռ1λ
#define  VIDEO_LEN_50HZ						0	//�ƹ�50HZ
#define  VIDEO_LEN_60HZ						1	//�ƹ�60HZ
#define  STREAM_MAIN						0	//������
#define  STREAM_SECOND						1	//������

//ʱ�䳣��
#define  TIME_OPEN_BITS_BEGIN         0
#define  TIME_OPEN_BITS_LAST          1
#define  TIME_SECTION_SIZE            4
#define  TIME_HOUR_BITS_BEGIN         11 //Сʱ��11λ��ʼ
#define  TIME_HOUR_BITS_LAST          6  //Сʱռ6λ
#define  TIME_MINUTE_BITS_BEGIN       5  //���Ӵ�5λ��ʼ
#define  TIME_MINUTE_BITS_LAST        6  //����ռ6λ
#define  TIME_SECOND_BITS_BEGIN       0  //��ӵ�0λ��ʼ
#define  TIME_SECOND_BITS_LAST        5  //��ռ5λ

//�ƶ���������
#define  MOVECHECK_LINK_VIDEO_BITS_BEGIN		0  //����¼�񱨾���0λ��ʼ
#define  MOVECHECK_LINK_VIDEO_BITS_LAST			1  //����¼��ռ1λ
#define  MOVECHECK_LINK_CAPTURE_BITS_BEGIN		1  //����ץ�Ĵ�1λ��ʼ
#define  MOVECHECK_LINK_CAPTURE_BITS_LAST		1  //����ץ��ռ1λ
#define  MOVECHECK_LINK_OUTPUT_BITS_BEGIN		2  //���������2λ��ʼ
#define  MOVECHECK_LINK_OUTPUT_BITS_LAST		1  //�������ռ1λ
#define  MOVECHECK_SWITCH_BITS_BEGIN			0  //��⿪�ش�0λ��ʼ
#define  MOVECHECK_SWITCH_BITS_LAST				1  //��⿪��ռ1λ
#define  MOVECHECK_SENSITIVITY_BITS_BEGIN		1  //�����ȴ�1λ��ʼ
#define  MOVECHECK_SENSITIVITY_BITS_LAST		3  //������ռ3λ
#define  MOVECHECK_MOVE_AREA_BITS_BEGIN			4  //�ƶ�����ӵ�4λ��ʼ
#define  MOVECHECK_MOVE_AREA_BITS_LAST			2  //�ƶ�����ռ2λ
#define  MOVECHECK_MOVE_AREA_PART				0  //��������
#define  MOVECHECK_MOVE_AREA_ALL				1  //ȫ������
#define  MOVECHECK_MOVE_AREA_CLEAR				2  //�������

//̽ͷ��������
#define  WARNCHECK_LINK_VIDEO_BITS_BEGIN		0  //����¼�񱨾���0λ��ʼ
#define  WARNCHECK_LINK_VIDEO_BITS_LAST			1  //����¼��ռ1λ
#define  WARNCHECK_LINK_CAPTURE_BITS_BEGIN		1  //����ץ�Ĵ�1λ��ʼ
#define  WARNCHECK_LINK_CAPTURE_BITS_LAST		1  //����ץ��ռ1λ
#define  WARNCHECK_LINK_OUTPUT_BITS_BEGIN		2  //���������2λ��ʼ
#define  WARNCHECK_LINK_OUTPUT_BITS_LAST		1  //�������ռ1λ
#define  WARNCHECK_SWITCH_BITS_BEGIN			0  //��⿪�ش�0λ��ʼ
#define  WARNCHECK_SWITCH_BITS_LAST				1  //��⿪��ռ1λ
#define  WARNCHECK_SWITCH_TYPE_BITS_BEGIN		1  //̽ͷ���ʹ�1λ��ʼ
#define  WARNCHECK_SWITCH_TYPE_BITS_LAST		1  //̽ͷ����ռ1λ
#define  WARN_TYPE_ALWAYS_CLOSE					0  //����̽ͷ
#define  WARN_TYPE_ALWAYS_OPEN					1  //����̽ͷ

//������ϳ���
#define  NETWORKCHECK_LINK_VIDEO_BITS_BEGIN       0   //����¼�񱨾���0λ��ʼ
#define  NETWORKCHECK_LINK_VIDEO_BITS_LAST        1   //����¼��ռ1λ
#define  NETWORKCHECK_LINK_CAPTURE_BITS_BEGIN     1   //����ץ�Ĵ�1λ��ʼ
#define  NETWORKCHECK_LINK_CAPTURE_BITS_LAST      1   //����ץ��ռ1λ
#define  NETWORKCHECK_LINK_OUTPUT_BITS_BEGIN      2   //���������2λ��ʼ
#define  NETWORKCHECK_LINK_OUTPUT_BITS_LAST       1   //�������ռ1λ
#define  NETWORKCHECK_SWITCH_BITS_BEGIN           0   //��⿪�ش�0λ��ʼ
#define  NETWORKCHECK_SWITCH_BITS_LAST            1   //��⿪��ռ1λ

//�������糣��
#define  WANLESS_ENCRYPT_BITS_BEGIN               4   //����λ�ӵ�4λ��ʼ
#define  WANLESS_ENCRYPT_BITS_LAST                2   //����λռ2λ
#define  WANLESS_BAND_BITS_BEGIN                  2   //Ƶ��λ�ӵ�2λ��ʼ
#define  WANLESS_BAND_BITS_LAST                   2   //Ƶ��λռ2λ
#define  WANLESS_MODE_BITS_BEGIN                  0   //ģʽλ�ӵ�2λ��ʼ
#define  WANLESS_MODE_BITS_LAST                   2   //ģʽλռ2λ

//�û�������
enum{
  USER_PERMISSION_ADMIN	= 0,   //����Ա
  USER_PERMISSION_CONTROL,	   //�����˺�
  USER_PERMISSION_PREVIEW		//Ԥ���˺�
};

//�������ĳ���
#define  ALARM_TYPE_HEARTBEAT                     0x2015 //�յ�����Ϊ��������
#define  ALARM_TYPE_BASE                          0x3000 //�������Ϳ�ʼ
#define  NOTIFY_EVENT_TYPE_BASE                   0x3300 //NVR�������Ϳ�ʼ
#define  ALARM_SYSTEM                             (ALARM_TYPE_BASE | 0x1) //ϵͳ����
#define  ALARM_DEVICE                             (ALARM_TYPE_BASE | 0x2) //�豸����
#define  ALARM_SOUND                              (ALARM_TYPE_BASE | 0x3) //��Ƶ����
#define  ALARM_VIDEO                              (ALARM_TYPE_BASE | 0x4) //��Ƶ����
#define  ALARM_MOVE                               (ALARM_TYPE_BASE | 0x5) //�ƶ�����
#define  ALARM_WARN                               (ALARM_TYPE_BASE | 0x6) //̽ͷ����
#define  ALARM_MEDIA_LOSE                         (ALARM_TYPE_BASE | 0x7) //������Ƶ��ʧ����
//#define  ALARM_BLACK                              (ALARM_TYPE_BASE | 0x7) //��������
#define  ALARM_BLOCK                              (ALARM_TYPE_BASE | 0x8) //�ڵ�����
#define  ALARM_UPDATE                             (ALARM_TYPE_BASE | 0x9) //�豸�˿ڸ���
#define  ALARM_TYPE_END                           (ALARM_TYPE_BASE | 0x10) //�������ͽ���

//��������
enum{
	UPDATE_BOOTLOADER = 0,   //��������
	UPDATE_KERNERL,		     //�ں�
	UPDATE_FILESYSTEM		 //�ļ�ϵͳ
};

////�û�Ȩ��(��public.h����)
//enum{
//	USER_ADMIN = 0,     //����Ա
//	USER_DVR,		    //DVR�û�
//	USER_CONTROL,		//�����û�
//	USER_PREVIEW		//Ԥ���û�
//};


//  {������} //����һ�����û򷵻ش�����,�����ص���string��,�򷵻ض�Ӧ��������
#define  ERROR_BASE				(1 < 3)
enum{
	ERROR_SOUND = (ERROR_BASE | 1),
	ERROR_STEAM,
	ERROR_VIDEO,
	ERROR_MOVECHECK,
	ERROR_NETWORKCHECK
};

//�豸����
enum{
	DEV_TYPE_NULL = 0,			//
	DEV_TYPE_NVR = 0xFF - 1,				//NVR
	DEV_TYPE_IPC = 0xFF,					//IPǹ
};

//�����ļ����� 
enum SEARCH_TYPE 
{ 
	SEARCH_TYPE_MANUAL = 0,					// �ֶ� 
	SEARCH_TYPE_TIMING,						// ��ʱ 
	SEARCH_TYPE_MOTION,						// �ƶ���� 
	SEARCH_TYPE_ALARM,						// ���� 
	SEARCH_TYPE_MOTIONORALARM,				// ����򱨾� 
	SEARCH_TYPE_MOTIONANDALARM,				// �����ұ��� 
	SEARCH_TYPE_ALL,						// ȫ�� 
	/////////////////////////////˳��ũ�̶�������ռ��/////////////////////////////
    SEARCH_TYPE_SDNS_COUNTER = 8,           //��̨���н���
    SEARCH_TYPE_SDNS_ATM,                   //ATM���н���
    //////////////////////////////////////////////////////////////////////////////
}; 

//�¼����� 
enum EVENT_TYPE 
{ 
	EVENT_MANUAL = 0,					// �ֶ� 
	EVENT_TIMING,						// ��ʱ 
	EVENT_MOTION,						// �ƶ���� 
	EVENT_ALARM,						// ���� 
	EVENT_MOTIONORALARM,				// ����򱨾� 
	EVENT_MOTIONANDALARM,				// �����ұ��� 
	EVENT_OTHER,						// ���� 
	EVENT_NORMAL,						// ���ڽ�����ͨ¼���ֶ���ʱ�����¼�¼�� 
	/////////////////////////////˳��ũ�̶�������ռ��/////////////////////////////
    EVENT_SDNS_COUNTER,                     //��̨���н���
    EVENT_SDNS_ATM,                         //ATM���н���
    ///////////////////////////////////////////////////////////////////////////////////////
	EVENT_NOTHING,	
};

//Զ�̻طſ�������
enum PLAY_CTL_CMD
{
    PLAY_CTL_PLAY,						//��ʼ����
    PLAY_CTL_PAUSE,						//��ͣ
    PLAY_CTL_GET_TIME,					//��ȡ��ǰ�Ѿ����ŵ�ʱ��
	PLAY_CTL_CONTINUE,					//����
    PLAY_CTL_SET_SPEED,					//���������                              
    PLAY_CTL_SET_TIME,					//���õ�ǰ���ŵ�ʱ��(�Ϸ�)
	PLAY_CTL_NEXT_FRAME,				//��֡
	PLAY_CTL_GET_TOTAL_FRAMES,			//��ȡ��֡��
	PLAY_CTL_SET_FRAME_RATE,			//���ûط�֡��
    PLAY_CTL_SET_DIRECTION,				//���ò��ŷ���(0������1������)

	PLAY_CTL_STARTAUDIO = 100,			//������
	PLAY_CTL_STOPTAUDIO,				//�ر�����
};

//֪ͨ�¼�
enum NOTIFY_EVENT
{
	MOTION_START = 0,					// �ƶ���⿪ʼ 
	MOTION_STOP,						// �ƶ������� 
	MASK_START,							// �ڵ�������ʼ 
	MASK_STOP,							// �ڵ��������� 

	ALARM_IO_START = 100,				// IO������ʼ 
	ALARM_IO_STOP,						// IO�������� 
	ALARM_MODULE_CONFIG,				// ����ģ�����޸�������Ϣ 

	MEDIA_RECORD_ERR = 200,				// ͨ������¼����� 
	MEDIA_MAIN_LOSE,					// ��������Ƶ��ʧ 
	MEDIA_SUB_LOSE,						// ��������Ƶ��ʧ 
	MEDIA_CONNECT,						// ��Ƶ���� 
	TIME_ERROR,							// Уʱ���� 
	TIME_OK,							// Уʱ�ɹ� 

	NETWORK_CHANGED = 300,				// ��������ı� 
	LOCAL_SHUTDOWN,						// ���عػ� 
	LOCAL_REBOOT,						// �������� 
	LOCAL_MODIFNETPRA,					// �����޸�������� 
	LOCAL_UPDATASYSTEM,					// �������� 
	LOCAL_COVERDEFAULCONFIG,			// ���ػָ�Ĭ������ 

	REMOTE_LOGIN = 400,					// Զ�̵�¼ 
	REMOTE_SHUTDOWN,					// Զ�̹ػ� 
	REMOTE_LOGOUT,						// Զ��ע�� 
	REMOTE_REBOOT,						// Զ������ϵͳ 
	REMOTE_MODIFNETPRA,					// Զ���޸�������� 
	REMOTE_UPDATASYSTEM,				// Զ������NVR 
	REMOTE_COVERDEFAULTCONFIG,			// Զ�ָ̻�Ĭ������ 

	TIME_CHANGEING = 500,				// ϵͳʱ�伴�������仯 
	TIME_CHANGED ,						// ϵͳʱ���Ѿ������仯 
	DISK_CHANGED,						// ����Ӳ�� 
	IPSAN_LOST,							// IPSAN ���� 
	DISK_FULL,							// Ӳ���� 
	SNAP_DISK_CHANGED,					// ����Ӳ�� 
	DISK_ERROR,							// Ӳ�̻�(ϵͳ�����еĹ����У�Ӳ�̱��ε�)
	DISK_FULL_OK,						// Ӳ������,��Ӧ��һ�ζ�Ӧ��Ӳ�����ı���
    DISK_ERROR_OK,						// Ӳ������,��Ӧ��һ�ζ�Ӧ��Ӳ�̻��ı���
};

//¼��״̬
enum STREAM_RECORD_STATUS
{
	STREAM_RECORD_STATUS_NULL = 0,				// 0 - δ¼��
	STREAM_RECORD_STATUS_MANUAL_MAIN,			// 1 - �ֶ�¼����������
	STREAM_RECORD_STATUS_TIMING_MAIN,			// 2 - ��ʱ¼���������� 
	STREAM_RECORD_STATUS_EVENT_MAIN,			// 3 - �¼�¼����������
	STREAM_RECORD_STATUS_MANUAL_SECOND,			// 1 - �ֶ�¼�񣨴�������
	STREAM_RECORD_STATUS_TIMING_SECOND,			// 2 - ��ʱ¼�񣨴������� 
	STREAM_RECORD_STATUS_EVENT_SECOND,			// 3 - �¼�¼�񣨴�������
};

enum HY_PTZ_CMD
{ 
	LIGHT_PWRON,				//��ͨ�ƹ��Դ 
	WIPER_PWRON,				//��ͨ��ˢ���� 
	FAN_PWRON,					//��ͨ���ȿ��� 
	HEATER_PWRON,				//��ͨ���������� 
	AUX_PWRON1,					//��ͨ�����豸���� 
	AUX_PWRON2,					//��ͨ�����豸���� 
	ZOOM_IN_EX,					//������(���ʱ��) 
	ZOOM_OUT_EX,					//�����С(���ʱ�С) 
	FOCUS_NEAR,					//����ǰ�� 
	FOCUS_FAR,					//������ 
	IRIS_OPEN,					//��Ȧ���� 
	IRIS_CLOSE,					//��Ȧ��С 
	TILT_UP,					//��̨���� 
	TILT_DOWN,					//��̨�¸� 
	PAN_LEFT,					//��̨��ת 
	PAN_RIGHT,					//��̨��ת 
	UP_LEFT,					//��̨��������ת 
	UP_RIGHT,					//��̨��������ת 
	DOWN_LEFT,					//��̨�¸�����ת 
	DOWN_RIGHT,					//��̨�¸�����ת 
	PAN_AUTO,					//��̨�����Զ�ɨ�� 
};

enum HY_PTZ_PRESET_CMD
{ 
	ADD_PRESET,				//����Ԥ�õ�
	SET_PRESET,					//����Ԥ�õ�
	CLE_PRESET,					//���Ԥ�õ�
	GOTO_PRESET,				//ת��Ԥ�õ�
};

//���������ļ�����
enum UPGRADE_IMG_TYPE	
{
	UPGRADE_IMG_UBOOT,
	UPGRADE_IMG_PAR,
	UPGRADE_IMG_KERNEL,
	UPGRADE_IMG_FS,
	UPGRADE_IMG_FS_VER,
	UPGRADE_IMG_END,
	UPGRADE_IMG_FILE
};

//����״̬
#define UPGRADE_STATE_OTHER		10
#define	UPGRADE_STATE_START		11
#define UPGRADE_STATE_END		12
#define UPGRADE_STATE_OK		13
#define UPGRADE_STATE_FAILED	14
#define UPGRADE_STATE_ING		15

enum HY_PLAYBACK_DPI
{
	PLAYBACK_DPI_DEF = 0,		//����ת��
	PLAYBACK_DPI_D1,			//ת���D1��704*576�� 25֡
	PLAYBACK_DPI_CIF			//ת���CIF��352*288��12֡
};

//�豸��������
typedef struct
{
	char szDevName[20];		// �豸��Ϣ
	char szDevNo[20];		// �豸���
	char szSerial[10];		// ���к�
} SYSTEM_DEV_STR;

//ϵͳ�汾��Ϣ
typedef struct
{
	char szUBOOTVer[10];		// U-BOOT�汾��
	char szKernelVer[10];		// �ں˰汾��
	char szApplicationVer[10];	// Ӧ�ð汾
} SYSTEM_VER_STR;

//ϵͳʱ��
typedef struct
{
	BYTE byNTPEnable;		//����ʱ������(0:�ر�,1:����)
	char szNTPServer[250];	//NTP������
	int iDate;				//Year= (23λ), Month(4λ), Day(5λ)
	int iTime;				//Hour(5λ), Minute(6λ), Second(6λ)
} SYSTEM_TIME_STR;

//����osd
typedef struct
{
	BYTE byOsdNo;		//Ŀ����
	BYTE byOsdType;		//Ŀ������(0:����ʱ��, 1:�Զ����ַ���)
	BYTE byShow;		//�Ƿ���ʾ(1: ��ʾ, 0:����ʾ)
	BYTE byVideoSource;	//osd���������� 0Ϊ�������� 1Ϊ������
	UINT dwDataSize;	//�������ݳ��ȣ����Ϊ0��ʾ������osd��ʽ
} SET_OSD_LINUX;

typedef struct
{
	SET_OSD_LINUX osdClient;
	char szActualContent[60];
} SET_OSD_T;


  //OSD��ȡ
typedef struct
{
	BYTE byNum;			//Ŀ����
	BYTE byOSDType;		//Ŀ�����ͣ��ַ�����(0-5��Ƶ���ƣ��豸������ʱ������, /֡��/����,ͼƬ,�û������ַ���)
	BYTE byShow;		//�ر���ʾ��state=1 ����ʾ
	unsigned short sX;	//OSD����X
	unsigned short sY;	//OSD����Y
	char szActualContent[60];	//osdʵ������
} REQ_OSD_T;

  //����osd��λ��
typedef struct
{
	BYTE byKindOfStream;			//�������
	BYTE byNum;						//Ŀ����
	unsigned short sX;				//OSD����X
	unsigned short sY;				//OSD����Y
} CONTROL_OSD_T;

//�����ɼ����ã�0x0003��
typedef struct
{
	BYTE byFormate;			//������2(0:8K, 1:16K), ����λ��1(0:8λ��1:16λ),
							//������1λ(0:1, 1:2),�����ʽ2λ(0:PCM, 1:PCMA,2:PCMU), ����1λ��0Ϊ��˷磬 1Ϊ�������룩
	BYTE byVolume;			//����������bit,���������bit; ���룺0-15; �����0-15;
} SOUND_STR;

typedef struct
{
	BYTE byVideoEffect;							//��ƵЧ��(0-2 ����Ϊ����ã��ã�һ��)
	BYTE byResolution;							//����ֱ���(0:QCIF, 1:CIF, 2:VGA��3:D1, 4:SVGA��5:720p, 6:960p��7:1080p��8:1200p)
	BYTE byFrameratePerSecond;					//����֡��(0-60)
	BYTE byRateControlImageEffect;				//�������ƣ�bit,0Ϊ�ɱ�������1,�̶�����;ͼ��Ч��4bit; 1-6
	unsigned short wBytePerSecond;				//����(0-4M), ��С����ֵ/1000
} STREAM_STR;

//��Ƶ����
typedef struct
{
	BYTE byFontState;							//������ɫ4bit(0-4 ����Ϊ����,��,��,��,��), ���ڸ�ʽ4bit(0-2 �����ǣ�YYYY-MM-DD,MM-DD-YYYY,DD-MM-YYYY)
	BYTE byState;								//��1bit(0Ϊ50hz,1Ϊ60Hz), ����1bit(0Ϊ�رվ���1Ϊ�򿪾���), ��ת1bit(0Ϊ�رշ�ת,1Ϊ�򿪷�ת), ��Ƶ����1bit(0Ϊ�ر���Ƶ����,1Ϊ����Ƶ����)
	STREAM_STR stream[2];						//��������
} VIDEO_STR;


  //��̬����
typedef struct
{
	int iState;						//״̬0-���ã�1-���ã�2-�Զ�
	int iLevel;						// �ȼ���0-100��
} VIDEO_EX;

//ʱ���
typedef struct
{
	BYTE byState;					//0λ��ʾ���Ƿ�ѡ��,1-4λ�ֱ��ʾʱ���1-4.
	unsigned short sT1Begin;         //���ʱ��1��ʼʱ��(��11-15λСʱ��5-10λ�ֵ�0-4λ��)
	unsigned short sT1End;           //���ʱ��1����ʱ��(��11-15λСʱ��5-10λ�ֵ�0-4λ��)
	unsigned short sT2Begin;         //���ʱ��2��ʼʱ��(��11-15λСʱ��5-10λ�ֵ�0-4λ��)
	unsigned short sT2End;           //���ʱ��2����ʱ��(��11-15λСʱ��5-10λ�ֵ�0-4λ��)
	unsigned short sT3Begin;         //���ʱ��3��ʼʱ��(��11-15λСʱ��5-10λ�ֵ�0-4λ��)
	unsigned short sT3End;           //���ʱ��3����ʱ��(��11-15λСʱ��5-10λ�ֵ�0-4λ��)
	unsigned short sT4Begin;         //���ʱ��4��ʼʱ��(��11-15λСʱ��5-10λ�ֵ�0-4λ��)
	unsigned short sT4End;           //���ʱ��4����ʱ��(��11-15λСʱ��5-10λ�ֵ�0-4λ��)
} TIME_STR;


typedef struct
{
	unsigned short sX1;         //16�ı���
	unsigned short sY1;         
	unsigned short sX2;         
	unsigned short sY2;         
	BYTE bySensitivity;			//0-3,0-Ϊ����⣬��ֵԽ�󼶱�Խ��
} MOVE_AREA_STR;

  //������Ϣ
typedef struct
{
	char* szDevNo;
	char* szTime;
} COMM_ALARM_STR;

  //̽ͷ������Ϣ
typedef struct
{
	BYTE byIp[16];
	BYTE byDevNo[20];
	BYTE channel;			//ͨ����(��0��ʼ)
	BYTE state;				//IO״̬(0 �� 1)
	int reserved1;
	int reserved2;
} DETECTOR_ALARM_STR;

//�ƶ�����
typedef struct
{
	BYTE byWarnLink;      //��������3bit; ����¼��(��0bit)������1bit, 0Ϊ�أ�1Ϊ��
                         //����ץ��(��1bit)������1bit, 0Ϊ�أ�1Ϊ��;�����������(��2bit)������1bit, 0Ϊ�أ�1Ϊ��
	MOVE_AREA_STR areas[16];
	BYTE byKeepTime;				//��������ʱ�䣨��������������
	BYTE byNumOfPhoto;				//ץ����Ƭ����(0-255)
	BYTE byPhotoInteval;			//ץ�ļ��ʱ��(0-255)��
	BYTE byTimeOfVedio;				//¼��ʱ��(0-255)��
	TIME_STR plan[7];				//0-6��������������
} MOVE_CHECK_STR;

//�ڵ�����
typedef struct
{
	BYTE byLinkOutput;     //�������
	BYTE byIsOpen;         //�Ƿ�򿪱���
	BYTE byDuration;       //����ʱ��
	TIME_STR plan[7];				//1-7����һ��������
}OCCLUSION_CHECK_STR;

//��Ƶ�ڸ�����
#define MAX_POLYGON_POINT_NUM 10	//������ε���Ŀ
#define MAX_HIDE_AREAS_NUM 10	//����ڸ�������Ŀ
#define MAX_AVAILABLE_HIDE_AREAS_NUM 8	//�����Ч�ڸ�����
typedef struct
{
	int x;
	int y;
}PLYGON_POINT_STR;

typedef struct
{
	int nPointNum;
	PLYGON_POINT_STR points[MAX_POLYGON_POINT_NUM];
}POLYGON_AREA_STR;

typedef struct
{
	BYTE byEnabled;	//0:��ֹ, 1:ʹ��
	BYTE byreserved[3];
	POLYGON_AREA_STR area;
}HIDE_AREA_STR;

typedef struct
{
	int nAreasNum;
	BYTE byReserved[8];
	HIDE_AREA_STR areas[MAX_HIDE_AREAS_NUM];
}HIDE_AREAS_STR;

//̽ͷ����
typedef struct
{
	BYTE byWarnLink;			//��������3bit;,
								//����¼��(��0bit)������1bit, 0Ϊ�أ�1Ϊ��
								//����ץ��(��1bit)������1bit, 0Ϊ�أ�1Ϊ��
								//�����������(��2bit)������1bit, 0Ϊ�أ�1Ϊ��
	BYTE byState;				//��⿪��(��0bit):   ����1bit, 0Ϊ�أ�1Ϊ��
								//̽ͷ����(��1): ����1bit,0-1
	BYTE byKeepTime;			//��������ʱ�䣨��������������
	BYTE byNumOfPhoto;			//ץ����Ƭ����(0-255)
	BYTE byPhotoInteval;		//ץ�ļ��ʱ��(0-255)��
	BYTE byTimeOfVedio;			//¼��ʱ��(0-255)��
	TIME_STR plan[7];			//1-7����һ��������
}WARN_CHECK_STR;

//�������
typedef struct
{
	BYTE byWarnLink;     //��������3bit;,
						//����¼��(��0bit)������1bit, 0Ϊ�أ�1Ϊ��
                        //����ץ��(��1bit)������1bit, 0Ϊ�أ�1Ϊ��
						//�����������(��2bit)������1bit, 0Ϊ�أ�1Ϊ��
	BYTE byOpen;         //��⿪��1bit ��⿪��(��0bit):1bit, 0Ϊ�أ�1Ϊ��
	BYTE byKeepTime;     //��������ʱ�䣨��������������
	BYTE byNumOfPhoto;   //ץ����Ƭ����(0-255)
	BYTE byPhotoInteval; //ץ�ļ��ʱ��(0-255)��
	BYTE byTimeOfVedio;  //¼��ʱ��(0-255)��
}NETWORK_CHECK_STR;

//��������
typedef struct
{
	BYTE	byIp[4];						//ip��ַ
	BYTE	bySubmask[4];					//����
	BYTE	byGateway[4];					//����
	BYTE	byPhaddr[6];					//�����ַ
	BYTE	byMainDNS[4];					//��ѡDNS
	BYTE	byBackupDNS[4];					//����DNS
	BYTE	byDHCPEnable;
	//char	szNTPServer[250];
	unsigned short	sSoundPort;						//��Ƶ�˿ںţ�����������
	unsigned short	sStreamPort;					//��Ƶ�������˿ںţ�����������
	unsigned short	sConfigPort;					//�������˿ڣ�ȱʡ�˿ڣ�������)
} NETWORK_BASE;

typedef union 
{ 
	int iDefaultRoute;						//Ĭ��·�� 0Ϊeth0 1Ϊeth1 
	int iMajorNic;							//������ 0Ϊeth0 1Ϊeth1 
	int iExtension;							//������� 
} NET_EXT_PARA; 

typedef struct 
{ 
	char szIp[20];							//IPv4��ַ 
	char szMask[20];						//�������� 
	char szGateway[20];						//���� 
} NET_BASIC_PARA; 

typedef struct 
{ 
	NET_BASIC_PARA basicParas[3];			//��Ŷ��������� 
	char szMac[20];							//mac ��ַ 
	unsigned int unMTU;						//MTU 
	BYTE byDHCPEnable;						//�Ƿ�ʹ��DHCP 
	int iNicType;							//��������:1Ϊ10M��˫�� 2Ϊ10Mȫ˫�� 3Ϊ100M��˫�� 4Ϊ100Mȫ˫�� 5Ϊ10M/100M/1000M����Ӧ 
	char szIpv6Addr1[45];					//IPv6��ַ1 
	char szIpv6Addr2[45];					//IPv6��ַ2 
	char szIpv6DefaultGateway[45];			//IPv6Ĭ������ 
} NIC_PARA; 

//��������(��չ)
typedef struct{ 
	int iMode;								//����ʹ�õ�����ģʽ 0Ϊ��ֵ�趨 1Ϊ����ƽ�� 2Ϊ�����ݴ� 
	int iNicNum;							//����������1~3�� 
	NIC_PARA nicParas[3];					//ÿ��ģʽ��3�������Ĳ��� 
	char szPrimaryDNS[20];					//��ѡDNS 
	char szBackupDNS[20];					//����DNS 
	NET_EXT_PARA extPara;					//���������������ģʽ��ͬ����ͬ 
} NETWORK_EX;

//������������
typedef struct
{
	BYTE	byIp[4];						//ip��ַ
	BYTE	bySubmask[4];					//����
	BYTE	byGateway[4];					//����
	BYTE	byEncryptFreqModeDHCP;			//���ܡ�Ƶ�Ρ�ģʽ����bit;
	UINT	dwSSID;							//SSID��
}WANLESS_STR;

//DDNS����
typedef struct
{
	BYTE	byDDNSUpdateInteval;
	char	szDDNSServerName[20];			//DDNS�����ṩ��
	char	szRegName[20];					//ע����
	char	szPwd[20];						//����
	char	szDDNSDomain[20];				//����
	char	szDDNSAddr[20];					//��ַ
	unsigned short sDDNSPort;				//�ģģΣӶ˿�
	unsigned short sDataMapPort;			//����ӳ��˿�
	unsigned short sWebMapPort;				//webӳ��˿�
}DDNS_STR;

//PPPOE����
typedef struct
{
	BYTE byPPPOEOpen;				//pppoe�Ƿ�����
	char szAddr[30];				//��ַ
	char szUserName[10];			//�û���
	char szPwd[10];					//����
	int iKeepTime;					//����ʱ��
}PPPOE_STR;

//�û�����ָ���루0x000D��
typedef struct
{
	char	szUserName[10];			//�û���
	char	szPwd[33];				//����  {�޸�}
	BYTE	byRight;				//Ȩ�޼���,0-3(����Ա, DVR�û�, ����Ȩ��, ���Ȩ��}
} USER_ACCOUNT;

//�����û���Ϣ
typedef struct
{
	short	sAccountNum;
	USER_ACCOUNT arrAccount[MAX_USER];
} ALL_USER_ACCOUNT;

//ͼ�������ṹ��
typedef struct
{
	BYTE byBright;                         //����(0-255)
	BYTE bySaturation;                     //���Ͷ�(0-255)
	BYTE byAcutance;                       //���(0-255)
	BYTE byRed;                            //��ɫ(0-255)
	BYTE byBlue;                           //��ɫ(0-255)
	BYTE byContras;						   //�Աȶ�(0-255)
	BYTE byGamma;                          //٤��(0-255)
}IMAGE_ADJUST_STR;

// ͼ�������ṹ����չ
typedef struct
{
	BYTE byEnhancement;                 //ͼ����ǿ(0-64)
	BYTE byDenoise;                     //����(0-16)
}IMAGE_ADJUST_STR_EX;

//��¼�û�
typedef struct
{
	char szUserName[10];
	char szPwd[32];
}USER_LOGIN_STR;

  //������������
typedef struct
{
	char byIP[4];
	unsigned short sPort;
}ALARM_CENTER_STR;

  //�û���־����
typedef struct
{
	BYTE byStart;
	BYTE byNum;
}REQ_USER_LOG_STR;

  //�û���־Ӧ��
typedef struct
{
	char szUserName[10];
	unsigned short sInfo;		//������Ϣ
	UINT iTime;					//ʱ��
}ANS_USER_LOG_STR;

typedef struct
{
	char szFileName[80];
	BYTE byFileType;
}UPDATE_STR;

typedef struct
{
	char	szUserName[10];			//�û���
	char	szPwd[33];				//����  {�޸�}
	BYTE	byRight;				//Ȩ�޼���,0-3(����Ա, DVR�û�, ����Ȩ��, ���Ȩ��}
} USER;

//�豸��ʶ�ṹ��
typedef struct
{
	int iHandle;					//��Ƶ���
	int iChannel;					//��Ƶͨ����
	int iVideoSource;				//��ƵԴ
}IDENTITY;


  //���������ṹ��
typedef struct
{
	IDENTITY identity;
	unsigned short sRecvPort;
	unsigned short sSendPort;
}REQ_STREAM;

  //���ն�
typedef struct
{
	int iGrayChangeThreshold;				//�Ҷȸı䷧ֵ
	int iLowLightThreshold;					//���նȷ�ֵ
	BYTE byCanChangeColor;					//�Ƿ�������ɫ�ı�
}LOW_LIGHT;

  //���ⲹ��
typedef struct
{
	int iEnable;
	int iBackGroundWeight;
	int iCenterWeight;
	int iX;
	int iY;
	int iWidth;
	int iHeight;
}BACK_LIGHT;

typedef struct
{
	BYTE pY[4096 * 4096 + 1];
	BYTE pU[4096 * 4096 / 4 + 1];
	BYTE pV[4096 * 4096 / 4 + 1];
}DECODE_DATA;

//�豸�����ϢA
typedef struct
{
	int iSeriusHotPixel;						//�������
	int iHotPixel;								//���
	int iSeriusBrightPixel;						//��������
	int iBrightPixel;							//����
	int iClusterCnt;							//����
	int iSeriusPixelMax;						//���ص����ֵ
	int iHotBrightPixelMax;						//�����������ֵ
	int iDarkPixelMax;							//�������ֵ
	int iClusterCntMax;							//�������ֵ
}DEV_CHECK_INFO_A;

  //�豸�����ϢB
  typedef struct
{
	int iSeriusDarkPixel;						//���ػ���
	int iDarkPixel;								//����
	int iClusterCnt;							//����
	int iSeriusPixelMax;						//���ص����ֵ
	int iHotBrightPixelMax;						//�����������ֵ
	int iDarkPixelMax;							//�������ֵ
	int iClusterCntMax;							//�������ֵ
}DEV_CHECK_INFO_B;

//����Ƶ
typedef struct 
{ 
  unsigned short  audio_port; 
  unsigned short  channel; //ͨ���� 
} AUDIO_OPEN;

//ͨ����Ϣ
typedef struct
{
    int      Id;              // ͨ����
    char     Ip[20];          // IP��ַ
    int      Port;            // ����˿�
    int      Protocol;        // Э��(ǹ���ͣ�0 - IPǹ��1 - �忨)
    char     Name[50];        // ͨ����
    char     Model[50];       // �豸�ͺ�
    int      State;           // ״̬(0 - δ���ӣ�1 - �����ӣ�
    char     SN[50];          // ���к�
    char     FireVersion[50]; // �̼��汾
} CHAN_INFO;

//ͨ���б�
typedef struct
{
    int         chanNum;                  //ͨ����
    CHAN_INFO chansInfo[MAX_CHAN_NUM];  //ͨ����Ϣ����
} CHANS_LIST_INFO;

//ϵͳʱ��
typedef struct
{
	BYTE byNTPEnable;		//����ʱ������(0:�ر�,1:����)
	char szNTPServer[250];	//NTP������
	int iDate;				//Year= (23λ), Month(4λ), Day(5λ)
	int iTime;				//Hour(5λ), Minute(6λ), Second(6λ)
} SYSTEM_TIME;

typedef struct
{
	DWORD dwTime;		//��������ʱ��
	char szIp[16];		//�����������豸ip
	WORD wKind;			//������������
	char szContent[50];	//��������
	int nLen;			//�������ݳ���
	char szAlarmTime[31];	//�����������豸ʱ��
}ALARM_RECORD;

//ʱ������ṹ��
typedef struct{  
	unsigned short		sYear;					//��
	unsigned short		sMonth;					//��
	unsigned short		sDay;					//��
	unsigned short		sHour;					//ʱ
	unsigned short		sMinute;				//��
	unsigned short    	sSecond;				//��
}TIME;

//���ҵ�¼���ļ���Ϣ�ṹ��
typedef struct{
	int				nChannel;					//ͨ����
	int				nFileType;					//¼���ļ����ͣ�0-�ֶ���1-��ʱ��2-�ƶ����,3-����,4-����򱨾�, 5-�����ұ���, 6-ȫ��
	int				nIsLocked;					//�Ƿ�������0-δ�����ļ���1-�����ļ�,2-��ʾ�����ļ�(����������δ����)
	TIME			struStartTime;				//��ʼʱ��
	TIME			struEndTime;				//ֹͣʱ��
	int				nReserved;					//Ԥ����Ϣ��4���ֽ�
}FILE_COND,*LPFILE_COND;

//�����ļ���Ϣ
typedef struct{
	char	szFileName[100];					//�ļ���
	TIME	struStartTime;						//�ļ��Ŀ�ʼʱ��
	TIME	struEndTime;						//�ļ��Ľ���ʱ��
	DWORD	dwFileSize;							//�ļ���С
	int		nLocked;							//�ļ��Ƿ�������1���ļ���������0���ļ�δ����
	int		nFileType;							//�ļ����ͣ�0-�ֶ���1-��ʱ��2-�ƶ����,3-����,4-����򱨾�, 5-�����ұ���, 6-ȫ��
	int		nReserved;							//Ԥ����Ϣ��4���ֽ�
}FIND_DATA,*LPFIND_DATA;

//�ط�����
typedef struct{
	int nChannel;								//ͨ����
	TIME struBeginTime;							//��ʼʱ��
	TIME struEndTime;							//����ʱ��
	HWND hWnd;									//�طŴ��ڣ�SDK����ʱ������Чֵ����
	WORD wPort;									//���ն˿�
	int	nData;									//��������(��8bit��ת�벥�ŷֱ��� HY_PLAYBACK_DPI; Ԥ����Ϣ��3���ֽ�,��Ϊ0)
}VOD_PARA,*LPVOD_PARA;

//Ӳ����Ϣ�ṹ�壺 
typedef struct 
{ 
	int nDiskNum;								//Ӳ�̺� 1-10 
	unsigned long lUsedRecordSize;				//����¼��ռ� ��λΪM 
	unsigned long lUsedSnapSize ;				//����ץ�Ŀռ� ��λΪM 
	unsigned long lDiskSize;					//Ӳ�̴�С ��λΪG 
	unsigned long lSnapQuota;					//ץ����� ��λΪG 
	unsigned long lRecordQuota;					//¼����� ��λΪG 
}DISK_INFO;

//Ӳ����Ϣ��
typedef struct 
{
	int nValidCount;							//��ЧӲ����Ŀ
	DISK_INFO arrDiskInfo[MAX_DISKNUM];			//Ӳ����Ϣ����
}DISK_SET;

//NVR�������ݽṹ�壺
typedef struct
{
    int     chan;           //ͨ����
    char    time[30];       //�¼�������ʱ��
	char	res1[2];
    NOTIFY_EVENT type;      //�¼�����
    char    name[30];       //�¼�����, Ŀǰ������IO����
	char	res2[2];
} NOTIFY_EVENT_MSG;

//ʱ������ṹ��
typedef struct 
{ 
	int nYear; 
	int nMonth; 
	int nDay; 
	int nHour; 
	int nMinute; 
	int nSecond; 
} HY_TIME;

//ͼ�������ṹ��
typedef struct 
{ 
	BYTE byBrightness;					//����(0-255) 
	BYTE bySaturation;					//���Ͷ�(0-255)
	BYTE bySharpness;					//���(0-255)
	BYTE byRed;							//��ɫ(0-255)
	BYTE byBlue;						//��ɫ(0-255)
	BYTE byContrast;					//�Աȶ�(0-255)
	BYTE byGamma;						//gamma(0-255)
	BYTE byEnhancement;                 //ͼ����ǿ(0-255)
	BYTE byDenoise;                     //����(0-255)
	BYTE byChroma;						//ɫ��(0-255)
	BYTE byRes[15];						//����
} HY_IMAGE_EFFECT;

//��̨����
typedef struct 
{ 
	int cmd;							//�������� HY_PTZ_CMD
	int nStopFlag;				//0: ��ʼ��1��ֹͣ 
	int nSpeed;					//�ٶȷ�Χ1 ~ 7, 0Ϊ��ֹ 
} HY_PTZ_CTL;

//Ԥ�õ���Ϣ
#define MAX_PRESET_TOKEN_LEN    25                                
#define MAX_PRESET_NAME_LEN    30
typedef struct  
{
    char    szToken[MAX_PRESET_TOKEN_LEN+1];                        
    char    szName[MAX_PRESET_NAME_LEN+1];
} HY_PRESET_INFO;


//Ԥ�õ����
typedef struct 
{ 
	int cmd;					//������̨Ԥ�õ����� HY_PTZ_PRESET_CMD  0: ���ӣ�1: �޸� 2�������3��ת�� 
	HY_PRESET_INFO presetInfo;				//Ԥ�õ���Ϣ
} HY_PTZ_PRESET;

//��Ƶ�������
typedef struct 
{ 
	int nStreamId;					//0:������ 1�������� ����:�������� 
	int nEncType;					//���뷽ʽ 0:JPEG 1:MPEG4 2:H264 
	int nWidth;						//�ֱ��ʿ�� 
	int nHeight;					//�ֱ��ʸ߶� 
	int nFrameRate;					//֡�� 
	int nBitrate;					//����(��λ��kb) 
	BYTE byRes[20]; 
} HY_VIDEO_ENC_INFO;

//����¼��״̬
typedef struct
{
    int nStreamId;	 //0: ������, 1��������
    int nState;      //0��ֹͣ�ֶ�¼��, 1: �����ֶ�¼��          
} HY_SET_RECORD_STATE;

//IO������Ϣ
#define MAX_NUM_IO				64	//�������IO������
#define MAX_LEN_IO_ID			30	//IO����ID���Ƴ���
typedef struct
{
    BYTE     nState;					//1��������ʼ 0������ֹͣ
    char     szId[MAX_LEN_IO_ID+1];		//IO����ID
} HY_IO_STATE;

//������־��Ϣ
#define LOG_SOURCE_LEN          100
#define SHORT_LOG_INFO_LEN	    100
#define WHOLE_LOG_INFO_LEN      11840

//������
typedef enum
{
    ALL = 0,
    ALARM,          //����
    ABNORMAL,       //�쳣
    OPERATION,      //����
    INFO            //��Ϣ
}HY_LOG_MAJOR_TYPE;

//�����Ĵ�����
typedef enum
{
    ALARMALL = 0,               //ȫ���������ڼ���
    ALARMINPUTSTART,            //�������뿪ʼ
    ALARMINPUTSTOP,             //�����������
    ALARMOUTPUT,                //�������
    STARTMOTIONDETECTION,       //�ƶ���⿪ʼ
    ENDMOTIONDETECTION,         //�ƶ�������
    STARTSHELTER,               //�ڵ�������ʼ
    ENDSHELTER                  //�ڵ���������
}HY_LOG_MINOR_TYPE_ALARM;

//�쳣�Ĵ�����
typedef enum
{
    ABNORMALALL = 0,            //ȫ���������ڼ���
    UNAUTHORIZEDACCESS,         //�Ƿ�����
    DRIVEFULL,                  //Ӳ����
    IPCONFLICT,                 //IP��ͻ
    NETWORKDROPPED,             //�������
    RECORDORCASCREENSHOTERROR,  //¼�����ץͼ�쳣
    IPCAMERAERROR,              //ip camera �쳣
    VIDEOFORMATERROR,           //���룬�����Ƶ��ʽ��ƥ��
    VIDEOSIGNALLOST             //��Ƶ�źŶ�ʧ
}HY_LOG_MINOR_TYPE_ABNORMAL;

//����������
typedef enum
{
    OPERATIONALL = 0,   //ȫ���������ڼ���
    LOCALSHUTDOWN,      //���عػ�
    ERRORSHUTDOWN,      //�쳣�ػ�
    LOCALREBOOT,        //��������
    LOCALLOGIN,         //���ص�¼
    LOCALLOGOUT,        //����ע��
    LOCALCONFIGURATION, //��������
    LOCALUPGRADE,       //��������
    LOCALSTARTRECORD,   //��������¼��
    LOCALSTOPRECORD,    //����ֹͣ¼��
    LOCALLOCKFILE,      //���������ļ�
    LOCALUNLOCKFILE,    //���ؽ����ļ�          ���� ww 20131226
    LOCALHANDALARM,     //���ر���
    LOCALINITIALIZEHARDDISK,    //���س�ʼ��Ӳ��
    LOCALADDIPCHANNEL,          //�������IPͨ��
    LOCALDELETIPCHANNEL,        //����ɾ��IPͨ��
    LOCALCONFIGIPCHANNEL,       //��������IPͨ��
    LOCALADDMOCKCHANNEL,          //�������ģ��ͨ��       ww 20140103
    LOCALDELETMOCKCHANNEL,        //����ɾ��ģ��ͨ��     ww 20140103
    LOCALPLAYRECORDFILE,        //���ػط�¼���ļ�
    LOCALINPORTPROFILE,         //���ص��������ļ�
    LOCALEXPORTPROFILE,         //���ص��������ļ�
    LOCALBACKUPRECORDFILE,      //���ر���¼���ļ�
    LOCALBACKUPSNAPFILE,        //���ر���ץ���ļ�
    LOCALADDNETHARDDISK,        //�����������Ӳ��
    LOCALCONFIGNETHARDDISK,     //������������Ӳ��
    LOCALSTARTSCREENSHOT,       //��������ץͼ
    LOCALSTOPSCREENSHOT,        //����ֹͣץͼ
    LOCALRECORERYADMINDEFAULTPASSWORD,  //���ػָ�����ԱĬ������
    LOCALLABELOPERATION,        //  ���ر�ǩ����
    REMOTELOGIN,                //Զ�̵�¼
    REMOTESHUTDOWN,             //Զ�̹ػ�
    REMOTEREBOOT,               //Զ������
    REMOTELOGOUT,               //Զ��ע��
    REMOTECONFIGURATION,        //Զ������
    REMOTEUPGRADE,              //Զ������
    REMOTESTARTRECORD,          //Զ�̿�ʼ¼��
    REMOTESTOPRECORD,           //Զ��ֹͣ¼��
    REMOTELOCKFILE,             //Զ�������ļ�
    REMOTEUNLOCKFILE,           //Զ�̽����ļ�
    REMOTEHANDALARM,            //Զ���ֶ�����
    REMOTEINITIALIZEHARDDISK,   //Զ�̳�ʼ��Ӳ��
    REMOTEADDIPCHANNEL,         //Զ�����IPͨ��     
    REMOTEDELTEIPCHANNEL,       //Զ��ɾ��IPͨ��     
    REMOTEADDMOCKCHANNEL,         //Զ�����ģ��ͨ��    ww 20140103
    REMOTEDELTEMOCKCHANNEL,       //Զ��ɾ��ģ��ͨ��    ww 20140103
    REMOTEPLAYORDOWNLOADBYFILE, //Զ�̰��ļ��طŻ�����
    REMOTEPLAYORDOWNLOADBYTIME, //Զ�̰�ʱ��طŻ�����
    REMOTEEXPORTPROFILE,        //Զ�̵��������ļ�
    REMOTEINPORTPROFILE,        //Զ�̵��������ļ�
    REMOTEBACKUPRECORDFILE,     //Զ�̱���¼���ļ�
    REMOTEBACKUPPICTUREFILE,    //Զ�̱���ͼƬ�ļ�
    REMOTEGETCONFIGURATION,     //Զ�̻�ȡ����
    REMOTEGETSTATUE,            //Զ�̻�ȡ״̬
    BUILDTRANSPARENTSTATUE,     //����͸��״̬
    DISCONNECTTRANSPARENTSTATU, //�Ͽ�͸��״̬
    STARTVOICEINTERCOM,         //�����Խ���ʼ
    STOPVOICEINTERCOM,          //�����Խ�����
    REMOTEARMING,               //Զ�̲���
    REMOTEADDNETHARDDISK,       //Զ���������Ӳ��
    REMOTEDELTENETHARDDISK,     //Զ��ɾ������Ӳ��
    REMOTECONFIGNETHARDDISK,    //Զ����������Ӳ��
    REMOTESTRTSCREENSHOT,       //Զ������ץͼ
    REMOTESTOPSCREENSHTO,       //Զ��ֹͣץͼ
    REMOTELABELOPERATION        //Զ�̱�ǩ����
} HY_LOG_MINOR_TYPE_OPERATION;

//��Ϣ������
typedef enum
{
    INFOALL = 0,        //ȫ���������ڼ���
    LOCALHARDDISKINFO,  //����Ӳ����Ϣ
    HARDDISKSMART,      //Ӳ��SMART
    STARTRECORD,        //��ʼ¼��
    STOPRECORD,         //����¼��
    STARTSCREENSHOOT,   //��ʼץͼ
    STOPSCREENSHOOT,    //����ץͼ
    DETELEOLDRECORD,    //ɾ������¼��
    DETELEOLDSNAP,      //ɾ������ͼƬ
    NETHARDDISKINFO     //����Ӳ����Ϣ
}HY_LOG_MINOR_TYPE_INFO;

//������־��Ϣ����
typedef struct{
	TIME			struStartTime;				//��ʼʱ��
	TIME			struEndTime;				//ֹͣʱ��
	int				nMajorType;					//������:HY_LOG_MAJOR_TYPE
	int				nMinorType;					//������:HY_LOG_MINOR_TYPE_ALARM,HY_LOG_MINOR_TYPE_ABNORMAL,HY_LOG_MINOR_TYPE_OPERATION,HY_LOG_MINOR_TYPE_INFO
	BYTE			byReserved[8];				//Ԥ����Ϣ��8���ֽ�
}HY_LOG_COND,*LPHY_LOG_COND;

//���ҵ�����־��Ϣ
typedef struct{
	int             nId;								//��¼ID
    int				nMajorType;							//������:HY_LOG_MAJOR_TYPE
	int				nMinorType;							//������:HY_LOG_MINOR_TYPE_ALARM,HY_LOG_MINOR_TYPE_ABNORMAL,HY_LOG_MINOR_TYPE_OPERATION,HY_LOG_MINOR_TYPE_INFO
    int             nLevel;								//��Ҫ�ȼ�
    int             nChannel;							//��Ӧ��ͨ����
    TIME			struTime;							//����ʱ��
    char            szIp[45];
    char            szSource[LOG_SOURCE_LEN];			//�¼���Դ
    char            szShortMsg[SHORT_LOG_INFO_LEN];		//�������
    char            szWholeMsg[WHOLE_LOG_INFO_LEN];		//��ϸ����
}HY_LOG_DATA,*LPHY_LOG_DATA;

//ץͼ����
typedef struct
{
    int nStreamType;  //��������: 0 - �������� 1 - ��������Ŀǰֻ֧��������
    int nQuality;    //ͼ��������0~100���������������Ƽ�75
} HY_SNAPSHOT_PARA, *LPHY_SNAPSHOT_PARA;

//����״̬��Ϣ
typedef struct
{
	int nState;				//Զ��������״̬
	int nProgress;			//��������(0��100)
	WORD wCmd;				//������
	WORD wErrorCode;		//������
	BYTE* pData;			//����
	BYTE byRes[8];			//����
}HY_UPGRADE_STATUS, *LPHY_UPGRADE_STATUS;
//������������
typedef struct
{
    int nX;						//ȡֵΪ������ȵİٷֱ�(ȡֵ��Χ��0-100)
    int nY;						//ȡֵΪ�����߶ȵİٷֱ�(ȡֵ��Χ��0-100)
    int nWidth;					//ȡֵΪ����ͼ�����֧�ֱַ��ʿ�ȵİٷֱ�(ȡֵ��Χ��0-100)
    int nHeight;				//ȡֵΪ����ͼ�����֧�ֱַ��ʸ߶ȵİٷֱ�(ȡֵ��Χ��0-100)
} HY_FACE_AREA;

//��������Ч��
typedef struct
{
    BYTE   byBrightness; //����(0-255)
    BYTE   bySaturation; //���Ͷ�(0-255)
    BYTE   bySharpness;  //���(0-255)
    BYTE   byHue;        //ɫ��(0-255)
    BYTE   byContrast;   //�Աȶ�(0-255)
    BYTE   byDenoise;    //����(0-15)
} HY_FACE_EFFECT;

//�㳮�ַ�����

//��ȡ�㳮�ַ�������ʾ����
typedef struct
{
    BYTE byDisplayMode;   //0: display both, 1: hide both, 2: display cash info only, 3: hide card last 4 chars
    BYTE byDisplayTime;   //in seconds, 0 means always
    BYTE byFontSize;      //0: auto, 1: big, 2: medium, 3: small
    int	nX;
    int	nY;
    char reserved[16];
} HY_CHAR_OVERLAY_CFG;

//�㳮���ͺ�֧���б�
#define MAX_CASH_READER_NUM      10
typedef struct
{
    WORD    wTotalNum;										//֧�ֵ㳮�������ܶ�
    WORD    wCurrentNum;									//��ǰҳ������Ŀ
    WORD    wPage;											//��ǰҳ��
    char    strName[MAX_CASH_READER_NUM][25];				//��֧�ֵ㳮�������б�(ÿ���㳮���������Ʋ�����20�ֽ�)
} HY_CASH_READER_TYPE_LIST;

//VGA����
typedef struct
{
    int nIsAuto;			//�Ƿ��Զ�ʶ��
    int nWidth;          
    int nHeight;        
    int nFrequency;
    int nV;					//��ֱλ��(��ΧΪ0��255)
    int nH;					//ˮƽλ��(��ΧΪ0��255)
    int nInvertColor;		//�Ƿ�ת��ɫ
    char reserved[8];		//����8�ֽ�
} HY_VGA_CONFIG;

//VGA��ѯ����
typedef struct
{
    int nWidth;        
    int nHeight;    
    int nFrequency;
    char reserved[8];		//����8�ֽ�
} HY_VGA_QUERY_PARA;

//�ƻ�ʱ��
typedef struct{
	unsigned short		sStartHour;					//��ʼʱ
	unsigned short		sStartMinute;				//��ʼ��
	unsigned short		sStartSecond;				//��ʼ��
	unsigned short		sStopHour ;					//����ʱ
	unsigned short		sStopMinute;				//������
	unsigned short		sStopSecond;				//������
}HY_SCHEDULE_TIME;

//IO������������
#define	NAME_LEN	32
#define MAX_CHANNUM	512
#define MAX_DAYS	8
#define	MAX_TIMESEGMENT	8
#define	MAX_ALARMOUT	128
#define	MAX_LEN_LINK_IO_ID	20
typedef struct {
    char				szId[MAX_LEN_IO_ID+1];			//��������ID
    char				szName[NAME_LEN];				//������������
    BYTE				byType;							//���������ͣ�0-������1- ����
    BYTE				byEnable;						//�Ƿ���0- ������1- ���� 
    int					nHandleType;					//����ʽ

    int					nLinkChan[MAX_CHANNUM];			//����¼��ͨ��
    HY_SCHEDULE_TIME	AlarmTime[MAX_DAYS][MAX_TIMESEGMENT];				//����ʱ�䣬һ��7��+���գ�ÿ���������8��ʱ���
    char				szLinkAlarmout[MAX_ALARMOUT][MAX_LEN_LINK_IO_ID+1];		//�������������
    BYTE				byReserved[64];					//����64�ֽ�
} HY_IO_ALARMIN_CFG;

//�������ã��������ݻص�����
//����
//lStream:      [out]  ���������HYRequestStream�ķ���ֵ
//pStream:      [out]  ��������(��ʽΪtagStreamHeaderͷ + ������)
//nLen:         [out]  ���ݳ���
//nFrameType:   [out]  ֡��������(0: Audio, 1: Header, 2: V-I, 3: V-P, 4: V-B, 5: ������)
//���أ���
typedef void (CALLBACK *HYMediaStreamInfo)(LONG lStream, BYTE *pStream, int nLen, int nFrameType); 

//�������ã��������ݻص�����(��չ)
//����
//lStream:						[out]  ���������HYRequestStream�ķ���ֵ
//pStream:						[out]  ��������(��ʽΪtagStreamHeaderͷ + ������)
//nLen:							[out]  ���ݳ���
//pFrameInfo:				[out]  ֡��Ϣ
//���أ���
typedef void (CALLBACK *HYMediaStreamInfoEx)(LONG lStream, BYTE *pStream, int nLen, HY_FRAME_INFO* pFrameInfo); 

//�������ã��豸����״̬�ص�����
//����
//nLogin:       [out]  ��¼�����HYLoginIPC�ķ���ֵ��
//nState:       [out]  �豸״̬��0��ʾ���ߣ� 1��ʾ������ 2��ʾ�����ߣ�
//���أ���
typedef void (CALLBACK *HYIPCOnlineState)(int nLogin, int nState); 

//�������ã��������Ȼص�����
//����
//nLogin:				[out]  ��¼�����HYLoginIPC�ķ���ֵ��
//lpUpgradeStatus:		[out]  ����״̬��Ϣ
//nUser:				[out]  �û��Զ�������
//���أ���
typedef void(CALLBACK *HYUpgradeCallBack)(int nLogin,LPHY_UPGRADE_STATUS lpUpgradeStatus, int nUser);

//����˵��: ��Ƶ���ݻص��ӿ�
//����
//lVoiceComHandle:						[out]  HYStartVoiceCom��HYStartVoiceComMR�ķ���ֵ
//pData:								[out]  ��Ƶ����(PCM������Ƶ��Ϊ8000��16λ,����ͨ��)
//nLen:									[out]  ���ݳ���
//byAudioFlag:							[out]  ��Ƶ�������ͣ�0�����زɼ������ݣ�1���豸���͹�������������
//pUser:								[out]  �û�����ָ��
//����ֵ��                     ��
typedef void (CALLBACK *HYVoiceDataCallback)(LONG lVoiceComHandle, char *pData, int nLen, BYTE byAudioFlag, void *pUser);

//�������ã��������ݻص�����
//����
//lDownloadHandle:      [out]  ���ؾ����HYRemoteGetFileByTime�ķ���ֵ
//pStream:				[out]  ��������(��ʽΪtagStreamHeaderͷ + ������)
//nLen:					[out]  ���ݳ���
//nFrameType:			[out]  ֡��������(0: Audio, 1: Header, 2: V-I, 3: V-P, 4: V-B, 5: ������)
//pUser:				[out]  �û�����ָ��
//���أ���
typedef void(CALLBACK *HYDownloadDataCallBack)(LONG lDownloadHandle, BYTE *pStream, int nLen, int nFrameType, void *pUser);


//�������ã���ʼ��sdk
//����
//��
//���أ�������
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYIpcInit(); 

//�������ã��ͷ�sdk
//����
//��
//���أ�������
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYIpcClean(); 

//�������ã����ý�����������ַ
//����
//szIp:            [in]  ����������ip
//wPort:           [in]  �����������˿�
//���أ�           [out] ������
extern "C" /*__declspec(dllexport)*/ void  WINAPI  HYSetIpSvrAddr(char *szIp, WORD wPort);

//�������ã���ip��������ѯip
//����
//szNo:            [in]  �豸���к�
//szOutIp:         [out] �豸����ip
//szInIp:          [out] �豸����ip
//pPort:           [out] �豸�˿�
//���أ�           [out] ������
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYGetIPByResolveSvr(char *szNo, char *szOutIp, char *szInIp, WORD *pPort);

//�������ã����õ�¼��ʱ
//����   
//nWaitTime:       [in]  ÿ�ε�¼��ʱʱ��(��λ����)
//nTryTimes:       [in]  ����½����
//���أ� ������
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYSetConnectTimeout(int nWaitTime, int nTryTimes);

//�������ã����ö�������
//����
//bEnable:          [in]  �Ƿ��������
//nReconInterval:   [in]  �����������ʱ�䣨��λ����)
//���أ� ������
extern "C" /*__declspec(dllexport)*/ void  WINAPI  HYSetReconnect(BOOL bEnable, int nReconInterval);

//�������ã�������Ϣ�ص�
//����
//szIp:             [out] �豸ip
//wCmd:             [out] ��������(��Э�飩
//pData:            [out] ������ϸ��Ϣ
//nDataLen:         [out] ������ϸ��Ϣ����
//���أ� ��
typedef void (CALLBACK *CallbackAlarmInfo) (char* szIp, unsigned short wCmd, char* pData, int nDataLen);

//�������ã�����һ����������(�ɴ����������)
//����
//wPort:            [in] ������������˿�
//���أ�            [out]������
extern "C" /*__declspec(dllexport)*/  int WINAPI HYCreateAlarmService(unsigned short wPort);                        

//�������ã��ر�һ����������
//����
//wPort:            [in] ������������˿�
//���أ�            [out]������
extern "C" /*__declspec(dllexport)*/  int WINAPI HYCloseAlarmService(unsigned short wPort);                          

//�������ã�ע�ᱨ������ص�
//����
//lpfnCallbackAlarm:[in] ���ձ�����Ϣ�ص�����
//���أ�                 ��
void WINAPI RegAlarmCallback(CallbackAlarmInfo lpfnCallbackAlarm);             //�����ص� 

//�������ã���¼�豸(ֻ֧�ֵ�¼64��)
//����
//szDevId:          [in]  �豸id(�豸����ʱʹ�ã� ΪNULL��ʾֱ�ӱ�ʾֱ������pIpInfo���������� �������ѯip��������������) 
//szIp:             [in]  �豸ip 
//wPort:            [in]  �豸ͨ�Ŷ˿�
//szUserName:       [in]  �豸�û���(���9��CHAR)
//szPwd:            [in]  �豸����(���32��CHAR) 
//pLimit:           [out] ���û�����Ӧ��Ȩ��
//���أ�            [out] -1��ʾʧ�ܣ�����ֵ��ΪHYLogoutIPC�Ⱥ����Ĳ�������ȡ���������HYGetLastError
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYLoginIPC(char *szDevId, char *szIp, WORD wPort, 
															 char *szUserName, char *szPwd,unsigned char *pLimit);

//�������ã�ע����½
//����
//nLogin:           [in]  ��¼�����HYLoginIPC�ķ���ֵ��
//���أ� ������
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYLogoutIPC(int nLogin);

//�������ã��豸���߻ص�
//����
//onLine:           [out]  �豸����״̬�ص�����
//���أ� ������
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYOnLineRegister(HYIPCOnlineState onLine);

//�������ã������豸����
//����
//nLogin:           [in]  ��¼�����HYLoginIPC�ķ���ֵ��
//wCmd:             [in]  �����豸ָ���Э�飩
//pData:            [in]  ָ������
//nDataLen:         [in]  pData�ĳ���
//���أ� ������
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYControlSet(int nLogin, WORD wCmd, char *pData, int nDataLen); 

//�������ã������豸����(��չ)
//����
//nLogin:           [in]  ��¼�����HYLoginIPC�ķ���ֵ��
//wCmd:             [in]  �����豸ָ���Э�飩
//pData:            [in]  ָ������
//nDataLen:         [in]  pData�ĳ���
//nChannel:         [in]  ͨ����
//���أ� ������
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYControlSetEx(int nLogin, WORD wCmd, char *pData, int nDataLen, int nChannel = 0); 

//�������ã���ȡ�豸����
//����
//nHandle:          [in]  ��¼�ɹ��󷵻ص��豸�����
//wCmd:             [in]  ��ȡ�豸ָ���Э�飩
//pSendData:        [in]  ��������buffer
//nSendDataLen:     [in]  �������ݳ���
//pReturnBuf:       [in, out] ��������buff
//nReturnBufLen��   [out] ����ʵ����Ҫ��ָ���
//���أ� ������
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYControlGet(int nHandle,unsigned short wCmd,char *pSendData,int nSendDataLen
																  ,char *pReturnBuf,int nReturnBufLen);

//�������ã���ȡ�豸����(��չ)
//����
//nHandle:          [in]  ��¼�ɹ��󷵻ص��豸�����
//wCmd:             [in]  ��ȡ�豸ָ���Э�飩
//pSendData:        [in]  ��������buffer
//nSendDataLen:     [in]  �������ݳ���
//pReturnBuf:       [in, out] ��������buff
//nReturnBufLen��   [out] ����ʵ����Ҫ��ָ���
//���أ� ������
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYControlGetEx(int nHandle,unsigned short wCmd,char *pSendData,int nSendDataLen
																  ,char *pReturnBuf,int nReturnBufLen, int nChannel = 0);

//�������ã�ע�������ص�
//����
//Media:            [out]  �������ݻص�������
//���أ� ������
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYMediaRegister(HYMediaStreamInfo Media);

//�������ã�ע�������ص�(��չ)
//����
//Media:            [out]  �������ݻص�������
//���أ� ������
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYMediaRegisterEx(HYMediaStreamInfoEx MediaEx);

//�������ã������������Ĵ�������Ϣ
//����
//nErrorCode:   [in]  ������룬HYGetLastError����ֵ��
//���أ�        [out] ������Ϣ�ַ�����
extern "C" /*__declspec(dllexport)*/ char*  WINAPI  HYGetErrorMsg(int nErrorCode);

//�������ã�������Ƶ����
//����
//nLogin:       [in]  ��¼�����HYLoginIPC�ķ���ֵ��
//nChannel:     [in]  �豸ͨ����
//nKindofStream:[in]  �������ࣨ0�� �������� 1�� ������)
//wRecvPort:    [in]  ���ն˿�
//���أ�        [out] -1��ʾʧ�ܣ�����ֵ��ΪHYStopPlayBack�Ⱥ����Ĳ�������ȡ���������HYGetLastError
extern "C" /*__declspec(dllexport)*/ LONG  WINAPI HYRequestStream(int nLogin, int nChannel, int nKindofStream, WORD wRecvPort); 

//�������ã��ر���Ƶ����
//����
//reqStream:    [in]  ���������HYRequestStream�ķ���ֵ��
//���أ�        [out] -1��ʾʧ�ܣ�����ֵ��ΪHYStopPlayBack�Ⱥ����Ĳ�������ȡ���������HYGetLastError
extern "C" /*__declspec(dllexport)*/ BOOL  WINAPI HYCloseStream(LONG lStream);

//�������ã���ȡ�������Ĵ�����
//����
//���أ�        [out] �������Ĵ����롣
extern "C" /*__declspec(dllexport)*/ int  WINAPI HYGetLastError();

//�������ã�������������
//����
//lStream:      [in]  HYRequestStream����ֵ��
//���أ�        [out] �ɹ�ΪTRUE�� ʧ��ΪFALSE
extern "C" /*__declspec(dllexport)*/ BOOL  WINAPI HYRequestSoundStream(LONG lStream); 

//�������ã�������������(��չ)
//����
//lStream:      [in]  HYRequestStream����ֵ��
//���أ�        [out] �ɹ�ΪTRUE�� ʧ��ΪFALSE
extern "C" /*__declspec(dllexport)*/ BOOL  WINAPI HYRequestSoundStreamEx(LONG lStream, int nChannel = 0); 

//�������ã��ر���������
//����
//lStream:      [in]  HYRequestStream����ֵ��
//���أ�        [out] ��
extern "C" /*__declspec(dllexport)*/ void  WINAPI HYCloseSoundStream(LONG lStream); 

//�������ã������ļ����͡�ʱ������豸¼���ļ�
//����
//nLogin:           [in]  ��¼�����HYLoginIPC�ķ���ֵ
//pFindCond:        [in]  �����ҵ��ļ�������Ϣ�ṹ
//���أ�            [out] -1��ʾʧ�ܣ�����ֵ��ΪHYRemoteFindNextFile��HYRemoteFindClose�Ⱥ����Ĳ�������ȡ���������HYGetLastError
extern "C" /*__declspec(dllexport)*/ LONG  WINAPI  HYRemoteFindFile(int nLogin, LPFILE_COND lpFindCond); 

//�������ã���ȡ���ҵ����ļ���Ϣ
//����
//nFindHandle:      [in]  �ļ����Ҿ����HYRemoteFindFile�ķ���ֵ
//lpFindData:       [out]  �����ļ���Ϣ��ָ��
//���أ�            [out] -1��ʾʧ�ܣ�����ֵ��ʾ��ǰ�Ļ�ȡ״̬����Ϣ(��ȡ�ļ���Ϣ�ɹ���δ���ҵ��ļ������ڲ�����ȴ���û�и�����ļ������ҽ����������ļ�ʱ�쳣)����ȡ���������HYGetLastError
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYRemoteFindNextFile(LONG lFindHandle, LPFIND_DATA lpFindData); 

//�������ã��ر��ļ����ң��ͷ���Դ
//����
//nFindHandle:      [in]  �ļ����Ҿ��HYRemoteFindFile�ķ���ֵ
//���أ�            [out] TRUE��ʾ�ɹ���FALSE��ʾʧ�ܡ���ȡ���������HYGetLastError
extern "C" /*__declspec(dllexport)*/ BOOL  WINAPI  HYRemoteFindClose(LONG lFindHandle); 

//�������ã���ʱ��ط�Զ��¼���ļ�
//����
//nLogin:       [in]  ��¼�����HYLoginIPC�ķ���ֵ��
//pVodPara:     [in]  �ط�����
//���أ�        [out] �����-1��ʾʧ�ܣ�����ֵ��ΪHYRemotePlayBackControl��HYStopRemotePlayBack�Ⱥ����Ĳ�������ȡ���������HYGetLastError��
extern "C" /*__declspec(dllexport)*/ LONG  WINAPI HYRemotePlayBackByTime(int nLogin, LPVOD_PARA pVodPara); 

//����˵��: Զ��¼��طſ��ơ�
//����
//lPlayBackHandle:       [in]  HYRemotePlayBackByTime���صľ��
//dwControlCode          [in]  ��ȡ�豸ָ���Э�飩
//pInBuffer:			 [in]  ��������buffer
//dwInLen:				 [in]  �������ݳ���
//pOutBuffer:			 [in, out] ��������buff
//lpOutLen��			 [out] ����ʵ����Ҫ�����ݳ���ָ��
//����ֵ��                �Ƿ�����ɹ�
extern "C" /*__declspec(dllexport)*/ BOOL WINAPI HYRemotePlayBackControl(LONG lPlayHandle, DWORD dwControlCode,char *pInBuffer, DWORD dwInLen, char *pOutBuffer,DWORD *lpOutLen);

//����˵��: ֹͣԶ��¼��طš�
//����
//lPlayHandle:       [in]  HYRemotePlayBackByTime���صľ��
//����ֵ��                �Ƿ�����ɹ�
extern "C" /*__declspec(dllexport)*/ BOOL WINAPI HYStopRemotePlayBack(LONG lPlayHandle);

//����˵��: Զ��¼��ط�ץͼ��
//����
//lPlayHandle:       [in]  HYRemotePlayBackByTime���صľ��
//szFileName:        [in]   ץͼ�ļ�����·��
//����ֵ��                �Ƿ�����ɹ�
extern "C" /*__declspec(dllexport)*/ BOOL WINAPI HYRemotePlayBackCaptureFile(LONG lPlayHandle,char *szFileName);

//�������ã���ʱ������Զ��¼���ļ�
//����
//nLogin:				[in]  ��¼�����HYLoginIPC�ķ���ֵ��
//pSavedFileName		[in] ���غ󱣴浽PC�����ļ�·������Ϊ����·�� 
//pVodPara:				[in]  �ط�����
//���أ�				[out] ���ؾ����-1��ʾʧ�ܣ�����ֵ��ΪHYRemotePlayBackControl��HYStopRemoteGetFile�Ⱥ����Ĳ�������ȡ���������HYGetLastError��
extern "C" /*__declspec(dllexport)*/ LONG  WINAPI HYRemoteGetFileByTime(int nLogin, char *pSavedFileName, LPVOD_PARA pVodPara); 

//����˵��: ֹͣ����¼���ļ���
//����
//lPlayHandle:			[in] �طž�������ž����HYRemoteGetFileByName��HYRemoteGetFileByTime�ķ���ֵ
//����ֵ��                �Ƿ�����ɹ�
extern "C" /*__declspec(dllexport)*/ BOOL WINAPI HYStopRemoteGetFile(LONG lPlayHandle);

//�������ã�ע�����ػص�
//����
//lPlayHandle:							[in] �ط����ؾ����HYRemoteGetFileByTime�ķ���ֵ
//cbDownloadDataCallBack:				[in]  �������ݻص�������
//pUser:								[in]  �û�����ָ��
//���أ� �Ƿ�����ɹ�
extern "C" /*__declspec(dllexport)*/ BOOL  WINAPI  HYSetDownloadDataCallBack(LONG lPlayHandle, HYDownloadDataCallBack cbDownloadDataCallBack, void *pUser);


//�������ã��������������豸��־
//����
//nLogin:           [in]  ��¼�����HYLoginIPC�ķ���ֵ
//lpLogCond:        [in]  ����������Ϣ�ṹ
//���أ�            [out] -1��ʾʧ�ܣ�����ֵ��ΪHYRemoteFindNextFile��HYRemoteFindClose�Ⱥ����Ĳ�������ȡ���������HYGetLastError
extern "C" /*__declspec(dllexport)*/ LONG  WINAPI  HYFindLog(int nLogin, LPHY_LOG_COND lpLogCond); 

//�������ã�������ȡ���ҵ�����־��Ϣ
//����
//lFindLogHandle:	[in]  ��־���Ҿ����HYFindLog�ķ���ֵ
//lpLogData:		[out]  ������־��Ϣ��ָ��
//���أ�            [out] -1��ʾʧ�ܡ���ȡ���������HYGetLastError
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYFindNextLog(LONG lFindLogHandle, LPHY_LOG_DATA lpLogData); 

//�������ã��ر���־���ң��ͷ���Դ
//����
//lFindLogHandle:	[in]  �ļ����Ҿ��HYFindLog�ķ���ֵ
//���أ�            [out] TRUE��ʾ�ɹ���FALSE��ʾʧ�ܡ���ȡ���������HYGetLastError
extern "C" /*__declspec(dllexport)*/ BOOL  WINAPI  HYFindLogClose(LONG lFindLogHandle); 

//����˵��: ��Ԥ��ץͼ
//����
//nLogin:				[in]	��¼�����HYLoginIPC�ķ���ֵ
//nChannel:				[in]	�豸ͨ����
//szFileName:           [in]	ץͼ�ļ�����·��(����·��)
//����ֵ��              [out]	�Ƿ�ɹ�
extern "C" /*__declspec(dllexport)*/  BOOL  WINAPI   HYSnapshot(int nLogin, int nChannel, LPHY_SNAPSHOT_PARA lpSnapshotPara, char *szFileName);

//����˵��: ��ʼԶ�������豸�̼�
//����
//nLogin:				[in]	��¼�����HYLoginIPC�ķ���ֵ
//nImgType:				[in]	�����ļ����� UPGRADE_IMG_TYPE
//szFileName:           [in]	�����ļ�����·��
//����ֵ��              [out]	�Ƿ�ɹ�
extern "C" /*__declspec(dllexport)*/  BOOL  WINAPI   HYStartUpgrade(int nLogin, int nImgType, char *szFileName);

//�������ã��豸���߻ص�
//����
//cbUpgrade:           [out]  �������Ȼص�����
//���أ� ������
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYUpgradeRegister(HYUpgradeCallBack cbUpgrade);

//�������ã����������Խ�
//����
//nLogin:           [in]  ��¼�����HYLoginIPC�ķ���ֵ
//nVoiceChannel:    [in]  ����ͨ���š������豸����������Խ�ͨ��Ϊ0
//pUser:			[in]  �û�����ָ��
//���أ�            [out] -1��ʾʧ�ܣ�����ֵ��ΪHYStopVoiceCom�Ⱥ����Ĳ�������ȡ���������HYGetLastError
extern "C" /*__declspec(dllexport)*/ LONG  WINAPI  HYStartVoiceCom(int nLogin, int nVoiceChannel, void *pUser); 

//�������ã���������ת��
//����
//nLogin:           [in]  ��¼�����HYLoginIPC�ķ���ֵ
//nVoiceChannel:    [in]  ����ͨ���š������豸����������Խ�ͨ��Ϊ0
//pUser:			[in]  �û�����ָ��
//���أ�            [out] -1��ʾʧ�ܣ�����ֵ��ΪHYStopVoiceCom�Ⱥ����Ĳ�������ȡ���������HYGetLastError
extern "C" /*__declspec(dllexport)*/ LONG  WINAPI  HYStartVoiceComMR(int nLogin, int nVoiceChannel, void *pUser); 

//����˵��: ת����������
//����
//lVoiceComHandle:						[in]  HYStartVoiceComMR�ķ���ֵ
//pSendData:							[in]  ��Ƶ����(PCM������Ƶ��Ϊ8000��16λ,����ͨ��)
//nDataLen:								[in]  ���ݳ���
//pUser:								[in]  �û�����ָ��
//����ֵ��                     ��
extern "C" /*__declspec(dllexport)*/ BOOL  WINAPI  HYVoiceComSendData(LONG lVoiceComHandle, char *pSendData, int nDataLen, void *pUser);

//�������ã����������Խ���ת��
//����
//lVoiceComHandle:  [in]  HYStartVoiceCom�ķ���ֵ
//���أ�            [out] �Ƿ�ɹ�����ȡ���������HYGetLastError
extern "C" /*__declspec(dllexport)*/ BOOL  WINAPI  HYStopVoiceCom(LONG lVoiceComHandle); 

//����˵��: ע��Խ���Ƶ���ݻص���
//����
//bNeedCBNoEncData:			[in]  ��Ҫ�ص��������������ͣ�0- �������������ݣ�1- ����ǰ��PCMԭʼ����
//lpfnDecodeData:			[in]  �������ݻص��ӿ�
//pUser:					[in]  �û�����ָ��
//����ֵ��					[out] ��
extern "C" /*__declspec(dllexport)*/ void   WINAPI	 HYRegVoiceComDataCallback(BOOL bNeedCBNoEncData, HYVoiceDataCallback lpfnVoiceData, void *pUser);

#endif