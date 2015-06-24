/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool set_first_row_zero = false;
        bool set_first_col_zero = false;
        
        
        for(int i = 0; i < matrix[0].size(); i++) {
            if(matrix[0][i] == 0) {
                set_first_row_zero = true;
            }
        }
         for(int i = 0; i < matrix.size(); i++) {
            if(matrix[i][0] == 0) {
                set_first_col_zero = true;
            }
        }
        
        for(int row = 1; row <matrix.size();row++) {
            for(int col = 1; col <matrix[0].size();col++) {
                if(matrix[row][col] == 0) {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }
        for(int row = 1; row < matrix.size(); row++){
            for(int col = 1; col < matrix[0].size(); col++) {
                if(matrix[row][0] == 0 || matrix[0][col] == 0) {
                    matrix[row][col] = 0;
                }
            }
        }
        if(set_first_row_zero) {
            for(int col = 0; col < matrix[0].size(); col++) {
                matrix[0][col] = 0;
            }
        }
        
        if(set_first_col_zero) {
            for(int row = 0; row < matrix.size(); row++) {
                matrix[row][0] = 0;
            }
        }
        
    }
};
