#pragma once

enum BonusType {STAR, LIFE, FASTER, SLOWER, BIGGER, SMALLER};

class Bonus
{
private:
	int width;
	int height;
	int posX, posY;
	BonusType bonusType;
public:
	Bonus();
	void Fall();
	int bX();
	int bY();
	int bWidht();
	int bHeight();
	BonusType bType();
};

#define N 7
class Blocks
{
private:
	int block[N][N] = { {1, 1, 1, 1, 1, 1, 1 },
						{1, 1, 1, 1, 1, 1, 1 },
						{1, 1, 1, 1, 1, 1, 1 },
						{1, 1, 1, 1, 1, 1, 1 },
						{1, 1, 1, 1, 1, 1, 1 },
						{1, 1, 1, 1, 1, 1, 1 },
						{1,	1, 1, 1, 1, 1, 1 }};
	const int width = 85;
	const int height = 30;
public:
	Blocks();
	int Width();
	int Height();

};