/*
Given an array with all elements greater than or equal to zero.Return the maximum product of two numbers possible.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N, N is size of array.
The second line of each test case contains N input A[i].

Output:

Print the maximum product of two numbers possible.

Constraints:

1 ≤ T ≤ 20
1 ≤ N ≤ 50
0 ≤ A[i] ≤ 1000

Example:

Input
1
5
1 100 42 4 23

Output
4200

*/

#include <iostream>
using namespace std;

void print_max_product(int A[], int size) {
    int max1 = A[0]>A[1]?A[0]:A[1];
    int max2 = A[0]<A[1]?A[0]:A[1];
    for(int i = 2; i < size; ++i) {
        if(A[i] > max2) {
            int new_max1 = A[i]>max1?A[i]:max1;
            max2 = A[i]<max1?A[i]:max1;
            max1= new_max1;
        }
    }
    cout << max1*max2 << endl;
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
	    for(int i = 0; i < size; ++i) {
	        int val;
	        cin >> val;
	        A[i] = val;
	    }
	    print_max_product(A,size);
	}

	return 0;
}