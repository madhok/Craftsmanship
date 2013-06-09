/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL)
            return head;
        if(head->next == NULL)
            return head;
        
        if(k == 0)
            return head;
        
        ListNode* kNode = head;
        ListNode* tailNode = head;
        
        while(k >0)
        {
            tailNode = kNode;
            kNode = kNode->next;
            k--;
            if(kNode == NULL)
            {
                kNode = head;
                tailNode = NULL;
            }   
        }
        if(tailNode == NULL)
            return head;
            
        ListNode* newHead = head; 
        
        while(kNode->next != NULL)
        {
            tailNode= newHead;
            kNode =kNode->next;
            newHead = newHead->next;
        }
        tailNode = newHead;
        newHead = newHead->next;
        
        kNode->next = head;
        tailNode->next = NULL;
        
        return newHead;
       
    }
};