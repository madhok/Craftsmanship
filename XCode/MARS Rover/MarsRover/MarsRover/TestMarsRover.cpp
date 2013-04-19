//
//  TestMarsRover.cpp
//  MarsRover
//
//  Created by Madhok Shivaratre on 4/1/13.
//  Copyright (c) 2013 Madhok Shivaratre. All rights reserved.
//

#include "TestMarsRover.h"

void TestMarsRover::RunAllTests()
{
    if(!checkMovement())
        cout << "TEST FAILED!! MarsRover movement test failed." << endl;
    if(!checkBlocking())
        cout << "TEST FAILED!! MarsRover blocking " << endl;
    if(!checkBoundary())
        cout << "TEST FAILED!! MarsRover movement test failed." << endl;
}

bool TestMarsRover::checkMovement()
{   
    int initialXPosition = test.getRoverXPosition();
    int initialYPosition = test.getRoverYPosition();
    vector<char> mycommands = {'f','r','f','r','f','r','f','r'};
    test.setCommands(mycommands);
    if(test.getRoverXPosition() != initialXPosition)
        return false;
    if(test.getRoverYPosition() != initialYPosition)
        return false;
    
    mycommands = {'f','l','f','l','f','l','f','l'};
    test.setCommands(mycommands);
    if(test.getRoverXPosition() != initialXPosition)
        return false;
    if(test.getRoverYPosition() != initialYPosition)
        return false;

    return true;
}

bool TestMarsRover::checkBlocking()
{
    test.setObstacle(2,2);
    vector<char> mycommands = {'f','f','r','f', 'f'};
    test.setCommands(mycommands);
    if(test.getRoverXPosition() != 1)
        return false;
    if(test.getRoverYPosition() != 2)
        return false;
    
    return true;
}

bool TestMarsRover::checkBoundary()
{
    int initialXPosition = test.getRoverXPosition();
    int initialYPosition = test.getRoverYPosition();
    
    vector<char> mycommands;
    for(int i =0; i < MAX; i++)
        mycommands.push_back('f');
    test.setCommands(mycommands);
    if(test.getRoverYPosition() != initialYPosition)
        return false;
    mycommands.push_back('r');
    for(int i =1; i < MAX; i++)
        mycommands.push_back('f');
    if(test.getRoverXPosition() != initialXPosition)
        return false;
    
    return true;
}
