//
//  chessmove.h
//  Object Oriented Chess
//
//  Created by Dan on 3/6/16.
//  Copyright © 2016 Brooks, Dan and Tom. All rights reserved.
//

#ifndef chessmove_h
#define chessmove_h

#include "move.h"
#include "chessboardsquare.h"
#include "chessboard.h"
#include <string>

class ChessMove : public Move
{
public:
   ChessMove();
   ChessMove(std::string s, Chessboard & inBoard) : Move() {moveString = s; board = &inBoard;}
   void parse();
   bool validate();
   void execute();
   std::string moveString;
   Chessboard * board;
};

#endif /* chessmove_h */
