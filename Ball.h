#pragma once
#include"Blocks.h"
#include"Player.h"

class Ball
{
private:
	int width;
	int height;
	int posX, posY;
	int vertStep, horStep;
public:
	Ball();
	int X();
	int Y();
	void Move(int horStep, int vertStep);
	void CheckCollision(Blocks blocks);
	bool CheckCollision(Player player);
	void CheckCollision();
};

