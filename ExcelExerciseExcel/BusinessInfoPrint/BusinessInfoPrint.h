// BusinessInfoPrint.h : BusinessInfoPrint DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CBusinessInfoPrintApp
// �йش���ʵ�ֵ���Ϣ������� BusinessInfoPrint.cpp
//

class CBusinessInfoPrintApp : public CWinApp
{
public:
	CBusinessInfoPrintApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
