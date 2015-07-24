/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) {
            return NULL;
        }
        int countA = 0;
        int countB = 0;
        ListNode* currA = headA;
        ListNode* currB = headB;
        while(currA) {
            countA++;
            currA = currA->next;
        }
        while(currB) {
            countB++;
            currB = currB->next;
        }
        currA = headA;
        currB = headB;
        if(countA > countB) {
            while(countA - countB) {
                currA = currA->next;
                countA--;
            } 
        }
        if(countB > countA) {
            while(countB -countA) {
                currB = currB->next;
                countB--;
            }
        }
        while(currA && currB && currA != currB) {
            currA= currA->next;
            currB = currB->next;
        }
        
        return currA;
    }
};
