#include "Blocks.h"

Blocks::Blocks()
{
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			block[i][j] = j+1;
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

void Blocks::copyArray(int arr[N][N])
{
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			arr[j][i] = block[j][i];
		}
	}
}