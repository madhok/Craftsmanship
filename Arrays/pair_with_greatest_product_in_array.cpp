/*
http://practice.geeksforgeeks.org/problems/pair-with-greatest-product-in-array/0

Given an array of n elements, the task is to find the greatest number such that it is product of two elements of given array. If no such element exists, print -1. 

Input :  A[] = {10, 3, 5, 30, 35}
Output:  30
Explanation: 30 is the product of 10 and 3.

Input :  A[] = {2, 5, 7, 8}
Output:  -1
Explanation: Since, no such element exists.

Input :  A[] = {10, 2, 4, 30, 35}
Output:  -1

Input :  A[] = {10, 2, 2, 4, 30, 35}
Output:  4

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer n denoting size of the array. Then in the next line are n space separated values of the array.

Output:
For each test case in a new line print the required output.

Constraints:
1<=T<=100
1<=n<=100
1<=A[]<=100

Example:
Input:
2
4
2 5 7 8
6
10 2 2 4 30 35

Output:
-1
4

**For More Examples Use Expected Output**


*/

#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int prodpair(vector<int>arr) {
    sort(arr.begin(),arr.end());
    /*for(int i = 0;i<arr.size();++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;*/
    for(int j = arr.size()-1;j>=0;--j) {
        for(int i = j; i>0;--i) {
            for(int k = i-1;k>=0;--k) {
                if(arr[j] == arr[i]*arr[k])
                    return arr[j];    
            }
        }
    }
    return -1;
}


int main()
 {
	 int n;
     cin >> n;
     while(n>0) {
         n--;
         int size;
         cin >>size;
         vector<int> arr;
         for(int i =0;i<size;++i) {
             int val;
             cin>>val;
             arr.push_back(val);
         }
         cout << prodpair(arr) << endl;
     }
	return 0;
}
