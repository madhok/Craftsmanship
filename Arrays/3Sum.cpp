/*
https://leetcode.com/problems/3sum/description/

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]


*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() <3) return res;
        sort(nums.begin(),nums.end());
        int size = nums.size();
        for(int i1 =0;i1<size-2;++i1) {
            if(i1>0 && nums[i1]==nums[i1-1]) continue;
            int start = i1+1;
            int end = size-1;
            while(start<end) {
                if(nums[i1] + nums[start]+ nums[end] == 0) {
                    vector<int> cur_res;
                    cur_res.push_back(nums[i1]);
                    cur_res.push_back(nums[start]);
                    cur_res.push_back(nums[end]);
                    res.push_back(cur_res);
                    start++;
                    end--;
                    while(nums[start] == nums[start-1]) start++;
                    while(nums[end] == nums[end+1]) end--;
                } else if(nums[i1] + nums[start]+ nums[end] > 0) {
                    end--;
                } else {
                    start++;
                }
            }
        }
        return res;
    }
};
