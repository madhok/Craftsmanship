struct Node
{
	int val;
	getAdjacentNodes(list<Node*> adjacent);
};

void BFS(Node* n)
{
	map<visited,bool>visitedmap;
	queue<Node*> myqueue;
	list<Node*> adjacent = NULL;
	myqueue.push(n);
	visitedmap[n] = true;

	while(!myqueue.empty())
	{
		Node* currentNode = myqueue.front();
		myqueue.pop();
		adjacent.clear();
		currentNode->getAdjacentNodes(adjacent);
		list<Node*>::iterator it;
		for(it = adjacent.begin(); it != adjacent.end(); it++)
		{
			if(visitedmap.find(*it) == visitedmap.end())
			{
				myqueue.push(*it);
				visitedmap[*it] = true;
			}
		}
	}
}