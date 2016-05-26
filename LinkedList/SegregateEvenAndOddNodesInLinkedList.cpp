/*

Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers same.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the number of elements in Linked List.
The second line of each test case contains N input,elements in Linked List.

Output:

Print the all even numbers then odd numbers in the modified Linked List.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 100
1 ≤ size of elements ≤ 1000

Example:

Input
3
7
17 15 8 9 2 4 6
4
1 3 5 7
7
8 12 10 5 4 1 6

Output
8 2 4 6 17 15 9
1 3 5 7
8 12 10 4 6 5 1

*/
#include <iostream>
using namespace std;
struct Node {
    int val;
    Node* next;
    Node(int x):val(x),next(NULL){}
};

Node* print_even_odd(Node* head) {
    if(head == NULL) return NULL;
    Node* odd = NULL;
    Node* even = NULL;
    Node* oddstart = NULL;
    Node* evenstart = NULL;
    Node* cur = head;
    while(cur) {
        if((cur->val)%2 == 0) {
            if(even == NULL) {
                even = new Node(cur->val);
                evenstart = even;
            } else {
                even->next= new Node(cur->val);
                even = even->next;
            } 
        } else {
            if(odd == NULL) {
                odd = new Node(cur->val);
                oddstart = odd;
            } else {
                odd->next= new Node(cur->val);
                odd = odd->next;
            } 
        }
        cur = cur->next;
    }
    if(even == NULL) {
        return oddstart;
    }
    even->next = oddstart;
    return evenstart;
}

int main() {
	int n;
	cin >>n;
	while(n) {
	    n--;
	    int size;
	    cin >> size;
	    Node* head = NULL;
	    Node* start = NULL;
	    for(int i=0; i<size; ++i) {
	        int val;
	        cin >> val;
	        if(head == NULL) {
	            head = new Node(val);
	            start = head;
	        } else {
	            head->next = new Node(val);
	            head = head->next;
	        }
	    }
	    Node* res = print_even_odd(start);
	    while(res) {
	        cout << res->val << " ";
	        res = res->next;
	    }
	    cout << endl;
	}
	return 0;
}