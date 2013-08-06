/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.



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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      if(inorder.size() != preorder.size())
        return NULL;
        
        if(inorder.size() == 0 || preorder.size() == 0)
            return NULL;
        
       
        return buildTreeHelper(preorder, inorder,0, 0, inorder.size()-1);
      
      
    }
    
    TreeNode* buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int startPre, int start, int end)
    {
        if(start > end)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[startPre]);
        
        int leftend = getinorderIndex(inorder, preorder[startPre]);
        
        if(leftend == -1)
            return NULL;
        
        int leftTreeElements = leftend - start;
        
        root->left = buildTreeHelper(preorder, inorder,startPre +1, start, leftend-1);
        root->right = buildTreeHelper(preorder, inorder, startPre + leftTreeElements +1, leftend+1, end);
        
        return root;
    }
    
    int getinorderIndex(vector<int> &inorder, int val)
    {
        for(int i = 0; i < inorder.size(); i++)
        {
            if(inorder[i] == val)
                return i;
        }
        return -1;
    }
};





