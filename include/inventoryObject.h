#pragma once

#include "gameObject.h"
#include "inventory.h"

class InventoryObject : public gameObject
{
private:
  string collectionMessage;

public:
  InventoryObject(string name, string description, string interaction, string collectionMessage);
  void interact() override;
  void collect();
};