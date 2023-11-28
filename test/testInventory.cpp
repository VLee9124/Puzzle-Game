#include "gtest/gtest.h"
#include "../include/inventory.hpp"
#include <string>

using namespace std;

// Testing if the constructor works
TEST(Constructor, TestDefaultConstructor) {
    inventory myInventory;

    EXPECT_NO_THROW(myInventory);
}

TEST(InventoryContents, TestInventoryNoItems) {
    inventory myInventory;
    vector<inventoryObject*> expectedObjs;

    ASSERT_NO_THROW(myInventory);
    EXPECT_EQ(myInventory.getInventoryContents(), expectedObjs);
}

// Tests the contents of the inventory if it has one item
TEST(InventoryContents, TestInventoryOneItem) {
    inventory myInventory;
    inventoryObject* Book = new inventoryObject("Clue Book", "An unopened book. What could be written inside?", "After opening the book you collected, you find that the first page reads '1294'.", "You picked up the book.");
    vector<inventoryObject*> expectedObjs;

    ASSERT_NO_THROW(myInventory);
    ASSERT_NO_THROW(Book);

    Book->interact();
    myInventory.addItem(Book);
    expectedObjs.push_back(Book);

    EXPECT_NO_THROW(myInventory.getInventoryContents());

    EXPECT_EQ(myInventory.getInventoryContents(), expectedObjs);
}

// Tests the contents of the inventory if it has multiple objects
TEST(InventoryContents, TestInventoryMultipleItems) {
    inventory myInventory;
    inventoryObject* Book = new inventoryObject("Clue Book", "An unopened book. What could be written inside?", "After opening the book you collected, you find that the first page reads '1294'.", "You picked up the book.");
    inventoryObject* Note = new inventoryObject("Faded Note", "A crumpled note.", "After uncrumpling the note you have, you read the note, which reads: '444-444-4444'.", "You picked up a note with scribbled writing on it.");
    vector<inventoryObject*> expectedObjs;

    ASSERT_NO_THROW(myInventory);
    ASSERT_NO_THROW(Book);
    ASSERT_NO_THROW(Note);

    Book->interact();
    myInventory.addItem(Book);
    expectedObjs.push_back(Book);
    
    Note->interact();
    myInventory.addItem(Note);
    expectedObjs.push_back(Note);

    EXPECT_NO_THROW(myInventory.getInventoryContents());

    EXPECT_EQ(myInventory.getInventoryContents(), expectedObjs);
}

// Tests printing out the first item's description
TEST(ItemDescription, TestItemDescriptionIndexZero) {
    inventory myInventory;
    inventoryObject* Note = new inventoryObject("Faded Note", "A crumpled note.", "After uncrumpling the note you have, you read the note, which reads: '444-444-4444'.", "You picked up a note with scribbled writing on it.");
    
    ASSERT_NO_THROW(myInventory);
    ASSERT_NO_THROW(Note);

    Note->interact();
    myInventory.addItem(Note);

    EXPECT_NO_THROW(myInventory.getItemDescription(0));

    string expectedOutput = "After uncrumpling the note you have, you read the note, which reads: '444-444-4444'.";
    EXPECT_EQ(myInventory.getItemDescription(0), expectedOutput);
}

