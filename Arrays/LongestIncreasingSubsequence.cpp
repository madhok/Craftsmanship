#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> inp) {
	for(int i = 0; i < inp.size(); ++i) {
		cout << inp[i] << ",";
	}
}

vector<int> LIS(vector<int> input) {
	vector<vector<int> > vlis(input.size());
	vlis[0].push_back(input[0]);
	int size = input.size();
	for(int i = 1; i < size; ++i) {
		for(int j = 0; j < i; ++j) {
			if(input[j]<input[i] && (vlis[i].size()<vlis[j].size()+1)) {
				vlis[i] = vlis[j];
			}	
		}
		vlis[i].push_back(input[i]);
	}
	int max =0 ,max_i =0;
	cout << vlis.size() << endl;
	for(int i = 0; i < vlis.size();++i) {
		if(max < vlis[i].size()) {
			max_i = i;
			max = vlis[i].size();
		}
			
	}
	return vlis[max_i];
}


int main() {
	vector<int> input;
	input.push_back(2);
	input.push_back(3);
	input.push_back(4);
	input.push_back(1);
	input.push_back(2);
	input.push_back(3);
	input.push_back(4);

	std::vector<int>v = LIS(input);
	//cout << v.size() << endl;
	for(int i = 0; i < v.size(); ++i) {
		cout << v[i] << ",";
	}	
}