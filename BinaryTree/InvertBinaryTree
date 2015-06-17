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
   /* int getTreeHeight(TreeNode* node) {
        if(node == NULL) return 0;
        return 1 + max(getTreeHeight(root->left), getTreeHeight(root->right));
    }*/
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        invertTreeHelper(root, root->left, root->right);
        /*int levels = getTreeHeight(root);
        std::queue<std::vector<TreeNode*>> myq;
        std::vector<std::vector<int>> allnodeval;
        std::vector<TreeNode*> levelnodes;
        levelnodes.push_back(root);
        myq.push(levelnodes);
        while(!myq.empty()) {
          std::vector<TreeNode*> lnodes = myq.front(); 
          myq.pop();
          std::vector<TreeNode*> nlnodes;
          for(int i = 0; i < lnodes.size(); i++){
              nlnodes.push_back()
              std::vector<TreeNode*> lnode = lnodes[i];
              std::reverse(lnode.begin(),lnode.end());
          }
            
        }*/
        
        return root;
    }
    void invertTreeHelper(TreeNode* root, TreeNode* left,TreeNode* right) {
        if(root == NULL) return;
        if(left == NULL && right == NULL) return;
        TreeNode* temp = left;  
        root->left =right;
        root->right = temp;
        if(left != NULL)
            invertTreeHelper(left,left->left,left->right);
        if(right != NULL)
            invertTreeHelper(right,right->left,right->right);
        return;
    }
};
