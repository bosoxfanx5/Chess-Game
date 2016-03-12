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

/**************
 * Draw Board *
 **************/
void Chessboard::Board::draw()
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
         if (white) std::cout << ((squares[r][c].getLetter() > 97) ? WW : WB); //white/black piece
         else       std::cout << ((squares[r][c].getLetter() > 97) ? RW : RB); //white/black piece
         
         //Output
         Piece piece = squares[r][c];
         if (piece != '\0') //occupied if not null
         {
            if (piece == 'P' || piece == 'p')
               piece = 'p';
            else
               piece = toupper(piece);
            
            std::cout << " " << piece << " ";
         }
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
   std::cout << "  abcdefgh" << endl;   // I prefer endl over '\0'.
   for (int r = 7; r >= 0; r--)
   {
      std::cout << r + 1 << " ";        //row headers
      for (int c = 0; c < 8; c++)
         if (squares[r][c] != '\0')  //occupied if not null
            std::cout << squares[r][c];
         else                      //free
            std::cout << " ";
      std::cout << std::endl;
   }
}