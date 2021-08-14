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
    gameBoard_[0][2] = 'D'; // Monster: Dragoon
    gameBoard_[0][3] = 'C'; // Skip position (move to next available location)
    gameBoard_[1][0] = 'F'; // Item: Food (Health +1)
    gameBoard_[1][1] = 'X'; // Out of bounds square 
    gameBoard_[1][2] = 'P'; // Item: Potion (Magic +1)
    gameBoard_[1][3] = 'X'; // Out of bounds square
    gameBoard_[1][4] = 'P'; // Item: Weapons (Strength +1)
    gameBoard_[2][1] = 'Z'; // Monster: Zombie
    gameBoard_[2][3] = 'G'; // Monster: Giant
    gameBoard_[3][0] = 'W'; // Item: Weapons (Strength +1)
    gameBoard_[3][1] = 'X'; // Out of bounds square
    gameBoard_[3][2] = 'F'; // Item: Food (Health +1)
    gameBoard_[3][3] = 'X'; // Out of bounds square
    gameBoard_[3][4] = 'W'; // Item: Potion (Magic +1)
    gameBoard_[4][1] = 'C'; // Skip position (move to next available location)
    gameBoard_[4][2] = 'S'; // Starting location
    gameBoard_[4][3] = 'C'; // Skip position (move to next available location)
}

unsigned int Dungeoon::GetDungeoonSize()
{
    return GAME_BOARD_SIZE;
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
                startXPosition = j;
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
                startYPosition = i;
                break;
            }
        }
    }

    return startYPosition;
}

char Dungeoon::GetCurrentSpace( const int& xLocation, const int& yLocation )
{
    return gameBoard_[yLocation][xLocation];
}

char Dungeoon::GetAdjacentSpace( const int& adjacentXLocation, const int& adjacentYLocation)
{
    return gameBoard_[adjacentYLocation][adjacentXLocation];
}

