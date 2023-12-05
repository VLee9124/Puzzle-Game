#include "../include/gameTerminal.hpp"

gameTerminal::gameTerminal() {
    Room* room1 = new Room("Start Room", "The beginning of your journey");
    Room* room2 = new Room("End Room", "The end of your journey");
    Door* door1To2 = new Door("door", "this is a door", "the door is unlocked", room2);
    room1->addDoor(door1To2);

    currMap.push_back(room1);
    currMap.push_back(room2);

    currPlayer = Player(currMap.at(0));
}

void gameTerminal::playGame(ostream& out, istream& in) {
    char userInput = '0';

    while (userInput != 'Q') {
        out << "=====================================================" << endl << endl;
        out << currPlayer.getCurrRoom()->getName() << endl << endl;
        out << currPlayer.getCurrRoom()->getDesc() << endl << endl;

        out << "Enter [F] to examine objects" << endl;
        out << "Enter [I] to open inventory" << endl;
        out << "Enter [M] to move to a different room" << endl;
        out << "Enter [Q] to quit to main menu" << endl << endl;

        out << "> ";

        in >> userInput;
    }
}