#include "../include/door.hpp"

Door::Door(string name, string description, string interaction, Room* adjRoom) : gameObject(name, description, interaction), adjacentRoom(adjRoom), isOpen(false) {}
Door::Door(string name, string description, string interaction, Room* adjRoom, bool isOpen) : gameObject(name, description, interaction), adjacentRoom(adjRoom), isOpen(isOpen) {}

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
    
    if (!isOpen) {
        setOpen(true);
        out << "You opened the door and gained access to the adjacent room" << endl << endl;
    }
    else {
        out << "The door is already opened" << endl << endl;
    }
}