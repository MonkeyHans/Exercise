
// TJJDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TJJDemo.h"
#include "TJJDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTJJDemoDlg �Ի���




CTJJDemoDlg::CTJJDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTJJDemoDlg::IDD, pParent)//, m_MessageEvent(this->m_comClient)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    m_hFile = INVALID_HANDLE_VALUE;
    m_hInputData = NULL;
    m_pStreamPlayer =NULL;
}

void CTJJDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

#define WM_USER_INPUT_DATA (WM_USER + 101)

BEGIN_MESSAGE_MAP(CTJJDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON1, &CTJJDemoDlg::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_BUTTON2, &CTJJDemoDlg::OnBnClickedButton2)
    ON_BN_CLICKED(IDC_BUTTON3, &CTJJDemoDlg::OnBnClickedButton3)
    ON_BN_CLICKED(IDC_BUTTON4, &CTJJDemoDlg::OnBnClickedButton4)
    ON_MESSAGE(WM_USER_INPUT_DATA, OnInputData)
END_MESSAGE_MAP()


// CTJJDemoDlg ��Ϣ�������

BOOL CTJJDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    HRESULT hr = m_comClient.QueryInterface(__uuidof(SSNetSdk_COM::SimpleCOMClient), &m_comClient);
     hr = m_comClient.CreateInstance(__uuidof(SSNetSdk_COM::SimpleCOMClient));

    if (FAILED(hr))
    {
        MessageBox(TEXT("����COMClient ʧ��"));
    }

    if (FAILED(m_MessageEvent.DispEventAdvise(m_comClient)))
    {
        MessageBox(TEXT("MessageEvent Advise Failed"));
    }

    if (m_comClient->Login("192.168.20.171", 7011, "admin", "12345"))
    {
        
        SAFEARRAY * deviceArray = m_comClient->GetVideoDevices("");
        for (long i = 0; i < deviceArray->rgsabound->cElements; i++)
        {
            SafeArrayGetElement(deviceArray, &i, m_videoDevice + i);

            CString str = m_videoDevice[i]->host();
            CString name = m_videoDevice[i]->Name();
            CString userid = m_videoDevice[i]->uid();
            CString password = m_videoDevice[i]->pwd();
            str.AppendFormat(TEXT("\t%d\t%s\t%s\t%s\\r\n"), m_videoDevice[i]->port(), name, userid, password);
            OutputDebugString(str);
        }
        

        for (int i = 0; i < deviceArray->rgsabound->cElements; i++)//
        {
            SAFEARRAY * channelArray = m_videoDevice[i]->Channels();
            for (long index = 0; index < channelArray->rgsabound->cElements; index++)
            {
                SafeArrayGetElement(channelArray, &index, &m_videoChannel[i][index]);
                _bstr_t chanID = (m_videoChannel[i][index])->ChannelId();

                CString strChanName = m_videoChannel[i][index]->Name();
                CString strChanID = m_videoChannel[i][index]->ChannelId();
                long lChanNO = m_videoChannel[i][index]->ChannelNo();
                CString str;
                str.Format("ͨ�����ƣ�%s, ͨ��ID %s, ͨ��NO %d\r\n", strChanName, strChanID, lChanNO);
                OutputDebugString(str);
            }


            //SafeArrayUnaccessData(channelArray);
            //SafeArrayDestroy(channelArray);
        }
        //SafeArrayUnaccessData(deviceArray);
        //SafeArrayDestroy(deviceArray);
    }

    _beginthreadex(NULL, 0, TestExceptionThradFunc, this, 0 , NULL);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTJJDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTJJDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTJJDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTJJDemoDlg::OnBnClickedButton1()
{
    for (int i = 0; i < 8; i++)
    {
        if (NULL == m_realPlay[i])
        {
            m_realPlay[i] = m_comClient->CreateRealPlayer((long) GetDlgItem(IDC_STATIC_REAL_PLAY_1 + i)->GetSafeHwnd());
        }
    }

    int data = 0;
    for (int i = 0; i < 8; i++)
    {
        _bstr_t chanID = m_videoChannel[0][i]->ChannelId();
        m_realPlay[i]->Play(chanID, (SSNetSdk_COM::StreamTypez) 0, 0, NULL, &data);
    }
}


