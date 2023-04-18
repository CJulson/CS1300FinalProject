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

Party::Party(Game &game_) {
    string temp;
    cout << "Welcome to Dungeon Escape!" << endl;
    cout << "Please input the names of your party." << endl;
    for (int i = 1; i < 6; i++) {
        cout << "Member " << i << ":" << endl;
        cin >> temp;
        members[i-1] = Character(temp);
        cout << "Hi, " << temp << " welcome to dungeon esacpe!" << endl;
    }
    gold = 100;
    ingredients=0;
    for(int i = 0; i < 3; i++) {
        cookware[i] = 0;
    }
    for(int i = 0; i < 5; i++) {
        weapons[i] = 0;
    }
    for(int i = 0; i < 5; i++) {
        treasures[i] = 0;
    }
    armor=0;
    keys = 0;
    roomsClear = 0;
    anger = 0;
    game = game_;
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
    cout << "| Weapons     | C: " << weapons[0] << " | S: " << weapons[1] << " | R: " << weapons[2] << " | B:  "<< weapons[3] << " | L: " << weapons[4] << endl;
    cout << "| Armor       | " << armor << endl;
    cout << "| Treasures   | R: " << treasures[0] << " | N: " << treasures[1] << " | B: " << treasures[2] << " | C:  "<< treasures[3] << " | G: " << treasures[4] << endl;
    cout << "+-------------+" << endl;
}

