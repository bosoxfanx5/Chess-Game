//
//  chessboardsquare.h
//  Object Oriented Chess
//
//  Created by Dan on 3/6/16.
//  Copyright © 2016 Brooks, Dan and Tom. All rights reserved.
//

#ifndef chessboardsquare_h
#define chessboardsquare_h

#include "location.h"
#include "chesspiece.h"

class ChessboardSquare : Location
{
public:
   ChessboardSquare() {};
   ChessboardSquare(ChessPiece inPiece) {piece = &inPiece;};
   ChessPiece getPiece() {return piece;}
   char getLetter() {return piece->getLetter();}
   
   //Could be any chess piece derived from ChessPiece (King, etc...)
   ChessPiece * piece; //Use a pointer to avoid slicing problem
};

#endif /* chessboardsquare_h */