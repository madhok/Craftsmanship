#include <iostream>

using namespace std;

bool validSumtree(TreeNode* root) {
	if(root == NULL) {
		return true;
	}
	int leftsum = sum(root->left);
	int rightsum = sum(root->right);

	if(leftsum + rightsum != root->val) return false;
	
	return validSumtree(root->right) && validSumtree(root->left);
}

int sum(TreeNode* root) {
	int sum = 0;
	sumhelper(root, sum);
	return sum;
}

void sumhelper(TreeNode* root, int& sum) {
	if(root == NULL) return;
	sum = sum + root->val;
	sumhelper(root>left,sum);
	sumhelper(root>right,sum);
}
