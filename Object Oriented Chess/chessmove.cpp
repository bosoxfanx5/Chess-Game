//
//  chessmove.cpp
//  Object Oriented Chess
//
//  Created by Dan on 3/13/16.
//  Copyright © 2016 Dan McDaniel. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "chessmove.h"
#include "chesspieces.h"

void ChessMove::parse()
{
   std::string originString      = moveString.substr(0,1);
   int originRow = originString[1] - 48;
   int originCol = originString[0] - 65;
   
   std::string destinationString = moveString.substr(2,3);
   int destinationRow = destinationString[1] - 48;
   int destinationCol = destinationString[0] - 65;
   
   //origin->x = originRow;
   //origin->y = originCol;
   //origin->z = 0;
   //destination->x = destinationRow;
   //destination->y = destinationCol;
   //destination->z = 0;
   
   ChessboardSquare * originSquare = &board->squares[originRow][originCol];
   ChessboardSquare * destinationSquare = &board->squares[destinationRow][destinationCol];
   
   destinationSquare->piece = originSquare->piece;
   originSquare->piece = new Space();
   
   //(ChessboardSquare)destination->piece = (ChessboardSquare)origin->piece;
}

bool ChessMove::validate()
{
   moveString;
   return true;
}

void ChessMove::execute()
{
   moveString;
}