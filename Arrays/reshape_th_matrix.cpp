/*
In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Example 1:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
Output: 
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
Example 2:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 2, c = 4
Output: 
[[1,2],
 [3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.

*/

class Solution {
public:
    int getval(vector<vector<int> > nums, int &index) {
        if(nums.size() == 0) return -1;
        int rows = nums.size();
        int cols = nums[0].size();
        int i = index/cols;
        int j = index%cols;
        return nums[i][j];
    }
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.size() ==0) return nums;
        int row = nums.size();
        int col = nums[0].size();
        
        if(row*col != r*c) return nums;
        
        vector<vector<int>>result;
        int index =0;
        for(int i = 0; i < r; ++i) {
            vector<int> row;
            for(int j = 0;j<c;++j) {
                int val = getval(nums,index);
                row.push_back(val);
                index++;
            }
            result.push_back(row);
        }
        return result;
    }
};
