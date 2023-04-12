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

Game::Game() {
    bool win = false;
    bool lose = false;
}

bool Game::setWin() {
    win = true;
}

void Game::checkWin() {
    if(win == true) {
        cout << "Congrats you have escaped the dungeon!" << endl;
    }
}

bool Game::checkLose(Party party) {
    if(party.anger > 99) {
        cout << "The wizard has grown too angry and sealed the exit! You perish in the dungeon." << endl;
        cout << "Game over." << endl;
        lose = true;
        return true;
    } else if (party.checkPartyLive()) {
        cout << "All of you party members have perished. You did not escape the dungeon" << endl;
        cout << "Game over." << endl;
        lose = true;
    } else {
        return false;
    }
}