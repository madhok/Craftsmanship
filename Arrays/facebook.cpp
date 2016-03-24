#include <iostream>
#include <map>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> getcombinations(string str, map<char,vector<string> > mymap) {
	vector<string> result;
	result.push_back("");
	if(str.length() == 0) return result;

	for(int i = 0; i< str.length(); i++) {
		vector<string> values = mymap[str[i]];
		std::vector<string> new_res;
		for(int j = 0; j < values.size(); ++j) {
			for(int k = 0; k < result.size(); ++k) {
				string temp = result[k] +values[j];	
				new_res.push_back(temp);
				
			}
		}
		result = new_res;
	}
	return result;
}

int main() {
	map<char, vector<string> > char_map;
	vector<string> values;
	values.push_back("c");
	values.push_back("C");
	values.push_back("(");
	char_map.insert(std::make_pair('c',values));
	values.clear();
	
	values.push_back("a");
	values.push_back("A");
	values.push_back("@");
	char_map.insert(std::make_pair('a',values));
	values.clear();

	values.push_back("t");
	values.push_back("T");
	values.push_back("#");
	char_map.insert(std::make_pair('t',values));
	values.clear();

	string str = "cat";
	vector<string> result = getcombinations(str, char_map);

	for(int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}
	cout << result.size();
}