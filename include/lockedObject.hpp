#pragma once

#include "gameObject.hpp"
#include "puzzle.hpp"
#include "keypadPuzzle.hpp"

class lockedObject : public gameObject
{
protected:
  bool isLocked;
  Puzzle* objPuzzle;

public:
  lockedObject(string, string, string, Puzzle *);
  ~lockedObject() { delete objPuzzle; }
  void interact(ostream&, istream&) override;
  bool getLocked() { return isLocked; }
  void setLocked(bool val) { isLocked = val; }
  virtual void unlock(ostream&, istream&);
};