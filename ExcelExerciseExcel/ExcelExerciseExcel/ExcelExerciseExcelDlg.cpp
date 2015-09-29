
// ExcelExerciseExcelDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ExcelExerciseExcel.h"
#include "ExcelExerciseExcelDlg.h"
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


// CExcelExerciseExcelDlg 对话框




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


// CExcelExerciseExcelDlg 消息处理程序

BOOL CExcelExerciseExcelDlg::OnInitDialog()
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
    if (FALSE == m_application.CreateDispatch(TEXT("Excel.Application"), NULL))
    {
        MessageBox(TEXT("创建Excel应用失败！"));

        return FALSE;
    }

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CExcelExerciseExcelDlg::OnPaint()
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
