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
#include "character.h"
#include "game.h"
using namespace std;

class Party {

    bool partyLive;
    bool checkPartyLive(string party);

    Character members[5];
    // void setParty(string name1, string name2, string name3, string name4, string name5);

    int gold;
    int ingredients;
    int cookware[3];
    int weapons[5];
    int armor;
    int treasures[5];

    int keys;

    void printInventory(string party);
    void printStatus(string party, string game);
    Party();
    Party(string party);


};