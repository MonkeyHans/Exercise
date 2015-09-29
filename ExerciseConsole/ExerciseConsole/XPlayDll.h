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

//20090608	//用于远程回放
XPLAYDLL_API BOOL WINAPI XPlay_InputDataEX(LONG nPort, PBYTE pBuf, DWORD nSize);

XPLAYDLL_API BOOL WINAPI XPlay_SetDisplayCallBack(LONG nPort,XDisplayCBFun DisplayCBFun);	//2011-04-26

XPLAYDLL_API BOOL WINAPI XPlay_ReleasePlayChn(long nPort); 

///< 设置或增加显示区域，可以做局部放大显示。
XPLAYDLL_API BOOL WINAPI XPlay_SetDisplayRegion(LONG nPort, HWND hShowWnd, RECT* pRegionRect, RECT *pShowWndRect);

///< @brief解码回调函数
typedef void (CALLBACK *XPlay_DecCBFun)(
	LONG lVideoID,             ///< [out] 播放器端口号
	char *pBuf,                ///< [out] 解码后的音视频数据指针
	long nSize,                ///< [out] 解码后的音视频数据pBuf的长度
	long nWidth,               ///< [out] 画面宽度，单位像素。如果是音频数据则为音频声道数
	long nHeight,              ///< [out] 画面高度，单位像素。如果是音频数据则为样位率
	long nStamp,               ///< [out] 时标信息，单位毫秒。
	BYTE nType,                ///< [out] 数据类型，参考ENUM_XPLAY_DECDATA_TYPE。
	long nFrameRate,           ///< [out] 编码时产生的图像帧率，如果为音频数据则为采样率。
	DWORD dwFrameNum,          ///< [out] 帧号，如未提供时，该值默认值为-1。
	DWORD dwUser,              ///< [out] 用户数据
	long nReserved             ///< [out] 保留数据，未使用。
);

XPLAYDLL_API BOOL WINAPI XPlay_SetDecCallBackMend(LONG nPort, XPlay_DecCBFun pfDecCBFun, LONG lVideoID, DWORD dwUser);


#endif