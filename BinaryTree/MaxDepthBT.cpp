/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

class Solution {
public:
    int maxDepth(TreeNode *root) 
    {                
        if(root != NULL)
        {
            return 1 + max(maxDepth(root->left), maxDepth(root->right));            
        }
        else
           return 0;      
    }
};