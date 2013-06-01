/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

*/

/*/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL)
            return NULL;
            
        ListNode* currentNode = head;
        queue<int>lesser;
        queue<int>greater;
        
        while(currentNode != NULL)
        {
            if(currentNode->val < x)
            {
                lesser.push(currentNode->val);
            }
            else
            {
                greater.push(currentNode->val);
            }
            currentNode = currentNode->next;
        }
        ListNode* newList =NULL;
        if(!lesser.empty())
        {
            newList = new ListNode(lesser.front());
            lesser.pop();
        }
        else
        {
            newList = new ListNode(greater.front());
            greater.pop();
        }
        ListNode* retList = newList;
        
        while(!lesser.empty())
        {
            newList->next = new ListNode(lesser.front());
            lesser.pop();
            newList = newList->next;
        }
        
        while(!greater.empty())
        {
            newList->next = new ListNode(greater.front());
            greater.pop();
            newList = newList->next;
        }
        return retList;
    }
};






