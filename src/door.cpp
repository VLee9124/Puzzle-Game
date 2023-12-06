#include "../include/door.hpp"

Door::Door(string name, string description, string interaction, Room* adjRoom) : gameObject(name, description, interaction), adjacentRoom(adjRoom) {}

Room* Door::getAdjacentRoom() {
    return adjacentRoom;
}

void Door::setOpen(bool val) {
    isOpen = val;
}


bool Door::getOpen() {
    return isOpen;
}

void Door::interact(ostream& out, istream& in) {
    gameObject::interact(out, in);
}