/*
Given an array of integers, sort the array into a wave like array and return it. 
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

Example

Given [1, 2, 3, 4]

One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]
 NOTE : If there are multiple answers possible, return the one thats lexicographically smallest. 

 

Input:

The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N depicting the size of square matrix and next line followed by the value of array.


Output:

Print the array into wave like array.


Constraints:

1 ≤ T ≤ 30
1 ≤ N ≤ 100
0 ≤ A[i] ≤ 100

Example:

Input
1
5
5 7 3 2 8
Output
3 2 7 5 8
*/

#include <iostream>
#include <algorithm>
using namespace std;

void print_array(vector<int> input) {
    for(int i =0; i <input.size(); ++i) {
        cout << input[i] << " ";
    }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

vector<int> to_wave(vector<int> input) {
    sort(input.begin(),input.end());
    for(int i =0; i+1<input.size(); i = i+2) {
        swap(input[i],input[i+1]);
    }
    return input;
}


int main() {
	//code
	int n;
	cin >> n;
	while(n--) {
	   vector<int> input;
	   int size;
	   cin >> size;
	   while(size--) {
	       int val;
	       cin >> val;
	       input.push_back(val);
	   }
	   print_array(to_wave(input));
	}
	return 0;
}