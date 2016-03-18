//
//  main.cpp
//  Object Oriented Chess
//
//  Created by Brooks Robison on 3/17/16.
//  Copyright © 2016 Dan McDaniel. All rights reserved.
//

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
   board.drawTest();
   board.interact();
   
   return 0;
}