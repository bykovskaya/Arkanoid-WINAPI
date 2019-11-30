#pragma once

class Board
{
private:
	int width;
	int height;
	int posX, posY;
public:
	Board();
	int X();
	int Y();
	void Move(int horStep);
	void Resize(int deltaSize);
};

