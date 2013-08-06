#include <iostream>

using namespace std;

int getlength(string line)
{
	int startIndex =0;
	

	if(line.length() == 0)
	{
		return 0;
	}
	int runIndex = line.length()-1;
	while(line[runIndex] == ' ')
	{
		runIndex--;
	}
	startIndex = runIndex;
	for(; runIndex >=0; runIndex--)
	{

		if(line[runIndex] == ' ')
			break;
	}
	return startIndex - runIndex;

	
}

int main()
{

	cout << getlength("sdasdsa");
	return 0;
}