/*
Given a set of distinct integers, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]


*/

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>>result;
        if(S.size() == 0)
            return result;
        
        int size = 1 << S.size();
        for(int i = 0; i < size; i++)
        {
            int bitnumber = i;
            vector<int>row;
            int index = 0;
            while(bitnumber > 0)
            {
                if(bitnumber & 0x01)
                {
                    row.push_back(S[index]);
                }
                bitnumber = bitnumber >> 1;
                index++;
            }
            sort(row.begin(), row.end());
            result.push_back(row);
        }
        sort(result.begin(), result.end());
        return result;
    }
};