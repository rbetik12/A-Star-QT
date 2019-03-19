#pragma once
#include "util.h"
struct node;
class Labyrinth
{
public:
	explicit Labyrinth(int width, int height);
	~Labyrinth();
	node getStartNode();
	node getGoalNode();
	bool findWay();
	void drawWay();
	void printLabyrinth();
	void printDebug();
    node **getLabyrinth();
private:
	node** labyrinth;
	node start;
	node goal;
	int height;
	int width;
	bool status;
	void calculateHCostForNode(int x, int y);
	void calculateFCostForNode(int x, int y);
	void find_path();
	void draw_path();
};





