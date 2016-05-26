/*
Given a string ‘str’, check if it can be constructed by taking a substring of it 
and appending multiple copies of the substring together.  For example "abab" 
can be created by appending "ab" to "ab", but "abac" cannot be created by 
appending a substring to itself.    
*/
#include <iostream>
#include <string>

using namespace std;

bool helper(string input, string s) {
    int substring_len = s.length();
    int len = input.length();
    if(len%substring_len != 0) return false;
    int mul = len/substring_len;
    string new_s = "";
    while(mul) {
        mul--;
        new_s +=s;
    }
    if(new_s == input) return true;
    return false;
    
}

bool can_form(string input) {
    int size = input.size();
    if(size == 0) return false;
    for(int i = 1; i <= size/2; ++i) {
        string substring = input.substr(0,i);
        
        if(helper(input,substring)) return true;
    }
    return false;
} 

int main() {
	//code
	if(can_form("abab")) {
	    cout << "True" << endl;
	}
	else {
	    cout << "False" << endl;
	}
	return 0;
}