//
//  chessmove.h
//  Object Oriented Chess
//
//  Created by Dan on 3/6/16.
//  Copyright © 2016 Brooks, Dan and Tom. All rights reserved.
//

#ifndef chessmove_h
#define chessmove_h

#include "move1.h"
#include "chessboardsquare.h"
#include "chessboard.h"
#include <string>

class ChessMove : public Move1
{
public:
   ChessMove();
   ChessMove(std::string s, Chessboard & inBoard) : Move1() {moveString = s; board = &inBoard;}
   void parse();
   bool validate();
   void execute();
   std::string moveString;
   Chessboard * board;
};

#endif /* chessmove_h */
