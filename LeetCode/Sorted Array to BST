/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      return createBST(num, 0, num.size() -1); 
        
    }
    
    TreeNode* createBST(vector<int> &num, int start, int end)
    {
        TreeNode* root;
        if(start > end)
            return NULL;
        int median = start + (end-start)/2;
        root = new TreeNode(num[median]);
        root->left = createBST(num, start, median -1);
        root->right = createBST(num, median+1, end);
        return root;
    }
};