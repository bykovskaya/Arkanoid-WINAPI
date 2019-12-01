#include "Game.h"

const wchar_t menuText[] = L"Press ENTER to start the game";

Game::Game() : inGame(false) {};

int Game::showMenu(HWND hWnd, HDC hdc, RECT rect)
{
	BITMAP bm;
	HDC hCmpDC = CreateCompatibleDC(hdc);
	HANDLE hBitMap = LoadImage(NULL, "pngguru.jpg", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	if (!hBitMap)
	{
		MessageBox(hWnd, "File is not found.", "Error", MB_OK);
		return 0;
	}

	GetObject(hBitMap, sizeof(BITMAP), &bm);
	SetStretchBltMode(hdc, COLORONCOLOR);
	SelectObject(hCmpDC, hBitMap);
	BitBlt(hdc, (rect.right - rect.left) / 2 - bm.bmWidth / 2, bm.bmHeight, bm.bmWidth, bm.bmHeight, hCmpDC, 0, 0, SRCCOPY);

	HFONT hFont;
	hFont = CreateFont(20, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, VARIABLE_PITCH, "Pica");
	SetTextColor(hdc, 0xffffff);
	SetBkMode(hdc, TRANSPARENT);
	SelectObject(hdc, hFont);
	
	TextOut(hdc, 240, 350, (LPCSTR)menuText, sizeof(menuText));

	DeleteObject(hCmpDC);
	DeleteObject(hBitMap);
	hCmpDC = NULL;

}