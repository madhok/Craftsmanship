/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/


class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        double val = x;
        double estimate = val - 0.1;
        double efficiency = 0.001;
        while(fabs(estimate - val) > efficiency)
        {
            val = estimate;
            estimate = val - (val * val - x)/(2*val);  // babylonian algorithm val - (val - (x/val))/2
        }
        return estimate;
    }
    
};
//Binary search method
class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long high = x;
        long long low = 0;
        if (x<=0) {return 0;}
        if (x==1) {return 1;}
        while (high-low >1){
            long long mid = low + (high-low)/2;
            if (mid*mid<=x){low = mid;}
            else {high = mid;}
        }
        return low;
    }
};
