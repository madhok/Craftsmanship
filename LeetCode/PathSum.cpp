/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return false;
        
        return getSumtoleaf(root, sum);
    }
    
    bool getSumtoleaf(TreeNode *Node, int sum)
    {
        if(Node == NULL)
        {
            // if(sum == 0)
             //   return true;
             return false;    
        }
        
        if(Node->left == NULL && Node->right == NULL)
        {
            if(Node->val == sum)
                return true;
            else
                return false;
        }
        
        return (getSumtoleaf(Node->left, sum - Node->val) || getSumtoleaf(Node->right,  sum - Node->val));
    }
};