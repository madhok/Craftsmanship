/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
*/


class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int nR =0;
        int nW = 0;
        int nB = 0;
        int i = 0;
        for(i = 0; i< n; i++)
        {   
            if(A[i] == 0)
                nR++;
            if(A[i] == 1)
                nW++;
            if(A[i] == 2)
                nB++;
        }
        i = 0;
        while(i < nR)
        {
            A[i++] = 0;
        }
        while(i < nR + nW)
        {
            A[i++] = 1;
        }
        while(i < nR + nW + nB)
        {
            A[i++] = 2;
        }
    }
};