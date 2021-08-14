#include "Character.h"

Character::Character()
{
    type_           = 0;
    class_          = 0;
    strength_       = 0;
    magic_          = 0;
    health_         = 0;
    xPosition_      = 0;
    yPosition_      = 0;
    xPositionPrev_  = 0;
    yPositionPrev_  = 0;
};

Character::Character( const char& userInput )
{
    type_ = PC;
    xPosition_ = 0;
    yPosition_ = 0;
    xPositionPrev_ = 0;
    yPositionPrev_ = 0;

    switch ( userInput )
    {
        case 'k':
        case 'K':
            class_      = KNIGHT;
            strength_   = 8;
            magic_      = 2;
            health_     = 5;
            break;

        case 'm':
        case 'M':
            class_      = MAGE;
            strength_   = 2;
            magic_      = 8;
            health_     = 5;
            break;

        case 'o':
        case 'O':
            class_      = ORC;
            strength_   = 9;
            magic_      = 0;
            health_     = 6;
            break;

        case 'e':
        case 'E':
            class_      = ELF;
            strength_   = 1;
            magic_      = 5;
            health_     = 9;
            break;

        default :
            // Do nothing
            break;
    };
};

Character::Character( const int& monsterClass )
{
    type_   = NPC;
    xPosition_ = 0;
    yPosition_ = 0;
    xPositionPrev_ = 0;
    yPositionPrev_ = 0;

    switch ( monsterClass )
    {
        case 4:
            class_      = ZOMBIE;
            strength_   = 8;
            magic_      = 2;
            health_     = 5;
            break;

        case 5:
            class_      = GIANT;
            strength_   = 2;
            magic_      = 8;
            health_     = 5;
            break;

        case 6:
            class_      = DRAGOON;
            strength_   = 9;
            magic_      = 0;
            health_     = 6;
            break;

        default :
            // Do nothing
            break;
    };   
};

Character::~Character( )
{
    // Do nothing
};

std::string Character::GetType()
{
    std::string type = "";
    if ( type_ == PC )
    {   
        type = "PC";
    }

    if ( type_ == NPC )
    {
        type = "NPC";
    }

    return type;
};

std::string Character::GetClass()
{
    std::string characterClass = "";

    if ( class_ == KNIGHT )
    {
        characterClass = "KNIGHT";
    }

    if ( class_ == MAGE )
    {
        characterClass = "MAGE";
    }

    if ( class_ == ORC )
    {
        characterClass = "ORC";
    }

    if ( class_ == ELF )
    {
        characterClass = "ELF";
    }

    if ( class_ == ZOMBIE )
    {
        characterClass = "ZOMBIE";
    }

    if ( class_ == GIANT )
    {
        characterClass = "GIANT";
    }

    if ( class_ == DRAGOON )
    {
        characterClass = "DRAGOON";
    }

    return characterClass;
};

int Character::GetStrength()        { return strength_;     };
int Character::GetMagic()           { return magic_;        };
int Character::GetHealth()          { return health_;       };
int Character::GetXPosition()       { return xPosition_;    };
int Character::GetYPosition()       { return yPosition_;    };
int Character::DecreaseStrength()   { return strength_--;   };
int Character::DecreaseMagic()      { return magic_--;      };
int Character::DecreaseHealth()     { return health_--;     };
int Character::IncreaseStrength()   { return strength_++;   };
int Character::IncreaseMagic()      { return magic_++;      };
int Character::IncreaseHealth()     { return health_++;     };

void Character::SetPlayerAtStart( const int& xPosition, const int& yPosition )
{
    xPosition_ = xPosition;
    yPosition_ = yPosition;
    xPositionPrev_ = xPosition;
    yPositionPrev_ = yPosition;
}

bool Character::SetAction( const char& action, Dungeoon& dungeoon )
{
    bool engageMonster = false;
    int newXPosition = 0;
    int newYPosition = 0;
    char nextSpace = ' ';
    unsigned int dungeoonSize = dungeoon.GetDungeoonSize();

    switch ( action )
    {
        case 'f':
        case 'F':
            newXPosition    = xPosition_;
            newYPosition    = yPosition_ - 1;
            nextSpace       = dungeoon.GetAdjacentSpace( newXPosition, newYPosition );
            if ( yPosition_ != 0 )
            {
                MoveForward( dungeoonSize, nextSpace );
            }
            break;

        case 'b':
        case 'B':
            newXPosition    = xPosition_;
            newYPosition    = yPosition_ + 1;
            nextSpace       = dungeoon.GetAdjacentSpace( newXPosition, newYPosition );
            if ( yPosition_ != dungeoonSize - 1 )
            {
                MoveBackward( dungeoonSize, nextSpace );
            }
            break;

        case 'l':
        case 'L':
            newXPosition    = xPosition_ - 1;
            newYPosition    = yPosition_;
            nextSpace       = dungeoon.GetAdjacentSpace( newXPosition, newYPosition );
            if ( xPosition_ != 0 )
            {
                MoveLeft( dungeoonSize, nextSpace );
            }
            break;

        case 'r':
        case 'R':
            newXPosition    = xPosition_ + 1;
            newYPosition    = yPosition_;
            nextSpace       = dungeoon.GetAdjacentSpace( newXPosition, newYPosition );
            if ( xPosition_ != 0 )
            {
                MoveRight( dungeoonSize, nextSpace );
            }
            break;

        case 'e':
        case 'E':
            engageMonster = EngageMonster();
            break;

        case 'a':
        case 'A':
            RunAway();
            break;

        default :
            break;
    }

    return engageMonster;
}

void Character::MoveForward( const unsigned int& dungeoonSize, const char& nextSpace )
{
    xPositionPrev_ = xPosition_;
    yPositionPrev_ = yPosition_;
    if ( nextSpace == 'C' )
    {
        yPosition_ -= 2;
    }
    else
    {
        yPosition_--;
    }
}

void Character::MoveBackward( const unsigned int& dungeoonSize, const char& nextSpace )
{
    xPositionPrev_ = xPosition_;
    yPositionPrev_ = yPosition_;
    if ( nextSpace == 'C' )
    {
        yPosition_ += 2;
    }
    else
    {
        yPosition_--;
    }
}

void Character::MoveLeft( const unsigned int& dungeoonSize, const char& nextSpace )
{
    xPositionPrev_ = xPosition_;
    yPositionPrev_ = yPosition_;
    if ( nextSpace == 'C' )
    {
        xPosition_ -= 2;
    }
    else
    {
        xPosition_--;
    }
}

void Character::MoveRight( const unsigned int& dungeoonSize, const char& nextSpace )
{
    xPositionPrev_ = xPosition_;
    yPositionPrev_ = yPosition_;
    if ( nextSpace == 'C' )
    {
        xPosition_ += 2;
    }
    else
    {
        xPosition_++;
    }
}

bool Character::EngageMonster()
{
    std::cout << "You engage the monster..." << std::endl;
    return true;
}

void Character::RunAway()
{
    std::cout << "You get away, but not without a few wounds. Health decreased by 2!" << std::endl;
    health_ -= 2;
    xPosition_ = xPositionPrev_;
    yPosition_ = yPositionPrev_;
}