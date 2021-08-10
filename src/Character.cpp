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

        case 'm':
        case 'M':
            class_      = MAGE;
            strength_   = 2;
            magic_      = 8;
            health_     = 5;

        case 'o':
        case 'O':
            class_      = ORC;
            strength_   = 9;
            magic_      = 0;
            health_     = 6;

        case 'e':
        case 'E':
            class_      = ELF;
            strength_   = 1;
            magic_      = 5;
            health_     = 9;

        default :
            // Do nothing
    }
};

Character::Character( const CHARACTER_CLASS& monsterClass )
{
    type_   = NPC;
    class_  = monsterClass;

    switch ( monsterClass )
    {
        case ZOMBIE:
            strength_   = 8;
            magic_      = 2;
            health_     = 5;

        case GIANT:
            strength_   = 2;
            magic_      = 8;
            health_     = 5;

        case DRAGON:
            strength_   = 9;
            magic_      = 0;
            health_     = 6;

        default :
            // Do nothing
    }
     
};

Character::~Character( )
{
    // Do nothing
};

int Character::GetType()        { return type_;     };
int Character::GetClass()       { return class_;    };
int Character::GetStrength()    { return strength_; };
int Character::GetMagic()       { return magic_;    };
int Character::GetHealth()      { return health_;   };