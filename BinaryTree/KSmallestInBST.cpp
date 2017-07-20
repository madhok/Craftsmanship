/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
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
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return -1;
        int c =0;
       
       stack<TreeNode*> mystk;
       
       while(root != NULL || !mystk.empty()) {
           if(root != NULL) {
               mystk.push(root);
               root = root->left;
           } else {
               root = mystk.top();
               mystk.pop();
               c++;
               if(c == k) {
                  return root->val;
               }
              root = root->right;
           }
       }
       return -1;
    }
    
 
};