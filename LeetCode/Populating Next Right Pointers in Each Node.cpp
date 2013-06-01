//Perfect binary tree

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       if(root == NULL)
            return;
        
        if(root->left == NULL || root->right== NULL)
            return;
        TreeLinkNode* leftmost = root;
        
        while(leftmost)
        {
            TreeLinkNode* rightsibling = NULL;
            if(leftmost->next)
            {
                rightsibling = leftmost->next->left;
            }
            else
            {
                rightsibling = NULL;
            }
            leftmost->left->next = leftmost->right;
            leftmost->right->next = rightsibling;
            leftmost = leftmost->next;
        }
        connect(root->left); 
    }
};