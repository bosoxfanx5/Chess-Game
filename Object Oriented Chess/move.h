//
//  move.h
//  Object Oriented Chess
//
//  Created by Dan on 3/6/16.
//  Copyright © 2016 Dan McDaniel. All rights reserved.
//

#ifndef move_h
#define move_h

#include "location.h"

class Move
{
   Move(Location origin, Location destination) {};
   
public:
   Location origin;
   Location destination;
   bool validate();
   void execute();
};

#endif /* move_h */
