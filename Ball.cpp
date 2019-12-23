#include "Ball.h"

Ball::Ball()
{
	posX = OX + ((FWIDTH - size) / 2);
	posY = OY + FHEIGHT - size * 2;
	horStep = 6;
	vertStep = -6;
}
int Ball::X()
{
	return posX;
}
int Ball::Y()
{
	return posY;
}

void Ball::Move(Blocks* blocks, Player player)
{
	//столкновение со стенами и блоками
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
		if (posX >= OX - horStep)
			posX += horStep;
		else
		{
			posX = OX;
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
				if (delta <= -size / 2 && horStep > 0)
					horStep *= -1;
				if (delta >= player.plWidth() - size / 2 &&
					horStep < 0)
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
		if (posY >= OY + blocks->Height() * N - vertStep)
			posY += vertStep;
		else
		{
			int i = ((posY - OY) / blocks->Height()) - 1;
			int j = (posX + size / 2 - OX) / blocks->Width();
			if (posY >= OY + blocks->Height() * (i + 1) - vertStep)
			{
				posY += vertStep;
			}
			else
			{
				if ((blocks->value(j, i) != 0))
				{
					posY = OY + blocks->Height() * (i + 1);
					blocks->decrease(j, i);
					vertStep *= -1;
				}
				else
				{
					if (posY >= OY - vertStep)
						posY += vertStep;
					else
					{
						posY = OY;
						vertStep *= -1;
					}
				}
			}
		}

		//if (posY >= OY + blocks->Height() * N - vertStep)
		//	posY += vertStep;
		//else
		//{
		//	int j = (posX + size / 2 - OX) / blocks->Width();
		//	int i = ((posY - OY) / blocks->Height()) - 1;
		//	if (i > 0)
		//	{
		//		if ((blocks->value(j, i) == 0) && (posY >= OY + blocks->Height() * i - vertStep))
		//		{
		//			posY += vertStep;
		//		}
		//		else
		//		{
		//			posY = OY + blocks->Height() * (i + 1);
		//			vertStep *= -1;
		//			//blocks->decrease(j, i);
		//		}
		//	}
		//	else
		//	{
		//		if (posY >= OY - vertStep)
		//			posY += vertStep;
		//		else
		//		{
		//			posY = OY;
		//			vertStep *= -1;
		//		}
		//	}
		//}
	}

}

void Ball::Reset()
{
	posX = OX + ((FWIDTH - size) / 2);
	posY = OY + FHEIGHT - size * 2;
	horStep = 10;
	vertStep = -10;
}