//
//  this->cpp
//  Object Oriented Chess
//
//  Created by Brooks Robison on 3/17/16.
//  Copyright © 2016 Dan McDaniel. All rights reserved.
//

#include <iostream>
#include "move.h"
#include <cassert>
#include <cctype>
using namespace std;

// Both of these define variables were part of Brother Helfrich's design
#define NO_PIECE ' '   // There is no piece on this location of the board
#define INVALID 127    // invalid row or column value

void Move::execute()
{
   
   bool isWhite = board->squares[source.getRow()][source.getCol()]->getIsWhite();
   // Set destination square equal to the source square - this gets all the attributes of the
   // source square with the piece
   board->squares[dest.getRow()][dest.getCol()] = board->squares[source.getRow()][source.getCol()];
   // set fMoved to true - regardless of what piece it is
   board->squares[dest.getRow()][dest.getCol()]->fMoved = true;
   // Set the source square to an empty square
   board->squares[source.getRow()][source.getCol()] = new Space();
   if (promote)
   {
      switch (moveString[4])
      {
         case 'c':  // short castling or kings castle
         {
            board->squares[dest.getRow()][5] = board->squares[source.getRow()][7];
            board->squares[source.getRow()][7] = new Space();
            break;
         }
         case 'C':  // long castling or queen castle
         {
            board->squares[dest.getRow()][3] = board->squares[source.getRow()][0];
            board->squares[source.getRow()][0] = new Space();
            break;
         }
         case 'E':  // En-passant
         {
            string lastMove = board->history[board->history.size() - 1];
            Position posLastMove(lastMove[2], lastMove[3]);
            board->squares[posLastMove.getRow()][posLastMove.getCol()] = new Space();
            break;
         }
         case 'N':  // Promote to knight
            board->squares[dest.getRow()][dest.getCol()] = new Knight(isWhite);
            break;
         case 'B':  // Promote to Bishop
            board->squares[dest.getRow()][dest.getCol()] = new Bishop(isWhite);
            break;
         case 'R':  // Promote to Rook
            board->squares[dest.getRow()][dest.getCol()] = new Rook(isWhite);
            break;
         case 'Q':  // Promote to Queen
            board->squares[dest.getRow()][dest.getCol()] = new Queen(isWhite);
            break;
      }
   }
}

void Move::parse() throw(string)
{
   string text = this->moveString;
   
   //Position source, dest;
   source.setRow(INVALID);
   source.setCol(INVALID);    // where the move originated from
   
   dest.setRow(INVALID);
   dest.setCol(INVALID);    // where the move originated from
   
   char      piece     = NO_PIECE;   // piece to be promoted to
   char      capture   = false;      // Piece to capture
   char      promote   = false;      // Piece to promote to
   bool      enpassant = false;      // Enpassant pawn capture
   bool      castleK   = false;      // kingside castle
   bool      castleQ   = false;      // queenside castle
   bool      isWhite   = false;      // white's move?
   
   isWhite = !(board->history.size() % 2);
   
   //
   // from square
   //
   
   // column: a-h
   if (text[0] < 'a' || text[0] > 'h')
      throw string("Invalid format of source coordinates");
   source.setCol(text[0] - 'a');
   assert(source.getCol()>= 0 && source.getCol() <= 7);
   
   // row: 1-8
   if (text[1] < '1' || text[1] > '8')
      throw string("Invalid format of source coordinates");
   
   source.setRow(text[1] - '1');
   assert(source.getRow() >= 0 && source.getRow() <= 7);
   
   // if there is nothing to move, we have an error
   piece = tolower(board->squares[source.getRow()][source.getCol()]->getLetter());
   if (this->piece == NO_PIECE)
      throw string("No piece in the source coordinates position");
   
   // if source piece belongs to opponent, we have an error
   // If Black Piece, but White Turn
   if (isupper(board->squares[source.getRow()][source.getCol()]->getLetter()) && isWhite)
      throw string("Piece in source coordinates belongs to opponent");
   
   // If White Piece, but Black Turn
   if (islower(board->squares[source.getRow()][source.getCol()]->getLetter()) && !isWhite)
      throw string("Piece in source coordinates belongs to opponent");
   
   //
   // to square
   //
   
   // column: a-h
   if (text[2] < 'a' || text[2] > 'h')
      throw string("Invalid format of destination coordinates");
   dest.setCol(text[2] - 'a');
   assert(dest.getCol() >= 0 && dest.getCol() <= 7);
   
   // row: 1-8
   if (text[3] < '1' || text[3] > '8')
      throw string("Invalid format of destination coordinates");
   
   dest.setRow(text[3] - '1');
   assert(dest.getRow() >= 0 && dest.getRow() <= 7);
   
   // if destination piece belongs to current player, we have an error
   // If Black Piece AND BLACK Turn
   if (isupper(board->squares[dest.getRow()][dest.getCol()]->getLetter()) && !isWhite)
      throw string("Piece in destination coordinates belongs to current player");
   
   // If White Piece, but White Turn
   if (islower(board->squares[dest.getRow()][dest.getCol()]->getLetter()) && isWhite)
      throw string("Piece in destination coordinates belongs to current player");
   
   // capture if there is something there
   if (board->squares[dest.getRow()][dest.getCol()]->getLetter() != NO_PIECE)
      capture = true;
   
   //
   // capture and promotion
   //
   
   for (int i = 4; i < text.size(); i++)
   {
      switch (text[i])
      {
         case 'p':   // capture a pawn
         case 'n':   // capture a knight
         case 'b':   // capture a bishop
         case 'r':   // capture a rook
         case 'q':   // capture a queen
         case 'k':   // !! you can't capture a king you silly!
            capture = true;
            break;
            
         case 'c':  // short castling or kings castle
            castleK = true;
            break;
         case 'C':  // long castling or queen castle
            castleQ = true;
            break;
         case 'E':  // En-passant
            enpassant = true;
            break;
            
         case 'N':  // Promote to knight
         case 'B':  // Promote to Bishop
         case 'R':  // Promote to Rook
         case 'Q':  // Promote to Queen
            setPromote();
            break;
            
         default:
            // unknown piece
            throw string("Unknown promotion piece specification");
      }
   }
   
   // if we made it this far, we are successful
   
   return;
}

bool Move::validate() throw(string)
{
   std::vector<std::string> temp;
   board->squares[source.getRow()][source.getCol()]->getMoves(*board, source);
   temp = board->squares[source.getRow()][source.getCol()]->posMoves;
   
   for (int i = 0; i < temp.size(); i++)
   {
      if (moveString == temp[i])
         return true;
   }
   throw string("Illegal move.  The piece cannot move to this location.");
   return false;
}