#pragma once

#define N 7
class Blocks
{
private:
	int block[N][N];
	const int width = 85;
	const int height = 29;
public:
	Blocks();
	int Width();
	int Height();
	void CheckCollision(int oX, int oY);
	void copyArray(int arr[N][N]);
};

