
// HYNVRExerciseDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HYNVRExercise.h"
#include "HYNVRExerciseDlg.h"
#include "afxdialogex.h"
#include "dtsdk\YUVConvert.h"

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


// CHYNVRExerciseDlg �Ի���




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


// CHYNVRExerciseDlg ��Ϣ�������

BOOL CHYNVRExerciseDlg::OnInitDialog()
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
    BYTE cbLimit = 0;
    m_lUserID = HYLoginIPC(NULL, "192.168.20.137", 7000, "admin", "12345", &cbLimit);
    if (-1 == m_lUserID)
    {
        CString str;
        str.Format(TEXT("��¼ʧ�ܣ������룺%d"), HYGetLastError());
        MessageBox(str);
    }

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CHYNVRExerciseDlg::OnPaint()
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
        MessageBox(TEXT("HYCreateReal ʧ��"));
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
            MessageBox(TEXT("HYRequestStream ʧ��"));
        }
    }
    /*else
    {
        MessageBox(TEXT("HYCreateReal ʧ��"));
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
