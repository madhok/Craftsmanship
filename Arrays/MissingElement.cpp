// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

void sort(vector<int>& A, int left, int right) 
{
      int i = left, j = right;
      int pivot = A[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (A[i] < pivot)
                  i++;
            while (A[j] > pivot)
                  j--;
            if (i <= j) 
            {
                  swap(A[i],A[j]);
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j)
            sort(A, left, j);
      if (i < right)
            sort(A, i, right);
  
}

int solution(vector<int> &A) {
    // write your code in C++11
    if(A.size() == 0) return 1;
    sort(A, 0, A.size()-1);
    int prev = 0;
    for(int i = 0; i < A.size(); i++) {
        if((A[i] -1) != prev) return (prev+1);
        prev = A[i];
    }
    return prev + 1;
}
