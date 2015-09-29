
// HYNVRExerciseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "HYNVRExercise.h"
#include "HYNVRExerciseDlg.h"
#include "afxdialogex.h"
#include "dtsdk\YUVConvert.h"

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


// CHYNVRExerciseDlg 对话框




CHYNVRExerciseDlg::CHYNVRExerciseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHYNVRExerciseDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    m_lRealHandle = -1;
    m_lRealStream = -1;
}

void CHYNVRExerciseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHYNVRExerciseDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON1, &CHYNVRExerciseDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CHYNVRExerciseDlg 消息处理程序

BOOL CHYNVRExerciseDlg::OnInitDialog()
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
    BYTE cbLimit = 0;
    m_lUserID = HYLoginIPC(NULL, "192.168.20.137", 7000, "admin", "12345", &cbLimit);
    if (-1 == m_lUserID)
    {
        CString str;
        str.Format(TEXT("登录失败，错误码：%d"), HYGetLastError());
        MessageBox(str);
    }

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CHYNVRExerciseDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CHYNVRExerciseDlg::OnPaint()
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
HCURSOR CHYNVRExerciseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CHYNVRExerciseDlg::OnBnClickedButton1()
{
    HYRegDecodeDataEx(CHYNVRExerciseDlg::DecodeDataEx);
    //int nLastError = HYGetLastError();
    int nMediaHandle = HYMediaRegister(CHYNVRExerciseDlg::MediaStream);
    //nLastError = HYGetLastError();

    m_lRealHandle = HYCreateReal(GetDlgItem(IDC_STATIC_REAL_PLAY)->GetSafeHwnd());
    if (-1 != m_lRealHandle)
    {
        HYSetStreamPlayMode(m_lRealHandle, 0);
    }
    else
    {
        MessageBox(TEXT("HYCreateReal 失败"));
    }

    //int nMediaHandle = HYMediaRegister(CHYNVRExerciseDlg::MediaStream);
    //int nLastError = HYGetLastError();
    //m_lRealHandle = HYCreateReal(GetDlgItem(IDC_STATIC_REAL_PLAY)->GetSafeHwnd());
    //if (-1 != m_lRealHandle)
    {
        //HYSetStreamPlayMode(m_lRealHandle, 0);
        m_lRealStream = HYRequestStream(m_lUserID, 3, 0, 39023);
        if (-1 != m_lRealStream)
        {
            int nLastError = HYGetLastError();

        }
        else
        {
            MessageBox(TEXT("HYRequestStream 失败"));
        }
    }
    /*else
    {
        MessageBox(TEXT("HYCreateReal 失败"));
    }*/
}

void CALLBACK CHYNVRExerciseDlg::MediaStream(LONG lStream, BYTE *pStream, int nLen, int nFrameType)
{
    CHYNVRExerciseDlg * pThis = (CHYNVRExerciseDlg *) theApp.m_pMainWnd;
    if (NULL != pThis)
    {
        //HYWriteReal(pThis->m_lRealHandle, pStream, nLen);

        switch(nFrameType)
        {
        case FRAME_HEADER:
        case FRAME_AUDIO:
        case FRAME_VIDEO_I:
        case FRAME_VIDEO_P:
        case FRAME_VIDEO_B:
            HYWriteReal(pThis->m_lRealHandle, pStream,nLen);
            break;
        }
    }
}

void CALLBACK CHYNVRExerciseDlg::DecodeDataEx(LONG  lDecoderHandle, char *pData, int nLen, HY_FRAME_INFO* pFrameInfo)
{
    if(pFrameInfo->nType == FRAME_TYPE_YUV420)
    {
        CHAR szFileName[MAX_PATH] = {0};
        _snprintf_s(szFileName, MAX_PATH, "%d.jpg", pFrameInfo->nStamp);
        ConvertSaveYUV420((unsigned char *)pData, pFrameInfo->nWidth, pFrameInfo->nHeight, szFileName);
    }

}
