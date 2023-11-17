#pragma once

#include <string>
#include <vector>

using namespace std;

class gameObject
{
private:
  string name;
  string description;
  string interaction;

public:
  gameObject(string name, string description, string interaction);

  string getName();
  string getDesc();
  string getInteraction();

  void setName();
  void setDesc();
  void setInteraction();

  void interact();
};

class InventoryObject : public gameObject
{
private:
  string collectionMessage;

public:
  InventoryObject(string name, string description, string interaction, string collectionMessage);
  void interact() override;
  void collect();
};