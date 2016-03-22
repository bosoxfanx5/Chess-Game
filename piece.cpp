/***************************************************************************
 * Program:
 *    Project 3, Object Oriented Chess
 *    Brother McCracken, CS165
 * Authors:
 *    Dan McDaniel, Brooks Robison, Thomas Woodworth
 * File Summary:
 *    Piece.cpp contains the following NON-MEMBER functions
 *    1: getCol
 *    2: getDiagMoves
 *    3: getLinearMoves
 *
 *    Piece.cpp contains the following MEMBER functions
 *    4: Space::getMoves
 *    5: King::getMoves
 *    6: Queen::getMoves
 *    7: Bishop::getMoves
 *    8: Knight::getMoves
 *    9: Rook::getMoves
 *   10: Pawn::getMoves
 ***************************************************************************/

#include "piece.h"
#include "board.h"
#include <vector>
#include <iostream>
#include <cctype>
#include <sstream>
//#include "position.h"

//Non-Member Functions
// #ifndef TRIM
// #define TRIM
// /*******************************************
//  * TRIM
//  *    This function will strip out all unneeded
//  *    spaces.
//  *******************************************/
// std::string trim(std::string& str)
// {
//     size_t first = str.find_first_not_of(' ');
//     size_t last = str.find_last_not_of(' ');
//     return str.substr(first, (last-first+1));
// }
// #endif
/*******************************************
 * GETCOL
 *    This function converts the numerical
 * column value to the equivalent alhpa value
 * for the column on the board.
 *******************************************/
char getCol(int c)
{
    char columns[9] = {"abcdefgh"};
    
    return columns[c];
}

/*******************************************
 * GETROWALPHA
 *    This function converts the numerical
 * column value to the equivalent alhpa value
 * for the column on the board.
 *******************************************/
char getRowAlpha(int r)
{
    char rows[10] = {"012345678"};
    
    return rows[r];
}

/*******************************************
 * GETDIAGMOVES
 *    This function gets all the diagonal moves
 * possible for the Queen or Bishop and returns
 * them in a vector.
 *******************************************/
