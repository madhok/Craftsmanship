//Find the longest common substring

#include <iostream>


using namespace std;

string getLongestCommonSubstring(string str1, string str2)
{
	int array[str1.length()+1][str2.length()+1];
	for(int i = 0; i<str1.length()+1;i++)
	{	
		for(int j = 0; j<str2.length()+1;j++)
			array[i][j] = 0;
	}
	int longest = 0;
	string commonstring;
	for(int i = 0; i < str1.length(); i++)
	{
		for(int j = 0; j < str2.length(); j++)
		{
			if(str1[i] == str2[j])
			{
				array[i+1][j+1] = array[i][j] + 1;
			}
			if(array[i+1][j+1] > longest)
			{
				longest = array[i+1][j+1];
				commonstring = str1.substr(i-array[i][j],i+1);
				
			}
		}	
	}
	cout << "longest:" << longest << endl;
	for(int i = 0; i<str1.length()+1;i++)
	{	
		for(int j = 0; j<str2.length()+1;j++)
			cout << array[i][j]<< "\t";
		cout << endl;
	}
	return commonstring;
}

int main()
{
	cout << getLongestCommonSubstring("Indianapolis", "IndiaIndianapolis");
}