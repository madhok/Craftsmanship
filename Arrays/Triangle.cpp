/*

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

*/

//This is vertibi algorithm

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       for(int row = triangle.size()-1; row >0; row--)
       {
           for(int col = 0; col < triangle[row-1].size(); col++)
           {
               triangle[row-1][col] = min(triangle[row-1][col] + triangle[row][col],
                                        triangle[row-1][col] + triangle[row][col + 1]);
           }
       }
       return triangle[0][0];
    }
};