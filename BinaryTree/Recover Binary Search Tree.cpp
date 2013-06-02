/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
    
    TreeNode* first;
    TreeNode* second;
    TreeNode* prev;
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        first = NULL;
        second = NULL;
        prev = NULL;
        inorder(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
        
    }
    
    void inorder(TreeNode* root)
    {
        if(root == NULL)
            return;
        
        inorder(root->left);
        if(prev == NULL)
        {
            prev = root;
        }
        else if (prev->val > root->val)
        {
            if(first == NULL)
                first = prev;
            second = root;    
        }
        prev = root;
        inorder(root->right);
    }
};