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
#include "BaseAction.h"
#include "score.h"
using namespace std;

int splitDriver(string input_string, char seperator, string arr[], int arr_size)
{
    // DECLARE VARIABLES 
    string str = "";
    int position = 0;
    int num_splits = 0;

    // LOOP THAT ADDS TO TEMPORARY STRING IF NO SEPERATOR DETECTED 
    for (int i = 0; i < input_string.length(); i++)
    {
        if (input_string[i] != seperator)
        {
            str = str + input_string[i];
        }

        // RESET AND ADD TO INDEX WHEN SEPERATOR DETECTED
        else
        {
            arr[position] = str;
            str = "";
            position++;
            num_splits++;
        }

    }

    arr[position] = str;

    // TEST FOR DIFFERENT OUTCOMES TO DETERMINE RETURN VALUE 
    if (arr_size < num_splits + 1)
    {
        num_splits = -1;
        return num_splits;
    }

    else if (input_string.length() == 0)
    {
        return 0;
    }

    else
    {
        return num_splits + 1;
    }

}

void sortScores(vector<Score> &scores) {
    Score temp = Score();
    for(int i = 0; i < scores.size(); i++) {
        for(int j = 0; j < scores.size() - 1; j++) {
            if(scores.at(j).turns > scores.at(j+1).turns) {
                temp = scores.at(j+1);
                scores.at(j+1) = scores.at(j);
                scores.at(j) = temp;
            }
        }
    }
    return;
}

void readScores(vector<Score> &scores) {
    fstream scoreFile("scores.txt");
    string line;
    string splitArr[10];
    int skipCount = 0;
    while(getline(scoreFile,line)) {
    //cout << "line: " << line << "skipcount: " << skipCount << endl;
        if(skipCount == 0) {
            int x = 5+5;
        } else if(skipCount % 2 == 0) {//CONNOR need to fix which line is read
            //cout << "if line: " << line << endl;
            splitDriver(line, ' ', splitArr, 10);
            // for(int i = 0; i < 10; i++) {
            //     cout << splitArr[i] << endl;
            // }
            Score tempScore = Score();
            tempScore.leaderName = splitArr[1];
            tempScore.turns = stoi(splitArr[3]);
            tempScore.gold = stoi(splitArr[5]);
            tempScore.treasures = stoi(splitArr[7]);
            tempScore.monstersDefeated = stoi(splitArr[9]);
            scores.push_back(tempScore);
            //cout << "Read Vect Size: " << scores.size() << endl;
        }
        skipCount++;
    }
    scoreFile.close();
}

void printScores(vector<Score> &scores) {
    fstream scoreFile;
    scoreFile.open("scores.txt", std::ofstream::out | std::ofstream::trunc);//deletes everything from the scores file
    scoreFile << "Leaderboard(High to Low):" << endl;
    for(int i = 0; i < scores.size(); i++) {
        scoreFile << "Number " << i + 1 << " -- " << endl;
        scoreFile << "Leader: " << scores.at(i).leaderName;
        scoreFile << " Turns: " << scores.at(i).turns;
        scoreFile << " Gold: " << scores.at(i).gold;
        scoreFile << " Treasures: " << scores.at(i).treasures;
        scoreFile << " MonstersDef: " << scores.at(i).monstersDefeated;
        //scoreFile << " Explored Spaces: " << scores.at(i).exploredSpaces;
        scoreFile << endl;
    }

    scoreFile.close();
}

