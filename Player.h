#pragma once

class Player
{
private:
	/*int width;
	int height;*/
	int posX, posY;
	int stars;
	int lifes;
	int points;
public:
	Player();
	int X();
	int Y();
	void Move(int horStep);
	void Resize(int deltaSize);
	void checkBallCollision();
	void checkBonusCollision();
};

