#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "puzzle.hpp"
#include "inventoryObject.hpp"

using namespace std;

class KeypadPuzzle : public Puzzle {
    public:
        KeypadPuzzle(string prompt, int solution);
        bool solvePuzzle(ostream&, istream&);
    private:
        int solution;
};

