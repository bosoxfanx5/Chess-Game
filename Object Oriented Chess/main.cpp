//
//  main.cpp
//  Object Oriented Chess
//
//  Created by Dan on 3/6/16.
//  Copyright © 2016 Brooks, Dan and Tom. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "chessmove.h"
#include "chessboard.h"
//#include <regex> // couldn't get this to work

using namespace std;


/////////////////
// Definitions //
/////////////////

//#define CLEAR "";       // null for debug
#define CLEAR "\E[H\E[2J";// clear screen
#define WW    "\E[31;47m" // white square, white piece
#define WB    "\E[30;47m" // white square, black piece
#define RW    "\E[37;41m" // red square, white piece
#define RB    "\E[30;41m" // red square, black piece
#define BW    "\E[0m"     // black background, white lettering
//#define TEMP "board.tmp"// temporary storage for board // opted for vector


////////////////
// Structures //
////////////////

/**********************
 * Coordinates Struct *
 *  - Row             *
 *  - Column          *
 **********************/
struct Coordinates
{
   int row;
   int col;
};

/**********************
 * Piece Struct       *
 *  - Color           *
 *  - Coordinates     *
 **********************/
struct PieceOld
{
   //Color
   bool color;
   
   //Squares
   Coordinates location;
};

/**********************
 * Move Struct        *
 *  - Source          *
 *  - Destination     *
 *  - Mover           *
 *  - Victim          *
 **********************/
struct MoveOld
{
   //Squares
   Coordinates source;
   Coordinates dest;
   
   //Pieces
   Piece mover;
   Piece victim;
};

/////////////
// Display //
/////////////

/********************
 * Initialize Board *
 ********************/
void init(char board[8][8])
{
   //Black
   board[7][3] = 'Q';
   board[7][4] = 'K';
   board[7][0] = board[7][7] = 'R';
   board[7][1] = board[7][6] = 'N';
   board[7][2] = board[7][5] = 'B';
   board[6][0] = board[6][1] = board[6][2] = board[6][3] =
   board[6][4] = board[6][5] = board[6][6] =
   board[6][7] = 'P';
   
   //The great divide
   for (int r = 5; r >= 2; r--)
      for (int c = 0; c <= 7; c++)
         board[r][c] = '\0';
   
   //White
   board[1][0] = board[1][1] = board[1][2] = board[1][3] =
   board[1][4] = board[1][5] = board[1][6] =
   board[1][7] = 'p';
   board[0][0] = board[0][7] = 'r';
   board[0][1] = board[0][6] = 'n';
   board[0][2] = board[0][5] = 'b';
   board[0][3] = 'q';
   board[0][4] = 'k';
}

/**************
 * Draw Board *
 **************/
void draw(char board[8][8])
{
   cout << CLEAR;
   cout << "   a  b  c  d  e  f  g  h " << endl; // I prefer endl.
   bool white = true; //for checkerboard pattern
   for (int r = 7; r >= 0; r--)
   {
      cout << r + 1 << " "; //row headers
      for (int c = 0; c < 8; c++)
      {
         //Formatting Board - false styleChecker errors on these lines, too...
         if (white) cout << ((board[r][c] > 97) ? WW : WB); //white/black piece
         else       cout << ((board[r][c] > 97) ? RW : RB); //white/black piece
         
         //Output
         char piece = board[r][c];
         if (piece != '\0') //occupied if not null
         {
            if (piece == 'P' || piece == 'p')
               piece = 'p';
            else
               piece = toupper(piece);
            
            cout << " " << piece << " ";
         }
         else                     //free
            cout << "   ";
         cout << BW;              //reset formatting
         
         //Flip the color bit
         white = !white; // When is white now white?  Now.
      }
      white = !white;    // And now, too.
      cout << endl;
   }
}

/*******************
 * Draw Test Board *
 *******************/
void test(char board[8][8])
{
   cout << "  abcdefgh" << endl;   // I prefer endl over '\0'.
   for (int r = 7; r >= 0; r--)
   {
      cout << r + 1 << " ";        //row headers
      for (int c = 0; c < 8; c++)
         if (board[r][c] != '\0')  //occupied if not null
            cout << board[r][c];
         else                      //free
            cout << " ";
      cout << endl;
   }
}


//////////
// Move //
//////////

/*************
 * Make Move *
 *************/
