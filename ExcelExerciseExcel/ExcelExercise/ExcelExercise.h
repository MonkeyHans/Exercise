
// ExcelExercise.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CExcelExerciseApp:
// �йش����ʵ�֣������ ExcelExercise.cpp
//

class CExcelExerciseApp : public CWinApp
{
public:
	CExcelExerciseApp();

// ��д
public:
	virtual BOOL InitInstance();
    virtual BOOL ExitInstance();
// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CExcelExerciseApp theApp;