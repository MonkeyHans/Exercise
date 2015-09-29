#ifndef EXCEL_OPERATOR_HEAD_FILE
#define EXCEL_OPERATOR_HEAD_FILE

/////////////////////////////////////////////////////////////////

#ifndef BUSINESSPRINT_EXPORTS
#define BUSINESSPRINT_API extern "C" __declspec(dllimport)
#else
#define BUSINESSPRINT_API extern "C" __declspec(dllexport)
#endif

/////////////////////////////////////////////////////////////////

#pragma once

typedef struct tagBusinessInfo{
    char        szCustomName[100];          //�ͻ�����
    char        szCustomId[25];             //�ͻ����֤
    char        szCustomBankAccout[25];     //�ͻ����п���
    char        szBusinessType[50];         //ҵ������
    char        szProductName[100];         //��Ʒ����
    char        szProductId[50];            //��Ʒ���
    char        szBusinessId[50];           //ҵ�񵥺�
    char        szBusinessTime[25];         //����ʱ��
    char        szProductPeriod[10];        //��Ʒ��������
    char        szBankName[100];            //��������
    char        szBankId[50];               //������
    char        szBankEmployeeName[100];    //ҵ��Ա����
    char        szBankEmployeeId[50];       //ҵ��Ա���
    char        szSnapshotBegin[250];       //¼��ʼ��ͼ·��
    char        szSnapshotEndp[250];        //¼�������ͼ·��
}TBusinessInfo, *PTBusinessInfo;

/////////////////////////////////////////////////////////////////

//��ӡ������Ϣ
//����ֵ��0 �ɹ�������ֵʧ��
BUSINESSPRINT_API long __stdcall BusinessInfoPrint(TBusinessInfo businessInfo);

/////////////////////////////////////////////////////////////////

#endif