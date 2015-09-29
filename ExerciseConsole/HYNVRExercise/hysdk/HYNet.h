/************************************************************
  Copyright (C), 1988-1999, Haoyun Tech. Co., Ltd.
  FileName: HYNet.h  
  Author:        Version :          Date:
  李双全         1.0                11-04-09
  Description:     记录日志     
  Version:         1.0
  Function List:   // 主要函数及其功能
    1. -------
  History:         // 历史修改记录
      <author>  <time>   <version >   <desc>
      Lsq       11/04/09 1.0          build this moudle 
***********************************************************/

#ifndef _HY_NET_
#define _HY_NET_

#ifndef HY_ERROR
#define HY_ERROR

enum{
	E_OK = 0,               //成功
	E_UNKNOWN,              //未知错误
	E_SDK_BASE = 100,       //sdk错误码的起始码
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
	E_SYSTEM_BUSY,			//系统忙

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
	E_UNSUPPORT,			//非法命令
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

#define MAX_USER			20			//设备支持的最大用户数
#define MAX_CHAN_NUM		64			//最大通道号
#define MAX_STREAM_NUM		2			//最大码流数量,包括主码流
#define MAX_DISKNUM			35			//最大硬盘数

//配置命令
#define CONFIG_SYS_DEVICE			(CONFIG_BASE | 0x1)		//设备参数配置
#define CONFIG_OSD					(CONFIG_BASE | 0x2)		//OSD参数配置
#define CONFIG_SOUND				(CONFIG_BASE | 0x3)		//音频参数配置
#define CONFIG_VEDIO				(CONFIG_BASE | 0x4)		//视频参数配置
#define CONFIG_ALARM_MOVE			(CONFIG_BASE | 0x5)		//移动侦测报警配置
#define CONFIG_ALARM_PROBE			(CONFIG_BASE | 0x6)		//探头报警配置
#define CONFIG_ALARM_NET			(CONFIG_BASE | 0x7)		//网络故障报警配置
#define CONFIG_NETWORK				(CONFIG_BASE | 0x8)		//网络参数配置
#define CONFIG_WIRELESS				(CONFIG_BASE | 0x9)		//无线网络参数配置
#define CONFIG_DDNS					(CONFIG_BASE | 0xA)		//DDNS参数配置
#define CONFIG_PPPOE				(CONFIG_BASE | 0xB)		//PPPOE参数配置
#define CONFIG_BLOCK				(CONFIG_BASE | 0xC)		//遮挡报警配置
#define CONFIG_USER					(CONFIG_BASE | 0xD)		//用户参数配置
#define CONFIG_ALARM_CENTER			(CONFIG_BASE | 0xE)		//报警中心配置
#define CONFIG_SYS_TIME				(CONFIG_BASE | 0xF)		//系统时间配置
//									(CONFIG_BASE | 0x10)
#define CONFIG_LOW_LIGHT			(CONFIG_BASE | 0x11)	//低照度配置
#define CONFIG_BACK_LIGHT			(CONFIG_BASE | 0x12)	//背光补偿配置
#define CONFIG_VIDEO_EX				(CONFIG_BASE | 0x13)	//宽动态设置
#define CONFIG_IMAGE_EX				(CONFIG_BASE | 0x14)	//图像扩展
#define CONFIG_SCENE				(CONFIG_BASE | 0x15)	//图像场景
#define CONFIG_NETWORK_EX			(CONFIG_BASE | 0x16)	//网络参数配置(扩展)
#define CONFIG_IR_EXPOSURE_PROTECT	(CONFIG_BASE | 0x17)	//设置红外防过曝
#define CONFIG_IMAGE				(CONFIG_BASE | 0x18)	//设置图像效果(注：原用CONTROL_IMAGE)
#define CONFIG_CHANNEL_NAME			(CONFIG_BASE | 0x19)	//设置通道名称
#define CONFIG_SYS_TIME_EX			(CONFIG_BASE | 0x1A)	//系统时间配置(扩展)
#define CONFIG_VIDEO_ENC_INFO		(CONFIG_BASE | 0x1B)	//视频编码参数配置
#define CONFIG_HIDE_AREAS			(CONFIG_BASE | 0x1C)	//视频遮盖区域配置
#define CONFIG_RECORD_STATE			(CONFIG_BASE | 0x1D)	//手动设置录像状态
#define	CONFIG_IO_ALARMOUT_STATE	(CONFIG_BASE | 0x1E)	//设置IO报警输出
#define CONFIG_FACE_AREAS			(CONFIG_BASE | 0x1F)	//设置人脸叠加区域
#define CONFIG_FACE_EFFECT			(CONFIG_BASE | 0x20)	//设置人脸效果
#define	CONFIG_CASH_READER_TYPE				(CONFIG_BASE | 0x21)	//设置当前点钞机型号
#define	CONFIG_CARD_READER_BAUDRATE			(CONFIG_BASE | 0x22)	//设置刷卡器波特率
#define	CONFIG_CHAR_OVERLAY_CFG				(CONFIG_BASE | 0x23)	//设置字符叠加显示配置
#define	CONFIG_VGA_CFG						(CONFIG_BASE | 0x24)	//设置VGA配置
#define	CONFIG_ALARMIN_CFG					(CONFIG_BASE | 0x25)	//设置IO报警输入参数

//获取命令
#define REQUEST_SYS_DEVICE			(CONFIG_REQ_BASE | 0x1)		//设备参数请求
#define	REQUEST_OSD					(CONFIG_REQ_BASE | 0x2)		//OSD参数请求
#define	REQUEST_SOND				(CONFIG_REQ_BASE | 0x3)		//声音参数请求
#define	REQUEST_VIDEO				(CONFIG_REQ_BASE | 0x4)		//视频参数请求
#define	REQUEST_MOVING_ALARM		(CONFIG_REQ_BASE | 0x5)		//移动侦测报警参数请求
#define	REQUEST_GROPING_ALARM		(CONFIG_REQ_BASE | 0x6)		//探头报警参数请求
#define	REQUEST_NET_ALARM			(CONFIG_REQ_BASE | 0x7)		//网络故障报警参数请求
#define	REQUEST_NETWORK				(CONFIG_REQ_BASE | 0x8)		//网络参数请求
#define	REQUEST_WIRELESS			(CONFIG_REQ_BASE | 0x9)		//无线参数请求
#define	REQUEST_DDNS				(CONFIG_REQ_BASE | 0xA)		//DDNS参数请求
#define	REQUEST_PPPOE				(CONFIG_REQ_BASE | 0xB)		//PPPOE参数请求
#define	REQUEST_BLOCK				(CONFIG_REQ_BASE | 0xC)		//遮挡报警请求
#define	REQUEST_USER				(CONFIG_REQ_BASE | 0xD)		//用户参数请求
#define	REQUEST_ALARM_CENTER		(CONFIG_REQ_BASE | 0xE)		//报警中心请求
#define	REQUEST_USERS_LOG			(CONFIG_REQ_BASE | 0xF)		//用户日志请求
#define	REQUEST_ALARM_LOG			(CONFIG_REQ_BASE | 0x10)	//报警日志请求
#define	REQUEST_SYS_TIME			(CONFIG_REQ_BASE | 0x11)	//系统时间请求
#define	REQUEST_SYS_VERSION			(CONFIG_REQ_BASE | 0x12)	//系统版本请求
#define	REQUEST_IMAGE				(CONFIG_REQ_BASE | 0x13)	//图像效果请求
//									(CONFIG_REQ_BASE | 0x14)
#define	REQUEST_LOW_LIGHT			(CONFIG_REQ_BASE | 0x15)	//低照度请求
#define	REQUEST_BACK_LIGHT			(CONFIG_REQ_BASE | 0x16)	//背光补偿请求
#define	REQUEST_VIDEO_EX			(CONFIG_REQ_BASE | 0x17)	//宽动态请求
#define	REQUEST_IMAGE_EX			(CONFIG_REQ_BASE | 0x18)	//图像效果扩展请求
#define	REQUEST_SCENE				(CONFIG_REQ_BASE | 0x19)	//图像场景请求
#define REQUEST_CHANS_INFO			(CONFIG_REQ_BASE | 0x1A)	//获取通道信息
#define REQUEST_SCENE_SUPPORT		(CONFIG_REQ_BASE | 0x1B)	//获取场景支持个数请求
#define REQUEST_RESOLUTION_SUPPORT	(CONFIG_REQ_BASE | 0x1C)	//分辨率支持掩码请求
#define	REQUEST_NETWORK_EX			(CONFIG_REQ_BASE | 0x1D)	//网络参数请求(扩展)
#define REQUEST_IR_EXPOSURE_PROTECT	(CONFIG_REQ_BASE | 0x1E)	//获取红外防过曝配置
#define	REQUEST_DISK_INFO			(CONFIG_REQ_BASE | 0x1F)	//获取硬盘信息
#define REQUEST_SYS_TIME_EX			(CONFIG_REQ_BASE | 0x20)	//系统时间请求(扩展)
#define REQUEST_RECORD_STATUS		(CONFIG_REQ_BASE | 0x21)	//录像状态请求
#define	REQUEST_VIDEO_ENC_INFO		(CONFIG_REQ_BASE | 0x22)	//视频编码参数请求
#define	REQUEST_PTZ_PRESET			(CONFIG_REQ_BASE | 0x23)	//预置点查询
#define	REQUEST_HIDE_AREAS			(CONFIG_REQ_BASE | 0x24)	//视频遮盖区域请求
#define	REQUEST_IO_ALARMIN_STATE	(CONFIG_REQ_BASE | 0x25)	//IO报警输入状态
#define	REQUEST_IO_ALARMOUT_STATE	(CONFIG_REQ_BASE | 0x26)	//IO报警输出状态
#define	REQUEST_FACE_AREAS			(CONFIG_REQ_BASE | 0x27)	//获取人脸叠加区域
#define	REQUEST_FACE_EFFECT			(CONFIG_REQ_BASE | 0x28)	//获取人脸叠加效果
#define	REQUEST_CASH_READER_TYPE				(CONFIG_REQ_BASE | 0x29)	//获取当前点钞机型号
#define	REQUEST_CARD_READER_BAUDRATE			(CONFIG_REQ_BASE | 0x2A)	//获取刷卡器波特率
#define	REQUEST_CHAR_OVERLAY_CFG				(CONFIG_REQ_BASE | 0x2B)	//获取字符叠加显示配置
#define	REQUEST_CASH_READER_TYPE_LIST			(CONFIG_REQ_BASE | 0x2C)	//获取点钞机型号支持列表
#define	REQUEST_VGA_CFG							(CONFIG_REQ_BASE | 0x2D)	//获取VGA配置
#define	REQUEST_ALARMIN_CFG						(CONFIG_REQ_BASE | 0x2E)	//获取IO报警输入参数


//控件命令
#define CONTROL_LOGIN							(CTL_BASE | 0x1)	//用户登录
#define CONTROL_LOGOUT							(CTL_BASE | 0x2)	//用户退出
#define CONTROL_RECOVER							(CTL_BASE | 0x3)	//恢复出厂设置
#define CONTROL_REBOOT							(CTL_BASE | 0x4)	//重启设备
#define CONTROL_SHUTDOWN						(CTL_BASE | 0x5)	//关闭设备
#define CONTROL_LENS_CONTROL					(CTL_BASE | 0x6)	//镜头控制
#define CONTROL_OSD_POSITION					(CTL_BASE | 0x7)	//osd位置调整
#define CONTROL_IMAGE							(CTL_BASE | 0x8)	//图像
#define CONTROL_LENS_ADJUST						(CTL_BASE | 0x9)	//镜头调节
#define CONTROL_OPEN_VIDOE						(CTL_BASE | 0xA)	//打开视频
#define CONTROL_CLOSE_VIDOE						(CTL_BASE | 0xB)	//关闭视频
#define CONTROL_GET_IFRAME						(CTL_BASE | 0xC)	//获取I帧
#define CONTROL_GROPING_ALARM_ENABLE			(CTL_BASE | 0xD)	//启动探头报警
#define CONTROL_GROPING_ALARM_UNENABLE			(CTL_BASE | 0xE)	//关闭探头报警
#define CONTROL_MOVING_ALARM_ENABLE				(CTL_BASE | 0xF)	//启动移动侦测报警
#define CONTROL_MOVING_ALARM_UNENABLE			(CTL_BASE | 0x10)	//关闭移动侦测报警
#define CONTROL_NET_ALARM_ENABLE				(CTL_BASE | 0x11)	//打开网络故障报警
#define CONTROL_NET_ALARM_UNENABLE				(CTL_BASE | 0x12)	//关闭网络故障报警
#define CONTROL_DEL_USER						(CTL_BASE | 0x13)	//删除用户
#define CONTROL_UNLOCK_PANNEL					(CTL_BASE | 0x14)	//解锁面板
#define CONTROL_HEARTBEAT						(CTL_BASE | 0x15)	//心跳
#define CONTROL_BLOCKALARM_OPEN					(CTL_BASE | 0x16)	//启动遮挡报警
#define CONTROL_BLOCKALARM_CLOSE				(CTL_BASE | 0x17)	//关闭遮挡报警
#define CONTROL_UPDATE							(CTL_BASE | 0x18)	//升级(发送镜像文件头)
#define CONTROL_SEND_FILE						(CTL_BASE | 0x19)	//发送文件(发送镜像文件内容)
#define CONTROL_PTZ								(CTL_BASE | 0x1A)	//云台控制
#define CONTROL_SND_MATRIX_HEAD					(CTL_BASE | 0x1B)	//发送点阵数据头
#define CONTROL_SND_MATRIX_DATA					(CTL_BASE | 0x1C)	//发送点阵数据
#define CONTROL_CAP_RAW							(CTL_BASE | 0x1D)	//抓拍采集图片
#define CONTROL_BEGIN_LISTEN					(CTL_BASE | 0x1E)	//启动监听
#define CONTROL_STOP_LISTEN						(CTL_BASE | 0x1F)	//停止监听
#define CONTROL_RESET_SCENE						(CTL_BASE | 0x20)	//复位指定场景的设置
#define CONTROL_DEV_CHECK_A						(CTL_BASE | 0x21)	//设备检测A模式
#define CONTROL_DEV_CHECK_B						(CTL_BASE | 0x22)	//设备检测B模式
#define CONTROL_REMOTE_FIND_FILE				(CTL_BASE | 0x23)	//查找设备录像文件
#define CONTROL_REMOTE_FIND_NEXT_FILE			(CTL_BASE | 0x24)	//逐个获取查找到的文件信息
#define CONTROL_REMOTE_FIND_CLOSE				(CTL_BASE | 0x25)	//关闭文件查找，释放资源
#define CONTROL_REMOTE_PLAY_BACK_OPEN			(CTL_BASE | 0x26)	//打开远程回放
#define CONTROL_REMOTE_PLAY_BACK_CONTROL		(CTL_BASE | 0x27)	//远程回放控制
#define CONTROL_REMOTE_PLAY_BACK_CLOSE			(CTL_BASE | 0x28)	//关闭远程回放
#define CONTROL_DETECT_TIMEOUT					(CTL_BASE | 0x29)	//检测socket是否超时
#define CONTROL_PTZ_PRESET						(CTL_BASE | 0x2A)	//云台预置点操作
#define CONTROL_SNAPSHOT						(CTL_BASE | 0x2B)	//抓图(非预览)
#define CONTROL_FIND_LOG						(CTL_BASE | 0x2C)	//查找设备日志
#define CONTROL_FIND_NEXT_LOG					(CTL_BASE | 0x2D)	//逐条获取查找到的日志信息
#define CONTROL_FIND_LOG_CLOSE					(CTL_BASE | 0x2E)	//关闭日志查找，释放资源
#define CONTROL_VOICE_COMM_START				(CTL_BASE | 0x2F)	//语音对讲开启
#define CONTROL_VOICE_COMM_STOP					(CTL_BASE | 0x30)	//语音对讲停止
#define CONTROL_RESET_FACE_EFFECT				(CTL_BASE | 0x31)	//恢复人脸效果默认值

#define CONTROL_REMOTE_GET_FILE					(CTL_BASE | 0xFFF)	//下载远程录像文件


#define APERTURE_LOVER		1	//降低自动光圈电平
#define APERTURE_LIFT		0   //升高自动光圈电平
#define	LENS_FOCUS			0   //焦距
#define	LENS_APERTURE		1   //光圈
#define	LENS_LIGHT			2   //灯光
#define	LENS_WIPER			3   //雨刮


#define	ALARM_PROBE_OPEN			0   //探头告警打开
#define	ALARM_PROBE_CLOSE			1   //探头告警关闭
#define ALARM_MOVE_OPEN				2   //移动告警打开
#define ALARM_MOVE_CLOSE			3   //移动告警关闭
#define ALARM_NET_OPEN				4   //网络告警打开
#define ALARM_NET_CLOSE				5   //网络告警关闭
#define SYSTEM_RESET				0   //系统参数重置
#define SYSTEM_REBOOT				1   //系统重启
#define SYSTEM_SHUT					2  	//系统重启

//OSD常量
#define OSD_TYPE_DATE				0  	//日期时间
#define OSD_TYPE_USER				1  	//自定义字符串

#define STATUS_CLOSE				0  	//关闭设备
#define STATUE_OPEN					1  	//打开设备

#define OSD_LEFT					1  	//osd向左
#define OSD_RIGHT					2  	//osd向右
#define OSD_UP						3  	//osd向上
#define OSD_DOWN					4  	//osd向下

//系统信息常量
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

//声音输入常量
#define	SOUND_SAMPLING_RATE_BEGIN				4 //采样率第４位开始
#define	SOUND_SAMPLING_RATE_LAST				4 //采样率占4位
#define	SAMPLING_RATE_8K						0 //采样率为8k
#define	SAMPLING_RATE_32K						1 //采样率为32k
#define SOUND_COMPRESSION_FORMAT_BEGIN			0 // 压缩格式第0位开始
#define	SOUND_COMPRESSION_FORMAT_LAST			4 //压缩格式占4位
#define COMPRESSION_FORMAT_G726					0 //压缩格式为G726
#define COMPRESSION_FORMAT_G711A				1 //压缩格式为G711A
#define COMPRESSION_FORMAT_G711U				2 //压缩格式为G711U
#define SOUND_SWITCH_BEGIN						1 //声音开关第1位开始
#define SOUND_SWITCH_LAST						1 //声音开关占1位
#define SOUND_INPUT_TYPE_BEGIN					0 //声音输入方式第0位开始
#define SOUND_INPUT_TYPE_LAST					1 //声音输入方式占1位
#define SOUND_INPUT_TYPE_MICROPHONE				0 //麦克风输入
#define SOUND_INPUT_TYPE_CIRCUIT				1 //线路输入
#define SOUND_INPUT_VOLUME_BEGIN				4 //输入音量第4位开始
#define SOUND_INPUT_VOLUME_LAST					4 //输入音量占4位
#define SOUND_OUTPUT_VOLUME_BEGIN				0 //输出音量第0位开始
#define SOUND_OUTPUT_VOLUME_LAST				4 //输出音量占4位

//码流常量
#define	STREAM_VIDEO_EFFECTS_BEST				0 //视频效果最好
#define STREAM_VIDEO_EFFECTS_GOOD				1 //视频效果好
#define STREAM_VIDEO_EFFECTS_COMMON				2 //视频效果一般
#define STREAM_CONTROL_BITS_BEGIN				4 //码流控制位从第4位开始
#define STREAM_CONTROL_BITS_LAST				4 //码流控制位占4位
#define STREAM_IMAGE_EFFECTS_BEGIN				0 //图像效果从第0位开始
#define STREAM_IMAGE_EFFECTS_LAST				4 //图像效果占4位
#define STREAM_CONTROL_VARIABLE					0 //码流可变
#define STREAM_CONTROL_FIXED					1 //码流固定

enum{
	RESOLUTION_MIN_VAL = 0,	//分辨率最小值
	RESOLUTION_DCIF = 0,	//DCIF分辨率 注：DCIF替换原QCIF
	RESOLUTION_CIF,			//CIF分辨率
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
	RESOLUTION_ADAPTATION,	//自适应
	RESOLUTION_MAX_VAL,	//分辨率最大值
};

//视频常量
#define  VIDEO_FONT_COLOR_BITS_BEGIN		4	//字体颜色从第4位开始
#define  VIDEO_FONT_COLOR_BITS_LAST			4	//字体颜色占4位
#define  VIDEO_FONT_COLOR_WHITE				0	//字体颜色白色
#define  VIDEO_FONT_COLOR_BLACK				1	//字体颜色黑色
#define  VIDEO_FONT_COLOR_YELLOW			2	//字体颜色黄色
#define  VIDEO_FONT_COLOR_RED				3	//字体颜色红色
#define  VIDEO_FONT_COLOR_BLUE				4	//字体颜色蓝色
#define  VIDEO_DATE_FORMAT_BITS_BEGIN		0	//日期格式从第0位开始
#define  VIDEO_DATE_FORMAT_BITS_LAST		4	//日期格式占4位
#define  VIDEO_DATE_FORMAT_YYYY_MM_DD		0
#define  VIDEO_DATE_FORMAT_MM_DD_YYYY		1
#define  VIDEO_DATE_FORMAT_DD_MM_YYYY		2
#define  VIDEO_LEN_BITS_BEGIN				7	//灯光从第7位开始
#define  VIDEO_LEN_BITS_LAST				1	//灯光占1位
#define  VIDEO_MIRROR_BITS_BEGIN			6	//镜像从第6位开始
#define  VIDEO_MIRROR_BITS_LAST				1	//镜像占1位
#define  VIDEO_TRUN_BITS_BEGIN				5	//镜像翻转从第5位开始
#define  VIDEO_TRUN_BITS_LAST				1	//镜像翻转占1位
#define  VIDEO_SHIELDING_BITS_BEGIN			4	//视频屏蔽从第4位开始
#define  VIDEO_SHIELDING_BITS_LAST			1	//视频屏蔽占1位
#define  VIDEO_LEN_50HZ						0	//灯光50HZ
#define  VIDEO_LEN_60HZ						1	//灯光60HZ
#define  STREAM_MAIN						0	//主码流
#define  STREAM_SECOND						1	//次码流

//时间常量
#define  TIME_OPEN_BITS_BEGIN         0
#define  TIME_OPEN_BITS_LAST          1
#define  TIME_SECTION_SIZE            4
#define  TIME_HOUR_BITS_BEGIN         11 //小时从11位开始
#define  TIME_HOUR_BITS_LAST          6  //小时占6位
#define  TIME_MINUTE_BITS_BEGIN       5  //分钟从5位开始
#define  TIME_MINUTE_BITS_LAST        6  //分钟占6位
#define  TIME_SECOND_BITS_BEGIN       0  //秒从第0位开始
#define  TIME_SECOND_BITS_LAST        5  //秒占5位

//移动报警常量
#define  MOVECHECK_LINK_VIDEO_BITS_BEGIN		0  //联动录像报警从0位开始
#define  MOVECHECK_LINK_VIDEO_BITS_LAST			1  //联动录像占1位
#define  MOVECHECK_LINK_CAPTURE_BITS_BEGIN		1  //联动抓拍从1位开始
#define  MOVECHECK_LINK_CAPTURE_BITS_LAST		1  //联动抓拍占1位
#define  MOVECHECK_LINK_OUTPUT_BITS_BEGIN		2  //联动输出从2位开始
#define  MOVECHECK_LINK_OUTPUT_BITS_LAST		1  //联动输出占1位
#define  MOVECHECK_SWITCH_BITS_BEGIN			0  //检测开关从0位开始
#define  MOVECHECK_SWITCH_BITS_LAST				1  //检测开关占1位
#define  MOVECHECK_SENSITIVITY_BITS_BEGIN		1  //灵敏度从1位开始
#define  MOVECHECK_SENSITIVITY_BITS_LAST		3  //灵敏度占3位
#define  MOVECHECK_MOVE_AREA_BITS_BEGIN			4  //移动区域从第4位开始
#define  MOVECHECK_MOVE_AREA_BITS_LAST			2  //移动区域占2位
#define  MOVECHECK_MOVE_AREA_PART				0  //部分区域
#define  MOVECHECK_MOVE_AREA_ALL				1  //全部区域
#define  MOVECHECK_MOVE_AREA_CLEAR				2  //清除区域

//探头报警常量
#define  WARNCHECK_LINK_VIDEO_BITS_BEGIN		0  //联动录像报警从0位开始
#define  WARNCHECK_LINK_VIDEO_BITS_LAST			1  //联动录像占1位
#define  WARNCHECK_LINK_CAPTURE_BITS_BEGIN		1  //联动抓拍从1位开始
#define  WARNCHECK_LINK_CAPTURE_BITS_LAST		1  //联动抓拍占1位
#define  WARNCHECK_LINK_OUTPUT_BITS_BEGIN		2  //联动输出从2位开始
#define  WARNCHECK_LINK_OUTPUT_BITS_LAST		1  //联动输出占1位
#define  WARNCHECK_SWITCH_BITS_BEGIN			0  //检测开关从0位开始
#define  WARNCHECK_SWITCH_BITS_LAST				1  //检测开关占1位
#define  WARNCHECK_SWITCH_TYPE_BITS_BEGIN		1  //探头类型从1位开始
#define  WARNCHECK_SWITCH_TYPE_BITS_LAST		1  //探头类型占1位
#define  WARN_TYPE_ALWAYS_CLOSE					0  //常闭探头
#define  WARN_TYPE_ALWAYS_OPEN					1  //常开探头

//网络故障常量
#define  NETWORKCHECK_LINK_VIDEO_BITS_BEGIN       0   //联动录像报警从0位开始
#define  NETWORKCHECK_LINK_VIDEO_BITS_LAST        1   //联动录像占1位
#define  NETWORKCHECK_LINK_CAPTURE_BITS_BEGIN     1   //联动抓拍从1位开始
#define  NETWORKCHECK_LINK_CAPTURE_BITS_LAST      1   //联动抓拍占1位
#define  NETWORKCHECK_LINK_OUTPUT_BITS_BEGIN      2   //联动输出从2位开始
#define  NETWORKCHECK_LINK_OUTPUT_BITS_LAST       1   //联动输出占1位
#define  NETWORKCHECK_SWITCH_BITS_BEGIN           0   //检测开关从0位开始
#define  NETWORKCHECK_SWITCH_BITS_LAST            1   //检测开关占1位

//无线网络常量
#define  WANLESS_ENCRYPT_BITS_BEGIN               4   //加密位从第4位开始
#define  WANLESS_ENCRYPT_BITS_LAST                2   //加密位占2位
#define  WANLESS_BAND_BITS_BEGIN                  2   //频段位从第2位开始
#define  WANLESS_BAND_BITS_LAST                   2   //频段位占2位
#define  WANLESS_MODE_BITS_BEGIN                  0   //模式位从第2位开始
#define  WANLESS_MODE_BITS_LAST                   2   //模式位占2位

//用户管理常量
enum{
  USER_PERMISSION_ADMIN	= 0,   //管理员
  USER_PERMISSION_CONTROL,	   //控制账号
  USER_PERMISSION_PREVIEW		//预览账号
};

//报警中心常量
#define  ALARM_TYPE_HEARTBEAT                     0x2015 //收到报警为心跳类型
#define  ALARM_TYPE_BASE                          0x3000 //报警类型开始
#define  NOTIFY_EVENT_TYPE_BASE                   0x3300 //NVR报警类型开始
#define  ALARM_SYSTEM                             (ALARM_TYPE_BASE | 0x1) //系统报警
#define  ALARM_DEVICE                             (ALARM_TYPE_BASE | 0x2) //设备报警
#define  ALARM_SOUND                              (ALARM_TYPE_BASE | 0x3) //音频报警
#define  ALARM_VIDEO                              (ALARM_TYPE_BASE | 0x4) //视频报警
#define  ALARM_MOVE                               (ALARM_TYPE_BASE | 0x5) //移动报警
#define  ALARM_WARN                               (ALARM_TYPE_BASE | 0x6) //探头报警
#define  ALARM_MEDIA_LOSE                         (ALARM_TYPE_BASE | 0x7) //人脸视频丢失报警
//#define  ALARM_BLACK                              (ALARM_TYPE_BASE | 0x7) //黑屏报警
#define  ALARM_BLOCK                              (ALARM_TYPE_BASE | 0x8) //遮挡报警
#define  ALARM_UPDATE                             (ALARM_TYPE_BASE | 0x9) //设备端口更新
#define  ALARM_TYPE_END                           (ALARM_TYPE_BASE | 0x10) //报警类型结束

//升级常量
enum{
	UPDATE_BOOTLOADER = 0,   //引导程序
	UPDATE_KERNERL,		     //内核
	UPDATE_FILESYSTEM		 //文件系统
};

////用户权限(在public.h定义)
//enum{
//	USER_ADMIN = 0,     //管理员
//	USER_DVR,		    //DVR用户
//	USER_CONTROL,		//控制用户
//	USER_PREVIEW		//预览用户
//};


//  {错误常量} //出错一般设置或返回错误常量,但返回的是string型,则返回对应函数名称
#define  ERROR_BASE				(1 < 3)
enum{
	ERROR_SOUND = (ERROR_BASE | 1),
	ERROR_STEAM,
	ERROR_VIDEO,
	ERROR_MOVECHECK,
	ERROR_NETWORKCHECK
};

//设备类型
enum{
	DEV_TYPE_NULL = 0,			//
	DEV_TYPE_NVR = 0xFF - 1,				//NVR
	DEV_TYPE_IPC = 0xFF,					//IP枪
};

//检索文件类型 
enum SEARCH_TYPE 
{ 
	SEARCH_TYPE_MANUAL = 0,					// 手动 
	SEARCH_TYPE_TIMING,						// 定时 
	SEARCH_TYPE_MOTION,						// 移动侦测 
	SEARCH_TYPE_ALARM,						// 报警 
	SEARCH_TYPE_MOTIONORALARM,				// 动测或报警 
	SEARCH_TYPE_MOTIONANDALARM,				// 动测且报警 
	SEARCH_TYPE_ALL,						// 全部 
	/////////////////////////////顺德农商定制类型占用/////////////////////////////
    SEARCH_TYPE_SDNS_COUNTER = 8,           //柜台敏感交易
    SEARCH_TYPE_SDNS_ATM,                   //ATM敏感交易
    //////////////////////////////////////////////////////////////////////////////
}; 

//事件类型 
enum EVENT_TYPE 
{ 
	EVENT_MANUAL = 0,					// 手动 
	EVENT_TIMING,						// 定时 
	EVENT_MOTION,						// 移动侦测 
	EVENT_ALARM,						// 报警 
	EVENT_MOTIONORALARM,				// 动测或报警 
	EVENT_MOTIONANDALARM,				// 动测且报警 
	EVENT_OTHER,						// 其他 
	EVENT_NORMAL,						// 正在进行普通录像（手动或定时，非事件录像） 
	/////////////////////////////顺德农商定制类型占用/////////////////////////////
    EVENT_SDNS_COUNTER,                     //柜台敏感交易
    EVENT_SDNS_ATM,                         //ATM敏感交易
    ///////////////////////////////////////////////////////////////////////////////////////
	EVENT_NOTHING,	
};

//远程回放控制命令
enum PLAY_CTL_CMD
{
    PLAY_CTL_PLAY,						//开始播放
    PLAY_CTL_PAUSE,						//暂停
    PLAY_CTL_GET_TIME,					//获取当前已经播放的时间
	PLAY_CTL_CONTINUE,					//继续
    PLAY_CTL_SET_SPEED,					//快进、慢进                              
    PLAY_CTL_SET_TIME,					//设置当前播放的时间(拖放)
	PLAY_CTL_NEXT_FRAME,				//单帧
	PLAY_CTL_GET_TOTAL_FRAMES,			//获取总帧数
	PLAY_CTL_SET_FRAME_RATE,			//设置回放帧率
    PLAY_CTL_SET_DIRECTION,				//设置播放方向(0：正向，1：反向)

