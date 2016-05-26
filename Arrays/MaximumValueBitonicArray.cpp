/*
Given an array of elements which is first increasing and then decreasing, find the maximum element in the array.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N, the size of array
The second line of each test case contains N integers which are the array elements.

Output:

Print the maximum element in the array.


Constraints:

1 ≤ T ≤ 50
3 ≤ N ≤ 100
1 ≤ a[i] ≤ 100000


Example:

Input
2
9
1 15 25 45 42 21 17 12 11
5
1 45 47 50 5

Output
45
50
*/
#include <iostream>
using namespace std;

int helper(int* A, int start,int end) {
    if(end < start) return -1;
    int mid = start +(end-start)/2;
    if(A[mid] > A[mid-1] &&
       A[mid] > A[mid+1]) {
           return A[mid];
       }
    else if(A[mid+1] > A[mid]) {
        return helper(A,mid+1,end);
    } else if(A[mid-1] > A[mid]) {
        return helper(A,start,mid-1);
    }
}
int maximum(int *A,int size) {
    if(size == 0) return -1;
    if(size ==1) return A[0];
    
    return helper(A,0,size-1);
}

int main() {
	//code
	int n;
	cin >>n;
	while(n) {
	    n--;
	    int size;
	    cin >> size;
	    int A[size];
	    for(int i=0;i<size;++i) {
	        int val;
	        cin >>val;
	        A[i] = val;
	    }
	    cout << maximum(A,size) << endl;
	}
	return 0;
}
