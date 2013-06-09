//WOrks for larger numbers


class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0)
            return 1;
        if(x == 0 || x == 1 || n == 1)
            return x;
        bool inverse = false;
        if(n < 0)
        {
            inverse = true;
            n = -1 * n;
        }
            
            
        double temp = x;
        double result = 1.0;
        for(int i = n; i >0; i =i/2)
        {
            if(i%2 == 1)
                result = result * temp;
            temp = temp * temp;    
        }
        if(inverse)
            return 1.0/result;
        return result;
    }
};




//Does not work for large numbers





class Solution {
public:

double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool inverse = false;
        
        if (n == 0)
            return 1;
        if(n == 1 || x == 1)
            return x;    
        if(n < 0)
        {
            n = -n;
            inverse = true;
        }
        bool isOdd = false;
        
        if(n%2 == 1)
        {
            isOdd = true;
            n--;
        }
        
        double result = x;
        while(n > 1)
        {
            result = result * result; 
            //n = n/2; 
            n = n >>1;
        }
        
        if(isOdd)
            result = result * x;
        if(inverse)
            return 1/result;
        return result;
    }



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