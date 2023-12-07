#include "gtest/gtest.h"

#include "../include/lockedObject.h"

// Test object constructor

TEST(ConstructorTests, testCreateConstructor)
{
  string name = "Lol1";
  string description = "Lol2";
  string interaction = "lol3";

  EXPECT_NO_THROW(lockedObject(name, description, interaction, nullptr));
}

TEST(ConstructorTests, testCreateConstructorEmptyStrings)
{
  string name = "";
  string description = "";
  string interaction = "";

  EXPECT_NO_THROW(lockedObject(name, description, interaction, nullptr));
}

// Test setLocked

TEST(setLockedTests, testSetUnlock)
{
  string name = "";
  string description = "";
  string interaction = "";

  lockedObject item(name, description, interaction, nullptr);
  item.setLocked(false);

  EXPECT_FALSE(item.getLocked());
}

TEST(setLockedTests, testSetLock)
{
  string name = "";
  string description = "";
  string interaction = "";

  lockedObject item(name, description, interaction, nullptr);

  item.setLocked(false);
  item.setLocked(true);

  EXPECT_TRUE(item.getLocked());
}

// Test getLocked

TEST(getLockedTests, testLocked)
{
  string name = "";
  string description = "";
  string interaction = "";

  lockedObject item(name, description, interaction, nullptr);

  EXPECT_TRUE(item.getLocked());
}

TEST(getLockedTests, testUnlocked)
{
  string name = "";
  string description = "";
  string interaction = "";

  lockedObject item(name, description, interaction, nullptr);

  item.setLocked(false);

  EXPECT_FALSE(item.getLocked());
}

// Test interact()

TEST(interactTests, testInteractSwitch)
{
  string name = "";
  string description = "Some description";
  string interaction = "Some interaction";

  lockedObject item(name, description, interaction, nullptr);

  item.interact();

  EXPECT_EQ(item.getDesc(), "Some interaction");
}

// Test runner

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}