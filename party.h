//CS1300 Spring 2023
// Author: Connor Julson/Ben P
// Recitation: 106 - Sachin Sharma
//Project 3

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <vector>
#include "game.h"
#include "character.h"
using namespace std;

#ifndef PARTY_H
#define PARTY_H

class Party {

public:
    Game game;
    int roomsClear;
    int anger;
    bool partyLive;
    bool checkPartyLive();

    Character members[5];
    // void setParty(string name1, string name2, string name3, string name4, string name5);

    int gold;
    int ingredients;
    int cookware[3];
    int weapons[5];
    int armor;
    int treasures[5];

    int keys;

    void printInventory();
    void printStatus();
    Party();
    Party(Game &game_);
    void checkAngerLose(Game &game);
    //void checkLose(Game &game);
    void merchantMenu();

    int monstersDefeated;


};

#endif