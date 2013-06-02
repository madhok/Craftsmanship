class Solution {
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int leftSum = 0;
        int rightSum = 0;
        if(root == NULL)
            return 0;
        
        if(root->left == NULL && root->right == NULL)
        {
            return root->val; 
        }  
       
      // if(!isdigit(root->val))
       //{
    //       return 0;
    //   }
       
        if(root->left == NULL)
            leftSum = 0;
        
        else
            leftSum = root->val * 10 + sumNumbers(root->left);
        
            
        
        if(root->right == NULL)
            rightSum = 0;
        else
            rightSum = root->val* 10 + sumNumbers(root->right);
        return leftSum + rightSum;
    }
};