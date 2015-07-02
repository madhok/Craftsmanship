
/*Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

// Every multiplt of 5 will get you a zero. like 5, 10,15,... So count the numbers which can be divided by 5 and that is the result.
class Solution {
public:
    int trailingZeroes(int n) {
        if(n < 0) return -1;
        if(n == 0) return 0;
        int count = 0;
        for(long i = 5; n/i >=1; i*=5) {
            count +=n/i;
        }
        return count;
    }
};
