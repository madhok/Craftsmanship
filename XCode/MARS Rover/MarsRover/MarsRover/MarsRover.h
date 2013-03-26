//
//  MarsRover.h
//  Trees
//
//  Created by Madhok Shivaratre on 3/24/13.
//  Copyright (c) 2013 Madhok Shivaratre. All rights reserved.
//

#ifndef __Trees__MarsRover__
#define __Trees__MarsRover__

#include <iostream>
#include <vector>

using namespace::std;

const int MAX = 100;
const int MIN = 0;

struct Position
{
    int x;
    int y;
    
    Position()
    {
        x = 0;
        y = 0;
    }
    void setPosition(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    
    void getPosition(int& x, int& y)
    {
        x = this->x;
        y = this->y;
    }
};

enum DIRECTION
{
    NORTH,
    SOUTH,
    EAST,
    WEST
};

class MarsRover
{
    Position Rover;
    DIRECTION currentDirection;
    bool gridObstacles[MAX][MAX];
    void setDirection(DIRECTION direction);
    bool changeRoverYPosition(int value);
    bool changeRoverXPosition(int value);
    bool moveForward();
    bool moveBackward();
    void turnLeft();
    void turnRight();
public:
    MarsRover()
    {
        currentDirection = NORTH;
        for(int x = 0; x < MAX; x++)
        {
            for(int y = 0; y < MAX; y++)
            {
                gridObstacles[x][y] = false;            
            }
        }
    }
    int getRoverXPosition()
    {
        return Rover.x;
    }
    int getRoverYPosition()
    {
        return Rover.y;
    }

    DIRECTION getCurrentDirection();
    void setObstacle(int X, int Y);
    bool isObstaclePresent(int newX, int newY);    
    bool setCommands(vector<char> commands);
};



#endif /* defined(__Trees__MarsRover__) */
