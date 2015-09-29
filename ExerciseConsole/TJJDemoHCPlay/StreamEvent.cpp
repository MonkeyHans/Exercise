#include "stdafx.h"
#include "StreamEvent.h"
#include <memory>




CStreamEvent::CStreamEvent(SSNetSdk_COM::ICOMClientPtr pClient,HWND wnd)
{
    pComClient = pClient;
    wndPlay = wnd;
    m_lPort = -1;
    m_bRunning = FALSE;
    m_hInputHandle = NULL;
    InitializeCriticalSection(&m_InputLock);
    if (FALSE == PlayM4_GetPort(&m_lPort))
    {
        MessageBox(NULL, TEXT("PlayM4_GetPort Error"), "PLAY", MB_OK);
    }
}


CStreamEvent::~CStreamEvent(void)
{
    DeleteCriticalSection(&m_InputLock);
}


STDMETHODIMP CStreamEvent::OnDisconnected(struct IComStreamer * streamer)
{
    //AfxMessageBox("¹Ø±ÕIStreamer");
    //if(pStreamPlayer)
    //{
    //    pStreamPlayer->Close();
        //pStreamPlayer = NULL;
        //pStreamPlayer->Release();
    //}
    if (FALSE == PlayM4_Stop(m_lPort))
    {
        MessageBox(NULL, TEXT("PlayM4_Stop Error"), "PLAY", MB_OK);
    }

    if (FALSE == PlayM4_CloseStream(m_lPort))
    {
        MessageBox(NULL, TEXT("PlayM4_CloseStream Error"), "PLAY", MB_OK);
    }

    m_bRunning = FALSE;
    if (NULL != m_hInputHandle)
    {
        CloseHandle(m_hInputHandle);
    }

    return S_OK;
}

STDMETHODIMP CStreamEvent::OnGotHeader(struct IComStreamer * streamer,SAFEARRAY * head)
{
    //char * pData = (char *)head->pvData;
    //SafeArrayAccessData(head,(void**)&pData);
    //bOpen = false;
    //if(!pStreamPlayer && pComClient)
    //    pStreamPlayer = pComClient->CreateComStreamPlayer();
    //if(pStreamPlayer)
    //    bOpen = pStreamPlayer->Open(head,(long)(wndPlay));
    //SafeArrayUnaccessData(head);
    //SAFEARRAYBOUND bound;

    if (FALSE == PlayM4_SetStreamOpenMode(m_lPort, STREAME_REALTIME))
    {
        MessageBox(NULL, TEXT("PlayM4_SetStreamOpenMode Error"), "PLAY", MB_OK);

        return S_OK;
    }

    BYTE * cbHeadData = (BYTE *) head->pvData;
    SafeArrayAccessData(head, (void **) &cbHeadData);

    try
    {
        DWORD dwHeadSize = head->rgsabound->cElements;
        BYTE * cbRebuildHead = new BYTE[dwHeadSize];
        memcpy_s(&cbRebuildHead[0], head->rgsabound->cElements, cbHeadData, head->rgsabound->cElements);

        if (FALSE == PlayM4_OpenStream(m_lPort, cbRebuildHead+4, dwHeadSize, 1024*1000))
        {
            MessageBox(NULL, TEXT("PlayM4_OpenStream Error"), "PLAY", MB_OK);
        }
        else
        {
            if (FALSE == PlayM4_Play(m_lPort, wndPlay))
            {
                MessageBox(NULL, TEXT("PlayM4_Play Error"), "PLAY", MB_OK);
            }
            else
            {
                m_bRunning = TRUE;
                m_hInputHandle = (HANDLE) _beginthreadex(NULL, 0, CStreamEvent::InputDataThreadFunc, this, 0, NULL);
            }
        }

        delete cbRebuildHead;
    }
    catch (...)
    {
    }

    SafeArrayUnaccessData(head);

    

    return S_OK;
}

STDMETHODIMP CStreamEvent::OnGotMedia(struct IComStreamer * streamer,SAFEARRAY * media)
{
    // 	char * pData = (char *)media->pvData;
    // 	SafeArrayAccessData(media,(void**)&pData);
    //if(pStreamPlayer)
    //    pStreamPlayer->InputStream(media);
    /*	SafeArrayUnaccessData(media);*/

    BYTE * cbMediaData = (BYTE *) media->pvData;
    SafeArrayAccessData(media, (void **) &cbMediaData);

    try
    {
        EnterCriticalSection(&m_InputLock);

        DWORD dwHeadSize = media->rgsabound->cElements;
        BYTE * cbRebuildData = new BYTE[dwHeadSize];
        memcpy_s(&cbRebuildData[0], media->rgsabound->cElements, cbMediaData, media->rgsabound->cElements);
        tagVideoData videoData = {0};
        videoData.pcbData = cbRebuildData;
        videoData.dwDataSize = media->rgsabound->cElements;
        m_InputData.push_back(videoData);
        LeaveCriticalSection(&m_InputLock);
    }
    catch (...)
    {
    }

    SafeArrayUnaccessData(media);

    return S_OK;
}

unsigned int __stdcall CStreamEvent::InputDataThreadFunc(LPVOID lpParam)
{
    CStreamEvent * pThis = (CStreamEvent *)lpParam;

    while (pThis->m_bRunning)
    {
        EnterCriticalSection(&pThis->m_InputLock);

        while (pThis->m_InputData.size() > 0)
        {
            tagVideoData videoData = pThis->m_InputData.front();
            BYTE * cbMediaData = videoData.pcbData;
            if ('S' == cbMediaData[0] && 'S' == cbMediaData[1] && 'A' == cbMediaData[2]&& 'V' == cbMediaData[3])
            {
                if (FALSE == PlayM4_InputData(pThis->m_lPort, cbMediaData + 4, videoData.dwDataSize))
                {
                    DWORD dwLastError = PlayM4_GetLastError(pThis->m_lPort);
                    OutputDebugString(TEXT("PlayM4_InputDataSSAV Error\r\n"));
                    break;
                }
            }
            else
            {
                if (FALSE == PlayM4_InputData(pThis->m_lPort, cbMediaData, videoData.dwDataSize))
                {
                    DWORD dwLastError = PlayM4_GetLastError(pThis->m_lPort);
                    OutputDebugString(TEXT("PlayM4_InputData Error\r\n"));
                    break;
                }
            }
            delete cbMediaData;
            pThis->m_InputData.pop_front();
        }
        LeaveCriticalSection(&pThis->m_InputLock);
        Sleep(10);
    }

    return 0;
}
