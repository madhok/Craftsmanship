 // O(m+n/2) - >keep incrementing the pointer2(starting from the start of wach array) untill u reach the medain of both.
 double findMedianSortedArrays(int A[], int m, int B[], int n) {
//        return findMedianSortedArrays1(A, m, B, n);
        return findMedianSortedArrays1(A, m, B, n);
    }

    double findMedianSortedArrays1(int A[], int m, int B[], int n) {
        int i = 0, j = 0;
        int m1 = -1, m2 = -1;
        int s = (m + n) / 2;
        while (s >= 0) {
            int a = (i < m) ? A[i] : INT_MAX;
            int b = (j < n) ? B[j] : INT_MAX;
            m1 = m2;
            if (a < b) {
                m2 = a;
                i++;
            }
            else {
                m2 = b;
                j++;
            }
            s--;
        }
        if ((m + n) % 2 == 0) return (m1 + m2) / 2.0;
        return m2;
    };

//Binary search way

class Merge {
public:

    
    //Median with log(min(m,n))
    double findMedianSortedArrays2(int A[], int m, int B[], int n) {
        return findMedianHelper2(A, m, B, n, max(0, (m-n)/2), min(m-1, (m+n)/2));
    };

    double findMedianHelper2(const int A[], const int m, const int B[], const int n, const int l, const int r) {
        if (l > r) return findMedianHelper2(B, n, A, m, max(0, (n-m)/2), min(n-1, (m+n)/2));
        int i = (l+r)/2;
        int j = (m+n)/2-i;

        assert(i >= 0 && i <= m && j >= 0 && j <= n);
        int Ai_1 = ((i == 0) ? INT_MIN : A[i-1]);
        int Bj_1 = ((j == 0) ? INT_MIN : B[j-1]);
        int Ai = ((i == m) ? INT_MAX : A[i]);
        int Bj = ((j == n) ? INT_MAX : B[j]);

        if (Ai < Bj_1) return findMedianHelper2(A, m, B, n, i+1, r);
        if (Ai > Bj) return findMedianHelper2(A, m, B, n, l, i-1);

        if (((m+n) % 2) == 1) return A[i];
        return (max(Ai_1, Bj_1) + Ai) / 2.0;
    };



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