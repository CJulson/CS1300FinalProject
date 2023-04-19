#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <vector>
#include "character.h"
using namespace std;

Character::Character() {
    name = "";
    fullness = 50;
    checkDead = false;//makes sure character doesn't get dead checked twice
}

Character::Character(string name_) {
    name = name_;
    fullness = 50;
    checkDead = false;//makes sure character doesn't get dead checked twice
}

bool Character::checkAlive() {
    if (fullness < 1 && checkDead == false) {
        string newName = name + " - Deceased.";
        name = newName;
        checkDead = true;
        return false;
    }else if(fullness < 1 && checkDead == true) {
        return false;
    } else {
        return true;
    }
}