std::vector<std::string> getDiagMoves(Board & board, Position & position)
{
    int r = position.getRow();
    int c = position.getCol();
    int row = 0;
    int col = 0;
    char l = '\0';
    string validMove;
    bool w = board.squares[r][c]->getIsWhite();
    
    std::vector<std::string> posMoves;
    // Check moves to the upper left
    for (row = (r + 1), col = (c - 1); row < 8 && col >= 0; col--, row++)
    {
        l = tolower(board.squares[row][col]->getLetter());
        if (l == ' ')
        {
            //validMove = getCol(c) + getRowAlpha(r + 1) + getCol(col) + getRowAlpha(row + 1);
            validMove = "";
            validMove += getCol(c);
            validMove += getRowAlpha(r + 1);
            validMove += getCol(col);
            validMove += getRowAlpha(row + 1);
            posMoves.push_back(validMove);
        }
        else
        {
           if (w != (board.squares[row][col]->getIsWhite()))
           {
              //validMove = getCol(c) + getRowAlpha(r + 1) + getCol(col) + getRowAlpha(row + 1) + l;
              validMove = "";
              validMove += getCol(c);
              validMove += getRowAlpha(r + 1);
              validMove += getCol(col);
              validMove += getRowAlpha(row + 1);
              validMove += l;
              posMoves.push_back(validMove);
              
           }
           break;
        }
    }
    
    // Check moves to the upper right
    for (row = (r + 1), col = (c + 1); row < 8 && col < 8; col++, row++)
    {
       l = tolower(board.squares[row][col]->getLetter());
       if (l == ' ')
       {
          //validMove = getCol(c) + getRowAlpha(r + 1) + getCol(col) + getRowAlpha(row + 1);
          validMove = "";
          validMove += getCol(c);
          validMove += getRowAlpha(r + 1);
          validMove += getCol(col);
          validMove += getRowAlpha(row + 1);
          posMoves.push_back(validMove);
       }
       else
       {
          if (w != (board.squares[row][col]->getIsWhite()))
          {
             //validMove = getCol(c) + getRowAlpha(r + 1) + getCol(col) + getRowAlpha(row + 1) + l;
             validMove = "";
             validMove += getCol(c);
             validMove += getRowAlpha(r + 1);
             validMove += getCol(col);
             validMove += getRowAlpha(row + 1);
             validMove += l;
             posMoves.push_back(validMove);
          }
          break;
       }

    }
   
    // Check moves to the lower right
    for (row = (r - 1), col = (c + 1); row >= 0 && col < 8; col++, row--)
    {
        l = tolower(board.squares[row][col]->getLetter());
        if (l == ' ')
        {
            //validMove = getCol(c) + getRowAlpha(r + 1) + getCol(col) + getRowAlpha(row + 1);
            validMove = "";
            validMove += getCol(c);
            validMove += getRowAlpha(r + 1);
            validMove += getCol(col);
            validMove += getRowAlpha(row + 1);
            posMoves.push_back(validMove);
        }
        else
        {
            if (w != (board.squares[row][col]->getIsWhite()))
            {
                //validMove = getCol(c) + getRowAlpha(r + 1) + getCol(col) + getRowAlpha(row + 1) + l;
                validMove = "";
                validMove += getCol(c);
                validMove += getRowAlpha(r + 1);
                validMove += getCol(col);
                validMove += getRowAlpha(row + 1);
                validMove += l;
                posMoves.push_back(validMove);
            }
            break;
        }
    }
    
    // Check moves to the lower left
    for (row = (r - 1), col = (c - 1); row >= 0 && col >= 0; col--, row--)
    {
        l = tolower(board.squares[row][col]->getLetter());
        if (l == ' ')
        {
            //validMove = getCol(c) + getRowAlpha(r + 1) + getCol(col) + getRowAlpha(row + 1);
            validMove = "";
            validMove += getCol(c);
            validMove += getRowAlpha(r + 1);
            validMove += getCol(col);
            validMove += getRowAlpha(row + 1);
            posMoves.push_back(validMove);
        }
        else
        {
            if (w != (board.squares[row][col]->getIsWhite()))
            {
                //validMove = getCol(c) + getRowAlpha(r + 1) + getCol(col) + getRowAlpha(row + 1) + l;
                validMove = "";
                validMove += getCol(c);
                validMove += getRowAlpha(r + 1);
                validMove += getCol(col);
                validMove += getRowAlpha(row + 1);
                validMove += l;
                posMoves.push_back(validMove);
            }
            break;
        }
    }
   
    return posMoves;
}

/*******************************************
 * GETLINEARMOVES
 *    This function gets all the linear moves
 * possible for the Queen or Rook and returns
 * them in a vector.
 *******************************************/
