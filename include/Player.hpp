#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <string>
#include "room.hpp"
#include "gameObject.h"
#include "Inventory.hpp"
using namespace std;

class Player {
    public:
        Player(Room* startRoom) : currRoom(startRoom) {}
        void setCurrRoom(Room*);
        Room* getCurrRoom() const;
    private:
        Room* currRoom;
        Inventory playerInventory;
}

#endif