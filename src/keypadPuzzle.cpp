#include "../include/keypadPuzzle.hpp"
#include <cassert>

KeypadPuzzle::KeypadPuzzle(string prompt, int solution) : Puzzle(prompt), solution(solution) {}

bool KeypadPuzzle::solvePuzzle(ostream& out, istream& in) {
    int userInput = 0;

    out << getPrompt() << endl << endl;

    out << "> ";
    if (!(in >> userInput)) {
        throw runtime_error("Bad input was detected.");
    }
    out << endl << endl;

    if (userInput == solution) {
        isSolved = true;
        out << "CORRECT. The puzzle is now solved." << endl << endl;
    } else {
        out << "INCORRECT. The puzzle remains unsolved." << endl << endl;
    }

    return isSolved;
}