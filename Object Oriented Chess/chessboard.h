//
//  chessboard.h
//  Object Oriented Chess
//
//  Created by Dan on 3/6/16.
//  Copyright © 2016 Dan McDaniel. All rights reserved.
//

#ifndef chessboard_h
#define chessboard_h

#include "board.h"
#include "chessboardsquare.h"
#include "chessmove.h"
#include "chesspiece.h"
#include <vector>

class ChessBoard : public Board
{
   ChessBoardSquare squares[8][8];
   std::vector<ChessMove> history;
};

#endif /* chessboard_h */
