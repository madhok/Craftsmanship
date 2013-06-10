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