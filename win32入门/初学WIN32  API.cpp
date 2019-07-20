#include<windows.h>

LRESULT CALLBACK WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	WNDCLASS cs;
	static TCHAR name[] = TEXT("��������");
	cs.cbClsExtra = 0;
	cs.cbWndExtra = 0;
	cs.hbrBackground = (HBRUSH)GetStockObject(WHITE_PEN);
	cs.hCursor = NULL;
	cs.hIcon = NULL;
	cs.hInstance = hInstance;
	cs.lpfnWndProc = (WNDPROC)WinProc;
	cs.lpszClassName =name;
	cs.lpszMenuName = NULL;
	cs.style = CS_VREDRAW | CS_HREDRAW;
	RegisterClass(&cs);//ʵ��ע�ᴰ��
	HWND hWnd = CreateWindow(name, TEXT("������"), WS_OVERLAPPEDWINDOW, 500, 100, 400, 520, NULL, NULL, hInstance, NULL);
	//��ʾ����
	ShowWindow(hWnd, iCmdShow);
	UpdateWindow(hWnd);
	MSG nMsg;
	while (GetMessage(&nMsg, 0, NULL, NULL))
	{
		TranslateMessage(&nMsg);
		DispatchMessage(&nMsg);
	}
	return 0;
}

LRESULT CALLBACK WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	TCHAR text[128];
	switch (uMsg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		MoveToEx(hdc,20,100,NULL);
		LineTo(hdc,20,200);
		LineTo(hdc, 300, 200);
		LineTo(hdc, 500, 300);
		EndPaint(hwnd, &ps);
		return 0;

	case WM_LBUTTONUP:
		MessageBox(hwnd, TEXT("������һ��"), TEXT("��ʾ"), MB_OK);
		return 0;

	/*case WM_CLOSE:
		if (MessageBox(hwnd, TEXT("�Ƿ�Ҫ��Ĺر���"), TEXT("��ȷ��"), MB_YESNO) == IDYES)
			DestroyWindow(hwnd);
		else
			return 0;*/

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
	
}
	
