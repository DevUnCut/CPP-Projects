#ifndef MAIN_WIN_H
#define MAIN_WIN_H
#include "MainWindow.h"
#include "baseWin.h"
#include <d2d1.h>

template <class T> void SafeRelease(T** ppT)
{
    if (*ppT)
    {
        (*ppT)->Release();
        *ppT = NULL;
    }
}

class MainWindow : public BaseWindow<MainWindow>
{
    ID2D1Factory* pFactory;
    ID2D1HwndRenderTarget* pRenderTarget;
    ID2D1SolidColorBrush* pBrush;
    D2D1_ELLIPSE            ellipse;

    void    CalculateLayout();
    HRESULT CreateGraphicsResources();
    void    DiscardGraphicsResources();
    void    OnPaint();
    void    Resize();

public:

    MainWindow() : pFactory(NULL), pRenderTarget(NULL), pBrush(NULL) {
        // default construct
    }

    PCWSTR  ClassName() const {
        return L"Ellipse Window Class";
    }
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};
#endif