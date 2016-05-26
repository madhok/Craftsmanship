/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.
*/

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num==0) return false;
        
        while(num) {
            if(num == 1) return true;
            if(num%4 !=0) return false;
            num = num/4;
        }
        return true;
    }
};