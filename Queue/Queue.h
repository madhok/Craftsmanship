//
//  Queue.h
//  Test
//
//  Created by Madhok Shivaratre on 11/24/12.
//  Copyright (c) 2012 Madhok Shivaratre. All rights reserved.
//

#ifndef __Test__Queue__
#define __Test__Queue__

#include <iostream>

# define QUEUE_MAX 5

class Queue
{
private:
    int nEndval;
    int Elements[QUEUE_MAX];
public:
    Queue();
    void add(int element);
    void del();
    void display();
};

#endif /* defined(__Test__Queue__) */
