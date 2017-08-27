/*
Leetcode: https://leetcode.com/problems/reverse-string-ii/description/

Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
*/

class Solution {
public:
    void swap(char &a, char &b) {
        char tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    string reverse(string s) {
        int start = 0;
        int end = s.length()-1;
        while(start < end) {
            swap(s[start],s[end]);
            start++;
            end--;
        }
        return s;
    }
    string reverseStr(string s, int k) {
        if(k < 2) return s;
        
        int cur_end_k = 2*k;
        int start = 0;
        while(start < s.length()) {
            string pre = s.substr(0,start);
            if((start+k) >= s.length()) {
                string sub = s.substr(start);
                s = pre+ reverse(sub);
                break;
            } 
            string sub = s.substr(start,k);    
            string ret = pre+ reverse(sub) + s.substr(start+k,s.length()-1);
            s = ret;
            start = cur_end_k;
            cur_end_k += 2*k;
        }
        return s;
    }
};
