class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(num.size() == 0)
            return 0;
        
        map<int,bool> number;
        map<int,bool>::iterator it;
        for(int i = 0; i< num.size(); i++)
            number.insert(pair<int,bool>(num[i],true));
        
        int maxLength = 1;
        int length = 1;
        bool reachedmax = false;
        for(int i = 0; i < number.size(); i++)
        {
            length = 0;
            int numTofind = num[i] -1;
            do
            {
                length++;   
                it = number.find(numTofind--);
            }while(it != number.end());
           
           numTofind = num[i] +1;
            it = number.find(numTofind++);
            while(it != number.end())
            {
                length++;
                it = number.find(numTofind++);
            }
            if(maxLength < length)
                maxLength = length;
            if(maxLength == number.size())
                break;
        }
        return maxLength;
    }
};