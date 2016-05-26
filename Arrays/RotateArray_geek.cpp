#include <iostream>
using namespace std;

void print_array(int A[], int size) {
    for(int i = 0; i < size; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void rotate_array(int *A,int size, int r) {
    int temp;
    while(r) {
        r--;
        temp = A[0];
        for(int i = 1; i <size; ++i) {
            A[i-1] = A[i];
        }
        A[size-1] = temp;
    }
}

int main() {
	//code
	int n;
	cin >> n;
	while(n) {
	    n--;
	    int size,r;
	    cin >> size;
	    cin >> r;
	    int A[size];
	    for(int i = 0; i< size; ++i) {
	        int val;
	        cin >> val;
	        A[i] = val;
	    }
	    rotate_array(A,size,r);
	    print_array(A,size);
	}
	return 0;
}