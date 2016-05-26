#include <iostream>
using namespace std;

int max_incr_subs(int A[], int size) {
    if(size == 0) return 0;
    if(size == 1) return A[0];
    
    int mis[size];
    for(int i = 0; i < size; ++i) {
        mis[i] = A[i];
    }
    for(int i = 1; i< size; ++i) {
        for(int j = 0; j<i; ++j) {
            if(A[i] >A[j] && mis[i] < (mis[j] +A[i])) {
                mis[i] = mis[j] + A[i];
            }
        }
    }
    int max = mis[0];
    for(int i = 1; i <size; ++i) {
        if(max < mis[i]) {
            max = mis[i];
        }
    }
    return max;
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
	    for(int i = 0; i< size; ++i) {
	        int val;
	        cin >> val;
	        A[i] = val;
	    }
	    cout << max_incr_subs(A,size) << endl;
	}
	return 0;
}