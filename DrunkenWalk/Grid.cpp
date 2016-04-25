#include "stdafx.h"
#include "Grid.h"
#include <iostream>
#include <vector>
#include <random>

Grid::Grid(int width, int height, char fill, char empty)
{
	Width = width;
	Height = height;
	Fill = fill;
	Empty = empty;
	for (auto y = 0; y < Height; y++)
	{
		charVector.push_back(std::vector <char>());
		for (auto x = 0; x < Width; x++)
		{
			charVector[y].push_back(Fill);
		}
	}
}


Grid::~Grid()
{
	charVector.clear();
	Width, Height, Fill, Empty = NULL;
}

void Grid::FillPoint(int x, int y)
{
	charVector[y][x] = Fill;
}

void Grid::EmptyPoint(int x, int y)
{
	charVector[y][x] = Empty;
}

// Returning reference to a pointer on to stack? Wot do....
int* Grid::GetRandomPoint() const
{
	int coords[2];
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distWidth(0, Width), distHeight(0, Height);
	coords[0] = distWidth(gen);
	coords[1] = distHeight(gen);
	return coords;
}

void Grid::Print()
{
	for (auto i = 0; i < Height; i++)
	{
		for (auto j = 0; j < Width; j++)
		{
			std::cout << charVector[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