void makeMove(char board[8][8], string move)
{
   //ChessMove m(move);
   //m.origin.row = move[0] - 97;
   //m.origin.col = move[1] - 49;
   //m.destination.row   = move[2] - 97;
   //m.destination.col   = move[3] - 49;
   
   //move the source piece to the destination
   //board[m.dest.col][m.dest.row] = board[m.source.col][m.source.row];
   //board[m.source.col][m.source.row] = '\0';
}

/******************************
 * Load - From Array of Moves *
 ******************************/
inline void load( vector <string> & moveArray, char board[8][8])
{
   for (int a = 0; a < moveArray.size(); a++)
   {
      string move = moveArray[a];
      makeMove(board, move);
   }
}

///////////
// DEBUG //
///////////

/*************************
 * List Moves from Array *
 *************************/
inline void list(vector <string> moveArray)
{
   cout << "List of moves from moveArray:" << endl;
   for (int a = 0; a < moveArray.size(); a++)
      cout << " " << moveArray[a] << endl;
}


/*
 //DEBUG - Duplicate Files
 void copy(char sourceFile[256], char destFile[256] = (char *)"board.tmp")
 {
 ifstream source(sourceFile, ios::binary)
 ofstream   dest(  destFile, ios::binary)
 
 dest << source.rdbuf()
 
 source.close()
 dest.close()
 }
 */


/////////////
// File IO //
/////////////

/********************
 * Load - From File *
 ********************/
void load(char filename[256], char board[8][8], vector <string> & moveArray)
{
   char move[8];
   
   //Reset board
   init(board);
   
   //Reset move array
   moveArray.empty();
   moveArray.clear();
   
   ifstream fin(filename);
   
   if (!fin.fail())
      while (fin >> move)
      {
         bool errorFlag = true;
         string error = "";
         
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
                        char p = board[move[1] - 49][move[0] - 97];
                        
                        if (p == 'p' || p == 'r' || p == 'n' ||
                            p == 'b' || p == 'q' || p == 'k' ||
                            p == 'P' || p == 'R' || p == 'N' ||
                            p == 'B' || p == 'Q' || p == 'K')
                        {
                           errorFlag = false;
                           makeMove(board, move);
                           moveArray.push_back(move);
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
            cout << "Error parsing file " << filename
            << " with move '"        << move
            << "': "                 << error       << endl;
            throw(error);
            return;
         }
      }
   else
      cout << "Unable to open file " << filename << " for input." << endl;
   
   //Close the file.
   fin.close();
}

/******************
 * Save - To File *
 ******************/
void save(string filename, vector <string> & moveArray)
{
   ofstream fout;
   fout.open(filename.c_str(), fstream::ate | fstream::app);
   
   //If we can write to the file...
   if (!fout.fail())
   {
      //Write all moves in the array to the file
      for (int a = 0; a < moveArray.size(); a++)
      {
         fout << moveArray[a];
         if (a % 2 == 0)
            fout << endl; //offsetting new lines
         else
            fout << " ";  //spacing moves on same line
      }
   }
   else //an error occurred...
      cout << "Unable to open file " << filename << " for output.";
   
   //Close the file
   fout.close();
}

//////////////////////
// User Interaction //
//////////////////////



//Clearly this is < 80 chars, but styleChecker freaks out again...

/************************************
 * ███╗   ███╗ █████╗ ██╗███╗   ██╗ *
 * ████╗ ████║██╔══██╗██║████╗  ██║ *
 * ██╔████╔██║███████║██║██╔██╗ ██║ *
 * ██║╚██╔╝██║██╔══██║██║██║╚██╗██║ *
 * ██║ ╚═╝ ██║██║  ██║██║██║ ╚████║ *
 * ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝ *
 ************************************/
/*int main(int argc, const char * argv[])
{
   vector <string> moveArray;
   char board[8][8] = {'\0'};
   
   init(board);
   draw(board);
   
   interact(board, moveArray);
   
   return 0;
}*/

int main(int argc, const char * argv[])
{
   Chessboard board = *new Chessboard(); //default to clean board
   board.Board::load();     //
   board.init();
   
   //std::cout << ".";
   
   while (board.interact())
   {
   //   std::cout << ".";
      board.drawTest();
      //board.draw();
   }
   
   // insert code here...
   //std::cout << "Hello, World!\n";
    return 0;
}

