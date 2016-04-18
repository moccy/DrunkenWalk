// DrunkenWalk.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Grid.h"


int main()
{
	Grid grid = Grid(50, 50, '#', 'O');
	grid.DrunkardWalk();
	grid.Print();
	std::getchar();
	grid.~Grid();
    return 0;
}
