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
        
        root->next = NULL;
        TreeLinkNode* leftmost = root;
        
        while(leftmost)
        {
            TreeLinkNode* rightsibling = NULL;
            if(leftmost->next)
            {
                rightsibling = leftmost->next->right;
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
        
        
        
    /*     while(leftmost->left != NULL)
        {
            TreeLinkNode* cur = leftmost;
            cur->left->next = cur->right;
            TreeLinkNode* cursibling = cur->next;
            while(cursibling != NULL)
            {
                //cur->left->next = cur->right;
                cur->right->next = cursibling->left;
                cur = cursibling; 
                cursibling = cursibling->next;
            }
        cur->right->next = NULL;    
        leftmost = leftmost->left;
        }
        
        /*
        root->next = NULL;
        if(root->left != NULL && root->right != NULL)
        {
            connectNext(root->left, root->right);
            connectNext(root->right, root>next->left);
            connectNext(root->right, root>next->left);
        }
        connect(root->left);
        connect(root->right);
        */
        
    }
    
    void connectNext(TreeLinkNode* root, TreeLinkNode* rootsibling)
    {
        root->next = rootsibling;
    }
};

