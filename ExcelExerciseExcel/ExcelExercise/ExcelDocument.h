#ifndef EXCEL_DOCUMENT_HEAD_FILE
#define EXCEL_DOCUMENT_HEAD_FILE

#pragma once

#include "stdafx.h"

#include "CApplication.h"
#include "CWorkbook.h"
#include "CWorkbooks.h"
#include "CWorksheet.h"
#include "CWorksheets.h"
#include "CRange.h"
#include "CShapes.h"

////////////////////////////////////////////////////////////////////////////////////////

//Excel ÎÄµµ²Ù×÷Àà
class CExcelDocument
{
public:
    CApplication                    m_application;
    CWorkbook                       m_workbook;
    CWorkbooks                      m_workbooks;
    CWorksheet                      m_worksheet;
    CWorksheets                     m_worksheets;
    CRange                          m_range;
    TCHAR                           m_filename[MAX_PATH];

    static COleVariant              g_missing;

public:
    CExcelDocument();
    ~CExcelDocument();

    BOOL Create(LPCTSTR lpszFileName);
    BOOL Open(LPCTSTR lpszFileName);
    BOOL Close(BOOL bSave = TRUE);
};

////////////////////////////////////////////////////////////////////////////////////////

#endif  // EXCEL_DOCUMENT_HEAD_FILE