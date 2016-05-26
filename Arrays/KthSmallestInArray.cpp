// Example program
#include <iostream>
#include <string>

using namespace std;

int findKthsmallest(int A[], int sA, int B[], int sB, int k) {
    if(sA == 0 && sB==0) return -1;
    if(sA ==0 && k < sB) return B[k];
    if(sB ==0 && k < sA) return A[k];
    int ia =0;
    int ib =0;
    int curr =1;
    while(ia <sA && ib <sB) {
        if(k == curr) return A[ia]<B[ib]?A[ia]:B[ib];
        if(A[ia] < B[ib]) {
            ia++;
        } else {
            ib++;
        }
        curr++;
    }
    if(ia == sA) {
        return B[ib+(k-curr)];
    } else if(ib == sB) {
        return A[ia+(k-curr)];
    }
    return -1;
}

int main()
{
  int A[5] = {1,3,5};
  int B[5] = {6,7,8,9,10};
  cout << findKthsmallest(A,3,B,5,7);
}
