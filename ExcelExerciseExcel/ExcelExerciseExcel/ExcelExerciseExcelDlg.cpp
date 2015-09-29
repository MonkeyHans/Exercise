
// ExcelExerciseExcelDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ExcelExerciseExcel.h"
#include "ExcelExerciseExcelDlg.h"
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


// CExcelExerciseExcelDlg �Ի���




CExcelExerciseExcelDlg::CExcelExerciseExcelDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExcelExerciseExcelDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CExcelExerciseExcelDlg::~CExcelExerciseExcelDlg()
{
    m_application.Quit();
    m_application.ReleaseDispatch();
    m_application = NULL;
}

void CExcelExerciseExcelDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_STATIC_NAME, m_staticName);
}

BEGIN_MESSAGE_MAP(CExcelExerciseExcelDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON1, &CExcelExerciseExcelDlg::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_BUTTON2, &CExcelExerciseExcelDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CExcelExerciseExcelDlg ��Ϣ�������

BOOL CExcelExerciseExcelDlg::OnInitDialog()
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
    if (FALSE == m_application.CreateDispatch(TEXT("Excel.Application"), NULL))
    {
        MessageBox(TEXT("����ExcelӦ��ʧ�ܣ�"));

        return FALSE;
    }

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CExcelExerciseExcelDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CExcelExerciseExcelDlg::OnPaint()
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
HCURSOR CExcelExerciseExcelDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExcelExerciseExcelDlg::OnBnClickedButton1()
{
    CWorkbooks books;
    CWorkbook book;
    CWorksheets sheets;
    CWorksheet sheet;
    CRange range;

    books.AttachDispatch(m_application.get_Workbooks(), TRUE);

    LPDISPATCH lpDisBook = books.Open(TEXT("D:/ReadBook1.xls"), COleVariant((LONG) DISP_E_PARAMNOTFOUND, VT_ERROR), COleVariant((LONG) DISP_E_PARAMNOTFOUND, VT_ERROR), COleVariant((LONG) DISP_E_PARAMNOTFOUND, VT_ERROR), COleVariant((LONG) DISP_E_PARAMNOTFOUND, VT_ERROR), COleVariant((LONG) DISP_E_PARAMNOTFOUND, VT_ERROR), COleVariant((LONG) DISP_E_PARAMNOTFOUND, VT_ERROR), COleVariant((LONG) DISP_E_PARAMNOTFOUND, VT_ERROR), COleVariant((LONG) DISP_E_PARAMNOTFOUND, VT_ERROR), COleVariant((LONG) DISP_E_PARAMNOTFOUND, VT_ERROR), COleVariant((LONG) DISP_E_PARAMNOTFOUND, VT_ERROR), COleVariant((LONG) DISP_E_PARAMNOTFOUND, VT_ERROR), COleVariant((LONG) DISP_E_PARAMNOTFOUND, VT_ERROR), COleVariant((LONG) DISP_E_PARAMNOTFOUND, VT_ERROR), COleVariant((LONG) DISP_E_PARAMNOTFOUND, VT_ERROR));
    //LPDISPATCH lpDisBook = books.Add(COleVariant(TEXT("D:/ReadBook1.xls")));
    if (lpDisBook)
    {
        book.AttachDispatch(lpDisBook, TRUE);
        sheets.AttachDispatch(book.get_Worksheets(), TRUE);

        LPDISPATCH lpDisSheet = sheets.get_Item(COleVariant((BYTE)1));
        if (lpDisSheet)
        {
            sheet.AttachDispatch(lpDisSheet, TRUE);

            LPDISPATCH lpDisRange = sheet.get_Cells();
            if (lpDisRange)
            {
                range.AttachDispatch(lpDisRange, TRUE);
                variant_t readData = range.get_Item(COleVariant((BYTE) 1), COleVariant((BYTE) 1));
                _bstr_t bstrData(readData.bstrVal);
                //bstrData.m_str.
                ::SetDlgItemTextA(m_hWnd, IDC_STATIC_NAME, bstrData);
                //m_staticName.SetWindowTextW(readData.bstrVal);
            }
        }
    }

    book.Close(COleVariant((BYTE)FALSE), COleVariant(TEXT("D:/ReadBook1.xls")), COleVariant((LONG) DISP_E_PARAMNOTFOUND, VT_ERROR));

    range.ReleaseDispatch();
    sheet.ReleaseDispatch();
    sheets.ReleaseDispatch();
    book.ReleaseDispatch();
    books.ReleaseDispatch();

}


void CExcelExerciseExcelDlg::OnBnClickedButton2()
{
    CWorkbooks books;
    CWorkbook book;
    CWorksheets sheets;
    CWorksheet sheet;
    CRange range;

    books.AttachDispatch(m_application.get_Workbooks(), TRUE);

    //books.
    //LPDISPATCH lpDisBook = books.OpenDatabase(TEXT("D:/ReadBook1.xls"), COleVariant((LONG) DISP_E_PARAMNOTFOUND, VT_ERROR), COleVariant((LONG) DISP_E_PARAMNOTFOUND, VT_ERROR), COleVariant((LONG) DISP_E_PARAMNOTFOUND, VT_ERROR), COleVariant((LONG) DISP_E_PARAMNOTFOUND, VT_ERROR));
    LPDISPATCH lpDisBook = books.Add(COleVariant(TEXT("D:/ReadBook1.xls")));
    if (lpDisBook)
    {
        book.AttachDispatch(lpDisBook, TRUE);
        sheets.AttachDispatch(book.get_Worksheets(), TRUE);

        LPDISPATCH lpDisSheet = sheets.get_Item(COleVariant((BYTE)0));
        if (lpDisSheet)
        {
            sheet.AttachDispatch(lpDisSheet, TRUE);

            LPDISPATCH lpDisRange = sheet.get_Cells();
            if (lpDisRange)
            {
                range.AttachDispatch(lpDisRange, TRUE);
                //variant_t readData = range.get_Item(COleVariant((BYTE) 1), COleVariant((BYTE) 1));
                //_bstr_t bstrData(readData.bstrVal);
                //bstrData.m_str.
                //::SetDlgItemTextA(m_hWnd, IDC_STATIC_NAME, bstrData);
                //m_staticName.SetWindowTextW(readData.bstrVal);
                range.put_Item(COleVariant((BYTE) 1), COleVariant((BYTE) 1), COleVariant(TEXT("This is test text.")));
            }
        }
    }

    //book.Close(COleVariant((BYTE)TRUE), COleVariant(TEXT("D:/ReadBook2.xls")), COleVariant((LONG) DISP_E_PARAMNOTFOUND, VT_ERROR));
    book.Save();
    book.Close(COleVariant((BYTE)TRUE), COleVariant(TEXT("D:/ReadBook1.xls")), COleVariant((LONG) DISP_E_PARAMNOTFOUND, VT_ERROR));

    range.ReleaseDispatch();
    sheet.ReleaseDispatch();
    sheets.ReleaseDispatch();
    book.ReleaseDispatch();
    books.ReleaseDispatch();
}
