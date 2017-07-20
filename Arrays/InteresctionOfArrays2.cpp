/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to num2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> result;
        if(size2 == 0 || size1==0) return result;
        map<int,int> indexes;
        for(int i=0;i<size1;++i) {
            if(indexes.find(nums1[i]) != indexes.end()) {
                indexes[nums1[i]]++;
            } else {
                indexes[nums1[i]] =1;
            }
        }
        
        for(int i=0;i<size2;++i) {
            if(indexes.find(nums2[i]) != indexes.end()) {
                if(indexes[nums2[i]] == 0) {
                    continue;
                } 
                indexes[nums2[i]]--;
                result.push_back(nums2[i]);
            }
        }
        
        return result;
    }
};