	PLAY_CTL_STARTAUDIO = 100,			//打开声音
	PLAY_CTL_STOPTAUDIO,				//关闭声音
};

//通知事件
enum NOTIFY_EVENT
{
	MOTION_START = 0,					// 移动侦测开始 
	MOTION_STOP,						// 移动侦测结束 
	MASK_START,							// 遮挡报警开始 
	MASK_STOP,							// 遮挡报警结束 

	ALARM_IO_START = 100,				// IO报警开始 
	ALARM_IO_STOP,						// IO报警结束 
	ALARM_MODULE_CONFIG,				// 报警模块有修改配置信息 

	MEDIA_RECORD_ERR = 200,				// 通道码流录像出错 
	MEDIA_MAIN_LOSE,					// 主码流视频丢失 
	MEDIA_SUB_LOSE,						// 次码流视频丢失 
	MEDIA_CONNECT,						// 视频连接 
	TIME_ERROR,							// 校时错误 
	TIME_OK,							// 校时成功 

	NETWORK_CHANGED = 300,				// 网络参数改变 
	LOCAL_SHUTDOWN,						// 本地关机 
	LOCAL_REBOOT,						// 本地重启 
	LOCAL_MODIFNETPRA,					// 本地修改网络参数 
	LOCAL_UPDATASYSTEM,					// 本地升级 
	LOCAL_COVERDEFAULCONFIG,			// 本地恢复默认配置 

