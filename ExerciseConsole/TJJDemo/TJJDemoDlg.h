
// TJJDemoDlg.h : ͷ�ļ�
//

#pragma once

#include "stdafx.h"
#include "StreamEvent.h"
#include "MssageEvent.h"




// CTJJDemoDlg �Ի���
class CTJJDemoDlg : public CDialogEx
{
// ����
public:
	CTJJDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TJJDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
    CMessageEvent m_MessageEvent;
    SSNetSdk_COM::ICOMClientPtr m_comClient;
    SSNetSdk_COM::IRealPlayerPtr m_realPlay[8];
    SSNetSdk_COM::IVideoDevicePtr m_videoDevice[10];
    SSNetSdk_COM::IVideoChannelPtr m_videoChannel[10][10];
    SSNetSdk_COM::IComStreamerPtr m_streamer[8];
    CStreamEvent * m_pStreamEvent[8];
    HANDLE m_hFile;
    HANDLE m_hInputData;
    SSNetSdk_COM::IComStreamPlayerPtr m_pStreamPlayer;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButton1();
    afx_msg void OnBnClickedButton2();
    afx_msg void OnBnClickedButton3();
    LRESULT OnInputData(WPARAM wParam, LPARAM lParam);

    static unsigned int __stdcall InputDataThreadFunc(LPVOID pParam);
    afx_msg void OnBnClickedButton4();

    static unsigned int __stdcall TestExceptionThradFunc(LPVOID pParam);
};
