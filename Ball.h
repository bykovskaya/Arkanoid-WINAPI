#pragma once
#include"Blocks.h"
#include"Player.h"
#include"common.h"

class Ball
{
private:
	int size = 20;
	int posX, posY;
	int vertStep, horStep;
public:
	Ball();
	int X();
	int Y();
	void Move(Blocks *blocks, Player player);
	void Reset();
	//void CheckCollision();
};

