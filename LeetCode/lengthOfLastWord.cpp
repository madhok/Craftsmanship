/*Length of Last WordMar 27 '12
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s[0] == '\0')
            return 0;
        bool wordFound = false;
        int count = 0;
        int i = 0;
        int length = 0;
        while(s[i] != '\0')
        {
            count = 0;
            while(s[i] != '\0' && s[i++] != ' ')
            {
               count++;                                   
            }
            if(count != 0)
                length = count;
        }
        return length;
        
    }
};