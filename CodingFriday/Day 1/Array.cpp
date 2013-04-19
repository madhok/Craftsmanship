#include <iostream>
#include <vector>
using namespace std;

void LargestSumArray(int* input, int size)
{
	
	int result[size];
	int sum = input[0];
	int index = 0;
	bool flag = false;
	int lengthofArray = 0;
	//get the sum of all the elements of the array
	for(int i = 1; i<= size;i++)	
	{
		sum = input[i-1];
		result[index] = input[i];
		index++;
		for(int j = i; j<=size; j--)
		{
			if((sum + input[j]) > sum)
			{
				sum += input[j];
				result[index] = input[j];
				index++;
				lengthofArray ++; 
			}
			else
			{
				if(lengthofArray > index)
				{
					flag = true;
				}
				break;
			}
		}
		if(!flag)
		{
		sum = 0;
		for (int n = 0; n< index; n++)
		{
			result[index] = 0;					
		}
		index = 0;
		flag =false;
		}				
	}	
	for (int n = 0; n< index; n++)
	{
		cout << result[index];
	}		
}

void getLargeArray(vector<int>input)
{
	//int maxsum = input;
	int sum = input.at(0);
	int startindex = 0;
	int endindex = 0;
	int maxsum = 0;
	for(int i = 1; i < input.size();i++)
	{
		if(input.at(i) + sum > 0) //add the new element to sum if greater than 0
		{
			sum += input.at(i);
			
		}
		else if(input.at(i) > sum) 
		{
			sum = input.at(i);	
			startindex = i;					
		}
		if(maxsum < sum)
		{
			maxsum = sum;			
			endindex = i;
		}
		if(maxsum < input.at(i))
		{
			startindex = i;
		}
	}
	if(startindex > endindex)
	{
		endindex = input.size();
	}	
	for(int j = startindex; j<=endindex; j++)
	{
		cout << input.at(j) << endl;
	}
}

int main()
{
	vector<int> sample(7);
	sample.at(0) = -5;
	sample.at(1) = 3;
	sample.at(2) = 6;
	sample.at(3) = -1;
	sample.at(4) = 9;
	sample.at(5) = 8;
	sample.at(6) = 1;
		
	getLargeArray(sample);
	return 0;
}