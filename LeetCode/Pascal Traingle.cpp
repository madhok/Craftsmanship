/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space? //NOTDONE*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> prevList;
        prevList.push_back(1);
        if(rowIndex < 1)
            return prevList;
        prevList.push_back(1);    
        vector<int> currentList;
        int currentIndex = 1;
        while(currentIndex != rowIndex)
        {
            currentList.clear();
            currentList.push_back(1);
            for(int i = 0; i < prevList.size() - 1; i++)
            {
                currentList.push_back(prevList[i] + prevList[i+1]);                
            }
            currentList.push_back(1);
            prevList.clear();
            prevList.swap(currentList);
            currentIndex++;           
        }
        return prevList;
    }
};

/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int>> pascalTriangle;
                
        if(numRows < 1)
            return pascalTriangle;
        vector<int>prevRow;
        prevRow.push_back(1);
        pascalTriangle.push_back(prevRow);
        
        if(numRows < 2)
        {           
           return pascalTriangle;
        }
            
        vector<int>row;
        int currentRow = 2;
        while(currentRow <= numRows)
        {
            row.clear();
            row.push_back(1);
            for(int i = 0; i< prevRow.size() - 1 ; i++)
            {
                row.push_back(prevRow[i] + prevRow[i+1]);                
            }
            row.push_back(1);
            pascalTriangle.push_back(row);
            prevRow.swap(row);
            currentRow++;
        }
        return pascalTriangle;
        
    }
};