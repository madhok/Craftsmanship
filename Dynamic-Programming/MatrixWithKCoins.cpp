/*
Given a matrix where every cell has some number of coins. Count number of ways to reach bottom right from top left with exactly k coins. We can move to (i+1, j) and (i, j+1) from a cell (i, j).

Input:
First line contains number of test cases T. For each test case, first line contains the integer value 'k' denoting coins, second line contains an integer 'N' denoting the order of square matrix.Last line contains NXN elements in a single line in row-major order.
Output:
Number of paths are displayed as output to the user. '0' is displayed when no path is found.


Constraints:
1 <=T<= 100
1 <=k<= 20
1 <=N<= 10
1 <=arr[i]<= 100


Example:

Input:
2
16
3
1 2 3 4 6 5 9 8 7
12
3
1 2 3 4 6 5 3 2 1

Output:
0
2
*/
#include <iostream>
using namespace std;

int ways(int ** A,int m,int n, int k) {
    if(m <0 || n < 0) return 0;
    if(m==0 && n ==0) return k==A[m][n];
    
    return ways(A,m-1,n,k-A[m][n]) + 
            ways(A,m,n-1,k-A[m][n]);
}

int main() {
	int n;
	cin >> n;
	while(n) {
	    n--;
	    int k;
	    cin >> k;
	    int size;
	    cin >> size;
	    int *A[size];
	    for(int i=0;i<size;++i) {
	        A[i] = new int(size);
	        for(int j=0;j<size;++j) {
	            int val;
	            cin >>val;
	            A[i][j] = val;
	        }
	    }
	    cout << ways(A,size-1,size-1,k) << endl;
	}
	return 0;
}
