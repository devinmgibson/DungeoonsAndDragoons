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

int Character::GetStrength()    { return strength_; };
int Character::GetMagic()       { return magic_;    };
int Character::GetHealth()      { return health_;   };

void Character::SetPlayerAtStart( const int& xPosition, const int& yPosition )
{
    xPosition_ = xPosition;
    yPosition_ = yPosition;
}

/*
void Character::SetAction( const char& action )
{
    switch ( action )
    {
        case 'f':
        case 'F':
            MoveForward();
            break;

        case 'b':
        case 'B':
            MoveBackward();
            break;

        case 'l':
        case 'L':
            MoveLeft();
            break;

        case 'r':
        case 'R':
            MoveRight();
            break;

        case 'p':
        case 'P':
            PickupItem();
            break;

        case 'd':
        case 'D':
            DropItem();
            break;

        case 'e':
        case 'E':
            EngageMonster();
            break;

        case 'a':
        case 'A':
            RunAway();
            break;

        default :
            break;
    }
}
*/