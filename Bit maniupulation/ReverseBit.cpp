//Reverse bit

#include <iostream>
#include <iomanip>

using namespace std;
unsigned int reversebit(unsigned int num)
{
	int result = 0;
	int NO_OF_BITS = sizeof(num) * 8;

	for(int i = 0; i< NO_OF_BITS; i++)
	{
		if(num & (1<< i))  // Shift the bit to the next bit in the num and check
		{
			result |= (1<< (NO_OF_BITS -1- i));
		}
	}
	return result;
}

int main()
{
	
	cout << hex << reversebit(1);
}