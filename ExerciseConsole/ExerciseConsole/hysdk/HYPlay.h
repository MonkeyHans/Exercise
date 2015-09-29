
#pragma once

//本地回放控制指令
enum{PLAYSTART = 0, PLAYPAUSE, PLAYRESTART, PLAYFAST, PLAYSLOW, PLAYNORMAL, PLAYFRAME, PLAYSTARTAUDIO, PLAYSTOPAUDIO,
	 PLAYAUDIOVOLUME, PLAYSETPOS, PLAYGETPOS, PLAYGETTIME, PLAYGETFRAME, PLAYSETFRAME, GETTOTALFRAMES, GETTOTALTIME};

//设置解码器播放模式， 默认是STREAM_PLAY_MODE(流模式）
enum{STREAM_PLAY_MODE = 0/*流模式*/, FILE_PLAY_MODE/*文件模式*/, FRAME_PLAY_MODE/*单帧模式(暂不支持)*/};

//回放文件的消息宏
enum{PLAY_START = 0, PLAY_PAUSE, PLAY_CONTINUE, PLAY_FINISH};

#ifndef HY_ERROR
#define HY_ERROR

//错误码
enum{
	E_OK = 0,       
	E_UNKNOWN,
	E_SDK_BASE = 100,       //sdk的起始码
	E_NOABILITY,            //能力不足
	E_ALREADYEXIST,         //已经存在
	E_CREATESOCKET,         //创建socket失败
	E_SOCKETFAILED,         //socket错误
	E_NORESPONSE,           //没有应答
	E_MALLOCMEM,            //内存分配失败
	E_NOTFIND,              //找不到对应的设备
	E_INIT,                 //没有初始化好参数
	E_PARAM,                //参数错误
	E_RELOG,                //设备重连
	E_INVALIDSOCKET,        //无效socket句柄
	E_PORTINUSE,            //端口被占用
	E_UNSUPPORT_RESOLUTION, //不支持的分辨率
	E_NOT_OPEN,             //打开不了文件
	E_SOCKET_TIMEOUT,       //socket超时

	E_DEV_BASE = 1000,      //设备起始码
    E_STARTCODE,            //起始码错误
    E_ALREADY_LOGIN,        //已登录
    E_LOGIN_FAIL,           //登录失败
    E_VERSION,              //版本不够新
    E_SEQ,                  //丢包错误
    E_MEM,                  //内存分配失败
    E_AUTH,                 //权限不够
    E_VIDEOFULL,            //视频请求客户端数已满
    E_THREADCREAT,          //线程创建失败
    E_ADMIN_NOT_DELETED,    //admin不能删除
    E_MULOPEN,              //多次打开视频
    E_FAULT_VAL,            //数值超出范围	
	E_RESOL_WRONG,          //码流分辨率不支持
    E_BIG_LOGNUM,           //请求日志数太大，最大50条
    E_NOTREADY,             //采集器或编码器未就绪
    E_NO_VIDEO_CLOSE,       //没有可关闭的视频
    E_NO_OSD_DATA,          //没有OSD字体数据发送过来
    E_BUSY,                 //系统正忙于处理上次同样的指令
    E_PASSWD,               //密码错误
    E_NOTFOUND,             //用户名不存在
	E_WRONG_IMG_TYPE,		//升级文件镜像类型不合理 
	E_ERASEFLASH,			//擦flash错 
	E_WRITEFLASH,			//写flash错 
	E_CRC,					//CRC校验错 
	E_AUDIOFULL,			//同时监听人数已满 
	E_NO_LISTENER_STOP,		//没有可停止的监听 
	E_NOSPACE,				//没有多余空间存放新用户 
	E_NAMERR,				//不是本设备的升级文件
	E_UNSUPPORT,			//不支持(非法命令)
	E_NO_LOGIN,				//绕过登录操作
    E_NO_FILE_FOUND,		//检索不到文件
    E_SEARCHING,			//正在检索
    E_SEARCH_OVER,			//检索结束
    E_SEARCH_FAIL,			//检索出错
	E_LOGIN_USER_FULL,		//登录用户数已满
	E_INVALID_UPDATE_FILE,	//非法升级文件 
	E_UNSUPPORT_FUNC,		//功能不支持 
	E_NO_LOG_FOUND,			//没有日志
	E_UPDATE_FILE_TOO_BIG,	//升级文件过大，无法升级
};

