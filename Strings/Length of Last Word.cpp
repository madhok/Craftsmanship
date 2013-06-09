/*
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
       if(*s == NULL)
        return 0;
       int index = 0;
       int lastword = 0;
       
       while(s[index] == ' ')
        index++;
       
       if(s[index] == '\0')
        return 0;
       
       while(s[index] != '\0')
       {
           if(s[index] == ' ')
           {
               while(s[index] == ' ')
                {
                    index++;
                }
                if(s[index] != '\0')
                    lastword = 1; 
                else if(s[index] == '\0')
                    return lastword;
           }  
          else
            lastword++;
         index++;
         
       }
       
       return lastword;
       
    }
};