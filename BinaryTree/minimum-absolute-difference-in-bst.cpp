/*
https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/ss
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.s

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
    void inorder(TreeNode* root, vector<int>& vals) {
        if(root == NULL) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }
    int get_min(vector<int>& vals) {
        if(vals.size() <2) return 0;
        int min = vals[1]-vals[0];
        for(int i=2; i< vals.size();++i) {
            min = std::min(vals[i]-vals[i-1], min);
        }
        return min;
    }
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL) return 0;
        vector<int> vals;
        inorder(root, vals);
        std::sort(vals.begin(),vals.end());
        return get_min(vals);
    }
};