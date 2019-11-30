#pragma once

#define N 7
enum BonusType {STAR, LIFE, FASTER, SLOWER, BIGGER, SMALLER};

class Bonus
{
private:
	int width;
	int height;
	int posX, posY;
	int bonusType;
public:
	Bonus();
	void Fall();
};

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