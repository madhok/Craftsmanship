/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/



class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0)
            return 0;
        if(n == 1)
            return A[0];
        
        int maxSum = A[0];
        int currentSum = A[0];
        
        for(int i = 1; i < n; i++)
        {
          
          currentSum = max(A[i], A[i]+ currentSum);
          if(currentSum > maxSum)
            maxSum = currentSum;
            
        }
        
        return maxSum;
    }
};



#include <iostream>

using namespace std;


int maxSubArray(vector<int> input)
{
	if(input.size() == 0)
		return 0;

	int maxSumTillHere = input[0];
	int maxSum = input[0];

	for(int i = 1; i < input.size(); i++)
	{
		if(maxSum < 0)
			maxSumTillHere = input[i];
		else
			maxSumTillHere += input[i];

		if(maxSum <= maxSumTillHere)
			maxSum = maxSumTillHere;	 
	}
	return maxSum;	
}