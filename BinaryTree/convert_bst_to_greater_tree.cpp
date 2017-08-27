/*

https://leetcode.com/problems/convert-bst-to-greater-tree/description/

Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13


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
    int total_sum(TreeNode* root) {
        if(root == NULL) return 0;
        int sum = root->val + total_sum(root->left) + total_sum(root->right);
        return sum;
    }
    void inorder_change(TreeNode* &root, int& sum) {
        if(root == NULL) return;
        inorder_change(root->left,sum);
        int temp = root->val;
        root->val = sum;
        sum = sum-temp;
        inorder_change(root->right,sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = total_sum(root);
        inorder_change(root,sum);
        return root;
    }
};
