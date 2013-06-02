// Return the Array of numbers of each level from a binary tree
//This is BFS -> use queue
vector<vector<int> > getlevelArray(Node* root)
{
	vector<vector<int> > result
	if(root == NULL)
		return result;

	queue<Node*> Nodes;
	Nodes.push(root);

	while(!Nodes.empty())
	{
		int size = Nodes.size();
		vector<int> levelValues;       
		for(int i = 0; i < size; i++)
		{
			Node* current = Nodes.pop();
			if(current->left)
				Nodes.push(current->left);
			if(current->right)
				Nodes.push(current->right);
			levelValues.push_back(current->val); 
		}
		result.push_back(levelValues);
	}
	return result;
}





// Using Stack - not recommended
vector<vector<int> > getlevelArray(Node* root)
{
	vector<vector<int> > result
	if(root == NULL)
		return result;

	stack<pair<Node*, int>>Nodes;
	Nodes.push(make_pair(root, 1);
	int currentLevel = 1;
	pair<Node*,int> current;
	current = Nodes.pop(); 

	while(current != NULL)	
	{
		vector<int> levelValues;
		currentLevel = current->second();
		while(current != NULL && currentLevel == current->second)
		 {
		 	Node* currentNode = current->first;
		 	if(currentNode->left)
			{
				Nodes.push(make_pair(currentNode->left,currentLevel+1));
			}
			if(currentNode->right)
			{
				Nodes.push(make_pair(currentNode->right,currentLevel+1));
			}
			levelValues.push_back(currentNode->val);
			current = Nodes.pop();
		 }
		 result.push_back(levelValues);
	}
}