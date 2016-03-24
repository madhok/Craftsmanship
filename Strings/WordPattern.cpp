/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if(str.length() == 0 && pattern.length() ==0)
            return true;
        vector<string> words = get_words(str);
        if(pattern.length() != words.size()) return false;
        map<string,char> has_match;
        
        map<char,string> match_map;
        for(int i =0; i < pattern.length(); ++i) {
           if(match_map.find(pattern[i]) == match_map.end() && 
                has_match.find(words[i]) == has_match.end()) {
                match_map[pattern[i]] = words[i];
                has_match[words[i]] = pattern[i];
           }
           else if(has_match[words[i]] != pattern[i] || match_map[pattern[i]] != words[i])
                return false;
        }
        return true;
    } 
    
    vector<string> get_words(string str) {
        vector<string> result;
        istringstream s(str);
        string word;
        while(s >> word) {
            result.push_back(word);
            
        }
        return result;
    }
};