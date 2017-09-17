/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*/
class Solution {
public:
    int binarysearch(vector<int>& nums, int start, int end, int target) {
        if(start > end) return -1;
        int mid = (start+end)/2;
        if(nums[start] == target) return start;
        else if(nums[end] == target) return end;
        else if(nums[mid] == target) {
            return mid;
        } else if(nums[mid] > target) {
            return binarysearch(nums, start+1, mid-1, target);
        } 
        return binarysearch(nums, mid+1, end-1, target);
    }
    int search(vector<int>& nums, int start, int end, int target) {
        if(start > end) return -1;
        int mid = (start +end)/2;
        if(nums[mid] == target ) return mid;
        
        if(target > nums[start] && target < nums[mid] && nums[start] < nums[mid]) {
            //cout << "first one";
            return binarysearch(nums, start, mid-1, target);
        } else if(target < nums[end] && target > nums[mid] && nums[mid] < nums[end]) {
            //cout << "second one";
            return binarysearch(nums, mid-1, end, target);
        } else {
            //cout << "Not in binary";
            if(nums[start] == target) {
                return start;
            } else if(nums[end] == target) {
                return end;
            } else {
                return search(nums, start+1, end-1, target);
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int start = 0;
        int end = nums.size()-1;
        return search(nums, start, end, target);
    }
};
