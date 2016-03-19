//
//  piece.cpp
//  Object Oriented Chess
//
//  Created by Brooks Robison on 3/17/16.
//  Copyright © 2016 Dan McDaniel. All rights reserved.
//

#include <stdio.h>
#include "piece.h"
#include "board.h"
#include <vector>
//#include "position.h"

//Non-Member Functions

std::vector<std::string> getDiagMoves(Board & board, Position & position)
{
   std::vector<std::string> posMoves;
   
   //Tom:  Your code goes here.
   
   return posMoves;
}

std::vector<std::string> getLinearMoves(Board & board, Position & position)
{
   std::vector<std::string> posMoves;
   
   //Tom:  Your code goes here.
   
   return posMoves;
}




//Member Functions

void King::getMoves(Board & board, Position & position)
{
   //Tom:  Your code goes here.
//   King
//   Get Possible moves from current position if board was empty
//      Min row/col = 0
//      Max row/col = 7
//      Get standard possible moves
//      For r = piece.r - 1 to piece.r + 1
//       IF r >= 0 && r < 8
//        For c = piece.c -1 to piece.c + 1
//         IF c >= 0 && c < 8
//          IF board[r][c].piece(isWhite) !=  source.piece(isWhite)
//           possibleMove = rc
//   
//      
//      2. with a rook that has already moved.
//      ***Add variable to King and Rook Classes: bool hasMoved
//      If (!King.hasMoved)
//      If (!Rook1.hasMoved)
//      Do more checks
//      If (!Rook2.hasMoved)
//      Do more checks
//      
//      There are only two spots a King can move to when castling: 2 squares to the left or 2 squares to the right.
//      All squares between the King and the Rook must be empty
//      For c = 1 to 3  // Queenside Castle; R = Row of King (either 0 or 7)
//      IF (!board[R][c].piece = EMPTY)
//      qCastle = false
//      IF c > 1  && qCastle = true  // check if space is
//      
//      For c = 5 to 6  // Kingside Castle; R = Row of King (either 0 or 7)
//      IF (!board[R][c].piece = EMPTY)
//      kCastle = false
   
   int r = position.getRow();
   int c = position.getCol();
   bool w = isWhite;
   string l = "";
   
   for (int i = r - 1; i <= r + 1; i++)
      if (i >= 0 && i < 8)
      {
         for (int j = c - 1; j <= c + 1; j++)
            if (j >= 0 && j < 8)
            {
               l = board.squares[i][j].Piece.getLetter();
               if (l == " " || w != board.squares[i][j].Piece.isWhite)
                  posMoves.push_back(&"" [ (r * 1000 + c * 100 + i * 10 + j)] + l);
                  posMoves.push_back("rcijl");
            }
      }
}

void Queen::getMoves(Board & board, Position & position)
{
   
   //Tom:  Your code goes here.

}

void Bishop::getMoves(Board & board, Position & position)
{
   
   //Tom:  Your code goes here.
   
}

void Knight::getMoves(Board & board, Position & position)
{
   
   //Tom:  Your code goes here.
   
}

void Rook::getMoves(Board & board, Position & position)
{
   
   //Tom:  Your code goes here.
   
}

void Pawn::getMoves(Board & board, Position & position)
{
   
   //Tom:  Your code goes here.

}