	REMOTE_LOGIN = 400,					// 远程登录 
	REMOTE_SHUTDOWN,					// 远程关机 
	REMOTE_LOGOUT,						// 远程注销 
	REMOTE_REBOOT,						// 远程重启系统 
	REMOTE_MODIFNETPRA,					// 远程修改网络参数 
	REMOTE_UPDATASYSTEM,				// 远程升级NVR 
	REMOTE_COVERDEFAULTCONFIG,			// 远程恢复默认配置 

	TIME_CHANGEING = 500,				// 系统时间即将发生变化 
	TIME_CHANGED ,						// 系统时间已经发生变化 
	DISK_CHANGED,						// 更换硬盘 
	IPSAN_LOST,							// IPSAN 掉线 
	DISK_FULL,							// 硬盘满 
	SNAP_DISK_CHANGED,					// 更换硬盘 
	DISK_ERROR,							// 硬盘坏(系统在运行的过程中，硬盘被拔掉)
	DISK_FULL_OK,						// 硬盘正常,对应上一次对应的硬盘满的报警
    DISK_ERROR_OK,						// 硬盘正常,对应上一次对应的硬盘坏的报警
};

//录像状态
enum STREAM_RECORD_STATUS
{
	STREAM_RECORD_STATUS_NULL = 0,				// 0 - 未录像
	STREAM_RECORD_STATUS_MANUAL_MAIN,			// 1 - 手动录像（主码流）
	STREAM_RECORD_STATUS_TIMING_MAIN,			// 2 - 定时录像（主码流） 
	STREAM_RECORD_STATUS_EVENT_MAIN,			// 3 - 事件录像（主码流）
	STREAM_RECORD_STATUS_MANUAL_SECOND,			// 1 - 手动录像（次码流）
	STREAM_RECORD_STATUS_TIMING_SECOND,			// 2 - 定时录像（次码流） 
	STREAM_RECORD_STATUS_EVENT_SECOND,			// 3 - 事件录像（次码流）
};

enum HY_PTZ_CMD
{ 
	LIGHT_PWRON,				//接通灯光电源 
	WIPER_PWRON,				//接通雨刷开关 
	FAN_PWRON,					//接通风扇开关 
	HEATER_PWRON,				//接通加热器开关 
	AUX_PWRON1,					//接通辅助设备开关 
	AUX_PWRON2,					//接通辅助设备开关 
	ZOOM_IN_EX,					//焦距变大(倍率变大) 
	ZOOM_OUT_EX,					//焦距变小(倍率变小) 
	FOCUS_NEAR,					//焦点前调 
	FOCUS_FAR,					//焦点后调 
	IRIS_OPEN,					//光圈扩大 
	IRIS_CLOSE,					//光圈缩小 
	TILT_UP,					//云台上仰 
	TILT_DOWN,					//云台下俯 
	PAN_LEFT,					//云台左转 
	PAN_RIGHT,					//云台右转 
	UP_LEFT,					//云台上仰和左转 
	UP_RIGHT,					//云台上仰和右转 
	DOWN_LEFT,					//云台下俯和左转 
	DOWN_RIGHT,					//云台下俯和右转 
	PAN_AUTO,					//云台左右自动扫描 
};

enum HY_PTZ_PRESET_CMD
{ 
	ADD_PRESET,				//增加预置点
	SET_PRESET,					//设置预置点
	CLE_PRESET,					//清除预置点
	GOTO_PRESET,				//转到预置点
};

//升级镜像文件类型
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

//升级状态
#define UPGRADE_STATE_OTHER		10
#define	UPGRADE_STATE_START		11
#define UPGRADE_STATE_END		12
#define UPGRADE_STATE_OK		13
#define UPGRADE_STATE_FAILED	14
#define UPGRADE_STATE_ING		15

enum HY_PLAYBACK_DPI
{
	PLAYBACK_DPI_DEF = 0,		//不用转码
	PLAYBACK_DPI_D1,			//转码成D1（704*576） 25帧
	PLAYBACK_DPI_CIF			//转码成CIF（352*288）12帧
};

//设备参数设置
typedef struct
{
	char szDevName[20];		// 设备信息
	char szDevNo[20];		// 设备编号
	char szSerial[10];		// 序列号
} SYSTEM_DEV_STR;

//系统版本信息
typedef struct
{
	char szUBOOTVer[10];		// U-BOOT版本号
	char szKernelVer[10];		// 内核版本号
	char szApplicationVer[10];	// 应用版本
} SYSTEM_VER_STR;

//系统时间
typedef struct
{
	BYTE byNTPEnable;		//网络时钟设置(0:关闭,1:启动)
	char szNTPServer[250];	//NTP服务器
	int iDate;				//Year= (23位), Month(4位), Day(5位)
	int iTime;				//Hour(5位), Minute(6位), Second(6位)
} SYSTEM_TIME_STR;

//设置osd
typedef struct
{
	BYTE byOsdNo;		//目标编号
	BYTE byOsdType;		//目标类型(0:日期时间, 1:自定义字符串)
	BYTE byShow;		//是否显示(1: 显示, 0:不显示)
	BYTE byVideoSource;	//osd所属码流， 0为主码流， 1为次码流
	UINT dwDataSize;	//字体数据长度，如果为0表示不更新osd样式
} SET_OSD_LINUX;

typedef struct
{
	SET_OSD_LINUX osdClient;
	char szActualContent[60];
} SET_OSD_T;


