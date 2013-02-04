#include <iostream>

using namespace std;

class Sorting
{
private:
void swap(int &a, int &b);
void printArray(int *array , int length);
void Test(int *SortedArray, int arrlength, string sortingMethod);

public:
void selectionSort(int* unsortedArray, int arrlength);
void bubbleSort(int *unsortedArray, int arrlength);
void insertionSort(int *unsortedArray, int arrlength);
};