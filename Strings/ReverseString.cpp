#include <iostream>

using namespace std;

void swap(char &A, char &B)
{
    char temp = A;
    A = B;
    B = temp;
}

string ReverseString(string inp)
{
    int startIndex = 0;
    int endIndex = inp.length()-1;
    
    while(startIndex < endIndex)
    {
        swap(inp[startIndex],inp[endIndex]);
        startIndex++;
        endIndex--;
    }
    return inp;
}

int main()
{
    cout << ReverseString("adasdadeqwex")<< endl;
    
    return 0;
}

