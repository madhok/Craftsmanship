//
//  main.cpp
//  Trees
//
//  Created by Madhok Shivaratre on 3/10/13.
//  Copyright (c) 2013 Madhok Shivaratre. All rights reserved.
//

#include <iostream>
#include "BinaryTree.h"
int main(int argc, const char * argv[])
{
   
   
    BinaryTree Mytree(50);
    Mytree.InsertNode(2);
    Mytree.InsertNode(3);
    Mytree.InsertNode(5);
    Mytree.InsertNode(1);
    Mytree.InsertNode(3000);
    Mytree.InsertNode(0);
    
    Mytree.ReversePrinting();
    
    
    std::cout << "Hello, World!\n";
    return 0;
}

