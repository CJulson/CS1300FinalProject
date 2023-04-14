#include <iostream>
#include "game.h"
#include "party.h"
using namespace std;


class baseAction
{
    public:
    // Normal Space Actions
    void investigate(Game game, Party party);  // Investigate Current Spot & Return Findings
    void monsterFight(Game game, Party party);   // Initiates Monster Fight
    void cook(Game game, Party party);   // Display Cooking Menu and Loop 

    // NPC Space Actions 
    void speak(Game game, Party party);

    // Room Space Actions
    void openDoor(Game game, Party party);

    // Anytime Actions
    void giveUp(Game game, Party party);   // Display Game Ending Conditons

};