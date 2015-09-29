#pragma  once
typedef unsigned char BYTE;
typedef int  BOOL;

/************************************************************************/
/* 检测结果结构体                                   */
/************************************************************************/
typedef struct 
{
	int pianse;//偏色
	int pianliang;//偏亮
	int pianan;//偏暗
	int mohu;//模糊
	int gunping;//滚屏， 暂不支持
	int zaosheng;//噪声 //雪花
	int diushi;//视频丢失
	int doudong;//视频抖动
	int zhedang;//遮挡
	int ganranwen; //干扰纹 2014/5/22 增加
}Result;
//Result结构体的所有成员取值都为0~99


/************************************************************************************************************************************
 *FUNCTION		:	DetectQualityDll
 *DESCRIPTION	:	视频质量诊断主要函数
 							需要检测的每个通道都有一个连续诊断帧数，就是要输入这么多帧才会给出一个较为正确的结果
 							该接口需要逐帧输入图像数据，每输入一帧数据，result都会有结果返回，但要以该通道连续帧数的最后帧为准。
 							用一个检测器检测多个视频，每个视频轮流取10帧输入即可分别得到各个视频的检测结果
 *PARAMETER		:	
 							idetector	[IN]	检测器序号，取值为0~29，这是为多个检测器同时工作设置的；如果是单个检测器，只要取其中的一个序号的检测器即可
							channel     [IN]	通道号， 相当摄像头的ID，　不可重复, 取值0~255
 							pRGB			[IN]	输入的图像24位的RGB位图数据
 							result		[OUT]	用来返回检测结果的数据结构体
 							width			[IN]  图像的宽
 							height		[IN]	图像的高
 *RETURN			：无用
 ***********************************************************************************************************************************/
//extern "C"  int __stdcall DetectQualityDll(int idetector,BYTE* pRGB, Result* result, int width , int height);
extern "C"  int __stdcall DetectQualityDll(int idetector, BYTE channel, BYTE* pRGB, Result* result, int width , int height);

/************************************************************************************************************************************
 *FUNCTION		:	ResetQualityDetector
 *DESCRIPTION	:	重置视频质量诊断检测器，使得该检测器重新累计诊断结果。
					若是用该检测器检测另外一个视频图像序列，请调用该函数以确保开始新的检测
 *PARAMETER		:	
 							idetector	[IN]	检测器序号，取值为0~29
 						
 *RETURN			：无用
 ***********************************************************************************************************************************/
extern "C"  int __stdcall ResetQualityDetector(int idetector);


/************************************************************************************************************************************
 *FUNCTION		:	DetectMovementDll
 *DESCRIPTION	:	用两张图像检测转动
 *PARAMETER		:
 							idetector	[IN]	检测器序号，取值为0~29，与DetectQualityDll里的idetector是相互独立的，用法一样
 							pRGB1			[IN]	第一张图像，输入的图像24位的RGB位图数据
 							width1		[IN]  
 							height1		[IN]
 							pRGB2			[IN]	第二张图像
 							width2		[IN]	
 							height2		[IN]
 *RETURN 			: 返回结果是转动程度， 取值0~99
 *************************************************************************************************************************************/
extern "C"  int __stdcall DetectMovementDll(int idetector,BYTE* pRGB1,  int width1, int height1, BYTE* pRGB2,int width2, int height2);
// extern "C"  int __stdcall DetectMovementDll2(int idetector,BYTE* pRGB,int width, int height ,
// 																 BYTE* pRGB1,  int width1, int height1, BYTE* pRGB2,int width2, int height2);

/***************************************************************************************************************************************
 *FUNCTION		: SetMovementSensitive
 *DESCRITION	: 设置函数DetectMovementDll的检测灵敏度
 *PARAMETER		: 
 							idetector 	[IN]	与DetectMovementDll要对应
							channel     [IN]	通道号， 相当摄像头的ID，　不可重复,取值0~255
 							s						[IN]	灵敏度值，取值0~10， 越大越灵敏，默认为5
 *RETURN			: 无用
 ***************************************************************************************************************************************/
extern "C"  int __stdcall SetMovementSensitive(int idetector, BYTE channel, int s);

/***************************************************************************************************************************************
 *FUNCTION		: SetVQFrameNum
 *CREATE BY		: RICHARD LEE
 *DESCRITION	: 设置在一个循环检测中每个通道的连续帧数， 默认都是30帧
 *PARAMETER		: 
							idetector 	[IN]	与DetectMovementDll要对应
							channel     [IN]	通道号， 相当摄像头的ID，　不可重复,取值0~255
 							nframe 	[IN]	帧数， 要大于10
 *RETURN			: 之前用的帧数
 ***************************************************************************************************************************************/
extern "C"  int __stdcall SetVQFrameNum(int idetector, BYTE channel, int nframe);

/***************************************************************************************************************************************
 *FUNCTION		: SetVQDetectType
 *CREATE BY		: RICHARD LEE
 *DESCRITION	: 设置检测类型，哪些需要检测，哪些不需要检测, 默认是全部都检测的
 *PARAMETER		: 
							idetector 	[IN]	与DetectMovementDll要对应
							channel     [IN]	通道号， 相当摄像头的ID，　不可重复,取值0~255
 							各个检测项目参数   设置为非0则要检测，设置为0则不需要检测
								丢失与遮挡是由参数bDiushi_Zhedang同时设置
 *RETURN			: 
 ***************************************************************************************************************************************/
extern "C"  int __stdcall SetVQDetectType(int idetector, BYTE channel,
															   BOOL bPianse, BOOL bPianliang, BOOL bPianan, BOOL bMohu,
															   BOOL bZaosheng, BOOL bDiushi_Zhedang, BOOL bDoudong);

/***************************************************************************************************************************************
*FUNCTION		: SetLogFilePath
*DESCRITION		: 设置日志文件路径,默认是自动在执行程序目录下创建
*PARAMETER		: 
				logfile  [IN]  完整的文件路径
*RETURN			: 无用
 ***************************************************************************************************************************************/
extern "C"  int __stdcall SetLogFilePath(char * logfile);

//以下两个函数 忽略
//extern "C"  void __stdcall ResetDll(int idetector);
//extern "C"  int __stdcall ZoomDIB(int idetector,BYTE* pDIBData, int Width, int Height, BYTE* pDIBNewData);

/***************************************************************************************
 *	FUNCTION	:	DetectTiaowen
 *	DESCRIPTION	:	检测条纹干扰
				因条纹干扰检测需要  32  帧，所以单独检测。

 *  PARAMTER	:
							idetector 	[IN]	检测器，用于多线程检测；不同线程用不同检测器，取值区间[0, 29]
							channel     [IN]	通道号， 相当摄像头的ID，　不可重复,取值0~255
							pRGB		[IN]	三通道位图的数据
							width, height		[IN]	图像的宽，高
							result	[OUT]	返回条纹干扰检测结果的参数， 取值范围是0~99
 *	RETURN		:	返回
						0， 需要继续压入帧
						1， 表示该通道的条纹干扰检测结果已得到
 ***************************************************************************************/
extern "C"  int __stdcall DetectTiaowen(int idetector, int channel, BYTE *pRGB, int width, int height, int *result);
/////////////////////////////////////////////////////////////////////////////