void CTJJDemoDlg::OnBnClickedButton2()
{
    for (int i = 0; i < 8; i++)
    {
        m_pStreamEvent[i] = new CStreamEvent(m_comClient, GetDlgItem(IDC_STATIC_REAL_PLAY_1 + i)->GetSafeHwnd());
    }

    for (int i = 0; i < 8; i++)
    {
        m_streamer[i] = m_comClient->CreateComStreamer();
    }

    for (int i = 0; i < 8; i++)
    {
        m_pStreamEvent[i]->DispEventAdvise(m_streamer[i]);
        _bstr_t chanID = m_videoChannel[0][i]->ChannelId();
        VARIANT_BOOL bRet = m_streamer[i]->Open(chanID);
        if (bRet == -1)
        {
            OutputDebugString("succeeded \r\n");
        }
        else if (bRet == 0)
        {
            OutputDebugString("failed \r\n");
        }
    }
}


void CTJJDemoDlg::OnBnClickedButton3()
{
   //m_hFile = CreateFile(TEXT("test.tjj"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
   //m_hInputData = (HANDLE) _beginthreadex(NULL, 0, &CTJJDemoDlg::InputDataThreadFunc, this, 0, NULL);
}

//unsigned int __stdcall CTJJDemoDlg::InputDataThreadFunc(LPVOID pParam)
//{
//    CTJJDemoDlg * pThis = (CTJJDemoDlg *) pParam;
//    if (pThis && NULL != pThis->m_comClient)
//    {
//        HANDLE hTempFile = CreateFile(TEXT("test.tjj"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//        if (INVALID_HANDLE_VALUE != hTempFile)
//        {
//            DWORD dwDataSize = 0;
//            DWORD dwNumberOfBytesRead = 0;
//            ReadFile(hTempFile, &dwDataSize, sizeof(DWORD), &dwNumberOfBytesRead, NULL);
//
//            HWND hWnd =  pThis->GetDlgItem(IDC_STATIC_REAL_PLAY_5 + 0)->GetSafeHwnd();
//            CStreamEvent * pStreamEvent = new CStreamEvent(pThis->m_comClient, hWnd);
//            
//            if (NULL != pStreamEvent)
//            {
//                BYTE * cbInputHead = new BYTE[dwDataSize];
//                if (ReadFile(hTempFile, cbInputHead, dwDataSize, &dwNumberOfBytesRead, NULL))
//                {
//                    //����ͷ֡����
//                    SAFEARRAYBOUND bound[1] = {0};
//                    bound[0].lLbound = 0;
//                    bound[0].cElements = dwDataSize;
//                    SAFEARRAY * psaHead = SafeArrayCreate(VT_UI1, 1, bound);
//
//                    if (psaHead)
//                    {
//                        BYTE * pcbHead;
//                        SafeArrayAccessData(psaHead, (VOID **) &pcbHead);
//                        for (ULONG i = 0; i < psaHead->rgsabound->cElements; i++)
//                        {
//                            pcbHead[i] = cbInputHead[i];
//                        }
//                        SafeArrayUnaccessData(psaHead);
//
//                        bool bRet = false;
//                        if (VARIANT_TRUE == pStreamEvent->OnGotHeaderEx(NULL, psaHead))
//                        {
//                            bRet = true;
//                        }
//
//                        //SafeArrayDestroy(psaHead);
//                        //delete cbInputHead;
//                        //cbInputHead = NULL;
//
//                        while (bRet)
//                        {
//                            if (ReadFile(hTempFile, &dwDataSize, sizeof(DWORD), &dwNumberOfBytesRead, NULL))
//                            {
//                                BYTE * cbInputData = new BYTE[dwDataSize];
//                                if (ReadFile(hTempFile, cbInputData, dwDataSize, &dwNumberOfBytesRead, NULL))
//                                {
//                                    //����ͷ֡����
//                                    SAFEARRAYBOUND boundData[1] = {0};
//                                    boundData[0].lLbound = 0;
//                                    boundData[0].cElements = dwDataSize;
//                                    SAFEARRAY * psaData = SafeArrayCreate(VT_UI1, 1, boundData);
//
//                                    if (psaData)
//                                    {
//                                        BYTE * pcbInputData;
//                                        SafeArrayAccessData(psaData, (VOID **) &psaData);
//                                        for (ULONG i = 0; i < psaData->rgsabound->cElements; i++)
//                                        {
//                                            pcbInputData[i] = cbInputData[i];
//                                        }
//                                        SafeArrayUnaccessData(psaData);
//
//                                        bool bRet = false;
//                                        if (VARIANT_TRUE == pStreamEvent->OnGotMediaEx(NULL, psaHead))
//                                        {
//                                            bRet = true;
//                                        }
//
//                                        //SafeArrayDestroy(psaData);
//                                        delete cbInputData;
//                                        cbInputData = NULL;
//                                    }
//                                }
//
//                            }
//                            else
//                            {
//                                break;
//                            }
//                        }
//                    }
//                }
//
//                //pStreamEvent->Close();
//            }
//        }
//
//    }
//
//    return 0;
//}

