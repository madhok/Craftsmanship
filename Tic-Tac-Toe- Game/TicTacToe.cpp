#include "TicTacToe.h"

void TicTacToe::StartGame()
{
    displayGameBoard();
    bool playerTurn = true;
    
    while(isBoardEmpty())
    {
        if(playerTurn)
        {
            acceptUserInput();
            if(isPlayerWin())
            {
                cout << "Congratulations!!!You WIN." << endl;
                return;
            }
            playerTurn = false;
        }
        else
        {
            computerMove();
            if(isComputerWin())
            {
                cout << "COMPUTER WINS" << endl;
                return;
            }
            playerTurn = true;
        }
    }
    cout << "MATCH DRAWN" << endl;
}

void TicTacToe::displayGameBoard()
{
    int boardRow = 1;    
    map<int,int>::iterator iter;
    for(iter = boardPosition.begin(); iter != boardPosition.end(); iter++)
    {
        if(iter->second == EMPTY)
            cout <<  " |" << iter->first;
        else
            cout << " |" << displayPlayer(iter->second);
        if(boardRow % ROW_SIZE == 0)
            cout << " |" << endl;
        boardRow++;
    }
}

string TicTacToe::displayPlayer(int player)
{
    string sPlayer = "";
    switch(player)
    {
        case PLAYER:
            sPlayer = "P";
            break;
        case COMPUTER:
            sPlayer = "C";
            break;
        default:
            break;
    }
    return sPlayer;
}

void TicTacToe::acceptUserInput()
{
    string input;
    cout << endl << "Enter the number to place your move ";
    getline(cin,input);
    while(cin.fail() || !isPositionValid(atoi(input.c_str())))
    {
        cin.clear();
        cout << "Invalid position. Reenter position!!" << endl;
        getline(cin,input);
    }
    boardPosition[atoi(input.c_str())] = PLAYER;
    displayGameBoard();
}

bool TicTacToe::isBoardEmpty()
{    
    map<int,int>::iterator iter;
    for (iter = boardPosition.begin(); iter != boardPosition.end(); ++iter )
    {
        if (iter->second == EMPTY)
            return true;
    }
    return false;
}

bool TicTacToe::isPositionValid(int pos)
{
    if((pos > 0) && (pos < (COLUMN_SIZE*ROW_SIZE + 1)))
    {
        if(boardPosition.find(pos)->second == EMPTY)
            return true;
    }
    return false;
}

void TicTacToe::computerMove()
{
    cout << "Computer places at position " << printComputerMove() << endl;
    displayGameBoard();
}

int TicTacToe::printComputerMove()
{
    int computerMove = generateRandom();
    boardPosition.find(computerMove)->second = COMPUTER;
    return computerMove;
}

int TicTacToe::generateRandom()
{
    if((isWinningMove(2,3) || isWinningMove(4,7) || 
             isWinningMove(5,9)) && isEmpty(1))
        return 1;
    else if((isWinningMove(1,3) || isWinningMove(5,8)) && isEmpty(2))
        return 2;
    else if((isWinningMove(1,2) || isWinningMove(6,9) || 
            isWinningMove(5,7)) && isEmpty(3))
        return 3;
    else if((isWinningMove(5,6) || isWinningMove(1,7)) && isEmpty(4))
        return 4;
    else if((isWinningMove(4,6) || isWinningMove(2,8) ||
             isWinningMove(1,9) || isWinningMove(3,7)) && isEmpty(5))
        return 5;
    else if((isWinningMove(4,5) || isWinningMove(3,9)) && isEmpty(6))
        return 6; 
    else if((isWinningMove(8,9) || isWinningMove(1,4) || 
                isWinningMove(3,5)) && isEmpty(7))
        return 7;
    else if((isWinningMove(7,9) || isWinningMove(2,5)) && isEmpty(8))
        return 8;
    else if((isWinningMove(7,8) || isWinningMove(3,6) ||
             isWinningMove(1,5)) && isEmpty(9))
        return 9;
    
    return randomEmptyPosition();
}

bool TicTacToe::isEmpty(int position)
{
    if(boardPosition.find(position)->second == EMPTY)
        return true;
    return false;
}

bool TicTacToe::isWinningMove(int pos1, int pos2)
{
    if((boardPosition.find(pos1)->second == COMPUTER) &&
       (boardPosition.find(pos2)->second == COMPUTER))
        return true;
    return false;    
}

int TicTacToe::randomEmptyPosition()
{
    vector<int> emptyPositions;
    map<int,int>::iterator iter;
    for(iter = boardPosition.begin();iter != boardPosition.end(); iter++)
    {
        if(iter->second == EMPTY)
            emptyPositions.push_back(iter->first);
    }    
    return emptyPositions[rand() % emptyPositions.size()];
}

bool TicTacToe::isPlayerWin()
{
    if(checkDiagonal(PLAYER) || checkRow(PLAYER) || checkColumn(PLAYER))
        return true;
    return false;
}

bool TicTacToe::isComputerWin()
{
    if(checkDiagonal(COMPUTER) || checkRow(COMPUTER) || checkColumn(COMPUTER))
        return true;
    return false;
}

bool TicTacToe::checkDiagonal(int winner)
{
    bool success = true;
    for(int i = 1; i <= COLUMN_SIZE*ROW_SIZE; i+= ROW_SIZE + 1 )
    {
        if(boardPosition.find(i)->second != winner)
        {
            success= false;
            break;
        }
    }
    if(!success)
    {
        success = true;
        for(int j = ROW_SIZE; j < COLUMN_SIZE*ROW_SIZE; j+= ROW_SIZE - 1 )
        {
            if(boardPosition.find(j)->second != winner)
            {
                success= false;
                break;
            }
        }
    }
    return success;
}

