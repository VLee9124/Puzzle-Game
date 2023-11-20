#include "gtest/gtest.h"
#include "../include/Inventory.hpp"
using namespace std;

// Testing if the constructor works
TEST(Inventory, TestConstructor) {
    Inventory myInventory;

    EXPECT_NO_THROW(myInventory);
}

TEST(Inventory, TestInventoryNoItems) {
    Inventory myInventory;

    ASSERT_NO_THROW(myInventory);
    EXPECT_EQ(myInventory.getInventoryContents(), "");
}

// Tests the contents of the inventory if it has one item
TEST(Inventory, TestInventoryOneItem) {
    Inventory myInventory;
    inventoryObject* Book = new inventoryObject("Clue Book", "An unopened book. What could be written inside?", "After opening the book you collected, you find that the first page reads '1294'.");

    ASSERT_NO_THROW(myInventory);
    ASSERT_NO_THROW(Book);

    Book->interact();
    myInventory.addItem(Book);

    EXPECT_NO_THROW(myInventory.getInventoryContents());

    string expectedOutput = "1. Clue Book\n";
    EXPECT_EQ(myInventory.getInventoryContents(), expectedOutput);
}

// Tests the contents of the inventory if it has multiple objects
TEST(Inventory, TestInventoryMultipleItems) {
    Inventory myInventory;
    inventoryObject* Book = new inventoryObject("Clue Book", "An unopened book. What could be written inside?", "After opening the book you collected, you find that the first page reads '1294'.");
    inventoryObject* Note = new inventoryObject("Faded Note", "A crumpled note.", "After uncrumpling the note you have, you read the note, which reads: '444-444-4444'.");

    ASSERT_NO_THROW(myInventory);
    ASSERT_NO_THROW(Book);
    ASSERT_NO_THROW(Note);

    Book->interact();
    myInventory.addItem(Book);
    
    Note->interact();
    myInventory.addItem(Note);

    EXPECT_NO_THROW(myInventory.getInventoryContents());

    string expectedOutput = "1. Clue Book\n2. Faded Note\n";
    EXPECT_EQ(myInventory.getInventoryContents(), expectedOutput);
}

// Tests printing out the first item's description
TEST(Inventory, TestItemDescriptionIndexZero) {
    Inventory myInventory;
    inventoryObject* Note = new inventoryObject("Faded Note", "A crumpled note.", "After uncrumpling the note you have, you read the note, which reads: '444-444-4444'.");
    
    ASSERT_NO_THROW(myInventory);
    ASSERT_NO_THROW(Note);

    Note->interact();
    myInventory.addItem(Note);

    EXPECT_NO_THROW(myInventory.getItemDescription(0));

    string expectedOutput = "After uncrumpling the note you have, you read the note, which reads: '444-444-4444'.";

    EXPECT_EQ(myInventory.getItemDescription(0), expectedOutput);
}

// Tests printing out any item's description given an index
TEST(Inventory, TestItemDescriptionIndexNonzero) {
    Inventory myInventory;
    inventoryObject* Bottle = new inventoryObject("Water Bottle", "A closed 500 mL water bottle.", "A 500mL water bottle you collected. It appears to be halfway full.");
    inventoryObject* RedCoin = new inventoryObject("Red Coin", "A small red coin with some writing on it.", "A small red coin you picked up. It reads '4' on one side and 'D' on the other.");
    inventoryObject* GreenCoin = new inventoryObject("Green Coin", "A small green coin with some writing on it.", "A small red coin you picked up. It reads '9' on one side and 'F' on the other.");

    ASSERT_NO_THROW(myInventory);
    ASSERT_NO_THROW(Bottle);
    ASSERT_NO_THROW(RedCoin);
    ASSERT_NO_THROW(GreenCoin);

    Bottle->interact();
    myInventory.addItem(Bottle);

    RedCoin->interact();
    myInventory.addItem(RedCoin);

    GreenCoin->interact();
    myInventory.addItem(GreenCoin);
    
    EXPECT_NO_THROW(myInventory.getItemDescription(2));

    string expectedOutput = "A small red coin you picked up. It reads '9' on one side and 'F' on the other.";

    EXPECT_EQ(myInventory.getItemDescription(2), expectedOutput);
}

TEST(Inventory, TestItemDescriptionOutOfRange) {
    Inventory myInventory;

    EXPECT_THROW(myInventory.getItemDescription(0), std::runtime_error);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}