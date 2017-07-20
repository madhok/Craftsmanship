/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3


*/

/* Explanation

trees[n] is the number of trees with exactly n nodes. There is 1 trees with 0 nodes, hence trees[0] == 1. For a given n > 0 there is a root node and two children trees whose total size is: n-1

trees[n-1] possible trees on the left and trees[0] on the right
trees[n-2] possible trees on the left and trees[1] on the right
...
trees[1] possible trees on the left and trees[n-1-1] on the right
trees[0] possible trees on the left and trees[n-1] on the right
When you have trees[k] possible trees on the left, and trees[l] on the right, it makes trees[k]*trees[l] possible combinations. This means:

trees[n] = trees[n-1]*trees[0]
         + trees[n-2]*trees[1]
         + ...
         + trees[1]*trees[n-2]
         + trees[0]*trees[n-1]
The outer loop compute all trees[n]. The inner loop compute each of these using the decomposition I shown above (and the computations of all the values before n).

*/


class Solution {
public:
    int numTrees(int n) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0)
            return 0;
        
        if(n == 1 || n == 2)
            return n;
        
        vector<int>result(n+1);
        
        result[0] = 1;
        result[1] = 1;
       // result[2] = 2;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                result[i] += result[j]*result[i-j-1];
            }
        }
        return result[n];
    }
};




