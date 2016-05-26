/*
Given an unsorted array that may contain duplicates. Also given a number k which is smaller than size of array. Write a function that returns true if array contains duplicates within k distance.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is K and N,K is the distance and N is the size of array.
The second line of each test case contains N input A[].

Output:

Print True if array contains duplicates within k distance else False

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 100
1 ≤ K ≤ N
1 ≤ A[] ≤ 1000

Example:

Input:
4
3 8
1 2 3 4 1 2 3 4
3 6
1 2 3 1 4 5
3 5
1 2 3 4 5
3 5
1 2 3 4 4

Output:
False
True
False
True
*/
#include <iostream>
using namespace std;

bool duplicate(int A[], int size, int k) {
    for(int i = 0;i < size; ++i) {
        for(int j = i+1; j < size && j <= i+k; ++j) {
            if(A[i] == A[j]) return true;
        }
    }
    return false;
}

int main() {
	int n;
	cin >> n;
	while(n) {
	    n--;
	    int k;
	    cin >> k;
	    int size;
	    cin >> size;
	    int A[size];
	    for(int i = 0; i< size; ++i) {
	        int val;
	        cin >> val;
	        A[i] = val;
	    }
	    cout << duplicate(A,size,k) << endl;
	}
	return 0;
}