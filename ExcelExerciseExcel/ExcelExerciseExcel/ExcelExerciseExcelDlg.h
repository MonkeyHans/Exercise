
// ExcelExerciseExcelDlg.h : ͷ�ļ�
//

#pragma once

#include "CRange.h"
#include "CWorkbook.h"
#include "CWorkbooks.h"
#include "CWorksheet.h"
#include "CWorksheets.h"
#include "CApplication.h"
#include "afxwin.h"


// CExcelExerciseExcelDlg �Ի���
class CExcelExerciseExcelDlg : public CDialogEx
{
// ����
public:
	CExcelExerciseExcelDlg(CWnd* pParent = NULL);	// ��׼���캯��
    ~CExcelExerciseExcelDlg();

// �Ի�������
	enum { IDD = IDD_EXCELEXERCISEEXCEL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
    CStatic m_staticName;

    CWorkbook               m_workbook;
    CWorkbooks              m_workbooks;
    CWorksheet              m_worksheet;
    CWorksheets             m_worksheets;
    CApplication            m_application;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButton1();
    afx_msg void OnBnClickedButton2();
};