  //OSD获取
typedef struct
{
	BYTE byNum;			//目标编号
	BYTE byOSDType;		//目标类型（字符叠加(0-5视频名称，设备，日期时间星期, /帧率/码率,图片,用户定义字符串)
	BYTE byShow;		//关闭显示；state=1 打开显示
	unsigned short sX;	//OSD坐标X
	unsigned short sY;	//OSD坐标Y
	char szActualContent[60];	//osd实际内容
} REQ_OSD_T;

  //调整osd的位置
typedef struct
{
	BYTE byKindOfStream;			//码流编号
	BYTE byNum;						//目标编号
	unsigned short sX;				//OSD坐标X
	unsigned short sY;				//OSD坐标Y
} CONTROL_OSD_T;

//声音采集设置（0x0003）
typedef struct
{
	BYTE byFormate;			//采样率2(0:8K, 1:16K), 采样位数1(0:8位，1:16位),
							//声道数1位(0:1, 1:2),编码格式2位(0:PCM, 1:PCMA,2:PCMU), 输入1位（0为麦克风， 1为线性输入）
	BYTE byVolume;			//输入音量４bit,输出音量４bit; 输入：0-15; 输出：0-15;
} SOUND_STR;

typedef struct
{
	BYTE byVideoEffect;							//视频效果(0-2 依次为：最好，好，一般)
	BYTE byResolution;							//编码分辨率(0:QCIF, 1:CIF, 2:VGA，3:D1, 4:SVGA，5:720p, 6:960p，7:1080p，8:1200p)
	BYTE byFrameratePerSecond;					//编码帧率(0-60)
	BYTE byRateControlImageEffect;				//码流控制４bit,0为可变码流，1,固定码流;图像效果4bit; 1-6
	unsigned short wBytePerSecond;				//码率(0-4M), 缩小的数值/1000
} STREAM_STR;

//视频设置
typedef struct
{
	BYTE byFontState;							//字体颜色4bit(0-4 依次为：白,黑,黄,红,蓝), 日期格式4bit(0-2 依次是：YYYY-MM-DD,MM-DD-YYYY,DD-MM-YYYY)
	BYTE byState;								//灯1bit(0为50hz,1为60Hz), 镜像1bit(0为关闭镜像1为打开镜像), 翻转1bit(0为关闭翻转,1为打开翻转), 视频屏蔽1bit(0为关闭视频屏蔽,1为打开视频屏蔽)
	STREAM_STR stream[2];						//两个码流
} VIDEO_STR;


  //宽动态设置
typedef struct
{
	int iState;						//状态0-禁用，1-启用，2-自动
	int iLevel;						// 等级（0-100）
} VIDEO_EX;

//时间段
typedef struct
{
	BYTE byState;					//0位表示天是否选中,1-4位分别表示时间段1-4.
	unsigned short sT1Begin;         //检测时间1起始时间(第11-15位小时第5-10位分第0-4位秒)
	unsigned short sT1End;           //检测时间1结束时间(第11-15位小时第5-10位分第0-4位秒)
	unsigned short sT2Begin;         //检测时间2起始时间(第11-15位小时第5-10位分第0-4位秒)
	unsigned short sT2End;           //检测时间2结束时间(第11-15位小时第5-10位分第0-4位秒)
	unsigned short sT3Begin;         //检测时间3起始时间(第11-15位小时第5-10位分第0-4位秒)
	unsigned short sT3End;           //检测时间3结束时间(第11-15位小时第5-10位分第0-4位秒)
	unsigned short sT4Begin;         //检测时间4起始时间(第11-15位小时第5-10位分第0-4位秒)
	unsigned short sT4End;           //检测时间4结束时间(第11-15位小时第5-10位分第0-4位秒)
} TIME_STR;


typedef struct
{
	unsigned short sX1;         //16的倍数
	unsigned short sY1;         
	unsigned short sX2;         
	unsigned short sY2;         
	BYTE bySensitivity;			//0-3,0-为不检测，数值越大级别越高
} MOVE_AREA_STR;

  //报警信息
typedef struct
{
	char* szDevNo;
	char* szTime;
} COMM_ALARM_STR;

  //探头报警信息
typedef struct
{
	BYTE byIp[16];
	BYTE byDevNo[20];
	BYTE channel;			//通道号(从0开始)
	BYTE state;				//IO状态(0 或 1)
	int reserved1;
	int reserved2;
} DETECTOR_ALARM_STR;

//移动报警
typedef struct
{
	BYTE byWarnLink;      //联动报警3bit; 联动录像(第0bit)：长度1bit, 0为关，1为开
                         //联动抓拍(第1bit)：长度1bit, 0为关，1为开;联动报警输出(第2bit)：长度1bit, 0为关，1为开
	MOVE_AREA_STR areas[16];
	BYTE byKeepTime;				//报警持续时间（０－２５５）秒
	BYTE byNumOfPhoto;				//抓拍照片张数(0-255)
	BYTE byPhotoInteval;			//抓拍间隔时间(0-255)秒
	BYTE byTimeOfVedio;				//录像时间(0-255)分
	TIME_STR plan[7];				//0-6星期天至星期六
} MOVE_CHECK_STR;

//遮挡报警
typedef struct
{
	BYTE byLinkOutput;     //联动输出
	BYTE byIsOpen;         //是否打开报警
	BYTE byDuration;       //持续时间
	TIME_STR plan[7];				//1-7星期一至星期日
}OCCLUSION_CHECK_STR;

//视频遮盖区域
#define MAX_POLYGON_POINT_NUM 10	//最大多边形点数目
#define MAX_HIDE_AREAS_NUM 10	//最大遮盖区域数目
#define MAX_AVAILABLE_HIDE_AREAS_NUM 8	//最大有效遮盖区域
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
	BYTE byEnabled;	//0:禁止, 1:使能
	BYTE byreserved[3];
	POLYGON_AREA_STR area;
}HIDE_AREA_STR;

typedef struct
{
	int nAreasNum;
	BYTE byReserved[8];
	HIDE_AREA_STR areas[MAX_HIDE_AREAS_NUM];
}HIDE_AREAS_STR;

//探头报警
typedef struct
{
	BYTE byWarnLink;			//联动报警3bit;,
								//联动录像(第0bit)：长度1bit, 0为关，1为开
								//联动抓拍(第1bit)：长度1bit, 0为关，1为开
								//联动报警输出(第2bit)：长度1bit, 0为关，1为开
	BYTE byState;				//检测开关(第0bit):   长度1bit, 0为关，1为开
								//探头类型(第1): 长度1bit,0-1
	BYTE byKeepTime;			//报警持续时间（０－２５５）秒
	BYTE byNumOfPhoto;			//抓拍照片张数(0-255)
	BYTE byPhotoInteval;		//抓拍间隔时间(0-255)秒
	BYTE byTimeOfVedio;			//录像时间(0-255)分
	TIME_STR plan[7];			//1-7星期一至星期日
}WARN_CHECK_STR;

//网络故障
typedef struct
{
	BYTE byWarnLink;     //联动报警3bit;,
						//联动录像(第0bit)：长度1bit, 0为关，1为开
                        //联动抓拍(第1bit)：长度1bit, 0为关，1为开
						//联动报警输出(第2bit)：长度1bit, 0为关，1为开
	BYTE byOpen;         //检测开关1bit 检测开关(第0bit):1bit, 0为关，1为开
	BYTE byKeepTime;     //报警持续时间（０－２５５）秒
	BYTE byNumOfPhoto;   //抓拍照片张数(0-255)
	BYTE byPhotoInteval; //抓拍间隔时间(0-255)秒
	BYTE byTimeOfVedio;  //录像时间(0-255)分
}NETWORK_CHECK_STR;

//网络设置
typedef struct
{
	BYTE	byIp[4];						//ip地址
	BYTE	bySubmask[4];					//掩码
	BYTE	byGateway[4];					//网关
	BYTE	byPhaddr[6];					//物理地址
	BYTE	byMainDNS[4];					//首选DNS
	BYTE	byBackupDNS[4];					//备用DNS
	BYTE	byDHCPEnable;
	//char	szNTPServer[250];
	unsigned short	sSoundPort;						//音频端口号（７０１０）
	unsigned short	sStreamPort;					//视频主码流端口号（７００２）
	unsigned short	sConfigPort;					//控制流端口（缺省端口７０００)
} NETWORK_BASE;

