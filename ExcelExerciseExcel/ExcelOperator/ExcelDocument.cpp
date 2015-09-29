#include "stdafx.h"
#include "ExcelDocument.h"

////////////////////////////////////////////////////////////////////////////////////////

COleVariant CExcelDocument::g_missing((LONG) DISP_E_PARAMNOTFOUND, VT_ERROR);

CExcelDocument::CExcelDocument()
{
    if (FALSE == m_application.CreateDispatch(TEXT("Excel.Application")))
    {
        throw TEXT("Excel����ʧ��");
    }

    ZeroMemory(m_filename, MAX_PATH);
}

CExcelDocument::~CExcelDocument()
{
    if (m_filename[0] != 0 && m_filename[0] != '0')
    {
        m_workbook.Close(variant_t((short) FALSE), variant_t(m_filename), g_missing);
        m_workbooks.Close();
        ZeroMemory(m_filename, MAX_PATH);

        m_range.ReleaseDispatch();
        m_worksheet.ReleaseDispatch();
        m_worksheets.ReleaseDispatch();
        m_workbook.ReleaseDispatch();
        m_workbooks.ReleaseDispatch();
    }

    m_application.Quit();
    m_application.ReleaseDispatch();
}

BOOL CExcelDocument::Create(LPCTSTR lpszFileName)
{
    LPDISPATCH lpDisBooks = m_application.get_Workbooks();
    if (NULL == lpDisBooks)
    {
        return FALSE;
    }

    m_workbooks.AttachDispatch(lpDisBooks);

    LPDISPATCH lpDisBook = m_workbooks.Add(variant_t(lpszFileName));
    if (lpDisBook)
    {
        m_workbook.AttachDispatch(lpDisBook);
        m_worksheets.AttachDispatch(m_workbook.get_Sheets());
        m_worksheet = m_worksheets.get_Item(variant_t((BYTE) 1));
        m_range = m_worksheet.get_Range(variant_t(TEXT("A1")), variant_t(TEXT("A1")));

        lstrcpyn(m_filename, lpszFileName, MAX_PATH);

        return TRUE;
    }

    m_workbooks.Close();
    m_workbooks.DetachDispatch();

    return FALSE;
}

BOOL CExcelDocument::Open(LPCTSTR lpszFileName)
{
    LPDISPATCH lpDisBooks = m_application.get_Workbooks();
    if (NULL == lpDisBooks)
    {
        return FALSE;
    }

    m_workbooks.AttachDispatch(lpDisBooks);

    LPDISPATCH lpDisBook = m_workbooks.Add(variant_t(lpszFileName));
    if (lpDisBook)
    {
        m_workbook.AttachDispatch(lpDisBook);
        m_worksheets.AttachDispatch(m_workbook.get_Sheets());
        m_worksheet = m_worksheets.get_Item(variant_t((BYTE) 1));
        m_range = m_worksheet.get_Range(variant_t(TEXT("A1")), variant_t(TEXT("A1")));

        lstrcpyn(m_filename, lpszFileName, MAX_PATH);

        return TRUE;
    }

    m_workbooks.Close();
    m_workbooks.DetachDispatch();

    return FALSE;
}

BOOL CExcelDocument::Close(BOOL bSave)
{
    if (m_filename[0] == 0 || m_filename[0] == '0')
    {
        return TRUE;
    }

    //����
    if (bSave)
    {
        m_workbook.SaveCopyAs(COleVariant(m_filename)); 
    }
    m_workbook.put_Saved(bSave);
    m_workbook.Close(variant_t((short) bSave), variant_t(m_filename), variant_t((short) FALSE));
    m_workbooks.Close();
    ZeroMemory(m_filename, MAX_PATH);

    m_range.ReleaseDispatch();
    m_worksheet.ReleaseDispatch();
    m_worksheets.ReleaseDispatch();
    m_workbook.ReleaseDispatch();
    m_workbooks.ReleaseDispatch();

    return TRUE;
}

////////////////////////////////////////////////////////////////////////////////////////