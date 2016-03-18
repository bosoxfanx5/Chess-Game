//
//  main.cpp
//  Object Oriented Chess
//
//  Created by Brooks Robison on 3/17/16.
//  Copyright © 2016 Dan McDaniel. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void interact(vector < string > &moveHistory, char board[][8])
{
    bool testMode = false;
    string input;
    bool quit = false;
    do
    {
        // who's turn is it? yours or mine?
        switch (moveHistory.size() % 2)
        {
            case 0:
                cout << "(White): ";
                break;
            case 1:
                cout << "(Black): ";
                break;
        }
        
        cin >> input;
        
        if (input == "?")
            options();
        else if (input == "read")
            readFile(moveHistory, board, testMode);
        else if (input == "test")
        {
            testMode = !testMode;
            display(board, testMode);
        }
        else if (input == "quit")
            quit = true;
        else
        {
            try
            {
                // take users input as an attempt to make a move on the
                // board
                Move move;
                move.text = input;
                parseMove(move, board);
                executeMove(move, board);
                display(board, testMode);
                moveHistory.push_back(move.text);
            }
            catch (string error)
            {
                cout << "Error in move \'" << input << "\': " << error << endl;
                cout << "      Type ? for more options\n";
            }
        }
    }
    while (quit == false);
    
    writeFile(moveHistory);
}