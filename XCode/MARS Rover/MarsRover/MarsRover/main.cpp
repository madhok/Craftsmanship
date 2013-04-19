//
//  main.cpp
//  MarsRover
//
//  Created by Madhok Shivaratre on 3/25/13.
//  Copyright (c) 2013 Madhok Shivaratre. All rights reserved.
//

#include <iostream>
#include "MarsRover.h"
#include "TestMarsRover.h"

int main(int argc, const char * argv[])
{
    TestMarsRover testRover;
    testRover.RunAllTests();
    return 0;
}

