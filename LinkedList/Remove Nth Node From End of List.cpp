/**

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass


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
        if(n == 0 || head == NULL)
            return head;
        
        ListNode* runningNode = head;
        
        while(n > 0)
        {
            runningNode = runningNode->next;
            n--;
        }
        if(runningNode == NULL)
            return head->next;
        ListNode* currentNode = head;
        while(runningNode->next != NULL)
        {
            currentNode = currentNode->next;
            runningNode = runningNode->next;
        }
        if(currentNode->next != NULL)
            currentNode->next = currentNode->next->next;
        else
            currentNode->next = NULL;    
        return head;
    }
};