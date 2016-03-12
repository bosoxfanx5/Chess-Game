//
//  chessboard.h
//  Object Oriented Chess
//
//  Created by Dan on 3/6/16.
//  Copyright © 2016 Brooks, Dan and Tom. All rights reserved.
//

#ifndef chessboard_h
#define chessboard_h

#include "board.h"
#include "chessboardsquare.h"
#include "chessmove.h"
#include "chesspiece.h"
#include <vector>

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


class Chessboard : public Board
{
public:
   void drawTest();
   ChessPiece getPieceAtLocation(Location location) {return squares[(int)location.x][(int)location.y].getPiece();}
   ChessboardSquare squares[8][8];
   std::vector<ChessMove> history;
};

#endif /* chessboard_h */
