/*
Note that the problem requires in-place operation.The flatten procedure is like:  cut the left child and set to right, the right child is then linked to somewhere behind the left child. Where should it be then?  Actually the right child should be linked to the most-right node of the left node. So the algorithm is as follows:

(1) store the right child (we call R)

(2) find the right-most node of left child

(3) set R as the right-most node's right child.

(4) set left child as the right child

(5) set the left child NULL

(6) set current node to current node's right child.

(7) iterate these steps until all node are flattened
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
    void flatten(TreeNode* root) {
        if(root == NULL) return ;
        TreeNode* currNode = root;
        while(currNode) {
            if(currNode->left && currNode->right) {
               TreeNode* Rnode = currNode->right;
                currNode->right = currNode->left;
                currNode->left = NULL;
                TreeNode* left_rightmost_node = getRightmostNode(currNode->right);
                left_rightmost_node->right = Rnode;
                currNode = currNode->right;
            }else if(currNode->left) {
                currNode->right = currNode->left;
                currNode->left = NULL;
                currNode = currNode->right;
            } else {
                currNode = currNode->right;
            }
        }
    }
    
    TreeNode* getRightmostNode(TreeNode* root) {
        while(root) {
            if(root->right == NULL) {
                return root;
            }
            root = root->right;
        }
        return NULL;
    }
    
};
