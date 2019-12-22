#pragma once
#include<Windows.h>
#include"Ball.h"
#include"Player.h"
#include"Bonus.h"
#include"Blocks.h"
#include"common.h"

enum States { PLAYING, PAUSE, MENU, RESULTS };
class Game
{
private:
	HANDLE hBMBlock[7];
	States state;
	Player player;
	Ball ball;
	//Bonus bonus;
	Blocks blocks;
public:
	Game();
	void Menu( HDC hdc, RECT rect);
	void controlPlayer(int horStep);
	void controlBall();
	void controlGame();
	void drawPlayingProcess(HDC hdc, RECT rect);
	void Pause(HDC hdc, RECT rect);
	void gameResult(HDC hdc, RECT rect);
	void setStatus(States);
	States Status();
};

