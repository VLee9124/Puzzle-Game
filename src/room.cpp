#include "../include/room.hpp"

Room::Room(string name, string desc) {
    this->roomName = name;
    this->roomDesc = desc;
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

    // gameObject* it = find(this->objectList.begin(), this->objectList.end(), targetObj);
    // if(it != this->objectList.end())
    //     this->objectList.erase(it);
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
