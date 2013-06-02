/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

*/

//With O(n) stack
class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.length() == 0)
            return 0;
        
       int maxLen = 0, last = -1;  
       stack<int> lefts;  
       for (int i=0; i<s.length(); ++i) {  
         if (s[i]=='(') {  
           lefts.push(i);  
         } else {  
           if (lefts.empty()) {  
             // no matching left  
             last = i;  
           } else {  
             // find a matching pair  
             lefts.pop();  
             if (lefts.empty()) {  
               maxLen = max(maxLen, i-last);  
             } else {  
               maxLen = max(maxLen, i-lefts.top());  
             }  
           }  
         }  
       }  
       return maxLen;     
            
    }
};


//Without extra space but have to iterate twice not O(n^2)
/*
When going from left to right,

First, skip invalid ')'s
Then, find the longest valid parentheses that ended with an invalid '(' or ')'
When going backwards,
Skip invalid '('s
Find the longest valid parentheses that ended with an invalid parenthesis
*/
private int findValidParentheses(String s, int start, int end, int step, char cc) {  
   int maxLen = 0, count = 0, len = 0;  
   for (int i=start; i!=end; i+=step) {  
     if (s.charAt(i)==cc) {  
       ++count;  
     } else {  
       if (count>0) {  
         // exist a matching  
         --count;  
         len += 2;  
         if (count==0) maxLen = Math.max(maxLen, len);  
       } else {  
         // no matching  
         len = 0;  
       }  
     }  
   }  
   return maxLen;  
 }  
   
 public int longestValidParentheses(String s) {  
   return Math.max(findValidParentheses(s, 0, s.length(), 1, '('),  
           findValidParentheses(s, s.length()-1, -1, -1, ')'));  
 }  