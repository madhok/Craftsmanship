/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note that if you end up using an additional array, you will only receive partial score.

Example:

If the array is 

1 2 3 4 5 6 7 8 9

Then the rotated array becomes: 

7 4 1 8 5 2 9 6 3
*/

#include <iostream>
#include <string>

using namespace std;

void print(int arr[3][3], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void transpose(int (&arr)[3][3], int n) {
    if(n == 1) return;
    for(int i = 0; i< n ; ++i) {
        for(int j = i; j < n ; j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
            //cout << "arr[i][j] " << arr[i][j] << endl;
            //cout << "arr[j][i] " << arr[j][i] << endl;
        }
        cout << endl;
    }
}

void reverse_rows(int (&arr)[3][3], int n) {
    for(int i = 0; i < n; ++i ) {
        int start = 0;
        int end = n -1;
        while(start<end) {
            int temp = arr[i][start];
            arr[i][start] = arr[i][end];
            arr[i][end] = temp;
            start++;
            end--;
        }
    }
}

int main()
{
  int index = 1;
  int arr[3][3];
  for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            arr[i][j] = index;
            index++;
        }
    }
    print(arr, 3);
    transpose(arr,3);
    reverse_rows(arr,3);
    print(arr, 3);
    
}
