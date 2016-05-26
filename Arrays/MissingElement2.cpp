#include <iostream>
#include <vector>

using namespace std;

int findElement(vector<int> input) {
    int size = input.size();
    if(size==0) return 0;
    int result = input[0];
    for(int i=1; i <size; ++i) {
        result = result^input[i];
    }
    return result;
}

int main() {
	//code
	vector<int> input;
	input.push_back(1);input.push_back(1);
	input.push_back(2);input.push_back(2);
	input.push_back(5);input.push_back(3);
	input.push_back(4);input.push_back(4);
	input.push_back(5);
	cout << findElement(input);
	return 0;
}