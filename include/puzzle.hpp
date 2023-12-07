#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Puzzle {
    public:
        Puzzle(string prompt);
        virtual ~Puzzle() {}
        string getPrompt();
        bool getSolved();
        virtual bool solvePuzzle(ostream&, istream&) = 0;
    protected:
        bool isSolved;
        string prompt;
};