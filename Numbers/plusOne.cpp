/*
Given a number represented as an array of digits, plus one to the number.

*/


class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(digits.size() == 0)
            return digits;
        
        int last = digits.size() -1;
        int carry =1;
        while(carry >0)
        {
            digits[last] += carry;
            if(digits[last] > 9)
            {
                digits[last] = digits[last]%10;
                carry = 1;
                last--;
                if(last ==-1)
                {
                    digits.insert(digits.begin(), carry);
                    break;
                }
                    
            }
            else
                carry = 0;
        }
        return digits;
    }
};