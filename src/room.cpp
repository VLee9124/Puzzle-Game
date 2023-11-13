#include "../header/room.hpp"

Room::Room(string name) {
    this->roomName = name;
}

string Room::getAdjacentRooms() {
   
}

string Room::getAllObjects() {

}

string Room::getDesc() {
    return this->roomDesc;
}

string Room::getName() {
    return this->roomName;
}

void Room::removeObject(GameObject* targetObj) {
    auto it = find(this->objectList.begin(), this->objectList.end(), targetObj);
    if(it != this->objectList.end())
        this->objectList.erase(it);
}

void Room::addObject(GameObject* newObj) {
    this->objectList.push_back(newObj);
}

void Room::addDoor(Door* newDoor) {
    this->doorList.push_back(newDoor);
}