// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include <objbase.h>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
        {
            if (S_OK != CoInitialize(NULL))
            {
                return FALSE;
            }

            break;
        }
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
        break;
	case DLL_PROCESS_DETACH:
        {
            CoUninitialize();

            break;
        }
	}

	return TRUE;
}

