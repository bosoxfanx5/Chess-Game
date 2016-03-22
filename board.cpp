/***************************************************************************
 * Program:
 *    Project 3, Object Oriented Chess
 *    Brother McCracken, CS165
 * Authors:
 *    Dan McDaniel, Brooks Robison, Thomas Woodworth
 * File Summary:
 *    Board.cpp contains the following functions for interacting with the board.
 *    1: showMenu
 *    2: prompt
 *    3: Board::load
 *    4: Board::writeFile
 *    5: Board::interact
 *    6: Board::draw
 *    7: Board::init
 *    8: Board::initk
 *    9: Board::initq
 *   10: Board::undo
 *
 ***************************************************************************/

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include "piece.h"
#include "move.h"
#include "position.h"
#include "board.h"


//NON-MEMBER FUNCTIONS//
#ifndef TRIM
#define TRIM
/*******************************************
 * TRIM
 *    This function will strip out all unneeded
 *    spaces.
 *******************************************/
std::string trim(std::string& str)
{
   size_t first = str.find_first_not_of(' ');
   size_t last = str.find_last_not_of(' ');
   return str.substr(first, (last-first+1));
}
#endif

/***************************************************
 * SHOWMENU
 *    This function displays the menu to the screen.
 ***************************************************/
void showMenu()
{
   std::cout << "Options:"                                   << std::endl
   << " ?      Display these options"                        << std::endl
   << " b2b4   Specify a move using the Smith Notation"      << std::endl
   << " read   Read a saved game from a file"                << std::endl
   << " help   Display all possible moves for a given piece" << std::endl
   << " test   Simple display for test purposes"             << std::endl
   << " rank   Who is winning?  What is the rank"     << std::endl
   << " quit   Leave the game. You will be prompted to save" << std::endl;
}

/***************************************************
 * PROMPT
 *    This function receives two character arrays.
 * The first receives the message to be displayed, and
 * the second will store the users response.
 ***************************************************/
inline void prompt(char prompt[256], char response[256])
{
   std::cout << prompt;
   std::cin  >> response;
}

/***************************************************
 * BOARD::LOAD
 *    This function loads a game from a user submitted
 * file.  If the file is valid, the moves will be stored
 * in a vector and the board will be updated with all
 * the moves from the file.  If the file cannot be
 * read, the function will display an error and load a
 * clean board.
 ***************************************************/
void Board::load()
{
   char fileName[256];
   bool goodRead = true;
   
   // gotta clear that board and the vector before reading a new file!!!
   init();
   history.clear();
   
   std::cout << "Filename: ";
   std::cin  >> fileName;
   
   // open the file
   std::ifstream fin(fileName);
   if (fin.fail())
   {
      std::cout << "Unable to open file \'" << fileName
      << "\' for input.\n";
      return;
   }
   std::string moveString;
   // read the file and try to parse, execute, and store the moves
   // inside the vector.
   while (fin >> moveString)
   {
      try
      {
         Move move(moveString, *this);
         move.parse();
         if (move.validate())
         {
            move.execute();
            history.push_back(moveString);
         }
      }
      catch (string fileError)
      {
         // catch the errors in parseMove if there are parsing errors
         goodRead = false;
         std::cout << "Error parsing file "
         << fileName
         << " with move \'"
         << moveString
         << "\': "
         << fileError
         << std::endl;
      }
   }
   
   fin.close();
   
   // if not a goodRead then clear the vector and reset the board
   if (!goodRead)
   {
      history.clear();
      init();
   }
   // if all is good with the file read then display the board!
   else
      draw();
   
}

/***************************************************
 * BOARD::WRITEFILE
 *    This function asks the user if they want to
 * save the game.  If yes, the moves of the game will
 * be written to a user designated file and saved.
 ***************************************************/
void Board::writeFile()
{
   char newFile[256];
   // if you don't want save the game, just press enter
   std::cout << "To save a game, please specify the filename.\n"
   << "    To quit without saving a file, just press <enter>\n";
   
   std::cin.ignore();
   std::cin.getline(newFile, 256);
   
   // open the new file
   std::ofstream fout(newFile);
   
   if (fout.fail())
      return;
   
   if (newFile[0] == '\0')
      return;
   
   // store the moves from the vector in the file
   for (int i = 0; i < history.size(); i++)
   {
      fout << history[i];
      if (i % 2 != 0)
         fout << std::endl;
      else
         fout << " ";
   }
   fout.close();
   
   return;
}



//MEMBER FUNCTIONS//

