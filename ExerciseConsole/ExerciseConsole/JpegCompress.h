#ifndef JPEG_COMPRESS_HEAD_FILE
#define JPEG_COMPRESS_HEAD_FILE

#pragma once

#include "stdafx.h"
#include "JpgPress.h"
#include <GdiPlus.h>
#include <sys/stat.h>

#pragma comment(lib, "Gdiplus.lib")

using namespace Gdiplus;

class CJpegCompress
{
private:
    FJpgCompress        m_pfnJpgCompress;
    HINSTANCE           m_hInstance;

private:
    ULONG_PTR           m_lToKen;

    static CJpegCompress g_Instance;

private:
    CJpegCompress()
    {
        GdiplusStartupInput startupInput;
        GdiplusStartup(&m_lToKen, &startupInput, NULL);


        m_hInstance = LoadLibrary(TEXT("JpgPress.dll"));
        if (NULL != m_hInstance)
        {
            m_pfnJpgCompress = (FJpgCompress) GetProcAddress(m_hInstance, "JpgCompress"); 
        }
    }

    ~CJpegCompress()
    {
        m_pfnJpgCompress = NULL;
        if (m_hInstance)
        {
            FreeLibrary(m_hInstance);
        }

        GdiplusShutdown(m_lToKen);
    }

public:
    static CJpegCompress & GetInstance() { return g_Instance; }

    bool Compress(const char* srcFile, const char* desFile, int pressQuality)
    {
        return m_pfnJpgCompress((char *) srcFile, (char *) desFile, pressQuality);
    }

    bool CompressEx(LPCWSTR lpszSrcFile, LPCWSTR lpszDesFile, int nQuality)
    {
        Image * image = new Image(lpszSrcFile);
        if (NULL == image)
        {
            return false;
        }

        UINT nWidth = image->GetWidth();
        UINT nHeight = image->GetHeight();
        if (1 > nWidth || 1 > nHeight)
        {
            return false;
        }

        EncoderParameters encoderParams;
        encoderParams.Count = 1;
        encoderParams.Parameter[0].Guid = Gdiplus::EncoderQuality;
        encoderParams.Parameter[0].Type = Gdiplus::EncoderParameterValueTypeLong;
        encoderParams.Parameter[0].NumberOfValues = 1;
        encoderParams.Parameter[0].Value = &nQuality;

        CLSID encoderClsID;
        if (false == GetEncoderClsid(L"image/png", &encoderClsID))
        {
            return false;
        }

        return (Gdiplus::Ok == image->Save(lpszDesFile, &encoderClsID, &encoderParams));
    }

    bool ResizePixelEx(LPCWSTR lpszSrcFile, LPCWSTR lpszDesFile, UINT nDesWidth, UINT nDesHeight)
    {
        ::std::unique_ptr<Image> pImage(new Image(lpszSrcFile));
        //Image * pImage = new Image(lpszSrcFile);
        if (NULL == pImage)
        {
            return false;
        }

        UINT nSrcWidth = pImage->GetWidth();
        UINT nSrcHeight = pImage->GetHeight();
        if (1 > nSrcWidth || 1 > nSrcHeight)
        {
            return false;
        }

        ::std::unique_ptr<Bitmap> pNewImage(new Bitmap(nDesWidth, nDesHeight));
        ::std::unique_ptr<Graphics> pGraphic(Graphics::FromImage(pNewImage.get()));
        //Bitmap * pNewImage = new Bitmap(nDesWidth, nDesHeight);
        //Graphics * pGraphic = Graphics::FromImage(pNewImage.get());
        if (NULL != pGraphic)
        {
            pGraphic->SetInterpolationMode(Gdiplus::InterpolationModeHighQuality);
            pGraphic->SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);

            Gdiplus::Rect rect(0, 0, nDesWidth, nDesHeight);
            pGraphic->DrawImage(pImage.get(), rect, 0, 0, nSrcWidth, nSrcHeight, Gdiplus::UnitPixel, NULL, NULL, NULL);

            CLSID encoderClsid;
            if (GetEncoderClsid(L"image/jpeg", &encoderClsid))
            {
                return (Gdiplus::Ok == pNewImage->Save(lpszDesFile, &encoderClsid));
            }
        }

