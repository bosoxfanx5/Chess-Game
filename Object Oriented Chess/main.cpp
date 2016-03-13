//
//  main.cpp
//  Object Oriented Chess
//
//  Created by Dan on 3/6/16.
//  Copyright © 2016 Brooks, Dan and Tom. All rights reserved.
//

#include <iostream>
#include "chessboard.h"

int main(int argc, const char * argv[])
{
   Chessboard board = Chessboard(); //default to clean board
   board.load();     //
   board.init();
   
   //std::cout << ".";
   
   //while (board.interact())
   //{
   //   std::cout << ".";
      board.drawTest();
   //}
   
   // insert code here...
   //std::cout << "Hello, World!\n";
    return 0;
}

