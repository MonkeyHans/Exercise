
// TJJDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTJJDemoApp:
// �йش����ʵ�֣������ TJJDemo.cpp
//

class CTJJDemoApp : public CWinApp
{
public:
	CTJJDemoApp();

// ��д
public:
	virtual BOOL InitInstance();
    virtual BOOL ExitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTJJDemoApp theApp;