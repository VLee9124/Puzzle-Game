#include "../include/lockedObject.h"

lockedObject::lockedObject(string name, string description, string interaction, Puzzle *objPuzzle) : gameObject(name, description, interaction), isLocked(true), objPuzzle(nullptr) {}

void lockedObject::interact()
{
  description = interaction;
  getLocked();
}

void lockedObject::unlock(ostream &out, ifstream &in)
{
}