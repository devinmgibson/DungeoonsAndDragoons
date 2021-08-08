#include <iostream>

int main()
{   
    // Welcome
    char character = 'z';
    char confirmSelection = 'n';
    std::cout << "Welcome to Dungeoons and Dragoons" << std::endl;

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
        std::cin >> character;

        // Verify player's selection
        if ( character == 'K' || character == 'k' )
        {
            std::cout << "You selected Knight. Are you sure? [y/n]";
        }
        else if ( character == 'M' || character == 'm' )
        {
            std::cout << "You selected Mage. Are you sure? [y/n]";
        }
        else if ( character == 'O' || character == 'o' )
        {
            std::cout << "You selected Orc. Are you sure? [y/n]";
        }
        else if ( character == 'E' || character == 'e' )
        {
            std::cout << "You selected Elf. Are you sure? [y/n]";
        }
        else if ( character == 's' )
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
            
            std::cin >> character;

            if ( character == 'K' || character == 'k' )
            {
                std::cout << "You selected Knight. Are you sure? [y/n]: ";
            }
            else if ( character == 'M' || character == 'm' )
            {
                std::cout << "You selected Mage. Are you sure? [y/n]: ";
            }
            else if ( character == 'O' || character == 'o' )
            {
                std::cout << "You selected Orc. Are you sure? [y/n]: ";
            }
            else if ( character == 'E' || character == 'e' )
            {
                std::cout << "You selected Elf. Are you sure? [y/n]: ";
            }
        }

        // Make player confirm selection
        std::cin >> confirmSelection;

        // Let's play
        if ( confirmSelection =='Y' || confirmSelection =='y' )
        {
            std::cout << std::endl << "Let's Play!" << std::endl;
        }
    }

    return 0;
}