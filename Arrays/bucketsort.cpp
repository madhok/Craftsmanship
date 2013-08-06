#include <iostream>
#include <utility>
#include <vector>

using namespace std;


void sort(pair<int,string>array [], int size)
{

	vector<string>bucket[size];

	for(int i= 0; i<size; i++)
	{
		bucket[array[i].first].push_back(array[i].second);
	}

	int index = 0;

	for(int i = 0; i < size; i++)
	{
		vector<string> strings = bucket[i];
		for(int j =0; j< strings.size(); j++)
		{
			array[index].first = i;
			array[index++].second = strings[j];
		}
	}
}


int main()
{
	cout << "Enter the size of the hash map" << endl;
	int size = 5; 
	
	pair<int, string> *array = new pair<int, string>[size];
	for(int i = 0; i < size; i++)
	{
		string value;
		int key;

		cout << "Key : ";
		cin >> key;	

		cout << "String : ";
		cin >> value;

		array[i] = make_pair (key,value);

	}

	sort(array,size);
	for(int i = 0; i<size; i++)
	{
		cout << "Key: " << array[i].first << "/t";
		cout << "string: " << array[i].second << endl;
	}
	return 0;
}