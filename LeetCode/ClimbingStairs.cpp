/*

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

*/

class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ways = 0;
        if(n < 2)
            return n;
        if(n == 2)
            return 2;
        else
            return climbStairs(n-1) + climbStairs(n-2);
        
    }
};