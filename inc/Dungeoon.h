#pragma once

#include <iostream>

class Dungeoon
{
    public:
        // Constructors and Destructor
        // ---------------------------
        // Constructor
        Dungeoon();

        // Deconstructor();
        ~Dungeoon();

        // Getter and setter functions
        // ---------------------------
        unsigned int    GetDungeoonSize();
        int             GetStartXPosition();
        int             GetStartYPosition();
        char            GetAdjacentSpace( const int& adjacentXLocation, const int& adjacentYLocation );

    private:
        static const unsigned int GAME_BOARD_SIZE = 5;
        char gameBoard_[GAME_BOARD_SIZE][GAME_BOARD_SIZE];

        // Dungeoon setup function
        // ---------------------------
        void DungeoonSetup();

        // Event functions
        // ---------------------------
        //void CheckForEvent();


};