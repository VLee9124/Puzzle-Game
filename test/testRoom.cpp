#include "gtest/gtest.h"
#include "../include/room.hpp"

TEST(RoomConstructorTests, TestName) {
    Room* room = new Room("name", "desc");
    EXPECT_EQ(room->getName(), "name");
    delete room;
}
TEST(RoomConstructorTests, TestDesc) {
    Room* room = new Room("name", "desc");
    EXPECT_EQ(room->getDesc(), "desc");
    delete room;
}

TEST(RoomObjectTests, TestAddObject) {
    Room* room = new Room("name", "desc");
    gameObject* newObj = new gameObject("name", "desc", "interaction");
    room->addObject(newObj);
    EXPECT_EQ(room->getObject(0), newObj);
    delete room;
    delete newObj;
}
TEST(RoomObjectTests, TestRemoveObject) {
    Room* room = new Room("name", "desc");
    gameObject* newObj = new gameObject("name", "desc", "interaction");
    room->addObject(newObj);
    gameObject* targetObj = newObj;
    room->removeObject(0);
    EXPECT_TRUE(room->emptyRoom());
    delete room;
}

TEST(RoomDoorTests, TestAddDoor) {
    Room* room = new Room("name", "desc");
    Door* newDoor = new Door("name", "desc", "interaction", room);
    room->addObject(newDoor);
    EXPECT_EQ(room->getObject(0), newDoor);
    delete room;
    delete newDoor;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}