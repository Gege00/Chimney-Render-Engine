#include <Windows.h>


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
		
	case WM_CLOSE :
		PostQuitMessage(55);
		break;
	}
	return DefWindowProc(hWnd,msg, wParam,lParam);
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR	lpCmdLine, int nCmdShow) {

	const auto pClassName = "creWin";


	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = pClassName;

	RegisterClassEx(&wc);

	HWND hWnd = CreateWindowExA(
		0,
		pClassName,
		"Chimney Render Engine",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200,
		1024, 768,
		nullptr, nullptr, hInstance, nullptr
	);

	ShowWindow(hWnd, SW_SHOW);

	

	MSG msg;
	BOOL gResult;
	while (gResult=GetMessage(&msg,nullptr,0,0)>0) {
		
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	if (gResult == -1) {
		
		return -1;
	}
	
	return msg.wParam;


}