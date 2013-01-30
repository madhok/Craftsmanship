#include <iostream>
#include <vector>
using namespace std;

bool test(vector<int> sample, int weight);

vector<int> getNumbers(int maxweight)
{
	vector<int> result;
	if (maxweight <= 0)
	{
		return result;
	}
	int nSumofNumbersPresent;
	int count = 0;
	
	nSumofNumbersPresent = 0;
	
	for(int nNumberneeded = 1; nNumberneeded <= maxweight; nNumberneeded++)
	{
	if(nNumberneeded > nSumofNumbersPresent)
		{
			count++;
			result.resize(count);
			result.at(count - 1) = nNumberneeded + nSumofNumbersPresent;
			nSumofNumbersPresent += result.at(count -1);			
		}
	}
	return result;	
}

int main()
{
	vector<int> sample;
	int weight;
	cout << "whats your max weight" << endl;
	cin >> weight;
	sample = getNumbers(weight);
	cout << "The numbers are " << endl;
	if(sample.empty())
	{
		cout << "Empty array" << endl;
	}
	for(int i = 0; i < sample.size(); i++)
	{
		cout << sample.at(i) << endl;
	}
	
	// testing	
/*	cout << "tests :";
	if(test(sample, weight) == 1)
	{
		cout << "passed" << endl;
	}
	else
	{
		cout << "failed" << endl;
	}
*/	
}

bool test(vector<int> sample, int weight)
{
int multiplier[3] = {1,-1,0,};
bool ret = false;
int resultval;
	for(int i = 1; i <= weight; i++)
	{	
		//check if the number can be formed from given values	
		for(int nMultiplier = 0 ; nMultiplier < 3; nMultiplier++)
		{
			for(int nMultiplier1 = 0 ; nMultiplier1 < 3; nMultiplier1++)
			{
				for(int nMultiplier2 = 0 ; nMultiplier2 < 3; nMultiplier2++)
				{
					for(int nMultiplier3 = 0 ; nMultiplier3 < 3; nMultiplier3++)
					{
						resultval = sample.at(3) * multiplier[nMultiplier] +
									 sample.at(2) * multiplier[nMultiplier1] +
									sample.at(1) * multiplier[nMultiplier2] +
									sample.at(0) * multiplier[nMultiplier3];						
						
						if(i == resultval)
						{
							ret = true;
						}
					}					
				}
			}
		}
		
		if(ret == false)
		{
			cout <<  "Failed at number:  " << i;
			return ret; 
		}
		if(i < weight)
			ret = false;
	}
	return ret;
}