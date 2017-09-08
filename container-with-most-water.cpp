/*
https://leetcode.com/problems/container-with-most-water/description/

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()<2) return 0;
        int size = height.size();
        int start = 0;
        int end = size-1;
        int res=0, area = 0;
        int mini=0;
        while(start<end) {
            mini = min(height[start],height[end]);
            area = (end-start)*mini;
            res = max(area,res);
            if(height[start]>height[end]) end--;
            else start++;
        }
        return res;
        
    }
};
