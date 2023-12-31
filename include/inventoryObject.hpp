#pragma once

#include <string>
#include "gameObject.hpp"
#include <iostream>
using namespace std;

class inventoryObject : public gameObject
{
private:
  string collectionMessage;
  bool collected;

public:
  inventoryObject(string, string, string, string);
  void interact(ostream& out, istream& in) override;
  void collect(ostream&);
  bool checkIfCollected();
  string getCollectMsg();
};