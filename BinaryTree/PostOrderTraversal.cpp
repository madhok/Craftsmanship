/*
Post order traversal for an N-ary tree iterative way. 
Given, 
struct Node { 
int val; 
vector<Node*> children; 
}; 

Without modifying original structure.

*/

#include <iostream>

using namespace std;

struct Node {
	int val;
	vector<int> children;
};

//iterative way
/*
Create 2 stacks
push root to stack 1
pop stack until empty
	push left and right of the popped node to stack 1,
	push the popped node to stack2
print stack2
*/
 //Binary tree
void post_order(Node* root) {
	if(root == NULL) return;
	stack<Node*> stack1;
	stack<Node*> stack2;
	stack1.push(root);
	while(!stack1.empty()) {
		Node* curr = stack1.top();
		stack1.pop();
		if(curr->left) stack1.push(curr->left);
		if(curr->right) stack1.push(curr->right);
		stack2.push(curr);
	}
	while(!stack2.empty()) {
		Node* curr = stack2.top();
		stack.pop();
		cout << curr->val << "\t";
	}
}

//N tree 
void post_order_n(Node* root) {
	if(root == NULL) return;
	stack<Node*> stack1;
	stack<Node*> stack2;
	stack1.push(root);
	while(!stack1.empty()) {
		Node* curr = stack.top();
		stack.pop();
		int size = curr->children.size();
		for(int i = 0; i < size; i++) {
			stack1.push(curr->children[i]);
		}
		stack2.push(curr);
	}
	while(!stack2.empty()) {
		Node* curr = stack2.top();
		stack2.pop();
		cout << curr->val << "\t";
	}
}

//recursive way
void postorder(Node* root) {
	if(root == NULL) {
		return ;
	}
	int csize = root->children.size();
	for(int i =0; i <csize; ++i) {
		postorder(root->children[i]);
	}
	cout << root->val << "\t";
}

