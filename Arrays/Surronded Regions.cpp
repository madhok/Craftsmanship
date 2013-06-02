/*Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region .

For example,

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    int lastcolumn = board.size() - 1;    
    for(int row = 0; row < board.size(); row++)
    {
        if(board[row][0] == 'O')
        {
            DFS(board, row, 0); 
        }
            
        if(board[row][lastcolumn] == 'O')
        {
            DFS(board, row, lastcolumn); 
        }
    }
    
    int lastrow = board.size() - 1;    
    for(int col = 0; col < board.size(); col++)
    {
        if(board[0][col] == 'O')
        {
            DFS(board, 0, col); 
        }
            
        if(board[lastrow][col] == 'O')
            DFS(board, lastrow, col); 
    }
    
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board.size(); j++)
        {
            if(board[i][j] == 'O')
                board[i][j] = 'X';
            if(board[i][j] == '+')
                board[i][j] = 'O';
        }
    }
    }
    
    void DFS(vector<vector<char>>& board, int i, int j) {
        board[i][j] = '+';
        if (i - 1 >= 0 && board[i-1][j] == 'O')
            DFS(board, i - 1, j);
        if (j + 1 < board[0].size() && board[i][j+1] == 'O')
            DFS(board, i, j + 1);
        if (i + 1 < board.size() && board[i+1][j] == 'O')
            DFS(board, i + 1, j);
        if (j - 1 >= 0 && board[i][j-1] == 'O')
            DFS(board, i, j - 1);
    }
};