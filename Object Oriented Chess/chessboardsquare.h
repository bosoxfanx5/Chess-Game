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
   ChessboardSquare();
   ChessPiece getPiece() {return piece;}
   
private:
   ChessPiece * piece; //Use a pointer to avoid slicing problem
};

#endif /* chessboardsquare_h */