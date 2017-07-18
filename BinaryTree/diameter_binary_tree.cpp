/*
http://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

Given a Binary Tree, find diameter of it.
The diameter of a tree is the number of nodes on the longest path between two leaves in the tree.
The diagram below shows two trees each with diameter nine,
the leaves that form the ends of a longest path are shaded
(note that there is more than one path in each tree of length nine, but no path longer than nine nodes).

Input:
The task is to complete the method which takes one argument, root of Binary Tree. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return diameter of binary tree.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input:
2
2
1 2 L 1 3 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
3
4

There are two test casess.  First case represents a tree with 3 nodes and 2 edges where root is 1,
left child of 1 is 2 and right child of 1 is 3.
Second test case represents a tree with 4 edges and 5 nodes.
*/


/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/* Computes the diameter of binary tree with given root.  */

int max(int a, int b) {
    return a>b?a:b;
}

int height(Node* node) {
    if(node == NULL) return 0;
    int lh = height(node->left);
    int rh = height(node->right);
    return max(lh,rh)+1;
}

int diameter(Node* node)
{
   if(node == NULL) return 0;
   int lh = height(node->left);
   int rh = height(node->right);
   
   int ldiameter = diameter(node->left);
   int rdiameter = diameter(node->right);
   
   return max(lh+rh+1, max(ldiameter,rdiameter));
}
