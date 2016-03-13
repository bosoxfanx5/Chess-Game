//
//  chessboard.cpp
//  Object Oriented Chess
//
//  Created by Dan on 3/11/16.
//  Copyright © 2016 Brooks, Dan and Tom. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "chessboard.h"
#include "chesspieces.h"
#include "chessboardsquare.h"

/**************
 * Draw Board *
 **************/
void Chessboard::draw()
{
   std::cout << CLEAR;
   std::cout << "   a  b  c  d  e  f  g  h " << std::endl; // I prefer endl.
   bool white = true; //for checkerboard pattern
   for (int r = 7; r >= 0; r--)
   {
      std::cout << r + 1 << " "; //row headers
      for (int c = 0; c < 8; c++)
      {
         //Formatting Board - false styleChecker errors on these lines, too...
         if (white) std::cout << ((this->squares[r][c].getLetter() > 97) ? WW : WB); //white/black piece
         else       std::cout << ((this->squares[r][c].getLetter() > 97) ? RW : RB); //white/black piece
         
         //Output
         ChessPiece piece = squares[r][c].getPiece();
         if (piece.getLetter() != '\0') //occupied if not null
            std::cout << " " << piece.getLetter() << " ";
         else                     //free
            std::cout << "   ";
         std::cout << BW;              //reset formatting
         
         //Flip the color bit
         white = !white; // When is white now white?  Now.
      }
      white = !white;    // And now, too.
      std::cout << std::endl;
   }
}

/*******************
 * Draw Test Board *
 *******************/
void Chessboard::drawTest()
{
   std::cout << "  abcdefgh" << std::endl;   // I prefer endl over '\0'.
   for (int r = 7; r >= 0; r--)
   {
      std::cout << r + 1 << " ";        //row headers
      for (int c = 0; c < 8; c++)
         if (this->squares[r][c].getLetter() != '\0')  //occupied if not null
            std::cout << this->squares[r][c].getLetter();
         else                      //free
            std::cout << " ";
      std::cout << std::endl;
   }
}

/********************
 * Initialize Board *
 ********************/
void Chessboard::init()
{
   //Black
   this->squares[7][4].piece = new King(true);
   this->squares[7][3].piece = new Queen(true);
   this->squares[7][0].piece = new Rook(true); //Left
   this->squares[7][7].piece = new Rook(true); //Right
   this->squares[7][1].piece = new Knight(true);
   this->squares[7][6].piece = new Knight(true);
   this->squares[7][2].piece = new Bishop(true);
   this->squares[7][5].piece = new Bishop(true);
   
   this->squares[6][0].piece = new Pawn(true);
   this->squares[6][1].piece = new Pawn(true);
   this->squares[6][2].piece = new Pawn(true);
   this->squares[6][3].piece = new Pawn(true);
   this->squares[6][4].piece = new Pawn(true);
   this->squares[6][5].piece = new Pawn(true);
   this->squares[6][6].piece = new Pawn(true);
   this->squares[6][7].piece = new Pawn(true);
   
   //The great divide
   for (int r = 5; r >= 2; r--)
      for (int c = 0; c <= 7; c++)
         this->squares[r][c].piece = new Space();
   
   //White
   this->squares[1][0].piece = new Pawn(false);
   this->squares[1][1].piece = new Pawn(false);
   this->squares[1][2].piece = new Pawn(false);
   this->squares[1][3].piece = new Pawn(false);
   this->squares[1][4].piece = new Pawn(false);
   this->squares[1][5].piece = new Pawn(false);
   this->squares[1][6].piece = new Pawn(false);
   this->squares[1][7].piece = new Pawn(false);
   
   this->squares[0][0].piece = new Rook(false);
   this->squares[0][7].piece = new Rook(false);
   this->squares[0][1].piece = new Knight(false);
   this->squares[0][6].piece = new Knight(false);
   this->squares[0][2].piece = new Bishop(false);
   this->squares[0][5].piece = new Bishop(false);
   this->squares[0][3].piece = new Queen(false);
   this->squares[0][4].piece = new King(false);
}