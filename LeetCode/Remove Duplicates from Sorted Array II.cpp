/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].

*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
     if(n == 0)
        return 0;
    
    int maxAllowed = 1;
    int runningIndex = 1;
    int currPos = 0;
    for(;runningIndex < n ; runningIndex++)
    {
        if(A[runningIndex] == A[currPos])
        {
            if(maxAllowed > 0)
            {
                maxAllowed--;
                currPos++;
                A[currPos] = A[runningIndex];
            }
        }
        else
        {
            currPos++;
            A[currPos] = A[runningIndex];
            maxAllowed = 1;
        }
    }
    return currPos + 1;
    
    }
};