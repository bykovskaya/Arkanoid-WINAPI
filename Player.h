#pragma once
#include "common.h"

class Player
{
private:
	int width;
	int posX;
	const int height = 20;
	const int posY = FHEIGHT-1;
	int stars;
	int lifes;
	int points;
public:
	Player();
	int X();
	int Y();
	void Move(int horStep);
	void Resize(int deltaSize);
	void checkBonusCollision();
};

