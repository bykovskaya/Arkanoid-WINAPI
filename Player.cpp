#include "Player.h"

Player::Player()
{
	posX = OX + ((FWIDTH-75) / 2);
	width = 75;
}

void Player:: Move(int horStep)
{
	if((posX <= FWIDTH+OX-width-horStep) && (posX >= OX - horStep))
		posX += horStep;
}
int Player::X()
{
	return posX;
}
int Player::Y()
{
	return posY;
}