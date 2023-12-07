#include "../include/gameObject.hpp"

// Gameobject functions here:

gameObject::gameObject(string objectName, string descriptionMsg, string interactionMsg)
{
  name = objectName;
  description = descriptionMsg;
  interaction = interactionMsg;
}

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