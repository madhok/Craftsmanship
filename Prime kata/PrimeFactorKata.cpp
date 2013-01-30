#include <iostream>
#include <vector>

using namespace std;

class PrimeFactorKata
{
	public:
	static bool isNumberPrime(int Number);
	static vector<int> generate(int Number)
	{
		
		int nPrimeNumber = 2;
		vector<int> nPrimeValues;
		while(Number >= nPrimeNumber)
		{
			if(Number % nPrimeNumber == 0 && PrimeFactorKata::isNumberPrime(nPrimeNumber))
			{	
				nPrimeValues.push_back(nPrimeNumber);
			}
			nPrimeNumber++;
		}
	return nPrimeValues;
	}
};

bool PrimeFactorKata::isNumberPrime(int Number)
{

	for(int i = 2; i <= Number/2; i++)
	{
		if (Number % i == 0)
		{
			return false;
		}
	}		
	return true;
}

int main()
{
	//PrimeFactorKata obj;
	int Number;
	cout << "Enter the number for which you want the prime factors " << endl;
	cin >> Number;

	vector<int> result = PrimeFactorKata::generate(Number);
	cout << "The prime factors of " << Number << " are : " ;
	for(int i = 0; i < result.size() - 1; i++)
	{
		cout << result[i] << ",";
	}
	cout << result[result.size() - 1] << endl;
	
	return 0;
}

