#pragma once
#include "common.h"

class Player
{
private:
	int width;
	int posX;
	const int height = 20;
	const int posY = FHEIGHT;
	int stars;
	int lifes;
	int points;
public:
	Player();
	int X();
	int Y();
	int plHeight();
	int plWidth();
	void Move(int horStep);
	void Resize(int deltaSize);
	void checkBonusCollision();
	void Reset();
};

