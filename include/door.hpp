#pragma once

#include <string>
#include "gameObject.hpp"

using namespace std;

class Room;

class Door : public gameObject{
    private:
        Room* adjacentRoom;
        bool isOpen;
    public:
        Door(string, string, string, Room*);
        Room* getAdjacentRoom();
        void setOpen(bool val);
        bool getOpen();
        void interact() override;
};