//
//  main.cpp
//  Object Oriented Chess
//
//  Created by Brooks Robison on 3/17/16.
//  Copyright © 2016 Dan McDaniel. All rights reserved.
//

/************************************************************
 * Extra Credit:
 *     1.  Undo feature is available by typing in 'undo'
 ************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "board.h"

using namespace std;

int main()
{
   Board board = *new Board(); //default to clean board
   //board.load();     //
   board.init();
   board.draw();
   board.interact();
   
   return 0;
}