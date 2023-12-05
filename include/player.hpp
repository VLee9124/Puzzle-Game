#pragma once

#include "room.hpp"
#include "inventory.hpp"

using namespace std;

class Player {
public:
    Player(Room* startRoom); //constructor in the first room

    void setCurrRoom(Room* newRoom); //setter for current room
    Room* getCurrRoom() const; //getter for current room

    Inventory& getInventory(); //public accessor for Inventory

private:
    Room* currRoom; //pointer to current room that player is inside
    Inventory playerInventory; 
};