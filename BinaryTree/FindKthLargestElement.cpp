#include <iostream>


using namespace std;
	
 void findKthlargestElement(TreeNode* root, int k, int& c) {
 	if(root == NULL) {
 		return;
 	}
 	findKthlargestElement(root->right, k, c);
 	c++;
 	if(c ==k) {
 		cout << "The K the largest element is " << root->val << endl;
 		return;
 	}
 	findKthlargestElement(root->left, k, c);
 }

 void Kthlargest(TreeNode* root, int k) {
 	int c = 0;
 	findKthlargestElement(root,k, c);
 }
 