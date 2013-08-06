//Not a perfect binary tree

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
 //best
 class Solution 
{
public:
    void connect(TreeLinkNode *root)
    {
        connect1(root);
    }

    void connect1(TreeLinkNode *curNode)
    {
        if (!curNode) return;
        TreeLinkNode* nextHead = NULL;
        while (curNode)
        {
            if(curNode->left)
            {
                curNode->left->next = getNextSibling(curNode, true);
                if (!nextHead) nextHead = curNode->left;
            }
            if (curNode->right)
            {
                curNode->right->next = getNextSibling(curNode, false);
                if (!nextHead) nextHead = curNode->right;
            }
            curNode = curNode->next;
        }
        connect1(nextHead);
    }

    TreeLinkNode* getNextSibling(TreeLinkNode *curNode, bool isLeft)
    {
        if (isLeft)
            if (curNode->right) return curNode->right;
        while ((curNode = curNode->next))
        {
            if (curNode->left) return curNode->left;
            if (curNode->right) return curNode->right;
        }
        return NULL;
    }
};
 
//bad 
 
 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL)
            return;
        
        TreeLinkNode *parent = root;
        TreeLinkNode *nextright = NULL;
        while(parent)
        {
            if(parent->left)
            {
                if(parent->right)
                    nextright = parent->right;
                else
                {
                   if(parent->next)
                    {
                    if(parent->next->left)
                        nextright = parent->next->left;
                    else if(parent->next->right)
                        nextright = parent->next->right;
                    } 
                }
                parent->left->next = nextright;
            }
            if(parent->right)
            {
             nextright = NULL;
             if(parent->next)
                {
                if(parent->next->left)
                    nextright = parent->next->left;
                else if(parent->next->right)
                    nextright = parent->next->right;
                } 
             parent->right->next = nextright;
            }
            if(parent->next)
            {
                parent = parent->next;
            }
            else
            {
                break;
            }
        }
        TreeLinkNode *nextlevelLeft = NULL;
        while(nextlevelLeft != NULL)
        {
            if(parent->left)
            {
                nextlevelLeft = parent->left;
                break;
            }
            else if(parent->right)    
            {
                nextlevelLeft = parent->right;
                break;
            }
            else if(parent->next == NULL)
                break;
            parent = parent->next;
        }
       connect(nextlevelLeft); 
    }
};