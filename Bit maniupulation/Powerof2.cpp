/*
Given an integer, write a function to determine if it is a power of two.

*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        
        while(n >0) {
            if(n& 0x1) {
              n= n >>1;
              break;
            }
            n = n >>1;
        }
        if(n>0) return false;
        return true;
    }
};
