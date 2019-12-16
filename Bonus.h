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
