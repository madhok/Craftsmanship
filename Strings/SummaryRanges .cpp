/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

*/

class Solution {
public:
    string createrange(int start,int end) {
        string ret;
        if(start == end) {
            ret = std::to_string(start);
            return ret;
        }
        ret = std::to_string(start);
        ret += "->";
        ret += std::to_string(end);
        return ret;
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>result;
        if(nums.size() == 0) return result;
        if(nums.size() == 1) {
            result.push_back(std::to_string(nums[0]));
            return result;
        }
        int start = nums[0];
        int end = nums[0];
        bool pushed = false;
        for(int i = 1; i <nums.size(); i++) {
            if(nums[i] == nums[i-1] +1) {
                end = nums[i];
                continue;
            }
            pushed = true;
            result.push_back(createrange(start,end));
            start = nums[i];
            end = nums[i];
            pushed = false;
        }
        if(pushed ==false)
            result.push_back(createrange(start,end));
        return result;
    }
};
