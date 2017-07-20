/*
http://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1

Given a Binary Search Tree and a target sum, write a function that returns true if there is a pair with sum equals to target sum, otherwise return false.

Input:
First line consists of T test cases. First line of every test case consists of N and target, denoting the number of elements in bst and target sum. Second line consists of elements of BST.

Output:
Return True if target sum pair is found else False.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
7 10
1 2 3 4 5 6 7
7 33
15 10 20 8 12 16 25  
Output:
1
1

*/


/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function below
Node is as follows
struct node
{
    int val;
    struct node *left, *right;
};
*/
void inorder(struct node* root, vector<node*>& arr) {
    if(root == NULL) return;
    inorder(root->left,arr);
    arr.push_back(root);
    inorder(root->right,arr);
}
vector<node*> getinorder(struct node* root) {
    vector<node*>arr;
    inorder(root,arr);
    return arr;
}
bool isPairPresent(struct node *root, int target)
{
    vector<node*>arr = getinorder(root);
    int start = 0;
    int end = arr.size()-1;
    while(start< end) {
        if(arr[start]->val + arr[end]->val == target) 
            return true;
        if(arr[start]->val + arr[end]->val < target)
            start++;
        if(arr[start]->val + arr[end]->val > target)
            end--;
    }
    return false;
}
