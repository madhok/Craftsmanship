/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       vector<vector<int>> fullQueue;
        vector<int> currentLevelQueue; 
        queue<TreeNode*> currentLevelNodes;
        
        if(root == NULL)
            return fullQueue;
        
        currentLevelNodes.push(root);
        
        while(currentLevelNodes.size() != 0)
        {
            int size = currentLevelNodes.size();
            for(int i= 0; i < size;i++)
            {
                TreeNode* Node = currentLevelNodes.front();
                currentLevelNodes.pop();
                currentLevelQueue.push_back(Node->val);
                
                if(Node->left != NULL)
                    currentLevelNodes.push(Node->left);
            
                if(Node->right != NULL)
                    currentLevelNodes.push(Node->right);
                  
            }
            fullQueue.push_back(currentLevelQueue);
            currentLevelQueue.clear();
        }
        return fullQueue;
    }
};


