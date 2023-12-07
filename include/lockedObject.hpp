#pragma once

#include "gameObject.hpp"

class Puzzle;

class lockedObject : public gameObject
{
protected:
  bool isLocked;
  Puzzle *objPuzzle;

public:
  lockedObject(string, string, string, Puzzle *);
  void interact() override;
  bool getLocked() { return isLocked; }
  void setLocked(bool val) { isLocked = val; }
  void unlock(ostream &out);
};