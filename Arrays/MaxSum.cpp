/*
Given an array of positive numbers, find the maximum sum of a subsequence with the constraint that no 2 numbers in the sequence should be adjacent in the array. So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7).

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the size of array.
The second line of each test case contains N input C[i].

Output:

Print the maximum sum of a subsequence.

Constraints:

1 ≤ T ≤ 80
1 ≤ N ≤ 100
1 ≤ C[i] ≤ 500

Example:

Input:
2
6
5 5 10 100 10 5
4
3 2 7 10

Output:
110
13
*/

#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
    return a>b?a:b;
} 
int maxSum(vector<int> input) {
  int size = input.size();
  if(size == 0) return 0;
  int incl = input[0];
  int excl = 0;
  int excl_new = 0;
  for(int i = 1; i < size; ++i) {
      excl_new = max(incl, excl);
      incl = excl + input[i];
      excl = excl_new;
  }
  return max(incl,excl);
}

int main() {
	//code
	int n;
	cin >> n;
	while(n) {
	    vector<int> input;
	    int size;
	    cin >> size;
	    for(int i = 0; i< size; ++i) {
	      int val;
	      cin >>val;
	      input.push_back(val);
	    }
	    cout << maxSum(input) << endl;
	    n--;
	}
	
	return 0;
}