#include"Game.h"
#include <time.h>

const TCHAR szWndClassName[] = "WindowClass";
const TCHAR szTitle[] = "Arkanoid";

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int LenCmd)
{
	WNDCLASSEX wndClass;
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.lpfnWndProc = WndProc;
	wndClass.style = CS_VREDRAW | CS_HREDRAW;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = szWndClassName;
	wndClass.hIconSm = LoadIcon(wndClass.hInstance, IDI_APPLICATION);

	if (!RegisterClassEx(&wndClass))
	{
		MessageBox(NULL, "Falled registering class", "Arkanoid:Error", MB_OK);
		return -1;
	}

	HWND hWnd = CreateWindow(
		szWndClassName,
		szTitle,
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
		CW_USEDEFAULT, CW_USEDEFAULT,
		900, 600,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hWnd)
	{
		MessageBox(NULL,
			("Call to CreateWindow failed!"),
			("Windows Desktop Guided Tour"),
			NULL);

		return 1;
	}

	ShowWindow(hWnd, LenCmd);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

#define FWIDTH 595
#define FHEIGHT 460

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	static Game game;
	static int wheelDelta = 0;
	const unsigned int MYTIMER = 1;
	switch (uMsg)
	{
	case WM_CREATE:

		break;
	case WM_PAINT:
		GetClientRect(hWnd, &rect);
		hdc = BeginPaint(hWnd, &ps);

		LOGBRUSH br;
		br.lbStyle = BS_SOLID;
		br.lbColor = 0x000000;

		HBRUSH brush;
		brush = CreateBrushIndirect(&br);
		FillRect(hdc, &rect, brush);
		DeleteObject(brush);

		switch (game.Status())
		{
		case MENU:
			game.Menu(hWnd, hdc, rect);
			break;
		case PAUSE:
			game.Pause(hdc, rect);
			break;
		case PLAING:
			game.drawPlaingProcess(hdc, rect);
			break;
		case RESULTS:
			//game.Result(hdc, rect);
			break;
		default:
			EndPaint(hWnd, &ps);
			break;
		}
		break;
	case WM_KEYDOWN:
		int keyPressed;
		keyPressed = (int)wParam;
		GetClientRect(hWnd, &rect);
		switch (keyPressed)
		{
		case VK_LEFT:

			break;
		case VK_RIGHT:

			break;
		case VK_RETURN:
			if (game.Status() == MENU)
				game.setStatus(PLAING);
			break;
		case VK_SPACE:
			if (game.Status() == PLAING)
				game.setStatus(PAUSE);
				//stop timer...
			else {
				if (game.Status() == PAUSE)
					game.setStatus(PLAING);
			}
			break;
		case VK_ESCAPE:

			break;
		default:
			break;
		}
		InvalidateRect(hWnd, NULL, FALSE);
		break;
	case WM_MOUSEWHEEL:
		GetClientRect(hWnd, &rect);
		wheelDelta += GET_WHEEL_DELTA_WPARAM(wParam);

		for (; wheelDelta > WHEEL_DELTA; wheelDelta -= WHEEL_DELTA)
			//	MoveLeft(step);
			;
		for (; wheelDelta < 0; wheelDelta += WHEEL_DELTA)
			//MoveRight(rect.right, bm.bmWidth, step);
			;

		InvalidateRect(hWnd, NULL, FALSE);
		break;
	case WM_ERASEBKGND:
		return 1;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
		break;
	}
}