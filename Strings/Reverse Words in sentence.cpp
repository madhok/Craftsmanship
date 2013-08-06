#include <iostream>

using namespace std;

void swap(char &A, char &B)
{
	char temp;
	temp = A;
	A= B;
	B= temp;
}

void reverse(string &str, int start, int end)
{
	if(end-start < 1)
	{
		return;
	}
	int len = (end-start);
	while(start < end)
	{
		swap(str[start++], str[end--]);	
	}
	return;
}


int main()
{
	string input = "Hello World"; 

	reverse(input, 0, input.length()-1);
	for(int i =0; i<input.length(); i++)
	{
		int start = i;
		int end = i;
		while(input[i] != ' ' && i < input.length())
		{
			end++;
			i++;
		}
		end--;
		reverse(input, start, end);
	}
	cout << input;

	return 0;
}