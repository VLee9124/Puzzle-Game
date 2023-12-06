#pragma once

#include "gameObject.h"

class inventoryObject : public gameObject
{
private:
  string collectionMessage;
  bool collected;

public:
  inventoryObject(string, string, string, string);
  void interact(ostream& out, istream& in) override;
  void collect();
  string getCollectMsg();
};