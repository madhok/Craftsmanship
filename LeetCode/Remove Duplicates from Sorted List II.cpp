/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//WORKING

 class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* newHead = NULL, *newNode = NULL;
        ListNode* curNode = head;
        while (curNode != NULL) {
            bool found = true;
            ListNode* nextNode;
            while (curNode->next != NULL && curNode->val == curNode->next->val) {
                nextNode = curNode->next;
                delete curNode;
                curNode = nextNode;
                found = false;
            }
            if (found) {
                if (newHead == NULL) {
                    newHead = curNode;
                    newNode = curNode;
                }
                else {
                    newNode->next = curNode;
                    newNode = newNode->next;
                }
                curNode = curNode->next;
            }
            else {
                nextNode = curNode->next;
                delete curNode;
                curNode = nextNode;
            }
        }
        if (newNode) newNode->next = NULL;
        return newHead;
    }
};


 //NOT WORKING

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* prevNode = NULL;
        ListNode* currentNode = head;
        ListNode* next = currentNode->next;
        bool attachcur = false;
        
        while(next != NULL)
        {
            if(currentNode->val != next->val)
            {
                if(prevNode == NULL)
                    prevNode = currentNode;
                else
                {
                    prevNode->next == currentNode;
                    prevNode= prevNode->next;
                }
                currentNode = next;
                next = next->next; 
                attachcur = true;
            }
            else
            {
                attachcur = false;
                while(next->next != NULL && next->val == currentNode->val)
                {
                    next = next->next;
                    
                }
                if(next->next == NULL)
                    attachcur = true;
                currentNode = next;
                next = next->next; 
                
            }
        }
        if(prevNode == NULL)
        {
            if(attachcur)
            {
                prevNode = currentNode;
            }
            return prevNode;
        }
        else
        {
           if(attachcur) 
           {
               prevNode->next = currentNode;
               prevNode = prevNode->next;
           }
           prevNode->next = NULL;
        }
        return head;
        
            
         /*   
            
            
            
            while(next->val == currentNode->val && next != NULL)
            {
                  next = next->next;
            }
            if(prevNode == NULL)
                prevNode = next;
            else
            {
                prevNode->next = next;
                prevNode = prevNode->next;
            }
            currentNode = next;
            next = next->next;
        }
       //if(prevNode != NULL)
    //        prevNode->next = NULL;
        return head;
        
    /*                 
        while(next != NULL)
        {
          
          if(next->val != currentNode->val)
            {
                if(prevNode == NULL)
                    prevNode = currentNode;
                else
                {
                    prevNode->next = currentNode;
                    prevNode = prevNode->next;
                }
                    
                currentNode = next;
                attachcur = true;
                next = next->next;
            }
            else
            {
                currentNode = next;
                attachcur = false;
                next = next->next;
            }
        }
        if(prevNode == NULL && attachcur == false)
            return prevNode;
            
        if(prevNode == NULL && attachcur == true)
        {
            prevNode = currentNode;
            prevNode->next = NULL;
            return head;
        }
            
            
        if(attachcur)
        {
            prevNode->next = currentNode;
            prevNode = prevNode->next;
        }
      */        
        prevNode->next = NULL;
        return head;
    }
};