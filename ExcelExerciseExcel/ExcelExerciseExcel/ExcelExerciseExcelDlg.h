
// ExcelExerciseExcelDlg.h : 头文件
//

#pragma once

#include "CRange.h"
#include "CWorkbook.h"
#include "CWorkbooks.h"
#include "CWorksheet.h"
#include "CWorksheets.h"
#include "CApplication.h"
#include "afxwin.h"


// CExcelExerciseExcelDlg 对话框
class CExcelExerciseExcelDlg : public CDialogEx
{
// 构造
public:
	CExcelExerciseExcelDlg(CWnd* pParent = NULL);	// 标准构造函数
    ~CExcelExerciseExcelDlg();

// 对话框数据
	enum { IDD = IDD_EXCELEXERCISEEXCEL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
    CStatic m_staticName;

    CWorkbook               m_workbook;
    CWorkbooks              m_workbooks;
    CWorksheet              m_worksheet;
    CWorksheets             m_worksheets;
    CApplication            m_application;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButton1();
    afx_msg void OnBnClickedButton2();
};
