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