 Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6



class Solution {
public:
    TreeNode* flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    if(root == NULL)
        return root;
    
    if(root->left == NULL && root->right == NULL)
        return root;
    
    TreeNode* left = flatten(root->left);
    TreeNode* right = flatten(root->right);
    
    TreeNode* head = root;
    
    if(left && right)
    {
        left->right = root->right;
        root->right = root->left;
        root->left = NULL;
        return right;
        
        
    }
    if(left)
    {
        root->right = root->left;
        root->left = NULL;
        return left;
    }

    root->left = NULL;
    return right;
        
    }
    
};