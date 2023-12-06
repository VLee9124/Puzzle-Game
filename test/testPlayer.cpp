#include <gtest/gtest.h>
#include <string>
#include <sstream>

#include "../include/player.hpp"
#include "../include/room.hpp"
#include "../include/door.hpp"
#include "../include/inventoryObject.hpp"

// Test the Player constructor
TEST(PlayerTest, Constructor) {
    Room* startRoom = new Room("StartRoom", "Starting Room Description");
    Player player(startRoom);

    EXPECT_EQ(player.getCurrRoom(), startRoom);
}

TEST(PlayerTest, ConstructorEmpty) {
    Room* startRoom = new Room("", "");
    Player empty(startRoom);

    EXPECT_NO_THROW(empty.getCurrRoom());
}

// Test for getCurrRoom
TEST(PlayerTest, GetCurrRoom) {
    Room* startRoom = new Room("Start Room", "This is the starting room");
    Player player(startRoom);

    EXPECT_EQ(player.getCurrRoom(), startRoom);
}
TEST(PlayerTest, GetCurrRoomDifferentStart) {
    Room* startRoom = new Room("Start Room", "This is the starting room");
    Room* anotherRoom = new Room("Another Room", "This is another room");

    Player player(anotherRoom);

    EXPECT_EQ(player.getCurrRoom(), anotherRoom);
}

// Test for setCurrRoom
TEST(PlayerTest, SetCurrRoom) {
    Room* startRoom = new Room("Start Room", "This is the starting room");
    Player player(startRoom);

    Room* newRoom = new Room("New Room", "This is a new room");
    player.setCurrRoom(newRoom);

    EXPECT_EQ(player.getCurrRoom(), newRoom);
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
}

// Test case for setCurrRoom with nullptr (edge case)
TEST(PlayerTest, SetCurrRoomNullptr) {
    Room* startRoom = new Room("Start Room", "This is the starting room");
    Player player(startRoom);

    player.setCurrRoom(nullptr);

    ASSERT_EQ(player.getCurrRoom(), nullptr);
}

// Test case for interacting with a closed door
TEST(PlayerTest, InteractWithClosedDoor) {
    Room* startRoom = new Room("Start Room", "This is the starting room");
    Room* adjacentRoom = new Room("Adjacent Room", "This is an adjacent room");
    Door* closedDoor = new Door("Closed Door", "A closed door", "Interaction message", adjacentRoom);

    Player player(startRoom);
    player.setCurrRoom(startRoom);

    player.interactWith(closedDoor);

    EXPECT_TRUE(closedDoor->getOpen());
}

// Test case for interacting with an open door
TEST(PlayerTest, InteractWithOpenDoor) {
    Room* startRoom = new Room("Start Room", "This is the starting room");
    Door* openDoor = new Door("Open Door", "A door that is already open", "Interaction message", startRoom);
    
    Player player(startRoom);
    player.setCurrRoom(startRoom);

    player.interactWith(openDoor);

    // Expect empty inventory 
    EXPECT_EQ(player.getInventory().itemCount(), 0);
}

// Test case for interacting with an inventory object
TEST(PlayerTest, InteractWithInventoryObject) {
    Room* startRoom = new Room("Start Room", "This is the starting room");
    inventoryObject* invObject = new inventoryObject("Item", "An item", "Interaction message", "Collection message");

    Player player(startRoom);
    player.setCurrRoom(startRoom);

    player.interactWith(invObject);

    // Expect the item to be collected 
    EXPECT_EQ(player.getInventory().itemCount(), 1);
    EXPECT_EQ(player.getInventory().getItemFromInventory(0), invObject);
}

// Test case for interacting with another inventory object
TEST(PlayerTest, InteractWithAnotherInventoryObject) {
    Room* startRoom = new Room("Start Room", "This is the starting room");
    inventoryObject* invObject1 = new inventoryObject("Item1", "An item", "Interaction message", "Collection message");
    inventoryObject* invObject2 = new inventoryObject("Item2", "Another item", "Interaction message", "Collection message");

    Player player(startRoom);
    player.setCurrRoom(startRoom);

    // Interact with the first object
    player.interactWith(invObject1);

    // Interact with another object
    player.interactWith(invObject2);

    EXPECT_EQ(player.getInventory().itemCount(), 2);
    EXPECT_EQ(player.getInventory().getItemFromInventory(0), invObject1);
    EXPECT_EQ(player.getInventory().getItemFromInventory(1), invObject2);
}

//Test for examine
TEST(PlayerTest, ExamineWithRoom) {
    // Create a room for testing
    Room* testRoom = new Room("Test Room", "This is a test room");

    // Implement room with objects
    gameObject* obj1 = new gameObject("Object1", "Description1", "Interaction1");
    testRoom->addObject(obj1);

    gameObject* obj2 = new gameObject("Object2", "Description2", "Interaction2");
    testRoom->addObject(obj2);

    Player player(nullptr);  // Initialize with nullptr, as the room will be set during the test

    ostringstream oss;
    player.examine(testRoom, oss);

    EXPECT_EQ(oss.str(), "You are in Test Room. This is a test room\n"
                         "Objects in the room:\n"
                         "1. Object1 - Description1\n"
                         "2. Object2 - Description2\n"
                         "There are no adjacent rooms.\n");
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}