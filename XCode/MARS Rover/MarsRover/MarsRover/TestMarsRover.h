//
//  TestMarsRover.h
//  MarsRover
//
//  Created by Madhok Shivaratre on 4/1/13.
//  Copyright (c) 2013 Madhok Shivaratre. All rights reserved.
//

#ifndef __MarsRover__TestMarsRover__
#define __MarsRover__TestMarsRover__

#include <iostream>
#include "MarsRover.h"

class TestMarsRover
{
    MarsRover test;
    bool checkMovement();
    bool checkBlocking();
    bool checkBoundary();

public:
    void RunAllTests();
    };

#endif /* defined(__MarsRover__TestMarsRover__) */
