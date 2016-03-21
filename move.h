//
//  move.h
//  Object Oriented Chess
//
//  Created by Brooks Robison on 3/17/16.
//  Copyright © 2016 Dan McDaniel. All rights reserved.
//



#ifndef _MOVE_
#define _MOVE_

#include <string>
#include "position.h"
#include "board.h"

#define PIECE_EMPTY ' '

/***************************************************
 * MOVE
 * One move across the board
 ***************************************************/
class Move
{
public:
    // constructors
    Move();
    Move(const Move & rhs)                      { *this = rhs;             }
    Move(const string & s, Board & b)           { moveString = s; board = &b;               }
    
    // a slew of getters.  All are const!
    const Position & getDes()             const { return dest;             }
    const Position & getSrc()             const { return source;           }
    string getText()                      const;
    bool getPromote()                     const { return promote;            }
    char getCapture()                     const { return capture;          }
    bool getEnPassant()                   const { return enpassant;        }
    bool getCastleK()                     const { return castleK;          }
    bool getCastleQ()                     const { return castleQ;          }
    bool getWhiteMove()                   const { return isWhite;          }
    bool operator == (const string & rhs) const { return getText() == rhs; }
    bool operator != (const string & rhs) const { return getText() != rhs; }
    bool operator == (const Move & rhs)   const;
    bool operator != (const Move & rhs)   const { return !(*this == rhs); }
    string moveString;
    
    // setters.  Since properties are the same as data, these are trivial
    void setCapture(char letter)            { capture    = tolower(letter); }
    void setWhiteMove(bool f)               { isWhite    = f;               }
    void setSrc(const Position & src)       { source     = src;             }
    void setDes(const Position & des)       { dest       = des;             }
    void setEnPassant()                     { enpassant  = true;            }
    void setPromote()                       { promote    = true;          }
    void setCastle(bool isKing)
    {
        if (isKing)
            castleK = true;
        else
            castleQ = true;
    }
    void execute();
    bool validate() throw(string);
    
    // display and prompt
    friend ostream & operator << (ostream & out, Move & rhs);
    friend istream & operator >> (istream & in,  Move & rhs) throw (string);
    
    // assignment with a variety of right-hand-sides
    const Move & operator = (const Move & rhs);
    const Move & operator = (const string & s) throw ( string )
    {
        parse();
        return *this;
    }
    const Move & operator = (const char *s) throw ( string )
    {
        parse();
        return *this;
    }
    
    Board * board;
    
    // this is the same as the parse function from Project 1
    void parse() throw(string);
    
    
private:
    Position  source;    // where the move originated from
    Position  dest;      // where the move finished
    char      piece;     // piece to be promoted to
    char      capture;   // did a capture happen this move?
    bool      enpassant; // Enpassant pawn capture
    bool      castleK;   // kingside castle
    bool      castleQ;   // queenside castle
    bool      isWhite;   // white's move?
    bool      promote;   // is this a promotion?
    string    error;     // if in error state, what was the bug?
    
};


#endif // _MOVE_

