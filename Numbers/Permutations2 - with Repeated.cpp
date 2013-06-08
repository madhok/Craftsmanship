/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].


*/


class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >result;
        permutehelper(num,0,result);
        return result;
    }
    
    bool noswap(int i, int j, const vector<int> num){
        for (int k=i;k<j;k++){
            if (num[k]==num[j]){
                return true;
            }
        }
        return false;
    }
    
    void permutehelper(vector<int>num, int i , vector<vector<int> >&result)
    {
        if(i == num.size())
            result.push_back(num);
        else
        {
            for(int j = i; j < num.size(); j++)
            {
                if (noswap(i,j,num)){continue;}
                swap(num[i],num[j]);
                permutehelper(num,i+1,result);
                swap(num[i],num[j]);
            }
        }
    }
};