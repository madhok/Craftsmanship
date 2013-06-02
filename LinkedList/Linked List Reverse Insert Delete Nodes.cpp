#include "Node.h"

Node::Node(int _data)
{
	data= _data;
	//next = NULL;
}	

void Node::DisplayNode(Node* list)
{
	while(list!= NULL)
	{
		cout << list->data << "\t" ;
		list = list->next;
	}	
}
	
Node* Node::ReverseLinkList(Node* currentNode)
{
	Node* temp;
	Node* prev = NULL;
	
	while(currentNode!= NULL)
	{
		temp = currentNode->next;
		currentNode->next = prev;
		prev = currentNode;
		currentNode = temp;
	}
	return currentNode;
}

Node* Node::AddNode(Node* newNode, Node* List)
{
	Node* temp;
	temp = List;
	
	while(List->next != NULL)
	{
		List = List->next;
	}
	List->next = newNode;
	newNode->next = NULL;
	
	List = temp;
	return List;
}

bool Node::InsertinFront(int newdata, Node** head)
{
	Node* newNode;
	newNode->data = newdata;
	newNode->next = *head;
	*head = newNode;
	
	return true;
	
}

Node* Node::Insert(int newData,int pos, Node* head)
{
    Node* newNode = new newNode(newData);
    Node* node = head;
    while(pos > 0)
    {
        node = node->next;
        pos--;
    }
    newNode->next = node->next;
    node->next = newNode;
    return head;
}