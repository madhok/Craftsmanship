/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:

    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively.


*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(root == NULL)
            return true;
        
        if(root->left == NULL && root->right == NULL)
            return true;
        
        return (isMirrorSiblings(root->left ,root->right));
            
    }
    
bool isMirrorSiblings(TreeNode *Node1,TreeNode *Node2)
{
    if(Node1 == NULL && Node2 == NULL)
        return true;
    if(Node1 && Node2)
    {
        if(Node1->val == Node2->val)
            return (isMirrorSiblings(Node1->left ,Node2->right) &&
                    isMirrorSiblings(Node1->right ,Node2->left));
    }
    return false;
}
    
};