#ifndef FLAGSYSTEM_H
#define FLAGSYSTEM_H

class Flag
{
public:
    Flag();
    bool update(int y);

    double prex{0};
    double prey{0};
    double flagY{0};
};

class FlagPole
{
public:
    FlagPole();
    bool update();

    int flagState{0};
};

#endif // FLAGSYSTEM_H
