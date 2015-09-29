
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
    SSNetSdk_COM::IRealPlayerPtr m_realPlay[4];
    SSNetSdk_COM::IVideoDevicePtr m_videoDevice[10];
    SSNetSdk_COM::IVideoChannelPtr m_videoChannel[10][10];
    SSNetSdk_COM::IComStreamerPtr m_streamer[4];
    CStreamEvent * m_pStreamEvent[4];

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
