#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
class Labyrinth;

struct node
{
	int x;
	int y;
	int gCost = -1;
	int hCost = 0;
	int fCost = 0;
	int parentX = -1;
	int parentY = -1;
	short int typeOfCell;
	//node() { gCost = -1; hCost = 0; fCost = 0; parentX = -1; parentY = -1; }
	void calculateFCost();
	void calculateHCost(node goal);
};

bool operator!=(const node &, const node &);
bool operator==(const node &, const node &);
std::ostream &operator<< (std::ostream &stream, node &outputNode);
node lowestFCostNode(std::vector<node>);
int calculateNeighboursCosts(node current, node parent);

const short int CLEAN_ROAD_WEIGHT = 1;
const int DIRTY_ROAD_WEIGHT = 5;

const short int SPACE_SYMBOL = 0;
const short int DIRTY_CELL_SYMBOL = 1;
const short int WALL_SYMBOL = 2;
const short int START_SYMBOL = 3;
const short int FINISH_SYMBOL = 4;
const short int PATH_SYMBOL = 7;
const short int DIRTY_PATH_SYMBOL = 8;