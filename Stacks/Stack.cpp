//
//  Stack.cpp
//  Test
//
//  Created by Madhok Shivaratre on 11/23/12.
//  Copyright (c) 2012 Madhok Shivaratre. All rights reserved.
//

#include "Stack.h"

void Stack_linklist::push(int val) {
    Node* temp = new Node(val);
    Node* lastNode = curr->next;
    curr->next = temp;
    temp->next = lastNode;
}

int Stack_linklist::pop() {
    Node* next = cur->next;
    if(next== NULL) {
        cout << "Stack Empty" <<endl;
        return;
    }
    Node* new_top = next->next;
    cur->next = new_top;
    int ret_val = next->val;
    delete next;
    return ret_val;
}

void Stack::push(int a)
{
    if (top >= STACK_MAX)
    {
        std::cout << "Stack is full";
        return;
    }
    else
    {
        arr[top] = a;
        top++;
    }
}

int Stack::pop()
{
    if (top == 0)
    {
        std::cout << "Stack is empty";
        return -1;
    }
    else
    {
        top--;
        int data = arr[top];
        arr[top] = NULL;
        return data;
    }
}