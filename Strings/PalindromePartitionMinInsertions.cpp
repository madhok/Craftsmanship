/*
Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is S.

Output:

Print the minimum number of characters.

*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int min(int a, int b) {
    return a>b?b:a;
}

int min_partitions(string s, int l, int h) {
    if(l >h) return INT_MAX;
    if(l==h) return 0;
    if(l == h-1) {
        return s[l]==s[h]?0:1;
    }
    
    return s[l]==s[h]?min_partitions(s,l+1,h-1):min(min_partitions(s,l,h-1),min_partitions(s,l+1,h)) +1;
}

int main() {
	//code
	string s = "abcd";
	cout << min_partitions(s,0,s.length()-1);
}
