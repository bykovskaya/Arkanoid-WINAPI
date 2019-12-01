#pragma once
#include<Windows.h>
#include"Ball.h"
#include"Board.h"
#include"Bonus.h"
#include"common.h"

enum States { PLAING, PAUSE, MENU, RESULTS };
class Game
{
private:
	States state;
public:
	Game();
	int Menu(HWND hWnd, HDC hdc, RECT rect);
	States Status();
	void setStatus(States);
	void checkBlockBallCollision();
	void checkBonusBoardCollision();
	void drawPlaingProcess(HDC hdc, RECT rect);
	void Pause(HDC hdc, RECT rect);
	void Result(HDC hdc, RECT rect);
};

