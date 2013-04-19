class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int number = 0;
        int startIndex = 0; 
        int j = 0;
        if(strlen(str) == 0)
            return 0;
        bool isNegative = false;
        while(str[startIndex] != ' ')
        {
            startIndex++;
        }
        if(str[startIndex] == '-')
        {
            isNegative = true;   
            startIndex++;
        }
        if(str[startIndex] == '+')
        {
            isNegative = false;   
            startIndex++;
        }
         
        if(isNumberValid(str, startIndex))
        {   
            for(int i =startIndex; i < strlen(str); i++)
            {
                number = number * 10 + getNumber(str[i]);                     
            }
            if(isNegative)
                number = -1 * number;
            
            return number;
        }
        return 0;
    }
    
    int getNumber(const char str)
    {
        switch(str)
        {
            case '0':
                return 0;
                
            case '1':
                return 1;
            
            case '2':
                return 2;
                
            case '3':
                return 3;
                
            case '4':
                return 4;
                
            case '5':
                return 5;
            
            case '6':
                return 6;
                
            case '7':
                return 7;
            
            case '8':
                return 8;
                
            case '9':
                return 9;
            
            default:
                return -1;            
        }
    }
    
    bool isNumberValid(const char *str, int startIndex)
    {
        for(int i = startIndex; i < strlen(str); i++)
        {                   
            int val = getNumber(str[i]);
            if((val >= 0 && val <= 9))
                continue;
            else
                return false;
        }
        return true;
    }
};