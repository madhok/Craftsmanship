#include <iostream>

using namespace std;

bool isIdentical(TreeNode* t1, TreeNode* t2) {
	if(t1 == NULL && t2 == NULL) return true;
	if(t1 == NULL || t2 == NULL) return false;

	if(t1->val != t2->val) return false;
	return isIdentical(t1->left, t2->left) &&
			isIdentical(t1->right, t2->right);
}

bool isSubTree(TreeNode* T, TreeNode* S) {
	if(S == NULL) return true;
	if(T == NULL) return false;

	if(isIdentical(T,S) == true) return true;
	return isSubTree(T->left,S) || isSubTree(T->right, S);
}