/*
Maximum product of a triplet (subsequnece of size 3) in array
Given an integer array, find a maximum product of a triplet in array.

Examples:

Input:  [10, 3, 5, 6, 20]
Output: 1200
Multiplication of 10, 6 and 20
 
Input:  [-10, -3, -5, -6, -20]
Output: -90

Input:  [1, -4, 3, -6, 7, 0]
Output: 168
*/


#include <iostream>
#include <climits>

using namespace std;

void max3(int arr[],int size) {
    int maxA = INT_MIN, maxB = INT_MIN, maxC = INT_MIN;
    int minA = INT_MAX, minB = INT_MAX;
    for(int i= 0; i<size;++i) {
        if(arr[i] > maxA) {
            maxC = maxB;
            maxB = maxA;
            maxA = arr[i];
        } else if (arr[i]>maxB) {
            maxC = maxB;
            maxB = arr[i];
        } else if(arr[i] >maxC) {
            maxC = arr[i];
        }
        if(arr[i]<minA) {
            minB = minA;
            minA = arr[i];
        } else if(arr[i]<minB) {
            minB = arr[i];
        }
    }
    cout << maxA << maxB << maxC << endl;
    cout << minA << minB << endl;
    double res = max(maxA*maxB*maxC, minA*minB*maxA);
    cout << "Max product is " << res<< endl;
}

int main()
{
    int arr[5] = {10, 3, 5, 6, 20};
    max3(arr, 5);

    return 0;
}



