/*
Given an array of integers, every element appears twice except for one. Find that single one in linear time complexity and without using extra memory.

 

Input:

The first line of input consists number of the test cases. The description of T test cases is as follows:

The first line of each test case contains the size of the array, and the second line has the elements of the array.

 


Output:

In each separate line print the number that appears only once in the array.


Constraints:

1 ≤ T ≤ 70
1 ≤ N ≤ 100
0 ≤ A[i] ≤ 100000


Example:

Input:

1
11
1 2 4 3 3 2 5 6 1 6 5

Output:

4


*/
#include <iostream>
using namespace std;

int single_element(int* A, int size) {
    if(size ==0) return -1;
    if(size == 1) return A[0];
    int ret = A[0];
    for(int i=1;i<size;++i) {
        ret = ret^A[i];
    }
    return ret;
} 

int main() {
	//code
	int n;
	cin>>n;
	while(n) {
	    n--;
	    int size;
	    cin >> size;
	    int A[size];
	    for(int i=0; i<size;++i) {
	        int val;
	        cin >>val;
	        A[i] = val;
	    }
	    cout << single_element(A,size) << endl;
	}
	return 0;
}