/*
An array containing heights of building was given. Its a rainy season. Calculate the amount of water collected between all the buildings.

 

Histograms with no space in between
Input:

 

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the number of buildings.
The second line of each test case contains N input H[i],height of buildings.

Output:

Print the amount of water collected between all the buildings.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 1000
1 ≤ H[i] ≤ 1000

Example:

Input
1
6
1 5 3 7 4 2

Output
2

*/
#include <iostream>
using namespace std;

int find_water(int* A, int size) {
    if(size == 0) return 0;
    int l[size];
    int r[size];
    l[0] = A[0];
    for(int i=1;i<size;++i) {
        l[i] = max(l[i-1],l[i]);
    }
    r[size-1] = A[size-1];
    for(int i=size-2;i>=0;++i) {
        r[i] = max(r[i+1],r[i]);
    }
    int ret = 0;
    for(int i=0; i< size;++i) {
        ret+=min(l[i],r[i]) -A[i];
    }
    return ret;
}

int main() {
	int n;
	cin >> n;
	while(n) {
	    n--;
	    int size;
	    cin >> size;
	    int A[size];
	    for(int i = 0; i< 1; ++i) {
	        int val;
	        cin >> val;
	        A[i] = val; 
	    }
	    cout << find_water(A,size) << endl;
	}
	return 0;
}
