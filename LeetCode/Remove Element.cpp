/*Remove ElementFeb 16 '12
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int count = 0;
        for(int position = 0; position < n; position++)
        {
            if(A[position]!= elem)
            {
                A[count++] = A[position];               
            }
        }
        return count;
    }
};