//
//  chesspieces.h
//  Object Oriented Chess
//
//  Created by Dan on 3/6/16.
//  Copyright © 2016 Brooks, Dan and Tom. All rights reserved.
//

#ifndef chesspieces_h
#define chesspieces_h

#include "chesspiece.h"

class King1 : public ChessPiece
{
public:
   King1(bool isWhite)  : ChessPiece(isWhite) {};
   int getScore()   const { return isWhite ? 100 : -100; }
   char getLetter() const { return isWhite ? 'k' : 'K';  }
   //virtual bool getIsWhite() {return true;}
};

class Queen1 : public ChessPiece
{
public:
   Queen1(bool isWhite) : ChessPiece(isWhite) {};
   virtual int getScore()   const { return isWhite ?  9 : -9; }
   virtual char getLetter() const { return isWhite ? 'q' : 'Q'; }
};

class Bishop1 : public ChessPiece
{
public:
   Bishop1(bool isWhite) : ChessPiece(isWhite) {};
   virtual int getScore()   const { return isWhite ?  5 : -5; }
   virtual char getLetter() const { return isWhite ? 'b' : 'B'; }
};

class Knight1 : public ChessPiece
{
public:
   Knight1(bool isWhite) : ChessPiece(isWhite) {};
   virtual int getScore()   const { return isWhite ? 3 : -3; }
   virtual char getLetter() const { return isWhite ? 'n' : 'N'; }
};

class Rook1 : public ChessPiece
{
public:
   Rook1(bool isWhite) : ChessPiece(isWhite) {};
   virtual int getScore()   const { return isWhite ?  3 : -3; }
   virtual char getLetter() const { return isWhite ? 'r' : 'R'; }
};

class Pawn1 : public ChessPiece
{
public:
   Pawn1(bool isWhite)  : ChessPiece(isWhite) {};
   virtual int getScore()   const { return isWhite ?  1  : -1;  }
   virtual char getLetter() const { return isWhite ? 'p' : 'P'; }
};

class Space1 : public ChessPiece
{
public:
   Space1() : ChessPiece(false) {}
   virtual int getScore()   const { return   0; }
   virtual char getLetter() const { return ' '; }
};


#endif /* chesspieces_h */
