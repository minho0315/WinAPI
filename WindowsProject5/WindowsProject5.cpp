﻿// WindowsProject5.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WindowsProject5.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT5, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT5));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT5));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT5);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      400, 200, 800, 600, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
#include <math.h>
#define _PI_ 3.141592f
float DegreeToRadian(float degree) {
    return _PI_ * degree / 180.0f;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            Rectangle(hdc, 100, 100, 200, 300);
            Ellipse(hdc, 100, 100, 200, 300);
            Ellipse(hdc, 200, 200, 700, 500);

            ////응용
            //RECT rt;
            //GetClientRect(hWnd, &rt);
            //float PosX = rt.right / 2.0f, PosY = rt.bottom / 2.0f;
            //MoveToEx(hdc,
            //    200.0f * cosf(DegreeToRadian(0.0f)) + PosX,
            //    200.0f * sinf(DegreeToRadian(0.0f)) + PosY,
            //    NULL);
            //int lineNum = 32;
            //for (size_t i = 1; i <= lineNum; i++)
            //{
            //    LineTo(hdc,
            //        200.0f * cosf(DegreeToRadian(360.0f / lineNum * i)) + PosX,
            //        200.0f * sinf(DegreeToRadian(360.0f/ lineNum * i)) + PosY);
            //}

            ////응용 : 정육면체 그리기
            //RECT rt;
            //GetClientRect(hWnd, &rt);
            //float PosX = rt.right / 2.0f, PosY = rt.bottom / 2.0f;
            //MoveToEx(hdc,
            //    200.0f * cosf(DegreeToRadian(0.0f)) + PosX,
            //    200.0f * sinf(DegreeToRadian(0.0f)) + PosY,
            //    NULL);

            //for (size_t i = 1; i <= 6; i++)
            //{
            //    LineTo(hdc,
            //        200.0f * cosf(DegreeToRadian(60.0f * i)) + PosX,
            //        200.0f * sinf(DegreeToRadian(60.0f * i)) + PosY);
            //}

           // // 화면 중앙 센터에 정 삼각형을 그린다.
           //// 원의 반지름 200 픽셀이라고 한다.
           // RECT rt;
           // GetClientRect(hWnd, &rt);
           // float PosX = rt.right / 2.0f, PosY = rt.bottom / 2.0f;
           // MoveToEx(hdc,
           //     200.0f * cosf(DegreeToRadian(90.0f)) + PosX,
           //     200.0f * sinf(DegreeToRadian(90.0f)) + PosY,
           //     NULL);
           // for (size_t i = 1; i <= 3; i++)
           // {
           //     LineTo(hdc,
           //         200.0f * cosf(DegreeToRadian(90.0f + 120.0f * i)) + PosX,
           //         200.0f * sinf(DegreeToRadian(90.0f + 120.0f * i)) + PosY);
           // }

           /* LineTo(hdc,
                200.0f * cosf(DegreeToRadian(90.0f+120.0f*1)) + PosX,
                200.0f * sinf(DegreeToRadian(90.0f+120.0f*1)) + PosY);
            LineTo(hdc,
                200.0f * cosf(DegreeToRadian(90.0f + 120.0f*2)) + PosX,
                200.0f * sinf(DegreeToRadian(90.0f + 120.0f*2)) + PosY);
            LineTo(hdc,
                200.0f * cosf(DegreeToRadian(90.0f + 120.0f * 3)) + PosX,
                200.0f * sinf(DegreeToRadian(90.0f + 120.0f * 3)) + PosY);*/
            //MoveToEx(hdc, 200, 200, NULL);
           // LineTo(hdc, 200 * cosf(DegreeToRadian(60.0f)) + 200, 200 * sinf(DegreeToRadian(30.0f)) + 200);
           // LineTo(hdc, 200 * cosf(DegreeToRadian(60.0f)) + 200, 200 * sinf(DegreeToRadian(30.0f)) + 200);
            //LineTo(hdc, 200*cosf(DegreeToRadian(60.0f)) + 200, 200*sinf(DegreeToRadian(30.0f))+200);
            //LineTo(hdc, cosf(DegreeToRadian(120.0f)) * 200+400, sinf(DegreeToRadian(120.0f))*200+300);
            //LineTo(hdc, cosf(DegreeToRadian(120.0f)) * 200+400, sinf(DegreeToRadian(120.0f))*200+300);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}