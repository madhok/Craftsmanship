class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool inverse = false;
        if(n < 0)
        {
            n = -n;
            inverse = true;
        }
            
        if (n == 0)
            return 1;
        
        double result = x;
        while(n > 1)
        {
            result = result * x; 
            n--;
        }
        
        if(inverse)
            return 1/result;
        return result;
    }
};

//recursive
class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool inverse = false;
        if(n < 0)
        {
            n = -n;
            inverse = true;
        }
            
        if (n == 0)
            return 1;
        
         x = x* pow(x, (n-1));
        
        if(inverse)
            return 1/x;
        return x;
    }
};