#include <iostream>
using namespace std;
void print_alternate(int A[], int size) {
    int startchange = -1;
    bool out_of_place = false;
    for(int i=0; i<size; ++i) {
        if(i%2 ==0 && A[i]<0) {
            if(!out_of_place) {
                startchange = i;
            } else {
                rotate_array(A,startchange,i);
            } 
        } else if(i%2 ==1 && A[i]>0){
            if(out_of_place) {
                
            }
        }
        
        
    }
}

int main() {
	//code
	int n ;
	cin>>n;
	while(n) {
	    n--;
	    int size;
	    int A[size];
	    for(int i = 0; i < size; ++i) {
	        int val;
	        cin >> val;
	        A[i] = val;
	    }
	    print_alternate(A,size);
	}
	return 0;
}