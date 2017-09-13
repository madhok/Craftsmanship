/*
https://leetcode.com/problems/maximum-swap/description/

Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 108]

*/
class Solution {
public:
    void swap(vector<int>& digits, int x, int y) {
        int tmp = digits[x];
        digits[x] = digits[y];
        digits[y] = tmp;
    }
    int digits_to_num(vector<int>& digits) {
        int ret = digits[0];
        int index =1;
        while(index <digits.size()) {
            ret = ret *10 + digits[index];
            index++;
        }
        return ret;
    }
    int get_cur_max(vector<int> digits,int cur_index) {
        if (cur_index >=digits.size()) return -1;
        int cur_max = cur_index;
        cur_index++;
        while(cur_index < digits.size()) {
            if(digits[cur_max] <= digits[cur_index]) cur_max = cur_index;
            
            cur_index++;
        }
        //cout << digits[cur_max] << endl;
        return cur_max;
    }
    int maximumSwap(int num) {
        if(num< 10) return num;
        vector<int>digits;
        int temp = num;
        while(temp>0 ) {
            int val = temp%10;
            temp = temp/10;
            digits.push_back(val);
        }
        reverse(digits.begin(),digits.end());
        int cur_index = 0;
        while(cur_index < digits.size()) {
            int tnum = get_cur_max(digits,cur_index+1);
            if(tnum == -1) {
                return num;
            }
            if(digits[tnum] > digits[cur_index]) {
                swap(digits,cur_index,tnum);
                return digits_to_num(digits);
            }
            cur_index++;
        }
        return num;
    }
};
