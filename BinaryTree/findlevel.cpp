#include<stdio.h>

/* A tree node structure */
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
} ;

/* Helper function for getLevel(). It returns level of the data if data is
present in tree, otherwise returns 0.*/


int get_level_helper(TreeNode* root, int data, int level) {
	if(root == NULL) return -1;
	if(root->val == data) return level;
	if(root->left) {
		int downlevel = get_level_helper(root->left,data,level+1);
		if(downlevel != -1) return downlevel;
	}
	if(root->right) {
		int downlevel = get_level_helper(root->right,data,level+1);
		if(downlevel != -1) return downlevel;
	}
	return -1; // not found	
}

int get_level(TreeNode* root, int data) {
	int level = 0;
	if(root == NULL) return -1;
	return get_level_helper(root,data,level+1);
}
/* Utility function to create a new Binary Tree node */
struct TreeNode* newNode(int data)
{
	struct TreeNode *temp = new struct TreeNode;
	temp->val = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

/* Driver function to test above functions */
int main()
{
	struct TreeNode *root = new struct TreeNode;
	int x;

	/* Constructing tree given in the above figure */
	root = newNode(3);
	root->left = newNode(2);
	root->right = newNode(5);
	root->left->left = newNode(1);
	root->left->right = newNode(4);

	for (x = 1; x <=5; x++)
	{
	int level = get_level(root, x);
	if (level)
		printf(" Level of %d is %d\n", x, get_level(root, x));
	else
		printf(" %d is not present in tree \n", x);

	}

	getchar();
	return 0;
}
