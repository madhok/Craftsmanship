/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"


*/

class Solution {
public:
    string countAndSay(int n) {
        if(n ==1) return "1";
        if(n == 2) return "11";
        string result = "11";
        int i = 2;
        while(i < n) {
            i++;
            int count = 1;
            string cur = "";
            int size = result.length();
            for(int j = 1; j<size;++j) {
                if(result[j] == result[j-1]) {
                    count++;
                } else {
                    cur += std::to_string(count) + result[j-1];
                    count = 1;
                }
            }
            string tmp = result;
            result = cur;
            result += std::to_string(count);
            result += tmp[size-1];
            
        }
        return result;
    }
};
