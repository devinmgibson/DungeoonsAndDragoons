#pragma once

class Character
{
    public:
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
            DRAGON
        };

        // Constructors and Destructor
        // ---------------------------
        // Constructor 
        Character();
        Character( const char& userInput );
        Character( const CHARACTER_CLASS& monsterClass );
        
        // Deconstructor
        ~Character();

        // Getter functions
        // ---------------------------
        int GetType();
        int GetClass();
        int GetStrength();
        int GetMagic();
        int GetHealth();

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

        // Character attributes:
        // ---------------------------
        int type_;
        int class_;
        int strength_;
        int magic_;
        int health_;

};