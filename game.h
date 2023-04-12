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
#include "party.h"
using namespace std;

#ifndef GAME_H
#define BUFFCHAT_H

class Game {
    private:


    public:
        bool win;
        bool setWin();

        bool lose;
        bool checkLose(Party party);

        Game();

};