/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        TreeNode* root = helper(nums,0,size-1);
        return root;
    }
    
    TreeNode* helper(vector<int>& nums, int start, int end) {
        if(start >end) return NULL;
        int mid = start + (end-start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left  = helper(nums,start,mid-1);
        root->right  = helper(nums,mid+1,end);
        return root;
    }
};