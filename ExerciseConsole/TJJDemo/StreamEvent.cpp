#include "stdafx.h"
#include "StreamEvent.h"

CStreamEvent::CStreamEvent(SSNetSdk_COM::ICOMClientPtr pClient,HWND wnd)
{
    pComClient = pClient;
    wndPlay = wnd;
}


CStreamEvent::~CStreamEvent(void)
{
    //DeleteCriticalSection(&m_InputLock);

    //if (INVALID_HANDLE_VALUE != m_hFile)
    //{
    //    CloseHandle(m_hFile);
    //}
}


STDMETHODIMP CStreamEvent::OnDisconnected(struct IComStreamer * streamer)
{
    //AfxMessageBox("¹Ø±ÕIStreamer");
    if(pStreamPlayer)
    {
    //    pStreamPlayer->Close();
        //pStreamPlayer = NULL;
        //pStreamPlayer->Release();
    }

    return S_OK;
}

STDMETHODIMP CStreamEvent::OnGotHeader(struct IComStreamer * streamer,SAFEARRAY * head)
{
    //char * pData = (char *)head->pvData;
    //SafeArrayAccessData(head,(void**)&pData);
    //bOpen = false;
    if(!pStreamPlayer && pComClient)
        pStreamPlayer = pComClient->CreateComStreamPlayer();
    if(pStreamPlayer)
        bOpen = pStreamPlayer->Open(head,(long)(wndPlay));
    //SafeArrayUnaccessData(head);
    //SAFEARRAYBOUND bound;

    return S_OK;
}

STDMETHODIMP CStreamEvent::OnGotMedia(struct IComStreamer * streamer,SAFEARRAY * media)
{
    // 	char * pData = (char *)media->pvData;
    // 	SafeArrayAccessData(media,(void**)&pData);
    if(pStreamPlayer)
        pStreamPlayer->InputStream(media);
    /*	SafeArrayUnaccessData(media);*/

    return S_OK;
}