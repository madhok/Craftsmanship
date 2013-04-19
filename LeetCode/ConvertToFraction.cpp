
#include <iostream>
using namespace std;

string getFraction(int num, int den)
{
    if(den == 0)
        return "error"; 
    //get the dvidend and the remainder
    int dividend = num/den;
    string fraction = to_string(dividend);
    int remainder = num%den;
    
    //place decimal
    
    int prevRemainder = remainder;
    if(remainder != 0)
    {
        fraction = fraction + ".";        
        remainder *= 10; 
    while(remainder !=0)
    {
        //Divide and get the remainder
        dividend = (remainder/den);
        remainder = remainder%den;
        if(prevRemainder == remainder)
        {
            fraction = fraction + "[" + to_string(dividend) + "]";
            break;
        }
        fraction = fraction + to_string(dividend);     
        prevRemainder = remainder;
        //multiply the remainder by 10 
        remainder *= 10; 
    }
    }
    return fraction;
}

int main() {
    // Start typing your code here...
    
    
    cout << getFraction(0, 0);
    
    return 0;
}