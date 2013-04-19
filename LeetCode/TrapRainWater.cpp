/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/
class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0 || n == 1)
            return 0;
        int max = INT_MIN;
        vector<int>forward; 
        for(int currentNumber = 0; currentNumber < n ; currentNumber++)
        {
            if(A[currentNumber] > max)
            {
                max = A[currentNumber];
            }
            forward.push_back(max - A[currentNumber]);   
        }
        vector<int>backward; 
        max = INT_MIN;
        for(int currentNumber = n-1; currentNumber >= 0; currentNumber--)
        {
            if(A[currentNumber] > max)
            {
                max = A[currentNumber];
            }            
            backward.push_back(max - A[currentNumber]);   
        }
        
        int size = 0;
        for(int i = 0; i < n; i++)
        {
            size += min(forward[i], backward[n-i-1]); 
        }
        
        return size;
    }
};