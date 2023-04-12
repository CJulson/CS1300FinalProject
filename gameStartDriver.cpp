#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <vector>
#include "character.h"
#include "game.h"
#include "party.h"
#include "merchant.h"
using namespace std;

int main() {
    Game testGame = Game();

    Party testParty = Party(testGame);

    merchantMenu(testParty);
}