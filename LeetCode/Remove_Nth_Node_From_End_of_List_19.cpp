/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *end = head;
        ListNode *delNode = head;
        int i =n;
        if(end->next == NULL)
        {
            if(i > 0)
                return NULL;
            else
              end = end->next;
        }            
        
        while(i > 0)
        {
            if(end->next == NULL)
                return delNode->next; // its the first element that shoul dbe deleted
            end = end->next;
            i--;
        }            
        
        while(end->next != NULL)
        {
            end = end->next;
            delNode = delNode->next;
        }
       
       
       if(delNode->next !=NULL)
        {
            delNode->next = delNode->next->next;
            return head;
        }
        return NULL;
    }
};