typedef union 
{ 
	int iDefaultRoute;						//默认路由 0为eth0 1为eth1 
	int iMajorNic;							//主网卡 0为eth0 1为eth1 
	int iExtension;							//扩充参数 
} NET_EXT_PARA; 

typedef struct 
{ 
	char szIp[20];							//IPv4地址 
	char szMask[20];						//子网掩码 
	char szGateway[20];						//网关 
} NET_BASIC_PARA; 

typedef struct 
{ 
	NET_BASIC_PARA basicParas[3];			//存放多个网络参数 
	char szMac[20];							//mac 地址 
	unsigned int unMTU;						//MTU 
	BYTE byDHCPEnable;						//是否使能DHCP 
	int iNicType;							//网卡类型:1为10M半双工 2为10M全双工 3为100M半双工 4为100M全双工 5为10M/100M/1000M自适应 
	char szIpv6Addr1[45];					//IPv6地址1 
	char szIpv6Addr2[45];					//IPv6地址2 
	char szIpv6DefaultGateway[45];			//IPv6默认网关 
} NIC_PARA; 

//网络设置(扩展)
typedef struct{ 
	int iMode;								//正在使用的网络模式 0为多值设定 1为负载平衡 2为网络容错 
	int iNicNum;							//网卡个数（1~3） 
	NIC_PARA nicParas[3];					//每种模式下3个网卡的参数 
	char szPrimaryDNS[20];					//首选DNS 
	char szBackupDNS[20];					//备用DNS 
	NET_EXT_PARA extPara;					//扩充参数，据网络模式不同而不同 
} NETWORK_EX;

//无线网络设置
typedef struct
{
	BYTE	byIp[4];						//ip地址
	BYTE	bySubmask[4];					//掩码
	BYTE	byGateway[4];					//网关
	BYTE	byEncryptFreqModeDHCP;			//加密、频段、模式各２bit;
	UINT	dwSSID;							//SSID号
}WANLESS_STR;

//DDNS设置
typedef struct
{
	BYTE	byDDNSUpdateInteval;
	char	szDDNSServerName[20];			//DDNS服务提供者
	char	szRegName[20];					//注册名
	char	szPwd[20];						//密码
	char	szDDNSDomain[20];				//域名
	char	szDDNSAddr[20];					//地址
	unsigned short sDDNSPort;				//ＤＤＮＳ端口
	unsigned short sDataMapPort;			//数据映射端口
	unsigned short sWebMapPort;				//web映射端口
}DDNS_STR;

//PPPOE设置
typedef struct
{
	BYTE byPPPOEOpen;				//pppoe是否启用
	char szAddr[30];				//地址
	char szUserName[10];			//用户名
	char szPwd[10];					//密码
	int iKeepTime;					//在线时间
}PPPOE_STR;

//用户配置指令码（0x000D）
typedef struct
{
	char	szUserName[10];			//用户名
	char	szPwd[33];				//密码  {修改}
	BYTE	byRight;				//权限级别,0-3(管理员, DVR用户, 控制权限, 浏览权限}
} USER_ACCOUNT;

//所有用户信息
typedef struct
{
	short	sAccountNum;
	USER_ACCOUNT arrAccount[MAX_USER];
} ALL_USER_ACCOUNT;

//图像质量结构体
typedef struct
{
	BYTE byBright;                         //亮度(0-255)
	BYTE bySaturation;                     //饱和度(0-255)
	BYTE byAcutance;                       //锐度(0-255)
	BYTE byRed;                            //红色(0-255)
	BYTE byBlue;                           //蓝色(0-255)
	BYTE byContras;						   //对比度(0-255)
	BYTE byGamma;                          //伽玛(0-255)
}IMAGE_ADJUST_STR;

// 图像质量结构体扩展
typedef struct
{
	BYTE byEnhancement;                 //图像增强(0-64)
	BYTE byDenoise;                     //降噪(0-16)
}IMAGE_ADJUST_STR_EX;

//登录用户
typedef struct
{
	char szUserName[10];
	char szPwd[32];
}USER_LOGIN_STR;

  //报警中心设置
typedef struct
{
	char byIP[4];
	unsigned short sPort;
}ALARM_CENTER_STR;

  //用户日志请求
typedef struct
{
	BYTE byStart;
	BYTE byNum;
}REQ_USER_LOG_STR;

  //用户日志应答
typedef struct
{
	char szUserName[10];
	unsigned short sInfo;		//访问信息
	UINT iTime;					//时间
}ANS_USER_LOG_STR;

typedef struct
{
	char szFileName[80];
	BYTE byFileType;
}UPDATE_STR;

typedef struct
{
	char	szUserName[10];			//用户名
	char	szPwd[33];				//密码  {修改}
	BYTE	byRight;				//权限级别,0-3(管理员, DVR用户, 控制权限, 浏览权限}
} USER;

//设备标识结构体
typedef struct
{
	int iHandle;					//视频句柄
	int iChannel;					//视频通道号
	int iVideoSource;				//视频源
}IDENTITY;


  //请求码流结构体
typedef struct
{
	IDENTITY identity;
	unsigned short sRecvPort;
	unsigned short sSendPort;
}REQ_STREAM;

  //低照度
typedef struct
{
	int iGrayChangeThreshold;				//灰度改变阀值
	int iLowLightThreshold;					//低照度阀值
	BYTE byCanChangeColor;					//是否允许颜色改变
}LOW_LIGHT;

  //背光补偿
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

//设备检测信息A
typedef struct
{
	int iSeriusHotPixel;						//严重燥点
	int iHotPixel;								//燥点
	int iSeriusBrightPixel;						//严重亮点
	int iBrightPixel;							//亮点
	int iClusterCnt;							//坏块
	int iSeriusPixelMax;						//严重点最大值
	int iHotBrightPixelMax;						//燥点和亮点最大值
	int iDarkPixelMax;							//坏点最大值
	int iClusterCntMax;							//坏块最大值
}DEV_CHECK_INFO_A;

  //设备检测信息B
  typedef struct
{
	int iSeriusDarkPixel;						//严重坏点
	int iDarkPixel;								//坏点
	int iClusterCnt;							//坏块
	int iSeriusPixelMax;						//严重点最大值
	int iHotBrightPixelMax;						//燥点和亮点最大值
	int iDarkPixelMax;							//坏点最大值
	int iClusterCntMax;							//坏块最大值
}DEV_CHECK_INFO_B;

//打开音频
typedef struct 
{ 
  unsigned short  audio_port; 
  unsigned short  channel; //通道号 
} AUDIO_OPEN;

//通道信息
typedef struct
{
    int      Id;              // 通道号
    char     Ip[20];          // IP地址
    int      Port;            // 管理端口
    int      Protocol;        // 协议(枪类型：0 - IP枪，1 - 板卡)
    char     Name[50];        // 通道名
    char     Model[50];       // 设备型号
    int      State;           // 状态(0 - 未连接，1 - 已连接）
    char     SN[50];          // 序列号
    char     FireVersion[50]; // 固件版本
} CHAN_INFO;

//通道列表
typedef struct
{
    int         chanNum;                  //通道数
    CHAN_INFO chansInfo[MAX_CHAN_NUM];  //通道信息数组
} CHANS_LIST_INFO;

//系统时间
typedef struct
{
	BYTE byNTPEnable;		//网络时钟设置(0:关闭,1:启动)
	char szNTPServer[250];	//NTP服务器
	int iDate;				//Year= (23位), Month(4位), Day(5位)
	int iTime;				//Hour(5位), Minute(6位), Second(6位)
} SYSTEM_TIME;

typedef struct
{
	DWORD dwTime;		//报警触发时间
	char szIp[16];		//发生报警的设备ip
	WORD wKind;			//发生报警类型
	char szContent[50];	//报警内容
	int nLen;			//报警内容长度
	char szAlarmTime[31];	//发生报警的设备时间
}ALARM_RECORD;

//时间参数结构体
typedef struct{  
	unsigned short		sYear;					//年
	unsigned short		sMonth;					//月
	unsigned short		sDay;					//日
	unsigned short		sHour;					//时
	unsigned short		sMinute;				//分
	unsigned short    	sSecond;				//秒
}TIME;

//查找的录像文件信息结构体
typedef struct{
	int				nChannel;					//通道号
	int				nFileType;					//录象文件类型：0-手动，1-定时，2-移动侦测,3-报警,4-动测或报警, 5-动测且报警, 6-全部
	int				nIsLocked;					//是否锁定：0-未锁定文件，1-锁定文件,2-表示所有文件(包括锁定和未锁定)
	TIME			struStartTime;				//开始时间
	TIME			struEndTime;				//停止时间
	int				nReserved;					//预留信息：4个字节
}FILE_COND,*LPFILE_COND;

//保存文件信息
typedef struct{
	char	szFileName[100];					//文件名
	TIME	struStartTime;						//文件的开始时间
	TIME	struEndTime;						//文件的结束时间
	DWORD	dwFileSize;							//文件大小
	int		nLocked;							//文件是否被锁定，1－文件已锁定；0－文件未锁定
	int		nFileType;							//文件类型：0-手动，1-定时，2-移动侦测,3-报警,4-动测或报警, 5-动测且报警, 6-全部
	int		nReserved;							//预留信息：4个字节
}FIND_DATA,*LPFIND_DATA;

//回放条件
typedef struct{
	int nChannel;								//通道号
	TIME struBeginTime;							//开始时间
	TIME struEndTime;							//结束时间
	HWND hWnd;									//回放窗口（SDK解码时设置有效值；）
	WORD wPort;									//接收端口
	int	nData;									//额外数据(低8bit：转码播放分辨率 HY_PLAYBACK_DPI; 预留信息：3个字节,置为0)
}VOD_PARA,*LPVOD_PARA;

//硬盘信息结构体： 
typedef struct 
{ 
	int nDiskNum;								//硬盘号 1-10 
	unsigned long lUsedRecordSize;				//已用录像空间 单位为M 
	unsigned long lUsedSnapSize ;				//已用抓拍空间 单位为M 
	unsigned long lDiskSize;					//硬盘大小 单位为G 
	unsigned long lSnapQuota;					//抓拍配额 单位为G 
	unsigned long lRecordQuota;					//录像配额 单位为G 
}DISK_INFO;

//硬盘信息集
typedef struct 
{
	int nValidCount;							//有效硬盘数目
	DISK_INFO arrDiskInfo[MAX_DISKNUM];			//硬盘信息数组
}DISK_SET;

//NVR报警数据结构体：
typedef struct
{
    int     chan;           //通道号
    char    time[30];       //事件发生的时间
	char	res1[2];
    NOTIFY_EVENT type;      //事件类型
    char    name[30];       //事件名称, 目前适用于IO报警
	char	res2[2];
} NOTIFY_EVENT_MSG;

//时间参数结构体
typedef struct 
{ 
	int nYear; 
	int nMonth; 
	int nDay; 
	int nHour; 
	int nMinute; 
	int nSecond; 
} HY_TIME;

//图像质量结构体
typedef struct 
{ 
	BYTE byBrightness;					//亮度(0-255) 
	BYTE bySaturation;					//饱和度(0-255)
	BYTE bySharpness;					//锐度(0-255)
	BYTE byRed;							//红色(0-255)
	BYTE byBlue;						//蓝色(0-255)
	BYTE byContrast;					//对比度(0-255)
	BYTE byGamma;						//gamma(0-255)
	BYTE byEnhancement;                 //图像增强(0-255)
	BYTE byDenoise;                     //降噪(0-255)
	BYTE byChroma;						//色度(0-255)
	BYTE byRes[15];						//保留
} HY_IMAGE_EFFECT;

