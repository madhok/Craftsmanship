/*
Given an alphanumeric array, sort it.

ex: A1 B7 C3 A21 B4
sorted: A1 A21 B4 B7 C3
*/

#include <iostream>
using namespace std;

set<string> sort(vector<string> &unsorted)
{
    set<string> sorted;
    for(int i = 0; i < unsorted.size(); i++)
    {
        sorted.insert(unsorted[i]);
    }
    
   return sorted;
    
}

int main() {
    // Start typing your code here...
    vector<string> unsorted;
    
    string array[] = {"A1","A7", "B3","C21", "A4"};
    unsorted.insert(unsorted.begin(), array, array+5);
    
    set<string> sorted;
    set<string>::iterator it;
    sorted = sort(unsorted);
    
    for (it=sorted.begin(); it!=sorted.end(); ++it)
     cout << ' ' << *it;
    cout << endl;
    
    
    return 0;
}

