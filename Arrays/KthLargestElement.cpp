#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int Kth_largestElement(vector<int> input,int k) {
    if(input.size() < k) return -1;
    make_heap(input.begin(),input.end());
    return input[k-1];  //Since it starts with zeroth element;
}

int main() {
	//code
	int ntestcases,input_size, k;
	vector<int> input;
	cin >> ntestcases;
	while(ntestcases) {
	 cin >> input_size;
	 cin >> k;
	 for(int i = 0; i < input_size; ++i) {
	    int val;
	    cin >> val;
	    input.push_back(val);
	 }
	 cout << Kth_largestElement(input, k);
	 ntestcases--;
	}
	
	return 0;
}