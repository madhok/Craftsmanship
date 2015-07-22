/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.


*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        
        return minhelper(nums, 0, size-1);
    }
    
    int minhelper(vector<int>& nums, int start, int end) {
        if(start > end) return -1;
        int mid = start + (end -start) /2;
        if(mid == start) {
            return nums[start]>nums[end] ? nums[end]:nums[start];
        }
        /*if(nums[mid] < nums[mid-1] &&
            nums[mid] < nums[mid+1]) {
                return nums[mid];
            }*/
        if(mid > start && nums[mid] < nums[mid-1]) {
            return nums[mid];
        }
        if(mid > end && nums[mid] > nums[mid+1]) {
            return nums[mid];
        }
        if(nums[mid] > nums[end])
            return minhelper(nums,mid+1,end);
        return minhelper(nums,start, mid-1);    
    }
};
