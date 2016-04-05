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

struct Node {
	int val;
	Node* next;
	Node(_val):val(_val),next(NULL) {} 
};

class Stack_linklist {
private:
	Node* curr;
public:
	Stack_linklist() {
		curr = new Node(0);
	}
	void push(int val);
	int pop();

};

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
