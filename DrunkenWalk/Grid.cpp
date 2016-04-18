#include "stdafx.h"
#include "Grid.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>

Grid::Grid(int width, int height, char fill, char empty)
{
	Width = width;
	Height = height;
	Fill = fill;
	Empty = empty;
	for (int x = 0; x < Width; x++)
	{
		charVector.push_back(std::vector <char>());
		for (int y = 0; y < Height; y++)
		{
			charVector[x].push_back(Fill);
		}
	}
}


Grid::~Grid()
{
	charVector.clear();
}

void Grid::FillPoint(int x, int y)
{
	charVector[x][y] = Fill;
}

void Grid::EmptyPoint(int x, int y)
{
	charVector[x][y] = Empty;
}

void Grid::Print()
{
	for (int i = 0; i < Width; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			std::cout << charVector[i][j];
		}
		std::cout << std::endl;
	}
}

void Grid::DrunkardWalk()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> disWidth(0, Width);
	int startX = gen(disWidth);
	int startY = gen(disWidth);
	std::cout << std::to_string(startX);
	EmptyPoint(startX, startY);
}