/*
The thief has found himself a new place for his thievery again. 
There is only one entrance to this area, called the "root." 
Besides the root, each house has one and only one parent house. 
After a tour, the smart thief realized that "all houses in this place 
forms a binary tree". It will automatically contact the police if 
two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob 
tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        vector<int> result = helper(root);
        return result[0]>result[1]?result[0]:result[1];
    }
    
    vector<int> helper(TreeNode* root) {
        vector<int> result = {0,0};
        if(root == NULL) {
            return result;
        }
        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);
        
        result[0] = root->val + left[1] + right[1];
        result[1] = max(left[0],left[1]) + max(right[0],right[1]);
        
        return result;
    }
};