//unsigned int __stdcall CTJJDemoDlg::InputDataThreadFunc(LPVOID pParam)
//{
//    CTJJDemoDlg * pThis = (CTJJDemoDlg *) pParam;
//    if (pThis && NULL != pThis->m_comClient)
//    {
//        HANDLE hTempFile = CreateFile(TEXT("test.tjj"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//        if (INVALID_HANDLE_VALUE != hTempFile)
//        {
//            DWORD dwDataSize = 0;
//            DWORD dwNumberOfBytesRead = 0;
//            ReadFile(hTempFile, &dwDataSize, sizeof(DWORD), &dwNumberOfBytesRead, NULL);
//
//            BYTE * cbInputHead = new BYTE[dwDataSize];
//            if (ReadFile(hTempFile, cbInputHead, dwDataSize, &dwNumberOfBytesRead, NULL))
//            {
//                pThis->PostMessage(WM_USER_INPUT_DATA, (WPARAM) cbInputHead, MAKELPARAM(1, dwDataSize));
//
//                Sleep(100);
//                while (true)
//                {
//                    if (ReadFile(hTempFile, &dwDataSize, sizeof(DWORD), &dwNumberOfBytesRead, NULL))
//                    {
//                        BYTE * cbInputData = new BYTE[dwDataSize];
//                        if (ReadFile(hTempFile, cbInputData, dwDataSize, &dwNumberOfBytesRead, NULL))
//                        {
//                            Sleep(50);
//                            pThis->PostMessage(WM_USER_INPUT_DATA, (WPARAM) cbInputHead, MAKELPARAM(0, dwDataSize));
//                        }
//
//                    }
//                    else
//                    {
//                        break;
//                    }
//                }
//            }
//        }
//
//    }
//
//    return 0;
//}

//unsigned int __stdcall CTJJDemoDlg::InputDataThreadFunc(LPVOID pParam)
//{
//    CTJJDemoDlg * pThis = (CTJJDemoDlg *) pParam;
//    if (pThis && NULL != pThis->m_comClient)
//    {
//        HANDLE hTempFile = CreateFile(TEXT("test.tjj"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//        if (INVALID_HANDLE_VALUE != hTempFile)
//        {
//            DWORD dwDataSize = 0;
//            DWORD dwNumberOfBytesRead = 0;
//            ReadFile(hTempFile, &dwDataSize, sizeof(DWORD), &dwNumberOfBytesRead, NULL);
//
//            HWND hWnd =  pThis->GetDlgItem(IDC_STATIC_REAL_PLAY_5 + 0)->GetSafeHwnd();
//
//            SSNetSdk_COM::IComStreamPlayerPtr pStreamPlayer = pThis->m_comClient->CreateComStreamPlayer();
//            if (NULL != pStreamPlayer)
//            {
//                BYTE * cbInputHead = new BYTE[dwDataSize];
//                if (ReadFile(hTempFile, cbInputHead, dwDataSize, &dwNumberOfBytesRead, NULL))
//                {
//                    //����ͷ֡����
//                    SAFEARRAYBOUND bound[1] = {0};
//                    bound[0].lLbound = 0;
//                    bound[0].cElements = dwDataSize;
//                    SAFEARRAY * psaHead = SafeArrayCreate(VT_UI1, 1, bound);
//
//                    if (psaHead)
//                    {
//                        BYTE * pcbHead;
//                        SafeArrayAccessData(psaHead, (VOID **) &pcbHead);
//                        for (ULONG i = 0; i < psaHead->rgsabound->cElements; i++)
//                        {
//                            pcbHead[i] = cbInputHead[i];
//                        }
//                        SafeArrayUnaccessData(psaHead);
//
//                        bool bRet = false;
//                        if (VARIANT_TRUE == pStreamPlayer->Open(psaHead, (long) hWnd))
//                        {
//                            bRet = true;
//                        }
//
//                        //SafeArrayDestroy(psaHead);
//                        //delete cbInputHead;
//                        //cbInputHead = NULL;
//
//                        while (bRet)
//                        {
//                            if (ReadFile(hTempFile, &dwDataSize, sizeof(DWORD), &dwNumberOfBytesRead, NULL))
//                            {
//                                BYTE * cbInputData = new BYTE[dwDataSize];
//                                if (ReadFile(hTempFile, cbInputData, dwDataSize, &dwNumberOfBytesRead, NULL))
//                                {
//                                    //����ͷ֡����
//                                    SAFEARRAYBOUND boundData[1] = {0};
//                                    boundData[0].lLbound = 0;
//                                    boundData[0].cElements = dwDataSize;
//                                    SAFEARRAY * psaData = SafeArrayCreate(VT_UI1, 1, boundData);
//
//                                    if (psaData)
//                                    {
//                                        BYTE * pcbInputData;
//                                        SafeArrayAccessData(psaData, (VOID **) &psaData);
//                                        for (ULONG i = 0; i < psaData->rgsabound->cElements; i++)
//                                        {
//                                            pcbInputData[i] = cbInputData[i];
//                                        }
//                                        SafeArrayUnaccessData(psaData);
//
//                                        bool bRet = false;
//                                        if (VARIANT_TRUE == pStreamPlayer->InputStream(psaData))
//                                        {
//                                            bRet = true;
//                                        }
//
//                                        //SafeArrayDestroy(psaData);
//                                        delete cbInputData;
//                                        cbInputData = NULL;
//                                    }
//                                }
//
//                            }
//                            else
//                            {
//                                break;
//                            }
//                        }
//                    }
//                }
//
//                pStreamPlayer->Close();
//            }
//        }
//
//    }
//
//    return 0;
//}

