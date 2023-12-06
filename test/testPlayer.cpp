#include <gtest/gtest.h>
#include "../include/Player.h"
#include <string>
#include <sstream>

// Test the Player constructor
TEST(PlayerTest, Constructor) {
    Room* startRoom = new Room("StartRoom", "Starting Room Description");
    Player player(startRoom);

    EXPECT_EQ(player.getCurrRoom(), startRoom);
    delete startRoom;
}

TEST(PlayerTest, ConstructorEmpty) {
    Room* startRoom = new Room("", "");
    Player empty(startRoom);

    EXPECT_NO_THROW(empty.getCurrRoom());
    delete startRoom;
}

// Test for getCurrRoom
TEST(PlayerTest, GetCurrRoom) {
    Room* startRoom = new Room("Start Room", "This is the starting room");
    Player player(startRoom);

    EXPECT_EQ(player.getCurrRoom(), startRoom);
    delete startRoom;
}

TEST(PlayerTest, GetCurrRoomDifferentStart) {
    Room* startRoom = new Room("Start Room", "This is the starting room");
    Room* anotherRoom = new Room("Another Room", "This is another room");

    Player player(anotherRoom);

    EXPECT_EQ(player.getCurrRoom(), anotherRoom);
    delete startRoom;
    delete anotherRoom;
}

// Test for setCurrRoom
TEST(PlayerTest, SetCurrRoom) {
    Room* startRoom = new Room("Start Room", "This is the starting room");
    Player player(startRoom);

    Room* newRoom = new Room("New Room", "This is a new room");
    player.setCurrRoom(newRoom);

    EXPECT_EQ(player.getCurrRoom(), newRoom);
    delete startRoom;
    delete newRoom;
}

TEST(PlayerTest, SetCurrRoomMultipleChanges) {
    Room* startRoom = new Room("Start Room", "This is the starting room");
    Room* room1 = new Room("Room 1", "Living Room");
    Room* room2 = new Room("Room 2", "Restroom");

    Player player(startRoom);

    player.setCurrRoom(room1);
    EXPECT_EQ(player.getCurrRoom(), room1);

    player.setCurrRoom(room2);
    EXPECT_EQ(player.getCurrRoom(), room2);
    delete startRoom;
    delete room1;
    delete room2;
}

// Test case for setCurrRoom with nullptr (edge case)
TEST(PlayerTest, SetCurrRoomNullptr) {
    Room* startRoom = new Room("Start Room", "This is the starting room");
    Player player(startRoom);

    player.setCurrRoom(nullptr);

    ASSERT_EQ(player.getCurrRoom(), nullptr);
    delete startRoom;
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}