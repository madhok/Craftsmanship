/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

*/


class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(word.length() == 0)
            return true;
            
        int rowLength = board[0].size();
        int colLength = board.size();
        for(int col = 0; col < colLength; col++)
        {
            for(int row =0; row < rowLength; row++)
            {
                if(board[col][row] == word[0])
                {
                    if(checkpath(board,row,col,word));
                        return true;
                }
            }
        }
        return false;
        
    }
    
    bool checkpath(vector<vector<char> > &board, int row, int col, string word)
    {
        vector<bool>rowvisited(board[0].size(),false);
        vector<vector<bool>>visited(board.size(), rowvisited);
        int maxCol = board.size();
        int maxRow = board[0].size();
        
        int i = 0;
        while(i < word.length())
        {
            if(word[i] == board[col][row] && visited[col][row] == false)
            {
                i++;   
                visited[col][row] = true;
            }
            else if(col > 0 && col <= maxCol && word[i] == board[col-1][row] && visited[col-1][row] == false)
            {
                i++;
                visited[col-1][row] = true;
                col--;
            }
            else if(row > 0 && row <= maxRow && word[i] == board[col][row-1] && visited[col][row-1] == false)
            {
                i++;
                visited[col][row-1] = true;
                row--;
            }
            else if(col < maxCol-1 && col >= 0 && word[i] == board[col+1][row] && visited[col+1][row] == false)
            {
                i++;
                visited[col+1][row] = true;
                col++;
            }
            else if(row < maxRow-1 && row >= 0 && word[i] == board[col][row+1] && visited[col][row+1] == false)
            {
                i++;
                visited[col][row+1] = true;
                row++;
            }
            else
                return false;
        }
        return true;
    }
    
    
};