/*
https://leetcode.com/problems/reverse-words-in-a-string-iii/#/description
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/

class Solution {
public:
    string reverseWords(string s) {
        if(s.length() <2) return s;
        vector<string> vect_strs;
        string ret = reverse(s);
        //cout << ret << endl;
        for(int i = 0; i <ret.length(); ++i) {
            int start = i;
            int len = 0;
            while(i <= ret.length()-1 && ret[i] != ' ') {
                len++;
                i++;
            }
            //cout << "start " << start << endl;
            //cout << "len " << len << endl;
            vect_strs.push_back(ret.substr(start,len));
             i = start + len;
        }
        string final;
        int i;
        
        for(i=vect_strs.size()-1;i>0;--i) {
            final += vect_strs[i];
            final += " ";
        }
        final += vect_strs[0];
        return final;
    }
    
    string reverse(string s) {
        string rev;
        for(int i = s.length()-1; i >=0; --i) {
            rev += s[i];
        }
        return rev;
    }
};
