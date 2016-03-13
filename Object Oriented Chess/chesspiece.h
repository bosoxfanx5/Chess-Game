//
//  chesspiece.h
//  Object Oriented Chess
//
//  Created by Dan on 3/6/16.
//  Copyright © 2016 Brooks, Dan and Tom. All rights reserved.
//

#ifndef chesspiece_h
#define chesspiece_h

#include "piece.h"

class ChessPiece : public Piece
{
public:
   ChessPiece(bool isWhite) {}
   bool getIsWhite() {return isWhite;}
   virtual bool getLetter() {return ' ';}
   
   bool isWhite;
   
protected:
   //bool isWhite;
};

#endif /* chesspiece_h */
