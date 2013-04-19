/*
Function takes 32 bit unsigned integer and returns the number of 1 bits

*/

#include <iostream>

using namespace std;

int NumberOfBits(int number)
{
    int count = 0;
    while(number > 0)
    {
        if(number & 0x01)
            count++;
       number = number >> 1;     
    }
    return count;
}

struct Node
{
    int data;
    Node *next;
};

int main()
{
   /* int number;
  cout << "Enter the number" << endl;
    cin >> number;
    cout <<  NumberOfBits(number);  
   */ 
   int length;
   Node *newNode = new Node;
   Node *rootNode;
   Node *myNode = new Node;
   cout << "Enter the number of elements in the array" << endl;
   cin >> length;
   rootNode = myNode;
   for (int i = 0; i < length; i++)
   {
     cin >> myNode->data;
     if(i != length -1)
     {
        myNode->next = new Node;
        myNode = myNode->next;   
    }
   }
   myNode->next = rootNode;
   myNode= myNode->next;
   int nShift;
   cout << "Enter the value of the shift" << endl;
   cin >> nShift;
   while(nShift>0)
   {
        myNode = myNode->next;
        nShift--;
   }
   Node* startHere;
   startHere= myNode;
   cout << myNode->data <<endl;
   myNode = myNode->next;
   while(myNode != startHere)
   {
    cout << myNode->data << endl;
    myNode = myNode->next;
   }
    return 0;    
}
