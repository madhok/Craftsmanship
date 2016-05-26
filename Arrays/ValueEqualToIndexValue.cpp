/*
Given an array, we need to find that element whose value is equal to that of its index value.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the size of array.
The second line of each test case contains N input A[].

Output:

Print that element whose value is equal to index value. Print "Not Found" when index value does not match with value.
Note: There can be more than one element in the array which have same value as their index. You need to print every such element's index separated by a single space.

Constraints:

1 ≤ T ≤ 30
1 ≤ N ≤ 50
1 ≤ A[i] ≤ 1000

Example:

Input
2
5
15 2 45 12 7
1
1

Output
2
1
 
*/

#include <iostream>
using namespace std;

void print_index_matched(int A[], int size) {
for(int i = 0; i< size; ++i) {
    if(i+1 == A[i]) {
        cout << A[i] << " ";
    }    
}
cout << endl;
}

int main() {
	//code
	int n;
	cin >> n;
	while(n) {
	    n--;
	    int size;
	    cin >> size;
	    int A[size];
	    for(int i = 0; i< size; ++i) {
	        int val;
	        cin >> val;
	        A[i] = val; 
	    }
	    print_index_matched(A,size);
	}
	return 0;
}