class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() < 4) return result;
        
        std::sort(nums.begin(),nums.end());
        int len = nums.size();
        for(int x1 = 0; x1 < len; ++x1) {
            for(int x2 = x1+1; x2 < len; ++x2) {
                int x3 = x2+1, x4 = len-1;
                while(x3<x4) {
                   if(nums[x1] + nums[x2] + nums[x3] + nums[x4] == target) {
                        vector<int> arr;
                        arr.push_back(nums[x1]);
                        arr.push_back(nums[x2]);
                        arr.push_back(nums[x3]);
                        arr.push_back(nums[x4]);
                        result.push_back(arr);
                         x3++;
                        x4--;
                    } else if(nums[x1] + nums[x2] + nums[x3] + nums[x4] > target) {
                        x4--;
                    } else if(nums[x1] + nums[x2] + nums[x3] + nums[x4] < target) {
                        x3++;
                    }
                }
               
            }
        }
        for(int i = 0; i  < result.size(); ++i) {
            for(int j = i+1; j < result.size(); ++j) {
                if(result[i] == result[j]) {
                    result.erase(result.begin()+j);
                    --j;
                }
            }
        }
        return result;
    }
};
