#ifndef EXCEL_DOCUMENT_HEAD_FILE
#define EXCEL_DOCUMENT_HEAD_FILE

#pragma once

#include "stdafx.h"

#include "Application.h"
#include "Workbook.h"
#include "Workbooks.h"
#include "Worksheet.h"
#include "Worksheets.h"
#include "Range.h"
#include "CShape.h"
#include "Shapes.h"

////////////////////////////////////////////////////////////////////////////////////////

//Excel ÎÄµµ²Ù×÷Àà
class CExcelDocument
{
private:
    CApplication                    m_application;
    CWorkbooks                      m_workbooks;
    TCHAR                           m_filename[MAX_PATH];

public:
    CWorkbook                       m_workbook;
    CWorksheet                      m_worksheet;
    CWorksheets                     m_worksheets;
    CRange                          m_range;
    COleVariant                     m_missing;

public:
    CExcelDocument();
    virtual ~CExcelDocument();

    BOOL Create(LPCTSTR lpszFileName);
    BOOL Open(LPCTSTR lpszFileName);
    BOOL Close(BOOL bSave = TRUE);
};

////////////////////////////////////////////////////////////////////////////////////////

#endif  // EXCEL_DOCUMENT_HEAD_FILE