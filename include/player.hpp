#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "gameObject.hpp"
#include "room.hpp"
#include "inventory.hpp"

using namespace std;

class Player {
    public:
        Player(Room* startRoom) : currRoom(startRoom) {}
        void setCurrRoom(Room* newRoom);
        Room* getCurrRoom() const;
        void interactWith(gameObject* object);
        void examine(Room* currRoom, ostream& out); // Had to add parameter
        const inventory& getInventory() const;  // Add this method to access the inventory
    private:
        Room* currRoom;
        inventory playerInventory;
};