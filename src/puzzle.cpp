#include "../include/puzzle.hpp"

Puzzle::Puzzle(string prompt) : prompt(prompt), isSolved(false) {}

string Puzzle::getPrompt() {
    return prompt;
}

bool Puzzle::getSolved() {
    return isSolved;
}