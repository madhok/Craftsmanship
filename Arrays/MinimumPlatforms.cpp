/*
Given arrival and departure times of all trains that reach a railway station, find the minimum number of platforms required for the railway station so that no train waits.

Input:

First line will contain a number T, the number of test cases.
Each test case will contain a number N, the number of trains.
Next two lines will consist of N space separated time intervals denoting arrival and departure times respectively.
NOTE: Time intervals are in 24 hour format(hhmm),preceding zeros are insignificant.
Consider the example for better understanding of input.

Output:

Print the required answer in separated line.

Constraints:

1<=T<=80
1<=N<=5000

1<=A[i]<=5000
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int nplatforms(vector<int> arr, vector<int>dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end()) ;
    int size = arr.size();
    int nplatforms = 1,ai =0, di=0,result = 0;
    while(ai < size && di < size ) {
        size--;
        if(arr[ai] < dep[di]) {
            nplatforms++;
            ai++;
            if(result < nplatforms) result++;
        } else {
            nplatforms--;
            di++;
        }
    }
    return result;
}


int main() {
	//code
	vector<int> arrivals;
	arrivals.push_back(900);
	arrivals.push_back(940);
	arrivals.push_back(950);
	arrivals.push_back(1100);
	arrivals.push_back(1500);
	arrivals.push_back(1800);
	vector<int> deps;
	deps.push_back(910);
	deps.push_back(1200);
	deps.push_back(1120);
	deps.push_back(1130);
	deps.push_back(1900);
	deps.push_back(2000);
	
	cout << nplatforms(arrivals, deps);
	return 0;
}