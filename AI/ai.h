#ifndef AI_INCLUDED
#define AI_INCLUDED

#include "..\utils\move.h"

class AI
{
  public:
    virtual Move get_move() = 0;
};



#endif