void CTJJDemoDlg::OnBnClickedButton4()
{
    for (int i = 0; i < 8; i++)
    {
        m_streamer[i]->Close();
    }

    //for (int i = 0; i < 1; i++)
    //{
    //    m_pStreamEvent[i]->DispEventAdvise(m_streamer[i]);
    //    _bstr_t chanID = m_videoChannel[1][i]->ChannelId();
    //    VARIANT_BOOL bRet = m_streamer[i]->Open(chanID);
    //    if (bRet == -1)
    //    {
    //        OutputDebugString("succeeded \r\n");
    //    }
    //    else if (bRet == 0)
    //    {
    //        OutputDebugString("failed \r\n");
    //    }
    //}
}

LRESULT CTJJDemoDlg::OnInputData(WPARAM wParam, LPARAM lParam)
{

    if (NULL == m_pStreamPlayer)
    {
        m_pStreamPlayer = m_comClient->CreateComStreamPlayer();
    }

    BYTE * pcbInputData = (BYTE *)wParam;
    WORD wSize = HIWORD(lParam);
    WORD wType = LOWORD(lParam); 

    //����ͷ֡����
    SAFEARRAYBOUND bound[1] = {0};
    bound[0].lLbound = 0;
    bound[0].cElements = wSize;
    SAFEARRAY * psaHead = SafeArrayCreate(VT_UI1, 1, bound);

    if (psaHead)
    {
        BYTE * pcbHead;
        SafeArrayAccessData(psaHead, (VOID **) &pcbHead);
        for (ULONG i = 0; i < psaHead->rgsabound->cElements; i++)
        {
            pcbHead[i] = pcbInputData[i];
        }
        SafeArrayUnaccessData(psaHead);

        if (wType)
        {
            HWND hWnd =  GetDlgItem(IDC_STATIC_REAL_PLAY_5 + 0)->GetSafeHwnd();
            if (VARIANT_TRUE == m_pStreamPlayer->Open(psaHead, (long) hWnd))
            {
            }
        }
        else
        {
            if (VARIANT_TRUE == m_pStreamPlayer->InputStream(psaHead))
            {
            }
        }

    }

    return 0;
}

unsigned int __stdcall CTJJDemoDlg::TestExceptionThradFunc(LPVOID pParam)
{
    CTJJDemoDlg * pThis = (CTJJDemoDlg *) pParam;

    if (pThis)
    {
        while (true)
        {
            VARIANT_BOOL bRet = pThis->m_comClient->Login("192.168.20.171", 7011, "admin", "12345");
            OutputDebugString("Thread hh");
            Sleep(5000);
        }
    }

    return 0;
}