std::vector<std::string> getLinearMoves(Board & board, Position & position)
{
    int r = position.getRow();
    int c = position.getCol();
    char l = '\0';
    string validMove;
    bool w = board.squares[r][c]->getIsWhite();
    
    std::vector<std::string> posMoves;
    
    // Check moves to the left
    for (int col = c - 1; col >= 0; col--)
    {
        l = tolower(board.squares[r][col]->getLetter());
        if (l == ' ')
        {
            //validMove = getCol(c) + getRowAlpha(r + 1) + getCol(col) + getRowAlpha(r + 1);
            validMove = "";
            validMove += getCol(c);
            validMove += getRowAlpha(r + 1);
            validMove += getCol(col);
            validMove += getRowAlpha(r + 1);
            posMoves.push_back(validMove);
        }
        else
        {
           if (w != (board.squares[r][col]->getIsWhite()))
              
           {
              //validMove = getCol(c) + getRowAlpha(r + 1) + getCol(col) + getRowAlpha(r + 1) + l;
              validMove = "";
              validMove += getCol(c);
              validMove += getRowAlpha(r + 1);
              validMove += getCol(col);
              validMove += getRowAlpha(r + 1);
              validMove += l;
              posMoves.push_back(validMove);
              
           }
           break;
        }
    }
    
    // Check moves to the right
    for (int col = c + 1; col < 8; col++)
    {
       l = tolower(board.squares[r][col]->getLetter());
       if (l == ' ')
       {
          //validMove = getCol(c) + getRowAlpha(r + 1) + getCol(col) + getRowAlpha(r + 1);
          validMove = "";
          validMove += getCol(c);
          validMove += getRowAlpha(r + 1);
          validMove += getCol(col);
          validMove += getRowAlpha(r + 1);
          posMoves.push_back(validMove);
       }
       else
       {
          if (w != (board.squares[r][col]->getIsWhite()))
          {
             //validMove = getCol(c) + getRowAlpha(r + 1) + getCol(col) + getRowAlpha(r + 1) + l;
             validMove = "";
             validMove += getCol(c);
             validMove += getRowAlpha(r + 1);
             validMove += getCol(col);
             validMove += getRowAlpha(r + 1);
             validMove += l;
             posMoves.push_back(validMove);
          }
          break;
       }
    }
   
    // Check moves to the top
    for (int row = r + 1; row < 8; row++)
    {
        l = tolower(board.squares[row][c]->getLetter());
        if (l == ' ')
        {
            //validMove = getCol(c) + getRowAlpha(r + 1) + getCol(c) + getRowAlpha(row + 1);
            validMove = "";
            validMove += getCol(c);
            validMove += getRowAlpha(r + 1);
            validMove += getCol(c);
            validMove += getRowAlpha(row + 1);
            posMoves.push_back(validMove);
        }
        else
        {
            if (w != (board.squares[row][c]->getIsWhite()))
            {
                //validMove = getCol(c) + getRowAlpha(r + 1) + getCol(c) + getRowAlpha(row + 1) + l;
                validMove = "";
                validMove += getCol(c);
                validMove += getRowAlpha(r + 1);
                validMove += getCol(c);
                validMove += getRowAlpha(row + 1);
                validMove += l;
                posMoves.push_back(validMove);
            }
            break;
        }
    }
    
    
    // Check moves to the bottom
    for (int row = r - 1; row >= 0; row--)
    {
        l = tolower(board.squares[row][c]->getLetter());
        if (l == ' ')
        {
            //validMove = getCol(c) + getRowAlpha(r + 1) + getCol(c) + getRowAlpha(row + 1);
            validMove = "";
            validMove += getCol(c);
            validMove += getRowAlpha(r + 1);
            validMove += getCol(c);
            validMove += getRowAlpha(row + 1);
            posMoves.push_back(validMove);
        }
        else
        {
            if (w != (board.squares[row][c]->getIsWhite()))
            {
                //validMove = getCol(c) + getRowAlpha(r + 1) + getCol(c) + getRowAlpha(row + 1) + l;
                validMove = "";
                validMove += getCol(c);
                validMove += getRowAlpha(r + 1);
                validMove += getCol(c);
                validMove += getRowAlpha(row + 1);
                validMove += l;
                posMoves.push_back(validMove);
            }
            break;
        }
    }
    
    return posMoves;
}


//Member Functions

void Space::getMoves(Board & board, Position & position)
{
}

/***************************************************
 * King::GETMOVES
 * This gets all of the valid moves for the KING.
 * It modifies the piece's possible moves vector.
 ***************************************************/
