/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
MS Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc. In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA”.

Input:

The first line of each input consists of the test cases. And, the second line consists of a number N.

Output:

In each separate line print the corresonding column title as it appears in an Excel sheet.

Constraints:

1 ≤ T ≤ 70
1 ≤ N ≤ 4294967295

Example:

Input:

2
28
13

Output:

AB
M

*/
#include <iostream>
#include <stack>
using namespace std;

string get_char(int val) {
    if(val == 0) return "Z";
    char s = 'A' + val-1;
    string str(1,s);
    return str;
}


string get_value(unsigned int val) {
    if(val < 27) return get_char(val);
    string ret = "";
    stack<string> stk;
    while(val) {
        int dig = val%26;
        if(dig == 0) {
            val = val/26 -1;
        } else {
         val = val/26;   
        }
        stk.push(get_char(dig));
    }
    while(!stk.empty()) {
        ret += stk.top();
        stk.pop();
    }
    return ret;
}

int main() {
    //code
    int n;
    cin >> n;
    while(n) {
        n--;
        unsigned int val;
        cin >> val;
        cout << get_value(val) << endl;
    }
    return 0;
}