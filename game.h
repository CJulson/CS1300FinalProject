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

class Game {
    private:


    public:
        bool win;
        bool checkWin();

        bool lose;
        bool checkLose();

        int anger;
        int checkAnger();

        int roomsClear;

        bool keys;
        bool checkKeys();

        Game();
        Game(string game);

};