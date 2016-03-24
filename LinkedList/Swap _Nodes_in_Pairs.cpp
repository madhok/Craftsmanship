/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* start = head->next;
        ListNode* cur = head;
        ListNode* second = head->next;
        ListNode* next_pair = head->next->next;
        
        while(second != NULL) {
            next_pair = second->next;
            second->next = cur;
            if(next_pair && next_pair->next)
                cur->next = next_pair->next;
            else {
                cur->next = next_pair;
            }
            cur = next_pair;
            if(next_pair)  second = next_pair->next;
            else second = NULL;
        }
        return start;
    }
};
