#include "../include/room.hpp"

Room::Room(string name, string desc) {
    this->roomName = name;
    this->roomDesc = desc;
}

Room::~Room() {
    for (unsigned i = 0; i < doorList.size(); ++i) {
        delete doorList.at(i);
    }
    for (unsigned i = 0; i < objectList.size(); ++i) {
        delete objectList.at(i);
    }
}

vector<gameObject*> Room::getAllObjects() {
    return this->objectList;
}

vector<Door*> Room::getAdjacentRooms() {
   return this->doorList;
}

string Room::getName() {
    return this->roomName;
}

string Room::getDesc() {
    return this->roomDesc;
}

void Room::addObject(gameObject* newObj) {
    this->objectList.push_back(newObj);
}

void Room::removeObject(int itemIndex) {
    if (!(0 <= itemIndex && itemIndex < objectList.size())) {
        throw runtime_error("Cannot get item. Index is out of range.");
    }

    gameObject* victimObject = objectList.at(itemIndex);
    objectList.erase(objectList.begin() + itemIndex);
    delete victimObject;
}

void Room::addDoor(Door* newDoor) {
    this->doorList.push_back(newDoor);
}

gameObject* Room::getObject(int index) {
    return objectList.at(index);
}

bool Room::emptyRoom() {
    return (objectList.size() == 0);
}
