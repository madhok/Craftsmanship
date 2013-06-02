/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

*/


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


//Insert in set is not nlogn. it is implemented as a binary tree and so it logn. so this alogorithm works
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        set<int> result;
        for(int i = 0; i< num.size(); i++)
        {
            result.insert(num[i]);
        }
        set<int>::iterator it;
        int maxcount = 1;
        int count = 1;
        it = result.begin();
        int prev = *it;
        it++;
        for(; it != result.end(); it++)
        {
            if(*it == (prev + 1))
                count++;
            else
                count = 1;
            
            prev = *it;
            if(maxcount < count)
                maxcount = count;
        }
        return maxcount;
    }
};