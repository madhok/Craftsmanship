/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

class Solution {
public:
    vector<string> append(vector<string> res, string val) {
        //cout << val << endl;
        vector<string> nres;
        for(int i = 0; i<res.size();++i) {
            for(int j = 0; j<val.size(); ++j) {
                string tmp = res[i] + val[j];
                nres.push_back(tmp);
            }
        }
        return nres;
    }
    vector<string> letterCombinations(string digits) {
        map<int,string> comb;
        comb[1] = "";
        comb[2] = "abc";
        comb[3] = "def";
        comb[4] = "ghi";
        comb[5] = "jkl";
        comb[6] = "mno";
        comb[7] = "pqrs";
        comb[8] = "tuv";
        comb[9] = "wxyz";
        comb[0] = " ";
        vector<string> res;
        for(int i = 0; i<digits.size();++i) {
            string val = comb[digits[i] -'0'];
            if(i == 0) {
                for(int j = 0; j<val.size();++j) {
                string tmp ="";
                tmp +=val[j];
                res.push_back(tmp);
                }
            } else {
                res =append(res,val);
            }
        }
        return res;
    }
};
