#pragma once
#include<Windows.h>
#include"Ball.h"
#include"Board.h"
#include"Bonus.h"
#include"common.h"

class Game
{
private:
	bool inGame;
public:
	Game();
	int Menu(HWND hWnd, HDC hdc, RECT rect);
	bool Status();
	void setStatus(bool);
	void checkBlockBallCollision();
	void checkBonusBoardCollision();
	void drawPlaingProcess(HDC hdc, RECT rect);
	void Pause(HDC hdc, RECT rect);
	void Result(HDC hdc, RECT rect);
};