//云台控制
typedef struct 
{ 
	int cmd;							//控制命令 HY_PTZ_CMD
	int nStopFlag;				//0: 开始，1：停止 
	int nSpeed;					//速度范围1 ~ 7, 0为静止 
} HY_PTZ_CTL;

//预置点信息
#define MAX_PRESET_TOKEN_LEN    25                                
#define MAX_PRESET_NAME_LEN    30
typedef struct  
{
    char    szToken[MAX_PRESET_TOKEN_LEN+1];                        
    char    szName[MAX_PRESET_NAME_LEN+1];
} HY_PRESET_INFO;


//预置点控制
typedef struct 
{ 
	int cmd;					//操作云台预置点命令 HY_PTZ_PRESET_CMD  0: 增加，1: 修改 2：清除，3：转到 
	HY_PRESET_INFO presetInfo;				//预置点信息
} HY_PTZ_PRESET;

//视频编码参数
typedef struct 
{ 
	int nStreamId;					//0:主码流 1：次码流 其他:其他码流 
	int nEncType;					//编码方式 0:JPEG 1:MPEG4 2:H264 
	int nWidth;						//分辨率宽度 
	int nHeight;					//分辨率高度 
	int nFrameRate;					//帧率 
	int nBitrate;					//码率(单位：kb) 
	BYTE byRes[20]; 
} HY_VIDEO_ENC_INFO;

//设置录像状态
typedef struct
{
    int nStreamId;	 //0: 主码流, 1：次码流
    int nState;      //0：停止手动录像, 1: 启动手动录像，          
} HY_SET_RECORD_STATE;

//IO报警信息
#define MAX_NUM_IO				64	//输入输出IO最大个数
#define MAX_LEN_IO_ID			30	//IO报警ID名称长度
typedef struct
{
    BYTE     nState;					//1：报警开始 0：报警停止
    char     szId[MAX_LEN_IO_ID+1];		//IO报警ID
} HY_IO_STATE;

//查找日志信息
#define LOG_SOURCE_LEN          100
#define SHORT_LOG_INFO_LEN	    100
#define WHOLE_LOG_INFO_LEN      11840

//主类型
typedef enum
{
    ALL = 0,
    ALARM,          //报警
    ABNORMAL,       //异常
    OPERATION,      //操作
    INFO            //信息
}HY_LOG_MAJOR_TYPE;

//报警的次类型
typedef enum
{
    ALARMALL = 0,               //全部，仅用于检索
    ALARMINPUTSTART,            //报警输入开始
    ALARMINPUTSTOP,             //报警输入结束
    ALARMOUTPUT,                //报警输出
    STARTMOTIONDETECTION,       //移动侦测开始
    ENDMOTIONDETECTION,         //移动侦测结束
    STARTSHELTER,               //遮挡报警开始
    ENDSHELTER                  //遮挡报警结束
}HY_LOG_MINOR_TYPE_ALARM;

//异常的次类型
typedef enum
{
    ABNORMALALL = 0,            //全部，仅用于检索
    UNAUTHORIZEDACCESS,         //非法访问
    DRIVEFULL,                  //硬盘满
    IPCONFLICT,                 //IP冲突
    NETWORKDROPPED,             //网络掉线
    RECORDORCASCREENSHOTERROR,  //录像或者抓图异常
    IPCAMERAERROR,              //ip camera 异常
    VIDEOFORMATERROR,           //输入，输出视频格式不匹配
    VIDEOSIGNALLOST             //视频信号丢失
}HY_LOG_MINOR_TYPE_ABNORMAL;

//操作次类型
typedef enum
{
    OPERATIONALL = 0,   //全部，仅用于检索
    LOCALSHUTDOWN,      //本地关机
    ERRORSHUTDOWN,      //异常关机
    LOCALREBOOT,        //本地重启
    LOCALLOGIN,         //本地登录
    LOCALLOGOUT,        //本地注销
    LOCALCONFIGURATION, //本地配置
    LOCALUPGRADE,       //本地升级
    LOCALSTARTRECORD,   //本地启动录像
    LOCALSTOPRECORD,    //本地停止录像
    LOCALLOCKFILE,      //本地锁定文件
    LOCALUNLOCKFILE,    //本地解锁文件          新增 ww 20131226
    LOCALHANDALARM,     //本地报警
    LOCALINITIALIZEHARDDISK,    //本地初始化硬盘
    LOCALADDIPCHANNEL,          //本地添加IP通道
    LOCALDELETIPCHANNEL,        //本地删除IP通道
    LOCALCONFIGIPCHANNEL,       //本地配置IP通道
    LOCALADDMOCKCHANNEL,          //本地添加模拟通道       ww 20140103
    LOCALDELETMOCKCHANNEL,        //本地删除模拟通道     ww 20140103
    LOCALPLAYRECORDFILE,        //本地回放录像文件
    LOCALINPORTPROFILE,         //本地导入配置文件
    LOCALEXPORTPROFILE,         //本地导出配置文件
    LOCALBACKUPRECORDFILE,      //本地备份录像文件
    LOCALBACKUPSNAPFILE,        //本地备份抓拍文件
    LOCALADDNETHARDDISK,        //本地添加网络硬盘
    LOCALCONFIGNETHARDDISK,     //本地配置网络硬盘
    LOCALSTARTSCREENSHOT,       //本地启动抓图
    LOCALSTOPSCREENSHOT,        //本地停止抓图
    LOCALRECORERYADMINDEFAULTPASSWORD,  //本地恢复操作员默认密码
    LOCALLABELOPERATION,        //  本地标签操作
    REMOTELOGIN,                //远程登录
    REMOTESHUTDOWN,             //远程关机
    REMOTEREBOOT,               //远程重启
    REMOTELOGOUT,               //远程注销
    REMOTECONFIGURATION,        //远程配置
    REMOTEUPGRADE,              //远程升级
    REMOTESTARTRECORD,          //远程开始录像
    REMOTESTOPRECORD,           //远程停止录像
    REMOTELOCKFILE,             //远程锁定文件
    REMOTEUNLOCKFILE,           //远程解锁文件
    REMOTEHANDALARM,            //远程手动报警
    REMOTEINITIALIZEHARDDISK,   //远程初始化硬盘
    REMOTEADDIPCHANNEL,         //远程添加IP通道     
    REMOTEDELTEIPCHANNEL,       //远程删除IP通道     
    REMOTEADDMOCKCHANNEL,         //远程添加模拟通道    ww 20140103
    REMOTEDELTEMOCKCHANNEL,       //远程删除模拟通道    ww 20140103
    REMOTEPLAYORDOWNLOADBYFILE, //远程按文件回放或下载
    REMOTEPLAYORDOWNLOADBYTIME, //远程按时间回放或下载
    REMOTEEXPORTPROFILE,        //远程导出配置文件
    REMOTEINPORTPROFILE,        //远程导入配置文件
    REMOTEBACKUPRECORDFILE,     //远程备份录像文件
    REMOTEBACKUPPICTUREFILE,    //远程备份图片文件
    REMOTEGETCONFIGURATION,     //远程获取参数
    REMOTEGETSTATUE,            //远程获取状态
    BUILDTRANSPARENTSTATUE,     //建立透明状态
    DISCONNECTTRANSPARENTSTATU, //断开透明状态
    STARTVOICEINTERCOM,         //语音对讲开始
    STOPVOICEINTERCOM,          //语音对讲结束
    REMOTEARMING,               //远程布防
    REMOTEADDNETHARDDISK,       //远程添加网络硬盘
    REMOTEDELTENETHARDDISK,     //远程删除网络硬盘
    REMOTECONFIGNETHARDDISK,    //远程设置网络硬盘
    REMOTESTRTSCREENSHOT,       //远程启动抓图
    REMOTESTOPSCREENSHTO,       //远程停止抓图
    REMOTELABELOPERATION        //远程标签操作
} HY_LOG_MINOR_TYPE_OPERATION;

//信息次类型
typedef enum
{
    INFOALL = 0,        //全部，仅用于检索
    LOCALHARDDISKINFO,  //本地硬盘信息
    HARDDISKSMART,      //硬盘SMART
    STARTRECORD,        //开始录像
    STOPRECORD,         //结束录像
    STARTSCREENSHOOT,   //开始抓图
    STOPSCREENSHOOT,    //结束抓图
    DETELEOLDRECORD,    //删除过期录像
    DETELEOLDSNAP,      //删除过期图片
    NETHARDDISKINFO     //网络硬盘信息
}HY_LOG_MINOR_TYPE_INFO;

//查找日志信息条件
typedef struct{
	TIME			struStartTime;				//开始时间
	TIME			struEndTime;				//停止时间
	int				nMajorType;					//主类型:HY_LOG_MAJOR_TYPE
	int				nMinorType;					//次类型:HY_LOG_MINOR_TYPE_ALARM,HY_LOG_MINOR_TYPE_ABNORMAL,HY_LOG_MINOR_TYPE_OPERATION,HY_LOG_MINOR_TYPE_INFO
	BYTE			byReserved[8];				//预留信息：8个字节
}HY_LOG_COND,*LPHY_LOG_COND;

//查找到的日志信息
typedef struct{
	int             nId;								//记录ID
    int				nMajorType;							//主类型:HY_LOG_MAJOR_TYPE
	int				nMinorType;							//次类型:HY_LOG_MINOR_TYPE_ALARM,HY_LOG_MINOR_TYPE_ABNORMAL,HY_LOG_MINOR_TYPE_OPERATION,HY_LOG_MINOR_TYPE_INFO
    int             nLevel;								//重要等级
    int             nChannel;							//对应的通道号
    TIME			struTime;							//发生时间
    char            szIp[45];
    char            szSource[LOG_SOURCE_LEN];			//事件来源
    char            szShortMsg[SHORT_LOG_INFO_LEN];		//简短描述
    char            szWholeMsg[WHOLE_LOG_INFO_LEN];		//详细描述
}HY_LOG_DATA,*LPHY_LOG_DATA;

//抓图参数
typedef struct
{
    int nStreamType;  //码流类型: 0 - 主码流， 1 - 次码流，目前只支持主码流
    int nQuality;    //图像质量，0~100，数据量递增，推荐75
} HY_SNAPSHOT_PARA, *LPHY_SNAPSHOT_PARA;

//升级状态信息
typedef struct
{
	int nState;				//远程升级的状态
	int nProgress;			//升级进度(0－100)
	WORD wCmd;				//命令码
	WORD wErrorCode;		//错误码
	BYTE* pData;			//数据
	BYTE byRes[8];			//保留
}HY_UPGRADE_STATUS, *LPHY_UPGRADE_STATUS;
//人脸叠加区域
typedef struct
{
    int nX;						//取值为背景宽度的百分比(取值范围：0-100)
    int nY;						//取值为背景高度的百分比(取值范围：0-100)
    int nWidth;					//取值为人脸图像最大支持分辨率宽度的百分比(取值范围：0-100)
    int nHeight;				//取值为人脸图像最大支持分辨率高度的百分比(取值范围：0-100)
} HY_FACE_AREA;

//人脸叠加效果
typedef struct
{
    BYTE   byBrightness; //亮度(0-255)
    BYTE   bySaturation; //饱和度(0-255)
    BYTE   bySharpness;  //锐度(0-255)
    BYTE   byHue;        //色调(0-255)
    BYTE   byContrast;   //对比度(0-255)
    BYTE   byDenoise;    //降噪(0-15)
} HY_FACE_EFFECT;

//点钞字符叠加

//获取点钞字符叠加显示配置
typedef struct
{
    BYTE byDisplayMode;   //0: display both, 1: hide both, 2: display cash info only, 3: hide card last 4 chars
    BYTE byDisplayTime;   //in seconds, 0 means always
    BYTE byFontSize;      //0: auto, 1: big, 2: medium, 3: small
    int	nX;
    int	nY;
    char reserved[16];
} HY_CHAR_OVERLAY_CFG;

