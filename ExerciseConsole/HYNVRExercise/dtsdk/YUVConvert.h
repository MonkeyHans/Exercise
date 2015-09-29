#pragma once 

/**
 *	DESCRIPTION	: 将24位RGB图像转化为YUV420， 分辨率不变
 */
int  ConvertRGBtoYUV420(int w,int h,unsigned char *rgbdata,unsigned char *yuv);
/**
 *	DESCRIPTION	: 将YUV420转化为24位RGB图像， 分辨率不变
 */
void ConvertYUV420toRGB(unsigned char *yuv,unsigned char *dst_ori,int width,int height);
// 
// 



/**
 *	DESCRIPTION	: 将YUV422转化为24位RGB图像， 分辨率可以改变
 */
int YUV422toRGB_scale(unsigned char* src, int width_src, int height_src, unsigned char* dst, int width_dst, int height_dst);

/**
 *	DESCRIPTION	: 将YUV422或者YUV420中取得Y分量作为灰度图， 分辨率可以改变
 */
void GetYfromYUV_scale(unsigned char *yuv, int width_src, int height_src, unsigned char* dst, int width_dst, int height_dst);

/**
 *	DESCRIPTION	: 将32位的RGB数据改为24位的RGB数据
 */
void RGB32toRGB24(unsigned char *rgb32, unsigned char * rgb24, int width, int height);



/**
 *DESCRIPTION	: [2015-03-16  新增接口]，将YUV420转换是rgb24位数据并保存到文件
 */
void ConvertSaveYUV420(unsigned char * pYUV420, int width, int height, char * szFileName);

/**
 *DESCRIPTION	: [2015-03-16  新增接口]，将YUV420三个分量转换是rgb24位数据
 */
void ConvertY_U_V_420toRGB(unsigned char *pY, unsigned char * pU, unsigned char * pV, int nYStride, int nUVStride, unsigned char *rgb24, int width, int height);
/**
 *DESCRIPTION	: [2015-03-16  新增接口]，将YUV420三个分量转换保存成图像文件， 由szFileName的扩展名来决定保存类别
 *RETURN		:
				0,  成功
				-1, 检查输入pY, pU, pV值
				-2, 检查图像宽和高
				-3, 内存不足
				-4, 保存图像文件失败
 */ 
int ConvertSaveY_U_V_420(unsigned char *pY, unsigned char * pU, unsigned char * pV,  int nYStride, int nUVStride, int width, int height, char * szFileName);