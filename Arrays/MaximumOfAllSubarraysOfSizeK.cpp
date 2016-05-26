/*
Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer 'N' denoting the size of array and the size of subarray 'k'.
The second line contains 'N' space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the maximum for every subarray of size k.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100
1 ≤ k ≤ N
0 ≤A[i]<1000

Example:

Input:
2
9 3
1 2 3 1 4 5 2 3 6
10 4
8 5 10 7 9 4 15 12 90 13

Output:
3 3 4 5 5 5 6
10 10 10 15 15 90 90

*/
#include <iostream>
using namespace std;

void print_max_subarray(int *A, int size, int k) {
    int *max;
    max = new int[size-k+1];
    int j = 0;
    max[j] = A[0];
    for(int i = 1; i<k; ++i) {
        if(A[i] > max[j]){
            max[j] = A[i];
        }
    }
    j++;
    for(int i = k;i<size;++i) {
        if(A[i]>max[j-1]) {
            max[j] = A[i];
        } else {
            max[j] = max[j-1];
        }
        j++;
    }
    
    for(int i = 0; i <=size-k; ++i) {
        cout << max[i] << " ";
    }
    cout << endl;
}

int main() {
	int n;
    cin >> n;
    while(n) {
        n--;
        int size,k;
        cin >> size;
        cin >> k;
        int* A;
        A = new int[size];
        for(int i = 0; i <size; ++i) {
            int val;
            cin >> val;
            A[i] = val;
        }
        print_max_subarray(A,size,k);
    }
    
    return 0;
}