void King::getMoves(Board & board, Position & position)
{
    
    int r = position.getRow();
    int c = position.getCol();
    bool w = isWhite;
    char l = '\0';
    string validMove;
    bool qCastle = true;
    bool kCastle = true;
    
    // Validate squares immediately around the King
    for (int i = r - 1; i <= r + 1; i++)
        if (i >= 0 && i < 8)
        {
            for (int j = c - 1; j <= c + 1; j++)
                if (j >= 0 && j < 8)
                {
                    l = tolower(board.squares[i][j]->getLetter());
                    if (l == ' ' || w != board.squares[i][j]->getIsWhite())
                    {
                        //validMove = getCol(c) + getRowAlpha(r + 1) + getCol(j) + getRowAlpha(i + 1) + l;
                        validMove = "";
                        validMove += getCol(c);
                        validMove += getRowAlpha(r + 1);
                        validMove += getCol(j);
                        validMove += getRowAlpha(i + 1);
                        validMove += l;
                        posMoves.push_back(validMove);
                        //std::cout << "c" << j << "r" << i << " is valid" << std::endl;
                    }
                }
        }
    // Check for castle move
    // syntax for castle move e1g1c (e8g1c) -> King Side, e1c1C (e8c1C) -> Queen Side
    //      There are only two spots a King can move to when castling: 2 squares to the left or 2 squares to the right.
    //      All squares between the King and the Rook must be empty
    
    // If the King has moved, Castling is NOT allowed.
    if (!board.squares[r][c]->fMoved)    //King has NOT moved
    {
        // If the Queen side Rook has moved, Queen side castling is NOT allowed
        if (!board.squares[r][0]->fMoved)  // Queen Side Rook has NOT moved
        {
            for (int i = 1; i < 4; i++)
                // If there are pieces between the King and the Rook,
                // Castling is NOT allowed
                if (!(board.squares[r][i]->getLetter() == ' '))
                {
                    qCastle = false;  // can NOT Queen side Castle
                    break;
                }
            // If qCastle = true, we CAN Queen side castle
            if (qCastle)
            {
                //validMove = getCol(c) + getRowAlpha(r + 1) + 'c' + getRowAlpha(r + 1) + 'C';
                validMove = "";
                validMove += getCol(c);
                validMove += getRowAlpha(r + 1);
                validMove += 'c';
                validMove += getRowAlpha(r + 1);
                validMove += 'C';
                posMoves.push_back(validMove);
            }
        }
        // If the King side Rook has moved, King side castling is NOT allowed
        if (!board.squares[r][7]->fMoved)  // King Side Rook has NOT moved
        {
            for (int i = 5; i < 7; i++)
                // If there are pieces between the King and the Rook,
                // Castling is NOT allowed
                if (!(board.squares[r][i]->getLetter() == ' '))
                {
                    kCastle = false;  // can NOT King side Castle
                    break;
                }
            // If kCastle = true, we CAN King side castle
            if (kCastle)
            {
                //validMove = getCol(c) + getRowAlpha(r + 1) + 'g' + getRowAlpha(r + 1) + 'c';
                validMove = "";
                validMove += getCol(c);
                validMove += getRowAlpha(r + 1);
                validMove += 'g';
                validMove += getRowAlpha(r + 1);
                validMove += 'c';
                posMoves.push_back(validMove);
            }
        }
    }
}

/***************************************************
 * QUEEN::GETMOVES
 * This gets all of the valid moves for the QUEEN.
 * It modifies the piece's possible moves vector.
 ***************************************************/
void Queen::getMoves(Board & board, Position & position)
{
    std::vector<std::string> linear;
    std::vector<std::string> diagonal;
    linear = getLinearMoves(board, position);
    diagonal = getDiagMoves(board, position);
    posMoves.insert(posMoves.end(), linear.begin(), linear.end());
    posMoves.insert(posMoves.end(), diagonal.begin(), diagonal.end());
    
}

/***************************************************
 * BISHOP::GETMOVES
 * This gets all of the valid moves for the BISHOP.
 * It modifies the piece's possible moves vector.
 ***************************************************/
void Bishop::getMoves(Board & board, Position & position)
{
    std::vector<std::string> diagonal;
    diagonal = getDiagMoves(board, position);
    posMoves.insert(posMoves.end(), diagonal.begin(), diagonal.end());
    
}

/***************************************************
 * KNIGHT::GETMOVES
 * This gets all of the valid moves for the KNIGHT.
 * It modifies the piece's possible moves vector.
 ***************************************************/
