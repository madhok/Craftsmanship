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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(cur != NULL) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
        
    }
};


// Recursion

void printReverse(Node* head) {
    if(head == NULL) {
        return;
    }
    printReverse(head->next);
    cout << head->val << " \t";
}
