#include <iostream>
#include "TicTacToe.h"

void RunTictacToeGameTest()
{
    TicTacToe Game;
    if(Game.TestGame())
        cout << "Tests successful" << endl;
    return;
}

int main(int argc, const char * argv[])
{
    RunTictacToeGameTest();
    
    TicTacToe myGame;
    myGame.StartGame();    
    return 0;
}

void RunTests()
{
    TicTacToe Game;
    Game.TestGame();
}