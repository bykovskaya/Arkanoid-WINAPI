#include "Game.h"
#include"common.h"

const wchar_t menuText[] = L"Press ENTER to start the game";
const wchar_t pauseText[] = L"PAUSE";
const wchar_t resultText[] = L"RESULT";
const wchar_t resultText2[] = L"Press ENTER to restart the game";
const char* imgBlocks[] = { {"red_block.bmp"},{"or_block.bmp"},{"yell_block.bmp"},{"green_block.bmp"},
							{"lblue_block.bmp"},{"blue_block.bmp"},
							{"purple_block.bmp"} };

Game::Game() : state(MENU)
{
	for (int i = 0; i < N; i++)
	{
		hBMBlock[i] = LoadImage(NULL, imgBlocks[i], IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	
	}
	blocks = new Blocks();
};
void ClearWorkspace(HDC hdc, RECT rect) 
{
	LOGBRUSH br;
	br.lbStyle = BS_SOLID;
	br.lbColor = 0x000000;
	
	HBRUSH brush;
	brush = CreateBrushIndirect(&br);
	FillRect(hdc, &rect, brush);
	DeleteObject(brush);
}

void Game::Menu( HDC hdc, RECT rect)
{
	ClearWorkspace( hdc,  rect);

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
	ClearWorkspace( hdc,  rect);
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
void Game::gameResult(HDC hdc, RECT rect)
{
	ClearWorkspace(hdc, rect);
	HFONT hFont;
	static TEXTMETRIC tm;
	hFont = CreateFont(20, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, VARIABLE_PITCH, "Pica");
	GetTextMetrics(hdc, &tm);
	SetTextColor(hdc, 0xffffff);
	SetBkMode(hdc, TRANSPARENT);
	SelectObject(hdc, hFont);
	TextOut(hdc, ((rect.right - rect.left - tm.tmAveCharWidth * sizeof(resultText)) / 2), 40, (LPCSTR)resultText, sizeof(resultText));
	TextOut(hdc, ((rect.right - rect.left - tm.tmAveCharWidth * sizeof(resultText2)) / 2), rect.bottom - 40, (LPCSTR)resultText2, sizeof(resultText2));
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

void Game::controlPlayer(int horStep)
{
	player.Move(horStep);
}

void Game::controlGame()
{

}

void Game:: controlBall()
{
	ball.Move(blocks, player);
	if (ball.Y() >= FHEIGHT)
	{
		state = RESULTS;
		player.Reset();
		ball.Reset();
		blocks->Reset();
	}
		
}

void Game::drawPlayingProcess(HDC hdc, RECT rect)
{
	HDC hCmpDC = CreateCompatibleDC(hdc);
	HBITMAP hCmpBM = CreateCompatibleBitmap(hdc, rect.right - rect.left, rect.bottom - rect.top);
	SelectObject(hCmpDC, hCmpBM);
	ClearWorkspace(hCmpDC, rect);

	HPEN hPen;
	hPen = CreatePen(PS_SOLID, 2, RGB(255, 200, 10));
	SelectObject(hCmpDC, hPen);
	MoveToEx(hCmpDC, OX - 1, OY-1, NULL);
	LineTo(hCmpDC, OX + FWIDTH + 1, OY-1);
	LineTo(hCmpDC, OX + FWIDTH + 1, OY + FHEIGHT + 1);
	LineTo(hCmpDC, OX - 1, OY + FHEIGHT + 1);
	LineTo(hCmpDC, OX - 1, OY-1);
	DeleteObject(hPen);

	HDC hCmpDC2 = CreateCompatibleDC(hCmpDC);
	HANDLE hBitMap;
	BITMAP bm;

	//painting ball
	hBitMap = LoadImage(NULL, "ball.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	GetObject(hBitMap, sizeof(BITMAP), &bm);
	SetStretchBltMode(hCmpDC, COLORONCOLOR);
	SelectObject(hCmpDC2, hBitMap);
	BitBlt(hCmpDC, ball.X(), ball.Y(), bm.bmWidth, bm.bmHeight, hCmpDC2, 0, 0, SRCCOPY);

	//рисование платформы
	hBitMap = LoadImage(NULL, "platform.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	GetObject(hBitMap, sizeof(BITMAP), &bm);
	SetStretchBltMode(hCmpDC, COLORONCOLOR);
	SelectObject(hCmpDC2, hBitMap);
	BitBlt(hCmpDC, player.X(), player.Y(), bm.bmWidth, bm.bmHeight, hCmpDC2, 0, 0, SRCCOPY);

	//рисование блоков
	
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (blocks->value(j, i) != 0)
			{
				GetObject(hBMBlock[i], sizeof(BITMAP), &bm);
				SetStretchBltMode(hCmpDC, COLORONCOLOR);
				SelectObject(hCmpDC2, hBMBlock[i]);
				BitBlt(hCmpDC, OX + bm.bmWidth * j, OY + bm.bmHeight * i, bm.bmWidth, bm.bmHeight, hCmpDC2, 0, 0, SRCCOPY);
			}
		}
	}
	

	SelectObject(hCmpDC, hCmpBM);
	SetStretchBltMode(hdc, COLORONCOLOR);
	BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, hCmpDC, 0, 0, SRCCOPY);

	DeleteDC(hCmpDC);
	DeleteDC(hCmpDC2);
	DeleteObject(hBitMap);
	DeleteObject(hCmpBM);
	hCmpDC = NULL;
}
