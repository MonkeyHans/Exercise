
// HYNVRExercise.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CHYNVRExerciseApp:
// �йش����ʵ�֣������ HYNVRExercise.cpp
//

class CHYNVRExerciseApp : public CWinApp
{
public:
	CHYNVRExerciseApp();

// ��д
public:
	virtual BOOL InitInstance();
    virtual BOOL ExitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CHYNVRExerciseApp theApp;