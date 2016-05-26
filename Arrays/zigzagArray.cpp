/*

Problem Description:
Given an array of distinct elements, rearrange the elements of array in zig-zag fashion in O(n) time. The converted array should be in form a < b > c < d > e < f.The relative order of elements is same in the output i.e you have to iterate on the original array only.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the size of array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the array in Zig-Zag fashion.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100
0 ≤A[i]<=10000

Example:
Input:
2
7
4 3 7 8 6 2 1
4
1 4 3 2
Output:
3 7 4 8 2 6 1
1 4 2 3

*/

#include <iostream>
using namespace std;

void print_array(int* A, int size) {
    for(int i = 0; i< size; ++i) {
        cout << A[i] << " ";
    }
}

void convert_zigzag(int *A, int size) {
    int flag =true;
    for(int i = 0; i <=size-2; ++i) {
        if(flag) {
            if(A[i] > A[i+1])
                swap(A[i],A[i+1]);
        } else{
            if(A[i] < A[i+1])
                swap(A[i],A[i+1]);
        }
        flag = !flag;
    }
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
	    convert_zigzag(A, size);
	    print_array(A, size); 
	    cout << endl;
	}
	return 0;
}