#endif

#ifndef HY_PUBLIC
#define HY_PUBLIC

//Frame Info
typedef struct{
	int nType;									//数据类型
	UINT nStamp;							//时间戳
	int nWidth;								//画面宽，单位：像素
	int nHeight;								//画面高，单位：像素		
	int nFrameRate;						//帧率
	BYTE byRes1[8];						//保留字节
	int nChannels;							//声道数
	int nBitPerSample;					//采样位数
	int nSamplesPerSec;				//采样频率
	BYTE byRes2[8];						//保留字节
}HY_FRAME_INFO;

//码流数据类型
enum{
	FRAME_AUDIO	= 0,       //声音码流
	FRAME_HEADER,	       //码流头
	FRAME_VIDEO_I,	       //视频I帧
	FRAME_VIDEO_P,	       //视频P帧
	FRAME_VIDEO_B,	       //视频B帧
	NO_VIDEO		       //无码流数据
};

//解码后数据的帧类型
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
	BYTE bySensitivity;			//0-,0-为不检测，数值越大级别越高
	BYTE byRes[3];				//保留
}MOTION_DETECT_INFO;


//函数说明: 本地播放状态回调
//参数
//lPaybackHandle:       [out]  HYOpenPlayBack返回的句柄
//nState:               [out]  回放状态(0: 开始播放， 1： 暂停, 2: 继续, 3: 完成)
//返回值：                     无
typedef void (CALLBACK *PaybackCallback)(LONG lPaybackHandle, int nState);

//函数说明: 解码数据回调接口
//参数
//pY:                   [out]  yuv格式的y分量
//pU:                   [out]  yuv格式的u分量
//pV:                   [out]  yuv格式的v分量
//nWidth:               [out]  yuv格式分辨率的宽度
//nHeight:              [out]  yuv格式分辨率的高度
//返回值：                     无
typedef void (CALLBACK *CallbackDecodeData)(LONG  lDecoderHandle, char *pY, char *pU, char *pV, int nYStride, int nUVStride, int nWidth, int nHeight);

//函数说明: 解码数据回调接口（扩展）
//参数
//lDecoderHandle:					[out] 解码对象句柄
//pData:										[out]  yuv数据
//nLen:										[out]  数据长度
//pFrameInfo:							[out]  帧信息
//返回值：                     无
typedef void (CALLBACK *CallbackDecodeDataEx)(LONG  lDecoderHandle, char *pData, int nLen, HY_FRAME_INFO* pFrameInfo);

//函数说明: 创建解码显示对象
//参数
//hWnd:                 [in]   播放窗口句柄
//返回值：              [out]  -1表示失败，其他值作为HYCloseReal等函数的句柄参数。获取错误码调用HYGetLastError
extern "C"   long WINAPI   HYCreateReal(HWND hWnd);

//函数说明: 写入实时数据流到解码显示对象解码显示
//参数
//hDecoder:             [in]   解码显示对象句柄, 即HYCreateReal的返回值.
//pData:                [in]   解码显示数据buff
//nDataLen:             [in]   pData的数据长度
//返回值：              [out]  返回已经处理的长度
extern "C"   int  WINAPI   HYWriteReal(long hDecoder,unsigned char *pData, int nDataLen);

//函数说明: 关闭实时解码显示
//参数
//hDecoder:             [in]   解码显示对象句柄, 即HYCreateReal的返回值.
//返回值：              [out]  TRUE表示成功，FALSE表示失败。获取错误码调用HYGetLastError
extern "C"	 BOOL  WINAPI	 HYCloseReal(long hDecoder);

