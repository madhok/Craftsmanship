#include "iostream"
#include "string.h"
using namespace std;

int abs(int num)
{
	if(num < 0)
	{
		num = -num;		
	}
	return num;
}
void getzigzagpattern(char* input, int rows, int len)
{
	string result[rows];
	int dividend = 0;
	for(int i = 0; i < len; i++)
	{
		int n = 0;			
		cout << dividend;
		dividend = (i/rows) + rows - 2;
		result[abs(i%rows - dividend)] += input[i];
		
	} 
	for(int j =0; j < rows ; j++)
	{
		cout << result[j] << endl;
	}
}

int main()
{
	getzigzagpattern("madhokha", 3, 8);	
}




