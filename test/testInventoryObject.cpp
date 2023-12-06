#include "gtest/gtest.h"
#include <sstream>

#include "../include/inventoryObject.hpp"

TEST(InventoryObjectTests, TestConstructor) {
  inventoryObject* objectA = new inventoryObject("Object A", "This is object A", "You changed object A", "You collected object A");
  EXPECT_NO_THROW(objectA);
  delete objectA;
}

TEST(InventoryObjectTests, TestGetMessage) {
  inventoryObject* objectA = new inventoryObject("Object A", "This is object A", "You changed object A", "You collected object A");

  EXPECT_EQ(objectA->getCollectMsg(), "You collected object A");

  delete objectA;
}

TEST(InventoryObjectTests, TestCollect) {
  ostringstream oss;
  inventoryObject* objectA = new inventoryObject("Object A", "This is object A", "You changed object A", "You collected object A");

  objectA->collect(oss);
  EXPECT_TRUE(objectA->checkIfCollected());
  EXPECT_EQ(oss.str(), "You collected object A\n\n");

  delete objectA;
}

TEST(InventoryObjectTests, TestInteract) {
  ostringstream oss;
  istringstream iss;
  inventoryObject* objectA = new inventoryObject("Object A", "This is object A", "You changed object A", "You collected object A");

  objectA->interact(oss, iss);
  EXPECT_TRUE(objectA->checkIfCollected());
  EXPECT_EQ(oss.str(), "You collected object A\n\n");
  EXPECT_EQ(objectA->getDesc(), objectA->getInteraction());

  delete objectA;
}