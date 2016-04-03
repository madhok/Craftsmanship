#include <iostream>
#include <string>
#include <sstream> 

using namespace std;

string getString(string input, int& index) ;
string csvparser(string input) {
	string result = "";
	if(input == "") return result;

	for(int i = 0; i < input.length(); ++i) {
		if(input[i] == '"') {
			result += getString(input, i);
		} else if(input[i] == ','){
			result += "|";
		} else {
			result += input[i];
		}
	}
	return result;
}

string getString(string input, int& index) {
	string result = "";
	bool inquote = false;
	if(index+1 < input.length() && input[index+1] =='"') {
		index++;
		result+='"';
		inquote = true;
	} 
	index++;
	while(index < input.length() && input[index] !='"') {
		result +=input[index++];
	}
	if(inquote && index < input.length()) {
		result +=input[index++];
	}
	
	return result;
}


int main() {
	char ch[100];
	cin.getline(ch, sizeof(ch));
	string input(ch);
	cout << csvparser(input) << endl;
}