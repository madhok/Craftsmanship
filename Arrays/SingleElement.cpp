/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

*/
 int singleNumber(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return -1;
        if(size  < 2) return nums[0];
        
        int result = 0;
        for(int i = 0; i < 32; i++) {
            int sum = 0;
            int x = 1 << i;
            for(int j = 0; j <size; j++) {
                if(nums[j] & x)
                    sum++;
            }
            if(sum%3)
                result |= x;
        }
        return result;
    }
    
int getSingle(int arr[], int n)
{
	// Initialize result
	int result = 0;

	int x, sum;
    
	// Iterate through every bit
	for (int i = 0; i < INT_SIZE; i++)
	{
	// Find sum of set bits at ith position in all
	// array elements
	sum = 0;
	x = (1 << i);
	for (int j=0; j< n; j++ )
	{
		if (arr[j] & x)
			sum++;
	}

	// The bits with sum not multiple of 3, are the
	// bits of element with single occurrence.
	if (sum % 3)
		result |= x;
	}

	return result;
}
