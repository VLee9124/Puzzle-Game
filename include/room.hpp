#pragma once

#include <vector>
#include <stdexcept>
#include "gameObject.hpp"
#include "door.hpp"

using namespace std;

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