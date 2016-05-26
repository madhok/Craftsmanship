/*
Given a tile of size 1 x 4, how many ways you can construct a grid of size N x 4.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N.

Output:

Print number of possible ways.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 80

Example:

Input:
3
1
4
5

Output:
1
2
3

*/

#include <iostream>
using namespace std;

using namespace std;

int main() {
	//code
	int ntests;
	cin >> ntests;
	while(ntests) {
	    ntests--;
	    int n;
	    cin >> n;
	    if(n < 4) {
	        cout << "1" << endl; 
	    } else {
	     long long ans[n+1];
	     ans[0] = ans[1]= ans[2]=ans[3] =1;
	     ans[4] = 2;
	     for(int i = 5; i <=n; i++) {
	        ans[i] = ans[i-1] + ans[i-4]; 
	     }
	     cout << ans[n] << endl;   
	    }
	}
	return 0;
}
