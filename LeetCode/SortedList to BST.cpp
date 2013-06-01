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



//Same thing

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
        
        if(head->next == NULL)
            return new TreeNode(head->val);
            
       return createtree(head, 0, getLength(head) -1);
        
    }
    
    TreeNode* createtree(ListNode* head, int start, int end)
    {
        if(start < end)
        {
           // int length = getLength(head); 
            int middle = start + (end - start)/2;
            TreeNode* root = new TreeNode(getMiddle(head, middle));
            root->left = createtree(head, start, middle-1);
            root->right = createtree(head, middle + 1, end);
            return root;
        }
        else if(start == end)
            return new TreeNode(getMiddle(head, start));
        return NULL;
    }
    
    int getLength(ListNode *head)
    {
        int count = 0;
        
        while(head != NULL)
        {
            count ++;
            head= head->next;
        }
        return count;
    }
    
    int getMiddle(ListNode *head, int n)
    {
        while(n!= 0)
        {
            head = head->next;
            n--;
        }
        return head->val;
    }
    
    
};