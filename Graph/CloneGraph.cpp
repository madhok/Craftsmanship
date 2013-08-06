#include <iostream>
#include <map>

struct Node
{
	int val;
	vector<Node*> neighbours;	
	Node(int x):val(x){}
};

Node* clonegraph(Node* gNode)
{
	map<Node*, Node*> mymap;
	queue<Node*> q;
	Node* ret = new Node(gNode->val);
	mymap[gNode] = ret;
	q.push(gNode);

	while(!q.empty())
	{
		Node* curr = q.front();
		q.pop();
		vector<Node*> curNeighbours = q.getneighbours();
		for(int i = 0; i<curNeighbours.size(); i++)
		{
			if(mymap.find(curNeighbours[i]) != mymap::end())
			{
				q.push(curNeighbours[i]);
				Node* cloneI = new Node(curNeighbours[i]);
				mymap[curNeighbours[i]] = cloneI;
				mymap[curr]->neightbours.push_back(cloneI); //mymap[curr] -> gives the clone for the curr
			}
			else
			{
				mymap[cur]->neightbours.push_back(curNeighbours[i]);
			}
		}
	}	

	return ret;

}