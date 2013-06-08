/*
Swap Nodes in PairsFeb 15 '12998 / 2279

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
 
 // recursion
 
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
     
     if(head == NULL || head->next == NULL)
        return head;
    
     ListNode* second = head->next;
     head->next = second->next;
     second->next = head;
     head = second;
     head->next->next = swapPairs(head->next->next);
     return head;
     
    }
};

//iterative

 
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
     
      if (!head || !head->next) return head;
    ListNode *ppre = NULL, *prev = head, *curr = head->next;

    while (curr) { //left at least 2 node
        prev->next = curr->next;
        curr->next = prev;
        if (ppre) ppre->next = curr;
        else head = curr;

        ppre = prev;
        prev = prev->next;
        if (prev) curr = prev->next; //left at least 1 node
        else curr = NULL; //none left
    }
    return head;
     
    }
};