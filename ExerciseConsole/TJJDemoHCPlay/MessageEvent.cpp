#include "stdafx.h"
#include "MssageEvent.h"
#include <process.h>

CComModule _Module;

CMessageEvent::CMessageEvent()
{
    _Module.Init(NULL, AfxGetInstanceHandle());

    m_bConnect = FALSE;
    m_bRunning = FALSE;
    m_hReconnect = NULL;
}

CMessageEvent::~CMessageEvent()
{

}

BOOL CMessageEvent::Initialize(SSNetSdk_COM::ICOMClientPtr comClient)
{
    m_comClient = comClient;
    m_bRunning = TRUE;
    if (NULL == m_hReconnect)
    {
        m_hReconnect = (HANDLE) _beginthreadex(NULL, 0, ReconnectThreadFunc, this, 0, NULL);
    }

    return 0;
}

BOOL CMessageEvent::Uninitialize()
{
    return 0;
}

STDMETHODIMP CMessageEvent::MessageEvent(enum MsgTypez msg, _bstr_t msgContent)
{
    //OutputDebugString(msgContent);
    
    if (SSNetSdk_COM::MsgTypez_ErrorDisonnected == msg)
    {
        OutputDebugString(TEXT("\tErrorDisconnected"));
    }
    else
    {
        OutputDebugString(TEXT("\tConnected"));
    }
    OutputDebugString(TEXT("\r\n"));

    return S_OK;
}

unsigned int __stdcall CMessageEvent::ReconnectThreadFunc(VOID * pParam)
{
    CMessageEvent * pThis = (CMessageEvent *) pParam;

    while (pThis->m_bRunning)
    {
        Sleep(5000);

        if (FALSE == pThis->m_bConnect)
        {
            if (VARIANT_TRUE == pThis->m_comClient->Login("192.168.20.171", 7011, "admin", "12345"))
            {

            }
        }
    }

    return 0;
}