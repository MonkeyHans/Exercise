
#pragma once

//���ػطſ���ָ��
enum{PLAYSTART = 0, PLAYPAUSE, PLAYRESTART, PLAYFAST, PLAYSLOW, PLAYNORMAL, PLAYFRAME, PLAYSTARTAUDIO, PLAYSTOPAUDIO,
	 PLAYAUDIOVOLUME, PLAYSETPOS, PLAYGETPOS, PLAYGETTIME, PLAYGETFRAME, PLAYSETFRAME, GETTOTALFRAMES, GETTOTALTIME};

//���ý���������ģʽ�� Ĭ����STREAM_PLAY_MODE(��ģʽ��
enum{STREAM_PLAY_MODE = 0/*��ģʽ*/, FILE_PLAY_MODE/*�ļ�ģʽ*/, FRAME_PLAY_MODE/*��֡ģʽ(�ݲ�֧��)*/};

//�ط��ļ�����Ϣ��
enum{PLAY_START = 0, PLAY_PAUSE, PLAY_CONTINUE, PLAY_FINISH};

#ifndef HY_ERROR
#define HY_ERROR

//������
enum{
	E_OK = 0,       
	E_UNKNOWN,
	E_SDK_BASE = 100,       //sdk����ʼ��
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
	E_UNSUPPORT,			//��֧��(�Ƿ�����)
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

#define MAX_MOTION_NUM 16
#define MOTION_DETECT_PRECISION	16		//// the precision of the 22*11 detect unit under D1(704*576) resolution is 32*32, in the demothepicture is displayed in cif(352*288), and precision/2
#define MOTION_RESOLUTION_WIDTH		352
#define MOTION_RESOLUTION_HEIGHT	288

typedef struct
{
	RECT rcArea;
	BYTE bySensitivity;			//0-,0-Ϊ����⣬��ֵԽ�󼶱�Խ��
	BYTE byRes[3];				//����
}MOTION_DETECT_INFO;


//����˵��: ���ز���״̬�ص�
//����
//lPaybackHandle:       [out]  HYOpenPlayBack���صľ��
//nState:               [out]  �ط�״̬(0: ��ʼ���ţ� 1�� ��ͣ, 2: ����, 3: ���)
//����ֵ��                     ��
typedef void (CALLBACK *PaybackCallback)(LONG lPaybackHandle, int nState);

//����˵��: �������ݻص��ӿ�
//����
//pY:                   [out]  yuv��ʽ��y����
//pU:                   [out]  yuv��ʽ��u����
//pV:                   [out]  yuv��ʽ��v����
//nWidth:               [out]  yuv��ʽ�ֱ��ʵĿ��
//nHeight:              [out]  yuv��ʽ�ֱ��ʵĸ߶�
//����ֵ��                     ��
typedef void (CALLBACK *CallbackDecodeData)(LONG  lDecoderHandle, char *pY, char *pU, char *pV, int nYStride, int nUVStride, int nWidth, int nHeight);

//����˵��: �������ݻص��ӿڣ���չ��
//����
//lDecoderHandle:					[out] ���������
//pData:										[out]  yuv����
//nLen:										[out]  ���ݳ���
//pFrameInfo:							[out]  ֡��Ϣ
//����ֵ��                     ��
typedef void (CALLBACK *CallbackDecodeDataEx)(LONG  lDecoderHandle, char *pData, int nLen, HY_FRAME_INFO* pFrameInfo);

//����˵��: ����������ʾ����
//����
//hWnd:                 [in]   ���Ŵ��ھ��
//����ֵ��              [out]  -1��ʾʧ�ܣ�����ֵ��ΪHYCloseReal�Ⱥ����ľ����������ȡ���������HYGetLastError
extern "C"   long WINAPI   HYCreateReal(HWND hWnd);

//����˵��: д��ʵʱ��������������ʾ���������ʾ
//����
//hDecoder:             [in]   ������ʾ������, ��HYCreateReal�ķ���ֵ.
//pData:                [in]   ������ʾ����buff
//nDataLen:             [in]   pData�����ݳ���
//����ֵ��              [out]  �����Ѿ�����ĳ���
extern "C"   int  WINAPI   HYWriteReal(long hDecoder,unsigned char *pData, int nDataLen);

//����˵��: �ر�ʵʱ������ʾ
//����
//hDecoder:             [in]   ������ʾ������, ��HYCreateReal�ķ���ֵ.
//����ֵ��              [out]  TRUE��ʾ�ɹ���FALSE��ʾʧ�ܡ���ȡ���������HYGetLastError
extern "C"	 BOOL  WINAPI	 HYCloseReal(long hDecoder);

//����˵��: ʵʱץͼ
//����
//hDecoder:             [in]   ������ʾ������, ��HYCreateReal�ķ���ֵ.
//szFileName:           [in]   ץͼ�ļ�����·��
//����ֵ��              [out]  ��
extern "C"   void  WINAPI   HYAcquireRealPicture(long hDecoder,char *szFileName);

//����˵��: �ط�ץͼ
//����
//lPlayHandle:          [in]   HYOpenPlayBack���صľ��
//szFileName:           [in]   ץͼ�ļ�����·��
//����ֵ��              [out]  ��
extern "C"   void  WINAPI   HYAcquirePlaybackPicture(long lPlayHandle,char *szFileName);

//����˵��: �򿪻طŲ�����
//����
//lPlayBackHandle��     [in]   ���ž��(һ��Ҫ����)
//hWnd:                 [in]   ���Ŵ��ھ��
//����ֵ��              [out]  -1��ʾʧ�ܣ�����ֵ��ΪHYStopPlayBack�Ⱥ����Ĳ�������ȡ���������HYGetLastError
extern "C"   BOOL  WINAPI   HYOpenPlayBack(LONG  lPlayBackHandle, HWND hWnd);

//����˵��: �رջط�
//����
//lPlayHandle:          [in]   HYOpenPlayBack���صľ��
//����ֵ��              [out]  ��
extern "C"   void  WINAPI   HYClosePlayBack(LONG  lPlayBackHandle);

//����˵��: ֹͣ�ط�¼���ļ�
//����
//lPlayHandle:          [in]   HYOpenPlayBack���صľ��
//����ֵ��              [out]  ��
extern "C"  void WINAPI HYStopPlayBack(LONG  lPlayBackHandle);

//����˵��: ��ʼ�ط�¼���ļ�
//����
//szFileName:           [in]   �ļ���
//lPlayHandle:          [in]   HYOpenPlayBack���صľ��
//����ֵ��              [out]  ��
extern "C"  BOOL WINAPI HYBeginPlayBack(char *szFileName, LONG  lPlayHandle);

//����˵��: ��ͣ�ط�¼���ļ�
//����
//lPlayHandle:          [in]   HYOpenPlayBack���صľ��
//����ֵ��              [out]  ��
extern "C"   void   WINAPI   HYPausePlayBack(LONG  lPlayBackHandle);

//����˵��: �л�ʵʱ���Ŵ���
//����
//indentity:            [in]   ������ʾ������, ��HYCreateReal�ķ���ֵ.
//hNewWnd:              [in]   �´��ھ����ע����Ϊ0�� ��ʶֻ���벻��ʾ��
//����ֵ��              [out]  ԭ���Ĵ��ھ��
extern "C"   HWND WINAPI    HYChageRealWindow(long hDecoder, HWND hNewWnd);

//����˵���� ʹ����ȫ��(��ȫ��), ���벥����Ƶʱ����Ч
//����
//hWnd��     [in] ���ھ��
//����ֵ��   ��
extern "C"  void WINAPI HYFullScreen(HWND hWnd);

//����˵���� �Ǵ��ڴ�ȫ��״̬���ش���״̬
//����
//hWnd:      [in] ���ھ��
//����ֵ��   ��
extern "C" void WINAPI HYRestoreScreen(HWND hWnd);

typedef void (CALLBACK *CallbackFrame)(int nIndex, DWORD dwFrame);

extern "C"   void WINAPI   RegCallbackFrame(CallbackFrame lpfnCallbackFrame);

//����˵���� ����ͼ����ǿ
//����
//lDecoder:      [in] ������ʾ������, ��HYCreateReal�ķ���ֵ.
//bEn:           [in] �Ƿ���ǿ
//����ֵ��       ��
extern "C"   void WINAPI HYSetImgEn(LONG lDecoder, BOOL bEn);

//����˵���� ��ȡͼ����ǿ
//����
//lDecoder:      [in] ������ʾ������, ��HYCreateReal�ķ���ֵ.
//����ֵ��       [out]TRUE��ʾ�Ѿ��򿪵���ǿ�� ���ʾû�д�
extern "C"   BOOL WINAPI HYGetImgEn(LONG lDecoder);

//����˵��: ������
//����
//����ֵ��              [out]  TRUE��ʾ�ɹ��� FALSE��ʾʧ��
extern "C"   BOOL  WINAPI    HYOpenSound(LONG lDecode);

//����˵��: ���ý������
//����                  [in] ���������С��0-9��
//����ֵ��              [out]  ��
extern "C"   void  WINAPI    HYReduceNoise(BYTE bySize);

//����˵��: �ر�����
//����
//����ֵ��              [out]  TRUE��ʾ�ɹ��� FALSE��ʾʧ��
extern "C"   BOOL  WINAPI    HYCloseSound();

//����˵��: ע�᱾�ػط�״̬�ص�
//����
//lpfnDecodeData:       [in]   ���ز���״̬�ص��ӿ�
//����ֵ��              ��
extern "C"  void  WINAPI	 HYRegisterPayback(PaybackCallback lpfnDecodeData);

//����˵��: ����¼��طŵ�״̬��
//����
//lPlayBackHandle:       [in]  HYOpenPlayBack��HYCreateReal���صľ��
//dwControlCode:         [in]  ������PLAYSTART��ʼ�ĺ궨��
//dwInValue:             [in]  ���õĲ������������Ҫ��������ʱ�� ��ֵ������)
//����ֵ��                ��
extern "C"  DWORD WINAPI HYPlayBackControl(LONG  lPlayBackHandle, DWORD dwControlCode, DWORD dwInValue);

//����˵��: ����¼��طŵ�״̬(ֻ���ڲ�������֮ǰ���ú�ģʽ����
//����
//lPlayBackHandle:       [in]  ������ʾ������, ��HYCreateReal�ķ���ֵ
//nMode:                 [in]  ���������ý���������ģʽenumָ��
//����ֵ��               [out] ʵ��ִ�е�ģʽ
extern "C"  int   WINAPI	 HYSetStreamPlayMode(LONG  lDecoder,  int nMode);


//����˵��: ������һ֡(��ʱ��֧��)��
//����
//lDecoder:              [in]  ������ʾ������, ��HYCreateReal�ķ���ֵ
//����ֵ��               [out] ��
extern "C"  void   WINAPI	 HYPlayNextFrame(LONG  lDecoder);

//����˵��: ���ý������ݻص���
//����
//lpfnDecodeData:        [in]  �������ݻص��ӿڡ�
//����ֵ��               [out] ��
extern "C"  void   WINAPI	 HYRegDecodeData(CallbackDecodeData lpfnDecodeData);

//����˵��: ���ý������ݻص�(��չ)
//����
//lpfnDecodeDataEx:        [in]  �������ݻص��ӿڡ�
//����ֵ��               [out] ��
extern "C"  void   WINAPI	 HYRegDecodeDataEx(CallbackDecodeDataEx lpfnDecodeDataEx);

//����˵��: �����Ƿ���ʾ�ƶ�֡������
//����
//lDecoder:								[in]  ������ʾ������, ��HYCreateReal�ķ���ֵ
//bShow										[in]  �Ƿ���ʾ
//pMotionDetectInfo:				[in]  �ƶ�֡��������Ϣ
//iMotionDetectInfoCnt			[in]  �ƶ�֡��������ϢMOTION_DETECT_INFO��Ŀ
//byShowType							[in]	������ʾ����: 1��ʾ����2��ʾ����
//����ֵ:					[out] ��
extern "C"  void   WINAPI	 HYShowMotionDetectArea(LONG lDecoder, bool bShow, MOTION_DETECT_INFO* pMotionDetectInfo = NULL, int iMotionDetectInfoCnt = 0, BYTE byShowType = 1);

//����˵��:������ʾ����
//����
//lDecoder:					[in]  ������ʾ������, ��HYCreateReal�ķ���ֵ
//pSrcRect:					[in]  ����Ҫ��ʾ��ԭͼ���ϵ��������pSrcRect=NULL������ʾ����ͼ��
//����ֵ:							[out] �ɹ�����true, ʧ�ܷ���false
extern "C"   bool  WINAPI    HYSetDisplayRegion(LONG lDecoder, RECT *pSrcRect);

//����˵��: ��������
//����
//dwVolume:				[in]	������ȡֵ��Χ[0,0xffff]
//����ֵ��              [out]  TRUE��ʾ�ɹ��� FALSE��ʾʧ��
extern "C"   BOOL  WINAPI    HYSetVolume(DWORD dwVolume);

//����˵��: ��ȡ����
//����
//pdwVolume:			[in]	������ȡֵ��Χ[0,0xffff]
//����ֵ��              [out]  TRUE��ʾ�ɹ��� FALSE��ʾʧ��
extern "C"   BOOL  WINAPI    HYGetVolume(DWORD* pdwVolume);