#include <iostream>
using namespace std;


class baseAction()
{
    public:
    // Normal Space Actions
    void investigate();  // Investigate Current Spot & Return Findings
    void monsterFight();   // Initiates Monster Fight
    void cook();   // Display Cooking Menu and Loop 

    // NPC Space Actions 
    void speak();

    // Room Space Actions
    void openDoor();

    // Anytime Actions
    void giveUp();   // Display Game Ending Conditons

}