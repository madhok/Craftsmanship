/*
Problem Statement

Suppose you have a string S which has length N and is indexed from 0 to N−1. String R is the reverse of the string S. The string S is funny if the condition |Si−Si−1|=|Ri−Ri−1| is true for every i from 1 to N−1.

(Note: Given a string str, stri denotes the ascii value of the ith character (0-indexed) of str. |x| denotes the absolute value of an integer x)

Input Format

First line of the input will contain an integer T. T testcases follow. Each of the next T lines contains one string S.

Constraints

1<=T<=10
2<=length of S<=10000
Output Format

For each string, print Funny or Not Funny in separate lines.

Sample Input

2
acxz
bcxz
Sample Output

Funny
Not Funny
Explanation

Consider the 1st testcase acxz

here

|c-a| = |x-z| = 2
|x-c| = |c-x| = 21
|z-x| = |a-c| = 2
Hence Funny.

Consider the 2st testcase bcxz

here

|c-b| != |x-z|
Hence Not Funny.

*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

std::string reverse(string str) {
    if(str.length() < 2) return str;
    int end = str.length()-1;
    string rev;
    while(end >=0) {
        rev += str[end];
        end--;
    }
    return rev;   
}
int val(char c1, char c2) {
    return abs(c1 -c2);
}
bool checkFunny(string str, string rev_str) {
    if(str.length() < 2) return true;
    for(int i = 1; i<str.length(); i++) {
        if(val(str[i],str[i-1]) != val(rev_str[i],rev_str[i-1]))
            return false;
    }
    return true;
}

int main() {    
    int n =0;
    cin >> n;  
    vector<bool> results;
    for(int i = 0; i < n; i++) {
        string input;
        cin >> input;
        string rev_input = reverse(input);
        bool isFunny = checkFunny(input, rev_input);
        results.push_back(isFunny);    
    }
    for(int i = 0; i < n; i++) {
        bool isFunny = results[i];
        if(isFunny) cout << "Funny" << endl;
        else cout << "Not Funny" << endl;   
    }
    return 0;
}
