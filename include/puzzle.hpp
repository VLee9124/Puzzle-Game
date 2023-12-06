#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Puzzle {
    public:
        Puzzle(string prompt);
        string getPrompt();
        bool getSolved();
        virtual bool solvePuzzle() = 0;
    protected:
        bool isSolved;
        string prompt;
};