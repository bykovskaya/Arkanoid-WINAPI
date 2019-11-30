#pragma once
class Ball
{
private:
	int width;
	int height;
	int posX, posY;
public:
	Ball();
	int X();
	int Y();
	void Move(int horStep, int vertStep);
};

