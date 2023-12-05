#include "gtest/gtest.h"
#include "../include/door.hpp"
#include "../include/room.hpp"

TEST(DoorFunctionTests, TestGetAdjRoom) {
    Room* room = new Room("name", "desc");
    Door* door = new Door("name", "desc", "interact", room);
    EXPECT_EQ(door->getAdjacentRoom(), room);
    delete room;
    delete door;
}
TEST(DoorFunctionTests, TestSetGetOpenTrue) {
    Room* room = new Room("name", "desc");
    Door* door = new Door("name", "desc", "interact", room);
    door->setOpen(true);
    EXPECT_EQ(door->getOpen(), true);
    delete room;
    delete door;
}
TEST(DoorFunctionTests, TestSetGetOpenFalse) {
    Room* room = new Room("name", "desc");
    Door* door = new Door("name", "desc", "interact", room);
    door->setOpen(false);
    EXPECT_EQ(door->getOpen(), false);
    delete room;
    delete door;
}
TEST(DoorFunctionTests, TestInteract) {
    Room* room = new Room("name", "desc");
    Door* door = new Door("name", "desc", "interact", room);
    door->setOpen(false);
    door->interact();
    EXPECT_EQ(door->getOpen(), true);
    delete room;
    delete door;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}