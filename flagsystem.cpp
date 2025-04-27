// flagsystem.cpp
#include "flagsystem.h"

//
// —— Flag implementation ——
//
Flag::Flag()
    : prex(0)
    , prey(0)
    , flagY(0)
{}

bool Flag::update(int yInput)
{
    // First call: initialize position
    if (prey == 0) {
        flagY = yInput;
        prey  = yInput;
        return false;       // no “movement” on init
    }

    // Prevent the flag from moving downward (i.e. y increasing)
    int yNew = yInput;
    if (yNew >= static_cast<int>(prey)) {
        yNew = static_cast<int>(prey);
    }

    // Did it actually move up?
    if (yNew != static_cast<int>(prey)) {
        flagY = yNew;
        prey  = yNew;
        return true;
    }

    return false;
}

//
// —— FlagPole implementation ——
//
FlagPole::FlagPole()
    : flagState(0)  // 0 = at top, 1 = hanging down
{}

bool FlagPole::update()
{
    // Toggle between “at top” and “hanging down”
    flagState = (flagState == 0 ? 1 : 0);
    return true;      // we always change state when called
}
