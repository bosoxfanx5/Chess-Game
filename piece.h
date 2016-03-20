/***************************************************************************
 * Program:
 *    Project 3, Object Oriented Chess
 *    Brother McCracken, CS165
 * Authors:
 *    Dan McDaniel, Brooks Robison, Thomas Woodworth
 * File Summary:
 *    Because the class has a variable of type Board, and the board class 
 * has a variable of type Piece, we have used 'Forward Declaration' to 
 * make this work.
 *    Piece.h contains the following piece classes:
 *    1: Piece
 *    2: Space
 *    3: King
 *    4: Queen
 *    5: Bishop
 *    6: Knight
 *    7: Rook
 *    8: Pawn
 ***************************************************************************/

#ifndef piece_h
#define piece_h

#include <vector>
#include <string>
#include "position.h"
#include "board.h"

/********************************************************
 * BOARD CLASS
 *    This class is added here for Forward Declaration.
 * It will not be defined here because it is defined the
 * board.h file.
 ********************************************************/
class Board; //Forward declaration (prototype)

/********************************************************
 * PIECE CLASS
 *    This class is the main class that all the other pieces
 * are derived from.
 * It contains the following pure virtual functions that 
 * MUST be redefined in each derived class:
 *    1. getLetter
 *    2. getScore
 *    3. getMoves
 ********************************************************/
class Piece
{
public:
   bool fMoved;
   Piece(bool isWhite) : isWhite(isWhite) {};
   bool getIsWhite() const                { return isWhite; }
   virtual char getLetter() const = 0;
   virtual int getScore()   const = 0;
   virtual void getMoves(Board & board, Position & position) = 0;   //
   std::vector<std::string> posMoves;   //
   
   //static bool fSimple;   // not starting off in Test mode
   //static int  currentMove;
   
protected:
   bool isWhite;
};

/********************************************************
 * SPACE CLASS
 *    This class is for each square on the board that
 * contains nothing.  Because each piece must have a color,
 * we decided that Spaces would be BLACK.
 ********************************************************/
class Space : public Piece
{
public:
   Space() : Piece(false) {};
   virtual int getScore()   const { return   0; }
   virtual char getLetter() const { return ' '; }
   void getMoves(Board & board, Position & position);// {};
};

/********************************************************
 * KING CLASS
 ********************************************************/
class King : public Piece
{
public:
   
   King(bool isWhite) : Piece(isWhite) {};
   char getLetter() const {return isWhite ? 'k' : 'K';}
   int getScore() const {return isWhite ? 100 : -100;}
   void getMoves(Board & board, Position & position);
};

/********************************************************
 * QUEEN CLASS
 ********************************************************/
class Queen : public Piece
{
public:
   Queen(bool isWhite) : Piece(isWhite) {};
   char getLetter() const {return isWhite ? 'q' : 'Q';}
   int getScore() const {return isWhite ? 10 : -10;}
   void getMoves(Board & board, Position & position);
};

/********************************************************
 * BISHOP CLASS
 ********************************************************/
class Bishop : public Piece
{
public:
   Bishop(bool isWhite) : Piece(isWhite) {};
   char getLetter() const {return isWhite ? 'b' : 'B';}
   int getScore() const {return isWhite ? 100 : -100;}
   void getMoves(Board & board, Position & position);
};

/********************************************************
 * KNIGHT CLASS
 ********************************************************/
class Knight : public Piece
{
public:
   Knight(bool isWhite) : Piece(isWhite) {};
   char getLetter() const {return isWhite ? 'n' : 'N';}
   int getScore() const {return isWhite ? 10 : -10;}
   void getMoves(Board & board, Position & position);
};

/********************************************************
 * ROOK CLASS
 ********************************************************/
class Rook : public Piece
{
public:
   bool fMoved;
   Rook(bool isWhite) : Piece(isWhite) {};
   char getLetter() const {return isWhite ? 'r' : 'R';}
   int getScore() const {return isWhite ? 1 : -1;}
   void getMoves(Board & board, Position & position);
};

/********************************************************
 * PAWN CLASS
 ********************************************************/
class Pawn : public Piece
{
public:
   bool fMoved;
   Pawn(bool isWhite) : Piece(isWhite) {};
   char getLetter() const {return isWhite ? 'p' : 'P';}
   int getScore() const {return isWhite ? 1 : -1;}
   void getMoves(Board & board, Position & position);
};

#endif /* piece_h */
