Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.



class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int len = s.length();
        if(len <= 1)
            return 0;
        
        int cutIndex = 0;
        int endIndex = len;
        int minCuts = 0;
       

            while(cutIndex < len)
            {
                string sub = s.substr(cutIndex, (endIndex -cutIndex));
                if(isPalindrome(sub))
                {

                 
                    cutIndex = endIndex;
                    endIndex = len;
                    if(cutIndex == len)
                        return minCuts;
                    minCuts++;
                    
                
                }
                else
                {
                    endIndex--;
                }
            }



        return minCuts;

        
        
    }
    
    bool isPalindrome(string str)
    {
        int endIndex = str.length() - 1;
        int startIndex = 0;
        
        while(startIndex < endIndex)
        {
            if(str[startIndex]  != str[endIndex])
                return false;
            startIndex++;
            endIndex--;
        }
        
        return true;
    }
};