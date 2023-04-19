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
using namespace std;



int main() {
    // Create Class Objects 
    Game testGame = Game();
    Party testParty = Party(testGame);
    baseAction testAction = baseAction(testGame, testParty);
    testParty.merchantMenu();


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
                testAction.speak(testParty);
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
                testAction.doorOpen();
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
        
        
        
        
        
        // CHECK CONDITIONS THAT COULD POTENTIALLY END GAME (PARTY DEAD, SORCERES ANGER, ECT...)
        // ALSO CHECK FOR PARTY MEMBER CONDITIONS

        //Check if party members alive and updates names/game status
        int sum = 0;
        for(int i =0; i < 5; i++) {
            sum += testParty.members[i].checkAlive();
        }
        if(testParty.checkPartyLive() == false) {
            testGame.setLose();
        }

        testGame.checkLose();//check win/lose conditions
        testGame.checkWin();
    }
}