void Knight::getMoves(Board & board, Position & position)
{
    int r = position.getRow();
    int c = position.getCol();
    int row = 0;
    int col = 0;
    char l = '\0';
    string validMove;
    bool w = board.squares[r][c]->getIsWhite();
    
    //std::vector<std::string> posMoves;
    
    // Check moves to the upper left
    int nSquares[8][2] =
    {
        {r + 2,c - 1},
        {r + 2,c + 1},
        {r + 1,c - 2},
        {r + 1,c + 2},
        {r - 2,c - 1},
        {r - 2,c + 1},
        {r - 1,c - 2},
        {r - 1,c + 2}
    };
    for (int i = 0; i < 8; i++)
    {
        row = nSquares[i][0];
        col = nSquares[i][1];
        //validate row and col
        if (row >= 0 && row < 8 && col >= 0 && col < 8)
        {
            l = tolower(board.squares[row][col]->getLetter());
            if (l == ' ')
            {
                //validMove = getCol(c) + getRowAlpha(r + 1) + getCol(col) + getRowAlpha(row + 1);
                validMove = "";
                validMove += getCol(c);
                validMove += getRowAlpha(r + 1);
                validMove += getCol(col);
                validMove += getRowAlpha(row + 1);
                posMoves.push_back(validMove);
            }
            else if (w != (board.squares[row][col]->getIsWhite()))
            {
                //validMove = getCol(c) + getRowAlpha(r + 1) + getCol(col) + getRowAlpha(row + 1) + l;
                validMove = "";
                validMove += getCol(c);
                validMove += getRowAlpha(r + 1);
                validMove += getCol(col);
                validMove += getRowAlpha(row + 1);
                validMove += l;
                posMoves.push_back(validMove);
            }
        }
    }
    
    
}

/***************************************************
 * ROOK::GETMOVES
 * This gets all of the valid moves for the ROOK.
 * It modifies the piece's possible moves vector.
 ***************************************************/
void Rook::getMoves(Board & board, Position & position)
{
    std::vector<std::string> linear;
    linear = getLinearMoves(board, position);
    posMoves.insert(posMoves.end(), linear.begin(), linear.end());
}

/***************************************************
 * PAWN::GETMOVES
 * This gets all of the valid moves for the PAWN.
 * It modifies the piece's possible moves vector.
 ***************************************************/
