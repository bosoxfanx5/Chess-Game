//
//  piece.cpp
//  Object Oriented Chess
//
//  Created by Brooks Robison on 3/17/16.
//  Copyright © 2016 Dan McDaniel. All rights reserved.
//

#include "piece.h"
#include "board.h"
#include <vector>
#include <iostream>
#include <cctype>
//#include "position.h"

//Non-Member Functions

char getCol(int c)
{
    char columns[9] = {"abcdefgh"};
    
    return columns[c];
}

std::vector<std::string> getDiagMoves(Board & board, Position & position)
{
    int r = position.getRow();
    int c = position.getCol();
    int row = 0;
    int col = 0;
    string l = "";
    string validMove;
    bool w = board.squares[r][c]->getIsWhite();
    
   std::vector<std::string> posMoves;
    
    // Check moves to the upper left
    for (row = (r + 1), col = (c - 1); row < 8 && col >= 0; col--, row++)
    {
        l = tolower(board.squares[row][col]->getLetter());
        if (l == " ")
        {
            validMove = getCol(c) + std::to_string(r + 1) + getCol(col) + std::to_string(row + 1);
            posMoves.push_back(validMove);
        }
        else if (w != (board.squares[row][col]->getIsWhite()))
        {
            validMove = getCol(c) + std::to_string(r + 1) + getCol(col) + std::to_string(row + 1) + l;
            posMoves.push_back(validMove);
            break;
        }
    }

    // Check moves to the upper right
    for (row = (r + 1), col = (c + 1); row < 8 && col < 8; col++, row++)
    {
        l = tolower(board.squares[row][col]->getLetter());
        if (l == " ")
        {
            validMove = getCol(c) + std::to_string(r + 1) + getCol(col) + std::to_string(row + 1);
            posMoves.push_back(validMove);
        }
        else if (w != (board.squares[row][col]->getIsWhite()))
        {
            validMove = getCol(c) + std::to_string(r + 1) + getCol(col) + std::to_string(row + 1) + l;
            posMoves.push_back(validMove);
            break;
        }
    }
    
    // Check moves to the lower right
    for (row = (r - 1), col = (c + 1); row >= 0 && col < 8; col++, row--)
    {
        l = tolower(board.squares[row][col]->getLetter());
        if (l == " ")
        {
            validMove = getCol(c) + std::to_string(r + 1) + getCol(col) + std::to_string(row + 1);
            posMoves.push_back(validMove);
        }
        else
        {
            if (w != (board.squares[row][col]->getIsWhite()))
            {
                validMove = getCol(c) + std::to_string(r + 1) + getCol(col) + std::to_string(row + 1) + l;
                posMoves.push_back(validMove);
            }
            break;
        }
    }
 
    // Check moves to the lower left
    for (row = (r - 1), col = (c - 1); row >= 0 && col >= 0; col--, row--)
    {
        l = tolower(board.squares[row][col]->getLetter());
        if (l == " ")
        {
            validMove = getCol(c) + std::to_string(r + 1) + getCol(col) + std::to_string(row + 1);
            posMoves.push_back(validMove);
        }
        else
        {
            if (w != (board.squares[row][col]->getIsWhite()))
            {
                validMove = getCol(c) + std::to_string(r + 1) + getCol(col) + std::to_string(row + 1) + l;
                posMoves.push_back(validMove);
            }
            break;
        }
    }
   //Tom:  Your code goes here.
   
   return posMoves;
}

