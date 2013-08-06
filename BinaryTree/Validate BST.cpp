/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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

// Easy implementation
int isBSTUtil(struct node* node, int min, int max);
 
/* Returns true if the given tree is a binary search tree 
 (efficient version). */
int isBST(struct node* node) 
{ 
  return(isBSTUtil(node, INT_MIN, INT_MAX)); 
} 
 
/* Returns true if the given tree is a BST and its 
   values are >= min and <= max. */
int isBSTUtil(struct node* node, int min, int max) 
{ 
 
  /* an empty tree is BST */
  if (node==NULL) 
     return 1;
       
  /* false if this node violates the min/max constraint */ 
  if (node->data < min || node->data > max) 
     return 0; 
 
  /* otherwise check the subtrees recursively, 
   tightening the min or max constraint */
  return
    isBSTUtil(node->left, min, node->data-1) &&  // Allow only distinct values
    isBSTUtil(node->right, node->data+1, max);  // Allow only distinct values
}   

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       int prev = INT_MIN;
        return isValidBSTHelper(root, prev); 
    }
    bool isValidBSTHelper(TreeNode* node, int &prev) {
        if (node == NULL) return true;
        if (isValidBSTHelper(node->left, prev)) {
            if (prev < node->val) {
                prev = node->val;
                return isValidBSTHelper(node->right, prev);
            }
            return false;
        }
        return false;
    }
};






/*if(root == NULL)
            return true;
        
        if(root->left == NULL && root->right == NULL)
            return true;
        
        if(root->left)
        {
            if(root->val <= root->left->val)
                return false;
        }
        if(root->right)
        {
            if(root->val >= root->right->val)
                return false;
        }
        return (isleftBST(root->left,root->val) && isRightBST(root->right,root->val));
    }
    
    bool isleftBST(TreeNode* Node, int rootval)
    {
        if(Node == NULL)
            return true;
        
        if(Node->left == NULL && Node->right == NULL)
        {
            if(Node->val >= rootval)
                return false;
            else
                return true;
        }
        
        if(Node->left)
        {
            if(Node->left->val >= Node->val)
                return false;
            return isleftBST(Node->left, rootval);
        }
        
        if(Node->right)
        {
            if(Node->right->val <= Node->val)
                return false;
            return isRightBST(Node->right, rootval);
        }
    }
    
    bool isRightBST(TreeNode* Node, int rootval)
    {
        if(Node == NULL)
            return true;
        
        if(Node->left == NULL && Node->right == NULL)
        {
            if(Node->val <= rootval)
                return false;
            else
                return true;
        }
        
        if(Node->left)
        {
            if(Node->left->val >= Node->val)
                return false;
            return isleftBST(Node->left, rootval);
        }
        
        if(Node->right)
        {
            if(Node->right->val <= Node->val)
                return false;
            return isRightBST(Node->right, rootval);
        }
    }*/