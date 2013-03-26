//
//  MarsRover.cpp
//  Trees
//
//  Created by Madhok Shivaratre on 3/24/13.
//  Copyright (c) 2013 Madhok Shivaratre. All rights reserved.
//

#include "MarsRover.h"

DIRECTION MarsRover::getCurrentDirection()
{
    return currentDirection;
}

void MarsRover::setDirection(DIRECTION direction)
{
    currentDirection = direction;
}

void MarsRover::setObstacle(int X, int Y)
{
    gridObstacles[X][Y] = true;
}

bool MarsRover::isObstaclePresent(int X, int Y)
{
    return gridObstacles[X][Y];
}

bool MarsRover::changeRoverYPosition(int value)
{
    if(!isObstaclePresent(Rover.x, Rover.y + value))
    {
        Rover.y = Rover.y + value;
        if(Rover.y > MAX)
            Rover.y = MIN;
        if(Rover.y < MIN)
            Rover.y = MAX;
        return true;
    }
    return false;
}

bool MarsRover::changeRoverXPosition(int value)
{
    if(!isObstaclePresent(Rover.x + value, Rover.y))
    {
        Rover.x = Rover.x + value;
        if(Rover.x > MAX)
            Rover.x = MIN;
        if(Rover.x < MIN)
            Rover.x = MAX;
        return true;
    }
    return false;
}

bool MarsRover::moveForward()
{
    bool success;
    switch (getCurrentDirection())
    {
        case NORTH:
            success = changeRoverYPosition(1);
            break;
            
        case SOUTH:
            success = changeRoverYPosition(-1);
            break;
            
        case EAST:
            success = changeRoverXPosition(1);
            break;
            
        case WEST:
            success = changeRoverXPosition(-1);
            break;
        default:
            break;
    }
    return success;
}

bool MarsRover::moveBackward()
{
    bool success;
    switch (getCurrentDirection())
    {
        case NORTH:
            success = changeRoverYPosition(-1);
            break;
            
        case SOUTH:
            success = changeRoverYPosition(1);
            break;
            
        case EAST:
            success = changeRoverXPosition(-1);
            break;
            
        case WEST:
            success = changeRoverXPosition(1);
            break;
        default:
            break;
    }
    return success;
}

void MarsRover::turnLeft()
{
    switch (getCurrentDirection())
    {
        case NORTH:
            setDirection(WEST);
            break;
        case SOUTH:
            setDirection(EAST);
            break;
        case EAST:
            setDirection(NORTH);
            break;
        case WEST:
            setDirection(SOUTH);
            break;
    }
}

void MarsRover::turnRight()
{
    switch (getCurrentDirection())
    {
        case NORTH:
            setDirection(EAST);
            break;
        case SOUTH:
            setDirection(WEST);
            break;
        case EAST:
            setDirection(SOUTH);
            break;
        case WEST:
            setDirection(NORTH);
            break;
    }
}

bool MarsRover::setCommands(vector<char> commands)
{
    bool success;
    for(int i = 0; i < commands.size();i++)
    {
        switch (commands[i])
        {
            case 'f':
                success = moveForward();
                break;
            case 'b':
                success = moveBackward();
                break;
            case 'l':
                turnLeft();
                break;
            case 'r':
                turnRight();
                break;
            default:
                break;
        }
        if(!success)
            break;
    }
    return success;
}

