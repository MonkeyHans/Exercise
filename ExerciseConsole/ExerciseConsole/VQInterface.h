#pragma  once
typedef unsigned char BYTE;
typedef int  BOOL;

/************************************************************************/
/* ������ṹ��                                   */
/************************************************************************/
typedef struct 
{
	int pianse;//ƫɫ
	int pianliang;//ƫ��
	int pianan;//ƫ��
	int mohu;//ģ��
	int gunping;//������ �ݲ�֧��
	int zaosheng;//���� //ѩ��
	int diushi;//��Ƶ��ʧ
	int doudong;//��Ƶ����
	int zhedang;//�ڵ�
	int ganranwen; //������ 2014/5/22 ����
}Result;
//Result�ṹ������г�Աȡֵ��Ϊ0~99


/************************************************************************************************************************************
 *FUNCTION		:	DetectQualityDll
 *DESCRIPTION	:	��Ƶ���������Ҫ����
 							��Ҫ����ÿ��ͨ������һ���������֡��������Ҫ������ô��֡�Ż����һ����Ϊ��ȷ�Ľ��
 							�ýӿ���Ҫ��֡����ͼ�����ݣ�ÿ����һ֡���ݣ�result�����н�����أ���Ҫ�Ը�ͨ������֡�������֡Ϊ׼��
 							��һ��������������Ƶ��ÿ����Ƶ����ȡ10֡���뼴�ɷֱ�õ�������Ƶ�ļ����
 *PARAMETER		:	
 							idetector	[IN]	�������ţ�ȡֵΪ0~29������Ϊ��������ͬʱ�������õģ�����ǵ����������ֻҪȡ���е�һ����ŵļ��������
							channel     [IN]	ͨ���ţ� �൱����ͷ��ID���������ظ�, ȡֵ0~255
 							pRGB			[IN]	�����ͼ��24λ��RGBλͼ����
 							result		[OUT]	�������ؼ���������ݽṹ��
 							width			[IN]  ͼ��Ŀ�
 							height		[IN]	ͼ��ĸ�
 *RETURN			������
 ***********************************************************************************************************************************/
//extern "C"  int __stdcall DetectQualityDll(int idetector,BYTE* pRGB, Result* result, int width , int height);
extern "C"  int __stdcall DetectQualityDll(int idetector, BYTE channel, BYTE* pRGB, Result* result, int width , int height);

/************************************************************************************************************************************
 *FUNCTION		:	ResetQualityDetector
 *DESCRIPTION	:	������Ƶ������ϼ������ʹ�øü���������ۼ���Ͻ����
					�����øü�����������һ����Ƶͼ�����У�����øú�����ȷ����ʼ�µļ��
 *PARAMETER		:	
 							idetector	[IN]	�������ţ�ȡֵΪ0~29
 						
 *RETURN			������
 ***********************************************************************************************************************************/
extern "C"  int __stdcall ResetQualityDetector(int idetector);


/************************************************************************************************************************************
 *FUNCTION		:	DetectMovementDll
 *DESCRIPTION	:	������ͼ����ת��
 *PARAMETER		:
 							idetector	[IN]	�������ţ�ȡֵΪ0~29����DetectQualityDll���idetector���໥�����ģ��÷�һ��
 							pRGB1			[IN]	��һ��ͼ�������ͼ��24λ��RGBλͼ����
 							width1		[IN]  
 							height1		[IN]
 							pRGB2			[IN]	�ڶ���ͼ��
 							width2		[IN]	
 							height2		[IN]
 *RETURN 			: ���ؽ����ת���̶ȣ� ȡֵ0~99
 *************************************************************************************************************************************/
extern "C"  int __stdcall DetectMovementDll(int idetector,BYTE* pRGB1,  int width1, int height1, BYTE* pRGB2,int width2, int height2);
// extern "C"  int __stdcall DetectMovementDll2(int idetector,BYTE* pRGB,int width, int height ,
// 																 BYTE* pRGB1,  int width1, int height1, BYTE* pRGB2,int width2, int height2);

