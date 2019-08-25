// Project1.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Project1.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_DESTROY) {
		PostQuitMessage(0);
	}
	else if (uMsg == WM_LBUTTONDOWN) {
		HWND h_find_wnd = NULL;
		while (h_find_wnd = FindWindowEx(NULL, h_find_wnd, L"#32770", NULL)) {
			HWND h_edit_wnd = FindWindowEx(h_find_wnd, NULL, L"RichEdit20W", NULL);
			if (h_edit_wnd != NULL) {
				SendMessage(h_edit_wnd, WM_SETTEXT, 0, (LPARAM)L"안녕하세요");
				// SendMessage는 동기식으로 메시지를 즉각 처리
				Sleep(200);		// 너무빨리 엔터를 치면 딜레이를 넣음
				PostMessage(h_edit_wnd, WM_KEYDOWN, 0x0000000D, 0x001C001);	// 엔터키를 누름
				PostMessage(h_edit_wnd, WM_KEYDOWN, 0x0000000D, 0xC01C001);	// 엔터키를 누름
				// PostMessage는 메시지 큐에 메시지를 넣는다.(안전)
				break;
			}
		}
	}
		
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS wc;

	wchar_t my_class_name[] = L"tipssoft";

	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = my_class_name;
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wc);

	HWND hWnd = CreateWindow(my_class_name, L"www.tipssoft.com",
		WS_OVERLAPPEDWINDOW, 100, 90, 400, 350, NULL, NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}