//函数说明: 实时抓图
//参数
//hDecoder:             [in]   解码显示对象句柄, 即HYCreateReal的返回值.
//szFileName:           [in]   抓图文件保存路径
//返回值：              [out]  无
extern "C"   void  WINAPI   HYAcquireRealPicture(long hDecoder,char *szFileName);

//函数说明: 回放抓图
//参数
//lPlayHandle:          [in]   HYOpenPlayBack返回的句柄
//szFileName:           [in]   抓图文件保存路径
//返回值：              [out]  无
extern "C"   void  WINAPI   HYAcquirePlaybackPicture(long lPlayHandle,char *szFileName);

//函数说明: 打开回放播放器
//参数
//lPlayBackHandle：     [in]   播放句柄(一定要大于)
//hWnd:                 [in]   播放窗口句柄
//返回值：              [out]  -1表示失败，其他值作为HYStopPlayBack等函数的参数。获取错误码调用HYGetLastError
extern "C"   BOOL  WINAPI   HYOpenPlayBack(LONG  lPlayBackHandle, HWND hWnd);

//函数说明: 关闭回放
//参数
//lPlayHandle:          [in]   HYOpenPlayBack返回的句柄
//返回值：              [out]  无
extern "C"   void  WINAPI   HYClosePlayBack(LONG  lPlayBackHandle);

//函数说明: 停止回放录像文件
//参数
//lPlayHandle:          [in]   HYOpenPlayBack返回的句柄
//返回值：              [out]  无
extern "C"  void WINAPI HYStopPlayBack(LONG  lPlayBackHandle);

//函数说明: 开始回放录像文件
//参数
//szFileName:           [in]   文件名
//lPlayHandle:          [in]   HYOpenPlayBack返回的句柄
//返回值：              [out]  无
extern "C"  BOOL WINAPI HYBeginPlayBack(char *szFileName, LONG  lPlayHandle);

//函数说明: 暂停回放录像文件
//参数
//lPlayHandle:          [in]   HYOpenPlayBack返回的句柄
//返回值：              [out]  无
extern "C"   void   WINAPI   HYPausePlayBack(LONG  lPlayBackHandle);

//函数说明: 切换实时播放窗口
//参数
//indentity:            [in]   解码显示对象句柄, 即HYCreateReal的返回值.
//hNewWnd:              [in]   新窗口句柄（注可以为0， 标识只解码不显示）
//返回值：              [out]  原来的窗口句柄
extern "C"   HWND WINAPI    HYChageRealWindow(long hDecoder, HWND hNewWnd);

//函数说明： 使窗口全屏(真全屏), 必须播放视频时才有效
//参数
//hWnd：     [in] 窗口句柄
//返回值：   无
extern "C"  void WINAPI HYFullScreen(HWND hWnd);

//函数说明： 是窗口从全屏状态返回窗口状态
//参数
//hWnd:      [in] 窗口句柄
//返回值：   无
extern "C" void WINAPI HYRestoreScreen(HWND hWnd);

typedef void (CALLBACK *CallbackFrame)(int nIndex, DWORD dwFrame);

extern "C"   void WINAPI   RegCallbackFrame(CallbackFrame lpfnCallbackFrame);

//函数说明： 设置图像增强
//参数
//lDecoder:      [in] 解码显示对象句柄, 即HYCreateReal的返回值.
//bEn:           [in] 是否增强
//返回值：       无
extern "C"   void WINAPI HYSetImgEn(LONG lDecoder, BOOL bEn);

//函数说明： 获取图像增强
//参数
//lDecoder:      [in] 解码显示对象句柄, 即HYCreateReal的返回值.
//返回值：       [out]TRUE表示已经打开的增强， 否表示没有打开
extern "C"   BOOL WINAPI HYGetImgEn(LONG lDecoder);

//函数说明: 打开声音
//参数
//返回值：              [out]  TRUE表示成功， FALSE表示失败
extern "C"   BOOL  WINAPI    HYOpenSound(LONG lDecode);

//函数说明: 设置降噪参数
//参数                  [in] 降噪参数大小（0-9）
//返回值：              [out]  无
extern "C"   void  WINAPI    HYReduceNoise(BYTE bySize);

