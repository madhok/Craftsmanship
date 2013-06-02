/*
Given inorder and postorder traversal of a tree, construct the binary tree.

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(inorder.size() == 0 || postorder.size() == 0)
            return NULL;
        
        return buildTreeHelper(inorder,postorder,0,inorder.size()-1,postorder.size()-1);
    }
    
    int getroot(vector<int>postorder, int end)
    {
        return postorder[end];
    }
    
    TreeNode* buildTreeHelper(vector<int> &inorder, vector<int> &postorder, int start, int end, int pend)
    {
         if(start > end)
            return NULL;
        
        int rootval = getroot(postorder,pend);
        pend--;
        TreeNode* root = new TreeNode(rootval);
        int endLeft = start;
        for(; endLeft < end; endLeft++)
        {
            if(inorder[endLeft] == rootval)
                break;
        }
        int rightelements = end - endLeft;
        root->left = buildTreeHelper(inorder,postorder,start,endLeft-1, pend-rightelements);
        root->right = buildTreeHelper(inorder,postorder,endLeft+1, end, pend);
        return root;
    }
};


