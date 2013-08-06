//
//  BinaryTree.cpp
//  Trees
//
//  Created by Madhok Shivaratre on 3/10/13.
//  Copyright (c) 2013 Madhok Shivaratre. All rights reserved.
//

#include "BinaryTree.h"

void BinaryTree::InsertNode(int val)
{
    Node* newNode = createNode(val);
    if(root == NULL)
    {
        root = newNode;
        return;
    }
    Node* currentNode = root;
    Node* prevNode = NULL;
   while(currentNode)
    {
        prevNode = currentNode;
        if(val > currentNode->data)
            currentNode = currentNode->right;
        else
            currentNode = currentNode->left;        
    }
    if(prevNode->data > val)
    {
        prevNode->left = newNode;
    }
    else
        prevNode->right = newNode;
    
}

Node* BinaryTree::createNode(int val)
{
    Node* newNode = new Node();
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

int BinaryTree::GetTreeHeight(Node *CurrentNode)
{
    if(CurrentNode == NULL)
    {
        return 0;
    }
    return 1 + max(GetTreeHeight(CurrentNode->left),GetTreeHeight(CurrentNode->right));
}

int BinaryTree::GetMinHeightTree(Node* CurrentNode)
{
    if(root == NULL)
    {
        return 0;
    }
    return 1 + min(GetMinHeightTree(root->left),GetMinHeightTree(root->right));
}

bool BinaryTree::IsEmpty()
{
    if(root == NULL)
        return true;
    return false;
}

void BinaryTree::InOrderTraverse()
{
    inOrder(root);
}

void BinaryTree::inOrder(Node* CurrentNode)
{
    if(CurrentNode == NULL)
        return;
    inOrder(CurrentNode->left);
    cout << CurrentNode->data << endl;   //Change the position of cout for preorder and post order
    inOrder(CurrentNode->right);
}

int BinaryTree::GetNodeCount()
{
    return nodeCount(root);
}

int BinaryTree::nodeCount(Node* CurrentNode)
{
    if(CurrentNode == 0)
        return 0;
    return 1 + nodeCount(CurrentNode->left) + nodeCount(CurrentNode->right);
}

int BinaryTree::GetLeafCount()
{
    return getleafs(root);
}

int BinaryTree::getleafs(Node *CurrentNode)
{
    if(CurrentNode == NULL)
        return 0;
    if(CurrentNode->left == NULL && CurrentNode->right == NULL)
        return 1;
    return (getleafs(CurrentNode->left) + getleafs(CurrentNode->right));
}

void BinaryTree::DestroyTree()
{
    destroyNode(root);
}

void BinaryTree::destroyNode(Node* CurrentNode)
{
    if(CurrentNode == NULL)
        return;
    if(CurrentNode->left == NULL && CurrentNode->right == NULL)
    {
        delete CurrentNode;
        CurrentNode = NULL;
    }
    destroyNode(CurrentNode->left);
    destroyNode(CurrentNode->right);
}

bool BinaryTree::IsPresent(int val)
{
    Node* currentNode = root;
    
    while(currentNode !=NULL)
    {
        if(val == currentNode->data)
            return true;
        if(val > currentNode->data)
        {
            currentNode = currentNode->right;
        }
        else
            currentNode = currentNode-> left;
    }
    return false;
}

bool BinaryTree::DeleteBSTNode(int val)
{
    bool bFound = false;
    Node* currentNode = root;
    Node* prevNode = NULL;
    
    while(currentNode)
    {
        if(currentNode->data == val)
        {
            bFound = true;
            break;
        }
        prevNode = currentNode;
        if(val > currentNode->data)
        {
            currentNode = currentNode->right;
        }
        else
            currentNode = currentNode-> left;

    }
    if(bFound == false)
        return false;
    
    if(currentNode->left == NULL && currentNode->right == NULL)
    {
        delete currentNode;
        currentNode = NULL;
    }
    
    if(currentNode->left == NULL)
    {
        if(currentNode->data > prevNode->data)
        {
            prevNode->right = currentNode->right;            
        }
        else
        {
            prevNode->left = currentNode->right;
        }
    }
    if(currentNode->right == NULL)
    {
        if(currentNode->data > prevNode->data)
        {
            prevNode->right = currentNode->left;
        }
        else
        {
            prevNode->left = currentNode->left;
        }
    }
    else
    {
         if(currentNode->data > prevNode->data)
         {
             Node* leafNode = currentNode->right;
             Node* leafPrevNode = currentNode;
             while(leafNode->left == NULL)
             {
                 leafPrevNode = leafNode;
                 leafNode = leafNode->left;
             }
             prevNode->right = leafNode;
             leafPrevNode->left = NULL;             
         }
         else
         {
             Node* leafNode = currentNode->left;
             Node* leafPrevNode = currentNode;
             while(leafNode->right == NULL)
             {
                 leafPrevNode = leafNode;
                 leafNode = leafNode->right;                 
             }
             prevNode->right = leafNode;
             leafPrevNode->right = NULL;             
         }
    }
    delete currentNode;
    currentNode = NULL;
}

void in_order_traversal_iterative(BinaryTree *root)
{
  stack<BinaryTree*> s;
  BinaryTree *current = root;
  while (!s.empty() || current) 
  {
    if (current) {
      s.push(current);
      current = current->left;
    } else {
      current = s.top();
      s.pop();
      cout << current->data << " ";
      current = current->right;
    }
  }
}


void BinaryTree::PreOrderTraverseIterative()
{
    stack<Node*> PreOrderStack;
    Node* currentNode = root;
    while(currentNode != NULL || !PreOrderStack.empty())
    {        
        if(currentNode != NULL)
        {
            cout << currentNode->data << endl;
            PreOrderStack.push(currentNode);
            currentNode = currentNode->left;

        }
        else
        {           
            currentNode = PreOrderStack.top();
             PreOrderStack.pop();
            currentNode = currentNode->right;
        }
    }    
}

void BinaryTree::PostOrderTraverseIterative()
{
    stack<Node*> PostOrderStack; //Does not work
    Node* currentNode = root;
    bool isLeftNode = true;
    while(currentNode != NULL || !PostOrderStack.empty())
    {
        if(currentNode != NULL)
        {
            PostOrderStack.push(currentNode);
            currentNode = currentNode->left;
            //isLeftNode = true;
        }
        else
        {
            currentNode = PostOrderStack.top();
            PostOrderStack.pop();
            cout << currentNode->data << endl;
            //currentNode = currentNode->right;
            if(currentNode == NULL && isLeftNode)
            {
                currentNode = PostOrderStack.top();
                //PostOrderStack.pop();
                currentNode = currentNode->right;
                isLeftNode = false;
            }
            else
            {
                isLeftNode = true;
            }
        }
    }
}

void BinaryTree::NonrecursivePostorder()
{
    BinaryTreeNode *current = root;
    stack<pair<BinaryTreeNode*, int>> stack;
    int traversingLeftOrRight = 0;//0 for root, 1 for left, 2 for right
    pair<BinaryTreeNode*, int> stackItem;
    
    if(current == NULL)
    {
        cout << "the tree is empty" <<endl;
        return;
    }
    else
    {
        stack.push(make_pair(current, 1));
        current = current->left;
        while(!stack.empty())
        {
            if(current != NULL && traversingLeftOrRight == 0)
            {
                stack.push(make_pair(current, 1));
                current = current->left;
            }
            else
            {
                stackItem = stack.top();
                stack.pop();
                current = stackItem.first;
                traversingLeftOrRight = stackItem.second;
                if(traversingLeftOrRight == 1)
                {
                    stack.push(make_pair(current, 2));
                    current = current->right;
                    traversingLeftOrRight = 0;
                }
                else    
                {
                    cout << current->data;
                }               
            }
        }        
    }    
}


void BinaryTree::BreadthFirstTraversal()
{    
    BFS(root);
}

void BinaryTree::BFS(Node* CurrentNode)
{    
    queue<Node*> Queue;
    if(CurrentNode !=NULL)
    {
        Queue.push(CurrentNode);
    }        
    while(!Queue.empty())
    {
        CurrentNode = Queue.front();
        cout << CurrentNode->data << endl;
        Queue.pop();
        if(CurrentNode->left)
            Queue.push(CurrentNode->left);
        if(CurrentNode->right)
            Queue.push(CurrentNode->right);        
    }
}

void BinaryTree::LevelPrinting()
{
    int height = GetTreeHeight(root);
    
    for(int level = 1; level <= height; level++)
    {
        levelPrint(root, level);
        cout << endl;
    }
    
}

void BinaryTree::levelPrint(Node* currentNode, int level)
{
    if(currentNode == NULL)
        return;
    if(level == 1)
        cout << currentNode->data << "\t";
    else
    {
        levelPrint(currentNode->left,level-1);
        levelPrint(currentNode->right,level-1);
    }    
}

void BinaryTree::ReversePrinting()
{
    int height = GetTreeHeight(root);
    
    for(int level = height; level > 0; level--)
    {
     levelPrint(root, level);
        cout << endl;
    }    
}

bool BinaryTree::IsBalanced()
{
    return((maxdepth(root) - mindepth(root)) < 2);
    //return checkBalance(root); -- MyLogic
}

int BinaryTree::maxdepth(Node* currentNode)
{
    if(currentNode == NULL)
            return 0;
    else
        return 1 + max(maxdepth(currentNode->left),maxdepth(currentNode->right));
}

int BinaryTree::mindepth(Node* currentNode)
{
    if(currentNode == NULL)
        return 0;
    else
        return 1 + min(maxdepth(currentNode->left),maxdepth(currentNode->right));
}

BinaryTree::BinaryTree(int sortedArray[], int length)
{
    root = new Node();
    root->data = getMedian(sortedArray,length);
    root->left = NULL;
    root->right = NULL;
 
    Node* currentNode = root;
    
    currentNode->left = createBTree(sortedArray,0,length/2 -1);
    currentNode->right = createBTree(sortedArray, length/2 +1, length-1);
    
}

 Node* BinaryTree::createBTree(int sortedArray[], int start, int end)
{
    Node* currentNode = new Node;
    currentNode->data = getMedian(sortedArray, end+1);
    currentNode->left = createBTree(sortedArray, 0,end/2 -1);
    currentNode->right = createBTree(sortedArray, end/2 + 1 , end);
    return currentNode;
}


int BinaryTree::getMedian(int sortedArray[], int length)
{
    return sortedArray[length/2];
}

bool BinaryTree::IsBST(Node* root)
{
    //do it as inorder traversal.. 
    //OR  check ValidateBST.cpp
}

Node* BinaryTree::FindCommonAncestorBest(Node* root, Node* node1, Node* node2)
{
    if(root == NULL)
        return root;
    if(root == node1 || root == node2)
        return root;
    Node* Left = FindCommonAncestorBest(root->left, node1,node2);
    Node* Right = FindCommonAncestorBest(root->right, node1,node2);
    if(Left && Right)
        return root;
    return Left? Left : Right;

}

Node* BinaryTree::FindCommonAncestor(Node* root, Node* node1, Node* node2)
{
    //This is for Binary tree not binary search tree
    if(root == NULL)
        return NULL;

    if(root->val == node1 || root->val == node2)
        return root;

    map<Node*,bool> visitedHash;

    while(node1)
    {
        visitedHash.insert(make_pair(node1, true));
        node1 = node1->parent;
    }
    while(node2)
    {
        if(visitedHash.find(node2))
            return node2;
        node2 = node2->parent;
    }
    return NULL;
}

Node* BinaryTree::FindCommonAncestorBST(Node* root, Node* node1, Node* node2)
{
    //This Binary search tree but O(n) space

    if(root == NULL)
        return NULL;

    if(root->val == node1->val || root->val == node2->val)
        return root;

    if(root->val > node1->val && root->val < node2->val)
        return root;

    if(root->val < node1->val && root->val > node2->val)
        return root;

    if(root->val > node1->val && root->val > node2->val)
        FindCommonAncestorBST(root->left , node1, node2);

    if(root->val < node1->val && root->val < node2->val)
        FindCommonAncestorBST(root->right, node1, node2);
}

Node* BinaryTree::FindCommonAncestorBSTbetter(Node* root, Node* node1, Node* node2)
{
    int h1 = GetTreeHeight(node1);
    int h2 = GetTreeHeight(node2);

    int diffheight;
    if(h1 > h2)
        diffheight = h1 - h2;
    else
    {
        diffheight = h2 - h1;
        swap(node1, node2);
    }
    
    for(int i =0; i< dh; i++)
        node1 = node1->parent;
    while(node2)
    {
        if(node1->val == node2->val)
            return node1;
        node1 = node1->parent;
        node2 = node2->parent;
    }   
    return NULL;
}






























