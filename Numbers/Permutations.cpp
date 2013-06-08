/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

*/

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> >result;
        permutehelper(num,0,result);
        return result;
    }
    
    void permutehelper(vector<int>num, int i , vector<vector<int> >&result)
    {
        if(i == num.size())
            result.push_back(num);
        else
        {
            for(int j = i; j < num.size(); j++)
            {
                swap(num[i],num[j]);
                permutehelper(num,i+1,result);
                swap(num[i],num[j]);
            }
        }
    }
};