
// ExcelExerciseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ExcelExercise.h"
#include "ExcelExerciseDlg.h"
#include "afxdialogex.h"
#include "ExcelDocument.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define PIC_MARGIN          10


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


// CExcelExerciseDlg 对话框




CExcelExerciseDlg::CExcelExerciseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExcelExerciseDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExcelExerciseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExcelExerciseDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON1, &CExcelExerciseDlg::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_BUTTON2, &CExcelExerciseDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CExcelExerciseDlg 消息处理程序

BOOL CExcelExerciseDlg::OnInitDialog()
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


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CExcelExerciseDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CExcelExerciseDlg::OnPaint()
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
HCURSOR CExcelExerciseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExcelExerciseDlg::OnBnClickedButton1()
{
    // TODO: 在此添加控件通知处理程序代码
    CApplication application;
    CWorkbooks books;
    CWorkbook book;
    CWorksheets sheets;
    CWorksheet sheet;
    CRange range;

    if (FALSE == application.CreateDispatch(TEXT("Excel.Application")))
    {
        MessageBox(TEXT("创建Excel应用失败"));
        return ;
    }

    books = application.get_Workbooks();

    LPDISPATCH lpBooks = books.Add(variant_t(TEXT("C:/ReadBook1.xls")));
    if (lpBooks)
    {
        book.AttachDispatch(lpBooks);
        sheets.AttachDispatch(book.get_Sheets(), TRUE);
        LPDISPATCH lpSheet = sheets.get_Item(variant_t(1));
        if (lpSheet)
        {
            sheet.AttachDispatch(lpSheet, TRUE);
            //LPDISPATCH lpCells = sheet.get_Cells();
            //if (lpCells)
            //{
            //    range.AttachDispatch(lpCells, TRUE);
            //    variant_t tempItem = range.get_Item(variant_t(1), variant_t(1));
            //    if (tempItem.vt == VT_BSTR)
            //    {
            //        SetDlgItemTextW(m_hWnd, IDC_STATIC_NAME, tempItem.bstrVal);
            //    }
            //    else if (tempItem.vt == VT_DISPATCH)
            //    {
            //        //tempItem.pdispVal->
            //    }
            //}
            range = sheet.get_Range(variant_t(TEXT("A1")), variant_t(TEXT("A1")));
            if (range)
            {
                variant_t tempData = range.get_Value2();
                if (tempData.vt == VT_BSTR)
                {
                    CStringW strName = tempData.bstrVal;
                    SetDlgItemTextW(m_hWnd, IDC_STATIC_NAME, strName);
                }
            }
        }
    }

    book.Close(variant_t((short) FALSE), variant_t(TEXT("C:/ReadBook1.xls")), variant_t(VT_ERROR));

    range.ReleaseDispatch();
    sheet.ReleaseDispatch();
    sheets.ReleaseDispatch();
    book.ReleaseDispatch();
    books.ReleaseDispatch();

    application.ReleaseDispatch();
    application.Quit();
}


void CExcelExerciseDlg::OnBnClickedButton2()
{
    // TODO: 在此添加控件通知处理程序代码
    CExcelDocument document;
    if (document.Open(TEXT("D:/Book2.xls")))
    {
        document.m_range.put_Item(variant_t(2), variant_t(2), variant_t(TEXT("或拉起")));
        document.m_range.put_Item(variant_t(3), variant_t(2), COleVariant(TEXT("\'124345345345"), VT_BSTR));
        document.m_range.put_Item(variant_t(4), variant_t(2), COleVariant(TEXT("\'234222222222222222222"), VT_BSTR));
        document.m_range.put_Item(variant_t(5), variant_t(2), variant_t(TEXT("热水")));
        document.m_range.put_Item(variant_t(6), variant_t(2), variant_t(TEXT("地图")));
        document.m_range.put_Item(variant_t(7), variant_t(2), variant_t(TEXT("热水1")));
        document.m_range.put_Item(variant_t(8), variant_t(2), variant_t(TEXT("地图2")));
        document.m_range.put_Item(variant_t(9), variant_t(2), variant_t(TEXT("热水3")));
        document.m_range.put_Item(variant_t(5), variant_t(4), variant_t(TEXT("热水4")));
        document.m_range.put_Item(variant_t(6), variant_t(4), variant_t(TEXT("地图4")));
        document.m_range.put_Item(variant_t(7), variant_t(4), variant_t(TEXT("热水14")));
        document.m_range.put_Item(variant_t(8), variant_t(4), variant_t(TEXT("地图24")));
        document.m_range.put_Item(variant_t(9), variant_t(4), variant_t(TEXT("热水34")));

        CShapes shapes = document.m_worksheet.get_Shapes();

        CRange rangeA11 = document.m_worksheet.get_Range(variant_t(TEXT("A11")), CExcelDocument::g_missing);
        CRange rangeB22 = document.m_worksheet.get_Range(variant_t(TEXT("B22")), CExcelDocument::g_missing);
        double leftA11 = rangeA11.get_Left().dblVal + PIC_MARGIN;
        double topA11 = rangeA11.get_Top().dblVal + PIC_MARGIN;
        double imageWidth = rangeA11.get_Width().dblVal + rangeB22.get_Width().dblVal - PIC_MARGIN * 2;
        double imageHeight = (rangeB22.get_Top().dblVal + rangeB22.get_Height().dblVal) - rangeA11.get_Top().dblVal - PIC_MARGIN * 2;

        shapes.AddPicture(TEXT("C:/Koala.jpg"), 0, 1, 
            leftA11, topA11, imageWidth, imageHeight);

        CRange rangeC11 = document.m_worksheet.get_Range(variant_t(TEXT("C11")), CExcelDocument::g_missing);
        CRange rangeD22 = document.m_worksheet.get_Range(variant_t(TEXT("D22")), CExcelDocument::g_missing);
        double leftC11 = rangeC11.get_Left().dblVal + PIC_MARGIN;
        double topC11 = rangeC11.get_Top().dblVal + PIC_MARGIN;
        double imageWidth2 = rangeC11.get_Width().dblVal + rangeD22.get_Width().dblVal - PIC_MARGIN * 2;
        double imageHeight2 = (rangeD22.get_Top().dblVal + rangeD22.get_Height().dblVal) - rangeC11.get_Top().dblVal - PIC_MARGIN * 2;

        shapes.AddPicture(TEXT("C:/Koala.jpg"), 0, 1, 
            leftC11, topC11, imageWidth2, imageHeight2);

        //document.m_worksheet.PrintOut(variant_t(1), variant_t(1), variant_t(1), variant_t((short) FALSE), 
        //    variant_t(TEXT("Microsoft XPS Document Writer")), variant_t((short) TRUE), variant_t((short) FALSE), variant_t(TEXT("D:/text.xps")));
        try
        {
            document.m_worksheet.PrintOut(variant_t(1), variant_t(1), variant_t(1), variant_t((short) FALSE), 
                CExcelDocument::g_missing, variant_t((short) FALSE), variant_t((short) FALSE), CExcelDocument::g_missing);
        }
        catch (...)
        {
            OutputDebugString(TEXT("打印异常\r\n"));
        }
        

        document.Close(FALSE);
    }
}
