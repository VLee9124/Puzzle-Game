#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include <vector>
#include <algorithm>
#include "gameObject.hpp"
#include "door.hpp"

class Room {
    private:
        vector<GameObject*> objectList;
        vector<Door*> doorList;
        string roomName;
        string roomDesc;
    public:
        Room(string name, string desc);
        vector<GameObject*> getAllObjects();
        vector<Door*> getAdjacentRooms();
        string getName();
        string getDesc();
        void addObject(GameObject* newObj);
        void removeObject(GameObject* targetObj);
        void addDoor(Door* newDoor);
};

#endif /* ROOM_HPP */