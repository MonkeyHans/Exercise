#pragma once


void HYResizeJPGFile(char * szSrc, char * szDst, int dw, int dh);

/******************************************************************
 * NAME		:	HYResizeImage
 *	DESCRIPTION	: 
							��ͼ����С���߷Ŵ�
 *	PARAMETER	:
				@pRGB			[in]		Դͼ�����ݣ� RGB24λ
				@width, height	[in]		Դͼ����
				@pDst		[in, out]			Ŀ��ͼ���ڴ��ַ����ҪԤ�ȷ���󽫵�ַ����
				@dw, dh		[in]  Ŀ��ͼ��Ŀ��
 *	RETURN	:
 ******************************************************************/

void HYResizeImage(unsigned char * pRGB, int width, int height, unsigned char * pDst, int dw, int dh);