/*
Write a function to find the longest common prefix string amongst an array of strings.

*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        string prefix = strs[0];
        for(int i = 1; i < strs.size(); i++) {
            if(prefix.length() > strs[i].length()) {
                prefix = strs[i];
            }
        }
        
        for(int i = 0; i < strs.size(); i++) {
            for(int j = 0; j < min(prefix.length(), strs[i].length()); j++) {
                if(prefix[j] != strs[i][j]) {
                    prefix = prefix.substr(0,j);
                }    
            }
        }
        return prefix;
    }
};
//Another solution same complexity
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       string result;
       if(strs.size() == 0)
        return result;
       vector<string>::iterator it;
       result = strs[0];
       for(it = strs.begin() + 1; it != strs.end(); it++)
       {
           result = getcommon(*it, result);
       }
       return result;
    }
    
    string getcommon(string str, string result)
    {
        if(str.length() == 0)
            return "";
        string ret;
        for(int i = 0; i < str.length() || i < result.length(); i++)
        {
            if(str[i] != result[i])
                return ret;
            ret += str[i];    
        }
        return ret;
    }
};
