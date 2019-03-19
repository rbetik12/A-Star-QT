#include "util.h"
bool operator== (const node &n1, const node &n2)
{
	return memcmp(&n1, &n2, sizeof(node)) == 0;
}

bool operator!= (const node &n1, const node &n2)
{
	return memcmp(&n1, &n2, sizeof(node)) != 0;
}

std::ostream &operator<< (std::ostream &stream, node &outputNode)
{
	stream << "Cell: " << outputNode.typeOfCell << ", "
		<< "X: " << outputNode.x << ", "
		<< "Y: " << outputNode.y << ", "
		<< "Parent X: " << outputNode.parentX << ", "
		<< "Parent Y: " << outputNode.parentY << ", "
		<< "G cost: " << outputNode.gCost << " + "
		<< "H cost: " << outputNode.hCost << " = "
		<< "F cost: " << outputNode.fCost << std::endl;
	return stream;
}

node lowestFCostNode(std::vector<node> nodes)
{
	node minFCostNode = nodes[0];
	for (node i : nodes)
	{
		if (i.fCost < minFCostNode.fCost)
			minFCostNode = i;
	}
	return minFCostNode;
}

int calculateNeighboursCosts(node current, node parent)
{
	if (current.typeOfCell == 1) return round(sqrt(pow((parent.x - current.x) + DIRTY_ROAD_WEIGHT, 2) + pow((parent.y - current.y) + DIRTY_ROAD_WEIGHT, 2)) * 10);
	return round(sqrt(pow((parent.x - current.x), 2) + pow((parent.y - current.y), 2)) * 10);
}

void node::calculateFCost()
{
	fCost = hCost + gCost;
}

void node::calculateHCost(node goal)
{
	hCost = round(sqrt(pow((goal.x - x), 2) + pow((goal.y - y), 2)) * 10);
}
