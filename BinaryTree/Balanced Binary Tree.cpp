/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //O(n2) - since u find height for every step
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(root == NULL)
            return true;
        
        if(abs(getMaxDepth(root->left) - getMaxDepth(root->right)) > 1)
            return false;
        else 
            if(isBalanced(root->left) && isBalanced(root->right))
                return true;
        return false;    
    }
    
    int getMaxDepth(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        else
            return 1 + max(getMaxDepth(root->left),getMaxDepth(root->right));
    }
};

//O(n) implemntation - pass height by reference
/* The function returns true if root is balanced else false
   The second parameter is to store the height of tree.  
   Initially, we need to pass a pointer to a location with value 
   as 0. We can also write a wrapper over this function */
bool isBalanced(struct node *root, int* height)
{
  /* lh --> Height of left subtree 
     rh --> Height of right subtree */   
  int lh = 0, rh = 0;  
 
  /* l will be true if left subtree is balanced 
    and r will be true if right subtree is balanced */
  int l = 0, r = 0;
     
  if(root == NULL)
  {
    *height = 0;
     return 1;
  }
 
  /* Get the heights of left and right subtrees in lh and rh 
    And store the returned values in l and r */   
  l = isBalanced(root->left, &lh);
  r = isBalanced(root->right,&rh);
 
  /* Height of current node is max of heights of left and 
     right subtrees plus 1*/   
  *height = (lh > rh? lh: rh) + 1;
     
  /* If difference between heights of left and right 
     subtrees is more than 2 then this node is not balanced
     so return 0 */
  if((lh - rh >= 2) || (rh - lh >= 2))
    return 0;
     
  /* If this node is balanced and left and right subtrees 
    are balanced then return true */
  else return l&&r;
}
