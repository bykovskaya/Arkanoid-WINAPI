#pragma once
#include<Windows.h>

class Game
{
private:
	bool inGame;
public:
	Game();
	void showMenu();
	void checkBlockBallCollision();
	void checkBonusBoardCollision();
	void drawPlaingProcess();
	void showResult();
};

