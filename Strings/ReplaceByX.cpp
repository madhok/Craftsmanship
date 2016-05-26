/*
Given a string and a pattern, Replace all the continuous occurrence of pattern with a single X in the string. For a clear view see the example below.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is string str.
The second line of each test case contains a string s,which is a pattern.

Output:

Print the modified string str.

Constraints:

1 ≤ T ≤ 100
1 ≤ size of str,s ≤ 1000

Example:

Input
2
abababcdefababcdab
ab
geeksforgeeks
geeks

Output
XcdefXcdX
XforX
*/
#include <iostream>
#include <string>
using namespace std;

string replace(string inp, string pat) {
    int len = inp.length();
    int pat_len = pat.length();
    string ret ="";
    int i =0;
    for(i = 0; i<len;++i) {
        string sub_inp = inp.substr(i,pat_len);
        //cout << sub_inp;
        if(sub_inp == pat) {
            ret +="X";
            i += pat_len-1; 
        } else {
            ret += inp[i];
        }
    }
    //ret += inp.substr();
    return ret;
}

int main() {
	//code
	int n;
	cin>>n;
	while(n) {
	    n--;
	    string inp;
	    string pat;
	    while (true) {
            getline(cin, inp);
            if (!inp.empty()) {
                break;
            }
        }
        while (true) {
            getline(cin, pat);
            if (!pat.empty()) {
                break;
            }
        }
        cout << replace(inp,pat) << endl;
	}
	return 0;
}