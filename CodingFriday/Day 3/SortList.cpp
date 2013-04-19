#include <iostream>

struct Node
{
    int val;
    Node* next;
};

Node* deleteNextNode(Node* root)
{
    root->next = root->next->next;
    return root;
}

Node* SortLinkedList(Node* root)
{
    while(root->next!=NULL)
    {
        if(root->val == root->next->val)
        {
            root = deleteNextNode(root);
        }
        root = root->next;
    }
    return root;
}

int main()
{
    int length;
    cout << "Enter the number elements in the array";
    cin >> length;
    
    Node *sample;
    int array[10] = {1,1,2,2,3,4,5,6,7,7};

    for(int i = 0; i < 10; i++)
    {
        sample->val = array[i];
        sample = sample->next;
    }
    return 0;
}