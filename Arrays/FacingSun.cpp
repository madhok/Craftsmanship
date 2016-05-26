/*
An array of buildings is facing the sun. The heights of the building is given in an array. You have to tell which all buildings will see the sunset.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the number of buildings.
The second line of each test case contains N input H[i],height of building.

Output:

Print the total number of buildings which will see the sunset.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 500
1 ≤ H[i] ≤ 1000

Example:

Input:
2
5
7 4 8 2 9
4
2 3 4 5

Output:
3
4
*/


#include <iostream>
using namespace std;

int n_buildings(int A[],int size) {
    if(size == 0) return 0;
    if(size == 1) return 1;
    int ncount =1;
    int cmax = A[0];
    for(int i = 1; i < size; ++i) {
        if(A[i] > cmax) {
            ncount++;
            cmax = A[i];
        }
    }
    return ncount;
}

int main() {
	//code
	int n;
	cin >> n;
	while(n) {
	    n--;
	    int size;
	    cin >> size;
	    int A[size];
	    for(int i = 0; i < size; ++i) {
	        int val;
	        cin >> val;
	        A[i] = val;
	    }
	    cout << n_buildings(A,size) << endl;
	}
	return 0;
}