#include <iostream>

using namespace std;

struct Node
{
	int val;
	vector<Node*> getAdjacentNodes();
};

class graph
{
public:
	bool isConnected(Node* gNode);
	vector<Node*> getAllNodes();
};

bool graph::isConnected(Node* gNode)
{
	stack<Node*> mystack;
	vector<Node*> totalNodes;
	vector<Node*> visited;
	mystack.push(gNode);
	visited.push_back(gNode);
	
	while(!mystack.empty())
	{
		Node* curr = mystack.top();
		mystack.pop();
		vector<Node*> adjacentNodes = gNode->getAdjacentNodes();
		for(int i = 0; i < adjacentNodes.length(); i++)
		{
			if(visited.find(adjacentNodes[i]) != visited.end())
			{
				mystack.push(adjacentNodes[i]);
				visited.push_back(adjacentNodes[i]);
			}
		}
	}
	totalNodes = getAllNodes();

	if(totalNodes.size() != visited.size())
	{
		return false;
	}
	return true;
}
