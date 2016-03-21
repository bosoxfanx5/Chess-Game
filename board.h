/***************************************************************************
 * Program:
 *    Project 3, Object Oriented Chess
 *    Brother McCracken, CS165
 * Authors:
 *    Dan McDaniel, Brooks Robison, Thomas Woodworth
 * File Summary:
 *    Board.h contains the board class.  Because the class has a variable
 * of type Piece, and the piece class has a variable of type Board, we have
 * used 'Forward Declaration' to make this work.
 ***************************************************************************/

#ifndef board_h
#define board_h

#include "piece.h"
#include "position.h"
#include <vector>
#include <string.h>

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

/********************************************************
 * PIECE CLASS
 *    This class is added here for Forward Declaration.
 * It will not be defined here because it is defined the
 * piece.h file.
 ********************************************************/
class Piece; //Forward declaration (prototype)


/********************************************************
 * BOARD CLASS
 ********************************************************/
class Board
{
public:
    Board() {isTestMode = false;}
    
public:
    //Chessboard() {};
    void init();
    void initk();
    void initq();
    void load();
    void draw();
    void undo();
    void drawTest();
    void writeFile();
    //Piece getPieceAtLocation(Position location) {return squares[location.getRow()][location.getCol()];}
    
    //Location Class //Array
    Piece * squares[8][8];
    void interact();// {std::cin; /*std::cin.ignore()*/; return true;}
    std::vector<std::string> history;
    bool isTestMode;
};

#endif /* board_h */
