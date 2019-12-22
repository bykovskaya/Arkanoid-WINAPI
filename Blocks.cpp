#include "Blocks.h"

Blocks::Blocks()
{
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			block[j][i] = 1;
		}
	}
}

int Blocks::Width()
{
	return width;
}
int Blocks::Height()
{
	return height;
}

void Blocks:: decrease(int j, int i)
{
	--(block[j][i]);
}
int Blocks::value(int j, int i)
{
	return block[j][i];
}
void Blocks::Reset()
{
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			block[j][i] = 1;
		}
	}
}