#include "../include/lockedDoor.hpp"

lockedDoor::lockedDoor(string name, string description, string interaction, Puzzle* objPuzzle, Room* adjRoom) :
    lockedObject(name, description, interaction, objPuzzle), Door(name, description, interaction, adjRoom) {}

void lockedDoor::interact(ostream& out, istream& in) {
    if (!isOpen) {
        if (objPuzzle != nullptr) {
            unlock(out, in);
        }
    }

    if (isOpen) {
        lockedObject::description = lockedObject::interaction;
        Door::description = Door::interaction;
    }
}

void lockedDoor::unlock(ostream& out, istream& in) {
    lockedObject::unlock(out, in);
    if (!isLocked) {
        setOpen(true);
        out << "You unlocked the door and gained access to the adjacent room." << endl << endl;
    }
    else {
        out << "The door is still locked." << endl << endl;
    }
}