void Pawn::getMoves(Board & board, Position & position)
{
    int r = position.getRow();  // index of source row
    int c = position.getCol();  // index of source col
    int lastRow;
    bool w = isWhite;
    char l = '\0';
    int dest1_index = 0;   // row index of 1 square move
    int dest1_display = 0; // row display of 1 square move
    int dest2_index = 0;   // row index of 2 square move
    int dest2_display = 0; // row display of 2 square move
    string validMove;
    char posPromotions[] = {"QRBN"};
    
    dest1_index = isWhite ? r + 1 : r - 1;
    dest2_index = isWhite ? r + 2 : r - 2;
    dest1_display = dest1_index + 1;
    dest2_display = dest2_index + 1;
    // A Pawn can only move to 4 possible squares
    // 1 & 2) either of the two squares directly in front of it
    // 3 & 4) either of the two squares diagonally in front of it
    
    // get last row based on color
    lastRow = w ? 7 : 0;
    
    // first: can the pawn move 1 square forward
    if (board.squares[dest1_index][c]->getLetter() == ' ')
    {
        // Check if move is into the last row
        if (dest1_index == lastRow)  // Promotion
        {
            for (int i = 0; i < 4; i++)
            {
                validMove = "";
                validMove += getCol(c);
                validMove += getRowAlpha(r + 1);
                validMove += getCol(c);
                validMove += getRowAlpha(dest1_display);
                validMove += posPromotions[i];
                posMoves.push_back(validMove);
            }
        }
        else
        {
            validMove = "";
            validMove += getCol(c);
            validMove += getRowAlpha(r + 1);
            validMove += getCol(c);
            validMove += getRowAlpha(dest1_display);
            posMoves.push_back(validMove);
        }
    }
    
    // second: has the pawn moved - can the pawn move 2 squares
    if (!board.squares[r][c]->fMoved)  // Pawn has not moved
    {
        if ((board.squares[dest1_index][c]->getLetter() == ' ') && (board.squares[dest2_index][c]->getLetter() == ' '))
        {
            validMove = "";
            validMove += getCol(c);
            validMove += getRowAlpha(r + 1);
            validMove += getCol(c);
            validMove += getRowAlpha(dest2_display);
            posMoves.push_back(validMove);
        }
    }
    
    // third: can the pawn attack to the left
   int colMoveLeft;
   int colMoveRight;
   colMoveLeft = (w) ? (c - 1) : (c + 1);
   //colMoveLeft = c - 1;
   if (colMoveLeft >= 0 && colMoveLeft < 8)
   {
      l = tolower(board.squares[dest1_index][colMoveLeft]->getLetter());
      if (!(l == ' ') && c > 0)
      {
         if (w != (board.squares[dest1_index][colMoveLeft]->getIsWhite()))
         {
            // Check if move is into the last row
            if (dest1_index == lastRow)  // Promotion
            {
               for (int i = 0; i < 4; i++)
               {
                  validMove = "";
                  validMove += getCol(c);
                  validMove += getRowAlpha(r + 1);
                  validMove += getCol(colMoveLeft);
                  validMove += getRowAlpha(dest1_display);
                  validMove += posPromotions[i];
                  validMove += l;
                  posMoves.push_back(validMove);
               }
            }
            else
            {
               //No Promotion - you failed the interview  :)
               validMove = "";
               validMove += getCol(c);
               validMove += getRowAlpha(r + 1);
               validMove += getCol(colMoveLeft);
               validMove += getRowAlpha(dest1_display);
               validMove += l;
               posMoves.push_back(validMove);
            }
         }
      }
   }
   
    // fourth: can the pawn attack to the right
    colMoveRight = (w) ? (c + 1) : (c - 1);
    //colMoveRight = c + 1;
   if (colMoveRight >= 0 && colMoveRight < 8)
   {
      l = tolower(board.squares[dest1_index][colMoveRight]->getLetter());
      if (!(l == ' ') && c < 7)
      {
         if (w != (board.squares[dest1_index][colMoveRight]->getIsWhite()))
         {
            // Check if move is into the last row
            if (dest1_index == lastRow)  // Promotion
            {
               for (int i = 0; i < 4; i++)
               {
                  validMove = "";
                  validMove += getCol(c);
                  validMove += getRowAlpha(r + 1);
                  validMove += getCol(colMoveRight);
                  validMove += getRowAlpha(dest1_display);
                  validMove += posPromotions[i];
                  validMove += l;
                  posMoves.push_back(validMove);
               }
            }
            else
            {
               //No Promotion - you failed the interview  :)
               validMove = "";
               validMove += getCol(c);
               validMove += getRowAlpha(r + 1);
               validMove += getCol(colMoveRight);
               validMove += getRowAlpha(dest1_display);
               validMove += l;
               posMoves.push_back(validMove);
            }
         }
      }
   }
   
    // fifth: can the pawn do an en passant
    if (board.history.size() >= 1 )
    {
        std::string lastMove = board.history[board.history.size() - 1];
        //std::cout << lastMove << std::endl;
        int pRow = lastMove[3] - '1'; // previous move Row Destination (Index)
        int pCol = lastMove[2] - 97;  // previous move Col Destination (Index)
        int pSourceRow = lastMove[1] - '1'; // previous move Row Destination (Index)
        //int pSourceCol = lastMove[0] - 97;  // previous move Col Destination (Index)
        
        if (tolower(board.squares[pRow][pCol]->getLetter()) == 'p')
        {
            if (pRow == r && (!((pSourceRow - pRow) % 2)))
            {
                if (pCol == (c - 1) && (w != (board.squares[pRow][pCol]->getIsWhite()))) // Check left side
                {
                    validMove = "";
                    validMove += getCol(c);
                    validMove += getRowAlpha(r + 1);
                    validMove += getCol(c - 1);
                    validMove += getRowAlpha(dest1_display);
                    validMove += 'E';
                    //validMove += (w) ? 'E' : 'e';
                    posMoves.push_back(validMove);
                    
                }
                else if (pCol == (c + 1) && (w != (board.squares[pRow][pCol]->getIsWhite()))) // Check right side
                {
                    validMove = "";
                    validMove += getCol(c);
                    validMove += getRowAlpha(r + 1);
                    validMove += getCol(c + 1);
                    validMove += getRowAlpha(dest1_display);
                    validMove += 'E';
                    //validMove += (w) ? 'E' : 'e';
                    posMoves.push_back(validMove);
                }
            }
        }
    }
}

