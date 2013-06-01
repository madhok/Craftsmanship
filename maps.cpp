#include <iostream>
#include <map>

using namespace std;
int main()
{

	cout << "Testing map" << endl;
	string t;
	map<string, int> M;
	map<string,int>::iterator it;
	string s[5] = {"The", "The", "aoo", "asdad", "asdad"};
	for(int i =0; i<5 ; i++)
	{
		M[s[i]]++;
	}
	for(it = M.begin(); it != M.end(); it++)
	{ 
		cout << it->first << "-" << it->second << endl;
	}
	return 0;
}