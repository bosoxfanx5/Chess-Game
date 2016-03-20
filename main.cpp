/***************************************************************************
 * Program:
 *    Project 3, Object Oriented Chess
 *    Brother McCracken, CS165
 * Authors:
 *    Dan McDaniel, Brooks Robison, Thomas Woodworth
 * File Summary:
 *    Main.cpp creates a new board and starts a new game.
 ***************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "board.h"

using namespace std;

/************************************************************
 * MAIN
 *     This function starts a new game and prompts the user
 * for input through the interact function.
 ************************************************************/
int main()
{
   Board board = *new Board(); //default to clean board
   //board.load();     //
   board.init();
   board.draw();
   board.interact();
   
   return 0;
}