//
//  BinaryTree.h
//  Trees
//
//  Created by Madhok Shivaratre on 3/10/13.
//  Copyright (c) 2013 Madhok Shivaratre. All rights reserved.
//

#ifndef __Trees__BinaryTree__
#define __Trees__BinaryTree__

#include <iostream>
#include <stack>
#include <queue>


using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};

class BinaryTree
{
    Node* root;
    void inOrder(Node* currentNode);
    int nodeCount(Node* currentNode);
    int getleafs(Node *currentNode);
    void destroyNode(Node* currentNode);
    Node* createNode(int val);
    void BFS(Node* currentNode);
    void levelPrint(Node* currentNode,int level);
    bool checkBalance(Node* currentNode);
    int abs(int a)
    {
        if(a>-1)
            return a;
        else
            return -a;
    }
    int maxdepth(Node* currentNode);
    int mindepth(Node* currentNode);
    int getMedian(int sortedArray[],int length);
    Node* createBTree(int sortedArray[],int start, int end);
    
public:
    
    BinaryTree(int val)
    {
        root = new Node();
        root->data = val;
        root->left = NULL;
        root->right = NULL;
    }
    BinaryTree(int sortedArray[], int length);
    
    void InsertNode(int val);
    int GetTreeHeight(Node* CurrentNode);
    int GetMinHeightTree(Node* CurrentNode);
    bool IsEmpty();
    void InOrderTraverse();
    int GetNodeCount();
    int GetLeafCount();
    void DestroyTree();
    bool IsPresent(int val);
    bool DeleteBSTNode(int val);
    void InOrderTraverseIterative();
    void PreOrderTraverseIterative();
    void PostOrderTraverseIterative();
    void BreadthFirstTraversal();
    void LevelPrinting();
    void ReversePrinting();    
    bool IsBalanced();
    static void CreateTree(int sortedArray[],int length);
    bool IsBST(Node* root);
};



#endif /* defined(__Trees__BinaryTree__) */
