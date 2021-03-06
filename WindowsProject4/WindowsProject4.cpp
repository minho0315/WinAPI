﻿// WindowsProject4.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WindowsProject4.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
//ATOM                MyRegisterClass(HINSTANCE hInstance);
//BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

#include <time.h>
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, // 응용프로그램의 고유 아이디
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow) // 윈도우의 초기 상태 지정
{
	srand((unsigned)time(NULL));
	//UNREFERENCED_PARAMETER(hPrevInstance);
	//UNREFERENCED_PARAMETER(lpCmdLine);
	// TODO: 여기에 코드를 입력합니다.
	//int num;
	// 전역 문자열을 초기화합니다.
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WINDOWSPROJECT4, szWindowClass, MAX_LOADSTRING);

	/*struct ST {
		int size;
		int a;
		int b;
	};
	ST st;
	st.size = sizeof(ST);*/

	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc; // 메시지 프로시져 함수 설정
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance; // 
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT4));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = CreateSolidBrush(RGB(0xff, 0x00, 0x80));  // (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT4);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	RegisterClassExW(&wcex);

	//여기부터
	hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

	HWND hWnd = CreateWindowW(
		szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		100, 200,
		800, 600,
		nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
		return FALSE;

	ShowWindow(hWnd, SW_SHOWDEFAULT); //SW_SHOWDEFAULT
	UpdateWindow(hWnd);

	//InitData();

	//HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT4));

	MSG msg;

	// 기본 메시지 루프입니다:
	bool done = FALSE;
	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				done = TRUE;
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else {
			// 변수 갱신만 전문적으로 하는 함수
			// 드로링(렌더링)과 관련된 함수
			//invalidateRect();

		   /* WCHAR Str[32];
			static int ct = 0;
			wsprintf(Str, TEXT("Real Time : %d\n"), ct++);
			OutputDebugString(Str);*/

		}
	}
	return (int)msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
//ATOM MyRegisterClass(HINSTANCE hInstance)
//{
//
//}

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
//BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
//{
//   
//}

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
HWND hBtn1,hBtn2,hBtn3;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{ // 1. 윈도우 생성 2. 메세지 처리 
	case WM_CREATE:
		//MessageBox(hWnd, TEXT("WM_CREATE"), TEXT("WM_CREATE"), MB_OK);
	{
		hBtn1 = CreateWindowW(
			TEXT("BUTTON"),                    //예약단어
			TEXT("호랑이1"),                     // 버튼에 나타나는 텍스트 설정
			WS_VISIBLE | WS_CHILD | WS_BORDER, // 윈도우의 스타일 설정
			0, 0,                            //위치 설정
			100, 50,                           // 버튼의 크기 설정
			hWnd,                               // 부모 윈도우 등록
			(HMENU)1000,                        // 버튼의 식별번호
			hInst,                              // 인스턴스 전달
			NULL);      // 

		hBtn2 = CreateWindowW(
			TEXT("BUTTON"), TEXT("호랑이2"),
			WS_VISIBLE | WS_CHILD | WS_BORDER,
			0, 50, 100, 50,
			hWnd, (HMENU)2000, hInst, NULL);

		hBtn3 = CreateWindowW(
			TEXT("BUTTON"), TEXT("호랑이3"),
			WS_VISIBLE | WS_CHILD | WS_BORDER,
			0, 100, 100, 50,
			hWnd, (HMENU)3000, hInst, NULL);

	}
	break;

	case WM_LBUTTONDOWN:
	{
		MessageBox(hWnd, TEXT("Hello"), TEXT("캡션"), MB_OK);
	}
	break;
	case WM_TIMER:
	{
		switch (wParam) 
		{
		case 123:
		{
			WCHAR Str[32];
			static int ct = 0;
			wsprintf(Str, TEXT("1번타이머:%d\n"), rand()%100 );
			OutputDebugString(Str);
		}
		break;
		case 456:
		{
			WCHAR Str[32];
			static int ct = 0;
			wsprintf(Str, TEXT("2번타이머:%d\n"), ct++);
			OutputDebugString(Str);
		}
		break;
		}
	}
		break;
	case WM_COMMAND:
	{
		switch (wParam)
		{
		case 1000:
		{
			// 1초는 1000ms
					// WM_TIMER
			HANDLE hTimer = (HANDLE)SetTimer(hWnd, 123, 500, NULL);
			//ShowWindow(hBtn3, false);
			//EnableWindow(hBtn3, false);
			//SetWindowText(hBtn3, TEXT("고양이"));
			//MessageBox(hWnd, TEXT("id 1000"), TEXT("캡션"), MB_OK);
		}
			break;
		case 2000:
		{
			HANDLE hTimer = (HANDLE)SetTimer(hWnd, 456, 800, NULL);
			//KillTimer(hWnd, 123);
			//ShowWindow(hBtn3, true);
			//EnableWindow(hBtn3, true);
			//SetWindowText(hBtn3, TEXT("독수리"));
			//MessageBox(hWnd, TEXT("id 2000"), TEXT("캡션"), MB_OK);
		}
			break;
		case 3000:
		{
			KillTimer(hWnd, 123);
			KillTimer(hWnd, 456);
		}
		break;
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		EndPaint(hWnd, &ps);
	}
	break;

	case WM_DESTROY:
		//MessageBox(hWnd, TEXT("WM_DESTROY"), TEXT("WM_DESTROY"), MB_OK);
		// WM_QUIT
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
