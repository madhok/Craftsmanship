/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result_str;
        if(root == NULL) return result_str;
        vector<vector<int>> values;
        vector<int> curr_path;
        helper(root, values,curr_path);
        
        result_str = convert(values);
        return result_str;
    }
    
    void helper(TreeNode* root, vector<vector<int>>& values, vector<int> curr_path) {
        if(root == NULL ) {
            return;
        }
        curr_path.push_back(root->val);
        if(root->left == NULL && root->right == NULL) {
            values.push_back(curr_path);
            return;
        }
       
        helper(root->left,values,curr_path);
        helper(root->right,values,curr_path);
       
       
    }
    
    vector<string> convert(vector<vector<int>>& values) {
        vector<string> result;
        for(int i = 0; i<values.size(); ++i) {
            string subres = convertToString(values[i]);
            result.push_back(subres);
        }
        return result;
    }
    
    string convertToString(vector<int>& v) {
        string result = "";
        if(v.size() ==0) return result;
        for(int i = 0; i <v.size()-1; ++i) {
            result +=to_string(v[i]);
            result += "->";
        }
        result +=to_string(v[v.size()-1]);
        return result;
    }
    
   
    
};