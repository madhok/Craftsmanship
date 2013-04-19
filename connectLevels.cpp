struct Node
{
  int val;
  Node* left;
  Node* right;
  Node* next;
};

void connect(Node* p) {
  if (!p) return;
  if (p->leftChild)
  p->leftChild->nextRight = p->rightChild;
  if (p->rightChild)
    p->rightChild->nextRight = (p->nextRight) ?
                               p->nextRight->leftChild :
                               NULL;
  connect(p->leftChild);
  connect(p->rightChild);
}

/// wrong solution

void ConnectNextNode(Node* parentNode)
{
 if(parentNode == NULL)
   return;

 Node* currentNode;
 Node* toConnectNode;
 
if(parentNode->left !=NULL)
 currentNode = parentNode->left;
else if(parentNode->right != NULL)
  currentNode = parent->right;
else
{
 cout << "Nothing to connect." << endl;
 return;
}

toConnectNode = nextConnectingNode(parentNode);
while(toConnectNode!= NULL)
{
  Node* temp =  nextConnectingNode(currentNode)
  toConnectNode = temp;
  currentNode->next = toConectNode;
  currentNode =temp;
}
 return;
}

Node* nextConnectingNode(Node* &parentNode)
{

while(parentNode!= NULL)
{
if(parentNode->left != NULL)
  return parentNode->left;
if(parentNode->right != NULL)
  return parentNode->right;
else
  parentNode = parentNode->next
}
return NULL;
}