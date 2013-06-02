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