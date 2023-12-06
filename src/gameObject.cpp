#include "../include/gameObject.h"

// Gameobject functions here:

gameObject::gameObject(string name, string description, string interaction) : name(name), description(description), interaction(interaction) {}

void gameObject::setName(string objectName)
{
  name = objectName;
}

void gameObject::setDesc(string descriptionMsg)
{
  description = descriptionMsg;
}

void gameObject::setInteraction(string interactionMsg)
{
  interaction = interactionMsg;
}

string gameObject::getName()
{
  return name;
}

string gameObject::getDesc()
{
  return description;
}

string gameObject::getInteraction()
{
  return interaction;
}

void gameObject::interact(ostream& out, istream& in)
{
  // We swap original description to interaction message. User is able to see object descriptions from examine(), but we want interaction message to only display when an object chooses to examine it particuarly.
  description = interaction;
}