/***************************************************************************************************************************************
 *FUNCTION		: SetMovementSensitive
 *DESCRITION	: ���ú���DetectMovementDll�ļ��������
 *PARAMETER		: 
 							idetector 	[IN]	��DetectMovementDllҪ��Ӧ
							channel     [IN]	ͨ���ţ� �൱����ͷ��ID���������ظ�,ȡֵ0~255
 							s						[IN]	������ֵ��ȡֵ0~10�� Խ��Խ������Ĭ��Ϊ5
 *RETURN			: ����
 ***************************************************************************************************************************************/
extern "C"  int __stdcall SetMovementSensitive(int idetector, BYTE channel, int s);

/***************************************************************************************************************************************
 *FUNCTION		: SetVQFrameNum
 *CREATE BY		: RICHARD LEE
 *DESCRITION	: ������һ��ѭ�������ÿ��ͨ��������֡���� Ĭ�϶���30֡
 *PARAMETER		: 
							idetector 	[IN]	��DetectMovementDllҪ��Ӧ
							channel     [IN]	ͨ���ţ� �൱����ͷ��ID���������ظ�,ȡֵ0~255
 							nframe 	[IN]	֡���� Ҫ����10
 *RETURN			: ֮ǰ�õ�֡��
 ***************************************************************************************************************************************/
extern "C"  int __stdcall SetVQFrameNum(int idetector, BYTE channel, int nframe);

/***************************************************************************************************************************************
 *FUNCTION		: SetVQDetectType
 *CREATE BY		: RICHARD LEE
 *DESCRITION	: ���ü�����ͣ���Щ��Ҫ��⣬��Щ����Ҫ���, Ĭ����ȫ��������
 *PARAMETER		: 
							idetector 	[IN]	��DetectMovementDllҪ��Ӧ
							channel     [IN]	ͨ���ţ� �൱����ͷ��ID���������ظ�,ȡֵ0~255
 							���������Ŀ����   ����Ϊ��0��Ҫ��⣬����Ϊ0����Ҫ���
								��ʧ���ڵ����ɲ���bDiushi_Zhedangͬʱ����
 *RETURN			: 
 ***************************************************************************************************************************************/
extern "C"  int __stdcall SetVQDetectType(int idetector, BYTE channel,
															   BOOL bPianse, BOOL bPianliang, BOOL bPianan, BOOL bMohu,
															   BOOL bZaosheng, BOOL bDiushi_Zhedang, BOOL bDoudong);

/***************************************************************************************************************************************
*FUNCTION		: SetLogFilePath
*DESCRITION		: ������־�ļ�·��,Ĭ�����Զ���ִ�г���Ŀ¼�´���
*PARAMETER		: 
				logfile  [IN]  �������ļ�·��
*RETURN			: ����
 ***************************************************************************************************************************************/
extern "C"  int __stdcall SetLogFilePath(char * logfile);

//������������ ����
//extern "C"  void __stdcall ResetDll(int idetector);
//extern "C"  int __stdcall ZoomDIB(int idetector,BYTE* pDIBData, int Width, int Height, BYTE* pDIBNewData);

/***************************************************************************************
 *	FUNCTION	:	DetectTiaowen
 *	DESCRIPTION	:	������Ƹ���
				�����Ƹ��ż����Ҫ  32  ֡�����Ե�����⡣

 *  PARAMTER	:
							idetector 	[IN]	����������ڶ��̼߳�⣻��ͬ�߳��ò�ͬ�������ȡֵ����[0, 29]
							channel     [IN]	ͨ���ţ� �൱����ͷ��ID���������ظ�,ȡֵ0~255
							pRGB		[IN]	��ͨ��λͼ������
							width, height		[IN]	ͼ��Ŀ���
							result	[OUT]	�������Ƹ��ż�����Ĳ����� ȡֵ��Χ��0~99
 *	RETURN		:	����
						0�� ��Ҫ����ѹ��֡
						1�� ��ʾ��ͨ�������Ƹ��ż�����ѵõ�
 ***************************************************************************************/
extern "C"  int __stdcall DetectTiaowen(int idetector, int channel, BYTE *pRGB, int width, int height, int *result);
/////////////////////////////////////////////////////////////////////////////
