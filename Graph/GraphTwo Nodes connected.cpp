//Determine if two nodes in the graph are connected

bool isConnected(Node* n1 , Node* n2)
{
	stack<Node*> Nodes;
	map<Node*, bool> visitedMap;
	list<Node*> adjacent = NULL;
	Nodes.push(n1);
	visitedMap[n1] = true;
	while(!Nodes.isempty())
	{
		Node* tmp = Nodes.pop();
		tmp->getAdjacentNodes(adjacent);
		list<int>::iterator i;
		for(i = adjacent.begin(); i != adjacent.end; i++)
		{
			if(*i == n2)
				return true;
			else
			{
				if(visited.find(*i) == visited.end())
				{
					Nodes.push(*i);
					visited[*i] = true;
				}
			} 
		}
	} 
	return false;
}