/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0) return false;
        if(s.length() %2 !=0) return false;
        
        std::map<char,char>paren_map;
        paren_map['('] = ')';
        paren_map['{'] = '}';
        paren_map['['] = ']';
        
        std::vector<char>vect_closed;
        vect_closed.push_back(')');
        vect_closed.push_back('}');
        vect_closed.push_back(']');
        
        std::stack<char> paren_stack;
        for(int i = 0; i < s.length(); i++) {
            if(paren_map.find(s[i]) != paren_map.end()) {
                paren_stack.push(s[i]);   
            }
            else if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if(!paren_stack.empty() && paren_map[paren_stack.top()] == s[i]) {
                    paren_stack.pop();
                }else {
                    return false;
                }
            }
        }
        if(paren_stack.empty())
            return true;
        return false;
        
    }
};
