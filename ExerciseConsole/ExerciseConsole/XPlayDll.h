//XPlayDll.h
//

#pragma once

#ifndef XPLAYDLL_H
#define XPLAYDLL_H

#define XPLAYDLL_API extern "C" __declspec( dllimport )

//Stream type
#define STREAME_REALTIME 0
#define STREAME_FILE	 1
#define INITPLAY_HEAD_LENGTH		4

typedef void (CALLBACK *XDisplayCBFun)(long nPort,char * pBuf,long nSize,long nWidth,long nHeight,long nStamp,long nType,long nReserved);

// added by Alvin.zeng 20140417 begin
typedef void (CALLBACK *FileRefDoneCallBack)(long nPort, void *pUser);
XPLAYDLL_API void WINAPI XPlay_FileRefCallBack(FileRefDoneCallBack pFileRefDoneCallBack, DWORD dwType);
// added by Alvin.zeng 20140417 end
XPLAYDLL_API BOOL WINAPI XPlay_InitPlayChn(WORD nPort, PBYTE pHeadBuf, DWORD dwHeadSize);
XPLAYDLL_API BOOL WINAPI XPlay_SetStreamOpenMode(long nPort, DWORD nMode);
XPLAYDLL_API BOOL WINAPI XPlay_OpenStream(LONG nPort, PBYTE pHeadBuf, DWORD nSize);
XPLAYDLL_API BOOL WINAPI XPlay_CloseStream(LONG nPort);
XPLAYDLL_API BOOL WINAPI XPlay_InputData(LONG nPort, PBYTE pBuf, DWORD nSize);
XPLAYDLL_API BOOL WINAPI XPlay_Play(LONG nPort, HWND hWnd);
XPLAYDLL_API BOOL WINAPI XPlay_Stop(LONG nPort);
XPLAYDLL_API BOOL WINAPI XPlay_SavePic(LONG nPort, char* szFilename);
XPLAYDLL_API BOOL WINAPI XPlay_StartAudio(LONG nPort);
XPLAYDLL_API BOOL WINAPI XPlay_StopAudio();
XPLAYDLL_API BOOL WINAPI XPlay_ResetSourceBuffer(LONG nPort);
XPLAYDLL_API DWORD WINAPI XPlay_GetFileHeadLength(LONG nPort);

//20081024
XPLAYDLL_API LONG WINAPI XPlay_InitPlayChnEX(PBYTE pHeadBuf, DWORD dwHeadSize);

//20081026
XPLAYDLL_API DWORD WINAPI XPlay_GetSourceBufferRemain(LONG nPort);

//20081027 V1.1.3.0
XPLAYDLL_API BOOL WINAPI XPlay_Fast(LONG nPort);
XPLAYDLL_API BOOL WINAPI XPlay_Slow(LONG nPort);
XPLAYDLL_API BOOL WINAPI XPlay_SetPause(long nPort, bool bPause);

//20081122 V2.0
XPLAYDLL_API LONG WINAPI XPlay_OpenFile(LPSTR szFileName, HWND hWnd, UINT nMsg, void (CALLBACK *pFileRefDone)(DWORD nPort,DWORD nUser),DWORD nUser);
XPLAYDLL_API BOOL WINAPI XPlay_CloseFile(long nPort);
//XPLAYDLL_API BOOL WINAPI XPlay_SetFileEndMsg(long nPort, HWND hWnd, UINT nMsg);
XPLAYDLL_API DWORD WINAPI XPlay_GetFileTime(long nPort);
XPLAYDLL_API DWORD WINAPI XPlay_GetPlayedTime(long nPort);
XPLAYDLL_API DWORD WINAPI XPlay_GetFileTotalFrames(long nPort);
XPLAYDLL_API DWORD WINAPI XPlay_GetCurrentFrameNum(long nPort);
XPLAYDLL_API BOOL WINAPI XPlay_SetCurrentFrameNum(long nPort, DWORD nFrameNum);
XPLAYDLL_API BOOL WINAPI XPlay_PlayOneByOne(long nPort);
XPLAYDLL_API BOOL WINAPI XPlay_PlayOneByOneBack(long nPort);
XPLAYDLL_API BOOL WINAPI XPlay_RigisterDrawFun(LONG nPort, void (CALLBACK* DrawFun)(long nPort, HDC hDc, LONG nUser), LONG nUser);
//XPLAYDLL_API BOOL WINAPI XPlay_SetFileRefCallBack(LONG nPort, void (CALLBACK *pFileRefDone)(DWORD nPort,DWORD nUser),DWORD nUser,LPSTR szFileName);

//20090219
XPLAYDLL_API BOOL WINAPI XPlay_OpenStreamEX(LONG nPort, HWND hWnd, PBYTE pHeadBuf, DWORD nSize, DWORD nMode);

//20090430
XPLAYDLL_API BOOL WINAPI XPlay_InitSDK(HWND hWnd, UINT nMsg);

//20090608	//����Զ�̻ط�
XPLAYDLL_API BOOL WINAPI XPlay_InputDataEX(LONG nPort, PBYTE pBuf, DWORD nSize);

XPLAYDLL_API BOOL WINAPI XPlay_SetDisplayCallBack(LONG nPort,XDisplayCBFun DisplayCBFun);	//2011-04-26

XPLAYDLL_API BOOL WINAPI XPlay_ReleasePlayChn(long nPort); 

///< ���û�������ʾ���򣬿������ֲ��Ŵ���ʾ��
XPLAYDLL_API BOOL WINAPI XPlay_SetDisplayRegion(LONG nPort, HWND hShowWnd, RECT* pRegionRect, RECT *pShowWndRect);

///< @brief����ص�����
typedef void (CALLBACK *XPlay_DecCBFun)(
	LONG lVideoID,             ///< [out] �������˿ں�
	char *pBuf,                ///< [out] ����������Ƶ����ָ��
	long nSize,                ///< [out] ����������Ƶ����pBuf�ĳ���
	long nWidth,               ///< [out] �����ȣ���λ���ء��������Ƶ������Ϊ��Ƶ������
	long nHeight,              ///< [out] ����߶ȣ���λ���ء��������Ƶ������Ϊ��λ��
	long nStamp,               ///< [out] ʱ����Ϣ����λ���롣
	BYTE nType,                ///< [out] �������ͣ��ο�ENUM_XPLAY_DECDATA_TYPE��
	long nFrameRate,           ///< [out] ����ʱ������ͼ��֡�ʣ����Ϊ��Ƶ������Ϊ�����ʡ�
	DWORD dwFrameNum,          ///< [out] ֡�ţ���δ�ṩʱ����ֵĬ��ֵΪ-1��
	DWORD dwUser,              ///< [out] �û�����
	long nReserved             ///< [out] �������ݣ�δʹ�á�
);

XPLAYDLL_API BOOL WINAPI XPlay_SetDecCallBackMend(LONG nPort, XPlay_DecCBFun pfDecCBFun, LONG lVideoID, DWORD dwUser);


#endif