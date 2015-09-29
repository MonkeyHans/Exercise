// ExcelOperator.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "BusinessInfoPrintHead.h"
#include "ExcelDocument.h"
#include <comutil.h>

#define PIC_MARGIN          10


BUSINESSPRINT_API long __stdcall BusinessInfoPrint(TBusinessInfo businessInfo)
{
    //ģ��·��
    TCHAR szModuleFileName[MAX_PATH];
    if (FALSE == GetModuleFileName(NULL, szModuleFileName, MAX_PATH))
    {
        OutputDebugString(TEXT("��ȡģ��·��ʧ��\r\n"));
        return 1;
    }

    //ģ��ȫ�ļ���
    TCHAR szExcelTemplate[MAX_PATH];
    _sntprintf_s(szExcelTemplate, _countof(szExcelTemplate), TEXT("%s/../BusinessInfoTemplate.xls"), szModuleFileName);

    //��ʱ�ļ���
    //TCHAR szTempPath[MAX_PATH];
    //TCHAR szTempFileName[MAX_PATH];
    //srand(GetCurrentTime());
    //_sntprintf_s(szTempFileName, _countof(szTempFileName), TEXT("%s/../%d_%d_%d.xls"), 
    //    szModuleFileName, GetTickCount(), rand() % 32767, time(NULL));

    //����ģ�嵽��ʱ�ļ�
    //if (FALSE == CopyFile(szExcelTemplate, szTempFileName, FALSE))
    //{
    //    OutputDebugString(TEXT("��ȡģ�嵽��ʱ�ļ�ʧ��\r\n"));
    //    return 3;
    //}


    BOOL bReturn = S_OK;
    CExcelDocument document;

    //��ģ��
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
            OutputDebugString(TEXT("��ģ���쳣\r\n"));
            bReturn = 3;
        }
    }

    //д�뽻����Ϣ
    if (S_OK == bReturn)
    {
        try
        {
            //�ͻ�����
            document.m_range.put_Item(variant_t(2), variant_t(2), variant_t(businessInfo.szCustomName));

            //���֤
            document.m_range.put_Item(variant_t(3), variant_t(2), variant_t(businessInfo.szCustomId));

            //����/�˺�
            document.m_range.put_Item(variant_t(4), variant_t(2), variant_t(businessInfo.szCustomBankAccout));

            //ҵ������
            document.m_range.put_Item(variant_t(5), variant_t(2), variant_t(businessInfo.szBusinessType));

            //��Ʒ���
            document.m_range.put_Item(variant_t(6), variant_t(2), variant_t(businessInfo.szProductId));

            //����ʱ��
            document.m_range.put_Item(variant_t(7), variant_t(2), variant_t(businessInfo.szBusinessTime));

            //Ӫҵ��������
            document.m_range.put_Item(variant_t(8), variant_t(2), variant_t(businessInfo.szBankName));

            //ҵ��Ա����
            document.m_range.put_Item(variant_t(9), variant_t(2), variant_t(businessInfo.szBankEmployeeName));

            //��Ʒ����
            document.m_range.put_Item(variant_t(5), variant_t(4), variant_t(businessInfo.szProductName));

            //ҵ�񵥺�
            document.m_range.put_Item(variant_t(6), variant_t(4), variant_t(businessInfo.szBusinessId));

            //��Ʒ��������
            document.m_range.put_Item(variant_t(7), variant_t(4), variant_t(businessInfo.szProductPeriod));

            //Ӫҵ������
            document.m_range.put_Item(variant_t(8), variant_t(4), variant_t(businessInfo.szBankId));

            //ҵ��Ա���
            document.m_range.put_Item(variant_t(9), variant_t(4), variant_t(businessInfo.szBankEmployeeId));

            //Excel ��״�ӿ�
            CShapes shapes;
            LPDISPATCH lpDisShapes = document.m_worksheet.get_Shapes();
            shapes.AttachDispatch(lpDisShapes);

            //¼��ʼ��ͼλ��
            CRange rangeA11 = document.m_worksheet.get_Range(variant_t(TEXT("A11")), document.m_missing);
            CRange rangeB22 = document.m_worksheet.get_Range(variant_t(TEXT("B22")), document.m_missing);
            double leftA11 = rangeA11.get_Left().dblVal + PIC_MARGIN;
            double topA11 = rangeA11.get_Top().dblVal + PIC_MARGIN;
            double imageWidth = rangeA11.get_Width().dblVal + rangeB22.get_Width().dblVal - PIC_MARGIN * 2;
            double imageHeight = (rangeB22.get_Top().dblVal + rangeB22.get_Height().dblVal) - rangeA11.get_Top().dblVal - PIC_MARGIN * 2;

            //���¼��ʼ��ͼ
            CShape shape1 = shapes.AddPicture(businessInfo.szSnapshotBegin, 0, 1, 
                leftA11, topA11, imageWidth, imageHeight);

            //¼�������ͼλ��
            CRange rangeC11 = document.m_worksheet.get_Range(variant_t(TEXT("C11")), document.m_missing);
            CRange rangeD22 = document.m_worksheet.get_Range(variant_t(TEXT("D22")), document.m_missing);
            double leftC11 = rangeC11.get_Left().dblVal + PIC_MARGIN;
            double topC11 = rangeC11.get_Top().dblVal + PIC_MARGIN;
            double imageWidth2 = rangeC11.get_Width().dblVal + rangeD22.get_Width().dblVal - PIC_MARGIN * 2;
            double imageHeight2 = (rangeD22.get_Top().dblVal + rangeD22.get_Height().dblVal) - rangeC11.get_Top().dblVal - PIC_MARGIN * 2;

            //���¼�������ͼ
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
            OutputDebugString(TEXT("д�뽻����Ϣ�쳣\r\n"));
            bReturn = 4;
        }
    }

    //��ӡ
    if (S_OK == bReturn)
    {
        try
        {
            document.m_worksheet.PrintOut(variant_t(1), variant_t(1), variant_t(1), variant_t((short) FALSE), 
                document.m_missing, variant_t((short) FALSE), variant_t((short) FALSE), document.m_missing);
        }
        catch (...)
        {
            OutputDebugString(TEXT("��ӡ�쳣\r\n"));
            bReturn = 5;
        }
    }

    //�ر��ͷ��ĵ�
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
        OutputDebugString(TEXT("�ر��ĵ��쳣\r\n"));
    }

    return bReturn;
}