std::vector<std::string> getLinearMoves(Board & board, Position & position)
{
    int r = position.getRow();
    int c = position.getCol();
    string l = "";
    string validMove;
    bool w = board.squares[r][c]->getIsWhite();
    
    std::vector<std::string> posMoves;
    
    // Check moves to the left
    for (int col = c - 1; col >= 0; col--)
    {
        l = tolower(board.squares[r][col]->getLetter());
        if (l == " ")
        {
            validMove = getCol(c) + std::to_string(r + 1) + getCol(col) + std::to_string(r + 1);
            posMoves.push_back(validMove);
        }
        else if (w != (board.squares[r][col]->getIsWhite()))
        {
            validMove = getCol(c) + std::to_string(r + 1) + getCol(col) + std::to_string(r + 1) + l;
            posMoves.push_back(validMove);
            break;
        }
    }

    // Check moves to the right
    for (int col = c + 1; col < 8; col++)
    {
        l = tolower(board.squares[r][col]->getLetter());
        if (l == " ")
        {
            validMove = getCol(c) + std::to_string(r + 1) + getCol(col) + std::to_string(r + 1);
            posMoves.push_back(validMove);
        }
        else if (w != (board.squares[r][col]->getIsWhite()))
        {
            validMove = getCol(c) + std::to_string(r + 1) + getCol(col) + std::to_string(r + 1) + l;
            posMoves.push_back(validMove);
            break;
        }
    }
  
    // Check moves to the top
    for (int row = r + 1; row < 8; row++)
    {
        l = tolower(board.squares[row][c]->getLetter());
        if (l == " ")
        {
            validMove = getCol(c) + std::to_string(r + 1) + getCol(c) + std::to_string(row + 1);
            posMoves.push_back(validMove);
        }
        else
        {
            if (w != (board.squares[row][c]->getIsWhite()))
            {
            validMove = getCol(c) + std::to_string(r + 1) + getCol(c) + std::to_string(row + 1) + l;
            posMoves.push_back(validMove);
            }
            break;
        }
    }
 
    
    // Check moves to the bottom
    for (int row = r - 1; row >= 0; row--)
    {
        l = tolower(board.squares[row][c]->getLetter());
        if (l == " ")
        {
            validMove = getCol(c) + std::to_string(r + 1) + getCol(c) + std::to_string(row + 1);
            posMoves.push_back(validMove);
        }
        else
        {
            if (w != (board.squares[row][c]->getIsWhite()))
            {
            validMove = getCol(c) + std::to_string(r + 1) + getCol(c) + std::to_string(row + 1) + l;
            posMoves.push_back(validMove);
            }
            break;
        }
    }
    
    //posMoves.push_back("a2a3");
   //Tom:  Your code goes here.
   
   return posMoves;
}


//Member Functions

void Space::getMoves(Board & board, Position & position)
{
}

/*******************************************
* King::getMoves
* This gets all of the valid moves for the king.
* It modifies the piece's possible moves vector.
*******************************************/
void King::getMoves(Board & board, Position & position)
{
  
   int r = position.getRow();
   int c = position.getCol();
   bool w = isWhite;
   string l = "";
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
               if (l == " " || w != board.squares[i][j]->getIsWhite())
               {
                  validMove = getCol(c) + std::to_string(r + 1) + getCol(j) + std::to_string(i + 1) + l;
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
               validMove = getCol(c) + std::to_string(r + 1) + 'c' + std::to_string(r + 1) + 'C';
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
               validMove = getCol(c) + std::to_string(r + 1) + 'g' + std::to_string(r + 1) + 'c';
               posMoves.push_back(validMove);
           }
       }
   }
}

void Queen::getMoves(Board & board, Position & position)
{
    std::vector<std::string> linear;
    std::vector<std::string> diagonal;
    linear = getLinearMoves(board, position);
    diagonal = getDiagMoves(board, position);
    posMoves.insert(posMoves.end(), linear.begin(), linear.end());
    posMoves.insert(posMoves.end(), diagonal.begin(), diagonal.end());

}

void Bishop::getMoves(Board & board, Position & position)
{
    std::vector<std::string> diagonal;
    diagonal = getDiagMoves(board, position);
    posMoves.insert(posMoves.end(), diagonal.begin(), diagonal.end());
   
}

void Knight::getMoves(Board & board, Position & position)
{
    int r = position.getRow();
    int c = position.getCol();
    int row = 0;
    int col = 0;
    string l = "";
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
            if (l == " ")
            {
                validMove = getCol(c) + std::to_string(r + 1) + getCol(col) + std::to_string(row + 1);
                posMoves.push_back(validMove);
            }
            else if (w != (board.squares[row][col]->getIsWhite()))
            {
                validMove = getCol(c) + std::to_string(r + 1) + getCol(col) + std::to_string(row + 1) + l;
                posMoves.push_back(validMove);
            }
        }
    }

   
}

