#include "Character.h"

Character::Character()
{
    type_       = 0;
    class_      = 0;
    strength_   = 0;
    magic_      = 0;
    health_     = 0;
};

Character::Character( const char& userInput )
{
    type_ = PC;

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

int Character::GetStrength()    { return strength_;     };
int Character::GetMagic()       { return magic_;        };
int Character::GetHealth()      { return health_;       };
int Character::GetXPosition()   { return xPosition_;    };
int Character::GetYPosition()   { return yPosition_;    };

void Character::SetPlayerAtStart( const int& xPosition, const int& yPosition )
{
    xPosition_ = xPosition;
    yPosition_ = yPosition;
}

void Character::SetAction( const char& action, Dungeoon& dungeoon )
{
    int newXPosition = 0;
    int newYPosition = 0;
    char nextSpace = ' ';
    unsigned int dungeoonSize = dungeoon.GetDungeoonSize();

    switch ( action )
    {
        case 'f':
        case 'F':
            newXPosition    = xPosition_;
            newYPosition    = yPosition_++;
            nextSpace       = dungeoon.GetAdjacentSpace( newXPosition, newYPosition );
            if ( yPosition_ != dungeoonSize - 1 )
            {
                MoveForward( dungeoonSize, nextSpace );
            }
            break;

        case 'b':
        case 'B':
            newXPosition    = xPosition_;
            newYPosition    = yPosition_--;
            nextSpace       = dungeoon.GetAdjacentSpace( newXPosition, newYPosition );
            if ( yPosition_ != 0 )
            {
                MoveBackward( dungeoonSize, nextSpace );
            }
            break;

        case 'l':
        case 'L':
            newXPosition    = xPosition_--;
            newYPosition    = yPosition_;
            nextSpace       = dungeoon.GetAdjacentSpace( newXPosition, newYPosition );
            if ( xPosition_ != 0 )
            {
                MoveLeft( dungeoonSize, nextSpace );
            }
            break;

        case 'r':
        case 'R':
            newXPosition    = xPosition_++;
            newYPosition    = yPosition_;
            nextSpace       = dungeoon.GetAdjacentSpace( newXPosition, newYPosition );
            if ( xPosition_ != 0 )
            {
                MoveRight( dungeoonSize, nextSpace );
            }
            break;

        case 'p':
        case 'P':
            //PickupItem();
            break;

        case 'd':
        case 'D':
            //DropItem();
            break;

        case 'e':
        case 'E':
            //EngageMonster();
            break;

        case 'a':
        case 'A':
            //RunAway();
            break;

        default :
            break;
    }
}

void Character::MoveForward( const unsigned int& dungeoonSize, const char& nextSpace )
{
    if ( yPosition_ < dungeoonSize && nextSpace == ' ' )
    {
        yPosition_++;
    }
    else if ( yPosition_ < dungeoonSize && nextSpace == 'C' )
    {
        yPosition_ += 2;
    }
}

void Character::MoveBackward( const unsigned int& dungeoonSize, const char& nextSpace )
{
    if ( yPosition_ > 0 && nextSpace == ' ' )
    {
        yPosition_--;
    }
    else if ( yPosition_ > 0 && nextSpace == 'C' )
    {
        yPosition_ -= 2;
    }
}

void Character::MoveLeft( const unsigned int& dungeoonSize, const char& nextSpace )
{
    if ( xPosition_ > 0 && nextSpace == ' ' )
    {
        xPosition_--;
    }
    else if ( xPosition_ > 0 && nextSpace == 'C' )
    {
        xPosition_ -= 2;
    }
}

void Character::MoveRight( const unsigned int& dungeoonSize, const char& nextSpace )
{
    if ( xPosition_ < dungeoonSize && nextSpace == ' ' )
    {
        xPosition_++;
    }
    else if ( xPosition_ < dungeoonSize && nextSpace == 'C' )
    {
        xPosition_ += 2;
    }
}