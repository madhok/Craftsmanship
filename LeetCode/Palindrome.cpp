/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/
#include <iostream>

using namespace std;

class Solution1 
{
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.length() == 0 || s.length() == 1)
            return true;
              
        int i = 0, j = s.length() -1;      
        while(i < j)
        {
            
            if(!isAlphaNumeric(s.at(i)))
            {
                i++;
                continue;
            }
            
            if(!isAlphaNumeric(s.at(j)))
            {
               j--;
               continue;
            }
              
            if(tolower(s.at(i)) != tolower(s.at(j)))
            {
                return false;
            } 
            i++;
            j--;
        }
        return true;
    }
    
bool isAlphaNumeric(char c)
{
    int asciival;
    asciival = (int) c;
    if((asciival >= 65 && asciival <= 90) || (asciival >= 48 && asciival <= 57)
        || (asciival >= 48 && asciival <= 57) || (asciival >= 97 && asciival <= 122))
    {
        return true;
    }
    return false;
}

char tolower(char c)
{
    int asciival = (int) c;
    if(asciival >=65 && asciival <= 90)
    {
        asciival += 32;
        return (char) asciival;
    }
    return c;
}
};