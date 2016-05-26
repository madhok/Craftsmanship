/*
Given a singly linked list, rearrange it in a way that all odd position nodes are together and all even positions node are together,

Input: You have to complete the method which takes one argument: the head of the linked list. You should not read any input from stdin/console.. 
Tses. For each testhere are multiple test ca case, this method will be called individually.

Output:  
Your function shoudl return pointer to head of the modified list.

Constraints:
1 <=T<= 50
1 <=N<= 100
1 <=value<= 1000

Example:
Input:
2
4
1 2 3 4
5
1 2 3 4 5

Output:
1 3 2 4
1 3 5 2 4


*/



/* Node structure
struct node
{
    int data;
    struct node* next;
}; */

// Should rearrange given linked list such that all even
// positioned Nodes are before odd positioned.
// Returns new head of linked List.
Node *rearrangeEvenOdd(Node *head)
{
   // Your Code here
   if(head == NULL || head->next == NULL)
     return head;
    Node* odd = head;
    Node* even = head->next;
    Node* start_odd = odd;
    Node* start_even = even;
    Node* next_pair = even->next;
    while(next_pair!= NULL) {
        odd->next = next_pair;
        odd = odd->next;
        if(next_pair->next == NULL) break;
        even->next = next_pair->next;
        even = even->next;
        next_pair = even->next;
    }
    even->next = NULL;
    odd->next = start_even;
    return start_odd;
}