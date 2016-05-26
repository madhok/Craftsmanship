#include <iostream>

using namespace std;
#define R 6
#define C 5

int min(int a, int b, int c) {
    if(a < b && a < c) return  a;
    if(b < a && b < c) return b;
    return c;
}
void print_matrix(bool arr[R][C]) {
    int S[R][C];  
    
    //build S
    //copy first row
    for(int i = 0; i < R; i++) {
        S[0][i] = arr[0][i];
    }
    //copy first col
    for(int i = 0; i < C; i++) {
        S[i][0] = arr[i][0];
    }
    
    for(int i = 1; i< R; i++) {
        for(int j = 1; j < C; ++j) {
            if(arr[i][j]) {
                int val = min(S[i][j-1],
                            S[i-1][j-1],
                            S[i-1][j]);
                S[i][j] = val;
            } else {
                S[i][j] = 0;
            }
        }
    }
    
    //find the max val in S[i][j];
    int max = S[0][0];
    int max_i =0, max_j=0;
    for(int i = 0; i <R; ++i) {
        for(int j = 0; j<C; ++j) {
            if(max < S[i][j]) {
                max = S[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    cout << max_i << endl;
    cout << max_j << endl;
    cout << max << endl;
    //Print from maxi, maxj till max value
    /*
    for(int i = max_i; i > max_i - max; i--) {
        for(int j = max_j; j > max_j - max;j--) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }*/
    
}

int main() {
	//code
    bool M[R][C] =  {{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
    print_matrix(M);
	return 0;
}