#pragma once

#include "room.hpp"
#include "inventory.hpp"

class Player {
public:
    Player();
    Player(Room* startRoom); //constructor in the first room

    void setCurrRoom(Room* newRoom); //setter for current room
    Room* getCurrRoom() const; //getter for current room

    inventory& getInventory(); //public accessor for Inventory

private:
    Room* currRoom; //pointer to current room that player is inside
    inventory playerInventory; 
};