void Dungeoon::GetAvailableActions( const int& currentXPosition, const int& currentYPosition, const char& currentSpace )
{
    if ( currentXPosition >= 0 && currentXPosition <= GAME_BOARD_SIZE - 1 && currentYPosition >= 0 && currentYPosition <= GAME_BOARD_SIZE - 1 )
    {
        switch( currentSpace )
        {
            case 'D':
                std::cout << "You've encountered a Dragoon! What will you do?" << std::endl;
                std::cout << "[E] Engage" << std::endl;
                std::cout << "[A] Run Away" << std::endl;
                break;

            case 'F':
                std::cout << "You've found some food! Health increased by 1!" << std::endl;
                gameBoard_[currentYPosition][currentXPosition] = ' ';
                GetAvailableActions( currentXPosition,currentYPosition, gameBoard_[currentYPosition][currentXPosition] );
                break;

            case 'G':
                std::cout << "You've encountered a Giant! What will you do?" << std::endl;
                std::cout << "[E] Engage" << std::endl;
                std::cout << "[A] Run Away" << std::endl;
                break;

            case 'P':
                std::cout << "You've found a potion! Magic increased by 1!" << std::endl;
                gameBoard_[currentYPosition][currentXPosition] = ' ';
                GetAvailableActions( currentXPosition,currentYPosition, gameBoard_[currentYPosition][currentXPosition] );
                break;

            case 'W':
                std::cout << "You've found some weapons! Strength increased by 1!" << std::endl;
                gameBoard_[currentYPosition][currentXPosition] = ' ';
                GetAvailableActions( currentXPosition,currentYPosition, gameBoard_[currentYPosition][currentXPosition] );
                break;

            case 'Z':
                std::cout << "You've encountered a Zombie! What will you do?" << std::endl;
                std::cout << "[E] Engage" << std::endl;
                std::cout << "[A] Run Away" << std::endl;
                break;

            default :
                if ( currentXPosition == 0 && currentYPosition == 0 )
                {
                    std::cout << "You have reached a right hand turn. It smells of fire and brimstome..." << std::endl;
                    std::cout << "What will you do?" << std::endl;
                    std::cout << "Move Character:" << std::endl;
                    std::cout << "[R] Right" << std::endl;
                    std::cout << "[B] Backward" << std::endl;
                }
                else if ( currentXPosition == GAME_BOARD_SIZE - 1 && currentYPosition == 0 )
                {
                    std::cout << "You have reached a left hand turn. It smells of fire and brimstome..." << std::endl;
                    std::cout << "What will you do?" << std::endl;
                    std::cout << "Move Character:" << std::endl;
                    std::cout << "[L] Left" << std::endl;
                    std::cout << "[B] Backward" << std::endl;
                }
                else if ( ( currentXPosition == 0 && currentYPosition == 1 ) || ( currentXPosition == 2 && currentYPosition == 1 )
                            || ( currentXPosition == 4 && currentYPosition == 1 ) || ( currentXPosition == 0 && currentYPosition == 3 ) 
                            || ( currentXPosition == 2 && currentYPosition == 3 ) || ( currentXPosition == 4 && currentYPosition == 3 ))
                {
                    std::cout << "What will you do?" << std::endl;
                    std::cout << "Move Character:" << std::endl;
                    std::cout << "[F] Forward" << std::endl;
                    std::cout << "[B] Backward" << std::endl;
                }
                else if ( currentXPosition == 0 && currentYPosition == 2 )
                {
                    std::cout << "Two paths emerge before you and smell something rotten coming from the right..." << std::endl;
                    std::cout << "What will you do?" << std::endl;
                    std::cout << "Move Character:" << std::endl;
                    std::cout << "[F] Forward" << std::endl;
                    std::cout << "[B] Backward" << std::endl;
                    std::cout << "[R] Right" << std::endl;
                }
                else if ( ( currentXPosition == 1 && currentYPosition == 2 ) || ( currentXPosition == 3 && currentYPosition == 2 ) )
                {
                    std::cout << "What will you do?" << std::endl;
                    std::cout << "Move Character:" << std::endl;
                    std::cout << "[L] Left" << std::endl;
                    std::cout << "[R] Right" << std::endl;
                }
                else if ( currentXPosition == 2 && currentYPosition == 2 )
                {
                    std::cout << "You enter an open space and hear noises coming from all directions..." << std::endl;
                    std::cout << "What will you do?" << std::endl;
                    std::cout << "Move Character:" << std::endl;
                    std::cout << "[R] Forward" << std::endl;
                    std::cout << "[B] Backward" << std::endl;
                    std::cout << "[L] Left" << std::endl;
                    std::cout << "[R] Right" << std::endl;
                }
                else if ( currentXPosition == GAME_BOARD_SIZE - 1 && currentYPosition == 2 )
                {
                    std::cout << "Two paths emerge before you and smell something rotten coming from the left..." << std::endl;
                    std::cout << "What will you do?" << std::endl;
                    std::cout << "Move Character:" << std::endl;
                    std::cout << "[R] Forward" << std::endl;
                    std::cout << "[B] Backward" << std::endl;
                    std::cout << "[L] Left" << std::endl;
                }
                else if ( currentXPosition == 0 && currentYPosition == GAME_BOARD_SIZE - 1 )
                {
                    std::cout << "A path opens up in front of you..." << std::endl;
                    std::cout << "What will you do?" << std::endl;
                    std::cout << "Move Character:" << std::endl;
                    std::cout << "[R] Forward" << std::endl;
                    std::cout << "[R] Right" << std::endl;
                }
                else if ( currentXPosition == 2 && currentYPosition == GAME_BOARD_SIZE - 1 )
                {
                    std::cout << "This place looks familiar. Maybe it is where you started?" << std::endl;
                    std::cout << "What will you do?" << std::endl;
                    std::cout << "Move Character:" << std::endl;
                    std::cout << "[R] Forward" << std::endl;
                    std::cout << "[L] Left" << std::endl;
                    std::cout << "[R] Right" << std::endl;
                }
                else if ( currentXPosition == GAME_BOARD_SIZE - 1 && currentYPosition == GAME_BOARD_SIZE - 1 )
                {
                    std::cout << "A path opens up in front of you..." << std::endl;
                    std::cout << "What will you do?" << std::endl;
                    std::cout << "Move Character:" << std::endl;
                    std::cout << "[R] Forward" << std::endl;
                    std::cout << "[R] Left" << std::endl;
                }
                break;
        }
    }
}