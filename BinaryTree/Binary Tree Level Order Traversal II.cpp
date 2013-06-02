/*
REVERSE WAY

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:

[
  [15,7]
  [9,20],
  [3],
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.




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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int>> result;
        
        if(root == NULL)
            return result;
        
        TreeNode* currentLevel = root;
        
        queue<TreeNode*> Nodes;
        Nodes.push(root);
        
        while(!Nodes.empty())
        {
            int size = Nodes.size();
            vector<int> levelnodes;  
            for(int i = 0 ; i < size; i++)
            {
                TreeNode* currentNode = Nodes.front();
                Nodes.pop();
                levelnodes.push_back(currentNode->val);
                if(currentNode->left)
                    Nodes.push(currentNode->left);
                if(currentNode->right)
                    Nodes.push(currentNode->right);
            }
            result.push_back(levelnodes);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};