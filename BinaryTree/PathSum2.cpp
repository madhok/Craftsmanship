/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals
 the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       vector<vector<int>>results;
       vector<int> pathSum;
       if(root == NULL)
            return results;
       
       getSum(root, sum, pathSum, results);
       return results;
       
    }
    
    void getSum(TreeNode* currentNode, int sum, vector<int>pathSum, vector<vector<int>>&results)
    {
        if(currentNode == NULL)
            return;
        pathSum.push_back(currentNode->val);
        sum -= currentNode->val;
        if(currentNode->left == NULL && currentNode->right == NULL && sum == 0)
        {
            results.push_back(pathSum);
            return;
        }
        
        getSum(currentNode->left, sum, pathSum, results);
        getSum(currentNode->right,sum, pathSum, results);
        
    }
};