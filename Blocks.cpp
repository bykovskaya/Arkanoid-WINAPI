#include "Blocks.h"

Blocks::Blocks()
{
	int arr[N][N] = { {0,0,0,0,0,0,0},
					  {0,0,0,0,0,0,0},
					  {0,0,0,0,0,0,0},
					  {0,0,0,0,0,0,0},
					  {0,0,0,0,0,0,0},
					  {1,1,1,1,1,1,1},
					  {0,0,0,0,0,0,0},
					   };
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			block[j][i] = arr[i][j];
			//block[i][j] = 1;
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

void Blocks::decrease(int j, int i)
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