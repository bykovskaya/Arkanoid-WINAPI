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
	void decrease(int j, int i);
	int value(int j, int i);
	void Reset();
};

