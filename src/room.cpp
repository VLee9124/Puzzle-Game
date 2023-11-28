#include "../header/room.hpp"

Room::Room(string name, string desc) {
    this->roomName = name;
    this->roomDesc = desc;
}

vector<GameObject*> Room::getAllObjects() {
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

void Room::addObject(GameObject* newObj) {
    this->objectList.push_back(newObj);
}

void Room::removeObject(GameObject* targetObj) {
    GameObject* it = find(this->objectList.begin(), this->objectList.end(), targetObj);
    if(it != this->objectList.end())
        this->objectList.erase(it);
}

void Room::addDoor(Door* newDoor) {
    this->doorList.push_back(newDoor);
}