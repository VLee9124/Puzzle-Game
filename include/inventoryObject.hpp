#pragma once

#include <string>
#include "gameObject.hpp"

using namespace std;

class inventoryObject : public gameObject
{
private:
  string collectionMessage;
  bool collected;

public:
  inventoryObject(string, string, string, string);
  void interact() override;
  void collect();
  string getCollectMsg();
};