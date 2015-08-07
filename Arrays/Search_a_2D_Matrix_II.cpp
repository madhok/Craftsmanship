/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows == 0) return false;
        int cols = matrix[0].size();
        if(target > matrix[rows-1][cols-1]) return false;
        
        for(int i = 0; i < rows; ++i) {
            if(target > matrix[i][cols-1]) {
                continue;
            }
            if(binary_search(matrix[i], 0, cols-1, target))
                return true;
        }
        return false;
    }
    
    bool binary_search(vector<int>& row, int start, int end, int target) {
        if(start>end ) return false;
        if(target < row[start]) return false;
        if(target == row[start]) return true;
        if(target == row[end]) return true;
        
        int mid = start + (end -start)/2;
        if(target == row[mid]) return true;
        if(target < row[mid]) {
            return binary_search(row, start+1, mid-1,target);    
        }else if(target > row[mid]) {
            return binary_search(row, mid+1, end-1,target);    
        }
        return false;
    }
};
