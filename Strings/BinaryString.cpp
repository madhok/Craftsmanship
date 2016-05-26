#include <iostream>
using namespace std;

int count_substrings(string input) {
    if(input.size() ==0) return 0;
    int size = input.size();
    int count_1s =0;
    for(int i = 0; i < size; ++i) {
        if(input[i] =='1') count_1s++;
    }
    return (count_1s)* (count_1s-1)/2;
    
}

int count_substrings_slow(string input) {
    if(input.size() ==0) return 0;
    int count = 0;
    for(int i=0; i<input.size();++i) {
        if(input[i]=='1') {
            for(int j=i+1; j<input.size();++j) {
                if(input[j]=='1') count++;
            }
        }
    }
    return count;
}
int main() {
    //code
    int n;
    cin >> n;
    while(n) {
        n--;
        int size;
        string input;
        cin >> size;
        while(size) {
            size--;
            string val;
            cin >> val;
            input +=val;
        }
        cout << count_substrings(input) << endl;
    }
    return 0;
}