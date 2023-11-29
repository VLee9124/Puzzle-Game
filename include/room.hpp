#pragma once

#include "gameObject.h"
#include "door.hpp"
#include <algorithm>
#include <stdexcept>

class Room {
    private:
        vector<gameObject*> objectList;
        vector<Door*> doorList;
        string roomName;
        string roomDesc;
    public:
        Room(string name, string desc);
        vector<Door*> getAdjacentRooms();
        vector<gameObject*> getAllObjects();
        string getDesc();
        string getName();
        gameObject* getObject(int index);
        bool emptyRoom();
        void removeObject(int itemIndex);
        void addObject(gameObject* newObj);
        void addDoor(Door* newDoor);
};