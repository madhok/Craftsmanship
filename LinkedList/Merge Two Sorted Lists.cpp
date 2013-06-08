/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

*/




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(l1 == NULL && l2 == NULL)
            return NULL;
        
        if(l1 == NULL)
            return l2;
        
        if(l2 == NULL)
            return l1;
        
        ListNode* list = NULL;
        if(l1->val > l2->val)
        {
            list = new ListNode(l2->val);
            l2 = l2->next;
        }
        else
        {
            list = new ListNode(l1->val);
            l1 = l1->next;
        }
        ListNode* curr = list;
        while(l1!= NULL && l2!= NULL)
        {
            if(l1->val > l2->val)
            {
                curr->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            else
            {
                curr->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            curr = curr->next;
        }
        
        while(l1 != NULL)
        {
            curr->next = new ListNode(l1->val);
            l1 = l1->next;
            curr = curr->next;
        }
        
        while(l2 != NULL)
        {
            curr->next = new ListNode(l2->val);
            l2 = l2->next;
            curr = curr->next;
        }
        
        return list;
    }
};