/*
Write a program to find the element in an array that is 
repeated more than half number of times. 
Print repeated element if no such element is found.
*/

#include <iostream>
#include <map>

using namespace std;

//TIME COMPLEXITY IS O(n), SPACE COMPLEXITY IS O(2n)
bool getRepeatingElement(int array[], int size, int& repeatedElement)
{
    map<int, int> occurenceHashMap;
    map<int, int>::iterator iter;
    for(int i = 0; i<size; i++)
    {
        iter = occurenceHashMap.find(array[i]);
        if(iter == occurenceHashMap.end())
        {
            occurenceHashMap.insert(make_pair(array[i], 1));
        }
        else
        {
            iter->second++;
            if(iter->second > size/2)
            {
                repeatedElement = iter->first;
                return true;
            }
        }
    }
    return false;
}

//Time complexity is O(2n) and Space complexity is O(n)
//Boyer Moore Voting algorithm

bool getRepeatingElementBoyerMoore(int array[], int size, int& repeatedElement)
{
    if(size < 1)
        return false;
    int count = 0, i = 0;
    int currentCandidate = array[0];
    for(i = 0; i< size; i++)
    {
        if(currentCandidate == array[i])
        {
            count++;
        }
        else if(count == 0)
        {
            currentCandidate = array[i];
            count++;
        }
        else 
        {
            count--;
        }
    }
    
    
    for(i = 0; i< size; i++)
    {
        if(currentCandidate == array[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        if(count == -1) 
        {
            currentCandidate = array[i];
            count = 1;
        }
    }    

    //The second phase check if the candidate actually repeats more than half the times
    count = 0;
    for(i = 0; i< size; i++)
    {
        if(array[i] == currentCandidate)
        {
            count++;
            if(count > size/2)
            {
                 repeatedElement = currentCandidate;
                 return true;
            }
        }
    }
    return false;
}

bool Tests()
{
    int array1[] = {2,2,2,3,4,5,2,1};
    int repeatingElement = 0;
    if(!getRepeatingElement(array1, 7, repeatingElement) || repeatingElement != 2)
        return false;
    if(!getRepeatingElementBoyerMoore(array1, 7, repeatingElement) || repeatingElement != 2)
        return false;
        
    int array2[] = {2,1,2,3,2,4,2,1};    
    if(!getRepeatingElement(array2, 7, repeatingElement) || repeatingElement != 2)
        return false;
    if(!getRepeatingElementBoyerMoore(array2, 7, repeatingElement) || repeatingElement != 2)
        return false;
    
    int array3[] = {2,1,2,3,3,4,2,1};    
    if(getRepeatingElement(array3, 7, repeatingElement))
        return false;
    if(getRepeatingElementBoyerMoore(array3, 7, repeatingElement))
        return false;
    
    
    int array4[] = {1,1,3,4,5,6,2,2};    
    if(getRepeatingElement(array4, 7, repeatingElement))
        return false;
    if(getRepeatingElementBoyerMoore(array4, 7, repeatingElement))
        return false;

//    int array4[] = {1,1,2,2};    

    
    return true;
}


int main()
{
    if(!Tests())
    {
        cout << "Tests failed" << endl;
        return 0;
    } 
    
    int array[] = {2,2,2,3,4,5,2,1};
    
    int repeatingElement = 0;
    
    if(getRepeatingElement(array, 7, repeatingElement))
        cout << "Repeating element is " << repeatingElement << endl;
    else
        cout << "No element that repeats more than half the times in the array"<<endl;
    
    cout << "Using Boyer Moore voting algorithm:" << endl;
    
    if(getRepeatingElementBoyerMoore(array, 7, repeatingElement))
        cout << "Repeating element is " << repeatingElement << endl;
    else
        cout << "No element repeats more than half the times in the array"<<endl;

    return 0;
}
