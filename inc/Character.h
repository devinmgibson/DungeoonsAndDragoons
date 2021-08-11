#pragma once

#include <iostream>
#include <string>

class Character
{
    public:
        // Constructors and Destructor
        // ---------------------------
        // Constructor 
        Character();
        Character( const char& userInput );
        Character( const int& monsterClass );
        
        // Deconstructor
        ~Character();

        // Getter and setter functions
        // ---------------------------
        std::string GetType();
        std::string GetClass();
        int         GetStrength();
        int         GetMagic();
        int         GetHealth();
        void        SetPlayerAtStart( const int& xPosition, const int& yPosition );
        //void        SetAction( const char& action );

    private:
        // Character type
        // ---------------------------
        enum CHARACTER_TYPE
        {
            // Player character
            PC,

            //Non-player character
            NPC
        };

        // Character class
        // ---------------------------
        enum CHARACTER_CLASS
        {
            // PCs (0-3)
            KNIGHT,
            MAGE,
            ORC,
            ELF,

            // NPCs (4-6)
            ZOMBIE,
            GIANT,
            DRAGOON
        };

        // Character attributes:
        // ---------------------------
        int type_;
        int class_;
        int strength_;
        int magic_;
        int health_;
        int xPosition_;
        int yPosition_;
        
        // Character action functions
        // ---------------------------
        //void        MoveForward();
        //void        MoveBackward();
        //void        MoveLeft();
        //void        MoveRight();
        //void        PickupItem();
        //void        DropItem();
        //void        EngageMonster();
        //void        RunAway();

};