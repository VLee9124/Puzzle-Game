#include "gtest/gtest.h"

#include "../include/lockedObject.hpp"

// Test object constructor

TEST(LockedObjTests, CreateConstructorNoPuzzle)
{
  string name = "Lol1";
  string description = "Lol2";
  string interaction = "lol3";

  EXPECT_NO_THROW(lockedObject(name, description, interaction, nullptr));
}

TEST(LockedObjTests, CreateConstructorWithPuzzle)
{
  string name = "Lol1";
  string description = "Lol2";
  string interaction = "lol3";

  EXPECT_NO_THROW(lockedObject(name, description, interaction, new KeypadPuzzle("Enter a number", 12)));
}

TEST(LockedObjTests, CreateConstructorEmptyStrings)
{
  string name = "";
  string description = "";
  string interaction = "";

  EXPECT_NO_THROW(lockedObject(name, description, interaction, nullptr));
}

// Test setLocked

TEST(LockedObjTests, SetUnlock)
{
  string name = "";
  string description = "";
  string interaction = "";

  lockedObject item(name, description, interaction, nullptr);
  item.setLocked(false);

  EXPECT_FALSE(item.getLocked());
}

TEST(LockedObjTests, SetLock)
{
  string name = "";
  string description = "";
  string interaction = "";

  lockedObject item(name, description, interaction, nullptr);

  item.setLocked(false);
  item.setLocked(true);

  EXPECT_TRUE(item.getLocked());
}

// Test interact()

TEST(LockedObjTests, InteractWithNoPuzzle)
{
  ostringstream oss;
  istringstream iss;
  string name = "";
  string description = "Some description";
  string interaction = "Some interaction";

  lockedObject item(name, description, interaction, nullptr);

  item.interact(oss, iss);

  EXPECT_EQ(item.getDesc(), "Some description");
}

TEST(LockedObjTests, InteractWithPuzzleCorrect)
{
  ostringstream oss;
  istringstream iss("1234");
  string name = "Locked Object";
  string description = "Some description";
  string interaction = "Some interaction";

  lockedObject item(name, description, interaction, new KeypadPuzzle("Enter a four digit number.", 1234));

  item.interact(oss, iss);

  EXPECT_EQ(item.getDesc(), "Some interaction");
  EXPECT_FALSE(item.getLocked());
  EXPECT_EQ(oss.str(), "Enter a four digit number.\n\n> \n\nCORRECT. The puzzle is now solved.\n\nThe object is now unlocked.\n\n");
}

TEST(LockedObjTests, InteractWithPuzzleIncorrect)
{
  ostringstream oss;
  istringstream iss("5678");
  string name = "Locked Object";
  string description = "Some description";
  string interaction = "Some interaction";

  lockedObject item(name, description, interaction, new KeypadPuzzle("Enter a four digit number.", 1234));

  item.interact(oss, iss);

  EXPECT_EQ(item.getDesc(), "Some description");
  EXPECT_TRUE(item.getLocked());
  EXPECT_EQ(oss.str(), "Enter a four digit number.\n\n> \n\nINCORRECT. The puzzle remains unsolved.\n\nThe object is still locked.\n\n");
}