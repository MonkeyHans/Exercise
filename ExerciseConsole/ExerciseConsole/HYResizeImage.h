#pragma once


void HYResizeJPGFile(char * szSrc, char * szDst, int dw, int dh);

/******************************************************************
 * NAME		:	HYResizeImage
 *	DESCRIPTION	: 
							将图像缩小或者放大
 *	PARAMETER	:
				@pRGB			[in]		源图像数据， RGB24位
				@width, height	[in]		源图像宽高
				@pDst		[in, out]			目标图像内存地址，需要预先分配后将地址传入
				@dw, dh		[in]  目标图像的宽高
 *	RETURN	:
 ******************************************************************/

void HYResizeImage(unsigned char * pRGB, int width, int height, unsigned char * pDst, int dw, int dh);