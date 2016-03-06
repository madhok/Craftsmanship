class Solution {
public:
    int max(int a, int b) {
         return a>b?a:b;
    }
    int min(int a, int b) {
        return a>b?b:a;
    }
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        
        int localmax = nums[0];
        int globalmax = nums[0];
        int localmin = nums[0];
        for(int i = 1; i< nums.size(); ++i ) {
            int temp = localmax;
            localmax = max(max(nums[i]*localmax, nums[i]), nums[i]*localmin);
            localmin = min(min(nums[i]*temp, nums[i]), nums[i]*localmin);
            globalmax = max(globalmax,localmax);
        }
        return globalmax;
    }
};
