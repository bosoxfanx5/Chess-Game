//
//  board.h
//  Object Oriented Chess
//
//  Created by Brooks Robison on 3/17/16...
//  Copyright © 2016 Dan McDaniel. All rights reserved.
//

#ifndef board_h
#define board_h

#include "piece.h"
#include "position.h"
#include <vector>
#include <string.h>

/////////////////
// Definitions //
/////////////////

//#define CLEAR "";       // null for debug
#define CLEAR "\E[H\E[2J";// clear screen
#define WW    "\E[31;47m" // white square, white piece
#define WB    "\E[30;47m" // white square, black piece
#define RW    "\E[37;41m" // red square, white piece
#define RB    "\E[30;41m" // red square, black piece
#define BW    "\E[0m"     // black background, white lettering
//#define TEMP "board.tmp"// temporary storage for board // opted for vector

class Piece; //Forward declaration (prototype)
class Board
{
public:
   Board() {};
   
private:
   float length = 0;
   float width  = 0;
   float height = 0;
   
public:
   //Chessboard() {};
   void init();
   void initk();
   void initq();
   void load();
   void draw();
   void undo();
   void drawTest();
   void writeFile();
   //Piece getPieceAtLocation(Position location) {return squares[location.getRow()][location.getCol()];}
   
   //Location Class //Array
   Piece * squares[8][8];
   void interact();// {std::cin; /*std::cin.ignore()*/; return true;}
   std::vector<std::string> history;
};

#endif /* board_h */
