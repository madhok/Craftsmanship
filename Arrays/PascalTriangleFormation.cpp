/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows == 0) return result;
        vector<int>row;
        row.push_back(1);
        result.push_back(row);
        for(int i = 1; i < numRows; i++) {
           row.clear();
           row.push_back(1);
           vector<int> prevrow = result[i-1];
           for(int j = 0; j <prevrow.size()-1; j++) {
               row.push_back(prevrow[j] +prevrow[j+1]);
           }
           row.push_back(1);
           result.push_back(row);
        }
        return result;
    }
};
