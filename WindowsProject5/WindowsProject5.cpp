// WindowsProject5.cpp : 애플리케이션에 대한 진입점을 정의합니다.
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
	if (!InitInstance(hInstance, nCmdShow))
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

	return (int)msg.wParam;
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

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT5));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT5);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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

	struct STRU {
		long* p;
	};

	STRU* st;
	st = new STRU;
	st->p = new long;

	delete st->p;
	delete st;

	case WM_PAINT:
	{
		//void func01() {

		//}
		//// 1. 주소가 리턴 된다.
		//void* func02() {
		//	return 
		//}

		//int* func03() {
		//	return
		//}

		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		

		//#define NUM 100
		//POINT pts[NUM + 1] = { 0 };
		//scanf();

		int NUM = 80;
		POINT* pts = new POINT[NUM+1];
		float PosX = 400, PosY = 280, w = 100.0f;

		for (int i = -(NUM / 2); i <= +(NUM / 2); ++i) // 수정되어야 한다.
		{
			// 수정
			pts[i + NUM / 2].x = i * (600.0f / NUM) + PosX;
			pts[i + NUM / 2].y = sinf(DegreeToRadian(i * (360.0f / NUM))) * w + PosY;
		}

		Polyline(hdc, pts, NUM + 1);

		delete[] pts;

		// 5단계
		//#define NUM 100
		//POINT pts[NUM+1] = { 0 };
		//float PosX = 400, PosY = 280, w = 100.0f;

		//for (int i = -(NUM/2); i <= +(NUM / 2); ++i) // 수정되어야 한다.
		//{
		//	// 수정
		//	pts[i + NUM/2].x = i * (600.0f/NUM) + PosX;
		//	pts[i + NUM/2].y = sinf(DegreeToRadian(i *(360.0f/NUM))) * w + PosY;
		//}

		//Polyline(hdc, pts, NUM+1);

		// 4단계
		//POINT pts[23] = { 0 };
		//float PosX = 400, PosY = 300, w = 60.0f;

		//for (int i = -11; i <= 11; ++i) // 수정되어야 한다.
		//{
		//	// 수정
		//	pts[i + 11].x = i * 20 + PosX;
		//	pts[i + 11].y = sinf(DegreeToRadian(i *(360.0f/22))) * w + PosY;
		//}

		//Polyline(hdc, pts, 23);

		//3단계
		/*point pts[13] = { 0 };

		float posx = 400, posy = 300, w = 60.0f;

		for (int i = -6; i <= 6; ++i)
		{
			pts[i+6].x = i*20 + posx; 
			pts[i+6].y = sinf(degreetoradian(i*30.0f)) * w + posy;
		}

		polyline(hdc, pts, 13);*/
		
		//// 2단계
		//POINT pts[13] = { 0 };
		//
		//float PosX = 400, PosY = 300, w = 60.0f;

		//pts[0].x = -60 + PosX; pts[0].y = sinf(DegreeToRadian(-180.0f)) * w + PosY;
		//pts[1].x = -50 + PosX; pts[1].y = sinf(DegreeToRadian(-150.0f)) * w + PosY;
		//pts[2].x = -40 + PosX; pts[2].y = sinf(DegreeToRadian(-120.0f)) * w + PosY;
		//pts[3].x = -30 + PosX; pts[3].y = sinf(DegreeToRadian(-90.0f)) * w + PosY;
		//pts[4].x = -20 + PosX; pts[4].y = sinf(DegreeToRadian(-60.0f)) * w + PosY;
		//pts[5].x = -10 + PosX; pts[5].y = sinf(DegreeToRadian(-30.0f)) * w + PosY;
		//pts[6].x = 0 + PosX; pts[6].y = sinf(DegreeToRadian(0.0f)) * w + PosY;
		//pts[7].x = 10 + PosX; pts[7].y = sinf(DegreeToRadian(30.0f)) * w + PosY;
		//pts[8].x = 20 + PosX; pts[8].y = sinf(DegreeToRadian(60.0f)) * w + PosY;
		//pts[9].x = 30 + PosX; pts[9].y = sinf(DegreeToRadian(90.0f)) * w + PosY;
		//pts[10].x = 40 + PosX; pts[10].y = sinf(DegreeToRadian(120.0f)) * w + PosY;
		//pts[11].x = 50 + PosX; pts[11].y = sinf(DegreeToRadian(150.0f)) * w + PosY;
		//pts[12].x = 60 + PosX; pts[12].y = sinf(DegreeToRadian(180.0f)) * w + PosY;

		//Polyline(hdc, pts, 13);
		//// 1단계
		//POINT pts[13] = {0};

		//Polyline(hdc, pts, 13);

		///////////////////////////////////////////////////////////////////////
		/*POINT pts[] = { {0,0} };

		for (int i = 0; i < 60; i++)
			pts[i] = { 6*i,sinf(DegreeToRadian(6.0f)) };

		Polyline(hdc, pts, 60);*/

		/*POINT pts[] = {
			{60,10},{160,10},{210,60},{210,160},{160,210},
			{60,210},{10,160},{10,60},{60,10}
		};
		Polyline(hdc, pts, 9);*/

		/*HPEN MyPen, OldPen;
		MyPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
		OldPen = (HPEN)SelectObject(hdc, MyPen);

		HBRUSH MyBrush, OldBrush;
		MyBrush = CreateSolidBrush(RGB(255, 255, 0));
		OldBrush = (HBRUSH)SelectObject(hdc, MyBrush);

		Rectangle(hdc, 100, 200, 300, 400);

		SelectObject(hdc, OldPen);
		DeleteObject(MyPen);

		SelectObject(hdc, OldBrush);
		DeleteObject(MyBrush);*/

		/* PAINTSTRUCT ps;
		 HDC hdc = BeginPaint(hWnd, &ps);

		 HPEN MyPen, OldPen;
		 MyPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
		 OldPen = (HPEN)SelectObject(hdc, MyPen);

		 MoveToEx(hdc, 10, 10, NULL);
		 LineTo(hdc, 200, 400);

		 SelectObject(hdc, OldPen);
		 DeleteObject(MyPen);*/

		 /* Rectangle(hdc, 100, 100, 200, 300);
		  Ellipse(hdc, 100, 100, 200, 300);
		  Ellipse(hdc, 200, 200, 700, 500);*/

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
