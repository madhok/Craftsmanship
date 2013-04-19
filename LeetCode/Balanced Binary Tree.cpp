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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(root == NULL)
            return true;
        
        if(abs(getMaxDepth(root->left) - getMaxDepth(root->right)) > 1)
            return false;
        else 
            if(isBalanced(root->left) && isBalanced(root->right))
                return true;
        return false;    
    }
    
    int getMaxDepth(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        else
            return 1 + max(getMaxDepth(root->left),getMaxDepth(root->right));
    }
};