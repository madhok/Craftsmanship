#include <iostream>
#include <map>

using namespace std;

int boyerMoore(int arr[]) //To find only the most repeated element 
                          //and the repeated element is more than half of the array
{
    int current_candidate = arr[0], counter = 0, i;
    for (i = 0; i < SIZE; ++i) {
        if (current_candidate == arr[i]) {
            ++counter;
        } else if (counter == 0) {
            current_candidate = arr[i];
            ++counter;
        } else {
            --counter;
        }
    }
    return current_candidate;
}


bool GetRepeatedElement(int inpArr[],int size, int &repeatedElement,int &maxCount)
{
    map<int,int>hashMap;
    map<int,int>::iterator it; 
    
    if(size == 0)
        return false;
       
    for(int i = 0; i < size; i++)
    {
        it = hashMap.find(inpArr[i]);
        if(it == hashMap.end())
        {
            hashMap.insert(make_pair(inpArr[i],1));  //pair<int,int>(inpArr[i],1)          
        }
        else
        {
            it->second++;
        } 
    }
    
    it = hashMap.begin();
    for(it = hashMap.begin(); it != hashMap.end();it++)
    {
        if(it->second > maxCount)
        {
            repeatedElement = it->first;
            maxCount = it->second;
        }
    }
    return true;
}

int main()
{
    int array[10] = {1,2,3,4,5,3,3,2,3,3};
    
    int maxCount = 0;
    int repeatedElement = 0;
    bool found = false;
    found = GetRepeatedElement(array, 10, repeatedElement,maxCount);
    if(found)
    {
        cout << "Repeated Element is " << repeatedElement << endl;
        cout << "Maximium count of repeated Element is " << maxCount << endl;
    }
    else{
        cout << "Array size id zero" << endl;
    }
    return 0;
}