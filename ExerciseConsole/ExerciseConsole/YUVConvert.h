#pragma once 

/**
 *	DESCRIPTION	: ��24λRGBͼ��ת��ΪYUV420�� �ֱ��ʲ���
 */
int  ConvertRGBtoYUV420(int w,int h,unsigned char *rgbdata,unsigned char *yuv);
/**
 *	DESCRIPTION	: ��YUV420ת��Ϊ24λRGBͼ�� �ֱ��ʲ���
 */
void ConvertYUV420toRGB(unsigned char *yuv,unsigned char *dst_ori,int width,int height);
// 
// 



/**
 *	DESCRIPTION	: ��YUV422ת��Ϊ24λRGBͼ�� �ֱ��ʿ��Ըı�
 */
int YUV422toRGB_scale(unsigned char* src, int width_src, int height_src, unsigned char* dst, int width_dst, int height_dst);

/**
 *	DESCRIPTION	: ��YUV422����YUV420��ȡ��Y������Ϊ�Ҷ�ͼ�� �ֱ��ʿ��Ըı�
 */
void GetYfromYUV_scale(unsigned char *yuv, int width_src, int height_src, unsigned char* dst, int width_dst, int height_dst);

/**
 *	DESCRIPTION	: ��32λ��RGB���ݸ�Ϊ24λ��RGB����
 */
void RGB32toRGB24(unsigned char *rgb32, unsigned char * rgb24, int width, int height);



/**
 *DESCRIPTION	: [2015-03-16  �����ӿ�]����YUV420ת����rgb24λ���ݲ����浽�ļ�
 */
void ConvertSaveYUV420(unsigned char * pYUV420, int width, int height, char * szFileName);

/**
 *DESCRIPTION	: [2015-03-16  �����ӿ�]����YUV420��������ת����rgb24λ����
 */
void ConvertY_U_V_420toRGB(unsigned char *pY, unsigned char * pU, unsigned char * pV, int nYStride, int nUVStride, unsigned char *rgb24, int width, int height);
/**
 *DESCRIPTION	: [2015-03-16  �����ӿ�]����YUV420��������ת�������ͼ���ļ��� ��szFileName����չ���������������
 *RETURN		:
				0,  �ɹ�
				-1, �������pY, pU, pVֵ
				-2, ���ͼ���͸�
				-3, �ڴ治��
				-4, ����ͼ���ļ�ʧ��
 */ 
int ConvertSaveY_U_V_420(unsigned char *pY, unsigned char * pU, unsigned char * pV,  int nYStride, int nUVStride, int width, int height, char * szFileName);