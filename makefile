########################################################################
# Program:
#     Project 3, Object Oriented Chess
#     Brother McCracken, CS165
# Author:
#    Dan McDaniel
# Summary: 
#    
# Extra Credit:
#    1.  Undo feature is available by typing in 'undo'
#    2.  Auto move feature is available by typeing in 'auto'
#    3.  Rank is available by typing in 'rank'
#    4.  Move history is available by typing 'hystory'
#
#    Auto move and Rank have been commented out to get it to compile on the
#    server.  This work when compiled on a Mac.
#
# Group Names and Contribution:
#    Dan McDaniel     = 33.3%
#    Brooks Robison   = 33.3%
#    Thomas Woodworth = 33.3%
#########################################################################

#########################################################################
#   The main rule
#########################################################################
a.out: main.o board.o move.o piece.o position.o
	g++ -o a.out main.o board.o move.o piece.o position.o
	tar -cf project3.tar *.h *.cpp makefile
	
#########################################################################
#   The object files
#########################################################################
main.o: main.cpp board.h
	g++ -c main.cpp
	
board.o: board.cpp board.h position.h move.h piece.h
	g++ -c board.cpp
   
move.o: move.cpp move.h
	g++ -c move.cpp
   
piece.o: piece.cpp piece.h board.h
	g++ -c piece.cpp
   
position.o: position.cpp position.h
	g++ -c position.cpp