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
#include "Map.h"
using namespace std;


void merchantMenu(Party &partyName) {
    bool exit = false;
    int start;

    cout << "If you're looking to get supplies, you've come to the right place." << endl;
    cout << "I would be happy to part with some of my wares...for the proper price!" << endl;

    //partyName.gold = 100;

    while(exit == false) {

        partyName.printInventory();

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
                } else if(buyFood > partyName.gold) {
                    cout << "Insufficent funds" << endl;//checks you have enough gold
                } else {
                    cout << "Confirm you want to buy " << buyFood << " Gold worth of food?(y/n)" << endl;
                    cin >> checkFood;
                    if(checkFood == 'n') {
                        break;
                    } else if(checkFood == 'y') {
                        partyName.gold -= buyFood;
                        partyName.ingredients += buyFood;//math for purchase
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
                    if (numCookware > 0 && numCookware * 2 <= partyName.gold) {//if they have enough gold
                        cout << "You want to buy " << numCookware << " Ceramic Pot(s) for " << 2*numCookware << " gold?(y/n)" << endl;
                        cin >> checkCookware;
                        if(checkCookware == 'n') {
                            break;
                        } else if(checkCookware == 'y') {
                            partyName.gold -= numCookware * 2;
                            partyName.cookware[0] += numCookware;//math for cookware
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numCookware > 0 && numCookware * 2 > partyName.gold){
                        cout << "Insufficient funds." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                } else if (buyCookware == 2) {
                    cout << "How many would you like" << endl;
                    cin >> numCookware;
                    if (numCookware > 0 && numCookware * 10 <= partyName.gold) {//if they have enough gold
                        cout << "You want to buy " << numCookware << " Frying Pan(s) for " << 10*numCookware << " gold?(y/n)" << endl;
                        cin >> checkCookware;
                        if(checkCookware == 'n') {
                            break;
                        } else if(checkCookware == 'y') {
                            partyName.gold -= numCookware * 10;
                            partyName.cookware[1] += numCookware;//math for cookware
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numCookware > 0 && numCookware * 10 > partyName.gold){
                        cout << "Insufficient funds." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                } else if (buyCookware == 3) {
                    cout << "How many would you like" << endl;
                    cin >> numCookware;
                    if (numCookware > 0 && numCookware * 10 <= partyName.gold) {//if they have enough gold
                        cout << "You want to buy " << numCookware << " cauldron(s) for " << 20*numCookware << " gold?(y/n)" << endl;
                        cin >> checkCookware;
                        if(checkCookware == 'n') {
                            break;
                        } else if(checkCookware == 'y') {
                            partyName.gold -= numCookware * 20;
                            partyName.cookware[2] += numCookware;//math for cookware
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numCookware > 0 && numCookware * 20 > partyName.gold){
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
                    if (numWeapons > 0 && numWeapons * 2 <= partyName.gold) {//if they have enough gold
                        cout << "You want to buy " << numWeapons << " Stone Club(s) for " << 2*numWeapons << " gold?(y/n)" << endl;
                        cin >> checkWeapons;
                        if(checkWeapons == 'n') {
                            break;
                        } else if(checkWeapons == 'y') {
                            partyName.gold -= numWeapons * 2;
                            partyName.weapons[0] += numWeapons;//math for weapons
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numWeapons > 0 && numWeapons * 2 > partyName.gold){
                        cout << "Insufficient funds." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                } else if (buyWeapons == 2) {
                    cout << "How many would you like" << endl;
                    cin >> numWeapons;
                    if (numWeapons > 0 && numWeapons * 2 <= partyName.gold) {//if they have enough gold
                        cout << "You want to buy " << numWeapons << " Iron Spear(s) for " << 2*numWeapons << " gold?(y/n)" << endl;
                        cin >> checkWeapons;
                        if(checkWeapons == 'n') {
                            break;
                        } else if(checkWeapons == 'y') {
                            partyName.gold -= numWeapons * 2;
                            partyName.weapons[1] += numWeapons;//math for weapons
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numWeapons > 0 && numWeapons * 2 > partyName.gold){
                        cout << "Insufficient funds." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                } else if (buyWeapons == 3) {
                    cout << "How many would you like" << endl;
                    cin >> numWeapons;
                    if (numWeapons > 0 && numWeapons * 5 <= partyName.gold) {//if they have enough gold
                        cout << "You want to buy " << numWeapons << " (+1) Mythril Rapier for " << 5*numWeapons << " gold?(y/n)" << endl;
                        cin >> checkWeapons;
                        if(checkWeapons == 'n') {
                            break;
                        } else if(checkWeapons == 'y') {
                            partyName.gold -= numWeapons * 5;
                            partyName.weapons[2] += numWeapons;//math for weapons
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numWeapons > 0 && numWeapons * 5 > partyName.gold){
                        cout << "Insufficient funds." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                }else if(buyWeapons == 4) {
                    cout << "How many would you like" << endl;
                    cin >> numWeapons;
                    if (numWeapons > 0 && numWeapons * 15 <= partyName.gold) {//if they have enough gold
                        cout << "You want to buy " << numWeapons << " (+2) Flaming Battle-Axe for " << 15*numWeapons << " gold?(y/n)" << endl;
                        cin >> checkWeapons;
                        if(checkWeapons == 'n') {
                            break;
                        } else if(checkWeapons == 'y') {
                            partyName.gold -= numWeapons * 15;
                            partyName.weapons[3] += numWeapons;//math for weapons
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numWeapons > 0 && numWeapons * 15 > partyName.gold){
                        cout << "Insufficient funds." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                } else if(buyWeapons == 5) {
                    cout << "How many would you like" << endl;
                    cin >> numWeapons;
                    if (numWeapons > 0 && numWeapons * 50 <= partyName.gold) {//if they have enough gold
                        cout << "You want to buy " << numWeapons << " (+3) Vorpal Longsword for " << 50*numWeapons << " gold?(y/n)" << endl;
                        cin >> checkWeapons;
                        if(checkWeapons == 'n') {
                            break;
                        } else if(checkWeapons == 'y') {
                            partyName.gold -= numWeapons * 50;
                            partyName.weapons[4] += numWeapons;//math for weapons
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numWeapons > 0 && numWeapons * 50 > partyName.gold){
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
                } else if(buyArmor * 5 > partyName.gold) {
                    cout << "Insufficent funds" << endl;//checks you have enough gold
                } else {
                    cout << "Confirm you want to buy " << buyArmor << " suits of armor worth " << buyArmor * 5 << "Gold?(y/n)" << endl;
                    cin >> checkArmor;
                    if(checkArmor == 'n') {
                        break;
                    } else if(checkArmor == 'y') {
                        partyName.gold -= buyArmor * 5;
                        partyName.armor += buyArmor;//math for purchase
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
                    if (numTreasure > 0 && numTreasure <= partyName.treasures[0]) {//if they have enough gold
                        cout << "You want to sell " << numTreasure << " Silver ring(s) for " << 10*numTreasure << " gold?(y/n)" << endl;
                        cin >> checkTreasure;
                        if(checkTreasure == 'n') {
                            break;
                        } else if(checkTreasure == 'y') {
                            partyName.gold += numTreasure * 10;
                            partyName.treasures[0] -= numTreasure;//math for weapons
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numTreasure > 0 && numTreasure > partyName.treasures[0]){
                        cout << "You dont have enough Silver rings." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                } else if (sellTreasure == 2) {
                    cout << "How many would you like to sell" << endl;
                    cin >> numTreasure;
                    if (numTreasure > 0 && numTreasure <= partyName.treasures[1]) {//if they have enough gold
                        cout << "You want to sell " << numTreasure << " Ruby necklace(s) for " << 20*numTreasure << " gold?(y/n)" << endl;
                        cin >> checkTreasure;
                        if(checkTreasure == 'n') {
                            break;
                        } else if(checkTreasure == 'y') {
                            partyName.gold += numTreasure * 20;
                            partyName.treasures[1] -= numTreasure;//math for weapons
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numTreasure > 0 && numTreasure > partyName.treasures[1]){
                        cout << "You dont have enough Ruby necklaces." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                } else if (sellTreasure == 3) {
                    cout << "How many would you like to sell" << endl;
                    cin >> numTreasure;
                    if (numTreasure > 0 && numTreasure <= partyName.treasures[2]) {//if they have enough gold
                        cout << "You want to sell " << numTreasure << " Emerald brackelet(s) for " << 30*numTreasure << " gold?(y/n)" << endl;
                        cin >> checkTreasure;
                        if(checkTreasure == 'n') {
                            break;
                        } else if(checkTreasure == 'y') {
                            partyName.gold += numTreasure * 30;
                            partyName.treasures[2] -= numTreasure;//math for weapons
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numTreasure > 0 && numTreasure > partyName.treasures[2]){
                        cout << "You dont have enough Emerald bracelets." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                }else if(sellTreasure == 4) {
                    cout << "How many would you like to sell" << endl;
                    cin >> numTreasure;
                    if (numTreasure > 0 && numTreasure <= partyName.treasures[3]) {//if they have enough gold
                        cout << "You want to sell " << numTreasure << " Diamond circlets for " << 40*numTreasure << " gold?(y/n)" << endl;
                        cin >> checkTreasure;
                        if(checkTreasure == 'n') {
                            break;
                        } else if(checkTreasure == 'y') {
                            partyName.gold += numTreasure * 40;
                            partyName.treasures[3] -= numTreasure;//math for weapons
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numTreasure > 0 && numTreasure > partyName.treasures[3]){
                        cout << "You dont have enough Diamond circlets." << endl;//prints they don't have enough gold
                    } else {
                        cout << "Invalid input" << endl;
                    }
                } else if(sellTreasure == 5) {
                    cout << "How many would you like to sell" << endl;
                    cin >> numTreasure;
                    if (numTreasure > 0 && numTreasure <= partyName.treasures[4]) {//if they have enough gold
                        cout << "You want to sell " << numTreasure << " Ruby necklace(s) for " << 50*numTreasure << " gold?(y/n)" << endl;
                        cin >> checkTreasure;
                        if(checkTreasure == 'n') {
                            break;
                        } else if(checkTreasure == 'y') {
                            partyName.gold += numTreasure * 50;
                            partyName.treasures[4] -= numTreasure;//math for weapons
                            cout << "Thanks for your purchase." << endl;
                        } else {
                            cout << "Invalid input." << endl;
                        }
                    } else if (numTreasure > 0 && numTreasure > partyName.treasures[4]){
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

void actionMenu(Game game, Party party) {
    
}

int main() {
    // Create Class Objects 
    Game testGame = Game();
    Party testParty = Party(testGame);
    baseAction testAction = baseAction();

    merchantMenu(testParty);


    //Create Seed For Random Numbers
    srand(time(NULL));  // SEEDS WITH RANDOM TIME


    //Initialize New Game Map & Set Player and Exit Positions
    Map gameMap;
    Map();


    // SET NPC LOCATIONS
    int counter1 = 0;
    while (counter1 < 5) 
    {
        // Random Numbers
        int random1 = rand() % 13;
        int random2 = rand() % 13;

        // Add Location If Available
        if (gameMap.isFreeSpace(random1, random2) == true)
        {
            gameMap.addNPC(random1, random2);
            counter1++;
        }
    }


    //Set Room Locations 
    int counter2 = 0;
    while (counter2 < 5) 
    {
        // Random Numbers
        int random1 = rand() % 13;
        int random2 = rand() % 13;

        // Add Location If Available
        if (gameMap.isFreeSpace(random1, random2) == true)
        {
            gameMap.addRoom(random1, random2);
            counter2++;
        }
    } 




]

    // MAIN GAME LOOP 
    while(testGame.lose == false && testGame.win == false) 
    {
        // Declare Variables (INTERNAL TO LOOP)
        int selection;
        char direction = 'x';
        bool selection_validity = true;


        // Display Party Status, Map, & Recieve Input
        testParty.printStatus();
        gameMap.displayMap();



        // CHECK CONDITIONS THAT COULD POTENTIALLY END GAME (PARTY DEAD, SORCERES ANGER, ECT...)
        // ALSO CHECK FOR PARTY MEMBER CONDITIONS 




        // TEST IF ON DIFFERENT SPACES TO DISPLAY DIFFERENT MENUS
        int row = gameMap.getPlayerRow(); 
        int col = gameMap.getPlayerCol();
        bool explored = gameMap.isExplored(row, col);
        bool NPCLocation = gameMap.isNPCLocation(row, col);
        bool roomLocation = gameMap.isRoomLocation(row, col);
        bool freeSpace = gameMap.isFreeSpace(row, col);
        bool dungeonExit = gameMap.isDungeonExit(row, col);



        // Free Space Actions
        if (freeSpace == true)
        {
        cout << "Select one:" << endl;
        cout << "1. Move" << endl;
        cout << "2. Investigate" << endl;
        cout << "3. Pick a Fight" << endl;
        cout << "4. Cook and Eat" << endl;
        cout << "5. Give up" << endl;
        cin >> selection;


        if(selection == 1) // MOVEMENT
        {
            // Loop Until Valid Input Recieved 
            while(direction == 'x')
            {
                cout << "Where would you like to move?" << endl;
                cout << "w (up), a (left), s (down), or d (right)" << endl;
                cin >> direction;

                if(direction == 'w')
                {
                    gameMap.move('w') // Move Up
                    if (explored != true)
                    {
                        // INCREASE SORECERS ANGER ONLY IF ALIVE
                    }
                    break;
                }

                else if(direction == 'a')
                {
                    gameMap.move('a') // Move Left
                    if (explored != true)
                    {
                        // INCREASE SORECERS ANGER ONLY IF ALIVE
                    }
                    break;
                }

                else if(direction == 's')
                {
                    gameMap.move('s') // Move Down
                    if (explored != true) // Increase Anger
                    {
                        // INCREASE SORECERS ANGER ONLY IF ALIVE
                    }
                    break;
                }

                else if(direction == 'd')
                {
                    gameMap.move('d') // Move Right
                    if (explored != true)
                    {
                        // INCREASE SORECERS ANGER ONLY IF ALIVE
                    }
                    break; 
                }

                else // Loop through again if invalid input
                {
                    cout << "Invalid Input. Please Enter A Valid Character" << endl;
                    direction = 'x';
                }
            }
        }


        else if(selection == 2)  // INVESTIGATE
        {
            testAction.investigate(testGame, testParty);
        }


        else if(selection == 3)  // MOSTER FIGHT 
        {
            testAction.monsterFight(testGame, testParty);
        }


        else if(selection == 4) // COOK
        {
            testAction.cook(testGame, testParty);
        }


        else if(selection == 5) // GIVE UP
        {
            testAction.giveUp(testGame, testParty);
        }

        else
        {
            cout << "Invalid Input. Please Enter A Number 1-5" << endl;
            selection_validity = false;
        }




        // Continue If Selection Is Valid
        if (selection_validity == true)
        {
            // AFTER BASE ACTION CODE HERE

            
        }

        } // END OF FREE SPACE IF Statement

        



        // NPC Space Actions
        else if(NPCLocation = true )
        {
            cout << "Select one:" << endl;
            cout << "1. Move" << endl;
            cout << "2. Speak to NPC" << endl;
            cout << "3. Give Up" << endl;
            cin >> selection;
        }






        // Room Space Actions
        else if(roomLocation = true )
        {
            cout << "Select one:" << endl;
            cout << "1. Move" << endl;
            cout << "2. Open Door" << endl;
            cout << "3. Give Up" << endl;
            cin >> selection;
        }
 
    }
}