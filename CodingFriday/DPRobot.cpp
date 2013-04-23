/*
Imagine a robot sitting on the upper left corner of an X by Y grid. 
The robot can only move in two directions: right and down. 
How many possible paths are there for the robot to go from (0,0) to (X, Y)?
*/


int NumberOfWays(int X, int Y)
{
    if(X == 0 && Y == 0)
        return 0;
    
    if(X == 0)
        return 1;
     
    if(Y == 0)
        return 1;
            
    return NumberOfWays(X-1, Y) + return NumberOfWays(X, Y-1);
}


int NumberOfWaysDP(int X, int Y)
{
    int ways = 0;
    
    if(X == 0 && Y == 0)
        return 0;
    
    if(X == 0)
        return 1;
     
    if(Y == 0)
        return 1;
    
    for(int i = 0; i < X; i++)
        Grid[i][Y] = 1;
    for(int i = 0; i < X; i++)
        Grid[Y][i] = 1;
        
    for(int i = 1 ; i < X; i++)
    {
        for(int j = 1 ; j < Y; i++)
        {
            Grid[i][j] = max(Grid[i-1][j],Grid[i][j-1]) + 1;
        }
    }
    return Grid[X-1, Y-1];        
}

