#include "BaseAction.h"
#include "game.h"
#include "party.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;



// INCLUDE SPLIT FUNCTION
int split(string input_string, char seperator, string arr[], int arr_size)
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

baseAction::baseAction() {
    int x = 5 + 5;
}



// INVESTIGATE UNEXPLORED SPACE
void baseAction::investigate(Game game, Party party)
{

    // Prepare Random Number Generation
    srand(time(NULL));  // SEEDS WITH RANDOM TIME
    int random = rand() % 11 + 1;   // GIVES RANDOM NUMBER (1-10)

    // 10% Chance To Add Key
    if(random == 1)
    {
        cout << "You have found a key!" << endl;
        party.keys++;
    }

    // 20% Chance To Find Treasure
    if (random == 2 || random == 3)
    {
        // ADD TREASURE (BASED ON ROOMS CLEARED?)
        int temp = rand() % 101 + 1 + party.roomsClear * 10;
        if(temp >= 90) {
            cout << "You have discovered a Gem-Encrusted Goblet!(Worth 50 gold)" << endl;
            party.treasures[4]++;
        } else if (temp >= 75) {
            cout << "You have discovered a Diamond Circlet!(Worth 40 gold)" << endl;
            party.treasures[3]++;
        } else if (temp >= 60) {
            cout << "You have discovered a Emerald Bracelet!(Worth 30 gold)" << endl;
            party.treasures[2]++;
        } else if(temp >= 30) {
            cout << "You have discovered a Ruby Necklace!(Worth 20 gold)" << endl;
            party.treasures[1]++;
        } else {
            cout << "You have discovered a Silver Ring!(Worth 10 gold)" << endl;
            party.treasures[0]++;
        }
    }

    if (random == 4 || random == 5)
    {
        monsterFight(); // Fight Random Monster
    }

    return;
}





// Monster Fight Function
void baseAction::monsterFight(Game game, Party party)
{
    // DECLARE VARIBALES
    ifstream file_input;
    string line;
    string monster; 
    string arr[2];   


    // Find Numbers of Monsters Left in File
    int counter = 0;
    file_input.open("monsters.txt");
    while(!file_input.eof())
    {
        getline(file_input, line);
        counter++;
    }
    file_input.close();


    // Prepare Random Number Generation
    srand(time(NULL));  // SEEDS WITH RANDOM TIME
    int random = rand() % counter + 1;   // GIVES RANDOM NUMBER (1 - total monsters left)


    // Select Random Monster From File and Send To "Monster"
    file_input.open("monsters.txt");
    for(int i = 1; i <= counter; i++)  
    {
        getline(file_input, monster);
        if (i == random);
        split(monster, ',', arr, 2);
    }
    file_input.close();


    // Fight Monster

    return;

}






// Cook & Eat Function 
void baseAction :: cook(Game game, Party party)
{
    cout << "You have selected to cook" << endl;
    if(party.ingredients == 0) {
        cout << "Sorry you don't have any ingredients." << endl;//checks if they have ingredients
        return;
    } else {
        bool haveCookware = false;
        for(int i = 0; i < 3; i++) {
            if (party.cookware[i] > 0) {
                haveCookware = true;
            }
        }
        if(haveCookware = false) {
            cout << "Sorry you have no cookware to cook with." << endl;//checks if they have cookware
            return;
        }
    }
    bool exit = false;
    int kilos;
    while(exit == false) {
        cout << "How many kg of food would you like to cook?(5kg = 1 fullness)" << endl;
        cin >> kilos;
        if(kilos > party.ingredients) {
            cout << "You don't have that much try again." << endl;
        } else {
            exit = true;
        }
    }
    exit = false;

    while(exit == false) {
        int item;
        cout << "What cooking item would you like to use?" << endl;
        cout << "Ceramic pot: " << party.cookware[0] << endl;
        cout << "Frying pan: " << party.cookware[1] << endl;
        cout << "Cauldron: " << party.cookware[2] << endl;
        cin >> item;
        switch(item) {
            case 1:
                if(party.cookware[0] < 1) {
                    cout << "Sorry you don't have a Ceramic pot to cook with." << endl;
                    break;
                } else {
                    cout << "You are cooking " << kilos << " kg of food with a Ceramic pot..." << endl;
                    party.ingredients -= kilos;
                    int random = rand() % 5 + 1;//random chance to break
                    if(random == 1) {
                        cout << "Your cook failed, you lose the pot and the ingredients" << endl;
                        party.cookware[0]--;
                    } else {
                        cout << "Your cook succeeded! Your party gains " << kilos / 5 << " fullness." << endl;
                        for(int i = 0; i < 5; i++) {
                            party.members[i].fullness += kilos / 5;
                        }
                    }
                }
                exit = true;
            break;
            case 2:
                if(party.cookware[1] < 1) {
                    cout << "Sorry you don't have a Frying pan to cook with." << endl;
                    break;
                } else {
                    cout << "You are cooking " << kilos << " kg of food with a Frying pan..." << endl;
                    party.ingredients -= kilos;
                    int random = rand() % 11 + 1;
                    if(random == 1) {
                        cout << "Your cook failed, you lose the pan and the ingredients" << endl;
                        party.cookware[1]--;
                    } else {
                        cout << "Your cook succeeded! Your party gains " << kilos / 5 << " fullness." << endl;
                        for(int i = 0; i < 5; i++) {
                            party.members[i].fullness += kilos / 5;
                        }
                    }
                }
                exit = true;
            break;
        }
    }

}




// NPC Speak Function (Puzzle)
void baseAction :: speak(Game game, Party party)
{
    // Declare Variables 
    ifstream file_input;
    string riddle; 
    string arr[2];   


    // Prepare Random Number Generation
    srand(time(NULL));  // SEEDS WITH RANDOM TIME
    int random = rand() % 21 + 1;   // GIVES RANDOM NUMBER (1 - total riddles(20))


    // Select Random Riddle From File and Send To "Riddle"
    file_input.open("riddles.txt");
    for(int i = 1; i <= 20; i++ )  
    {
        getline(file_input, riddle);
        if (i == random);
        split(monster, '~', arr, 2);
    }
    file_input.close();


    // Interaction With Player
    string answer; 
    cout << "Here is your riddle, please answer correctly" << endl;
    cout << arr[0] << endl;
    cin >> answer;

    if (answer == arr[1]) // Correct Answer
    {
        party.MerchantMenu()
        // OPEN MERCHANT MENU
    }

    else // Incorrect Answer
    {
        monsterFight();
    }



}
