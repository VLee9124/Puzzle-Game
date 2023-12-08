#include "gtest/gtest.h"
#include "../include/lockedDoor.hpp"
#include "../include/room.hpp"
#include <sstream>
using namespace std;

TEST(LockedDoorTests, ConstructorNullParameters) {
    Door* myLockedDoor = new lockedDoor("Door to Escape", "A closed door that leads to the exit.", "An open door to the exit.", nullptr, nullptr);

    ASSERT_NO_THROW(myLockedDoor);

    delete myLockedDoor;
}

TEST(LockedDoorTests, ConstructorWithParameters) {
    Room* room1 = new Room("First Room", "The start of your journey.");
    Room* room2 = new Room("Second Room", "The next stop of your journey.");
    Door* myLockedDoor = new lockedDoor("Door to Escape", "A closed door that leads to the exit.", "An open door to the exit.", new KeypadPuzzle("Enter a four digit number.", 1111), room2);

    ASSERT_NO_THROW(myLockedDoor);

    delete myLockedDoor;
    delete room1;
    delete room2;
}

TEST(LockedDoorTests, SetOpen) {
    Room* room1 = new Room("First Room", "The start of your journey.");
    Room* room2 = new Room("Second Room", "The next stop of your journey.");
    Door* myLockedDoor = new lockedDoor("Door to Escape", "A closed door that leads to the exit.", "An open door to the exit.", new KeypadPuzzle("Enter a four digit number.", 1111), room2);

    myLockedDoor->setOpen(true);

    EXPECT_TRUE(myLockedDoor->getOpen());

    delete myLockedDoor;
    delete room1;
    delete room2;
}

TEST(LockedDoorTests, UnlockSuccessful) {
    ostringstream oss;
    istringstream iss("1111");
    Room* room1 = new Room("First Room", "The start of your journey.");
    Room* room2 = new Room("Second Room", "The next stop of your journey.");
    lockedDoor* myLockedDoor = new lockedDoor("Door to Escape", "A closed door that leads to the exit.", "An open door to the exit.", new KeypadPuzzle("Enter a four digit number.", 1111), room2);

    myLockedDoor->unlock(oss, iss);
    EXPECT_TRUE(myLockedDoor->getOpen());
    EXPECT_FALSE(myLockedDoor->getLocked());
    EXPECT_EQ(oss.str(), "Enter a four digit number.\n\n> \n\nCORRECT. The puzzle is now solved.\n\nYou unlocked the door and gained access to the adjacent room.\n\n");

    delete myLockedDoor;
    delete room1;
    delete room2;
}

TEST(LockedDoorTests, UnlockFailed) {
    ostringstream oss;
    istringstream iss("1337");
    Room* room1 = new Room("First Room", "The start of your journey.");
    Room* room2 = new Room("Second Room", "The next stop of your journey.");
    lockedDoor* myLockedDoor = new lockedDoor("Door to Escape", "A closed door that leads to the exit.", "An open door to the exit.", new KeypadPuzzle("Enter a four digit number.", 1111), room2);

    myLockedDoor->unlock(oss, iss);
    EXPECT_FALSE(myLockedDoor->getOpen());
    EXPECT_TRUE(myLockedDoor->getLocked());
    EXPECT_EQ(oss.str(), "Enter a four digit number.\n\n> \n\nINCORRECT. The puzzle remains unsolved.\n\nThe door is still locked.\n\n");

    delete myLockedDoor;
    delete room1;
    delete room2;
}

TEST(LockedDoorTests, InteractSolved) {
    ostringstream oss;
    istringstream iss("1111");
    Room* room1 = new Room("First Room", "The start of your journey.");
    Room* room2 = new Room("Second Room", "The next stop of your journey.");
    Door* myLockedDoor = new lockedDoor("Door to Escape", "A closed door that leads to the exit.", "An open door to the exit.", new KeypadPuzzle("Enter a four digit number.", 1111), room2);

    myLockedDoor->interact(oss, iss);
    EXPECT_TRUE(myLockedDoor->getOpen());
    EXPECT_EQ(myLockedDoor->getDesc(), myLockedDoor->getInteraction());
    EXPECT_EQ(oss.str(), "Enter a four digit number.\n\n> \n\nCORRECT. The puzzle is now solved.\n\nYou unlocked the door and gained access to the adjacent room.\n\n");

    delete myLockedDoor;
    delete room1;
    delete room2;
}

TEST(LockedDoorTests, InteractUnsolved) {
    ostringstream oss;
    istringstream iss("1337");
    Room* room1 = new Room("First Room", "The start of your journey.");
    Room* room2 = new Room("Second Room", "The next stop of your journey.");
    Door* myLockedDoor = new lockedDoor("Door to Escape", "A closed door that leads to the exit.", "An open door to the exit.", new KeypadPuzzle("Enter a four digit number.", 1111), room2);

    myLockedDoor->interact(oss, iss);
    EXPECT_FALSE(myLockedDoor->getOpen());
    EXPECT_EQ(myLockedDoor->getDesc(), "A closed door that leads to the exit.");
    EXPECT_EQ(oss.str(), "Enter a four digit number.\n\n> \n\nINCORRECT. The puzzle remains unsolved.\n\nThe door is still locked.\n\n");

    delete myLockedDoor;
    delete room1;
    delete room2;
}