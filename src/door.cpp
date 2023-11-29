#include "../header/door.hpp"
#include "../header/room.hpp"

Door::Door(Room* adjRoom) {
    this->adjacentRoom = adjRoom;
}

Room* getAdjacentRoom() {
    return this->adjacentRoom;
}

void setOpen(bool val) {
    this->isOpen = val;
}


bool getOpen() {
    return this->isOpen;
}

void interact() override {
    
}