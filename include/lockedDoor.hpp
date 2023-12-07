#pragma once

#include "door.hpp"
#include "lockedObject.hpp"
using namespace std;

class lockedDoor : public Door, public lockedObject {
    public:
        lockedDoor(string, string, string, Puzzle*, Room*);
        void interact(ostream&, istream&) override;
        void unlock(ostream&, istream&) override;
};