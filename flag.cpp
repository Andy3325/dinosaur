#include "flag.h"

Flag::Flag()
{
    prex = 0;
    prey = 0;
}

bool Flag::update(int y)
{
    if(y>=prey&&prey!=0)
    {
        y=prey;
    }
    return false;
}

