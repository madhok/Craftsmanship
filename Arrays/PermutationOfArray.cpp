/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int size = nums.size();
        if(size == 0) return result;
        if(size == 1) {
            result.push_back(nums);
            return result;
        }
        int start = 0, end= size-1;
        helper(nums,start,end,result);
        //result.push_back(nums);
        /*for(int i = 0; i<size; ++i) {
            start = i;
            while(start <= end) {
                swap(nums[start],nums[i]);
                result.push_back(nums);
                swap(nums[start],nums[i]);
                start++;
            }
        }*/ 
        return result;
    }
    
    void helper(vector<int>& nums, int start, int end, vector<vector<int> >& result) {
        if(start == end) {
            result.push_back(nums);
            return;
        }
        
        for(int i = start; i<= end; ++i) {
            swap(nums[start], nums[i]);
            helper(nums, start+1, end,result);
            swap(nums[start], nums[i]);
        }
    }
    
    void swap(int&a, int& b) {
        int temp;
        temp = a;
        a = b;
        b =temp;
    }
};