// DrunkenWalk.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Grid.h"

void createDungeon(Grid &grid, int iterations)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> directionDist(0, 3);
	int direction;
	int lastPoint[2];

	int *randomPoint = grid.GetRandomPoint();
	grid.EmptyPoint(randomPoint[0], randomPoint[1]);
	lastPoint[0] = randomPoint[0];
	lastPoint[1] = randomPoint[1];
	for (auto i = 0; i < iterations; i++)
	{
		direction = directionDist(gen);
		switch (direction)
		{
			// North
		case 0:
			if(lastPoint[1] != 0)
			{
				grid.EmptyPoint(lastPoint[0], lastPoint[1] - 1);
				lastPoint[1] -= 1;
			}
			else
			{
				i--;
				break;
			}
			break;
			// East
		case 1:
			if(lastPoint[0] != 0)
			{
				grid.EmptyPoint(lastPoint[0] - 1, lastPoint[1]);
				lastPoint[0] -= 1;
			}
			else
			{
				i--;
				break;
			}		
			break;
			// South
		case 2:
			if(lastPoint[1] != grid.Height - 1)
			{
				grid.EmptyPoint(lastPoint[0], lastPoint[1] + 1);
				lastPoint[1] += 1;
			}
			else
			{
				i--;
				break;
			}			
			break;
			// West
		case 3:
			if(lastPoint[0] != grid.Width - 1)
			{
				grid.EmptyPoint(lastPoint[0] + 1, lastPoint[1]);
				lastPoint[0] += 1;
			}
			else
			{
				break;
			}
			break;
		default:
			std::cout << "Direction mismatch! Dungeon generation failed." << std::endl
				<< "Direction: " << direction << std::endl;
			return;
		}
	}

}

int main()
{
	Grid grid = Grid(60, 25, '#', '.');
	createDungeon(grid, 2000);
	grid.Print();
	getchar();
	grid.~Grid();
    return 0;
}

