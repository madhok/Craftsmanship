/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].


*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 0 || nums.size()==1) {
            return;
        }
        if(k > nums.size()) k = k%nums.size();
        int split = nums.size() - k;
        reverse(nums, 0, split-1);
        reverse(nums, split, nums.size()-1);
        reverse(nums,0, nums.size()-1);
        return;
    }
    void reverse(std::vector<int>&nums, int start, int end){
        while(start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};
