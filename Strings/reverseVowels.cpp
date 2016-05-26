/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

*/
class Solution {
public:
    bool isvowel(char c) {
        c = tolower(c);
        if(c == 'a' || c =='e'
          || c == 'i' || c =='o'
          || c == 'u') return true;
          return false;
    }
    void swap(char& a, char& b) {
        char tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    string reverseVowels(string s) {
        int size = s.length();
        if(size <2) return s;
        
        int start = 0;
        int end = size-1;
        while(start < end)  {
            while(start < end && !isvowel(s[start])) start++;
            while(start < end && !isvowel(s[end])) end--;
            if(start>end) return s;
            else {
                swap(s[start],s[end]);
                start++;
                end--;
            }
        }
        return s;
    }
};