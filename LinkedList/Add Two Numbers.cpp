/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode* newlist = new ListNode(0);
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* p3 = newlist;
        int carry = 0;
        while(p1 != NULL || p2 != NULL){
            if(p1 != NULL) {
                carry += p1->val;
                p1 = p1->next;
            }
            if(p2 != NULL) {
                carry += p2->val;
                p2 = p2->next;
            }
        
            int val = carry%10;
            p3->next = new ListNode(val);
            p3 = p3->next;
            carry = carry/10;
        }
        if(carry != 0) {
            p3->next = new ListNode(carry);
            p3 = p3->next;
        }
        return newlist->next;
    }
};
// Too much lines of code but works
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
            
        int carry =0;
        ListNode* head = NULL;
        ListNode* result = NULL;
        while(l1 != NULL && l2 != NULL)
        {
            int sum = l1->val + l2->val + carry;
            carry =0;
            if(sum > 9)
            {
                carry = sum/10;
                sum = sum %10;
            }
            if(result == NULL)
            {
                result = new ListNode(sum);
                if(head == NULL)
                    head = result;
            }
            else
            {
                result->next = new ListNode(sum);
                result = result->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 == NULL)
        {
           while(l2 != NULL)
           {
               int sum = l2->val + carry;
               carry = 0;
               if(sum > 9)
               {
                   carry = 1;
                   sum = sum % 10;
               }
               if(result == NULL)
               {
                result = new ListNode(sum);
                if(head == NULL)
                    head = result;   
               }
               else
               {
                result->next = new ListNode(sum);
                result = result->next;   
               }
               l2 = l2->next;
           }
        }
        if(l2 == NULL)
        {
           while(l1 != NULL)
           {
               int sum = l1->val + carry;
               carry = 0;
               if(sum > 9)
               {
                   carry = 1;
                   sum = sum % 10;
               }
                if(result == NULL)
                {
                    result = new ListNode(sum);
                    if(head == NULL)
                        head = result;   
                }
                else
                {
                    result->next = new ListNode(sum);
                    result = result->next;   
                }
               l1 = l1->next;
           } 
        }
        if(carry == 1)
        {
           result->next = new ListNode(carry); 
        }
        return head;
    }
};
