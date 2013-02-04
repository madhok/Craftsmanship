#include <iostream>
#include <vector>
using namespace std;

bool test(vector<int> sample, int weight);

vector<int> getStoneWeights(int nMaxWeight)
{
	vector<int> vWeights;
	if (nMaxWeight <= 0)
	{
		return vWeights;
	}
	int nSumOfWeightsPresent = 0;
	
	for(int nWeight = 1; nWeight <= nMaxWeight; nWeight++)
	{
	if(nWeight > nSumOfWeightsPresent)
		{
			vWeights.push_back(nWeight + nSumOfWeightsPresent);
			nSumOfWeightsPresent += vWeights.at(vWeights.size() -1); // previous weight in the list			
		}
	}
	return vWeights;	
}

int main()
{
	vector<int> sample;
	int weight;
	cout << "whats the weight of the stone?" << endl;
	cin >> weight;
	sample = getStoneWeights(weight);
	cout << "The smaller stone weights are " << endl;
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