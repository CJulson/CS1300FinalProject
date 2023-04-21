#include <iostream>
#include <string>
using namespace std;

#ifndef SCORE_H
#define SCORE_H

class Score {
    public:
    string leaderName;
    int turns;
    int gold;
    int treasures;
    int monstersDefeated;
    int exploredSpaces;
    Score();
};

#endif