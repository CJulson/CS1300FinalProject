#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <vector>
#include "game.h"
#include "party.h"
using namespace std;

Game::Game() {
    bool win = false;
    bool lose = false;
}

void Game::setWin() {
    win = true;
}

void Game::checkWin() {
    if(win == true) {
        cout << "Congrats you have escaped the dungeon!" << endl;
    }
}

void Game::setLose() {
    lose = true;
}
void Game::checkLose() {
    if(lose = true) {
        cout << "Game over." << endl;
    }
}