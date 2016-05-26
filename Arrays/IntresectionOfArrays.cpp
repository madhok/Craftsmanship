/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.

*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int size1 = nums1.size();
        int size2 = nums2.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(int i = 0,j=0;i<size1&& j<size2;) {
            int val = nums1[i];
            if(nums1[i] ==nums2[j]) {
                result.push_back(nums1[i]);
                while(nums1[i] == val) i++;
                while(nums2[j] == val)j++;
            } else if(nums1[i]>nums2[j]) {
                j++;
            } else {
                i++;
            }
            if(j==size2) return result;
        }
        return result;
        
    }
};