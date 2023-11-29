#ifndef DOOR_HPP
#define DOOR_HPP

#include <string>
#include "gameObject.hpp"

class Room;

class Door : public gameObject {
    private:
        Room* adjacentRoom;
        bool isOpen;
    public:
        Door(Room* adjRoom);
        Room* getAdjacentRoom();
        void setOpen(bool val);
        bool getOpen();
        void interact() override;
};

#endif /* DOOR_HPP */