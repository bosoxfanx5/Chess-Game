//
//  main.cpp
//  Object Oriented Chess
//
//  Created by Dan on 3/6/16.
//  Copyright © 2016 Dan McDaniel. All rights reserved.
//

#include <iostream>
#include "chessboard.h"

int main(int argc, const char * argv[])
{
   Chessboard board;
   board.load();
   while (board.interact())
      board.draw();
   
   // insert code here...
   std::cout << "Hello, World!\n";
    return 0;
}

