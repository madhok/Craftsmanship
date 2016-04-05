// Example program
/*
Just append the reverse of initial substrings of the string, 
from shortest to longest, to the string until you have a palindrome. 
e.g., for "acbab", try appending "a" which yields "acbaba", which is 
not a palindrome, then try appending "ac" reversed, yielding "acbabca"
 which is a palindrome.

Update: Note that you don't have to actually do the append. 
You know that the substring matches since you just reversed it. 
So all you have to do is check whether the remainder of the string
 is a palindrome, and if so append the reverse of the substring. 
 Which is what Ptival wrote symbolically, so he should probably 
 get the credit for the answer. Example: for "acbab", find the 
 longest suffix that is a palindrome; that is "bab". Then append 
 the remainder, "ac", in reverse: ac bab ca.
*/

#include <iostream>
#include <string>

using namespace std;

string reverse (string input) {
    int len = input.length();
    if(len == 0) return input;
    string result ="";
    while(len>0) {
        result = result + input[len-1];
        len--;
    }
    return result;
}

string shortest_palindrome(string input) {
    int len = input.length();
    string result = "";
    if(len == 0) return result;
    
    string rev_inp = reverse(input);
    //cout << rev_inp;
    int start = 0;
    int end = len-1;
    for(;start<end;end--) {
        if(rev_inp[start] == rev_inp[end]) {
            start++;
        } else {
            start = 0;
        }
    }
    result = rev_inp.substr(start+end+1);
    return result;
}

int main()
{
    string input = "cabab";
    cout << shortest_palindrome(input);
}
