//
//  move.h
//  Object Oriented Chess
//
//  Created by Dan on 3/6/16.
//  Copyright © 2016 Brooks, Dan and Tom. All rights reserved.
//

#ifndef move_h
#define move_h

#include "location.h"

class Move
{
public:
   
   Move() {};
   Move(Location origin, Location destination) {};

   Location * origin;
   Location * destination;
   virtual bool validate() = 0;
   virtual void execute() = 0;
};

#endif /* move_h */
