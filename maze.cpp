
#include <stdio.h>
#include <ctime>
#include <cstdlib> 
#include <iostream>

class point {
public:
	int x;
	int y;
	point(int xPoint, int yPoint){
	this->x = xPoint;
	this->y = yPoint;
	}
};

int main() 
{
	srand(time(0));
	int gridSize = (rand() % 5) + 3;
	int randXA = (rand() % gridSize);
	int randYA = (rand() % gridSize);
	int randXB = (rand() % gridSize);
	int randYB = (rand() % gridSize);
	int counter = 0; 
	int flip = 1;
	std::cout << "grid: " << gridSize << "x" << gridSize << std::endl;
	std::cout << "A coordinate: (" << randXA << "," << randYA << ")" << std::endl;
	std::cout << "B coordinate: (" << randXB << "," << randYB << ")" << std::endl;
	point pointA (randXA, randYA);
	point pointB (randXB, randYB);
	point search (randXA, randYA);
	while (search.x != 0){
		search.x -= 1; 
	}
	while (search.y != 0){
		search.y -= 1; 
	}
	for (int i = 0; i <= gridSize; i++)
	{
		while(search.y != pointB.y && search.x != pointB.x && search.x <= gridSize)
		{
			search.x += 1 * flip; 
		}
		if (search.y == pointB.y && search.x == pointB.x)
		{
			point foundB (search.x, search.y);
			std::cout << "Point B has been found at:" << "(" << foundB.x << "," << foundB.y << ")" << std::endl;
			counter = abs(foundB.x - pointA.x) + abs(foundB.y - pointA.y);
			break;
		}
		flip *= -1;
		search.y += 1;
	}	
	std::cout << "The shortest number of moves from point A to point B is: " << counter << std::endl;
	return (0);
}

