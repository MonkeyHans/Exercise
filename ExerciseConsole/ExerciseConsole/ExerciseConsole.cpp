// ExerciseConsole.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <sstream>
#include <varargs.h>
#include <iostream>
#include <vector>
#include <memory>
#include <time.h>
#include <atlbase.h>
#include <atlcom.h>
#include <map>
#include "JpegCompress.h"
#include "HYResizeImage.h"
#include "XPlayDll.h"

#pragma comment(lib, "HYResizeImage.lib")
#pragma comment(lib, "XPlayDll.lib")

#pragma warning(push,1)
#pragma warning(disable: 4005)

using namespace std;

#import "SSNetSdk.COM.tlb"
//#include <ssnetsdk.com.tlh>

#include <atlbase.h>
CComModule _Module;
#include <atlcom.h>
#include "algorithm"

#define TJJ_FILEHEAD            {'T', 'J', 'J', '0'}    //add by hanhb 2015-07-06

VOID TraceA(char * fmt, ...)
{
    //_VA_LIST argList;

    //va_start(argList, psz);

    //CHAR szOutput[1024];

    //_snprintf_s(szOutput, 1024, psz, argList);
    //OutputDebugStringA(szOutput);

    //::std::ostringstream streamBuf;

    ////int i = 0;

    ////do 
    ////{
    ////    i = va_arg(argList, CHAR *);
    ////} while (-1 != i);

    //va_end(argList);

    double vargflt = 0;  
    int  vargint = 0;  
    char* vargpch = NULL;  
    char vargch = 0;  
    char* pfmt = NULL;  
    va_list vp;  
  
    va_start(vp, fmt);  
    pfmt = fmt;  

    ::std::string str = "";
    ::std::ostringstream streamBuf;
  
    while(*pfmt)  
    {  
        if(*pfmt == '%')  
        {  
            switch(*(++pfmt))  
            {  
                  
                case 'c':  
                    vargch = va_arg(vp, int);   
                    /*    va_arg(ap, type), if type is narrow type (char, short, float) an error is given in strict ANSI 
                        mode, or a warning otherwise.In non-strict ANSI mode, 'type' is allowed to be any expression. */  
                    //printch(vargch);  
                    streamBuf<<vargch;
                    break;  
                case 'd':  
                case 'i':  
                    vargint = va_arg(vp, int);  
                    //printdec(vargint);  
                    streamBuf<<vargint;
                    break;  
                case 'f':  
                    vargflt = va_arg(vp, double);  
                    /*    va_arg(ap, type), if type is narrow type (char, short, float) an error is given in strict ANSI 
                        mode, or a warning otherwise.In non-strict ANSI mode, 'type' is allowed to be any expression. */  
                    //printflt(vargflt);  
                    streamBuf<<vargflt;
                    break;  
                case 's':  
                    vargpch = va_arg(vp, char*);  
                    //printstr(vargpch);  
                    streamBuf<<vargpch;
                    break;  
                case 'b':  
                case 'B':  
                    vargint = va_arg(vp, int);  
                    //printbin(vargint);  
                    streamBuf<<vargint;
                    break;  
                case 'x':  
                case 'X':  
                    vargint = va_arg(vp, int);  
                    //printhex(vargint);  
                    streamBuf<<vargint;
                    break;  
                case '%':  
                    //printch('%');  
                    streamBuf<<'%';
                    break;  
                default:  
                    break;  
            }  
            pfmt++;  
        }  
        else  
        {  
            streamBuf<<*pfmt++;
            //printch(*pfmt++);  
        }  
    }  
    va_end(vp); 

    OutputDebugStringA(streamBuf.str().c_str());
}

VOID TraceW(WCHAR * fmt, ...)
{
    double vargflt = 0;  
    int  vargint = 0;  
    WCHAR* vargpch = NULL;  
    WCHAR vargch = 0;  
    WCHAR* pfmt = NULL;  
    va_list vp;  
  
    va_start(vp, fmt);  
    pfmt = fmt;  

    ::std::wostringstream streamBuf;
  
    while(*pfmt)  
    {  
        if(*pfmt == '%')  
        {  
            switch(*(++pfmt))  
            {  
                  
                case 'c':  
                    vargch = va_arg(vp, int);   
                    /*    va_arg(ap, type), if type is narrow type (char, short, float) an error is given in strict ANSI 
                        mode, or a warning otherwise.In non-strict ANSI mode, 'type' is allowed to be any expression. */  
                    //printch(vargch);  
                    streamBuf<<vargch;
                    break;  
                case 'd':  
                case 'i':  
                    vargint = va_arg(vp, int);  
                    //printdec(vargint);  
                    streamBuf<<vargint;
                    break;  
                case 'f':  
                    vargflt = va_arg(vp, double);  
                    /*    va_arg(ap, type), if type is narrow type (char, short, float) an error is given in strict ANSI 
                        mode, or a warning otherwise.In non-strict ANSI mode, 'type' is allowed to be any expression. */  
                    //printflt(vargflt);  
                    streamBuf<<vargflt;
                    break;  
                case 's':  
                    vargpch = va_arg(vp, WCHAR*);  
                    //printstr(vargpch);  
                    streamBuf<<vargpch;
                    break;  
                case 'b':  
                case 'B':  
                    vargint = va_arg(vp, int);  
                    //printbin(vargint);  
                    streamBuf<<vargint;
                    break;  
                case 'x':  
                case 'X':  
                    vargint = va_arg(vp, int);  
                    //printhex(vargint);  
                    streamBuf<<vargint;
                    break;  
                case '%':  
                    //printch('%');  
                    streamBuf<<'%';
                    break;  
                default:  
                    break;  
            }  
            pfmt++;  
        }  
        else  
        {  
            streamBuf<<*pfmt++;
            //printch(*pfmt++);  
        }  
    }  
    va_end(vp); 

    OutputDebugStringW(streamBuf.str().c_str());
}

