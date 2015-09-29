#pragma once

#include "stdafx.h"

class CMessageEvent : public IDispEventImpl<0, CMessageEvent, &__uuidof(SSNetSdk_COM::IMessageEvent), &__uuidof(SSNetSdk_COM::__SSNetSdk_COM), 1, 0>
{
private:
    volatile BOOL                      m_bConnect;
    volatile BOOL                      m_bRunning;
    HANDLE                             m_hReconnect;

private:
    SSNetSdk_COM::ICOMClientPtr        m_comClient;

public:
    CMessageEvent();
    ~CMessageEvent();

    BOOL Initialize(SSNetSdk_COM::ICOMClientPtr comClient);
    BOOL Uninitialize();

    STDMETHOD(MessageEvent)(enum MsgTypez msg, _bstr_t msgContent);

    BEGIN_SINK_MAP(CMessageEvent)
        SINK_ENTRY_EX(0, __uuidof(SSNetSdk_COM::IMessageEvent), 1610743808, MessageEvent)
    END_SINK_MAP()

private:
    static unsigned int __stdcall ReconnectThreadFunc(VOID * pParam);
};