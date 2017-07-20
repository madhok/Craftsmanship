/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size= lists.size();
        if(size == 0) return NULL;
        if(size == 1) return lists[0];
        
        int start = 0, end = size-1;
        
        for(int i = 1; i <lists.size();) {
            ListNode* merged = merge2Lists(lists[0],lists[i]);
            lists.erase(lists.begin());
            lists.erase(lists.begin());
            lists.insert(lists.begin(),merged);
            //lists[0] = merged;
        }
        return lists[0];
    }
    
    
    ListNode* merge2Lists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        while(list1 != NULL && list2!= NULL) {
            if(list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2= list2->next;
            }
            curr = curr->next;
        }
        if(list1) curr->next = list1;
        if(list2) curr->next = list2;
        return head->next;
    }
};
//Using priority_queue
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        priority_queue<int, vector<int>, greater<int> > queue;
        
        if(lists.size() == 0)
            return NULL;
        
        for(int i = 0; i<lists.size(); i++)
        {
            ListNode* temp = lists[i];
            while(temp != NULL)
            {
                queue.push(temp->val);
                temp = temp->next;
            }
        }
        if(queue.empty())
           return NULL; 
        ListNode* result = new ListNode(queue.top());
        queue.pop();
        ListNode* head  = result;
        while(!queue.empty())
        {
            result->next = new ListNode(queue.top());
            queue.pop();
            result = result->next;
        }
        return head;
    }
};