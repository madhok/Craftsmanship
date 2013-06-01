#include <iostream>

using namespace std;

bool IsPowerOf2(int num)
{
	if((num & (num-1)) == 0)
		return true;
	return false;
}

int nextPowOf2(int num)
{
	num--;
	num |= (num >> 1);
	num |= (num >> 2);
	num |= (num >> 4);
	num |= (num >> 8);
	num |= (num >> 16);
	num++;
	return num;
}

int main()
{
	if(IsPowerOf2(32))
		cout << "32 is power of 2"<< endl;
	else
		cout << "I am wrong" << endl;

	cout << "Next power of 2 of 5 is " << nextPowOf2(5) << endl;

	return 0;
}