int main() {
    int score = 0;//score count
    string groupName;
    vector <Score>scores = {};

    // Create Class Objects 
    Game testGame = Game();
    Party testParty = Party(testGame);
    baseAction testAction = baseAction(testGame, testParty);
    testParty.merchantMenu();
    Score gameScore = Score();


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




    // MAIN GAME LOOP 
    while(testGame.lose == false && testGame.win == false) 
    {
        score++;//each action they make increases the score
        
        // Declare Variables (INTERNAL TO LOOP)
        int selection;
        char direction = 'x';
        bool selection_validity = true;

        // Display Party Status & Map
        testParty.printStatus();
        gameMap.displayMap();




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
                    gameMap.move('w'); // Move Up
                    if (explored != true)
                    {
                        // INCREASE SORECERS ANGER ONLY IF ALIVE
                        testParty.anger++;

                    }
                    break;
                }

                else if(direction == 'a')
                {
                    gameMap.move('a'); // Move Left
                    if (explored != true)
                    {
                        // INCREASE SORECERS ANGER ONLY IF ALIVE
                        testParty.anger++;
                    }
                    break;
                }

                else if(direction == 's')
                {
                    gameMap.move('s'); // Move Down
                    if (explored != true) // Increase Anger
                    {
                        // INCREASE SORECERS ANGER ONLY IF ALIVE
                        testParty.anger++;
                    }
                    break;
                }

                else if(direction == 'd')
                {
                    gameMap.move('d'); // Move Right
                    if (explored != true)
                    {
                        // INCREASE SORECERS ANGER ONLY IF ALIVE
                        testParty.anger++;
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
            testAction.investigate(testParty);
        }


        else if(selection == 3)  // MOSTER FIGHT 
        {
            testAction.monsterFight(testParty);
        }


        else if(selection == 4) // COOK
        {
            testAction.cook(testParty);
        }


        else if(selection == 5) // GIVE UP
        {
            testAction.giveUp(testGame);
        }

        //cheat code to win
        else if(selection == 23) {
            testGame.setWin();
        }

        else
        {
            cout << "Invalid Input. Please Enter A Valid Number" << endl;
            selection_validity = false;
        }

        } // END OF FREE SPACE IF Statement

        



        // NPC Space Actions
        else if(NPCLocation == true )
        {
            //Receive Input
            cout << "Select one:" << endl;
            cout << "1. Move" << endl;
            cout << "2. Speak to NPC" << endl;
            cout << "3. Give Up" << endl;
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
                        gameMap.move('w'); // Move Up
                        if (explored != true)
                        {
                            // INCREASE SORECERS ANGER ONLY IF ALIVE
                        }
                        break;
                    }

                    else if(direction == 'a')
                    {
                        gameMap.move('a'); // Move Left
                        if (explored != true)
                        {
                            // INCREASE SORECERS ANGER ONLY IF ALIVE
                        }
                        break;
                    }

                    else if(direction == 's')
                    {
                        gameMap.move('s'); // Move Down
                        if (explored != true) // Increase Anger
                        {
                            // INCREASE SORECERS ANGER ONLY IF ALIVE
                        }
                        break;
                    }

                    else if(direction == 'd')
                    {
                        gameMap.move('d'); // Move Right
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


            
            else if(selection == 2) // NPC SPEAK
            {
                testAction.speak(testParty, gameMap);
            }


            else if(selection == 3) // Give Up
            {
                testAction.giveUp(testGame);
            }

            else
            {
                cout << "Invalid Input. Please Enter A Valid Number" << endl;
                selection_validity = false;
            }

        } // END OF NPC ACTION SELECTION





        // Room Space Actions
        if(roomLocation == true )
        {
            cout << "Select one:" << endl;
            cout << "1. Move" << endl;
            cout << "2. Open Door" << endl;
            cout << "3. Give Up" << endl;
            cin >> selection;


            if(selection == 1)  // Movement
            {
                // Loop Until Valid Input Recieved 
                while(direction == 'x')
                {
                    cout << "Where would you like to move?" << endl;
                    cout << "w (up), a (left), s (down), or d (right)" << endl;
                    cin >> direction;

                    if(direction == 'w')
                    {
                        gameMap.move('w'); // Move Up
                        if (explored != true)
                        {
                            // INCREASE SORECERS ANGER ONLY IF ALIVE
                        }
                        break;
                    }

                    else if(direction == 'a')
                    {
                        gameMap.move('a'); // Move Left
                        if (explored != true)
                        {
                            // INCREASE SORECERS ANGER ONLY IF ALIVE
                        }
                        break;
                    }

                    else if(direction == 's')
                    {
                        gameMap.move('s'); // Move Down
                        if (explored != true) // Increase Anger
                        {
                            // INCREASE SORECERS ANGER ONLY IF ALIVE
                        }
                        break;
                    }

                    else if(direction == 'd')
                    {
                        gameMap.move('d'); // Move Right
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


            
            else if(selection == 2) // Open Door
            {
                testAction.doorOpen(testParty, gameMap);
            }


            else if(selection == 3) // Give Up
            {
                testAction.giveUp(testGame);
            }


            else
            {
                cout << "Invalid Input. Please Enter A Valid Number" << endl;
                selection_validity = false;
            }


        } // End of Room Space Actions


        // EXIT SPACE ACTION
        if(dungeonExit == true )
        {
            if(testParty.roomsClear == 5) // IF ALL ROOMS CLEARED
            {
                int numTreasures = 0;
                for(int i = 0; i < 5; i++) {
                    if(testParty.treasures[i] > 0) {
                        numTreasures += testParty.treasures[i];//counts number of treasures
                    }
                }
                cout << "Congratulation! You Have Cleared All Rooms And Found The Exit. YOU WIN!" << endl;

                // SET WIN CONDITION 
                testGame.setWin();

                //Print Out Game Data
                cout << "Number of rooms cleared: " << testParty.roomsClear << endl;
                cout << "Gold pieces remaining: " << testParty.gold << endl;
                cout << "Treasure remaining: " << numTreasures << endl;
                cout << "Number of spaces explored: " << 0 << endl;//add spaces explored counter
                cout << "Number of monsters defeated: " << testParty.monstersDefeated << endl;
                cout << "Number of turns elapsed: " << score << endl;

            }


            else // IF ROOMS NOT CLEARED
            {
                cout << "Not All Rooms Have Been Cleared. Continue Exploring" << endl;

                // Loop Until Valid Input Recieved 
                while(direction == 'x')
                {
                    cout << "Where would you like to move?" << endl;
                    cout << "w (up), a (left), s (down), or d (right)" << endl;
                    cin >> direction;

                    if(direction == 'w')
                    {
                        gameMap.move('w'); // Move Up
                        if (explored != true)
                        {
                            // INCREASE SORECERS ANGER ONLY IF ALIVE
                        }
                        break;
                    }

                    else if(direction == 'a')
                    {
                        gameMap.move('a'); // Move Left
                        if (explored != true)
                        {
                            // INCREASE SORECERS ANGER ONLY IF ALIVE
                        }
                        break;
                    }

                    else if(direction == 's')
                    {
                        gameMap.move('s'); // Move Down
                        if (explored != true) // Increase Anger
                        {
                            // INCREASE SORECERS ANGER ONLY IF ALIVE
                        }
                        break;
                    }

                    else if(direction == 'd')
                    {
                        gameMap.move('d'); // Move Right
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
        }

        // MISFORTUNES
        if(selection != 1)
        {
            //Generate Random Number 1-10
            int rand_num = (rand() % 10) + 1;

            if(rand_num == 1 || rand_num == 2 || rand_num == 3 || rand_num == 4) // 40% Chance Misfortune Happens 
            {
                //Generate New Random Number 1-10
                int rand_num2 = (rand() % 10) + 1;


                if(rand_num2 == 1 || rand_num2 == 2 || rand_num2 == 3)  // ROBBERY
                {
                    cout << "OH NO! Your team was robbed by dungeon bandits!" << endl;

                    // Randomly Choose Party Item To Lose
                    if(rand_num2 == 1)  // LOSE 10kg Ingredients 
                    {
                        // LOSE 10kg INGREDIENTS
                        cout << "You lose 10kg ingredients" << endl;
                        if(testParty.ingredients - 10 < 0) {
                            testParty.ingredients = 0;
                        } else {
                            testParty.ingredients -= 10;
                        }
                    }

                    else if(rand_num2 == 2) // LOSE ARMOR
                    {
                        // LOSE ARMOR
                        cout << "Bandits make off with your armor!" << endl;
                        if(testParty.armor > 0) {
                            testParty.armor--;
                        }
                    }

                    else  // LOSE COOKWARE
                    {
                        // LOSE COOKWARE
                        int numCookware = 0;
                    for (int i = 0; i < 3; i++) {
                        if(testParty.cookware[i] > 0) {
                            numCookware += testParty.cookware[i];
                        }
                    }
                    if(numCookware > 0) {
                        bool exit = false;
                        while(exit == false) {
                            int randNum = rand() % 3;
                            switch(randNum) {
                                case 0: 
                                    if(testParty.cookware[0] > 0) {
                                        testParty.cookware[0]--;
                                        cout << "Bandits made off with your Ceramic Pot!" << endl;
                                        exit = true;
                                    }
                                break;
                                case 1: 
                                    if(testParty.cookware[1] > 0) {
                                        testParty.cookware[1]--;
                                        cout << "Bandits made off with your Frying Pan!" << endl;
                                        exit = true;
                                    }
                                break;
                                case 2: 
                                    if(testParty.cookware[2] > 0) {
                                        testParty.cookware[2]--;
                                        cout << "Bandits made off with your Cauldron!" << endl;
                                        exit = true;
                                    }
                                break;
                            }
                        }
                    }
                    }
                }


                else if(rand_num2 == 4 || rand_num2 == 5 || rand_num2 == 6)  // FOOD POISONING
                {
                    cout << "Due to food poisoning, 1 party member has passed away" << endl;
                    // PARTY MEMBER DECREASE BY 1
                    bool exit = false;
                    while(exit == false) {
                        int randNum = rand() % 5;
                        if(testParty.members[randNum].checkAlive() == false) {//checks that random party member is already alive
                            int x = 1 + 1;
                        } else {
                            testParty.members[randNum].fullness = 0;//kills party member
                            cout << testParty.members[randNum].name << " was left behind."<< endl;
                            testParty.checkPartyLive();
                            testParty.members[randNum].checkAlive();
                            exit = true;
                        }

        }
                }


                else if(rand_num2 == 7 || rand_num2 == 8 || rand_num2 == 9)  // LOCKED IN ROOM
                {
                    if(roomLocation == true && selection == 2) // Only Can Happen If Locked Room 
                    {

                    }
                }

                else if(rand_num2 == 10)  // WEAPON BREAK
                {
                    //WEAPON BREAK (ARE THEY STORED IN ARRAY?)
                    int numWeapons = 0;
                    for (int i = 0; i < 5; i++) {
                        if(testParty.weapons[i] > 0) {
                            numWeapons += testParty.weapons[i];
                        }
                    }
                    if(numWeapons > 0) {
                        bool exit = false;
                        while(exit == false) {
                            int randNum = rand() % 5;
                            switch(randNum) {
                                case 0: 
                                    if(testParty.weapons[0] > 0) {
                                        testParty.weapons[0]--;
                                        cout << "Bandits made off with your Stone Club!" << endl;
                                        exit = true;
                                    }
                                break;
                                case 1: 
                                    if(testParty.weapons[1] > 0) {
                                        testParty.weapons[1]--;
                                        cout << "Bandits made off with your Spear!" << endl;
                                        exit = true;
                                    }
                                break;
                                case 2: 
                                    if(testParty.weapons[2] > 0) {
                                        testParty.weapons[2]--;
                                        cout << "Bandits made off with your Rapier!" << endl;
                                        exit = true;
                                    }
                                break;
                                case 3: 
                                    if(testParty.weapons[3] > 0) {
                                        testParty.weapons[3]--;
                                        cout << "Bandits made off with your Battle-Axe!" << endl;
                                        exit = true;
                                    }
                                break;
                                case 4: 
                                    if(testParty.weapons[4] > 0) {
                                        testParty.weapons[4]--;
                                        cout << "Bandits made off with your Long-sword!" << endl;
                                        exit = true;
                                    }
                                break;
                            }
                        }
                    }
                }
            }
        }
        
        
        
        // CHECK CONDITIONS THAT COULD POTENTIALLY END GAME (PARTY DEAD, SORCERES ANGER, ECT...)
        // ALSO CHECK FOR PARTY MEMBER CONDITIONS

        //Check if party members alive and updates names/game status
        for(int i =0; i < 5; i++) {
            testParty.members[i].checkAlive();//runs check name on every party member
        }
        if(testParty.checkPartyLive() == false) {//checks that at least one party member is alive
            testGame.setLose();
        }

        testGame.checkLose();//check win/lose conditions
        testGame.checkWin();
    }

    if(testGame.win == true) {
        //saves score and pushes to scoreboard
        gameScore.leaderName = testParty.members[0].name;
        gameScore.turns = score;
        gameScore.gold = testParty.gold;

        //count treasures
        int numTreasures = 0;
        for(int i = 0; i < 5; i++) {
            if(testParty.treasures[i] > 0) {
                numTreasures += testParty.treasures[i];//counts number of treasures
            }
        }
        gameScore.treasures = numTreasures;
        gameScore.monstersDefeated = testParty.monstersDefeated;

        scores.push_back(gameScore);

        readScores(scores);
        sortScores(scores);

        //cout << "Vect Size: " << scores.size() << endl;

        printScores(scores);
    }

}