#include <iostream>

using namespace std;


void BFS(Node* root) {
	if(root == NULL) return;

	queue<Node*> nodeq;
	node.push(root);
	while(!nodeq.empty()) {
		int size = nodeq.size();
		for(int i = 0;  i< node1.size(); ++i) {
			Node* curr = nodeq.pop();
			cout << curr->data << "\t";

			if(curr->left) nodeq.push(curr->left);
			if(curr->right) nodeq.push(curr->right);
		}
		cout << "\n";
	}
	return;
}