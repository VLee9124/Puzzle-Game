#include "../include/lockedObject.hpp"

lockedObject::lockedObject(string name, string description, string interaction, Puzzle *objPuzzle) : gameObject(name, description, interaction), isLocked(true), objPuzzle(objPuzzle) {}

void lockedObject::interact(ostream& out, istream& in) {
  if (objPuzzle != nullptr) {
      unlock(out, in);
  }
  if (!isLocked) {
    description = interaction;
  }
}

void lockedObject::unlock(ostream& out, istream& in) {
  if (isLocked) {
    if (objPuzzle->solvePuzzle(out, in)) {
      setLocked(false);
    }
  }
}