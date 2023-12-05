#include "gtest/gtest.h"

#include "../include/gameObject.hpp"

// Constructor tests

TEST(ConstructorTests, testNormalStrings)
{
  string name = "Note";
  string description = "An old piece of paper lies in the corner of the room.";
  string interaction = "The paper contains light markings of the number 12481";

  EXPECT_NO_THROW(gameObject(name, description, interaction));
}

TEST(ConstructorTests, testEmptyStrings)
{
  string name = "";
  string description = "";
  string interaction = "";

  EXPECT_NO_THROW(gameObject(name, description, interaction));
}

TEST(ConstructorTests, testLongStrings)
{
  string name = "Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah";
  string description = "Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah";
  string interaction = "Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah Blah blah blah blah";

  EXPECT_NO_THROW(gameObject(name, description, interaction));
}

// Getter tests

TEST(GetNameTests, testName)
{
  string name = "Ultraviolet light";
  string description = "";
  string interaction = "";

  gameObject item(name, description, interaction);

  EXPECT_EQ(item.getName(), name);
}

TEST(GetNameTests, testEmptyName)
{
  string name = "";
  string description = "";
  string interaction = "";

  gameObject item(name, description, interaction);

  EXPECT_EQ(item.getName(), name);
}

TEST(GetNameTests, testLongName)
{
  string name = "This object has a very long name that exceeds the typical length of an object name";
  string description = "";
  string interaction = "";

  gameObject item(name, description, interaction);

  EXPECT_EQ(item.getName(), name);
}

TEST(GetNameTests, testSpecialCharactersName)
{
  string name = "~!@#$%^&*()-+_={}";
  string description = "";
  string interaction = "";

  gameObject item(name, description, interaction);

  EXPECT_EQ(item.getName(), name);
}

TEST(GetDescriptionTests, testDescription)
{
  string name = "";
  string description = "An odd-looking book stands out amongst the other books in the bookshelf.";
  string interaction = "";

  gameObject item(name, description, interaction);

  EXPECT_EQ(item.getDesc(), description);
}

TEST(GetDescriptionTests, testEmptyDescription)
{
  string name = "";
  string description = "";
  string interaction = "";

  gameObject item(name, description, interaction);

  EXPECT_EQ(item.getDesc(), description);
}

TEST(GetInteractionTests, testInteraction)
{
  string name = "";
  string description = "";
  string interaction = "Some interactive message here";

  gameObject item(name, description, interaction);

  EXPECT_EQ(item.getInteraction(), interaction);
}

TEST(GetInteractionTests, testEmptyInteraction)
{
  string name = "";
  string description = "";
  string interaction = "";

  gameObject item(name, description, interaction);

  EXPECT_EQ(item.getInteraction(), interaction);
}

// Setter tests

TEST(SetNameTests, setName)
{
  string name = "Margaritaville CD";
  string description = "Some description here.";
  string interaction = "Some interaction here.";

  gameObject item(name, description, interaction);

  string newName = "YOASOBI Vinyl";
  item.setName(newName);

  EXPECT_EQ(item.getName(), newName);
}

TEST(SetNameTests, setNameToEmpty)
{
  string name = "Margaritaville CD";
  string description = "Some description here.";
  string interaction = "Some interaction here.";

  gameObject item(name, description, interaction);
  item.setName("");

  EXPECT_EQ(item.getName(), "");
}

TEST(SetDescriptionTests, setDescription)
{
  string name = "Some name here.";
  string description = "Some description here.";
  string interaction = "Some interaction here.";

  gameObject item(name, description, interaction);

  string newDescription = "A small mirror gleams from the corner of the room.";
  item.setDesc(newDescription);

  EXPECT_EQ(item.getDesc(), newDescription);
}

TEST(SetDescriptionTests, setDescriptionToEmpty)
{
  string name = "Some name here.";
  string description = "Some description here.";
  string interaction = "Some interaction here.";

  gameObject item(name, description, interaction);
  item.setDesc("");

  EXPECT_EQ(item.getDesc(), "");
}

TEST(SetInteractionTests, setInteraction)
{
  string name = "Some name here.";
  string description = "Some description here.";
  string interaction = "Some interaction here.";

  gameObject item(name, description, interaction);

  string newInteraction = "Upon closer examination, you notice text that reads: It was my fate, my fate grand order";
  item.setInteraction(newInteraction);

  EXPECT_EQ(item.getInteraction(), newInteraction);
}

TEST(SetInteractionTests, setInteractionEmpty)
{
  string name = "Some name here.";
  string description = "Some description here.";
  string interaction = "Some interaction here.";

  gameObject item(name, description, interaction);
  item.setInteraction("");

  EXPECT_EQ(item.getInteraction(), "");
}

// Interact tests

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}