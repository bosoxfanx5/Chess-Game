//
//  chesspiece.h
//  Object Oriented Chess
//
//  Created by Dan on 3/6/16.
//  Copyright © 2016 Dan McDaniel. All rights reserved.
//

#ifndef chesspiece_h
#define chesspiece_h

#include "piece.h"

class ChessPiece
{
public:
   ChessPiece(bool isWhite) {}
   bool getIsWhite() {return isWhite;}
   
private:
   bool isWhite;
};

#endif /* chesspiece_h */
