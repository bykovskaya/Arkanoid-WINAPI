#pragma once


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
