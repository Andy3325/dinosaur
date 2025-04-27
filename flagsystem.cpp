
#include "flagsystem.h"

Flag::Flag()
    : prex(0)
    , prey(0)
    , flagY(0)
{}

bool Flag::update(int yInput)
{

    if (prey == 0) {
        flagY = yInput;
        prey  = yInput;
        return false;
    }


    int yNew = yInput;
    if (yNew >= static_cast<int>(prey)) {
        yNew = static_cast<int>(prey);
    }


    if (yNew != static_cast<int>(prey)) {
        flagY = yNew;
        prey  = yNew;
        return true;
    }

    return false;
}


FlagPole::FlagPole()
    : flagState(0)
{}

bool FlagPole::update()
{

    flagState = (flagState == 0 ? 1 : 0);
    return true;
}
