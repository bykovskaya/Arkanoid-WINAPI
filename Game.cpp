#include "Game.h"
#include"common.h"

const wchar_t menuText[] = L"Press ENTER to start the game";
const wchar_t pauseText[] = L"PAUSE";
void printMessage(HDC, const wchar_t*, int, int, int);

Game::Game() : state(MENU){};

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
	TextOut(hdc, ((rect.right-rect.left-tm.tmAveCharWidth * sizeof(pauseText)) / 2), (rect.bottom - rect.top - tm.tmHeight) / 2, (LPCSTR)pauseText, sizeof(pauseText));
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


void Game::checkBlockBallCollision()
{

}
void Game::checkBonusBoardCollision()
{

}
void Game::drawPlaingProcess(HDC hdc, RECT rect)
{
	
}
void Game::gameResult(HDC hdc, RECT rect)
{

}