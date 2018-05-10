
#include <stdio.h>
#include <ctime>
#include <cstdlib> 
#include <iostream>

	int count = 0;
class point {
public:
	int x;
	int y;
	point(int xPoint, int yPoint){
	this->x = xPoint;
	this->y = yPoint;
	}
	bool samePoint(point testPoint){
		if (this->y == testPoint.y && this->x == testPoint.x){
			return true;
		}
		return false;
	}
	bool findX(point blockPoint, point finalPoint){
		int dir; 
		if (this->x > finalPoint.x){
			dir = -1;
		}
		else {
			dir = 1;
		}
		while(this->x != finalPoint.x){
			this->x += 1 * dir;
			count += 1;
			if (count >= 10){
				break;
			}
			if (this->x == blockPoint.x && this->y == blockPoint.y){
				this->x -= 1 * dir;
				count -= 1;
				this->findY(blockPoint, finalPoint);
			}
		}
		return true;
	}
	bool findY(point blockPoint, point finalPoint){
		int dir; 
		if (this->y > finalPoint.y){
			dir = -1;
		}
		else {
			dir = 1;
		}
		while(this->y != finalPoint.y){
			this->y += 1 * dir;
			count += 1;
			if (count >= 10){
				break;
			}
			if (this->y == blockPoint.y && this->x == blockPoint.x){
				this->y -= 1 * dir;
				count -= 1;
				this->findX(blockPoint, finalPoint);
			}
		}
		return true;
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
	int numOfBlocks = (rand() % 2) + 1;
	int counter = 0; 
	int flip = 1;
	bool foundPoint = false;
	int blockX; 
	int blockY;
	std::cout << "numOfBlocks: " << numOfBlocks << std::endl;
	std::cout << "grid: " << gridSize << "x" << gridSize << std::endl;
	std::cout << "A coordinate: (" << randXA << "," << randYA << ")" << std::endl;
	std::cout << "B coordinate: (" << randXB << "," << randYB << ")" << std::endl;

	point pointA (randXA, randYA);
	point pointB (randXB, randYB);
	point search (0, 0);
	point foundB (0,0);	
	//Find a random place for the blocker
	for (int i = 0; i <= numOfBlocks; i++){
		blockX = (rand() % gridSize);
		blockY = (rand() % gridSize);
		//Make sure the blocker isnt on either point A or B
		while ((blockX == pointA.x && blockY == pointA.y) || (blockX == pointB.x && blockY == pointB.y)){ 
			blockX = (rand() % gridSize);
		}
		std::cout << "Block coordinate: (" << blockX << "," << blockY << ")" << std::endl;
	}
	point blocker (blockX, blockY);
	//Look for point B using the search point
	while(search.y <= gridSize)
	{
		while(search.x <= gridSize)
		{
			search.x += 1; 
			if (search.samePoint(pointB)){
				foundB.x = search.x;
				foundB.y = search.y;
				std::cout << "Point B has been found at:" << "(" << foundB.x << "," << foundB.y << ")" << std::endl;
				//counter = abs(foundB.x - pointA.x) + abs(foundB.y - pointA.y);
				//std::cout << "The shortest number of moves from point A to point B is: " << counter << std::endl;
				foundPoint = true;
				goto pickle;
				//break;
			}
			if (foundPoint == true){
				break;
			}
		}
		if (foundPoint == true){
			break;
		}
		search.y += 1;
		search.x = -1;
	}
	pickle:	
	search.x = randXA;
	search.y = randYA;
	while(search.findX(blocker, foundB) == false || search.findY(blocker, foundB) == false)
	{
		search.findX(blocker, foundB);
		search.findY(blocker, foundB);
	}
	std::cout << "The shortest number of moves from point A to point B is: " << count << std::endl;	
	if (foundPoint == false){
		std::cout << "No pathway has been found" << std::endl;
	}
	return (0);
}

