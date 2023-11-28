#ifndef PLAYER_H
#define PLAYER_H

#include "Room.h"
#include "Inventory.h"

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

#endif /* PLAYER_H */