#include"System.h"
#include<windows.h>
#include<Winuser.h>
#include"resource.h"
#include<string>
using std::string;
System ST;
HINSTANCE hInst;
LRESULT CALLBACK WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK DlgProc2(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK DlgProc3(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK DlgProc4(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow)
{

	WNDCLASS wc;
	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_PEN);
	wc.hCursor = NULL;
	wc.hIcon = NULL;
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WinProc;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = TEXT("信息管理系统");
	wc.style = CS_VREDRAW | CS_HREDRAW;
	RegisterClass(&wc);//实现注册窗口
	HWND hwnd = CreateWindow(wc.lpszClassName,TEXT("学生信息管理系统"), WS_OVERLAPPEDWINDOW, 400, 100, 600, 500, NULL, NULL, hInstance, NULL);//创建窗口
	ShowWindow(hwnd, iCmdShow);//显示窗口
	UpdateWindow(hwnd);
	
	MSG msg;
	while(GetMessage(&msg, 0, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
	
}

LRESULT CALLBACK WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	switch (uMsg)
	{

	case WM_CREATE:
	{
		HWND button1 = CreateWindow(TEXT("button"), TEXT("添加"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 100, 60, 60, 45, hwnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		HWND button2 = CreateWindow(TEXT("button"), TEXT("删除"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 200, 60, 60, 45, hwnd, (HMENU)2, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		HWND button3 = CreateWindow(TEXT("button"), TEXT("排序"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 300, 60, 60, 45, hwnd, (HMENU)3, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		HWND button4 = CreateWindow(TEXT("button"), TEXT("查找"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 400, 60, 60, 45, hwnd, (HMENU)4, ((LPCREATESTRUCT)lParam)->hInstance, NULL);

	}	
	return 0; 

	case WM_COMMAND:

	 switch (LOWORD(wParam))
		{
	    case 1:DialogBox(hInst, MAKEINTRESOURCE(101), hwnd, DlgProc); break;
		case 2:DialogBox(hInst, MAKEINTRESOURCE(102), hwnd, DlgProc2); break;
		case 3:DialogBox(hInst, MAKEINTRESOURCE(103), hwnd, DlgProc3); break;
		case 4:DialogBox(hInst, MAKEINTRESOURCE(105), hwnd, DlgProc4); break;
		}
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}
INT_PTR CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	
	//wchar_t *IpString= GetDlgItem(hWnd, IDC_EDIT1);

	switch (uMsg)
	{
	case WM_INITDIALOG:
		return TRUE;
	
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:EndDialog(hWnd, 0); 
			//GetDlgItemText(hWnd, IDC_EDIT1, IpString, 20);
			ST.Add("iiiii" ,GetDlgItemInt(hWnd, IDC_EDIT3, NULL, TRUE), GetDlgItemInt(hWnd, IDC_EDIT4, NULL, TRUE));
			return TRUE;
		case IDCANCEL:EndDialog(hWnd, 0); return TRUE;
		}
		return TRUE;
	}
return FALSE;
}
INT_PTR CALLBACK DlgProc2(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:

		return TRUE;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:EndDialog(hWnd, 0); ST.Delete(GetDlgItemInt(hWnd, IDC_EDIT1, NULL, TRUE)); return TRUE;
		case IDCANCEL:EndDialog(hWnd, 0); return TRUE;
		}
		return TRUE;

	}return FALSE;
}
INT_PTR CALLBACK DlgProc3(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:

		return TRUE;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON1:ST.Sort(0); break;
		case IDC_BUTTON2:ST.Sort(1); break;
		}
		EndDialog(hWnd, 0); 
		return TRUE;
	}return FALSE;
}
INT_PTR CALLBACK DlgProc4(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:

		return TRUE;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:ST.Search(GetDlgItemText(hWnd, IDC_EDIT1, NULL, 10)); EndDialog(hWnd, 0); return TRUE;
		case IDCANCEL:EndDialog(hWnd, 0); return TRUE;
		}
		return TRUE;
	}return FALSE;
}