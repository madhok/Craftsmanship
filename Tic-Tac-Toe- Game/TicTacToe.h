#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

const int SIZE = 3;

enum PLAYER
{
    EMPTY = 0,
    PLAYER = 1,
    COMPUTER = 2
};

class TicTacToe
{
private:
    const int ROW_SIZE;
    const int COLUMN_SIZE;
    map<int,int> boardPosition;
    
    void displayGameBoard();
    string displayPlayer(int player);
    
    void acceptUserInput();
    bool isBoardEmpty();    
    bool isPositionValid(int pos);
    
    void computerMove();
    int printComputerMove();
    int generateRandom();
    bool isEmpty(int position);
    bool isWinningMove(int pos1, int pos2);
    int randomEmptyPosition();
    
    bool isPlayerWin();
    bool isComputerWin();
    bool checkDiagonal(int winner);
    bool checkRow(int winner);
    bool checkColumn(int winner);
        
    bool testDisplayGameBoard();
    bool testUserInput();
    bool testComputerMove();
    bool testWinCondition();
    
public:
    TicTacToe():ROW_SIZE(SIZE),COLUMN_SIZE(SIZE)
    {
        for(int i = 1; i <= ROW_SIZE*COLUMN_SIZE; i++)
        {
            boardPosition[i] = EMPTY;
        }
    }
    
    void StartGame();
    bool TestGame();
};
