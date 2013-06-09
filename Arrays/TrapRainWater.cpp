/*
Given n non-negative integers representing an elevation map 
where the width of each bar is 1, compute how much water it 
is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.



The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped. 
Thanks Marcos for contributing this image!
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