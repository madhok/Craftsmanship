Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]


class Solution {
public:
    vector<vector<string>> partition(string s) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string>>palindromes;
        vector<string> output;
        DFS(s,0,output,palindromes);
        return palindromes;
    }
    
     void DFS(string &s, int start, vector<string>& output, vector<vector<string>> &result)  
     {      
            if(start == s.size())  
            {  
                 result.push_back(output);  
                 return;  
            }  
            for(int i = start; i< s.size(); i++)  
            {    
                 if(isPalindrome(s, start, i))  
                 {  
                      output.push_back(s.substr(start, i-start+1));  
                      DFS(s, i+1, output, result);  
                      output.pop_back();  
                 }  
            }  
     }
    
    bool isPalindrome(string s, int startIndex, int endIndex)
    {
        //int startIndex = 0;
        //int endIndex = s.length() -1;
        
        while(startIndex < endIndex)
        {
            if(s[startIndex++] != s[endIndex--])
            {
                return false;
            }
        }
        return true;
    }
};