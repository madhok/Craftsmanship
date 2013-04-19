#include <iostream>

using namespace std;

void PrintNumbers(int endRange, int divisibleBy)
{
    int negative = 1;
    if(endRange < 0)
        negative = -1;
    int currentNum = 1;
    while(currentNum < abs(endRange))
    {
        if(currentNum % divisibleBy == 0)
            cout << negative * currentNum << ", "; 
        currentNum++;    
    }
    cout << endl;
}

void PrintPow2Numbers(int endRange)
{
    if(endRange <= 0)
        return;
    
    int currentNum = 1;
    
    while(currentNum <= endRange)
    {
       cout << currentNum << ", ";
       currentNum = currentNum << 1 ;
    }
    cout << endl;
        
}

void PrintPowNumbers(int endRange, int Number)
{
    if(endRange < 0)
        return;
    
    int currentNum = 1;
    while(currentNum < endRange)
    {
        cout << currentNum << ", ";
        currentNum = currentNum * Number;
    }
    cout << endl;    
}

int main()
{
    PrintPowNumbers(100,5);
    
    return 0;
}