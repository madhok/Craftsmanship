#include <iostream>

using namespace std;

class Sorting
{
private:
void swap(int &a, int &b);
void printArray(int *array , int length);
void Test(int *SortedArray, int arrlength, string sortingMethod);
void merge(int *unsortedArray, int start, int end);
void callMergeSort(int *unsortedArray, int start, int end);

public:
void selectionSort(int* unsortedArray, int arrlength);
void bubbleSort(int *unsortedArray, int arrlength);
void insertionSort(int *unsortedArray, int arrlength);
void quickSort(int *unsortedArray, int start, int end);
void shellSort(int *unsortedArray, int arrlength);
void mergeSort(int *unsortedArray, int start, int end);
};