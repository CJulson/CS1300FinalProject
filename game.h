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

using namespace std;

#ifndef GAME_H
#define GAME_H

class Game {
    private:


    public:
        bool win;
        void setWin();
        void checkWin();

        bool lose;
        void checkLose();
        void setLose();

        Game();

};

#endif