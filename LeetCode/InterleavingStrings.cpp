class Solution {
public:
   bool isInterleave(string s1, string s2, string s3) {
    	int n = s1.length();
		int m = s2.length();
		bool f[n + 1][m + 1];

		if (n + m != s3.length()) {
			return false;
		}

		f[0][0] = true;
		for (int i = 1; i <= n; i++) {
			f[i][0] = s1.substr(0, i).compare(s3.substr(0, i)) == 0;
		}

		for (int j = 1; j <= m; j++) {
			f[0][j] = s2.substr(0, j).compare(s3.substr(0, j)) == 0;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				f[i][j] = false;
				if (s1[i - 1] == s3[i + j - 1] && f[i - 1][j]) {
					f[i][j] = true;
				}
				if (s2[j - 1] == s3[i + j - 1] && f[i][j - 1]) {
					f[i][j] = true;
				}
			}
		}

		return f[n][m];
	}
};