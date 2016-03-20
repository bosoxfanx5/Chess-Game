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
#include <cctype>
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
    int r = position.getRow();  // index of source row
    int c = position.getCol();  // index of source col
    //bool w = isWhite;
    string l = "";
    int dest1_index = 0;   // row index of 1 square move
    int dest1_display = 0; // row display of 1 square move
    int dest2_index = 0;   // row index of 2 square move
    int dest2_display = 0; // row display of 2 square move
    string validMove;
    bool enPassant = true;

    dest1_index = isWhite ? r + 1 : r - 1;
    dest2_index = isWhite ? r + 2 : r - 2;
    dest1_display = dest1_index + 1;
    dest2_display = dest2_index + 1;
    // A Pawn can only move to 4 possible squares
    // 1 & 2) either of the two squares directly in front of it
    // 3 & 4) either of the two squares diagonally in front of it
    
    // first: can the pawn move 1 square forward
    if (board.squares[dest1_index][c]->getLetter() == ' ')
    {
        validMove = getCol(c) + std::to_string(r + 1) + getCol(c) + std::to_string(dest1_display);
        posMoves.push_back(validMove);
    }
    
    // second: has the pawn moved - can the pawn move 2 squares
    if (!board.squares[r][c]->fMoved)  // Pawn has not moved
    {
        if ((board.squares[dest1_index][c]->getLetter() == ' ') && (board.squares[dest2_index][c]->getLetter() == ' '))
        {
            validMove = getCol(c) + std::to_string(r + 1) + getCol(c) + std::to_string(dest2_display);
            posMoves.push_back(validMove);
        }
    }
 
    // third: can the pawn attack to the left
    if (!(board.squares[dest1_index][c - 1]->getLetter() == ' ') && c > 0)
    {
        validMove = getCol(c) + std::to_string(r + 1) + getCol(c - 1) + std::to_string(dest1_display);
        posMoves.push_back(validMove);
    }

    // fourth: can the pawn attack to the right
    if (!(board.squares[dest1_index][c + 1]->getLetter() == ' ') && c < 7)
    {
        validMove = getCol(c) + std::to_string(r + 1) + getCol(c + 1) + std::to_string(dest1_display);
        posMoves.push_back(validMove);
    }

    // fifth: can the pawn do an en passant
    if (board.history.size() >= 1 )
    {
        std::string lastMove = board.history[board.history.size() - 1];
        //std::cout << lastMove << std::endl;
        int pRow = lastMove[3] - '1'; // previous move Row Destination (Index)
        int pCol = lastMove[2] - 97;  // previous move Col Destination (Index)
        int pSourceRow = lastMove[1] - '1'; // previous move Row Destination (Index)
        //int pSourceCol = lastMove[0] - 97;  // previous move Col Destination (Index)
        
        if (tolower(board.squares[pRow][pCol]->getLetter()) == 'p')
        {
            if (pRow == r && (!((pSourceRow - pRow) % 2)))
            {
                if (pCol == (c - 1)) // Check left side
                {
                    validMove = getCol(c) + std::to_string(r + 1) + getCol(c - 1) + std::to_string(dest1_display) + 'e';
                    posMoves.push_back(validMove);

                }
                else if (pCol == (c + 1)) // Check right side
                {
                    validMove = getCol(c) + std::to_string(r + 1) + getCol(c + 1) + std::to_string(dest1_display) + 'e';
                    posMoves.push_back(validMove);
                }
            }
        }
    }
    
}

