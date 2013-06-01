/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.

*/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int na= m-1;
        int nb = n-1;
        
        for(int i = m +n -1; i >= 0; i--)
        {
            if(na >= 0 && nb >= 0)
            {
            if(A[na] > B[nb])
                A[i] = A[na--];
            else
                A[i] = B[nb--];    
            }
            else if(nb >= 0 )
            {
                A[i] = B[nb--];
            }
            else
            {
                A[i] = A[na--];
            }
            
            
        }
        return;
    }
};