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
    win = false;
    lose = false;
}

void Game::setWin() {
    win = true;
}

void Game::checkWin() {
    if(win == true) {
        cout << "Congrats you have escaped the dungeon!" << endl;
        cout << "You win!" << endl;
    }
}

void Game::setLose() {
    lose = true;
}
void Game::checkLose() {
    if(lose == true) {
        cout << "You have failed to escape the dungeon." << endl;
        cout << "Game over." << endl;

    }
}