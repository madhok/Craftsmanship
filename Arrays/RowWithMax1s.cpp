/*
Given a boolean 2D array. Find the row with the maximum number of 1s.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is n and m,n is the number of rows and m is the number of columns.
The second line of each test case contains C[n][m].

Output:

Print the row with the maximum number of 1s.

Constraints:

1 ≤ T ≤ 50
1 ≤ n,m ≤ 50
0 ≤ C[] ≤ 1

Example:

Input:
1
4 4
0 1 1 1 0 0 1 1 1 1 1 1 0 0 0 0

Output:
2
 
*/
#include <iostream>
using namespace std;

int print_max_1s(int** A, int m, int n) {
    int max[n];
    for(int i = 0; i < n; ++i) {
        max[i] = 0;
    }
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; j++) {
            if(A[i][j] == 1) {
                max[i] +=1;
            }
        }
    }
    int max_val = 0;
    int row = 0;
    for(int i = 0; i < n; ++i) {
        if(max[i] > max_val){
            max_val = max[i];
            row = i;
        }
    }
    return row;
}

int main() {
    int n;
    cin >> n;
    while(n) {
        n--;
        int m,n;
        cin >> m;
        cin >> n;
        int** A;
        A = new int *[m];
        for(int i = 0; i< m; ++i) {
            A[i] = new int [n];
            for(int j = 0; j<n;++j) {
                int val;
                cin >> val;
                A[i][j] = val;
            }
        }
        cout << print_max_1s(A,m,n) << endl;
    }
    return 0;
}