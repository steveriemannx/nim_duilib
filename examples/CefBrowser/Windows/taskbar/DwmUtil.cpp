#include "DwmUtil.h"

#if defined (DUILIB_BUILD_FOR_WIN) && !defined (DUILIB_BUILD_FOR_SDL)

HRESULT DwmSetIconicThumbnail(HWND hwnd, HBITMAP hbmp, DWORD dwSITFlags)
{
    typedef HRESULT(WINAPI *LPSetProcessDPIAware)(HWND hwnd, HBITMAP hbmp, DWORD dwSITFlags);
    static LPSetProcessDPIAware pDwmSetIconicThumbnail = nullptr;
    if (pDwmSetIconicThumbnail) {
        return pDwmSetIconicThumbnail(hwnd, hbmp, dwSITFlags);
    }
    else {
        HMODULE hModule = ::LoadLibrary(_T("dwmapi.dll"));
        if (nullptr != hModule) {
            pDwmSetIconicThumbnail = (LPSetProcessDPIAware)GetProcAddress(hModule, "DwmSetIconicThumbnail");
            if (pDwmSetIconicThumbnail) {
                return pDwmSetIconicThumbnail(hwnd, hbmp, dwSITFlags);
            }
            ::FreeLibrary(hModule);
        }
    }

    return S_FALSE;
}

HRESULT DwmSetIconicLivePreviewBitmap(HWND hwnd, HBITMAP hbmp, POINT *pptClient, DWORD dwSITFlags)
{
    typedef HRESULT(WINAPI *LPDwmSetIconicLivePreviewBitmap)(HWND hwnd, HBITMAP hbmp, POINT *pptClient, DWORD dwSITFlags);
    static LPDwmSetIconicLivePreviewBitmap pDwmSetIconicLivePreviewBitmap = nullptr;
    if (pDwmSetIconicLivePreviewBitmap) {
        return pDwmSetIconicLivePreviewBitmap(hwnd, hbmp, pptClient, dwSITFlags);
    }
    else {
        HMODULE hModule = ::LoadLibrary(_T("dwmapi.dll"));
        if (nullptr != hModule) {
            pDwmSetIconicLivePreviewBitmap = (LPDwmSetIconicLivePreviewBitmap)GetProcAddress(hModule, "DwmSetIconicLivePreviewBitmap");
            if (pDwmSetIconicLivePreviewBitmap) {
                return pDwmSetIconicLivePreviewBitmap(hwnd, hbmp, pptClient, dwSITFlags);
            }
            ::FreeLibrary(hModule);
        }
    }

    return S_FALSE;
}

HRESULT DwmInvalidateIconicBitmaps(HWND hwnd)
{
    typedef HRESULT(WINAPI *LPDwmInvalidateIconicBitmaps)(HWND hwnd);
    static LPDwmInvalidateIconicBitmaps pDwmInvalidateIconicBitmaps = nullptr;
    if (pDwmInvalidateIconicBitmaps) {
        return pDwmInvalidateIconicBitmaps(hwnd);
    }
    else {
        HMODULE hModule = ::LoadLibrary(_T("dwmapi.dll"));
        if (nullptr != hModule) {
            pDwmInvalidateIconicBitmaps = (LPDwmInvalidateIconicBitmaps)GetProcAddress(hModule, "DwmInvalidateIconicBitmaps");
            if (pDwmInvalidateIconicBitmaps) {
                return pDwmInvalidateIconicBitmaps(hwnd);
            }
            ::FreeLibrary(hModule);
        }
    }

    return S_FALSE;
}

HRESULT DwmSetWindowAttribute(HWND hwnd, DWORD dwAttribute, LPCVOID pvAttribute, DWORD cbAttribute)
{
    typedef HRESULT(WINAPI *LPDwmSetWindowAttribute)(HWND hwnd, DWORD dwAttribute, LPCVOID pvAttribute, DWORD cbAttribute);
    static LPDwmSetWindowAttribute pDwmSetWindowAttribute = nullptr;
    if (pDwmSetWindowAttribute) {
        return pDwmSetWindowAttribute(hwnd, dwAttribute, pvAttribute, cbAttribute);
    }
    else {
        HMODULE hModule = ::LoadLibrary(_T("dwmapi.dll"));
        if (nullptr != hModule) {
            pDwmSetWindowAttribute = (LPDwmSetWindowAttribute)GetProcAddress(hModule, "DwmSetWindowAttribute");
            if (pDwmSetWindowAttribute) {
                HRESULT hr = pDwmSetWindowAttribute(hwnd, dwAttribute, pvAttribute, cbAttribute);
                return hr;
            }
            ::FreeLibrary(hModule);
        }
    }

    return S_FALSE;
}

#endif //defined (DUILIB_BUILD_FOR_WIN) && !defined (DUILIB_BUILD_FOR_SDL)
