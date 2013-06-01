/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ? m ? n ? length of list.



*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *preTail = NULL, *curTail = NULL;
        ListNode *preNode = NULL, *curNode = head;
        for (int i = 1; i <= n; i++) {
            if (i == m-1) preTail = curNode;
            if (i == m) curTail = curNode;
            if (i >= m) {
                ListNode* nextNode = curNode->next;
                curNode->next = preNode;
                preNode = curNode;
                curNode = nextNode;
            }
            else curNode = curNode->next;
        }
        if (preTail == NULL) head = preNode;
        else preTail->next = preNode;
        curTail->next = curNode;
        return head;
    }


 //NOT WORKING
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL)
            return NULL;
        if(head->next == NULL || (n-m) < 2)
            return head;
        
        int count = n-m;
        ListNode* prev = NULL;
        ListNode* endlist = head;
        ListNode* startlist = head;
        m--;
        n--;
        while(m > 0)
        {
            prev = startlist;
            startlist = startlist->next;
            m--;
        }
        
        while(n > 0)
        {
            endlist = endlist->next;
            n--;
        }
        endlist = endlist->next;
        
        if(prev == NULL)
            prev = reverseList(startlist, count);
        else
            prev->next = reverseList(startlist, count);
       
       while(count > 0)
        {
            prev = prev->next;
            count--;
        }
        prev->next = endlist;
        
        return head;
    }
    
    ListNode* reverseList(ListNode* head, int count)
    {
        ListNode* current = head;
        ListNode* prev = NULL;
        while(count > 0 && current != NULL)
        {
            ListNode* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
            count--;
        }
        return current;
    }
};




