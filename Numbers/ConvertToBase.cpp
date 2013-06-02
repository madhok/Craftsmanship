//Convert integer to another Base system


#include <iostream>
#include <stack>

using namespace std;

int ConvertToBase(int number, int base)
{
    int val = 0;
    stack<int>myStack;
    
    while(number >= base)
    {
        myStack.push(number%base);
        number = number/base ;
    }
    myStack.push(number);
    
    while(!myStack.empty()) 
    {
        int num = myStack.top();
        myStack.pop();
        val = val * 10 + num;
    }
    return val;
}

int main()
{
    cout << ConvertToBase(100,3);
    return 0;
}