/***************************************************
 * BOARD::INTERACT
 *    This function allows for the playing of the game.
 * All interaction with the game will be done through
 * this function.
 ***************************************************/
void Board::interact()
{
   bool quit = false;
   
   do
   {
      // who's turn is it? yours or mine?
      switch (history.size() % 2)
      {
         case 0:
            std::cout << "(White): ";
            break;
         case 1:
            std::cout << "(Black): ";
            break;
      }
      
      std::string moveString;
      std::cin >> moveString;
      
      if (moveString == "?")
         showMenu();
      else if (moveString == "read")
         load();
      else if (moveString == "test")
      {
         isTestMode = !isTestMode;
         draw();
      }
      else if (moveString == "undo")
      {
         undo();
      }
      else if (moveString == "auto")
      {
         autoMove();
      }
      else if (moveString == "history")
      {
         printHistory();
      }
      else if (moveString == "quit")
         quit = true;
      else if(moveString == "help")
      {
         std::cout << "Which piece would you like to find the moves for? ";
         char r, c = '\0';
         std::cin >> c >> r;
         
         Position origin(r, c);
         if (origin.getRow() >= 0 && origin.getRow() <= 7 && origin.getCol() >= 0 && origin.getCol() <= 7)
         {
            squares[origin.getRow()][origin.getCol()]->posMoves.clear();
            squares[origin.getRow()][origin.getCol()]->getMoves(*this, origin);
            
            std::cout << "Possible moves are: " << std::endl;
            
            int count = 0;
            
            for (std::vector<std::string>::iterator it = squares[origin.getRow()][origin.getCol()]->posMoves.begin();
                 it != squares[origin.getRow()][origin.getCol()]->posMoves.end();
                 ++it)
            {
               std::cout << "\t" << trim(squares[origin.getRow()][origin.getCol()]->posMoves[count++]) << std::endl;
            }
         }
         else
            std::cout << "Error: Invalid specification of coordinates" << std::endl;
         
      }
      
      else if(moveString == "rank")
         std::cout << "This feature is not available" << std::endl;
      else
      {
         try
         {
            // take users input as an attempt to make a move on the
            // board
            Move move(moveString, *this);
            move.parse();
            if (move.validate())
            {
               move.execute();
               history.push_back(moveString);
               draw();
            }
         }
         catch (std::string error)
         {
            std::cout << "Error in move \'" << moveString << "\': " << error << std::endl;
            std::cout << "\tType ? for more options\n";
         }
      }
   }
   while (quit == false);
   
   writeFile();
   
   return;
   
}



/***************************************************
 * BOARD::DRAW
 *    This function draws the board to the screen.
 * There are two versions, black and white, or colored.
 * Before drawing the board to the screen, the screen
 * will be cleared.
 ***************************************************/
void Board::draw()
{
   
   
   if (isTestMode)
   {
      std::cout << "  abcdefgh" << std::endl;   // I prefer endl over '\0'.
      for (int r = 7; r >= 0; r--)
      {
         std::cout << r + 1 << " ";        //row headers
         for (int c = 0; c <= 7; c++)
            if (this->squares[r][c]->getLetter() != ' ')  //occupied if not null
               std::cout << this->squares[r][c]->getLetter();
            else                      //free
               std::cout << " ";
         std::cout << std::endl;
      }
   }
   else
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
            if (white) std::cout << ((this->squares[r][c]->getLetter() > 97) ? WW : WB); //white/black piece
            else       std::cout << ((this->squares[r][c]->getLetter() > 97) ? RW : RB); //white/black piece
            
            char tempPiece = tolower(this->squares[r][c]->getLetter());
            std::string backRow = "rnbqk ";
            //Output
            if (tempPiece != '\0') //occupied if not null
            {
               if (tempPiece == 'p')
                  std::cout << " " << (char)tolower(tempPiece) << " ";
               else if (backRow.find(tempPiece) + 1)
                  std::cout << " " << (char)toupper(tempPiece) << " ";
            }
            
            
            std::cout << BW;              //reset formatting
            
            //Flip the color bit
            white = !white; // When is white now white?  Now.
         }
         white = !white;    // And now, too.
         std::cout << " " << r + 1 << std::endl;
         
      }
      std::cout << "   a  b  c  d  e  f  g  h " << std::endl;
   }
}

/***************************************************
 * BOARD::INIT
 *    This function initializes the board with all
 * the pieces in their original position for a new
 * game.
 ***************************************************/
