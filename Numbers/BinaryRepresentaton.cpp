//Find the Binary representation of the number

#include <iostream>
#include <string>
#include <stack>
using namespace std;

//better
void print_bin_nostack(int x) {
    for(unsigned int i=1<<31; i>0;i = i>>1) {
        if(i & x) cout << "1";
        else cout << "0";
    }
}

void print_bin_stack(int x) {
    stack<int> bin_stack;
    for(int i = x; i != 0; i=i>>1 ) {
        if(i & 0x01) {
            bin_stack.push(1);
        } else {
            bin_stack.push(0);
        }
    }
    while(!bin_stack.empty()){
        cout << bin_stack.top();
        bin_stack.pop();
    }
}

int main()
{
  print_bin(7);
}