//函数说明: 关闭声音
//参数
//返回值：              [out]  TRUE表示成功， FALSE表示失败
extern "C"   BOOL  WINAPI    HYCloseSound();

//函数说明: 注册本地回放状态回调
//参数
//lpfnDecodeData:       [in]   本地播放状态回调接口
//返回值：              无
extern "C"  void  WINAPI	 HYRegisterPayback(PaybackCallback lpfnDecodeData);

//函数说明: 控制录像回放的状态。
//参数
//lPlayBackHandle:       [in]  HYOpenPlayBack或HYCreateReal返回的句柄
//dwControlCode:         [in]  见上面PLAYSTART开始的宏定义
//dwInValue:             [in]  设置的参数（如果不需要参数设置时， 该值被忽略)
//返回值：                无
extern "C"  DWORD WINAPI HYPlayBackControl(LONG  lPlayBackHandle, DWORD dwControlCode, DWORD dwInValue);

//函数说明: 控制录像回放的状态(只能在播放数据之前设置好模式）。
//参数
//lPlayBackHandle:       [in]  解码显示对象句柄, 即HYCreateReal的返回值
//nMode:                 [in]  见上面设置解码器播放模式enum指令
//返回值：               [out] 实际执行的模式
extern "C"  int   WINAPI	 HYSetStreamPlayMode(LONG  lDecoder,  int nMode);


//函数说明: 播放下一帧(暂时不支持)。
//参数
//lDecoder:              [in]  解码显示对象句柄, 即HYCreateReal的返回值
//返回值：               [out] 无
extern "C"  void   WINAPI	 HYPlayNextFrame(LONG  lDecoder);

//函数说明: 设置解码数据回调。
//参数
//lpfnDecodeData:        [in]  解码数据回调接口。
//返回值：               [out] 无
extern "C"  void   WINAPI	 HYRegDecodeData(CallbackDecodeData lpfnDecodeData);

//函数说明: 设置解码数据回调(扩展)
//参数
//lpfnDecodeDataEx:        [in]  解码数据回调接口。
//返回值：               [out] 无
extern "C"  void   WINAPI	 HYRegDecodeDataEx(CallbackDecodeDataEx lpfnDecodeDataEx);

//函数说明: 设置是否显示移动帧测区域。
//参数
//lDecoder:								[in]  解码显示对象句柄, 即HYCreateReal的返回值
//bShow										[in]  是否显示
//pMotionDetectInfo:				[in]  移动帧测区域信息
//iMotionDetectInfoCnt			[in]  移动帧测区域信息MOTION_DETECT_INFO数目
//byShowType							[in]	区域显示类型: 1表示网格，2表示矩形
//返回值:					[out] 无
extern "C"  void   WINAPI	 HYShowMotionDetectArea(LONG lDecoder, bool bShow, MOTION_DETECT_INFO* pMotionDetectInfo = NULL, int iMotionDetectInfoCnt = 0, BYTE byShowType = 1);

//函数说明:设置显示区域
//参数
//lDecoder:					[in]  解码显示对象句柄, 即HYCreateReal的返回值
//pSrcRect:					[in]  设置要显示的原图像上的区域，如果pSrcRect=NULL，将显示整个图像。
//返回值:							[out] 成功返回true, 失败返回false
extern "C"   bool  WINAPI    HYSetDisplayRegion(LONG lDecoder, RECT *pSrcRect);

//函数说明: 设置音量
//参数
//dwVolume:				[in]	音量，取值范围[0,0xffff]
//返回值：              [out]  TRUE表示成功， FALSE表示失败
extern "C"   BOOL  WINAPI    HYSetVolume(DWORD dwVolume);

//函数说明: 获取音量
//参数
//pdwVolume:			[in]	音量，取值范围[0,0xffff]
//返回值：              [out]  TRUE表示成功， FALSE表示失败
extern "C"   BOOL  WINAPI    HYGetVolume(DWORD* pdwVolume);