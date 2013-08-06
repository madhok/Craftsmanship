/*
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxlength = 0;
        
        if(s.length() < 2)
            return s.length();
        
        vector<char> myvector; 
        std::vector<char>::iterator it;   
        for(int i =0; i < s.length(); i++)
        {
            it = find(myvector.begin(), myvector.end(), s[i]);
            if(it == myvector.end())
            {
                myvector.push_back(s[i]);
            }
            else
            {
                if(maxlength < myvector.size())
                    maxlength = myvector.size();
                myvector.erase(myvector.begin(), it);
                myvector.erase(myvector.begin());
                myvector.push_back(s[i]);
            }
            
        }
        if(maxlength < myvector.size())
            maxlength = myvector.size();
        return maxlength;
    }
};