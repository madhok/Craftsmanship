/*
Given an array of integers, find two numbers such that they add up to a specific target
 number.

The function twoSum should return indices of the two numbers such that they add up to 
the target, where index1 must be less than index2. Please note that your returned answers 
(both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int>result;
        int startIndex =0;
        int endIndex = numbers.size() -1;
        vector<int>copyNumbers = numbers;
        sort(numbers.begin(), numbers.end());
        while(startIndex < endIndex)
        {
            if(numbers[startIndex] + numbers[endIndex] == target)
            {
                result.push_back(numbers[startIndex]);
                result.push_back(numbers[endIndex]);
                break;
            }
                
            else if(numbers[startIndex] + numbers[endIndex] < target)
            {
                startIndex++;
            
            }
            else if(numbers[startIndex] + numbers[endIndex] > target)
            {
                endIndex--;
            }                
        }
        bool foundFirst = false;
        bool foundSecond = false;
        for(int i = 0; i< copyNumbers.size(); i++)
        {
            if(result[0] == copyNumbers[i] && !foundFirst)
            {
                result[0]= i+1;
                foundFirst = true;
            }
            else if(result[1] == copyNumbers[i] && !foundSecond)
            {
                result[1]= i+1;
                foundSecond =true;
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};