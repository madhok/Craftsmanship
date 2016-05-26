/*
Problem Description:
Given an integer array, you need to find the two elements such that their sum is closest to zero.
 
Input:
The first line of input contains an integer T denoting the number of test cases.  
The first line of each test case is N,the size of array
Each test case consist of a N integers which are the array elements.
 
Output:
Print the two numbers in ascending order such that their sum is closest to zero.
 
Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000
-100007 ≤ a[i] ≤ 100007
 
Example:
Input
3
3
-8 -66 -60  
6
-21 -67 -37 -18 4 -65  
2
-24 -73  
 
Output
-60 -8
-18 4
-73 -24
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_nums(vector<int> A) {
    int size = A.size();
    if(size < 2) return;
    sort(A.begin(),A.end());
    int min_l=0,min_r=size-1;
    int si=0, ei=size-1;
    int min =A[si];
    int max = A[ei];
    int minsum = A[ei] +A[si];
    while(si<ei) {
        int sum = A[si] + A[ei];
        if(abs(minsum) > abs(sum)) {
            minsum = sum;
            min_l = si;
            min_r =ei;
        } 
        if (sum <0){
            si++;
        } else {
            ei--;
        }
    }
    cout << A[min_l] << " " << A[min_r];
}

int main() {
	//code
	int n;
	cin >>n;
	while(n) {
	    n--;
	    int size;
	    cin >> size;
	    vector<int> v;
	    for(int i = 0; i<size; ++i) {
	        int val;
	        cin >>val;
	        v.push_back(val);
	    }
	    print_nums(v);
	    cout << endl;
	}
	return 0;
}