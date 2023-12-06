#pragma once

#include <string>
#include "gameObject.h"

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
        void interact(ostream& out, istream& in) override;
};