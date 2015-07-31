/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int size = digits.size();
        int carry = 1;
        for(int i = size-1; i>=0; i--) {
            int a = digits[i] + carry;
            carry = a/10;
            a = a%10;
            result.push_back(a);
        }
        if(carry) result.push_back(carry);
        reverse(result.begin(), result.end());
        return result;
    }
};
