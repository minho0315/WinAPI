// WindowsProject3.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WindowsProject3.h"

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
    LoadStringW(hInstance, IDC_WINDOWSPROJECT3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    //HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT3));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        WCHAR Str[32];
        static int ct = 0;
        wsprintf(Str, TEXT("%d\n"), ct++);
        //OutputDebugString(Str); // F5, Output[Debug]

        //if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            // WM_CHAR 메세지를 발생시킨다.
            //TranslateMessage(&msg);
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT3);
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
      100, 200, 400, 300, nullptr, nullptr, hInstance, nullptr);

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
int mx, my;
int count = 0;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_KEYDOWN:
    {
        WCHAR Str[32];
        wsprintf(Str, TEXT("WM_KEYDOWN:%d\n"), count++);
        OutputDebugString(Str);
    }
    break;
    case WM_KEYUP:
    {
        WCHAR Str[32];
        wsprintf(Str, TEXT("WM_KEYUP:%d\n"), count++);
        OutputDebugString(Str);
    }
    break;
    case WM_CHAR:
    {
        WCHAR Str[32];
        wsprintf(Str, TEXT("WM_CHAR:%d\n"), count++);
        OutputDebugString(Str);
    }
    break;
    case WM_MOUSEMOVE:
    {
        int x = LOWORD(lParam);
        int y = HIWORD(lParam);

        WCHAR str[32];
        wsprintf(str, TEXT("%d %d\n"), x, y);
       // OutputDebugString(str);

        mx = x;
        my = y;
        // 프로그래머가 특정 메세지를 발생시킬 수가 있다.
        InvalidateRect(hWnd, NULL, TRUE);
    }

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

            /*RECT r;
            SIZE s;
            POINT p;*/

            HDC hdc = BeginPaint(hWnd, &ps);

            RECT rt;
            GetClientRect(hWnd, &rt);
            /*RECT rt2;
            GetWindowRect(hWnd, &rt2);*/
            WCHAR str[32] = TEXT("호랑이");

            //필기
            //                Unicode         범용타입
            //    char        wchar_t         TCHAR(WCHAR)
            //    char*       wchar_t*        LPTSTR
            //    const char* const wchar_t*  LPCTSTR

            ////필기
            // HWND 윈도우에 대한 핸들
            // HCUSOR 커서에 대한 핸들
            // HICON 아이콘에 대한 핸들
            // HMENU 메뉴에 대한 핸들
            // HDC 그래픽 디바이스에 대한 핸들

            int size = sizeof(str);
            ZeroMemory(str, sizeof(str));

            // strlen(), wcslen()
            int len = wcslen(str); 
            DrawText(hdc, str, wcslen(str), &rt, DT_LEFT);
            DrawText(hdc, str, wcslen(str), &rt, DT_CENTER);
            DrawText(hdc, str, wcslen(str), &rt, DT_RIGHT);

            DrawText(hdc, str, wcslen(str), &rt, DT_SINGLELINE | DT_VCENTER);
            DrawText(hdc, str, wcslen(str), &rt, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
            DrawText(hdc, str, wcslen(str), &rt, DT_SINGLELINE | DT_VCENTER | DT_RIGHT);

            DrawText(hdc, str, wcslen(str), &rt, DT_SINGLELINE | DT_BOTTOM);
            DrawText(hdc, str, wcslen(str), &rt, DT_SINGLELINE | DT_BOTTOM | DT_CENTER);
            DrawText(hdc, str, wcslen(str), &rt, DT_SINGLELINE | DT_BOTTOM | DT_RIGHT);

            wsprintf(str, TEXT("MouseX:%d MouseY:%d"), mx, my);
            TextOut(hdc, 100, 200, str, wcslen(str));
            TextOut(hdc, mx, my, str, wcslen(str));

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
