// Example program
/*
Print all permutations of a String
*/

#include <iostream>
#include <string>

using namespace std;

void swap(char& a, char& b) {
    char temp;
    temp = a;
    a = b;
    b= temp;
}

void permute(string& input, int start, int end) {
    if(start == end) {
        cout << input << endl;
    }
    for(int i = start; i < end; ++i) {
        swap(input[start],input[i]);
        permute(input, start+1,end);
        swap(input[start],input[i]);
    }
}

int main()
{
    string input = "cabab";
    permute(input,0,input.length());
}
