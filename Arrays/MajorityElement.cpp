/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() ==0) return -1;
        int result = 0; int count = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            if(count == 0) {
                result = nums[i];
                count++;
            }
            else if(result == nums[i]) count++;
            else count--;
        }
        return result;
    }
};
