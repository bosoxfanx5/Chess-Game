//
//  chessboard.cpp
//  Object Oriented Chess
//
//  Created by Dan on 3/11/16.
//  Copyright © 2016 Brooks, Dan and Tom. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
//#include <vector>
#include "chessmove.h"
#include "chessboard.h"
#include "chesspieces.h"
#include "chessboardsquare.h"


//NON-MEMBER FUNCTIONS//

/*************
 * Draw Menu *
 *************/
void showMenu()
{
   std::cout << "Options:"                                   << std::endl
   << " ?      Display these options"                        << std::endl
   << " b2b4   Specify a move using the Smith Notation"      << std::endl
   << " read   Read a saved game from a file"                << std::endl
   << " test   Simple display for test purposes"             << std::endl
   << " quit   Leave the game. You will be prompted to save" << std::endl;
}

/**********
 * Prompt *
 **********/
inline void prompt(char prompt[256], char response[256])
{
   std::cout << prompt;
   std::cin  >> response;
}

/********************
 * Load - From File *
 ********************/
void Chessboard::load(std::string filename)
{
   //char move[8];
   std::string move;
   //Reset board
   init();
   
   //Reset move array
   history.empty();
   history.clear();
   
   std::ifstream fin(filename);
   
   if (!fin.fail())
      while (fin >> move)
      {
         bool errorFlag = true;
         std::string error = "";
         
         //Capture character
         char c = move[4];
         if (!(c == '\0' || c == 'p' || c == 'r' || c == 'n'
               || c == 'b' || c == 'q' || c == 'k'))
            error = "Unknown promotion piece specification";
         else
            if (move[0] >= 'a' && move[0] <= 'h')
               if (move[1] >= '0' && move[1] <= '8')
                  if (move[2] >= 'a' && move[2] <= 'h')
                     if (move[3] >= '0' && move[3] <= '8')
                     {
                        char p = squares[move[1] - 49][move[0] - 97].getLetter();
                        
                        if (p == 'p' || p == 'r' || p == 'n' ||
                            p == 'b' || p == 'q' || p == 'k' ||
                            p == 'P' || p == 'R' || p == 'N' ||
                            p == 'B' || p == 'Q' || p == 'K')
                        {
                           errorFlag = false;
                           //makeMove(board, move);
                           //moveArray.push_back(move);
                           ChessMove m(move, *this);
                           m.execute();
                        }
                        else error =
                           "No piece in the source coordinates position";
                     }
         //Errors below in styleChecker are unfounded.
                     else error = "Invalid format of destination coordinates";
                     else error =    "Invalid format of destination coordinates";
                     else error =       "Invalid format of source coordinates";
                     else error =          "Invalid format of source coordinates";
         
         if (errorFlag)
         {
            std::cout << "Error parsing file " << filename
            << " with move '"        << move
            << "': "                 << error       << std::endl;
            throw(error);
            return;
         }
      }
   else
      std::cout << "Unable to open file " << filename << " for input." << std::endl;
   
   //Close the file.
   fin.close();
}


//MEMBER FUNCTIONS//

/**********************
 * Interact with User *
 **********************/
bool Chessboard::interact()
{
   char filename[256] = {'\0'};
   char move[8] = { '\0' };
   
   while (move[0] != 'q')
   {
      //prompt for a move
      if (history.size() % 2 == 0)
         std::cout << "(White): ";
      else
         std::cout << "(Black): ";
      
      std::string moveString;
      std::cin >> moveString;
      
      ChessMove move(moveString, *this);
      
      //moves
      //if (move.origin move[0] >= 97 && move[0] <= 104) //first letter is a-h
      if (move.validate()) //first letter is a-h
         {
         history.push_back(move);
         move.execute();
         drawTest();
      }
      //commands
      else
      {
         switch (moveString[0])
         {
            case '?' :         //help
               showMenu();
               break;
            case 'r' :         //read
               try
            {
               prompt((char *)"Filename: ", filename);
               load(filename);
               drawTest();
            }
               catch (std::string error)
            {
               std::cout << "";// "ERROR DETECTED";
            }
               break;
            case 't' :         //test output
               drawTest();
               break;
            case 'l' :         //list moves in array
               //list(moveArray);
               break;
            case 'q' :
               break;          //quit
            default:           //unknown input
               std::cout << "Error: Unknown Input"
               << "	Type ? for more options"               << std::endl;
               break;
         }
      }
   }
   std::cout << "To save a game, please specify the filename." << std::endl
   << "    To quit without saving a file, just press <enter>"  << std::endl;
   std::string response;
   response = std::cin.get();
   if (std::cin.get() != '\n');
      //save(response, moveArray);
   std::cin.ignore();
}


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
         //ChessPiece piece = squares[r][c].getPiece();
         if (this->squares[r][c].getLetter() != '\0') //occupied if not null
            std::cout << " " << this->squares[r][c].getLetter() << " ";
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
//*/

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
         if (this->squares[r][c].piece->getLetter() != '\0')  //occupied if not null
            std::cout << this->squares[r][c].getLetter();
            //std::cout << 'z';
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

