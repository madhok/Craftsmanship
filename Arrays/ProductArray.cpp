/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/
//Constatn space and O(n) solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     double res =1;
     
     int size = nums.size();
     vector<int> result(size);
     if(size ==0 ) return result;
     result[size-1] = 1;
     for(int i =size-2; i >=0; i--) {
         result[i] = result[i+1] * nums[i+1];
     }
     int left = 1; 
     for(int i =0; i <size; i++) {
         result[i] = result[i] * left;
         left = left * nums[i];
     }
     return result;
    }
};