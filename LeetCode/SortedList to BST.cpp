/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    
    if(head == NULL)
        return NULL;
    
    ListNode* currentNode = head;
    int count = 0;
    while(currentNode != NULL)
    {
        count++;
        currentNode = currentNode->next;
    }
    
    currentNode = head;  
    return createBST(currentNode, 0 , count);
    
    }
    
    TreeNode* createBST(ListNode* &list, int start, int end)
    {
        
        TreeNode* root = NULL;
        if(start > end)
        {
            return NULL;
        }
        int median = start + (end - start)/2;
        TreeNode* left = createBST(list, start , median-1);
        root = new TreeNode(list->val);
        root->left = left;
        list = list->next;
        root->right = createBST(list, median+1, end);
        
        return root;
    }
    
};