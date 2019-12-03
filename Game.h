#pragma once
#include<Windows.h>
#include"Ball.h"
#include"Player.h"
#include"Bonus.h"
#include"common.h"

enum States { PLAING, PAUSE, MENU, RESULTS };
class Game
{
private:
	States state;
public:
	Game();
	void Menu(HWND hWnd, HDC hdc, RECT rect);
	void setStatus(States);
	void checkBlockBallCollision();
	void checkBonusBoardCollision();
	void drawPlaingProcess(HDC hdc, RECT rect);
	void Pause(HDC hdc, RECT rect);
	void gameResult(HDC hdc, RECT rect);
	States Status();
};

