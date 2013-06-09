/*
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "*") ? true
isMatch("aa", "a*") ? true
isMatch("ab", "?*") ? true
isMatch("aab", "c*a*b") ? false



*/
//Dosest work for larger numbers.. below works for large numbers
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(*s == '\0')
        {
            if(*p == '\0') return true;
            if(*p == '*') return isMatch(s,p+1);
            return false;
        }
        
        if(*p == '\0') return false;
        if(*s == *p || *p == '?') return isMatch(s+1, p+1);
        if(*p == '*') return (isMatch(s, p+1) || isMatch(s+1, p));
        return false;
    }
};

//Works for large  numbers too

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const char *ps, *pp;
        bool star = false;
        loopStart:
        for (ps = s, pp = p; *ps; ++ps, ++pp) {
            switch (*pp) {
            case '?':
                break;
            case '*':
                star = true;
                s = ps, p = pp+1;
                if (!*p) return true;
                goto loopStart;
            default:
                if (*ps != *pp)
                    goto starCheck;
                break;
            }
        }
        while (*pp == '*') ++pp;
        return (!*pp);
        starCheck:
        if (!star) return false;
        s++;
        goto loopStart;
        return false;
    }
};