bool TicTacToe::checkRow(int winner)
{
    bool winning;
    for(int row = 1; row <= (COLUMN_SIZE*ROW_SIZE); row+=ROW_SIZE)
    {
        winning = true;
        for(int i = row; i < row + ROW_SIZE; i++)
        {
            if(boardPosition.find(i)->second != winner)
            {
                winning = false;
                break;
            }
        }
        if(winning)
            return true;        
    }
    return false;
}

bool TicTacToe::checkColumn(int winner)
{
    bool winning;
    for(int col = 1; col <= ROW_SIZE; col++)
    {
        winning = true;
        for(int i = col; i <= (COLUMN_SIZE*ROW_SIZE); i+= ROW_SIZE)
        {
            if(boardPosition.find(i)->second != winner)
            {
                winning = false;
                break;
            }
        }
        if(winning)
            return true;
    }
    return false;
}

bool TicTacToe::TestGame()
{
    if(!testDisplayGameBoard() || !testUserInput() ||
       !testComputerMove() || !testWinCondition())
        return false;
    return true;
}

bool TicTacToe::testDisplayGameBoard()
{
    if(ROW_SIZE != COLUMN_SIZE)
    {
        cout << "TEST FAILED!!!! Board size has to be a sqaure." << endl;
        return false;
    }
    if(boardPosition.size() != ROW_SIZE*COLUMN_SIZE)
    {
        cout << "TEST FAILED!!!! Board size is " << boardPosition.size() << endl;
        return  false;
    }
    return true;
}

bool TicTacToe::testUserInput()
{
    //Test for boundary conditions
    if(isPositionValid(ROW_SIZE*COLUMN_SIZE + 1) || 
        !isPositionValid(ROW_SIZE*COLUMN_SIZE))
    {
        cout << "TEST FAILED!!!! User input failed to pass boundary conditions." << endl;
        return false;
    }
    
    //Test for only valid numbers
    if(isPositionValid(atoi("A")) || isPositionValid(0) ||
        isPositionValid(atoi("@")))
    {
        cout << "TEST FAILED!!!! User input failed to pass validation test." << endl;
        return false;
    }
    return true;    
}

bool TicTacToe::testComputerMove()
{
    bool success = false;
    boardPosition.clear();
    //Test computer move
    for(int i = 1; i < (ROW_SIZE*COLUMN_SIZE) ; )
    {
        boardPosition.insert(pair<int,int>(i++,COMPUTER));
        boardPosition.insert(pair<int,int>(i++,PLAYER));
    }
    boardPosition.insert(pair<int,int>(ROW_SIZE*COLUMN_SIZE,EMPTY));
    if(printComputerMove() == ROW_SIZE*COLUMN_SIZE)
    {
        success = true;
    }
    boardPosition.clear();
    if(!success)
    {
        cout << "TEST FAILED!!!! Computer move Test failed." << endl;
    }
    return success;    
}

bool TicTacToe::testWinCondition()
{
    int i;
    boardPosition.clear();
    //Check  for row win condition
    for(i = 1; i <= ROW_SIZE ; i++)
    {
        boardPosition.insert(pair<int,int>(i,PLAYER));
    }
    if(!isPlayerWin())
    {
        boardPosition.clear();
        cout << "TEST FAILED!!!! Test Row Win failed." << endl;
        return false;
    }
    boardPosition.clear();
    
    //Check for Column Win Condition
    for(i = ROW_SIZE; i <= COLUMN_SIZE*ROW_SIZE ; i +=ROW_SIZE)
    {
        boardPosition.insert(pair<int,int>(i,PLAYER));
    }
    if(!isPlayerWin())
    {
        boardPosition.clear();
        cout << "TEST FAILED!!!! Test Column Win failed." << endl;
        return false;
    }
    boardPosition.clear();
    
    //Check for Diagonal Win Condition
    for(i = ROW_SIZE; i < COLUMN_SIZE*(ROW_SIZE) ; i +=ROW_SIZE - 1)
    {
        boardPosition.insert(pair<int,int>(i,PLAYER));
    }
    if(!isPlayerWin())
    {
        boardPosition.clear();
        cout << "TEST FAILED!!!! Test Diagonal Win failed." << endl;
        return false;
    }
    boardPosition.clear();
    
    //Check for MATCH DRAWN Condition
    int startPlayer = PLAYER;
    for(i = 1; i <= COLUMN_SIZE*ROW_SIZE ;i += ROW_SIZE)
    {
        if(i == 1)
        {
            for(;i < ROW_SIZE; i++)
            {
                boardPosition.insert(pair<int,int>(i,PLAYER));
            }
        }
        if(startPlayer == PLAYER)
            startPlayer = COMPUTER;
        else if(startPlayer == COMPUTER)
            startPlayer = PLAYER;
        for(int j = i; j < (i + ROW_SIZE) && j <= (COLUMN_SIZE*ROW_SIZE); j++)
        {
            boardPosition.insert(pair<int,int>(j,startPlayer));
        }        
    }
    if(isPlayerWin() || isComputerWin())
    {
        boardPosition.clear();
        cout << "TEST FAILED!!!! Test Match drawn failed." << endl;
        return false;
    }
    
    boardPosition.clear();
    return true;
}

