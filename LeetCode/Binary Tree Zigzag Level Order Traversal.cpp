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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>>results;
        
        if(root == NULL)
            return results;
        
        vector<pair<TreeNode*, int>>Nodes;
        Nodes.push_back(make_pair(root,0));
        int element = 0;
        while(element < Nodes.size())
        {
            TreeNode *currentNode = Nodes[element].first;
            int NodeLevel = Nodes[element].second;
            
            if(currentNode->left != NULL)
                Nodes.push_back(make_pair(currentNode->left, NodeLevel+1));
            if(currentNode->right != NULL)
                Nodes.push_back(make_pair(currentNode->right, NodeLevel+1));    
            
            element++;    
        }
     
        for(int i =0 ; i < Nodes.size(); i++)
        {
            int level = Nodes[i].second;
            TreeNode* currentNode = Nodes[i].first;
            if(level >= results.size())
                results.resize(level+1);
            results[level].push_back(currentNode->val);
        }
        
        for(int i = 1 ; i < results.size(); i+=2)
        {
            reverse(results[i].begin(), results[i].end());
        }
        return results;
    }
};


