#pragma once
#include<Windows.h>
#include"Ball.h"
#include"Player.h"
#include"Bonus.h"
#include"Blocks.h"
#include"common.h"

enum States { PLAING, PAUSE, MENU, RESULTS };
class Game
{
private:
	States state;
	//Player player;
	//Ball ball;
	//Bonus bonus;
	Blocks blocks;
public:
	Game();
	void Menu(HWND hWnd, HDC hdc, RECT rect);
	void controlGame();
	void drawPlaingProcess(HDC hdc, RECT rect);
	void Pause(HDC hdc, RECT rect);
	void gameResult(HDC hdc, RECT rect);
	void setStatus(States);
	States Status();
};

