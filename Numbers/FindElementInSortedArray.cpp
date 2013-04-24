/*
There is rotated sorted array.Write the program to find any element in that array 
Original Array A={1,2,3,5,6,7,8} 
Rotated Array B={5,6,7,8,1,2,3} 

Write the program to find any element in array B

*/
#include <iostream>
#include <vector>

using namespace std;

int findElement(vector<int> rotatedArray,int element, int startIndex, int endIndex)
{
    if(rotatedArray.size() == 0)
    {
        cout << "Element not found" << endl; 
        return -1;
    }
    
    if(startIndex > endIndex)
    {
        cout << "Element not found" << endl; 
        return -1;
    }
    else if(element == rotatedArray[startIndex])
    {
        cout << "Element found at Index " << startIndex << endl; 
    }
    else if(element == rotatedArray[endIndex])
    {
        cout << "Element found at Index " << endIndex << endl; 
    }
    else
    {
        int midIndex = startIndex + (endIndex - startIndex)/2;
        
        if(rotatedArray[startIndex] < rotatedArray[endIndex])
        {
            if(element >= rotatedArray[midIndex])
            {
                startIndex = midIndex;
            }
            else
            {
                endIndex = midIndex;
            }
        }
        else
        {
            if(element >= rotatedArray[midIndex])
            {
                startIndex = midIndex;
            }
            else
            {
                endIndex = midIndex;
            }
        }
      findElement(rotatedArray,element, startIndex+1, endIndex);  
    }
}

int main()
{
    vector<int>array;
    array.push_back(8);
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);
    array.push_back(6);
    array.push_back(7);
    findElement(array, 1, 0, array.size()-1);
}