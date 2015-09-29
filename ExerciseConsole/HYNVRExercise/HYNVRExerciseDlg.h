
// HYNVRExerciseDlg.h : ͷ�ļ�
//

#pragma once


// CHYNVRExerciseDlg �Ի���
class CHYNVRExerciseDlg : public CDialogEx
{
// ����
public:
	CHYNVRExerciseDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_HYNVREXERCISE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
    long m_lUserID;
    long m_lRealHandle;
    long m_lRealStream;

	// ���ɵ���Ϣӳ�亯��
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
