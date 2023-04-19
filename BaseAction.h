#include <iostream>
#include "game.h"
#include "party.h"
using namespace std;


class baseAction
{
    public:
    Game game;
    Party party;
    baseAction(Game &game, Party &party);
    // Normal Space Actions
    void investigate(Party &party);  // Investigate Current Spot & Return Findings
    void monsterFight(Party &party);   // Initiates Monster Fight
    void cook(Party &party);   // Display Cooking Menu and Loop 

    // NPC Space Actions 
    void speak(Party &party);

    // Room Space Actions
    void openDoor();

    // Anytime Actions
    void giveUp(Game &game);   // Display Game Ending Conditons

    void doorOpen();

};