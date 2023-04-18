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


#ifndef CHARACTER_H
#define CHARACTER_H

using namespace std;

class Character {
    private:

    public:

        int fullness;
        int checkAlive();

        string name;

        Character();
        Character(string name);

};

#endif