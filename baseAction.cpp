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




// INVESTIGATE UNEXPLORED SPACE
void baseAction::investigate(Game game, Party party)
{

    // Prepare Random Number Generation
    srand(time(NULL));  // SEEDS WITH RANDOM TIME
    int random = rand() % 11 + 1;   // GIVES RANDOM NUMBER (1-10)

    // 10% Chance To Add Key
    if(random == 1)
    {
        party.keys++;
    }

    // 20% Chance To Find Treasure
    if (random == 2 || random == 3)
    {
        // ADD TREASURE (BASED ON ROOMS CLEARED?)
    }

    if (random == 4 || random == 5)
    {
        monsterFight() // Fight Random Monster
    }

    return;
}





// Monster Fight Function
void BaseAction :: monsterFight()
{
    // DECLARE VARIBALES
    ifstream file_input;
    string line;
    string monster; 
    string arr[2];   


    // Find Numbers of Monsters Left in File
    int counter = 0;
    file_input.open(monsters.txt);
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
    file_input.open(monsters.txt);
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
void BaseAction :: cook()
{

}




// NPC Speak Function (Puzzle)
void BaseAction :: speak()
{
    // Declare Variables 
    ifstream file_input;
    string riddle; 
    string arr[2];   


    // Prepare Random Number Generation
    srand(time(NULL));  // SEEDS WITH RANDOM TIME
    int random = rand() % 21 + 1;   // GIVES RANDOM NUMBER (1 - total riddles(20))


    // Select Random Riddle From File and Send To "Riddle"
    file_input.open(riddles.txt);
    for(int i = 1; i <= 20; i++ )  
    {
        getline(file_input, monster);
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
        // OPEN MERCHANT MENU
    }

    else // Incorrect Answer
    {
        monsterFight();
    }



}






int main()
{

    return 0;
}