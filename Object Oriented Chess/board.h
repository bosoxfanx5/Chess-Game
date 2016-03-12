//
//  board.h
//  Object Oriented Chess
//
//  Created by Dan on 3/6/16.
//  Copyright © 2016 Brooks, Dan and Tom. All rights reserved.
//

#ifndef board_h
#define board_h

class Board
{
public:
   virtual void load() = 0;
   virtual void draw() = 0;
   bool interact() {return true;}
   
private:
   float length = 0;
   float width  = 0;
   float height = 0;
};

#endif /* board_h */
