#include "gtest/gtest.h"
#include "../include/door.hpp"
#include "../include/room.hpp"

TEST(ClosedDoorTests, TestConstructor) {
    Room* room = new Room("name", "desc");
    Door* door = new Door("name", "desc", "interact", room);

    ASSERT_NO_THROW(room);
    EXPECT_NO_THROW(door);

    delete room;
    delete door;
}

TEST(OpenDoorTests, TestConstructor) {
    Room* room = new Room("name", "desc");
    Door* door = new Door("name", "desc", "interact", room, true);

    ASSERT_NO_THROW(room);
    EXPECT_NO_THROW(door);

    delete room;
    delete door;
}

TEST(OpenDoorTests, TestGetOpen) {
    Room* room = new Room("name", "desc");
    Door* door = new Door("name", "desc", "interact", room, true);

    EXPECT_TRUE(door->getOpen());

    delete room;
    delete door;
}

TEST(ClosedDoorTests, TestGetAdjRoom) {
    Room* room = new Room("name", "desc");
    Door* door = new Door("name", "desc", "interact", room);
    EXPECT_EQ(door->getAdjacentRoom(), room);
    delete room;
    delete door;
}
TEST(ClosedDoorTests, TestSetGetOpenTrue) {
    Room* room = new Room("name", "desc");
    Door* door = new Door("name", "desc", "interact", room);
    door->setOpen(true);
    EXPECT_TRUE(door->getOpen());
    delete room;
    delete door;
}
TEST(ClosedDoorTests, TestSetGetOpenFalse) {
    Room* room = new Room("name", "desc");
    Door* door = new Door("name", "desc", "interact", room);
    EXPECT_FALSE(door->getOpen());
    delete room;
    delete door;
}
TEST(ClosedDoorTests, TestInteract) {
    ostringstream oss;
    istringstream iss;
    Room* room = new Room("name", "desc");
    Door* door = new Door("name", "desc", "interact", room);
    door->interact(oss, iss);

    EXPECT_TRUE(door->getOpen());
    EXPECT_EQ(oss.str(), "You opened the door and gained access to the adjacent room\n\n");

    delete room;
    delete door;
}

TEST(OpenDoorTests, TestInteract) {
    ostringstream oss;
    istringstream iss;
    Room* room = new Room("name", "desc");
    Door* door = new Door("name", "desc", "interact", room, true);
    door->interact(oss, iss);

    EXPECT_TRUE(door->getOpen());
    EXPECT_EQ(oss.str(), "The door is already opened\n\n");

    delete room;
    delete door;
}