#include <iostream>
#include "Character.h"
#include "DungeoonsAndDragoons.h"

int main()
{   
    // Welcome
    char characterInput = 'z';
    char confirmSelection = 'n';
    std::cout << "Welcome to Dungeoons and Dragoons!" << std::endl;

    while ( confirmSelection == 'N' || confirmSelection == 'n' )
    {
        std::cout << "Please select a character class: " << std::endl;
        std::cout << "[K] Knight" << std::endl;
        std::cout << "[M] Mage" << std::endl;
        std::cout << "[O] Orc" << std::endl;
        std::cout << "[E] Elf" << std::endl;
        std::cout << "[s] Character Stats" <<std::endl;
        std::cout << "Selection: ";

        // Player selects character
        std::cin >> characterInput;

        // Verify player's selection
        if ( characterInput == 'K' || characterInput == 'k' )
        {
            std::cout << "You selected Knight. Are you sure? [y/n]: ";
        }
        else if ( characterInput == 'M' || characterInput == 'm' )
        {
            std::cout << "You selected Mage. Are you sure? [y/n]: ";
        }
        else if ( characterInput == 'O' || characterInput == 'o' )
        {
            std::cout << "You selected Orc. Are you sure? [y/n]: ";
        }
        else if ( characterInput == 'E' || characterInput == 'e' )
        {
            std::cout << "You selected Elf. Are you sure? [y/n]: ";
        }
        else if ( characterInput == 's' )
        {
            std::cout << "Character Stats:" << std::endl;
            std::cout << "Knight: \tStrength: 8/10, \tMagic 2/10, \tHealth: 5/10" << std::endl;
            std::cout << "Mage: \tStrength: 1/10, \tMagic 9/10, \tHealth: 5/10" << std::endl;
            std::cout << "Orc: \tStrength: 9/10, \tMagic 0/10, \tHealth: 6/10" << std::endl;
            std::cout << "Elf: \tStrength: 1/10, \tMagic 5/10, \tHealth: 9/10" << std::endl;
            std::cout << "Please select a character class: " << std::endl;
            std::cout << "[K] Knight" << std::endl;
            std::cout << "[M] Mage" << std::endl;
            std::cout << "[O] Orc" << std::endl;
            std::cout << "[E] Elf" << std::endl;
            std::cout << "Selection: ";
            
            std::cin >> characterInput;

            if ( characterInput == 'K' || characterInput == 'k' )
            {
                std::cout << "You selected Knight. Are you sure? [y/n]: ";
            }
            else if ( characterInput == 'M' || characterInput == 'm' )
            {
                std::cout << "You selected Mage. Are you sure? [y/n]: ";
            }
            else if ( characterInput == 'O' || characterInput == 'o' )
            {
                std::cout << "You selected Orc. Are you sure? [y/n]: ";
            }
            else if ( characterInput == 'E' || characterInput == 'e' )
            {
                std::cout << "You selected Elf. Are you sure? [y/n]: ";
            }
        }

        // Make player confirm selection
        std::cin >> confirmSelection;

        // Set player character
        if ( confirmSelection == 'Y' || confirmSelection == 'y' )
        {
            Character player        = Character( characterInput );
            std::string playerType  = player.GetType();
            std::string playerClass = player.GetClass();
            int playerStrength      = player.GetStrength();
            int playerMagic         = player.GetMagic();
            int playerHealth        = player.GetHealth();
        }
        else if ( confirmSelection !='N' && confirmSelection !='n' )
        {
            std::cout << "Invalid selection!" << std::endl;
        }
    }

    // Create monsters
    Character zombie    = Character( 4 );
    int zombieStrength  = zombie.GetStrength();
    int zombieMagic     = zombie.GetMagic();
    int zombieHealth    = zombie.GetHealth();

    Character giant     = Character( 5 );
    int giantStrength   = zombie.GetStrength();
    int giantMagic      = zombie.GetMagic();
    int giantHealth     = zombie.GetHealth();

    Character dragoon   = Character( 6 );
    int dragoonStrength = zombie.GetStrength();
    int dragoonMagic    = zombie.GetMagic();
    int dragoonHealth   = zombie.GetHealth();

    // Load dungeoon

    // Play game
    bool playGame = true;
    bool endOfDungeoonReached = false;
    while ( playGame )
    {
        // Check if player has reached end of dungeoon
        if ( playGame )
        {
            endOfDungeoonReached = true;
        }

        // Check if end of dungeoon has been reached
        if ( endOfDungeoonReached )
        {
            // Game over
            playGame = false;
        }
    }

    // End of game
    std::cout << "Congratulations! You have beaten Dungeoons and Dragoons!" << std::endl;

    return 0;
}