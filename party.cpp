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

Party::Party() {
    for (int i = 1; i < 6; i++) {
        Character("");
    }
}

Party::Party(string party) {
    string temp;
    cout << "Welcome to Dungeon Escape!" << endl;
    cout << "Please input the names of your party." << endl;
    for (int i = 1; i < 6; i++) {
        cout << "Member " << i << ":" << endl;
        cin >> temp;
        party.members[i-1] = Character(temp);
        cout << "Hi, " << temp << " welcome to dungeon esacpe!" << endl;
    }
}

bool Party::checkPartyLive(string party) {
    int liveCount = 0;
    for(int i = 1; i < 6; i++) {
        if(party.members[i].fullness > 1) {
            liveCount++;
        }
    }
    if(liveCount < 1) {
        return false;
    } else {
        return true;
    }
}

void Party::printInventory(string party) {
        cout << "+-------------+" << endl;
    cout << "| INVENTORY   |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Gold        | " << party.gold << endl;
    cout << "| Ingredients | " << party.ingedients << " kg" << endl;
    cout << "| Cookware    | P: " << party.cookware[0] << " | F: " << party.cookware[1] << " | C: " << party.cookware[2] << endl;
    cout << "| Weapons     | C: " << party.weapons[0] << " | S: " << party.weapons[1] << " | R: " << party.weapons[2] << " B:  "<< party.weapons[3] << " | L: " << party.weapons[4] << endl;
    cout << "| Armor       | " << party.armor << endl;
    cout << "| Treasures   | R: " << party.treasures[0] << " | N: " << party.treasures[1] << " | B: " << party.treasures[2] << " C:  "<< party.treasures[3] << " | G: " << party.treasures[4] << endl;
    cout << "+-------------+" << endl;
}

void Party::printStatus(string party, string game) {
    cout << "+-------------+" << endl;
    cout << "| STATUS      |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Rooms Cleared: " << game.roomsClear << " | Keys: " << game.keys << " | Anger Level: " << game.anger << endl;
    party.printInventory(party);
    cout << "| PARTY.      |" << endl;
    cout << "+-------------+" << endl;
    cout << "| " << party.members[0].name << " | Fullness: " << party.members[0].fullness << endl;
    cout << "| " << party.members[1].name << " | Fullness: " << party.members[1].fullness << endl;
    cout << "| " << party.members[2].name << " | Fullness: " << party.members[2].fullness << endl;
    cout << "| " << party.members[3].name << " | Fullness: " << party.members[3].fullness << endl;
    cout << "| " << party.members[4].name << " | Fullness: " << party.members[4].fullness << endl;
    cout << "+-------------+" << endl;


}

