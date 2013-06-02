//
//  main.cpp
//  Test
//
//  Created by Madhok Shivaratre on 11/19/12.
//  Copyright (c) 2012 Madhok Shivaratre. All rights reserved.
//

#include <iostream>
#include "stdio.h"
#include "Header.h"
#include "Stack.h"
#include "Queue.h"

void rev_str(char* s)
{
    
    if(*s != '\0')
        rev_str(s+1);
    
    
    printf("%c",*s);
}

int main(int argc, const char * argv[])
{
    rev_str("born2c0de");
    return 0;
    //test code
  /*  MyClass Obj;
    Obj.x = 10;
    Obj.y = 20;
    
    char *p;
    p = (char*) malloc(sizeof(char)+ 1);
    sprintf(p, "%d", Obj.add());
    sprintf((p+2), "%d", Obj.add() + 9);
    std::cout << p;
    std::cout << *(p + 2);
    free(p);
  */  
    //Stack code
  /*  Stack myStack;
    myStack.push(100);
    myStack.push(200);
    myStack.push(400);
    myStack.push(500);
    std::cout << myStack.pop();
    std::cout << myStack.pop();
    std::cout << myStack.pop();
    std::cout << myStack.pop();
    std::cout << myStack.pop();
  
    
    //Queue code
    Queue myQueue;
    myQueue.add(100);
    myQueue.add(200);
    myQueue.add(300);
    myQueue.add(400);
    myQueue.del();
    myQueue.del();
    myQueue.del();
    myQueue.add(500);
    myQueue.add(600);
    myQueue.display();
    /*myQueue.del();
    myQueue.del();
    myQueue.del();
    myQueue.del();
    myQueue.del();
    myQueue.del();
    myQueue.display();
    */
    return 0;
}