void Party::printStatus() {
    cout << "+-------------+" << endl;
    cout << "| STATUS      |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Rooms Cleared: " << roomsClear << " | Keys: " << keys << " | Anger Level: " << anger << endl;
    cout << "+-------------+" << endl;
    cout << "| INVENTORY   |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Gold        | " << gold << endl;
    cout << "| Ingredients | " << ingredients << " kg" << endl;
    cout << "| Cookware    | P: " << cookware[0] << " | F: " << cookware[1] << " | C: " << cookware[2] << endl;
    cout << "| Weapons     | C: " << weapons[0] << " | S: " << weapons[1] << " | R: " << weapons[2] << " | B:  "<< weapons[3] << " | L: " << weapons[4] << endl;
    cout << "| Armor       | " << armor << endl;
    cout << "| Treasures   | R: " << treasures[0] << " | N: " << treasures[1] << " | B: " << treasures[2] << " | C:  "<< treasures[3] << " | G: " << treasures[4] << endl;
    cout << "+-------------+" << endl;
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

void Party::merchantMenu() {

    bool exit = false;
    int start;

    cout << "If you're looking to get supplies, you've come to the right place." << endl;
    cout << "I would be happy to part with some of my wares...for the proper price!" << endl;

    //partyName.gold = 100;

    while(exit == false) {

        printInventory();

        cout << "Choose one of the following: " << endl;
        cout << "1. Ingredients: To make food, you have to cook raw ingredients." << endl;
        cout << "2. Cookware: You will need something to cook those ingredients." << endl;
        cout << "3. Weapons: It's dangerous to go alone, take this!" << endl;
        cout << "4. Armor: If you want to survive monster attacks, you will need some armor." << endl;
        cout << "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl;
        cout << "6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl;

        cin >> start;

        switch(start) {
            case 1: {
                int buyFood;
                cout << "How many kg of food would you like to buy(1 Gold/kg)" << endl;

                char checkFood;

                cin >> buyFood;

                if(buyFood < 1) {
                    cout << "Invalid input" << endl;//input validation
                } else if(buyFood > gold) {
                    cout << "Insufficent funds" << endl;//checks you have enough gold
                } else {
                    cout << "Confirm you want to buy " << buyFood << " Gold worth of food?(y/n)" << endl;
                    cin >> checkFood;
                    if(checkFood == 'n') {
                        break;
                    } else if(checkFood == 'y') {
                        gold -= buyFood;
                        ingredients += buyFood;//math for purchase
                        cout << "Thanks for your purchase" << endl;
                    } else {
                        cout << "Invalid input." << endl;
                    }
                }

                
            }
            break;

            case 2: {
                int buyCookware;
                int numCookware;
                char checkCookware;
                cout << "We offer several types of cookware, which would you like?" << endl;
                cout << "Each type has a different probability of breaking when used, marked with (XX%)." << endl;
                cout << endl;
                cout << "Choose one of the following:" << endl;
                cout << " 1. (25%) Ceramic Pot [2 Gold]" << endl;
                cout << " 2. (10%) Frying Pan [10 Gold]" << endl;
                cout << " 3. ( 2%) Cauldron [20 Gold]" << endl;
                cout << " 4. Cancel" << endl;
                cin >> buyCookware;

                if(buyCookware > 4 || buyCookware < 1) {
                    cout << "Invalid input." << endl;
                } else if(buyCookware == 1) {
                    cout << "How many would you like" << endl;
                    cin >> numCookware;
                    if (numCookware > 0 && numCookware * 2 <= gold) {//if they have enough gold
                        cout << "You want to buy " << numCookware << " Ceramic Pot(s) for " << 2*numCookware << " gold?(y/n)" << endl;
                        cin >> checkCookware;
                        if(checkCookware == 'n') {
                            break;
                        } else if(checkCookware == 'y') {
                            gold -= numCookware * 2;
                            cookware[0] += numCookware;//math for cookware
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numCookware > 0 && numCookware * 2 > gold){
                        cout << "Insufficient funds." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                } else if (buyCookware == 2) {
                    cout << "How many would you like" << endl;
                    cin >> numCookware;
                    if (numCookware > 0 && numCookware * 10 <= gold) {//if they have enough gold
                        cout << "You want to buy " << numCookware << " Frying Pan(s) for " << 10*numCookware << " gold?(y/n)" << endl;
                        cin >> checkCookware;
                        if(checkCookware == 'n') {
                            break;
                        } else if(checkCookware == 'y') {
                            gold -= numCookware * 10;
                            cookware[1] += numCookware;//math for cookware
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numCookware > 0 && numCookware * 10 > gold){
                        cout << "Insufficient funds." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                } else if (buyCookware == 3) {
                    cout << "How many would you like" << endl;
                    cin >> numCookware;
                    if (numCookware > 0 && numCookware * 10 <= gold) {//if they have enough gold
                        cout << "You want to buy " << numCookware << " cauldron(s) for " << 20*numCookware << " gold?(y/n)" << endl;
                        cin >> checkCookware;
                        if(checkCookware == 'n') {
                            break;
                        } else if(checkCookware == 'y') {
                            gold -= numCookware * 20;
                            cookware[2] += numCookware;//math for cookware
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numCookware > 0 && numCookware * 20 > gold){
                        cout << "Insufficient funds." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                } else {
                    break;
                }


            }
            break;

            case 3: {
                int buyWeapons;
                int numWeapons;
                char checkWeapons;
                cout << "I have a plentiful collection of weapons to choose from, what would you like?" << endl;
                cout << "Note that some of them provide you a special bonus in combat, marked by a (+X)." << endl;
                cout << endl;
                cout << "Choose one of the following:" << endl;
                cout << " 1. Stone Club [2 Gold]" << endl;
                cout << " 2. Iron Spear [2 Gold]" << endl;
                cout << " 3. (+1) Mythril Rapier [5 Gold]" << endl;
                cout << " 4. (+2) Flaming Battle-Axe [15 Gold]" << endl;
                cout << " 5. (+3) Vorpal Longsword [50 Gold]" << endl;
                cout << " 6. Cancel" << endl;

                cin >> buyWeapons;

                if(buyWeapons > 6 || buyWeapons < 1) {
                    cout << "Invalid input." << endl;
                } else if(buyWeapons == 1) {
                    cout << "How many would you like" << endl;
                    cin >> numWeapons;
                    if (numWeapons > 0 && numWeapons * 2 <= gold) {//if they have enough gold
                        cout << "You want to buy " << numWeapons << " Stone Club(s) for " << 2*numWeapons << " gold?(y/n)" << endl;
                        cin >> checkWeapons;
                        if(checkWeapons == 'n') {
                            break;
                        } else if(checkWeapons == 'y') {
                            gold -= numWeapons * 2;
                            weapons[0] += numWeapons;//math for weapons
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numWeapons > 0 && numWeapons * 2 > gold){
                        cout << "Insufficient funds." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                } else if (buyWeapons == 2) {
                    cout << "How many would you like" << endl;
                    cin >> numWeapons;
                    if (numWeapons > 0 && numWeapons * 2 <= gold) {//if they have enough gold
                        cout << "You want to buy " << numWeapons << " Iron Spear(s) for " << 2*numWeapons << " gold?(y/n)" << endl;
                        cin >> checkWeapons;
                        if(checkWeapons == 'n') {
                            break;
                        } else if(checkWeapons == 'y') {
                            gold -= numWeapons * 2;
                            weapons[1] += numWeapons;//math for weapons
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numWeapons > 0 && numWeapons * 2 > gold){
                        cout << "Insufficient funds." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                } else if (buyWeapons == 3) {
                    cout << "How many would you like" << endl;
                    cin >> numWeapons;
                    if (numWeapons > 0 && numWeapons * 5 <= gold) {//if they have enough gold
                        cout << "You want to buy " << numWeapons << " (+1) Mythril Rapier for " << 5*numWeapons << " gold?(y/n)" << endl;
                        cin >> checkWeapons;
                        if(checkWeapons == 'n') {
                            break;
                        } else if(checkWeapons == 'y') {
                            gold -= numWeapons * 5;
                            weapons[2] += numWeapons;//math for weapons
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numWeapons > 0 && numWeapons * 5 > gold){
                        cout << "Insufficient funds." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                }else if(buyWeapons == 4) {
                    cout << "How many would you like" << endl;
                    cin >> numWeapons;
                    if (numWeapons > 0 && numWeapons * 15 <= gold) {//if they have enough gold
                        cout << "You want to buy " << numWeapons << " (+2) Flaming Battle-Axe for " << 15*numWeapons << " gold?(y/n)" << endl;
                        cin >> checkWeapons;
                        if(checkWeapons == 'n') {
                            break;
                        } else if(checkWeapons == 'y') {
                            gold -= numWeapons * 15;
                            weapons[3] += numWeapons;//math for weapons
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numWeapons > 0 && numWeapons * 15 > gold){
                        cout << "Insufficient funds." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                } else if(buyWeapons == 5) {
                    cout << "How many would you like" << endl;
                    cin >> numWeapons;
                    if (numWeapons > 0 && numWeapons * 50 <= gold) {//if they have enough gold
                        cout << "You want to buy " << numWeapons << " (+3) Vorpal Longsword for " << 50*numWeapons << " gold?(y/n)" << endl;
                        cin >> checkWeapons;
                        if(checkWeapons == 'n') {
                            break;
                        } else if(checkWeapons == 'y') {
                            gold -= numWeapons * 50;
                            weapons[4] += numWeapons;//math for weapons
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numWeapons > 0 && numWeapons * 50 > gold){
                        cout << "Insufficient funds." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                } else {
                    break;
                }
            }
            break;

            case 4: {

                int buyArmor;
                cout << "How many suits of armor would you like to buy(5 Gold/suit)" << endl;

                char checkArmor;

                cin >> buyArmor;

                if(buyArmor < 1) {
                    cout << "Invalid input" << endl;//input validation
                } else if(buyArmor * 5 > gold) {
                    cout << "Insufficent funds" << endl;//checks you have enough gold
                } else {
                    cout << "Confirm you want to buy " << buyArmor << " suits of armor worth " << buyArmor * 5 << "Gold?(y/n)" << endl;
                    cin >> checkArmor;
                    if(checkArmor == 'n') {
                        break;
                    } else if(checkArmor == 'y') {
                        gold -= buyArmor * 5;
                        armor += buyArmor;//math for purchase
                        cout << "Thanks for your purchase" << endl;
                    } else {
                        cout << "Invalid input." << endl;
                    }
                }

            }
            break;

            case 5: {
                int sellTreasure;
                int numTreasure;
                char checkTreasure;
                cout << "There are several treasures I can buy off of you." << endl;
                cout << "Each of them sells for a different amount." << endl;
                cout << endl;
                cout << "Choose one of the following:" << endl;
                cout << " 1. Silver Ring [10 Gold]" << endl;
                cout << " 2. Ruby necklace [20 Gold]" << endl;
                cout << " 3. Emerald bracelet [30 Gold]" << endl;
                cout << " 4. Diamond circlet [40 Gold]" << endl;
                cout << " 5. Gem-encrusted goblet [50 Gold]" << endl;
                cout << " 6. Cancel" << endl;

                cin >> sellTreasure;

                if(sellTreasure > 6 || sellTreasure < 1) {
                    cout << "Invalid input." << endl;
                } else if(sellTreasure == 1) {
                    cout << "How many would you like to sell" << endl;
                    cin >> numTreasure;
                    if (numTreasure > 0 && numTreasure <= treasures[0]) {//if they have enough gold
                        cout << "You want to sell " << numTreasure << " Silver ring(s) for " << 10*numTreasure << " gold?(y/n)" << endl;
                        cin >> checkTreasure;
                        if(checkTreasure == 'n') {
                            break;
                        } else if(checkTreasure == 'y') {
                            gold += numTreasure * 10;
                            treasures[0] -= numTreasure;//math for weapons
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numTreasure > 0 && numTreasure > treasures[0]){
                        cout << "You dont have enough Silver rings." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                } else if (sellTreasure == 2) {
                    cout << "How many would you like to sell" << endl;
                    cin >> numTreasure;
                    if (numTreasure > 0 && numTreasure <= treasures[1]) {//if they have enough gold
                        cout << "You want to sell " << numTreasure << " Ruby necklace(s) for " << 20*numTreasure << " gold?(y/n)" << endl;
                        cin >> checkTreasure;
                        if(checkTreasure == 'n') {
                            break;
                        } else if(checkTreasure == 'y') {
                            gold += numTreasure * 20;
                            treasures[1] -= numTreasure;//math for weapons
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numTreasure > 0 && numTreasure > treasures[1]){
                        cout << "You dont have enough Ruby necklaces." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                } else if (sellTreasure == 3) {
                    cout << "How many would you like to sell" << endl;
                    cin >> numTreasure;
                    if (numTreasure > 0 && numTreasure <= treasures[2]) {//if they have enough gold
                        cout << "You want to sell " << numTreasure << " Emerald brackelet(s) for " << 30*numTreasure << " gold?(y/n)" << endl;
                        cin >> checkTreasure;
                        if(checkTreasure == 'n') {
                            break;
                        } else if(checkTreasure == 'y') {
                            gold += numTreasure * 30;
                            treasures[2] -= numTreasure;//math for weapons
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numTreasure > 0 && numTreasure > treasures[2]){
                        cout << "You dont have enough Emerald bracelets." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                }else if(sellTreasure == 4) {
                    cout << "How many would you like to sell" << endl;
                    cin >> numTreasure;
                    if (numTreasure > 0 && numTreasure <= treasures[3]) {//if they have enough gold
                        cout << "You want to sell " << numTreasure << " Diamond circlets for " << 40*numTreasure << " gold?(y/n)" << endl;
                        cin >> checkTreasure;
                        if(checkTreasure == 'n') {
                            break;
                        } else if(checkTreasure == 'y') {
                            gold += numTreasure * 40;
                            treasures[3] -= numTreasure;//math for weapons
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numTreasure > 0 && numTreasure > treasures[3]){
                        cout << "You dont have enough Diamond circlets." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                } else if(sellTreasure == 5) {
                    cout << "How many would you like to sell" << endl;
                    cin >> numTreasure;
                    if (numTreasure > 0 && numTreasure <= treasures[4]) {//if they have enough gold
                        cout << "You want to sell " << numTreasure << " Ruby necklace(s) for " << 50*numTreasure << " gold?(y/n)" << endl;
                        cin >> checkTreasure;
                        if(checkTreasure == 'n') {
                            break;
                        } else if(checkTreasure == 'y') {
                            gold += numTreasure * 50;
                            treasures[4] -= numTreasure;//math for weapons
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numTreasure > 0 && numTreasure > treasures[4]){
                        cout << "You dont have enough Gem-encrusted goblets." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                } else {
                    break;
                }

            }
            break;

            case 6:
                exit = true;
                break;

            default:
                cout << "Invalid input." << endl;

            break;
        }
    }

}

Party::Party() {
    gold = 100;
    ingredients=0;
    for(int i = 0; i < 3; i++) {
        cookware[i] = 0;
    }
    for(int i = 0; i < 5; i++) {
        weapons[i] = 0;
    }
    for(int i = 0; i < 5; i++) {
        treasures[i] = 0;
    }
    armor=0;
    keys = 0;
    roomsClear = 0;
    anger = 0;
}

