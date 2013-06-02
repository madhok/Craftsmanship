/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int>result;
        result.push_back(1);
        if(rowIndex < 1)
            return result;
        int index = 1;
        for(int index = 0;index < rowIndex ; index++)
        {
            vector<int>newvector;
            int prev = 0;
            
            for(int prevrowIndex = 0; prevrowIndex < result.size(); prevrowIndex++)
            {
                newvector.push_back(prev + result[prevrowIndex]);  
                prev = result[prevrowIndex];
            }
            newvector.push_back(1);
            result = newvector;
        }
        return result;
    }
};