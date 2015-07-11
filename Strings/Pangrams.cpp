/*
Problem Statement

Roy wanted to increase his typing speed for programming contests. So, his friend advised him to type the sentence "The quick brown fox jumps over the lazy dog" repeatedly, because it is a pangram. (Pangrams are sentences constructed by using every letter of the alphabet at least once.)

After typing the sentence several times, Roy became bored with it. So he started to look for other pangrams.

Given a sentence s, tell Roy if it is a pangram or not.

Input Format Input consists of a line containing s.

Constraints 
Length of s can be at most 103 (1≤|s|≤103) and it may contain spaces, lower case and upper case letters. Lower case and upper case instances of a letter are considered the same.

Output Format Output a line containing pangram if s is a pangram, otherwise output not pangram.

Sample Input #1

We promptly judged antique ivory buckles for the next prize    
Sample Output #1

pangram
Sample Input #2

We promptly judged antique ivory buckles for the prize    
Sample Output #2

not pangram
Explanation 
In the first test case, the answer is pangram because the sentence contains all the letters of the English alphabet.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <string>
using namespace std;

int getval(char c) {
    if(c >= 'A' && c <= 'Z')
        return (c - 'A');
    if(c >= 'a' && c <='z')
        return c-'a';
    return -1;
}

bool checkPangram(string str) {
    if(str.length() < 26) return false;
    vector<bool> characters(26,false);
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ') continue;
        int val = getval(str[i]); 
        if(val>25) return false;
        if(val <0) return false;
        characters[val] = true;
    }
    for(int i = 0; i < 26; i++) {
        if(characters[i] == false) 
            return false;
    }
    return true;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string input;
    getline(cin,input);
    if(input.length() > 1000) return 0;
    bool ispangram = checkPangram(input);
    if(ispangram) cout << "pangram" << endl;
    else cout << "not pangram" << endl;
    return 0;
}
