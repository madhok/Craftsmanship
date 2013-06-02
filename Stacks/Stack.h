//
//  Stack.h
//  Test
//
//  Created by Madhok Shivaratre on 11/23/12.
//  Copyright (c) 2012 Madhok Shivaratre. All rights reserved.
//

#ifndef __Test__Stack__
#define __Test__Stack__

#include <iostream>
#define STACK_MAX 100

class Stack
{
  private :
    int top = 0;
    int arr[STACK_MAX];
    
 public:
    Stack()
    {
        top = 0;
    }
    void push(int element);
    int pop();
};
#endif /* defined(__Test__Stack__) */
