/*
Write a function to find the longest common prefix string amongst an array of strings.

*/

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