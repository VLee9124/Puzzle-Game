// player.cpp
#include "../include/player.hpp"
#include <sstream>
#include <string>

void Player::setCurrRoom(Room* newRoom) {
    currRoom = newRoom;
}

Room* Player::getCurrRoom() const {
    return currRoom;
}

const inventory& Player::getInventory() const {
    return playerInventory;
}


void Player::interactWith(gameObject* object) {
    // Check for nullptr
    if (!object) {
        return;
    }

    // Check if the object is a Door
    if (Door* door = dynamic_cast<Door*>(object)) {
        if (door->getOpen()) {
            cout << "The door is already open." << endl;
        } else {
            door->interact();
        }
    }
    // Check if the object is inventoryObject
    else if (inventoryObject* invObject = dynamic_cast<inventoryObject*>(object)) {
        invObject->interact();
        playerInventory.addItem(invObject);
        cout << "You collected: " << invObject->getName() << endl;
    }
    else {
        // Interaction for unknown object
        cout << "You don't know how to interact with this object." << endl;
    }
}


void Player::examine(Room* currRoom, std::ostream& out) {
    // Use 'out' instead of 'cout' for output
    out << "You are in " << currRoom->getName() << ". " << currRoom->getDesc() << endl;

    // Display information about the objects in the room
    vector<gameObject*> objects = currRoom->getAllObjects();
    if (!objects.empty()) {
        out << "Objects in the room:" << endl;
        for (unsigned i = 0; i < objects.size(); ++i) {
            out << i + 1 << ". " << objects[i]->getName() << " - " << objects[i]->getDesc() << endl;
        }
    } else {
        out << "The room is empty." << endl;
    }

    // Display information about adjacent rooms
    vector<Door*> doors = currRoom->getAdjacentRooms();
    if (!doors.empty()) {
        out << "Adjacent rooms:" << endl;
        for (unsigned i = 0; i < doors.size(); ++i) {
            Room* adjRoom = doors[i]->getAdjacentRoom();
            out << i + 1 << ". " << adjRoom->getName() << " - " << adjRoom->getDesc() << endl;
        }
    } else {
        out << "There are no adjacent rooms." << endl;
    }
}