// Tests printing out any item's description given an index
TEST(ItemDescription, TestItemDescriptionIndexNonzero) {
    inventory myInventory;
    inventoryObject* Bottle = new inventoryObject("Water Bottle", "A closed 500 mL water bottle.", "A 500mL water bottle you collected. It appears to be halfway full.", "You picked up the bottle.");
    inventoryObject* RedCoin = new inventoryObject("Red Coin", "A small red coin with some writing on it.", "A small red coin you picked up. It reads '4' on one side and 'D' on the other.", "You picked up the red coin.");
    inventoryObject* GreenCoin = new inventoryObject("Green Coin", "A small green coin with some writing on it.", "A small red coin you picked up. It reads '9' on one side and 'F' on the other.", "You picked up the green coin.");

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

TEST(ItemDescription, TestItemDescriptionOutOfRange) {
    inventory myInventory;

    EXPECT_THROW(myInventory.getItemDescription(0), runtime_error);
}

TEST(GetItem, OneItemInInventory) {
    inventory myInventory;
    inventoryObject* Bottle = new inventoryObject("Water Bottle", "A closed 500 mL water bottle.", "A 500mL water bottle you collected. It appears to be halfway full.", "You picked up the bottle.");

    ASSERT_NO_THROW(myInventory);
    ASSERT_NO_THROW(Bottle);

    Bottle->interact();
    myInventory.addItem(Bottle);

    EXPECT_EQ(myInventory.getItemFromInventory(0), Bottle);
}

TEST(GetItem, MultipleItemsInInventory) {
    inventory myInventory;
    inventoryObject* RedCoin = new inventoryObject("Red Coin", "A small red coin with some writing on it.", "A small red coin you picked up. It reads '4' on one side and 'D' on the other.", "You picked up the red coin.");
    inventoryObject* GreenCoin = new inventoryObject("Green Coin", "A small green coin with some writing on it.", "A small red coin you picked up. It reads '9' on one side and 'F' on the other.", "You picked up the green coin.");

    RedCoin->interact();
    myInventory.addItem(RedCoin);

    GreenCoin->interact();
    myInventory.addItem(GreenCoin);

    EXPECT_EQ(myInventory.getItemFromInventory(1), GreenCoin);
}

TEST(GetItem, OutOfRangeError) {
    inventory myInventory;
    inventoryObject* RedCoin = new inventoryObject("Red Coin", "A small red coin with some writing on it.", "A small red coin you picked up. It reads '4' on one side and 'D' on the other.", "You picked up the red coin.");
    inventoryObject* GreenCoin = new inventoryObject("Green Coin", "A small green coin with some writing on it.", "A small red coin you picked up. It reads '9' on one side and 'F' on the other.", "You picked up the green coin.");

    RedCoin->interact();
    myInventory.addItem(RedCoin);

    GreenCoin->interact();
    myInventory.addItem(GreenCoin);

    EXPECT_THROW(myInventory.getItemFromInventory(3), runtime_error);
}

TEST(RemoveItem, RemoveOnlyItem) {
    inventory myInventory;
    inventoryObject* Book = new inventoryObject("Clue Book", "An unopened book. What could be written inside?", "After opening the book you collected, you find that the first page reads '1294'.", "You picked up the book.");

    Book->interact();
    myInventory.addItem(Book);

    EXPECT_EQ(myInventory.itemCount(), 1);

    myInventory.removeItem(0);

    EXPECT_EQ(myInventory.itemCount(), 0);
}

TEST(RemoveItem, RemoveMultipleItems) {
    inventory myInventory;
    inventoryObject* Bottle = new inventoryObject("Water Bottle", "A closed 500 mL water bottle.", "A 500mL water bottle you collected. It appears to be halfway full.", "You picked up the bottle.");
    inventoryObject* RedCoin = new inventoryObject("Red Coin", "A small red coin with some writing on it.", "A small red coin you picked up. It reads '4' on one side and 'D' on the other.", "You picked up the red coin.");
    inventoryObject* GreenCoin = new inventoryObject("Green Coin", "A small green coin with some writing on it.", "A small red coin you picked up. It reads '9' on one side and 'F' on the other.", "You picked up the green coin.");

    Bottle->interact();
    myInventory.addItem(Bottle);

    RedCoin->interact();
    myInventory.addItem(RedCoin);

    GreenCoin->interact();
    myInventory.addItem(GreenCoin);

    EXPECT_EQ(myInventory.itemCount(), 3);

    myInventory.removeItem(0);
    myInventory.removeItem(0);

    EXPECT_EQ(myInventory.itemCount(), 1);
    EXPECT_EQ(myInventory.getItemFromInventory(0), GreenCoin);
}

TEST(RemoveItem, UnderflowError) {
    inventory myInventory;

    EXPECT_THROW(myInventory.removeItem(0), runtime_error);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}