//点钞机型号支持列表
#define MAX_CASH_READER_NUM      10
typedef struct
{
    WORD    wTotalNum;										//支持点钞机类型总额
    WORD    wCurrentNum;									//当前页类型数目
    WORD    wPage;											//当前页码
    char    strName[MAX_CASH_READER_NUM][25];				//所支持点钞机名称列表(每个点钞机类型名称不超过20字节)
} HY_CASH_READER_TYPE_LIST;

//VGA配置
typedef struct
{
    int nIsAuto;			//是否自动识别
    int nWidth;          
    int nHeight;        
    int nFrequency;
    int nV;					//垂直位置(范围为0～255)
    int nH;					//水平位置(范围为0～255)
    int nInvertColor;		//是否翻转颜色
    char reserved[8];		//保留8字节
} HY_VGA_CONFIG;

//VGA查询参数
typedef struct
{
    int nWidth;        
    int nHeight;    
    int nFrequency;
    char reserved[8];		//保留8字节
} HY_VGA_QUERY_PARA;

//计划时间
typedef struct{
	unsigned short		sStartHour;					//开始时
	unsigned short		sStartMinute;				//开始分
	unsigned short		sStartSecond;				//开始秒
	unsigned short		sStopHour ;					//结束时
	unsigned short		sStopMinute;				//结束分
	unsigned short		sStopSecond;				//结束秒
}HY_SCHEDULE_TIME;

//IO报警输入配置
#define	NAME_LEN	32
#define MAX_CHANNUM	512
#define MAX_DAYS	8
#define	MAX_TIMESEGMENT	8
#define	MAX_ALARMOUT	128
#define	MAX_LEN_LINK_IO_ID	20
typedef struct {
    char				szId[MAX_LEN_IO_ID+1];			//报警输入ID
    char				szName[NAME_LEN];				//报警输入名称
    BYTE				byType;							//报警器类型：0-常开，1- 常闭
    BYTE				byEnable;						//是否处理：0- 不处理，1- 处理 
    int					nHandleType;					//处理方式

    int					nLinkChan[MAX_CHANNUM];			//触发录像通道
    HY_SCHEDULE_TIME	AlarmTime[MAX_DAYS][MAX_TIMESEGMENT];				//布防时间，一周7天+假日，每天可以设置8个时间段
    char				szLinkAlarmout[MAX_ALARMOUT][MAX_LEN_LINK_IO_ID+1];		//触发报警输出号
    BYTE				byReserved[64];					//保留64字节
} HY_IO_ALARMIN_CFG;

//函数作用：码流数据回调函数
//参数
//lStream:      [out]  码流句柄即HYRequestStream的返回值
//pStream:      [out]  码流数据(格式为tagStreamHeader头 + 数据域)
//nLen:         [out]  数据长度
//nFrameType:   [out]  帧数据类型(0: Audio, 1: Header, 2: V-I, 3: V-P, 4: V-B, 5: 无数据)
//返回：无
typedef void (CALLBACK *HYMediaStreamInfo)(LONG lStream, BYTE *pStream, int nLen, int nFrameType); 

//函数作用：码流数据回调函数(扩展)
//参数
//lStream:						[out]  码流句柄即HYRequestStream的返回值
//pStream:						[out]  码流数据(格式为tagStreamHeader头 + 数据域)
//nLen:							[out]  数据长度
//pFrameInfo:				[out]  帧信息
//返回：无
typedef void (CALLBACK *HYMediaStreamInfoEx)(LONG lStream, BYTE *pStream, int nLen, HY_FRAME_INFO* pFrameInfo); 

//函数作用：设备在线状态回调函数
//参数
//nLogin:       [out]  登录句柄即HYLoginIPC的返回值。
//nState:       [out]  设备状态（0表示在线， 1表示重连， 2表示不在线）
//返回：无
typedef void (CALLBACK *HYIPCOnlineState)(int nLogin, int nState); 

//函数作用：升级进度回调函数
//参数
//nLogin:				[out]  登录句柄即HYLoginIPC的返回值。
//lpUpgradeStatus:		[out]  升级状态信息
//nUser:				[out]  用户自定义数据
//返回：无
typedef void(CALLBACK *HYUpgradeCallBack)(int nLogin,LPHY_UPGRADE_STATUS lpUpgradeStatus, int nUser);

//函数说明: 音频数据回调接口
//参数
//lVoiceComHandle:						[out]  HYStartVoiceCom或HYStartVoiceComMR的返回值
//pData:								[out]  音频数据(PCM，采样频率为8000，16位,，单通道)
//nLen:									[out]  数据长度
//byAudioFlag:							[out]  音频数据类型：0－本地采集的数据；1－设备发送过来的语音数据
//pUser:								[out]  用户数据指针
//返回值：                     无
typedef void (CALLBACK *HYVoiceDataCallback)(LONG lVoiceComHandle, char *pData, int nLen, BYTE byAudioFlag, void *pUser);

//函数作用：下载数据回调函数
//参数
//lDownloadHandle:      [out]  下载句柄即HYRemoteGetFileByTime的返回值
//pStream:				[out]  码流数据(格式为tagStreamHeader头 + 数据域)
//nLen:					[out]  数据长度
//nFrameType:			[out]  帧数据类型(0: Audio, 1: Header, 2: V-I, 3: V-P, 4: V-B, 5: 无数据)
//pUser:				[out]  用户数据指针
//返回：无
typedef void(CALLBACK *HYDownloadDataCallBack)(LONG lDownloadHandle, BYTE *pStream, int nLen, int nFrameType, void *pUser);


//函数作用：初始化sdk
//参数
//无
//返回：错误码
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYIpcInit(); 

//函数作用：释放sdk
//参数
//无
//返回：错误码
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYIpcClean(); 

//函数作用：设置解析服务器地址
//参数
//szIp:            [in]  解析服务器ip
//wPort:           [in]  解析服务器端口
//返回：           [out] 错误码
extern "C" /*__declspec(dllexport)*/ void  WINAPI  HYSetIpSvrAddr(char *szIp, WORD wPort);

//函数作用：从ip服务器查询ip
//参数
//szNo:            [in]  设备序列号
//szOutIp:         [out] 设备外网ip
//szInIp:          [out] 设备内网ip
//pPort:           [out] 设备端口
//返回：           [out] 错误码
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYGetIPByResolveSvr(char *szNo, char *szOutIp, char *szInIp, WORD *pPort);

//函数作用：设置登录超时
//参数   
//nWaitTime:       [in]  每次登录超时时间(单位毫秒)
//nTryTimes:       [in]  最大登陆次数
//返回： 无意义
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYSetConnectTimeout(int nWaitTime, int nTryTimes);

//函数作用：设置断线重连
//参数
//bEnable:          [in]  是否断线重连
//nReconInterval:   [in]  断线重连间隔时间（单位毫秒)
//返回： 无意义
extern "C" /*__declspec(dllexport)*/ void  WINAPI  HYSetReconnect(BOOL bEnable, int nReconInterval);

//函数作用：报警信息回调
//参数
//szIp:             [out] 设备ip
//wCmd:             [out] 报警类型(见协议）
//pData:            [out] 报警详细信息
//nDataLen:         [out] 报警详细信息长度
//返回： 无
typedef void (CALLBACK *CallbackAlarmInfo) (char* szIp, unsigned short wCmd, char* pData, int nDataLen);

//函数作用：创建一个报警服务(可创建多个服务)
//参数
//wPort:            [in] 报警服务监听端口
//返回：            [out]错误码
extern "C" /*__declspec(dllexport)*/  int WINAPI HYCreateAlarmService(unsigned short wPort);                        

//函数作用：关闭一个报警服务
//参数
//wPort:            [in] 报警服务监听端口
//返回：            [out]错误码
extern "C" /*__declspec(dllexport)*/  int WINAPI HYCloseAlarmService(unsigned short wPort);                          

//函数作用：注册报警服务回调
//参数
//lpfnCallbackAlarm:[in] 接收报警信息回调函数
//返回：                 无
void WINAPI RegAlarmCallback(CallbackAlarmInfo lpfnCallbackAlarm);             //报警回调 

//函数作用：登录设备(只支持登录64个)
//参数
//szDevId:          [in]  设备id(设备重连时使用， 为NULL表示直接表示直接利用pIpInfo参数重连， 否则则查询ip解析服务器重连) 
//szIp:             [in]  设备ip 
//wPort:            [in]  设备通信端口
//szUserName:       [in]  设备用户名(最多9个CHAR)
//szPwd:            [in]  设备密码(最多32个CHAR) 
//pLimit:           [out] 该用户所对应的权限
//返回：            [out] -1表示失败，其他值作为HYLogoutIPC等函数的参数。获取错误码调用HYGetLastError
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYLoginIPC(char *szDevId, char *szIp, WORD wPort, 
															 char *szUserName, char *szPwd,unsigned char *pLimit);

//函数作用：注销登陆
//参数
//nLogin:           [in]  登录句柄即HYLoginIPC的返回值。
//返回： 无意义
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYLogoutIPC(int nLogin);

//函数作用：设备在线回调
//参数
//onLine:           [out]  设备在线状态回调函数
//返回： 无意义
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYOnLineRegister(HYIPCOnlineState onLine);

//函数作用：设置设备配置
//参数
//nLogin:           [in]  登录句柄即HYLoginIPC的返回值。
//wCmd:             [in]  设置设备指令（见协议）
//pData:            [in]  指令数据
//nDataLen:         [in]  pData的长度
//返回： 错误码
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYControlSet(int nLogin, WORD wCmd, char *pData, int nDataLen); 

//函数作用：设置设备配置(扩展)
//参数
//nLogin:           [in]  登录句柄即HYLoginIPC的返回值。
//wCmd:             [in]  设置设备指令（见协议）
//pData:            [in]  指令数据
//nDataLen:         [in]  pData的长度
//nChannel:         [in]  通道号
//返回： 错误码
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYControlSetEx(int nLogin, WORD wCmd, char *pData, int nDataLen, int nChannel = 0); 

//函数作用：获取设备配置
//参数
//nHandle:          [in]  登录成功后返回的设备句柄。
//wCmd:             [in]  获取设备指令（见协议）
//pSendData:        [in]  发送数据buffer
//nSendDataLen:     [in]  发送数据长度
//pReturnBuf:       [in, out] 返回数据buff
//nReturnBufLen：   [out] 返回实际需要的指令长度
//返回： 错误码
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYControlGet(int nHandle,unsigned short wCmd,char *pSendData,int nSendDataLen
																  ,char *pReturnBuf,int nReturnBufLen);

//函数作用：获取设备配置(扩展)
//参数
//nHandle:          [in]  登录成功后返回的设备句柄。
//wCmd:             [in]  获取设备指令（见协议）
//pSendData:        [in]  发送数据buffer
//nSendDataLen:     [in]  发送数据长度
//pReturnBuf:       [in, out] 返回数据buff
//nReturnBufLen：   [out] 返回实际需要的指令长度
//返回： 错误码
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYControlGetEx(int nHandle,unsigned short wCmd,char *pSendData,int nSendDataLen
																  ,char *pReturnBuf,int nReturnBufLen, int nChannel = 0);

//函数作用：注册码流回调
//参数
//Media:            [out]  码流数据回调函数。
//返回： 无意义
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYMediaRegister(HYMediaStreamInfo Media);

//函数作用：注册码流回调(扩展)
//参数
//Media:            [out]  码流数据回调函数。
//返回： 无意义
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYMediaRegisterEx(HYMediaStreamInfoEx MediaEx);

//函数作用：返回最后操作的错误码信息
//参数
//nErrorCode:   [in]  出错代码，HYGetLastError返回值。
//返回：        [out] 出错信息字符串。
extern "C" /*__declspec(dllexport)*/ char*  WINAPI  HYGetErrorMsg(int nErrorCode);

