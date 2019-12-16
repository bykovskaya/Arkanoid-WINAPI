#include "Game.h"
#include"common.h"

const wchar_t menuText[] = L"Press ENTER to start the game";
const wchar_t pauseText[] = L"PAUSE";


Game::Game() : state(MENU)
{

};

void Game::Menu(HWND hWnd, HDC hdc, RECT rect)
{
	BITMAP bm;
	HDC hCmpDC = CreateCompatibleDC(hdc);
	HANDLE hBitMap = LoadImage(NULL, "pngguru.jpg", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

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

	DeleteObject(hFont);
	DeleteObject(hCmpDC);
	DeleteObject(hBitMap);
	hCmpDC = NULL;

}
void Game::Pause(HDC hdc, RECT rect)
{
	HFONT hFont;
	static TEXTMETRIC tm;
	hFont = CreateFont(20, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, VARIABLE_PITCH, "Pica");
	GetTextMetrics(hdc, &tm);
	SetTextColor(hdc, 0xffffff);
	SetBkMode(hdc, TRANSPARENT);
	SelectObject(hdc, hFont);
	TextOut(hdc, ((rect.right - rect.left - tm.tmAveCharWidth * sizeof(pauseText)) / 2), (rect.bottom - rect.top - tm.tmHeight) / 2, (LPCSTR)pauseText, sizeof(pauseText));
	DeleteObject(hFont);
}

States Game::Status()
{
	return state;
}

void Game::setStatus(States val)
{
	state = val;
}



void Game::drawPlaingProcess(HDC hdc, RECT rect)
{
	HPEN hPen;
	hPen = CreatePen(PS_SOLID, 2, RGB(255, 200, 10));
	SelectObject(hdc, hPen);
	MoveToEx(hdc, OX, OY, NULL);
	LineTo(hdc, OX + FWIDTH, OY);
	LineTo(hdc, OX + FWIDTH, OY + FHEIGHT);
	LineTo(hdc, OX, OY + FHEIGHT);
	LineTo(hdc, OX, OY);

	//рисование блоков
	BITMAP bm;
	HDC hCmpDC = CreateCompatibleDC(hdc);
	//HANDLE hBitMap = LoadImage(NULL, "pngguru.jpg", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	static HANDLE hBitMap;
	int blockarr[N][N];
	blocks.copyArray(blockarr);
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			switch (blockarr[j][i])
			{
			case 1:
				hBitMap = LoadImage(NULL, "blue_block.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				break;
			case 2:
				hBitMap = LoadImage(NULL, "green_block.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				break;
			case 3:
				hBitMap = LoadImage(NULL, "red_block.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				break;
			case 4:
				hBitMap = LoadImage(NULL, "lblue_block.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				break;
			case 5:
				hBitMap = LoadImage(NULL, "yell_block.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				break;
			case 6:
				hBitMap = LoadImage(NULL, "or_block.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				break;
			case 7:
				hBitMap = LoadImage(NULL, "purple_block.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				break;
			}
			if (blockarr[j][i] != 0)
			{
				GetObject(hBitMap, sizeof(BITMAP), &bm);
				SetStretchBltMode(hdc, COLORONCOLOR);
				SelectObject(hCmpDC, hBitMap);
				BitBlt(hdc, OX + bm.bmWidth * j, OY + bm.bmHeight * i, bm.bmWidth, bm.bmHeight, hCmpDC, 0, 0, SRCCOPY);

			}
		}

	}

	DeleteObject(hCmpDC);
	DeleteObject(hBitMap);
	hCmpDC = NULL;
}
void Game::gameResult(HDC hdc, RECT rect)
{

}