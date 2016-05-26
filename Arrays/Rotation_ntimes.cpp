/*
Given a sorted array which is rotated 'N' times. Find the value of 'N'.
 

Input:

The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N depicting the size of array and next line followed by the value of array.


Output:

Print the value of 'n'.


Constraints:

1 ≤ T ≤ 40
1 ≤ N ≤ 100
0 ≤ A[i] ≤ 100


Example:

Input
2
5
5 1 2 3 4
5
1 2 3 4 5

Output
1
0

*/
#include <iostream>
using namespace std;

int n_rotation(int* A, int size) {
    if(size == 0) return 0;
    int prev = A[0];
    int ncount=0;
    for(int i=1;i<size;++i) {
        if(prev>A[i]) {
            ncount =i;
        }
        prev = A[i];
    }
    return ncount;
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
	    for(int i = 0;i<size;++i) {
	        int val;
	        cin>>val;
	        A[i] = val;
	    }
	    cout << n_rotation(A, size) << endl;
	}
	return 0;
}