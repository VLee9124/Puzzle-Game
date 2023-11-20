#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string>
#include <vector>
using namespace std;

/*General abstract object that can be interacted with. This item cannot be collected.*/
class gameObject
{
protected:
  string name;
  string description;
  string interaction;

public:
  gameObject(string name, string description, string interaction) : name(name), description(description), interaction(interaction) {}

  // Getters and setters
  string getName() { return name; }
  string getDescription() { return description; }
  string getInteraction() { return interaction; }
  void setName(string s) { name = s; }
  void setDescription(string s) { description = s; }
  void setInteraction(string s) { interaction = s; }

  // Game object functions
  virtual void interact() {
    description = interaction;
  }
};

#endif