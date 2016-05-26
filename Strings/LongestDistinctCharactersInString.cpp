/*
Given a string, find length of the smallest substring with maximum number of distinct characters.  For example, for input "abca", the output is 3 as "abc" is the smallest substring with maximum number of distinct characters.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is String str.

Output:

Print length of smallest substring with maximum number of distinct characters.

Constraints:

1 ≤ T ≤ 100
1 ≤ size of str ≤ 10000

Example:

Input
2
abababcdefababcdab
geeksforgeeks
 

Output:
6
7

*/
#include <iostream>
#include <map>
using namespace std;

int max_distinct(string input) {
    int len = input.length();
    if(len <=1) return len;
    map<char,bool> m;
    int max_len =0;
    int cur_len = 0;
    for(int i = 0; i<len; ++i) {
        if(m.find(input[i]) == m.end()) {
            cur_len++;
            m[input[i]] = true;
        } else {
            max_len = max(cur_len,max_len);
            m.clear();
            m[input[i]] = true;
            cur_len =1;
        }
        max_len = max(cur_len,max_len);
    }
    return max_len;
}

int main() {
	//code
	int n;
	cin>>n;
	while(n) {
	    n--;
	    string inp;
	    while (true) {
            getline(cin, inp);
            if (!inp.empty()) {
                break;
            }
        }
        cout << max_distinct(inp) << endl;
	}
	return 0;
}