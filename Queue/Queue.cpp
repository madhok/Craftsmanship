//
//  Queue.cpp
//  Test
//
//  Created by Madhok Shivaratre on 11/24/12.
//  Copyright (c) 2012 Madhok Shivaratre. All rights reserved.
//

#include "Queue.h"

Queue::Queue()
{
    nEndval = -1;
}
void Queue::add(int element)
{
    if (nEndval == QUEUE_MAX)
    {
        std::cout << "Queue is full.";
    }
    else
    {
        nEndval++;
        Elements[nEndval] = element;
    }
}

void Queue::del()
{
    if (nEndval == -1)
    {
        std::cout << "Queue is empty";
    }
    else
    {
        for (int j = 0; j < nEndval; j++)
        {
            Elements[j] = Elements[j+1];
        }
        Elements[nEndval] = NULL;
        nEndval--;
    }
}

void Queue::display()
{
    for(int j = 0; j <= nEndval; j++)
    {
        std::cout << Elements[j] << "\n";
    }
}