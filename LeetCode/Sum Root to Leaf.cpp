/*
Sum Root to Leaf NumbersFeb 192444 / 6813
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    
    if(root == NULL)
        return 0;   
    int result = 0;
    sumNode(root, root->val, result);
    return result;
    }
    
    void sumNode(TreeNode* root,int sum, int &result)
    {
        
       
        if(root->left == NULL && root->right == NULL)
        {
            result += sum;
        }
         
        
        if(root->left != NULL)
        {
            int num = sum* 10 + root->left->val; 
            sumNode(root->left, num, result);
        }
        
        if(root->right != NULL)
        {
             int num2 = sum* 10 + root->right->val; 
            sumNode(root->right, num2, result);
        }
       
    }
    
};