/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

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
    int get_count(ListNode* head) {
        int count = 1;
        while(head) {
            count++;
            head = head->next;
        }
        return count;
    }
    
    ListNode* reverse(ListNode* head, int start) {
        ListNode* cur = head;
        int n = 1;
        while(start != n) {
            cur = cur->next;
            n++;
        }
        ListNode* prev = NULL;
        ListNode* temp = NULL; 
        while(cur) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp; 
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        int count = get_count(head);
        int revstart = count - count/2;
        int end =count/2;
        ListNode* rev = reverse(head, revstart);
        while(rev) {
            if(rev->val != head->val) {
                return false;
            }
            rev = rev->next;
            head = head->next;
        }
        return true;
    }
};
