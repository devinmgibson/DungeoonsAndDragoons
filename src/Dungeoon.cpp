#include "Dungeoon.h"

Dungeoon::Dungeoon()
{
    DungeoonSetup();
}

Dungeoon::~Dungeoon()
{
    // Do nothing
}

void Dungeoon::DungeoonSetup()
{
    // Initiailze dungeoon
    for ( unsigned int i = 0; i < GAME_BOARD_SIZE; ++i )
    {
        for ( unsigned int j = 0; j < GAME_BOARD_SIZE; ++j )
        {
            gameBoard_[i][j] = ' ';
        }
    }

    // Place boundaries, items, and monsters
    gameBoard_[0][1] = 'C'; // Skip position (move to next available location)
    gameBoard_[0][2] = 'S'; // Starting location
    gameBoard_[0][3] = 'C'; // Skip position (move to next available location)
    gameBoard_[1][0] = 'W'; // Item: Weapons (Strength +1)
    gameBoard_[1][1] = 'X'; // Out of bounds square
    gameBoard_[1][2] = 'F'; // Item: Food (Health +1)
    gameBoard_[1][3] = 'X'; // Out of bounds square
    gameBoard_[1][4] = 'P'; // Item: Potion (Magic +1)
    gameBoard_[2][1] = 'Z'; // Monster: Zombie
    gameBoard_[2][3] = 'G'; // Monster: Giant
    gameBoard_[3][0] = 'F'; // Item: Food (Health +1)
    gameBoard_[3][1] = 'X'; // Out of bounds square
    gameBoard_[3][2] = 'P'; // Item: Potion (Magic +1)
    gameBoard_[3][3] = 'X'; // Out of bounds square
    gameBoard_[3][4] = 'W'; // Item: Weapons (Strength +1)
    gameBoard_[4][1] = 'C'; // Skip position (move to next available location)
    gameBoard_[4][2] = 'D'; // Monster: Dragoon
    gameBoard_[4][3] = 'C'; // Skip position (move to next available location)
}

int Dungeoon::GetStartXPosition()
{
    int startXPosition = 0;
    for ( unsigned int i = 0; i < GAME_BOARD_SIZE; ++i )
    {
        for ( unsigned int j = 0; j < GAME_BOARD_SIZE; ++j )
        {
            if ( gameBoard_[i][j] == 'S' )
            {
                startXPosition = i;
                break;
            }
        }
    }

    return startXPosition;
}

int Dungeoon::GetStartYPosition()
{
    int startYPosition = 0;
    for ( unsigned int i = 0; i < GAME_BOARD_SIZE; ++i )
    {
        for ( unsigned int j = 0; j < GAME_BOARD_SIZE; ++j )
        {
            if ( gameBoard_[i][j] == 'S' )
            {
                startYPosition = j;
                break;
            }
        }
    }

    return startYPosition;
}