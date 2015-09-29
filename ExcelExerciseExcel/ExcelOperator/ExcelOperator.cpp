// ExcelOperator.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "ExcelOperatorHead.h"
//#include "ExcelDocument.h"
#include <comutil.h>

EXCELOPERATOR_API long __stdcall PrintBusinessInfo(TBusinessInfo businessInfo)
{
    //CExcelDocument document;
    //if (document.Open(TEXT("bussiness_template.xls")))
    //{
    //    document.Close(FALSE);
    //}
    variant_t excelApp;

    //try
    //{
    //    excelApp = CreateOleObject();
    //}
    //catch (...)
    //{
    //}


    return -1;
}