#include <iostream>

using namespace std;


int findtheMaxelement(int *a, int start ,int end)
{
    bool isIncreasing;
    int middle = (start + end)/2;
    //find the middle three elements
    if((a[middle -1] < a[middle]) &&  (a[middle] < a[middle + 1])) 
    {
        cout << "middle " << a[middle] << endl;
        cout << "end " << a[end] << endl;
        findtheMaxelement(a, middle, end); 
    }
    if((a[middle -1] > a[middle]) && (a[middle] > a[middle + 1]))
    {
        cout << "decreasing" <<endl;
        cout << "middle " << a[middle +1] << endl;
        cout << "start " << a[start] << endl;
        findtheMaxelement(a, start, middle); 
    }
    else
        return a[middle];
}


int main()
{
    int nLength;
    cout << "Enter the length of the array" << endl;
    cin >> nLength;
    
    int *a = new int[nLength];
    cout << "Enter the array elements" << endl;
    for(int i = 0; i< nLength; i++)
    {
        cin >> a[i];
    }
  
    cout << findtheMaxelement(a,0,nLength-1);
  
    return 0;
}