#include "Character.h"
#include "Dungeoon.h"
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
        if ( confirmSelection == 'Y' || confirmSelection == 'y' )
        {
            // Start game
            break;
        }
        else if ( confirmSelection != 'N' && confirmSelection != 'n' )
        {
            // Make user choose a valid selection
            std::cout << "Invalid selection!" << std::endl;
        }
    }

    // Create player
    Character player        = Character( characterInput );
    std::string playerType  = player.GetType();
    std::string playerClass = player.GetClass();
    int playerStrength      = player.GetStrength();
    int playerMagic         = player.GetMagic();
    int playerHealth        = player.GetHealth();

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
    Dungeoon dungeoon = Dungeoon();
    
    // Play game
    bool playGame = true;
    bool endOfDungeoonReached = false;
    char action = ' ';
    while ( playGame )
    {
        // Place player at starting location
        int startXPosition = dungeoon.GetStartXPosition();
        int startYPosition = dungeoon.GetStartYPosition();
        player.SetPlayerAtStart( startXPosition, startYPosition );

        // Begin story
        BeginStory();
        std::cin >> action;
        // CheckInput( action );
        // player.SetAction( action );

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
}

void CheckInput()
{
    if 
}

void BeginStory()
{
    std::cout << "You find yourself in a dark and dank place..." << std::endl;
    std::cout << "There is just enough light to see only a few feet in front of you..." << std::endl;
    std::cout << "What will you do?" << std::endl;

    std::cout << "Move Character:" << std::endl;
    std::cout << "[F] Forward" << std::endl;
    std::cout << "[L] Left" << std::endl;
    std::cout << "[R] Right" << std::endl;
    std::cout << "Selection: ";
}