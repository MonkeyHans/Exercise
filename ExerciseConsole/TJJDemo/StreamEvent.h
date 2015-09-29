
#pragma once

#include "stdafx.h"
#include <list>

using namespace SSNetSdk_COM;

struct tagVideoData
{
    BYTE *  pcbData;
    DWORD   dwDataSize;
};

class CStreamEvent : public IDispEventImpl<0,CStreamEvent,&(__uuidof(SSNetSdk_COM::IComStreamerEvent)),&(__uuidof(SSNetSdk_COM::__SSNetSdk_COM)),1,0>
{
private:
    SSNetSdk_COM::ICOMClientPtr pComClient;
    SSNetSdk_COM::IComStreamPlayerPtr pStreamPlayer;
    HWND wndPlay;
    bool bOpen;

public:
    CStreamEvent(SSNetSdk_COM::ICOMClientPtr pClient,HWND wnd);
    ~CStreamEvent(void);

public:
    STDMETHOD(OnDisconnected)(struct IComStreamer * streamer);
    STDMETHOD(OnGotHeader)(struct IComStreamer * streamer,SAFEARRAY * head);
    STDMETHOD(OnGotMedia)(struct IComStreamer * streamer,SAFEARRAY * media);

    BEGIN_SINK_MAP(CStreamEvent)
        SINK_ENTRY_EX(0,(__uuidof(SSNetSdk_COM::IComStreamerEvent)),100,OnDisconnected)
        SINK_ENTRY_EX(0,(__uuidof(SSNetSdk_COM::IComStreamerEvent)),101,OnGotHeader)
        SINK_ENTRY_EX(0,(__uuidof(SSNetSdk_COM::IComStreamerEvent)),102,OnGotMedia)
    END_SINK_MAP()
};