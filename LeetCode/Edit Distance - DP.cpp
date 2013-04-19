class Solution {
public:

    int minimal(int a, int b, int c) {
        int min = a;
        if (b < min) min = b;
        if (c < min) min = c;
        return min;
    }
    int minDistance(string word1, string word2) {
       int ed[word1.length() + 1][word2.length() + 1];

        // initialize
       for (int i = 0; i < word1.length() + 1; i++) {
            ed[i][0] = i;
       }
       for (int i = 0; i < word2.length() + 1; i++) {
            ed[0][i] = i;
       }

        // DP
       for (int i = 1; i < word1.length() + 1; i++) {
            for (int j = 1; j < word2.length() + 1; j++) {
                    if (word1[i - 1] == word2[j - 1]) {
                        ed[i][j] = ed[i -1][j - 1];
                    }
                    else {
                        ed[i][j] = minimal(ed[i - 1][j] + 1,
                                           ed[i][j - 1] + 1,
                                           ed[i - 1][j - 1] + 1);
                    }
            }
       }

       return ed[word1.length()][word2.length()];
    }
};