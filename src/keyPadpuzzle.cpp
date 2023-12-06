#include "../include/keyPadpuzzle.hpp"


KeypadPuzzle::KeypadPuzzle(string prompt, int solution) : Puzzle(prompt), solution(solution) {}

bool KeypadPuzzle::solvePuzzle(int userInput) {
    if (userInput == solution) {
        isSolved = true;
        cout << "Correct! The keypad puzzle is solved." << endl;
    } else {
        cout << "Incorrect. The keypad puzzle remains unsolved." << endl;
    }
    return isSolved;
}