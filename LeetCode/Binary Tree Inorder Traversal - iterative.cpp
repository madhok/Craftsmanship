/**
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> val;
        
        if(root == NULL)
            return val;
        
        stack<TreeNode*> Nodes;
        
        while(!Nodes.empty() || root!= NULL)
        {
            if(root!=NULL)
            {
                Nodes.push(root);
                root= root->left;
            }
            else
            {
                root = Nodes.top();
                Nodes.pop();
                val.push_back(root->val);
                root = root->right;
            }
        }
        return val;
};