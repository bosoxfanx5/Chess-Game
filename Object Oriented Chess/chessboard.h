//
//  chessboard.h
//  Object Oriented Chess
//
//  Created by Dan on 3/6/16.
//  Copyright © 2016 Brooks, Dan and Tom. All rights reserved.
//

#ifndef chessboard_h
#define chessboard_h

#include "board1.h"
#include "chessboardsquare.h"

#ifndef chessmove_h
#define chessmove_h

#include "chessmove.h"

#endif


#include "chesspiece.h"
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


class Chessboard : public Board1
{
public:
   Chessboard() {};
   void init();
   void load(std::string filename);
   void draw();
   void drawTest();
   ChessPiece getPieceAtLocation(Location location) {return squares[(int)location.x][(int)location.y].getPiece();}
   
   //Location Class //Array
   ChessboardSquare squares[8][8];
   bool interact();// {std::cin; /*std::cin.ignore()*/; return true;}
   std::vector<std::string> history;
};

#endif /* chessboard_h */
