/*AnagramsMar 19 '12
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        map<string, vector<string> > dict;

        if (strs.size() == 0) {
            return result;
        }

        for (int i = 0; i < strs.size(); i++) {
            string sorted(strs[i]);
            sort(sorted.begin(), sorted.end());
            dict[sorted].push_back(strs[i]);
        }

        map<string, vector<string> >::iterator it;        
        for (it = dict.begin(); it != dict.end(); it++) {
            if (it->second.size() > 1) {
                for (int i = 0; i < it->second.size(); i++) {
                    result.push_back(it->second[i]);
                }
            }
        }

        return result;
    }
};