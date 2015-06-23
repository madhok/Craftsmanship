/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).

*/
class Solution {
public:
    int reverse(int x) {
        bool isneg = false;
        int val = x;
        if(x == INT_MIN) return 0;
        if(x < 0) {
            isneg = true;
            val = x * -1;
        }
        if(val < 10) return x;
        double retval = 0;
        while(val > 0) {
            int temp = val%10;
            retval = retval*10 + temp;
            val = val/10;
        }
        
        if(retval >= INT_MAX) {
            return 0;
        }
        if(isneg) {
            retval = retval * -1;
        }
        return retval;
    }
};
