/*
https://leetcode.com/problems/generate-parentheses/description/
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]


*/
class Solution {
public:
    bool isvalid(string combo) {
        // At any point of time left('(') i always greater than right(')')
        int left =0;
        int right = 0;
        for(int i = 0; i< combo.size();++i) {
            if(left <right) return false;
            if(combo[i] == '(') left++;
            if(combo[i] == ')') right++;
        }
        return true;
    }
    void util(int n, int left, int right, string& combo, vector<string>& result) {
        if(left == n && right ==n) {
            if(isvalid(combo)) {
                //cout << combo << endl;
                result.push_back(combo);
            }
            return;
        }
        if(left <n) {
            combo.push_back('(');
            util(n,left+1,right,combo,result);
            combo.pop_back();
        }
        if(right < n) {
            combo.push_back(')');
            util(n,left,right+1,combo,result);
            combo.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string combo;
        util(n,0,0,combo,result);
        return result;
    }
};
