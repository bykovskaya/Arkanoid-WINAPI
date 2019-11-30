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
	void showMenu(HDC hdc, RECT rect);
	/*void checkBlockBallCollision();
	void checkBonusBoardCollision();
	void drawPlaingProcess();
	void showResult();*/
};

