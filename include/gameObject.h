#pragma once

#include <string>
#include <vector>

/*General abstract object that can be interacted with. This item cannot be collected.*/
class gameObject
{
private:
  std::string name;
  std::string description;
  std::string interaction;

public:
  gameObject(std::string name, std::string description, std::string interaction);

  // Getters and setters
  std::string getName() { return name; }
  std::string getDescription() { return description; }
  std::string getInteraction() { return interaction; }
  void setName(std::string s) { name = s; }
  void setDescription(std::string s) { description = s; }
  void setInteraction(std::string s) { interaction = s; }

  // Game object functions
  virtual void interact() = 0;
};

/*An interactable object that can be collected and stored in the inventory.*/
class inventoryObject : public gameObject
{
private:
  bool collected = false;
  std::string collectionMessage;

public:
  inventoryObject(std::string name, std::string description, std::string interaction);

  // Getters and setters
  std::string getCollectionMessage() { return collectionMessage; }
  void setCollectionMessage(std::string s) { collectionMessage = s; }

  // Inventory object functions
  virtual void collect() = 0;
};