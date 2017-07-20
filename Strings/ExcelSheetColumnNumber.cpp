/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 

*/
class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        int ret=0;
        
        //BAC = B *26*26 + A*26 + C
       for(int i = 0; i< len;++i) {
            ret*=26;
            ret += s[i]-'A' +1;
        }
        return ret;
    }
};