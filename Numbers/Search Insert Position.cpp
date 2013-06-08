/*
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

*/

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(target >A[n-1])
            return n;
        if(target <= A[0])
            return 0;
        return searchHelper(A,0, n-1, target);
        
    }
    
    int searchHelper(int A[], int startIndex, int endIndex, int target)
    {
        int mid = startIndex + (endIndex - startIndex)/2;
        
        if(A[mid] == target)
            return mid;
            
        if(startIndex < endIndex)
        {
            if(A[startIndex] == target)
                return startIndex;
            if(A[endIndex] == target)
                return endIndex;
            else
            {
                if(target < A[mid])
                   return searchHelper(A,startIndex, mid -1, target);
                else if(target > A[mid])
                   return searchHelper(A,mid+1, endIndex, target);
            }
        }
       if(target < A[mid])
            return mid;
        else
            return mid + 1;
    }
};