#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "door.hpp"
using namespace std;

class gameTerminal {
    public:
        gameTerminal();
        gameTerminal(vector<Room*>);
        void playGame(ostream&, istream&);
        void displayCurrRoom(ostream&);
        void proceedToOpenInventory(ostream&, istream&);
        void proceedToMoveTo(ostream&, istream&);
        void proceedToExamine();
        void proceedToWinScreen();
    private:
        Player currPlayer;
        vector<Room*> currMap;
};