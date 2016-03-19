//
//  piece.cpp
//  Object Oriented Chess
//
//  Created by Brooks Robison on 3/17/16.
//  Copyright © 2016 Dan McDaniel. All rights reserved.
//

#include "piece.h"
#include "board.h"
#include <vector>
#include <iostream>
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

char getCol(int c)
{
    char columns[9] = {"abcdefgh"};
    
    return columns[c];
}

//Member Functions

void Space::getMoves(Board & board, Position & position)
{
}

void King::getMoves(Board & board, Position & position)
{
   //Tom:  Your code goes here.
//   King
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
   string validMove;
   bool qCastle = true;
   bool kCastle = true;
   
    // Validate squares immediately around the King
   for (int i = r - 1; i <= r + 1; i++)
      if (i >= 0 && i < 8)
      {
         for (int j = c - 1; j <= c + 1; j++)
            if (j >= 0 && j < 8)
            {
               l = board.squares[i][j]->getLetter();
               if (l == " " || w != board.squares[i][j]->getIsWhite())
               {
                  validMove = getCol(c) + std::to_string(r + 1) + getCol(j) + std::to_string(i + 1) + l;
                  posMoves.push_back(validMove);
                  //std::cout << "c" << j << "r" << i << " is valid" << std::endl;
               }
            }
      }
   // Check for castle move
    // syntax for castle move e1g1c (e8g1c) -> King Side, e1c1C (e8c1C) -> Queen Side
   if (!board.squares[r][c]->fMoved)    //King has NOT moved
   {
       if (!board.squares[r][0]->fMoved)  // Queen Side Rook has NOT moved
       {
           for (int i = 1; i < 4; i++)
               if (!(board.squares[r][i]->getLetter() == ' '))
               {
                   qCastle = false;
                   break;
               }
           if (qCastle)
           {
               validMove = getCol(c) + std::to_string(r + 1) + 'c' + std::to_string(r + 1) + 'C';
               posMoves.push_back(validMove);
           }
       }

       if (!board.squares[r][7]->fMoved)  // King Side Rook has NOT moved
       {
           for (int i = 5; i < 7; i++)
               if (!(board.squares[r][i]->getLetter() == ' '))
               {
                   kCastle = false;
                   break;
               }
           if (kCastle)
           {
               validMove = getCol(c) + std::to_string(r + 1) + 'g' + std::to_string(r + 1) + 'c';
               posMoves.push_back(validMove);
           }
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

