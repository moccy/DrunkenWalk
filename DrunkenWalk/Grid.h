#pragma once
#include <vector>
#include <random>
class Grid
{
public:
	Grid(int w, int h, char f, char e);
	~Grid();

	int Height;
	int Width;
	char Fill;
	char Empty;
	std::vector<std::vector<char>> charVector;
	
	void Print();
	int* GetRandomPoint() const;
	void FillPoint(int x, int y);
	void EmptyPoint(int x, int y);	
};

