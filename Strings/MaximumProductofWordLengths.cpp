/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/
class Solution {
public:
    int max(int a, int b) {
        return a>b?a:b;
    }
    int maxProduct(vector<string>& words) {
        int size = words.size();
        if(size <2) return 0;
        int arr[size];
        
        for(int i = 0; i< size; ++i) {
            int val = 0;
            for(int j = 0; j < words[i].length(); ++j) {
                int bit_pos = words[i][j] -'a';
                val = val | 1 << bit_pos; 
            }
            arr[i] = val;
        }
        
        for(int i = 0; i < size; ++i) {
            //cout << arr[i] << endl;
        }
        
        
        int max_len =0;
        for(int i = 0; i < size; ++i) {
            for(int j = i+1; j<size; ++j) {
                if((arr[i] & arr[j]) == 0) {
                    max_len = max(max_len, words[i].length() * words[j].length());
                }
            }
        }
        return max_len;
        
    }
};
