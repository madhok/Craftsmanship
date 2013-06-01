/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

*/

class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0)
        {
            return false;
        }
        return searchHelper(A,0, n-1, target);
        
    }
    
    bool searchHelper(int A[], int start, int end, int target)
    {
        if(start > end)
            return false;
        
        if(start == end && A[start] != target)
            return false;
        
        if(A[end] < A[start])
        {
            int middle = (start + end)/2;
            if(target == A[start] || target == A[end] || target == A[middle])
            {
                return true;
            }
            else
            {
                if(target > A[middle] && target < A[end])
                {
                    searchHelper(A,middle+1,end-1,target);
                }
                else if(target < A[middle] && target > A[start])
                {
                    searchHelper(A,start+1, middle-1,target);
                }
           //     else if(target > A[middle] && target > A[end])   //Cannot do this if duplicated are allowed
        //        {
          //          searchHelper(A,middle+1,end-1,target);
        //        }
           //     else if(target < A[middle] && target < A[start])
            //        searchHelper(A,middle+1,end,target);
                else
                    searchHelper(A,start+1,end-1,target);
            }
        }
        else if(A[end] > A[start])
        {
            int middle = (start + end)/2;
            if(target == A[middle])
                return true;
            else if(target > A[middle])
            {
                searchHelper(A, middle +1, end, target);
            }
            else if(target < A[middle])
            {
                searchHelper(A, start, middle-1,target);
            }
        }
        else
        {
            if(target == A[start] || target == A[end])
                return true;
            else 
                searchHelper(A, start+1, end-1,target);
        }
    }
};