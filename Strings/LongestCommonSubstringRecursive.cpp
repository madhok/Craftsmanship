#include<iostream>

using namespace std;

int max(int a, int b) {
    return a>b?a:b;
}

int LCS(string a, string b,int n, int m) {
	if(m ==0 ||  n== 0) return 0;
	if(a[n-1] == b[m-1])
		return 1 + LCS(a,b,n-1,m-1);
	else 
		return max(LCS(a,b,n-1,m),LCS(a,b,n,m-1));	
}

int longest_common_subsequence(string a, string b) {
	int end_a = a.length();
	int end_b = b.length();

	return LCS(a,b,end_a,end_b);
}

int main() {
	cout << longest_common_subsequence("ABCD", "ABC");
}



