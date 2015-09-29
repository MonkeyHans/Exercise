// ExcelOperator.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "BusinessInfoPrintHead.h"
#include "ExcelDocument.h"
#include <comutil.h>

#define PIC_MARGIN          10


BUSINESSPRINT_API long __stdcall BusinessInfoPrint(TBusinessInfo businessInfo)
{
    //模块路径
    TCHAR szModuleFileName[MAX_PATH];
    if (FALSE == GetModuleFileName(NULL, szModuleFileName, MAX_PATH))
    {
        OutputDebugString(TEXT("获取模块路径失败\r\n"));
        return 1;
    }

    //模板全文件名
    TCHAR szExcelTemplate[MAX_PATH];
    _sntprintf_s(szExcelTemplate, _countof(szExcelTemplate), TEXT("%s/../BusinessInfoTemplate.xls"), szModuleFileName);

    //临时文件名
    //TCHAR szTempPath[MAX_PATH];
    //TCHAR szTempFileName[MAX_PATH];
    //srand(GetCurrentTime());
    //_sntprintf_s(szTempFileName, _countof(szTempFileName), TEXT("%s/../%d_%d_%d.xls"), 
    //    szModuleFileName, GetTickCount(), rand() % 32767, time(NULL));

    //复制模板到临时文件
    //if (FALSE == CopyFile(szExcelTemplate, szTempFileName, FALSE))
    //{
    //    OutputDebugString(TEXT("获取模板到临时文件失败\r\n"));
    //    return 3;
    //}


    BOOL bReturn = S_OK;
    CExcelDocument document;

    //打开模板
    if (S_OK == bReturn)
    {
        try
        {
            if (FALSE == document.Open(szExcelTemplate))
            {
                bReturn = 2;
            }
        }
        catch (...)
        {
            OutputDebugString(TEXT("打开模板异常\r\n"));
            bReturn = 3;
        }
    }

    //写入交易信息
    if (S_OK == bReturn)
    {
        try
        {
            //客户姓名
            document.m_range.put_Item(variant_t(2), variant_t(2), variant_t(businessInfo.szCustomName));

            //身份证
            document.m_range.put_Item(variant_t(3), variant_t(2), variant_t(businessInfo.szCustomId));

            //卡号/账号
            document.m_range.put_Item(variant_t(4), variant_t(2), variant_t(businessInfo.szCustomBankAccout));

            //业务类型
            document.m_range.put_Item(variant_t(5), variant_t(2), variant_t(businessInfo.szBusinessType));

            //产品编号
            document.m_range.put_Item(variant_t(6), variant_t(2), variant_t(businessInfo.szProductId));

            //交易时间
            document.m_range.put_Item(variant_t(7), variant_t(2), variant_t(businessInfo.szBusinessTime));

            //营业网点名称
            document.m_range.put_Item(variant_t(8), variant_t(2), variant_t(businessInfo.szBankName));

            //业务员姓名
            document.m_range.put_Item(variant_t(9), variant_t(2), variant_t(businessInfo.szBankEmployeeName));

            //产品名称
            document.m_range.put_Item(variant_t(5), variant_t(4), variant_t(businessInfo.szProductName));

            //业务单号
            document.m_range.put_Item(variant_t(6), variant_t(4), variant_t(businessInfo.szBusinessId));

            //产品购买周期
            document.m_range.put_Item(variant_t(7), variant_t(4), variant_t(businessInfo.szProductPeriod));

            //营业网点编号
            document.m_range.put_Item(variant_t(8), variant_t(4), variant_t(businessInfo.szBankId));

            //业务员编号
            document.m_range.put_Item(variant_t(9), variant_t(4), variant_t(businessInfo.szBankEmployeeId));

            //Excel 形状接口
            CShapes shapes;
            LPDISPATCH lpDisShapes = document.m_worksheet.get_Shapes();
            shapes.AttachDispatch(lpDisShapes);

            //录像开始截图位置
            CRange rangeA11 = document.m_worksheet.get_Range(variant_t(TEXT("A11")), document.m_missing);
            CRange rangeB22 = document.m_worksheet.get_Range(variant_t(TEXT("B22")), document.m_missing);
            double leftA11 = rangeA11.get_Left().dblVal + PIC_MARGIN;
            double topA11 = rangeA11.get_Top().dblVal + PIC_MARGIN;
            double imageWidth = rangeA11.get_Width().dblVal + rangeB22.get_Width().dblVal - PIC_MARGIN * 2;
            double imageHeight = (rangeB22.get_Top().dblVal + rangeB22.get_Height().dblVal) - rangeA11.get_Top().dblVal - PIC_MARGIN * 2;

            //添加录像开始截图
            CShape shape1 = shapes.AddPicture(businessInfo.szSnapshotBegin, 0, 1, 
                leftA11, topA11, imageWidth, imageHeight);

            //录像结束截图位置
            CRange rangeC11 = document.m_worksheet.get_Range(variant_t(TEXT("C11")), document.m_missing);
            CRange rangeD22 = document.m_worksheet.get_Range(variant_t(TEXT("D22")), document.m_missing);
            double leftC11 = rangeC11.get_Left().dblVal + PIC_MARGIN;
            double topC11 = rangeC11.get_Top().dblVal + PIC_MARGIN;
            double imageWidth2 = rangeC11.get_Width().dblVal + rangeD22.get_Width().dblVal - PIC_MARGIN * 2;
            double imageHeight2 = (rangeD22.get_Top().dblVal + rangeD22.get_Height().dblVal) - rangeC11.get_Top().dblVal - PIC_MARGIN * 2;

            //添加录像结束截图
            CShape shape2 = shapes.AddPicture(businessInfo.szSnapshotEndp, 0, 1, 
                leftC11, topC11, imageWidth2, imageHeight2);

            shapes.ReleaseDispatch();
            rangeA11.ReleaseDispatch();
            rangeB22.ReleaseDispatch();
            rangeC11.ReleaseDispatch();
            rangeD22.ReleaseDispatch();
            shape1.ReleaseDispatch();
            shape2.ReleaseDispatch();
        }
        catch (...)
        {
            OutputDebugString(TEXT("写入交易信息异常\r\n"));
            bReturn = 4;
        }
    }

    //打印
    if (S_OK == bReturn)
    {
        try
        {
            document.m_worksheet.PrintOut(variant_t(1), variant_t(1), variant_t(1), variant_t((short) FALSE), 
                document.m_missing, variant_t((short) FALSE), variant_t((short) FALSE), document.m_missing);
        }
        catch (...)
        {
            OutputDebugString(TEXT("打印异常\r\n"));
            bReturn = 5;
        }
    }

    //关闭释放文档
    try
    {
        document.Close(FALSE);
    }
    catch (COleDispatchException * pEx)
    {
        OutputDebugString(pEx->m_strDescription);
    }
    catch (...)
    {
        OutputDebugString(TEXT("关闭文档异常\r\n"));
    }

    return bReturn;
}