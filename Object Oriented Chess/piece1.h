//
//  piece.h
//  Object Oriented Chess
//
//  Created by Dan on 3/6/16.
//  Copyright © 2016 Brooks, Dan and Tom. All rights reserved.
//

#ifndef piece_h
#define piece_h

#include "move1.h"
#include <vector>

class Piece1
{
public:
   bool move();
   void getPossibleMoves(std::vector<Move1> moves);
};

#endif /* piece_h */