void Board::init()
{
   //White
   this->squares[0][4] = new King(true); //true = isWhite
   this->squares[0][3] = new Queen(true);
   this->squares[0][0] = new Rook(true); //Left
   this->squares[0][7] = new Rook(true); //Right
   this->squares[0][1] = new Knight(true);
   this->squares[0][6] = new Knight(true);
   this->squares[0][2] = new Bishop(true);
   this->squares[0][5] = new Bishop(true);
   
   this->squares[1][0] = new Pawn(true);
   this->squares[1][1] = new Pawn(true);
   this->squares[1][2] = new Pawn(true);
   this->squares[1][3] = new Pawn(true);
   this->squares[1][4] = new Pawn(true);
   this->squares[1][5] = new Pawn(true);
   this->squares[1][6] = new Pawn(true);
   this->squares[1][7] = new Pawn(true);
   
   //The great divide
   for (int r = 5; r >= 2; r--)
      for (int c = 0; c <= 7; c++)
         this->squares[r][c] = new Space();
   
   //Black
   this->squares[6][0] = new Pawn(false);
   this->squares[6][1] = new Pawn(false);
   this->squares[6][2] = new Pawn(false);
   this->squares[6][3] = new Pawn(false);
   this->squares[6][4] = new Pawn(false);
   this->squares[6][5] = new Pawn(false);
   this->squares[6][6] = new Pawn(false);
   this->squares[6][7] = new Pawn(false);
   
   this->squares[7][0] = new Rook(false);
   this->squares[7][7] = new Rook(false);
   this->squares[7][1] = new Knight(false);
   this->squares[7][6] = new Knight(false);
   this->squares[7][2] = new Bishop(false);
   this->squares[7][5] = new Bishop(false);
   this->squares[7][3] = new Queen(false);
   this->squares[7][4] = new King(false);
}

/***************************************************
 * BOARD::UNDO
 *         *** EXTRA CREDIT ****
 *
 *    This function will undo the last move made.
 ***************************************************/
void Board::undo()
{
   
   // open the new file
   std::ofstream fout("temp.txt");
   
   if (fout.fail())
      return;
   
   // store the moves from the vector in the file
   for (int i = 0; i < history.size() - 1; i++)
   {
      fout << history[i];
      if (i % 2 != 0)
         fout << std::endl;
      else
         fout << " ";
   }
   fout.close();
   
   //
   
   bool goodRead = true;
   
   // gotta clear that board and the vector before reading a new file!!!
   init();
   history.clear();

   // open the file
   std::ifstream fin("temp.txt");
   std::string moveString;
   // read the file and try to parse, execute, and store the moves
   // inside the vector.
   while (fin >> moveString)
   {
      try
      {
         Move move(moveString, *this);
         move.parse();
         if (move.validate())
         {
            move.execute();
            history.push_back(moveString);
         }
      }
      catch (string fileError)
      {
         // catch the errors in parseMove if there are parsing errors
         goodRead = false;
         std::cout << "Error parsing undo file with move \'"
         << moveString
         << "\': "
         << fileError
         << std::endl;
      }
   }
   
   fin.close();
   
   // if not a goodRead then clear the vector and reset the board
   if (!goodRead)
   {
      history.clear();
      init();
   }
   // if all is good with the file read then display the board!
   else
      draw();
   
   return;
   
}

/***************************************************
 * BOARD::PRINTHISTORY
 *         *** EXTRA CREDIT ****
 *
 *    This function will print the move history.
 ***************************************************/
void Board::printHistory()
{
   for (int i = 0; i < history.size(); i++)
   {
      std::cout << history[i] << std::endl;
   }
   return;
}

/***************************************************
 * BOARD::AUTOMOVE
 *         *** EXTRA CREDIT ****
 *
 *    This function make a random move.
 ***************************************************/
void Board::autoMove()
{
   Piece *p;
   bool w = !(history.size() % 2);
   int r;
   int c;
   
   bool moved = false;
   while (!moved)
   {
      do
      {
         r = rand() % 7; //random bumber between 0 and 7
         c = rand() % 7; //random bumber between 0 and 7
         
         p = squares[r][c];
      } while (p->getIsWhite() != w);
      
      Position position(r, c);
      
      p->posMoves.clear();
      p->getMoves(*this, position);
      int myRand = std::rand();
      int s = squares[r][c]->posMoves.size();
      int i = 0;
      if (s == 0)
         continue;
      else if (s == 1)
         i = 0;
      else
         i = myRand % s;
      
      string moveString = p->posMoves[i];
      
      Move move(moveString, *this);
      move.parse();
      if (move.validate())
      {
         move.execute();
         history.push_back(moveString);
         draw();
         moved = true;
      }
   }
   return;
}



