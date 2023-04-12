#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <vector>
#include "character.h"
#include "party.h"
#include "game.h"
using namespace std;

// Party::Party() {
//     for (int i = 1; i < 6; i++) {
//         Character("");
//     }
// }

Party::Party(Game game_) {
    string temp;
    cout << "Welcome to Dungeon Escape!" << endl;
    cout << "Please input the names of your party." << endl;
    for (int i = 1; i < 6; i++) {
        cout << "Member " << i << ":" << endl;
        cin >> temp;
        members[i-1] = Character(temp);
        cout << "Hi, " << temp << " welcome to dungeon esacpe!" << endl;
    }
    int gold =0;
    int ingredients=0;
    int cookware[3]={0,0,0};
    int weapons[5]={0,0,0,0,0};
    int armor=0;
    int treasures[5]={0,0,0,0,0};
    int keys = 0;
    int roomsClear = 0;
    int anger = 0;
    Game game = game_;
}

bool Party::checkPartyLive() {
    int liveCount = 0;
    //bool deadIndex[5] = {0,0,0,0,0};
    for(int i = 1; i < 6; i++) {
        if(members[i].fullness > 1) {
            liveCount++;
            //deadIndex[i] = 1;
        }
    }

    if(liveCount < 1) {
        return false;
    } else {
        return true;
    }
}

void Party::printInventory() {
    cout << "+-------------+" << endl;
    cout << "| INVENTORY   |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Gold        | " << gold << endl;
    cout << "| Ingredients | " << ingredients << " kg" << endl;
    cout << "| Cookware    | P: " << cookware[0] << " | F: " << cookware[1] << " | C: " << cookware[2] << endl;
    cout << "| Weapons     | C: " << weapons[0] << " | S: " << weapons[1] << " | R: " << weapons[2] << " B:  "<< weapons[3] << " | L: " << weapons[4] << endl;
    cout << "| Armor       | " << armor << endl;
    cout << "| Treasures   | R: " << treasures[0] << " | N: " << treasures[1] << " | B: " << treasures[2] << " C:  "<< treasures[3] << " | G: " << treasures[4] << endl;
    cout << "+-------------+" << endl;
}

void Party::printStatus() {
    cout << "+-------------+" << endl;
    cout << "| STATUS      |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Rooms Cleared: " << roomsClear << " | Keys: " << keys << " | Anger Level: " << anger << endl;
    printInventory();
    cout << "| PARTY.      |" << endl;
    cout << "+-------------+" << endl;
    cout << "| " << members[0].name << " | Fullness: " << members[0].fullness << endl;
    cout << "| " << members[1].name << " | Fullness: " << members[1].fullness << endl;
    cout << "| " << members[2].name << " | Fullness: " << members[2].fullness << endl;
    cout << "| " << members[3].name << " | Fullness: " << members[3].fullness << endl;
    cout << "| " << members[4].name << " | Fullness: " << members[4].fullness << endl;
    cout << "+-------------+" << endl;
}

void Party::checkAnger() {
    if(anger > 99) {
        game.lose = false;
    } else {
        return;
    }
}

void Party::checkLose() {
    if(anger > 99) {
        cout << "The wizard has grown too angry and sealed the exit! You perish in the dungeon." << endl;
        game.setLose();
        return;
    } else if (checkPartyLive()) {
        cout << "All of you party members have perished. You did not escape the dungeon" << endl;
        game.setLose();
        return;
    } else {
        return;
    }
}

