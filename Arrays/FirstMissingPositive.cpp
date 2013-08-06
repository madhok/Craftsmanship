  /*
  Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
  Using Map
  */
  //Uses O(2n) space
  
   int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(n == 0)
            return 1;
            
        map<int,bool>MissingNumber;
        
        for(int i = 1; i <= n + 1; i++)
        {
            MissingNumber.insert(pair<int,bool>(i,false));
        }
        
        for(int i = 0; i < n; i++)
        {
            MissingNumber[A[i]] = true;
        }
        
        for(int i = 1; i <= n+1; i++)
        {
            if(MissingNumber[i] == false)
                return i;
        }
    }