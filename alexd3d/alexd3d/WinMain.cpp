#include<Windows.h>
#include<string>

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	//get lpszClassName
	std::string s = "alexd3d";
	std::wstring stemp(s.begin(), s.end());
	LPCWSTR pClassName = stemp.c_str();
	//register window class
	WNDCLASSEXW wc = { 0 };
	//wc. = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = DefWindowProc;
	wc.cbSize = sizeof( wc );
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	RegisterClassEx( &wc );
	


	//get windowname
	std::string s2 = "Happy hard Window";
	std::wstring stemp2(s2.begin(), s2.end());
	LPCWSTR pWndName = stemp2.c_str();
	//create window
	HWND hwnd = CreateWindowExW(
		0, pClassName,
		pWndName,
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr
	);

	//show window
	ShowWindow(hwnd , SW_SHOW);
	while (true);
	return 0;
}