class CTest
{
private:
    int         m_nWidth;
    int         m_nHeight;
    void *      m_pData;

public:
    CTest()
    {
        m_nWidth = 100;
        m_nHeight = 200;
        m_pData = new int(300);
    }

    static void Print()
    { 
        cout<<"Hello"<<endl;
    }

    void TestConst()
    {
        m_nWidth = 1001;
        m_nHeight = 2001;
        m_pData = new int(3001);
    }

    void TestConst1() const
    {
        //error C3490: 由于正在通过常量对象访问“m_nWidth”，因此无法对其进行修改
        //m_nWidth = 1001;         
        //m_nHeight = 2001;
        //m_pData = new int(3001);
    }

    const void * const TestConst2()
    {
        return m_pData;
    }

    const int TestConst3()
    {
        return m_nWidth;
    }

    const int & TestConst4() const
    {
        //error C3490: 由于正在通过常量对象访问“m_nWidth”，因此无法对其进行修改
        //m_nWidth = 1001;
        //m_nHeight = 2001;
        return m_nWidth;
    }

    const CTest & TestConst6()
    {
        static CTest test;
        return test;
    }

    static void TestContest5(CTest & test1, const CTest & test2)
    {
        test1.TestConst();
        test1.TestConst1();
        test1.TestConst2();
        test1.TestConst3();
        test1.TestConst4();

        //error C2678: 二进制“=”: 没有找到接受“const CTest”类型的左操作数的运算符(或没有可接受的转换)
        //test2 = test1;
        //error C2662: “CTest::TestConst”: 不能将“this”指针从“const CTest”转换为“CTest &”
        //test2.TestConst();
        //test2.TestConst2();
        //test2.TestConst3();
        const void * pData1 = test1.TestConst2();
        int n2 = test1.TestConst4();
        const CTest & test5 = test1.TestConst6();

        pData1 = new int(102);
        //*pData1 = 100;//error C2100: 非法的间接寻址&error C2440: “=”: 无法从“int”转换为“const void *”

        int i = 1011;
        n2 = 1001;
        n2 = i;

    }

    static void Const()
    {
        int nData = 101;
        const int m0 = 100;
        const int * m1 = new int(10);
        int const * m11 = new int(11);
        int * const m2 = new int(20);
        const int * const m3 = new int(30);

        const int & nRef1 = nData;
        //int & const nRef2 = nData;//warning C4227: 使用了记时错误: 忽略引用上的限定符

        //*m1 = 100;//error C3892: “m1”: 不能给常量赋值
        m1 = m2;

        //*m11 = 100;//error C3892: “m1”: 不能给常量赋值
        m11 = m1;

        //m2 = (int * const)m3;//error C3892: “m2”: 不能给常量赋值
        *m2 = 200;

        //m3 = m1;//error C3892: “m3”: 不能给常量赋值
        //*m3 = 300; //error C3892: “m3”: 不能给常量赋值
    }
};

typedef enum {   
    NET_BYPASS_MODE_UNKNOW,                           // 未知状态
    NET_BYPASS_MODE_BYPASS,                           // 旁路
    NET_BYPASS_MODE_NORMAL,                           // 正常
    NET_BYPASS_MODE_ISOLATED,                         // 隔离
}NET_BYPASS_MODE;

CRITICAL_SECTION criticalSection = {0};

//自动锁
class CAutoLock
{
private:
    CRITICAL_SECTION &                              m_CriticalSection;

public:
    CAutoLock(CRITICAL_SECTION & criticalSection) : m_CriticalSection(criticalSection)
    {
        EnterCriticalSection(&m_CriticalSection);
    }

    ~CAutoLock()
    {
        LeaveCriticalSection(&m_CriticalSection);
    }
};

void LockException()
{
    try
    {
        CAutoLock lock(criticalSection);
        throw 0;
    }
    catch (...)
    {
    }
}

typedef ::std::vector<::std::unique_ptr<BYTE>>   TestDataVec;
typedef ::std::map<long, RECT> TestMap;
TestDataVec testDataVec;

