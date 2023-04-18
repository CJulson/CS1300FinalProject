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
}

Character::Character(string name_) {
    name = name_;
    fullness = 50;
}

int Character::checkAlive() {
    if (fullness < 1) {
        string newName = "Dead " + name;
        name = newName;
        return 0;
    } else {
        return 1;
    }
}