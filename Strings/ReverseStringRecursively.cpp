#include<iostream>

using namespace std;

string reverseString(string givenStr)
{
    if(givenStr.length() > 1)
    { 
        return givenStr[givenStr.length()-1] 
            + reverseString(givenStr.substr(1,givenStr.length()-2)) 
                    + givenStr[0];
    } 
    return givenStr;
}

int main()
{
    cout << reverseString("adasdadeqwex")<< endl;
    
    return 0;
}