        return false;
    }

    bool CompressToSpecifySize(LPCSTR lpszSrcFile, LPCSTR lpszDesFile, int nMaxFileSize, int nQuality)
    {
        if (m_pfnJpgCompress((char *) lpszSrcFile, (char *) lpszDesFile, nQuality))
        {
            struct _stat64i32 fileStatus = {0};

            if (0 == _stat64i32(lpszDesFile, &fileStatus))
            {
                if (nMaxFileSize < fileStatus.st_size && 5 < nQuality)
                {
                    DeleteFileA(lpszDesFile);
                    int nTempQuality = __max(5, nQuality - 10);
                    if (true == CompressToSpecifySize(lpszSrcFile, lpszDesFile, nMaxFileSize, nTempQuality))
                    {
                        return true;//(TRUE == MoveFileW(strTempFile.c_str(), lpszDesFile));
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return true;
                }
            }
        }

        DeleteFileA(lpszDesFile);

        return false;
    }

    bool CompressToSpecifySizeEx(LPCWSTR lpszSrcFile, LPCWSTR lpszDesFile, int nMaxFileSize, int nQuality)
    {
        Image * image = new Image(lpszSrcFile);
        if (NULL == image)
        {
            return false;
        }

        UINT nWidth = image->GetWidth();
        UINT nHeight = image->GetHeight();
        if (1 > nWidth || 1 > nHeight)
        {
            return false;
        }

        EncoderParameters encoderParams;
        encoderParams.Count = 1;
        encoderParams.Parameter[0].Guid = Gdiplus::EncoderQuality;
        encoderParams.Parameter[0].Type = Gdiplus::EncoderParameterValueTypeLong;
        encoderParams.Parameter[0].NumberOfValues = 1;
        encoderParams.Parameter[0].Value = &nQuality;

        CLSID encoderClsID;
        if (false == GetEncoderClsid(L"image/jpeg", &encoderClsID))
        {
            return false;
        }

        if (Gdiplus::Ok == image->Save(lpszDesFile, &encoderClsID, &encoderParams))
        {
            struct _stat64i32 fileStatus = {0};
            if (0 == _wstat(lpszDesFile, &fileStatus))
            {
                if (nMaxFileSize < fileStatus.st_size && 5 < nQuality)
                {
                    DeleteFileW(lpszDesFile);
                    //::std::wstring strTempFile = lpszDesFile;
                    //strTempFile += L".jpg";
                    int nTempQuality = __max(5, nQuality - 10);
                    if (true == CompressToSpecifySizeEx(lpszSrcFile, lpszDesFile, nMaxFileSize, nTempQuality))
                    {
                        return true;//(TRUE == MoveFileW(strTempFile.c_str(), lpszDesFile));
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return true;
                }
            }
        }

        DeleteFileW(lpszDesFile);

        return false;
    }

    bool GetEncoderClsid(LPCWSTR lpszFormat, CLSID * pClsid)
    {
        UINT nNum = 0;
        UINT nSize = 0;

        Gdiplus::Status retStatus = GetImageEncodersSize(&nNum, &nSize);

        if (0 == nSize || Gdiplus::Ok != retStatus)
        {
            return false;
        }

        ImageCodecInfo * pImageCodecInfo = (ImageCodecInfo *) new BYTE[nSize];

        if (NULL == pImageCodecInfo)
        {
            return false;
        }

        retStatus = GetImageEncoders(nNum, nSize, pImageCodecInfo);

        if (Gdiplus::Ok != retStatus)
        {
            return false;
        }

        for (int i = 0; i < nNum; i++)
        {
            if (0 == wcscmp(pImageCodecInfo[i].MimeType, lpszFormat))
            {
                *pClsid = pImageCodecInfo[i].Clsid;
                delete pImageCodecInfo;
                pImageCodecInfo = NULL;

                return true;
            }
        }

        delete pImageCodecInfo;
        pImageCodecInfo = NULL;

        return false;
    }
};

CJpegCompress CJpegCompress::g_Instance;

#endif