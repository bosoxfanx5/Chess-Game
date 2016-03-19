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

/*******************************************
* King::getMoves
* This gets all of the valid moves for the king.
* It modifies the piece's possible moves vector.
*******************************************/
void King::getMoves(Board & board, Position & position)
{
  
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
    //      There are only two spots a King can move to when castling: 2 squares to the left or 2 squares to the right.
    //      All squares between the King and the Rook must be empty

    // If the King has moved, Castling is NOT allowed.
    if (!board.squares[r][c]->fMoved)    //King has NOT moved
   {
       // If the Queen side Rook has moved, Queen side castling is NOT allowed
       if (!board.squares[r][0]->fMoved)  // Queen Side Rook has NOT moved
       {
           for (int i = 1; i < 4; i++)
               // If there are pieces between the King and the Rook,
               // Castling is NOT allowed
               if (!(board.squares[r][i]->getLetter() == ' '))
               {
                   qCastle = false;  // can NOT Queen side Castle
                   break;
               }
           // If qCastle = true, we CAN Queen side castle
           if (qCastle)
           {
               validMove = getCol(c) + std::to_string(r + 1) + 'c' + std::to_string(r + 1) + 'C';
               posMoves.push_back(validMove);
           }
       }
       // If the King side Rook has moved, King side castling is NOT allowed
       if (!board.squares[r][7]->fMoved)  // King Side Rook has NOT moved
       {
           for (int i = 5; i < 7; i++)
               // If there are pieces between the King and the Rook,
               // Castling is NOT allowed
               if (!(board.squares[r][i]->getLetter() == ' '))
               {
                   kCastle = false;  // can NOT King side Castle
                   break;
               }
           // If kCastle = true, we CAN King side castle
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
    int r = position.getRow();
    int c = position.getCol();
    bool w = isWhite;
    string l = "";
    int move1 = 0;
    int move2 = 0;
    string validMove;
    bool enPassant = true;

    move1 = isWhite ? r + 1 : r - 1;
    move2 = isWhite ? r + 2 : r - 2;
    
    // A Pawn can only move to 4 possible squares
    // 1 & 2) either of the two squares directly in front of it
    // 3 & 4) either of the two squares diagonally in front of it
    
    // first: can the pawn move 1 square forward
    if (board.squares[move1][c]->getLetter() == ' ')
    {
        validMove = getCol(c) + std::to_string(r) + getCol(c) + std::to_string(move1);
        posMoves.push_back(validMove);
    }
    
    // second: has the pawn moved - can the pawn move 2 squares
    if (!board.squares[r][c]->fMoved)  // Pawn has not moved
    {
        if ((board.squares[move1][c]->getLetter() == ' ') && (board.squares[move2][c]->getLetter() == ' '))
        {
            validMove = getCol(c) + std::to_string(r) + getCol(c) + std::to_string(move2);
            posMoves.push_back(validMove);
        }
    }
 
    // third: can the pawn attack to the left
    if (!(board.squares[move1][c - 1]->getLetter() == ' '))
    {
        validMove = getCol(c) + std::to_string(r) + getCol(c - 1) + std::to_string(move1);
        posMoves.push_back(validMove);
    }

    // fourth: can the pawn attack to the right
    if (!(board.squares[move1][c + 1]->getLetter() == ' '))
    {
        validMove = getCol(c) + std::to_string(r) + getCol(c + 1) + std::to_string(move1);
        posMoves.push_back(validMove);
    }

    // fifth: can the pawn do an en passant
    if (board.history.size() >= 1 )
        std::cout << board.history[board.history.size()] << std::endl;
}

