#include<Windows.h>
#include<string>
#include<fstream>
#include"WindowsMessageMap.h"


LPCWSTR str2LPCWSTR(std::string s) {
	std::wstring temp(s.begin(),s.end());
	return temp.c_str();
}


LRESULT CALLBACK WndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam) {

	static WindowsMessageMap mm;
	OutputDebugString(mm(msg,lParam,wParam).c_str());

	switch (msg) {
	case WM_CLOSE:
		PostQuitMessage(1023);
		break;
	case WM_KEYDOWN:
		if (wParam == 'F') {
			SetWindowText(hWnd,L"happy birthday to xu");
		}
	case WM_KEYUP:
		if (wParam == 'F') {
			SetWindowText(hWnd, L"sdf");
		}
		break;
	}
	return DefWindowProc(hWnd,msg,wParam,lParam);
}


int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	//register window class
	WNDCLASSEXW wc = { 0 };
	//wc. = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbSize = sizeof( wc );
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = L"alex3d";
	RegisterClassEx( &wc );
	


	//create window
	HWND hwnd = CreateWindowExW(
		0, L"alex3d",
		L"Happy hard Window",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr
	);

	//show window
	ShowWindow(hwnd , SW_SHOW);

	//message pump
	BOOL bRet;

	MSG msg;
	UINT temp = 0;
	int  k = 0;
	while ((bRet = GetMessage(&msg, nullptr, 0, 0)) != 0) {
		if (bRet == -1) {
			//error
		}
		else {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			k = 1;
		}
	}
	return msg.wParam;
}