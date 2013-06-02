//Determine if two nodes in the graph are connected

bool isConnected(Node* n1 , Node* n2)
{
	stack<Node*> Nodes;
	map<Node*, bool> visitedMap;
	list<Node*> adjacent;
	Nodes.push(n1);
	visitedMap[n1] = true;
	while(Nodes.isempty())
	{
		Node* tmp = Nodes.pop();
		adjacent[tmp] = tmp->getAdjacentNodes();
		list<int>::iterator i;
		for(i = adjacent[tmp].begin(); i != adjacent[tmp].end; i++)
		{
			if(*i == n2)
				return true;
			else if(visitedMap[*i] == false)
			{
				visitedMap[*i] = true;
				Nodes.push(*i);
			}
		}
	} 
	return false;
}