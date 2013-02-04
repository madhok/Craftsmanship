class LeetCode {
public:

/* Question Merge Sorted Array
Given two sorted integer arrays A and B, merge B into A as one sorted array.
Note:You may assume that A has enough space 
to hold additional elements from B. The number 
of elements initialized in A and B are m and n respectively*/

  void merge(int A[], int m, int B[], int n) 
  {
    int ia = m -1;
    int ib = n -1;
    int index = m + n - 1;
    while(ia>= 0 && ib >=0)
    {
      if(B[ib] >= A[ia])
         A[index--] = B[ib--];                
      else
         A[index--] = A[ia--];            
      }
      while(ib >= 0)
        A[index--] = B[ib--];            
    }
    
    
    /* Median of two Sorted Arrays
    There are two sorted arrays A and B of size m and n respectively. 
    Find the median of the two sorted arrays. 
    The overall run time complexity should be O(log (m+n)).
    NOT-WORKING
    */
    
    
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
     int mA,mB;
     
     if(m == 0)
        return getMedian(B,n);
     if(n == 0)    
        return getMedian(A,m);
        
     mA = getMedian(A,m);
     mB = getMedian(B,n);
     
     if(mA > mB)
     {
         findMedianSortedArrays(getArray(A, 0, m/2 + 1), m/2 + 1 ,getArray(B, n/2 - 1, n), n/2 + 1);
     }
     else if(mB > mA)
     {
         findMedianSortedArrays(getArray(A, m/2 - 1, m), m/2 + 1,  getArray(B, 0, n/2 + 1), n/2 + 1);
     }
     return mA;
     
    }
    
    double getMedian(int Array[], int n)
    {
        if(n == 1)
            return Array[n-1];            
        else if(n%2 == 1)
            return Array[(n-1)/2];
        else
            return (Array[(n-1)/2] + Array[(n+1)/2])/2;            
    }
    
    int* getArray(int A[], int startval, int endval)
    {
        int length = endval - startval;
        int temp[endval - startval];
        
        for(int i = 0; i <= length; i++)
        {
            temp[i] = A[startval];
            startval++;
        }
        return temp;
    }  
};