#include "gtest/gtest.h"
#include "../header/room.hpp"

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
    GameObject* newObj = new GameObject("name", "desc", "interaction");
    room.addObject(newObj);
    EXPECT_EQ(room->objectList[0], newObj);
    delete room;
    delete newObj;
}
TEST(RoomObjectTests, TestRemoveObject) {
    Room* room = new Room("name", "desc");
    GameObject* newObj = new GameObject("name", "desc", "interaction");
    room.addObject(newObj);
    GameObject* targetObj = newObj;
    room.removeObject(targetObj);
    EXPECT_TRUE(room->objectList.empty());
    delete room;
    delete newObj;
}

TEST(RoomDoorTests, TestAddDoor) {
    Room* room = new Room("name", "desc");
    Door* newDoor = new Door(room);
    EXPECT_EQ(room->doorList[0], newDoor);
    delete room;
    delete newDoor;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}