
// TJJDemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TJJDemo.h"
#include "TJJDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CTJJDemoDlg 对话框




CTJJDemoDlg::CTJJDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTJJDemoDlg::IDD, pParent)//, m_MessageEvent(this->m_comClient)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTJJDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTJJDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON1, &CTJJDemoDlg::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_BUTTON2, &CTJJDemoDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CTJJDemoDlg 消息处理程序

BOOL CTJJDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
    HRESULT hr = m_comClient.QueryInterface(__uuidof(SSNetSdk_COM::SimpleCOMClient), &m_comClient);
     hr = m_comClient.CreateInstance(__uuidof(SSNetSdk_COM::SimpleCOMClient));

    if (FAILED(hr))
    {
        MessageBox(TEXT("创建COMClient 失败"));
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
                str.Format("通道名称：%s, 通道ID %s, 通道NO %d\r\n", strChanName, strChanID, lChanNO);
                OutputDebugString(str);
            }


            //SafeArrayUnaccessData(channelArray);
            //SafeArrayDestroy(channelArray);
        }
        //SafeArrayUnaccessData(deviceArray);
        //SafeArrayDestroy(deviceArray);
    }

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTJJDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTJJDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTJJDemoDlg::OnBnClickedButton1()
{
    for (int i = 0; i < 4; i++)
    {
        if (NULL == m_realPlay[i])
        {
            m_realPlay[i] = m_comClient->CreateRealPlayer((long) GetDlgItem(IDC_STATIC_REAL_PLAY_1 + i)->GetSafeHwnd());
        }
    }

    int data = 0;
    for (int i = 0; i < 2; i++)
    {
        _bstr_t chanID = m_videoChannel[0][i]->ChannelId();
        m_realPlay[i]->Play(chanID, (SSNetSdk_COM::StreamTypez) 0, 0, NULL, &data);
    }
}


void CTJJDemoDlg::OnBnClickedButton2()
{
    for (int i = 0; i < 1; i++)
    {
        m_pStreamEvent[i] = new CStreamEvent(m_comClient, GetDlgItem(IDC_STATIC_REAL_PLAY_5 + i)->GetSafeHwnd());
    }

    for (int i = 0; i < 1; i++)
    {
        m_streamer[i] = m_comClient->CreateComStreamer();
    }

    for (int i = 0; i < 1; i++)
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
