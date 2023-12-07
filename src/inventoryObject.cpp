#include "../include/inventoryObject.hpp"

inventoryObject::inventoryObject(string name, string description, string interaction, string collectionMessage) : gameObject(name, description, interaction), collectionMessage(collectionMessage), collected(false) {}

void inventoryObject::interact(ostream& out, istream& in)
{
  gameObject::interact(out, in);
  collect(out);
}

void inventoryObject::collect(ostream& out)
{
  if (!collected)
  {
    out << getCollectMsg() << endl << endl;
    collected = true;
  }
}

bool inventoryObject::checkIfCollected() {
  return collected;
}

string inventoryObject::getCollectMsg() {
  return collectionMessage;
}