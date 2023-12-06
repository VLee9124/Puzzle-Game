#include "../include/inventoryObject.h"

inventoryObject::inventoryObject(string name, string description, string interaction, string collectionMessage) : gameObject(name, description, interaction), collectionMessage(collectionMessage), collected(false) {}

void inventoryObject::interact(ostream& out, istream& in)
{
  gameObject::interact(out, in);
  collect();
}

void inventoryObject::collect()
{
  if (!collected)
  {
    collected = true;
  }
}

string inventoryObject::getCollectMsg() {
  return collectionMessage;
}