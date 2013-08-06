/*
Determine whether an integer is a palindrome. Do this without extra space.
*/
class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
     if(x < 0)
        return false;
     if(x < 10)
        return true;
     int rev = 0;
     int val = x;
     while(val > 0)
     {
         rev = rev * 10 + val%10;
         val = val/10;
     }
     if (rev == x)
        return true;
    return false;    
    }
};