#pragma once

#include <string>
#include <vector>

using namespace std;

class gameObject
{
protected:
  string name;
  string description;
  string interaction;

public:
  gameObject(string name, string description, string interaction);

  string getName();
  string getDesc();
  string getInteraction();

  void setName(string name);
  void setDesc(string description);
  void setInteraction(string interaction);

  virtual void interact();
};