void Rook::getMoves(Board & board, Position & position)
{
    std::vector<std::string> linear;
    linear = getLinearMoves(board, position);
    posMoves.insert(posMoves.end(), linear.begin(), linear.end());
}

void Pawn::getMoves(Board & board, Position & position)
{
    int r = position.getRow();  // index of source row
    int c = position.getCol();  // index of source col
    int lastRow;
    bool w = isWhite;
    string l = "";
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
    
    // get last row
    lastRow = w ? 7 : 0;
    
    // first: can the pawn move 1 square forward
    if (board.squares[dest1_index][c]->getLetter() == ' ')
    {
        // Check if move is into the last row
        if (dest1_index == lastRow)  // Promotion
        {
            for (int i = 0; i < 4; i++)
            {
                validMove = getCol(c) + std::to_string(r + 1) + getCol(c) + std::to_string(dest1_display) + posPromotions[i];
                posMoves.push_back(validMove);
            }
        }
        else
        {
            validMove = getCol(c) + std::to_string(r + 1) + getCol(c) + std::to_string(dest1_display);
            posMoves.push_back(validMove);
        }
    }
    
    // second: has the pawn moved - can the pawn move 2 squares
    if (!board.squares[r][c]->fMoved)  // Pawn has not moved
    {
        if ((board.squares[dest1_index][c]->getLetter() == ' ') && (board.squares[dest2_index][c]->getLetter() == ' '))
        {
            validMove = getCol(c) + std::to_string(r + 1) + getCol(c) + std::to_string(dest2_display);
            posMoves.push_back(validMove);
        }
    }
 
    // third: can the pawn attack to the left
    l = tolower(board.squares[dest1_index][c - 1]->getLetter());
    if (!(l == " ") && c > 0)
    {
        if (w != (board.squares[dest1_index][c - 1]->getIsWhite()))
        {
            // Check if move is into the last row
            if (dest1_index == lastRow)  // Promotion
            {
                for (int i = 0; i < 4; i++)
                {
                    validMove = getCol(c) + std::to_string(r + 1) + getCol(c - 1) + std::to_string(dest1_display) + posPromotions[i] + l;
                    posMoves.push_back(validMove);
                }
            }
            else
            {
                //Check if the move is into the last row for promotion
                validMove = getCol(c) + std::to_string(r + 1) + getCol(c - 1) + std::to_string(dest1_display) + l;
                posMoves.push_back(validMove);
            }
        }
    }

    // fourth: can the pawn attack to the right
    l = tolower(board.squares[dest1_index][c + 1]->getLetter());
    if (!(l == " ") && c < 7)
    {
        if (w != (board.squares[dest1_index][c + 1]->getIsWhite()))
        {
            // Check if move is into the last row
            if (dest1_index == lastRow)  // Promotion
            {
                for (int i = 0; i < 4; i++)
                {
                    validMove = getCol(c) + std::to_string(r + 1) + getCol(c + 1) + std::to_string(dest1_display) + posPromotions[i] + l;
                    posMoves.push_back(validMove);
                }
            }
            else
            {
                validMove = getCol(c) + std::to_string(r + 1) + getCol(c + 1) + std::to_string(dest1_display) + l;
                posMoves.push_back(validMove);
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
                    validMove = getCol(c) + std::to_string(r + 1) + getCol(c - 1) + std::to_string(dest1_display) + 'E';
                    posMoves.push_back(validMove);

                }
                else if (pCol == (c + 1) && (w != (board.squares[pRow][pCol]->getIsWhite()))) // Check right side
                {
                    validMove = getCol(c) + std::to_string(r + 1) + getCol(c + 1) + std::to_string(dest1_display) + 'E';
                    posMoves.push_back(validMove);
                }
            }
        }
    }
    
}

