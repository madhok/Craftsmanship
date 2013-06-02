#include <iostream>


int main()
{

}


int hash(string s)
{
	int h = 0;
	for(int i = 0; i < s.length(); i++)
	{
		h = 31 * h + s[i]
	}
	return h % N; // N = Total nuber of words
}