#ifndef INVENTORY_OBJECT_H
#define INVENTORY_OBJECT_H

#include <string>
#include <vector>
#include "gameObject.h"
using namespace std;

/*An interactable object that can be collected and stored in the inventory.*/
class inventoryObject : public gameObject
{
private:
  bool collected = false;
  string collectionMessage;

public:
  inventoryObject(string name, string description, string interaction) : gameObject(name, description, interaction) {}

  // Getters and setters
  string getCollectionMessage() { return collectionMessage; }
  void setCollectionMessage(string s) { collectionMessage = s; }

  // Inventory object functions

  // void collect();
  
  virtual void interact() {
    // collect();
    gameObject::interact();
  }
};

#endif