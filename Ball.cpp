#include "Ball.h"

Ball::Ball()
{
	posX = OX + ((FWIDTH - size) / 2);
	posY = OY + FHEIGHT - size * 2;
	horStep = 10;
	vertStep = -10;
}
int Ball::X()
{
	return posX;
}
int Ball::Y()
{
	return posY;
}

void Ball::Move(Blocks *blocks, Player player)
{
	//столкновение со стенами
	if (horStep > 0)
	{
		if (posX <= OX + FWIDTH - horStep - size)
			posX += horStep;
		else
		{
			posX = OX + FWIDTH - size;
			horStep *= -1;
		}
	}
	else
	{
		if (posX >= OX + size)
			posX += horStep;
		else
		{
			posX += OX - posX;
			horStep *= -1;
		}
	}

	if (vertStep > 0)
	{
		if (posY <= OY + FHEIGHT - vertStep - size - player.plHeight())
			posY += vertStep;
		else
		{
			int delta = posX - player.X();
			if ((delta <= player.plWidth() - size / 4) && delta >= -(3 * size / 4))
			{
				posY = FHEIGHT - size;
				vertStep *= -1;
				if (delta <= -size / 2)
					horStep *= -1;
				if (delta >= player.plWidth() - size / 2)
					horStep *= -1;
			}
			else
			{
				posY += vertStep;
			}
		}
	}
	else
	{
		//столкновение с блоками и стенами

		if (posY >= OY + blocks->Height() * N + vertStep + size)
			posY += vertStep;
		else
		{
			int j = (posX + size / 2 - OX)/blocks->Width();
			int i = ((posY - OY)/blocks->Height())-1;
			if (blocks->value(j, i) != 0)
			{
				blocks->decrease(j, i);
				posY = OY + blocks->Height() * ++i;
				vertStep *= -1;
			}
			else
				posY += vertStep;
		}
			
	}

}

void Ball::Reset()
{
	posX = OX + ((FWIDTH - size) / 2);
	posY = OY + FHEIGHT - size * 2;
	horStep = 10;
	vertStep = -10;
}