//void Data()
//{
//    int n = 129;
//    BYTE * pcbMsg = new BYTE(n);
//    _sntprintf_s((CHAR *)pcbMsg, n, n, TEXT("“ExerciseConsole.exe”: 已加载“C:\Windows\SysWOW64\KernelBase.dll”，"));
//    unique_ptr<BYTE> testByte(pcbMsg);
//    testDataVec.push_back(testByte);
//}

#define X 1
#define Y 2

extern "C" void __stdcall TestTJJPlay()
{
    CoInitialize(NULL);
    SSNetSdk_COM::ICOMClientPtr comClient;
    comClient.CreateInstance(__uuidof(SSNetSdk_COM::SimpleCOMClient));

    HANDLE hTempFile = CreateFile(TEXT("test.tjj"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE != hTempFile)
    {
        DWORD dwDataSize = 0;
        DWORD dwNumberOfBytesRead = 0;
        ReadFile(hTempFile, &dwDataSize, sizeof(DWORD), &dwNumberOfBytesRead, NULL);

        comClient->Login("192.168.20.171", 7011, "admin", "12345");

        HWND hWnd =  FindWindow(NULL, TEXT("TJJDemo"));
        SSNetSdk_COM::IComStreamPlayerPtr pStreamPlayer = comClient->CreateComStreamPlayer();

        if (NULL != pStreamPlayer)
        {
            BYTE * cbInputHead = new BYTE[dwDataSize];
            if (ReadFile(hTempFile, cbInputHead, dwDataSize, &dwNumberOfBytesRead, NULL))
            {
                //复制头帧数据
                SAFEARRAYBOUND bound[1] = {0};
                bound[0].lLbound = 0;
                bound[0].cElements = dwDataSize;
                SAFEARRAY * psaHead = SafeArrayCreate(VT_UI1, 1, bound);

                if (psaHead)
                {
                    BYTE * pcbHead;
                    SafeArrayAccessData(psaHead, (VOID **) &pcbHead);
                    for (ULONG i = 0; i < psaHead->rgsabound->cElements; i++)
                    {
                        pcbHead[i] = cbInputHead[i];
                    }
                    SafeArrayUnaccessData(psaHead);

                    bool bRet = false;
                    if (VARIANT_TRUE == pStreamPlayer->Open(psaHead, (long) hWnd))
                    {
                        bRet = true;
                    }

                    //SafeArrayDestroy(psaHead);
                    //delete cbInputHead;
                    //cbInputHead = NULL;

                    while (bRet)
                    {
                        if (ReadFile(hTempFile, &dwDataSize, sizeof(DWORD), &dwNumberOfBytesRead, NULL))
                        {
                            BYTE * cbInputData = new BYTE[dwDataSize];
                            if (ReadFile(hTempFile, cbInputData, dwDataSize, &dwNumberOfBytesRead, NULL))
                            {
                                //复制头帧数据
                                SAFEARRAYBOUND boundData[1] = {0};
                                boundData[0].lLbound = 0;
                                boundData[0].cElements = dwDataSize;
                                SAFEARRAY * psaData = SafeArrayCreate(VT_UI1, 1, boundData);

                                if (psaData)
                                {
                                    BYTE * pcbInputData;
                                    SafeArrayAccessData(psaData, (VOID **) &psaData);
                                    for (ULONG i = 0; i < psaData->rgsabound->cElements; i++)
                                    {
                                        pcbInputData[i] = cbInputData[i];
                                    }
                                    SafeArrayUnaccessData(psaData);

                                    bool bRet = false;
                                    if (VARIANT_TRUE == pStreamPlayer->InputStream(psaHead))
                                    {
                                        bRet = true;
                                    }

                                    //SafeArrayDestroy(psaData);
                                    delete cbInputData;
                                    cbInputData = NULL;
                                }
                            }

                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }

            //pStreamPlayer->Close();
        }
    }
}

extern "C" void __stdcall TestTJJPlayEx()
{
    //CoInitialize(NULL);
    //SSNetSdk_COM::ICOMClientPtr comClient;
    //comClient.CreateInstance(__uuidof(SSNetSdk_COM::SimpleCOMClient));
    XPlay_InitSDK(NULL, 0);

    HANDLE hTempFile = CreateFile(TEXT("video.tjj"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE != hTempFile)
    {
        DWORD dwDataSize = 0;
        DWORD dwNumberOfBytesRead = 0;
        ReadFile(hTempFile, &dwDataSize, sizeof(DWORD), &dwNumberOfBytesRead, NULL);

        BYTE * cbInputHead = new BYTE[dwDataSize];
        if (ReadFile(hTempFile, cbInputHead, dwDataSize, &dwNumberOfBytesRead, NULL))
        {
            LONG lPlayPort = XPlay_InitPlayChnEX(cbInputHead,dwDataSize);
            if (-1 == lPlayPort)
            {
                cout<<"XPlay_InitPlayChnEX 失败"<<endl;
            }
            else
            {
                if (FALSE == XPlay_OpenStream(lPlayPort, cbInputHead, dwDataSize))
                {
                    cout<<"XPlay_OpenStream 失败"<<endl;
                }

                HWND hWnd =  FindWindow(NULL, TEXT("TJJDemo"));
                HWND hSubWnd = NULL;
                if (NULL != hWnd)
                {
                    hSubWnd = GetDlgItem(hWnd, 1006);
                }
                hWnd = GetConsoleWindow();

                if (FALSE == XPlay_Play(lPlayPort, hWnd))
                {
                    cout<<"XPlay_Play 失败"<<endl;
                }
                else
                {
                    bool bRet = true;
                    while (bRet)
                    {
                        if (ReadFile(hTempFile, &dwDataSize, sizeof(DWORD), &dwNumberOfBytesRead, NULL))
                        {
                            BYTE * cbInputData = new BYTE[dwDataSize];
                            if (ReadFile(hTempFile, cbInputData, dwDataSize, &dwNumberOfBytesRead, NULL))
                            {
                                if (FALSE == XPlay_InputData(lPlayPort, cbInputData, dwDataSize))
                                {
                                    cout<<"XPlay_InputData 失败"<<endl;
                                }
                            }
                        }
                        else
                        {
                            break;
                        }
                    }

                    XPlay_Stop(lPlayPort);
                }

                XPlay_CloseStream(lPlayPort);
            }
        }
    }
}

#define HY_EXERCISE

#ifdef HY_EXERCISE

#include "hysdk/hynet.h"
#pragma comment(lib, "hysdk/hynet.lib")
#include "hysdk/hyplay.h"
#pragma comment(lib, "hysdk/hyplay.lib")

#include"dtsdk/VQInterface.h"
#include"dtsdk/YUVConvert.h"
#pragma comment(lib, "dtsdk/VideoQuality.lib")
#pragma comment(lib, "dtsdk/YUVConvert.lib")

#include "BusinessInfoPrintHead.h"
//#pragma comment(lib, "BusinessInfoPrint.lib")

typedef long (__stdcall * PFBusinessInfoPrint)(TBusinessInfo businessInfo);

long g_hyOldUserID;
long g_hyUserID;
long g_hyRealHandle;
long g_hyStreamHandle;

void CALLBACK MediaStream(LONG lStream, BYTE *pStream, int nLen, int nFrameType)
{
    if (g_hyStreamHandle == lStream)
    {
        //HYWriteReal(pThis->m_lRealHandle, pStream, nLen);

        switch(nFrameType)
        {
        case FRAME_HEADER:
        case FRAME_AUDIO:
        case FRAME_VIDEO_I:
        case FRAME_VIDEO_P:
        case FRAME_VIDEO_B:
            HYWriteReal(g_hyRealHandle, pStream,nLen);
            break;
        }
    }
}

void CALLBACK DecodeData(LONG  lDecoderHandle, char *pY, char *pU, char *pV, int nYStride, int nUVStride, int nWidth, int nHeight)
{

    CHAR szFileName[MAX_PATH] = {0};
    _snprintf_s(szFileName, MAX_PATH, "%I64d.jpg", GetTickCount64());
    ConvertSaveY_U_V_420((unsigned char *)pY, (unsigned char *)pU, (unsigned char *)pV, nYStride, nUVStride, nWidth, nHeight, szFileName);
    BYTE * rgbBuf = new BYTE[nWidth * nHeight * 3];
    BYTE * yuvBuf = new BYTE[nWidth * nHeight * 3];
    ConvertY_U_V_420toRGB((unsigned char *)pY, (unsigned char *)pV, (unsigned char *)pU, nYStride, nUVStride, rgbBuf, nWidth, nHeight);
    ConvertRGBtoYUV420(nWidth, nHeight, rgbBuf, yuvBuf);
    _snprintf_s(szFileName, MAX_PATH, "%s.jpg", szFileName);
    ConvertSaveYUV420(yuvBuf, nWidth, nHeight, szFileName);
    delete rgbBuf;
    delete yuvBuf;
}

void CALLBACK DecodeDataEx(LONG  lDecoderHandle, char *pData, int nLen, HY_FRAME_INFO* pFrameInfo)
{
    if(pFrameInfo->nType == FRAME_TYPE_YUV420)
    {
        CHAR szFileName[MAX_PATH] = {0};
        _snprintf_s(szFileName, MAX_PATH, "%d.jpg", pFrameInfo->nStamp);
        ConvertSaveYUV420((unsigned char *)pData, pFrameInfo->nWidth, pFrameInfo->nHeight, szFileName);
    }

}

void TestHYRealPlay()
{
    HYIpcInit();

    HYSetConnectTimeout(3000, 65535);
    HYSetReconnect(TRUE, 3000);

    BYTE nLimit = 0;
    g_hyUserID = HYLoginIPC(NULL, "192.168.20.137", 7000, "admin", "12345", &nLimit);
    if (-1 == g_hyUserID)
    {
        cout<<HYGetErrorMsg(HYGetLastError())<<endl;

        return;
    }

    g_hyOldUserID = g_hyUserID;
    g_hyStreamHandle = HYRequestStream(g_hyUserID, 1, 0, 39023);
    if (-1 != g_hyStreamHandle)
    {
        int nLastError = HYGetLastError();
        int nMediaHandle = HYMediaRegister(MediaStream);

        g_hyRealHandle = HYCreateReal(GetConsoleWindow());
        if (-1 != g_hyRealHandle)
        {
            HYSetStreamPlayMode(g_hyRealHandle, 0);
            HYRegDecodeData(DecodeData);
        }
        else
        {
            cout<<"HYCreateReal 失败"<<endl;
        }
    }
    else
    {
        cout<<"HYRequestStream 失败"<<endl;
    }
}

void TestHYRequest()
{
    DISK_SET diskSet = {0};
    if (E_OK != HYControlGetEx(g_hyUserID, REQUEST_DISK_INFO, NULL, 0, (char *) &diskSet, sizeof(diskSet)))
    {
        cout<<"发送请求失败 "<<HYGetErrorMsg(HYGetLastError())<<endl;
    }
    else
    {
        cout<<"发送请求成功 "<<HYGetErrorMsg(HYGetLastError())<<endl;
    }
}

void TestHYLogout()
{
    if (E_OK != HYLogoutIPC(g_hyUserID))
    {
        cout<<"退出登录失败 "<<HYGetErrorMsg(HYGetLastError())<<endl;
    }
    else
    {
        cout<<"退出登录成功 "<<HYGetErrorMsg(HYGetLastError())<<endl;
    }
    TestHYRequest();
}

void TestHYReLogin()
{
    BYTE nLimit = 0;
    g_hyUserID = HYLoginIPC(NULL, "192.168.20.137", 7000, "admin", "12345", &nLimit);
    if (-1 == g_hyUserID)
    {
        cout<<"重新登录失败 "<<HYGetErrorMsg(HYGetLastError())<<endl;
    }
    else
    {
        cout<<"重新登录成功 "<<HYGetErrorMsg(HYGetLastError())<<endl;
    }
    TestHYRequest();
    g_hyStreamHandle = HYRequestStream(g_hyUserID, 1, 0, 39023);
    if (-1 == g_hyStreamHandle)
    {
        cout<<"重新预览失败 "<<HYGetErrorMsg(HYGetLastError())<<endl;
    }
    else
    {
        cout<<"重新预览成功 "<<HYGetErrorMsg(HYGetLastError())<<endl;
    }
}

void TestHYStopPlay()
{
    HYCloseStream(g_hyStreamHandle);
    HYCloseReal(g_hyRealHandle);

    HYRegDecodeDataEx(NULL);
    HYMediaRegister(NULL);

    HYLogoutIPC(g_hyUserID);
    HYIpcClean();
}

#endif

SSNetSdk_COM::ICOMClientPtr comClient;

unsigned int __stdcall TJJExceptionThreadFunc(LPVOID lpParam)
{
    while (true)
    {
        comClient->Login("192.168.20.171", 7011, "admin", "12345");
        OutputDebugString("Thread ex");
        Sleep(5000);
    }
}

void InitTJJ()
{
    comClient.CreateInstance(__uuidof(SSNetSdk_COM::SimpleCOMClient));

    comClient->Login("192.168.20.171", 7011, "admin", "12345");
    _beginthreadex(NULL, 0, TJJExceptionThreadFunc, NULL, 0, NULL);
}



#define MAGIC_CODE      (('H' << 24) | ('Y' << 16) | ('M' << 8) | ('C'))
#define MAGIC_TEXT      "HYMC"

#define RAND_ROUND(min, max)    (rand() / (max + 1) * (max - min))


int _tmain(int argc, _TCHAR* argv[])
{
    //TraceA("s都是 %s；二%s", "对方", "电饭锅");
    //TraceW(L"s都是 %s；二%s", L"对方", L"电饭锅");

    //NET_BYPASS_MODE test32;
    //cout<<sizeof(NET_BYPASS_MODE)<<"  1"<<endl;
    //cout<<sizeof(test32)<<"  1"<<endl;

    //CTest::Print();

    //CTest::Const();

    //InitializeCriticalSection(&criticalSection);

    //const CTest * pTest1 = new CTest();
    ////CTest * pTest2 = pTest1;//error C2440: “初始化”: 无法从“const CTest *”转换为“CTest *”

    //CTest * const pTest3 = new CTest();
    //CTest * pTest4 = pTest3;
    ////const CTest & operator = (const CTest & test);

    //DeleteCriticalSection(&criticalSection);

    //LockException();

    //HANDLE ternHandle = OpenProcess(0, 0, 3592);
    //TerminateProcess(ternHandle, 0);

    //Data();
    //unique_ptr<BYTE> pBack(std::move(testDataVec.back()));
    //BYTE * pMsg = (BYTE *) (pBack.get());
    //cout<<testDataVec.front().get()<<endl;

    //::std::unique_ptr<BYTE[]> testByte;
    //testByte.operator* = new BYTE
    //testByte = ::std::move(new BYTE[40]);
    //testByte.reset(std::nullptr_t);
    //testByte.reset(new BYTE[20]);
    //sprintf_s((CHAR *)testByte.get(), 40, "error C2440: ");
    //cout<<(CHAR *)testByte.get()<<endl;

    //srand((unsigned int) time(NULL));
    //LONG lUserID1 = MAKELONG(MAKEWORD(rand() % 0xFF, rand() % 0xFF), (MAKEWORD(rand() % 0xFF, 0x7F)));
    //LONG lUserID2 = MAKELONG(MAKEWORD(rand() % 0xFF, rand() % 0xFF), (MAKEWORD(rand() % 0xFF, 0x7F)));
    //LONG lUserID3 = MAKELONG(MAKEWORD(rand() % 0xFF, rand() % 0xFF), (MAKEWORD(rand() % 0xFF, 0x7F)));

    //cout<<lUserID1<<"\t"<<lUserID2<<"\t"<<lUserID3<<endl;

    //BYTE cbDataArray[] = TJJ_FILEHEAD;

    //cout<<sizeof(cbDataArray)<<endl;

    //int nRet = system("net start ");

    //TCHAR szFullImageName[MAX_PATH];
    //DWORD dwSize = MAX_PATH;
    //QueryFullProcessImageName(GetCurrentProcess(), 0, szFullImageName, &dwSize);

    //cout<<szFullImageName<<endl;

    //BYTE cbSource[MAX_PATH] = {0};
    //BYTE cbDestination[MAX_PATH] = {0};

    //SAFEARRAYBOUND sourceBound = {0};
    //sourceBound.cElements = MAX_PATH;
    //sourceBound.lLbound = 0;

    //SAFEARRAY * pSource = SafeArrayCreate(VT_UI1, 1, &sourceBound);
    //if (pSource)
    //{
    //    BYTE * pcbSource = NULL;
    //    HRESULT hr = SafeArrayAccessData(pSource, (void **) &pcbSource);
    //    if (SUCCEEDED(hr))
    //    {
    //        for (long i = 0; i < sourceBound.cElements; i++)
    //        {
    //            pcbSource[i] = i + 10;
    //            //SafeArrayGetElement(pSource, i, &pcbSource);
    //        }
    //    }
    //    SafeArrayUnaccessData(pSource);

    //    long lArrayIndex = 0;
    //    for (long index = 0; index < pSource->rgsabound->cElements; index++)
    //    {
    //        long tempIndex = index;
    //        ::SafeArrayGetElement(pSource, &tempIndex, cbDestination + lArrayIndex);
    //        lArrayIndex++;
    //    }
    //}

//        printf("%d",X);
//        printf("\n%d",Y);
//#define Y 3   // C4005
//#pragma push_macro("Y")
//#pragma push_macro("X")
//        printf("\n%d",X);
//#define X 2   // C4005
//        printf("\n%d",X);
//#pragma pop_macro("X")
//        printf("\n%d",X);
//#pragma pop_macro("Y")
//        printf("\n%d",Y);



    //TestMap testmap;

    //RECT rect = {0};
    //rect.left = 10;
    //rect.top = 11;
    //rect.right = 101;
    //rect.bottom = 202;
    //testmap.insert(::std::pair<long, RECT>(1, rect));

    //RECT rect2 = {0};
    //rect2.left = 20;
    //rect2.top = 21;
    //rect2.right = 201;
    //rect2.bottom = 202;
    //testmap.emplace(::std::pair<long, RECT>(1, rect2));
    //testmap.insert(::std::pair<long, RECT>(1, rect2));
    //testmap[1] = rect2;

    //for (auto iter = testmap.begin(); iter != testmap.end(); iter++)
    //{
    //    cout<<iter->second.left<<","<<iter->second.top<<","<<iter->second.right<<","<<iter->second.bottom<<","<<endl;
    //}

    //CHAR szDirectory[MAX_PATH] = {0};
    //GetCurrentDirectoryA(MAX_PATH, szDirectory);

    //::std::string strDirectory = szDirectory;
    //::std::string strSourceFile;
    //::std::string strDestination;

    //CJpegCompress & compress = CJpegCompress::GetInstance();

    //strSourceFile = strDirectory + "\\1.jpg";
    //strDestination = strDirectory + "\\01.jpg";
    //compress.Compress(strSourceFile.c_str(), strDestination.c_str(), 50);

    //strSourceFile = strDirectory + "\\2.jpg";
    //strDestination = strDirectory + "\\02.jpg";
    //compress.Compress(strSourceFile.c_str(), strDestination.c_str(), 50);

    //strSourceFile = strDirectory + "\\3.jpg";
    //strDestination = strDirectory + "\\03.jpg";
    //compress.Compress(strSourceFile.c_str(), strDestination.c_str(), 50);

    //strSourceFile = strDirectory + "\\7.jpg";
    //strDestination = strDirectory + "\\07.jpg";
    //compress.CompressToSpecifySize(strSourceFile.c_str(), strDestination.c_str(), 1024 * 50, 90);

    //WCHAR szWDirectory[MAX_PATH] = {0};
    //GetCurrentDirectoryW(MAX_PATH, szWDirectory);

    //::std::wstring strWDirectory = szWDirectory;
    //::std::wstring strWSourceFile;
    //::std::wstring strWDestination;

    //strWSourceFile = strWDirectory + L"\\4.jpg";
    //strWDestination = strWDirectory + L"\\04.jpg";
    //bool bRet = compress.CompressEx(strWSourceFile.c_str(), strWDestination.c_str(), 50);

    //strWSourceFile = strWDirectory + L"\\5.jpg";
    //strWDestination = strWDirectory + L"\\05.jpg";
    //bRet = compress.CompressEx(strWSourceFile.c_str(), strWDestination.c_str(), 50);

    //strWSourceFile = strWDirectory + L"\\6.jpg";
    //strWDestination = strWDirectory + L"\\06.jpg";
    //bRet = compress.CompressEx(strWSourceFile.c_str(), strWDestination.c_str(), 50);

    //strWSourceFile = strWDirectory + L"\\8.jpg";
    //strWDestination = strWDirectory + L"\\08.jpg";
    //bRet = compress.ResizePixelEx(strWSourceFile.c_str(), strWDestination.c_str(), 352, 288);
    ////bRet = compress.CompressToSpecifySizeEx(strWSourceFile.c_str(), strWDestination.c_str(), 1024 * 50, 90);

    //HYResizeJPGFile("8.jpg", "008.jpg", 352, 288);
    //HANDLE hFile = CreateFileW(strWSourceFile.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    //DWORD dwFileSize = GetFileSize(hFile, NULL);
    //if (dwFileSize > 10 * 1024)
    //{
    //    DWORD dwReadSize = 0;
    //    BYTE * photoResult = new BYTE[dwFileSize];
    //    ReadFile(hFile, photoResult, dwFileSize, &dwReadSize, NULL);
    //    {
    //        cout<<dwReadSize<<dwFileSize;
    //    }

    //    //BYTE * pDesResult = new BYTE[dwFileSize];
    //    //GetTickCount()
    //    HYResizeJPGFile("8.jpg", "008.jpg", 352, 288);
    //    //HYResizeImage(photoResult, 1920, 1200, pDesResult, 352, 288);

    //    //HANDLE hNewFile = CreateFileW(L"008.jpg", GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    //    //if (INVALID_HANDLE_VALUE != hNewFile)
    //    //{
    //    //    WriteFile(hNewFile, pDesResult, dwFileSize, NULL, NULL);
    //    //}
    //    //CloseHandle(hNewFile);
    //}

    //srand(GetTickCount());
    //(rand() % 0x0FFF << 16) | rand() % 0xFFFF;

    //FILE * tempFile = NULL;
    //if (0 == fopen_s(&tempFile, strSourceFile.c_str(), "r"))
    //{
    //    fseek(tempFile, 0 , SEEK_END);
    //    long lTempFileSize = ftell(tempFile);
    //    fseek(tempFile, 0, SEEK_SET);

    //    BYTE * photoResult = new BYTE[lTempFileSize];
    //    int readNum = fread_s(photoResult, lTempFileSize, 1, lTempFileSize, tempFile);
    //    {
    //        cout<<readNum<<lTempFileSize;
    //    }
    //}

    /*struct _stat64i32 fileStatus;
    if (0 == _stat64i32("1.txt", &fileStatus))
    {
        long lFileSize = fileStatus.st_size;
        if (0 != rename("1.txt", "2.txt"))
        {
            int nErrorNo = errno;
            if (EACCES == nErrorNo)
            {
                cout<<"File by newname aleady exists or could not be created."<<endl;
            }
            else if (ENOENT == nErrorNo)
            {
                cout<<"File by oldname not found."<<endl;
            }
            else if (EINVAL == nErrorNo)
            {
                cout<<"Name contains invalid characters"<<endl;
            }

            if (0 == remove("2.txt"))
            {
                cout<<"The file is successfully deleted."<<endl;
            }

            if (0 == rename("1.txt", "2.txt"))
            {
                cout<<"After delete a file is already exists, Rename file is successfully."<<endl;
            }
        }
        else
        {
            cout<<"Rename a file is successfully."<<endl;
        }
    }*/
    //TestTJJPlayEx();

    //FILE * file = fopen("tt_debug.log", "w+");
    //char szDebug[MAX_PATH];
    //_snprintf_s(szDebug, MAX_PATH, "请求预览成功，通道%d,句柄%d\r\n", 1, 2);
    //fwrite(szDebug, sizeof(char), lstrlen(szDebug), file);
    //fflush(file);

    TBusinessInfo businessinfo = {0};
    sprintf_s(businessinfo.szCustomName, _countof(businessinfo.szCustomName), "王晓东");
    sprintf_s(businessinfo.szCustomId, _countof(businessinfo.szCustomId), "610122100000929292929");
    sprintf_s(businessinfo.szCustomBankAccout, _countof(businessinfo.szCustomBankAccout), "293848238484783");
    sprintf_s(businessinfo.szBusinessType, _countof(businessinfo.szBusinessType), "未知类型");
    sprintf_s(businessinfo.szProductName, _countof(businessinfo.szProductName), "离心式");
    sprintf_s(businessinfo.szProductId, _countof(businessinfo.szProductId), "334466776");
    sprintf_s(businessinfo.szBusinessId, _countof(businessinfo.szBusinessId), "9877878");
    sprintf_s(businessinfo.szBusinessTime, _countof(businessinfo.szBusinessTime), "2015-09-02 12:02:02");
    sprintf_s(businessinfo.szProductPeriod, _countof(businessinfo.szProductPeriod), "10 years");
    sprintf_s(businessinfo.szBankName, _countof(businessinfo.szBankName), "之支行");
    sprintf_s(businessinfo.szBankId, _countof(businessinfo.szBankId), "007");
    sprintf_s(businessinfo.szBankEmployeeName, _countof(businessinfo.szBankEmployeeName), "老五");
    sprintf_s(businessinfo.szBankEmployeeId, _countof(businessinfo.szBankEmployeeId), "521");
    sprintf_s(businessinfo.szSnapshotBegin, _countof(businessinfo.szSnapshotBegin), "D:/20150901180246_P1_01.bmp");
    sprintf_s(businessinfo.szSnapshotEndp, _countof(businessinfo.szSnapshotEndp), "D:/20150901180246_P2_01.bmp");
    //int nBusinessRet = BusinessInfoPrint(businessinfo);
    int nBusinessRet = -1;
    HINSTANCE hPrintInstance = LoadLibrary("BusinessInfoPrint.dll");
    if (NULL != hPrintInstance)
    {
        PFBusinessInfoPrint lpPrint = (PFBusinessInfoPrint)GetProcAddress(hPrintInstance, "BusinessInfoPrint");
        if (lpPrint)
        {
            nBusinessRet = lpPrint(businessinfo);
        }

        FreeLibrary(hPrintInstance);
    }

    cout<<"打印结果 "<<nBusinessRet<<endl;

//typedef struct tagBusinessInfo{
//    char        szCustomName[100];          //客户姓名
//    char        szCustomId[25];             //客户身份证
//    char        szCustomBankAccout[25];     //客户银行卡号
//    char        szBusinessType[50];         //业务类型
//    char        szProductName[100];         //产品名称
//    char        szProductId[50];            //产品编号
//    char        szBusinessId[50];           //业务单号
//    char        szBusinessTime[25];         //交易时间
//    char        szProductPeriod[10];        //产品购买周期
//    char        szBankName[100];            //网点名称
//    char        szBankId[50];               //网点编号
//    char        szBankEmployeeName[100];    //业务员姓名
//    char        szBankEmployeeId[50];       //业务员编号
//    char        szSnapshotBegin[250];       //录像开始截图路径
//    char        szSnapshotEndp[250];        //录像结束截图路径
//}TBusinessInfo, *PTBusinessInfo;


    

    /*InitTJJ();

    srand((unsigned int) GetCurrentTime());
    for (int i = 0; i < 100; i++)
    {
        cout<<MAKELONG(MAKEWORD(RAND_ROUND(1, 0xFF), RAND_ROUND(0, 0xFF)), (MAKEWORD(RAND_ROUND(1, 0xFF), 0)))<<"\r\n";
    }

    CRITICAL_SECTION testLock;
    DWORD dwLockError = GetLastError();
    InitializeCriticalSection(&testLock);
    dwLockError = GetLastError();
    EnterCriticalSection(&testLock);
    dwLockError = GetLastError();
    LeaveCriticalSection(&testLock);
    dwLockError = GetLastError();
    LeaveCriticalSection(&testLock);
    dwLockError = GetLastError();


    long lMagicCode = MAGIC_CODE;
    char * pszMagicCode = MAGIC_TEXT;
    long lReinterpretMagicCode = (long)(*((long *)pszMagicCode));

    typedef map<long, LPRECT> RectMap;
    RectMap rectMap;
    auto findIter = find_if(rectMap.begin(), rectMap.end(), [](pair<long, LPRECT>  iterPair){
        return (iterPair.second->bottom == 10);
    });

    TestHYRealPlay();

    system("pause");
    TestHYRequest();
    TestHYLogout();
    Sleep(1000 * 10);
    TestHYReLogin();
    cout<<"第一次登录ID "<<g_hyOldUserID<<";第二次登录ID "<<g_hyUserID<<endl;
    Sleep(1000 * 10);
    TestHYStopPlay();*/
    system("pause");

	return 0;
}

#pragma warning(pop)