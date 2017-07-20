/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) 
            return head;
        
        int n = 0;
        ListNode* tail = head;
        while(tail->next !=NULL) {
            tail = tail->next;
            n++;
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        int k = n/2;
        if(n%2==1) k = (n-1)/2 +1;
        while(k>0){
            k--;
            //n = n-2;
            tail->next = curr;
            prev->next = curr->next;
            tail = tail->next;
            tail->next = NULL;
            prev = prev->next;
            curr = prev->next;
        }
        return head;
    }
};