//函数作用：请求视频码流
//参数
//nLogin:       [in]  登录句柄即HYLoginIPC的返回值。
//nChannel:     [in]  设备通道号
//nKindofStream:[in]  码流种类（0： 主码流， 1： 子码流)
//wRecvPort:    [in]  接收端口
//返回：        [out] -1表示失败，其他值作为HYStopPlayBack等函数的参数。获取错误码调用HYGetLastError
extern "C" /*__declspec(dllexport)*/ LONG  WINAPI HYRequestStream(int nLogin, int nChannel, int nKindofStream, WORD wRecvPort); 

//函数作用：关闭视频码流
//参数
//reqStream:    [in]  码流句柄即HYRequestStream的返回值。
//返回：        [out] -1表示失败，其他值作为HYStopPlayBack等函数的参数。获取错误码调用HYGetLastError
extern "C" /*__declspec(dllexport)*/ BOOL  WINAPI HYCloseStream(LONG lStream);

//函数作用：获取最后操作的错误码
//参数
//返回：        [out] 最后操作的错误码。
extern "C" /*__declspec(dllexport)*/ int  WINAPI HYGetLastError();

//函数作用：请求语言码流
//参数
//lStream:      [in]  HYRequestStream返回值。
//返回：        [out] 成功为TRUE， 失败为FALSE
extern "C" /*__declspec(dllexport)*/ BOOL  WINAPI HYRequestSoundStream(LONG lStream); 

//函数作用：请求语言码流(扩展)
//参数
//lStream:      [in]  HYRequestStream返回值。
//返回：        [out] 成功为TRUE， 失败为FALSE
extern "C" /*__declspec(dllexport)*/ BOOL  WINAPI HYRequestSoundStreamEx(LONG lStream, int nChannel = 0); 

//函数作用：关闭语音码流
//参数
//lStream:      [in]  HYRequestStream返回值。
//返回：        [out] 无
extern "C" /*__declspec(dllexport)*/ void  WINAPI HYCloseSoundStream(LONG lStream); 

//函数作用：根据文件类型、时间查找设备录像文件
//参数
//nLogin:           [in]  登录句柄即HYLoginIPC的返回值
//pFindCond:        [in]  欲查找的文件条件信息结构
//返回：            [out] -1表示失败，其他值作为HYRemoteFindNextFile、HYRemoteFindClose等函数的参数。获取错误码调用HYGetLastError
extern "C" /*__declspec(dllexport)*/ LONG  WINAPI  HYRemoteFindFile(int nLogin, LPFILE_COND lpFindCond); 

//函数作用：获取查找到的文件信息
//参数
//nFindHandle:      [in]  文件查找句柄，HYRemoteFindFile的返回值
//lpFindData:       [out]  保存文件信息的指针
//返回：            [out] -1表示失败，其他值表示当前的获取状态等信息(获取文件信息成功、未查找到文件、正在查找请等待、没有更多的文件，查找结束、查找文件时异常)。获取错误码调用HYGetLastError
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYRemoteFindNextFile(LONG lFindHandle, LPFIND_DATA lpFindData); 

//函数作用：关闭文件查找，释放资源
//参数
//nFindHandle:      [in]  文件查找句柄HYRemoteFindFile的返回值
//返回：            [out] TRUE表示成功，FALSE表示失败。获取错误码调用HYGetLastError
extern "C" /*__declspec(dllexport)*/ BOOL  WINAPI  HYRemoteFindClose(LONG lFindHandle); 

//函数作用：按时间回放远程录像文件
//参数
//nLogin:       [in]  登录句柄即HYLoginIPC的返回值。
//pVodPara:     [in]  回放条件
//返回：        [out] 句柄。-1表示失败，其他值作为HYRemotePlayBackControl、HYStopRemotePlayBack等函数的参数。获取错误码调用HYGetLastError。
extern "C" /*__declspec(dllexport)*/ LONG  WINAPI HYRemotePlayBackByTime(int nLogin, LPVOD_PARA pVodPara); 

//函数说明: 远程录像回放控制。
//参数
//lPlayBackHandle:       [in]  HYRemotePlayBackByTime返回的句柄
//dwControlCode          [in]  获取设备指令（见协议）
//pInBuffer:			 [in]  发送数据buffer
//dwInLen:				 [in]  发送数据长度
//pOutBuffer:			 [in, out] 返回数据buff
//lpOutLen：			 [out] 返回实际需要的数据长度指针
//返回值：                是否操作成功
extern "C" /*__declspec(dllexport)*/ BOOL WINAPI HYRemotePlayBackControl(LONG lPlayHandle, DWORD dwControlCode,char *pInBuffer, DWORD dwInLen, char *pOutBuffer,DWORD *lpOutLen);

//函数说明: 停止远程录像回放。
//参数
//lPlayHandle:       [in]  HYRemotePlayBackByTime返回的句柄
//返回值：                是否操作成功
extern "C" /*__declspec(dllexport)*/ BOOL WINAPI HYStopRemotePlayBack(LONG lPlayHandle);

//函数说明: 远程录像回放抓图。
//参数
//lPlayHandle:       [in]  HYRemotePlayBackByTime返回的句柄
//szFileName:        [in]   抓图文件保存路径
//返回值：                是否操作成功
extern "C" /*__declspec(dllexport)*/ BOOL WINAPI HYRemotePlayBackCaptureFile(LONG lPlayHandle,char *szFileName);

//函数作用：按时间下载远程录像文件
//参数
//nLogin:				[in]  登录句柄即HYLoginIPC的返回值。
//pSavedFileName		[in] 下载后保存到PC机的文件路径，需为绝对路径 
//pVodPara:				[in]  回放条件
//返回：				[out] 下载句柄。-1表示失败，其他值作为HYRemotePlayBackControl、HYStopRemoteGetFile等函数的参数。获取错误码调用HYGetLastError。
extern "C" /*__declspec(dllexport)*/ LONG  WINAPI HYRemoteGetFileByTime(int nLogin, char *pSavedFileName, LPVOD_PARA pVodPara); 

//函数说明: 停止下载录像文件。
//参数
//lPlayHandle:			[in] 回放句柄，播放句柄，HYRemoteGetFileByName、HYRemoteGetFileByTime的返回值
//返回值：                是否操作成功
extern "C" /*__declspec(dllexport)*/ BOOL WINAPI HYStopRemoteGetFile(LONG lPlayHandle);

//函数作用：注册下载回调
//参数
//lPlayHandle:							[in] 回放下载句柄，HYRemoteGetFileByTime的返回值
//cbDownloadDataCallBack:				[in]  码流数据回调函数。
//pUser:								[in]  用户数据指针
//返回： 是否操作成功
extern "C" /*__declspec(dllexport)*/ BOOL  WINAPI  HYSetDownloadDataCallBack(LONG lPlayHandle, HYDownloadDataCallBack cbDownloadDataCallBack, void *pUser);


//函数作用：根据条件查找设备日志
//参数
//nLogin:           [in]  登录句柄即HYLoginIPC的返回值
//lpLogCond:        [in]  查找条件信息结构
//返回：            [out] -1表示失败，其他值作为HYRemoteFindNextFile、HYRemoteFindClose等函数的参数。获取错误码调用HYGetLastError
extern "C" /*__declspec(dllexport)*/ LONG  WINAPI  HYFindLog(int nLogin, LPHY_LOG_COND lpLogCond); 

//函数作用：逐条获取查找到的日志信息
//参数
//lFindLogHandle:	[in]  日志查找句柄，HYFindLog的返回值
//lpLogData:		[out]  保存日志信息的指针
//返回：            [out] -1表示失败。获取错误码调用HYGetLastError
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYFindNextLog(LONG lFindLogHandle, LPHY_LOG_DATA lpLogData); 

//函数作用：关闭日志查找，释放资源
//参数
//lFindLogHandle:	[in]  文件查找句柄HYFindLog的返回值
//返回：            [out] TRUE表示成功，FALSE表示失败。获取错误码调用HYGetLastError
extern "C" /*__declspec(dllexport)*/ BOOL  WINAPI  HYFindLogClose(LONG lFindLogHandle); 

//函数说明: 非预览抓图
//参数
//nLogin:				[in]	登录句柄即HYLoginIPC的返回值
//nChannel:				[in]	设备通道号
//szFileName:           [in]	抓图文件保存路径(完整路径)
//返回值：              [out]	是否成功
extern "C" /*__declspec(dllexport)*/  BOOL  WINAPI   HYSnapshot(int nLogin, int nChannel, LPHY_SNAPSHOT_PARA lpSnapshotPara, char *szFileName);

//函数说明: 开始远程升级设备固件
//参数
//nLogin:				[in]	登录句柄即HYLoginIPC的返回值
//nImgType:				[in]	升级文件类型 UPGRADE_IMG_TYPE
//szFileName:           [in]	升级文件保存路径
//返回值：              [out]	是否成功
extern "C" /*__declspec(dllexport)*/  BOOL  WINAPI   HYStartUpgrade(int nLogin, int nImgType, char *szFileName);

//函数作用：设备在线回调
//参数
//cbUpgrade:           [out]  升级进度回调函数
//返回： 无意义
extern "C" /*__declspec(dllexport)*/ int  WINAPI  HYUpgradeRegister(HYUpgradeCallBack cbUpgrade);

//函数作用：启动语音对讲
//参数
//nLogin:           [in]  登录句柄即HYLoginIPC的返回值
//nVoiceChannel:    [in]  语音通道号。对于设备本身的语音对讲通道为0
//pUser:			[in]  用户数据指针
//返回：            [out] -1表示失败，其他值作为HYStopVoiceCom等函数的参数。获取错误码调用HYGetLastError
extern "C" /*__declspec(dllexport)*/ LONG  WINAPI  HYStartVoiceCom(int nLogin, int nVoiceChannel, void *pUser); 

//函数作用：启动语音转发
//参数
//nLogin:           [in]  登录句柄即HYLoginIPC的返回值
//nVoiceChannel:    [in]  语音通道号。对于设备本身的语音对讲通道为0
//pUser:			[in]  用户数据指针
//返回：            [out] -1表示失败，其他值作为HYStopVoiceCom等函数的参数。获取错误码调用HYGetLastError
extern "C" /*__declspec(dllexport)*/ LONG  WINAPI  HYStartVoiceComMR(int nLogin, int nVoiceChannel, void *pUser); 

//函数说明: 转发语音数据
//参数
//lVoiceComHandle:						[in]  HYStartVoiceComMR的返回值
//pSendData:							[in]  音频数据(PCM，采样频率为8000，16位,，单通道)
//nDataLen:								[in]  数据长度
//pUser:								[in]  用户数据指针
//返回值：                     无
extern "C" /*__declspec(dllexport)*/ BOOL  WINAPI  HYVoiceComSendData(LONG lVoiceComHandle, char *pSendData, int nDataLen, void *pUser);

//函数作用：启动语音对讲或转发
//参数
//lVoiceComHandle:  [in]  HYStartVoiceCom的返回值
//返回：            [out] 是否成功。获取错误码调用HYGetLastError
extern "C" /*__declspec(dllexport)*/ BOOL  WINAPI  HYStopVoiceCom(LONG lVoiceComHandle); 

//函数说明: 注册对讲音频数据回调。
//参数
//bNeedCBNoEncData:			[in]  需要回调的语音数据类型：0- 编码后的语音数据，1- 编码前的PCM原始数据
//lpfnDecodeData:			[in]  解码数据回调接口
//pUser:					[in]  用户数据指针
//返回值：					[out] 无
extern "C" /*__declspec(dllexport)*/ void   WINAPI	 HYRegVoiceComDataCallback(BOOL bNeedCBNoEncData, HYVoiceDataCallback lpfnVoiceData, void *pUser);

#endif