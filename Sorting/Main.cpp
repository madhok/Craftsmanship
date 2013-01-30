#include <iostream>
#include "Sorting.h"
using namespace std;

int main()
{
    int length;
    int *array;
    cout << "Enter the length of the array" << endl; 
    cin >> length;
    array = new int[length];
    cout << "Enter the values of the array" << endl; 
    for(int i = 0; i< length ; i++)
    {
        cin >> array[i];
    } 
    
    Sorting objSort;
    //Selection Sort    
    objSort.selectionSort(array, length);  
    //Bubble Sort
    objSort.bubbleSort(array, length);
    //Insertion Sort
    
    delete[] array;
    return 0;
}