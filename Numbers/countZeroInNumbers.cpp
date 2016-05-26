/*
Given a number d, representing the number of digits of a number. Find the total count of positive integers which have at-least one zero in them and consist d or less digits.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is D,D is number of digits.

Output:

Print the total count of positive integers which have at-least one zero in them.

Constraints:

1 ≤ T ≤ 15
1 ≤ N ≤ 15

Example:

Input:
2
2
3

Output:
9
180

**For More Examples Use Expected Output**
*/

#include <iostream>

using namespace std;

int has0(int val) {
    if(val == 0) return 0;
    while(val) {
        if(val%10 ==0) return 1;
        val = val/10;
    }
    return 0;
}
int count_0(int val) {
    int count = 0;
    if(val == 0) return 0;
    for(int i = 1; i <= val; ++i) {
        count +=has0(i);
    }
    return count;
}
int getmaxNum(int digits) {
    if(digits == 0) return 0;
    int ret = 1;
    while(digits) {
        ret = ret*10;
        digits--;
    }
    return ret-1;
}
int main() {
	//code
	int n;
	cin >> n;
	while(n) {
	    n--;
	    int digit;
	    cin >> digit;
	    int number = getmaxNum(digit);
	    //cout << number << endl;
	    cout << count_0(number) << endl;
	}
	return 0;
}