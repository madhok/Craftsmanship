/*
You are given two numbers A and B. Write a program to count number of bits needed to be flipped to convert A to B.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is a and b.

Output:

Print the number of bits needed to be flipped.

Constraints:

1 ≤ T ≤ 100
1 ≤ a,b ≤ 1000

Example:

Example:
Input
1
10 20

Output
4
 

Explanation:

A  = 1001001
B  = 0010101
No of bits need to flipped = set bit count i.e. 4
*/

#include <iostream>

using namespace std;

int get_last_bit (int a) {
    return a&0x1;
}
int bit_difference(int a, int b) {
    if(a == b) return 0;
    int count = 0;
    while(a || b) {
        if(get_last_bit(a) != get_last_bit(b)){
            count++;
        } 
        a = a >> 1;
        b = b >> 1;
    }
    return count;
}

int main() {
	//code
	int n ;
	cin >> n;
	while(n) {
	    n--;
	    int a, b;
	    cin >> a;
	    cin >> b;
	    cout << bit_difference(a,b);
	}
	return 0;
}