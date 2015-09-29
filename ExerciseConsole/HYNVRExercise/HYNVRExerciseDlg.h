
// HYNVRExerciseDlg.h : 头文件
//

#pragma once


// CHYNVRExerciseDlg 对话框
class CHYNVRExerciseDlg : public CDialogEx
{
// 构造
public:
	CHYNVRExerciseDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_HYNVREXERCISE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
    long m_lUserID;
    long m_lRealHandle;
    long m_lRealStream;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButton1();
    static void CALLBACK MediaStream(LONG lStream, BYTE *pStream, int nLen, int nFrameType);
    static void CALLBACK DecodeDataEx(LONG  lDecoderHandle, char *pData, int nLen, HY_FRAME_INFO* pFrameInfo);
};
