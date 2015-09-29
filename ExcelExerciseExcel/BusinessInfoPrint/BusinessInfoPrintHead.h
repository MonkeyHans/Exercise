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
    char        szCustomName[100];          //客户姓名
    char        szCustomId[25];             //客户身份证
    char        szCustomBankAccout[25];     //客户银行卡号
    char        szBusinessType[50];         //业务类型
    char        szProductName[100];         //产品名称
    char        szProductId[50];            //产品编号
    char        szBusinessId[50];           //业务单号
    char        szBusinessTime[25];         //交易时间
    char        szProductPeriod[10];        //产品购买周期
    char        szBankName[100];            //网点名称
    char        szBankId[50];               //网点编号
    char        szBankEmployeeName[100];    //业务员姓名
    char        szBankEmployeeId[50];       //业务员编号
    char        szSnapshotBegin[250];       //录像开始截图路径
    char        szSnapshotEndp[250];        //录像结束截图路径
}TBusinessInfo, *PTBusinessInfo;

/////////////////////////////////////////////////////////////////

//打印交易信息
//返回值：0 成功；其他值失败
BUSINESSPRINT_API long __stdcall BusinessInfoPrint(TBusinessInfo businessInfo);

/////////////////////////////////////////////////////////////////

#endif