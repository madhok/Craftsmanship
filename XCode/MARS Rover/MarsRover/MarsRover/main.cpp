//
//  main.cpp
//  MarsRover
//
//  Created by Madhok Shivaratre on 3/25/13.
//  Copyright (c) 2013 Madhok Shivaratre. All rights reserved.
//

#include <iostream>
#include "MarsRover.h"

bool checkNormal()
{
    MarsRover test;
    vector<char> mycommands = {'f','f','r','f', 'f'};
    test.setCommands(mycommands);
    if(test.getRoverXPosition() != 2)
        return false;
    if(test.getRoverYPosition() != 2)
        return false;
    
    return true;
}

bool checkBlocking()
{
    MarsRover test;
    test.setObstacle(2,2);
    vector<char> mycommands = {'f','f','r','f', 'f'};
    test.setCommands(mycommands);
    if(test.getRoverXPosition() != 1)
        return false;
    if(test.getRoverYPosition() != 2)
        return false;
    
    return true;
}

bool checkBoundary()
{
    MarsRover test;
    vector<char> mycommands;
    for(int i =0; i <= MAX; i++)
        mycommands.push_back('f');
    test.setCommands(mycommands);
    if(test.getRoverYPosition() != 0)
        return false;
    mycommands.push_back('r');
    for(int i =1; i <= MAX; i++)
        mycommands.push_back('f');
    if(test.getRoverXPosition() != 0)
        return false;
    
    return true;
}

int main(int argc, const char * argv[])
{
    
    if(!checkNormal() || !checkBlocking() || !checkBoundary())
    {
        cout << "Test failed" << endl;
        return -1;
    }
    
    
    //Check Blocking
    
    cout << "Test passed" << endl;
    return 0;
}

