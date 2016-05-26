/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int size = nums.size();
        vector<int> result;
        if(size <3) {
            return nums;
        }
        int res = nums[0];
        for(int i = 1; i <size; ++i) {
            res ^= nums[i];
        }
        int first_bit_pos =0;
        int tmp = res;
        int i = 0;
        while(tmp) {
            if(tmp & 0x01)  {
                first_bit_pos = i;
                break;
            }
            i++;
            tmp = tmp >>1;
        }
        int first=0,second =0;
        for(int i = 0; i < size; ++i) {
            if((nums[i] >> first_bit_pos) & 1 ==1) {
                first ^=nums[i];
            } else {
                second ^=nums[i];
            }
        }
        result.push_back(first);
        result.push_back(second);
        return result;
    }
};