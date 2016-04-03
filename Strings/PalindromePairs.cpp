#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

bool isPalindrome(string str);

vector<string> PalidromePairs(vector<string> input) {
	vector<string> result;
	if(input.size() == 0) return result;
	int len = input.size();
	for(int i =0; i < len; ++i) {
		for(int j =i+1; j<len;++j) {
			if(isPalindrome(input[i]+input[j])) {
				result.push_back(input[i]+input[j]);
			}
		}
	}
}

bool isPalindrome(string str) {
	int len = str.length();
	if(len == 0) return true;

	int start_index = 0;
	int end_index = len-1;
	while(start_index < end_index) {
		if(str[start_index++] != str[end_index--]) {
			return false;
		}
	}
	return true;
}


int main() {
	vector<string> input;
	input.push_back("abc");
	input.push_back("cba");
	input.push_back("bc");
	input.push_back("cb");

	vector<string> result = PalidromePairs(input);
	for(int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}
	return 0;
}

	