#include "../include/gameTerminal.hpp"

// This is a default constructor that simply creates a test situation. FOR TESTING ONLY AND WILL NOT BE USED IN GAME.
gameTerminal::gameTerminal() {
    Room* room1 = new Room("Start Room", "The beginning of your journey.");
    Room* room2 = new Room("End Room", "The end of your journey.");

    Door* door1To2 = new Door("Door to End", "this is a door.", "the door is unlocked.", room2);
    Door* door2To1 = new Door("Door to Start", "this is a door.", "the door is unlocked.", room1);
    room1->addDoor(door1To2);
    room2->addDoor(door2To1);

    inventoryObject* objA = new inventoryObject("Object A", "This is an object.", "The object reads 1929.", "Object A has been collected.");

    currMap.push_back(room1);
    currMap.push_back(room2);

    currPlayer = Player(currMap.at(0));
    currPlayer.getInventory().addItem(objA);
}

gameTerminal::gameTerminal(vector<Room*> importedMap) : currPlayer(importedMap.at(0)), currMap(importedMap) {}

void gameTerminal::playGame(ostream& out, istream& in) {
    char userInput = '0';

    while (userInput != 'Q') {
        out << "=====================================================" << endl << endl;
        
        displayCurrRoom(out);

        out << "Enter [F] to examine objects" << endl;
        out << "Enter [I] to open inventory" << endl;
        out << "Enter [M] to move to a different room" << endl;
        out << "Enter [Q] to quit to main menu" << endl << endl;

        out << "> ";
        in >> userInput;
        out << endl;

        if (userInput == 'I') {
            proceedToOpenInventory(out, in);
        }
        if (userInput == 'M') {
            proceedToMoveTo(out, in);
        }
    }
}

void gameTerminal::displayCurrRoom(ostream& out) {
    out << currPlayer.getCurrRoom()->getName() << endl << endl;
    out << currPlayer.getCurrRoom()->getDesc() << endl << endl;
}

void gameTerminal::proceedToOpenInventory(ostream& out, istream& in) {
    char userInput = '0';

    while (userInput != 'Q') {
        out << "=====================================================" << endl << endl;
        out << "INVENTORY" << endl << endl;

        if (currPlayer.getInventory().itemCount() <= 0) {
            out << "There are no objects in your inventory right now" << endl;
            break;
        }

        out << "The following objects are in your inventory right now:" << endl;
        for (unsigned i = 0; i < currPlayer.getInventory().itemCount(); ++i) {
            out << to_string(i + 1) << ". " << currPlayer.getInventory().getInventoryContents().at(i)->getName() << endl;
        }

        out << endl << "Enter the corresponding number to observe an object" << endl;
        out << "Enter [Q] to go back" << endl << endl;

        out << "> ";
        in >> userInput;
        out << endl;

        if (0 < int(userInput - '0') && int(userInput - '0') <= 9) {
            if (int(userInput - '0') > currPlayer.getInventory().itemCount()) {
                out << "The number is invalid because it is out of the inventory range" << endl;
            }
            else {
                out << currPlayer.getInventory().getItemFromInventory(int(userInput - '0') - 1)->getDesc() << endl;
            }
            out << endl;
        }
    }
}

void gameTerminal::proceedToMoveTo(ostream& out, istream& in) {
    char userInput = '0';

    while (userInput != 'Q') {
        out << "=====================================================" << endl << endl;
        out << "MOVING TO A DIFFERENT ROOM" << endl << endl;

        out << "You are currently in: " << currPlayer.getCurrRoom()->getName() << endl << endl;

        if (currPlayer.getCurrRoom()->getAdjacentRooms().size() <= 0) {
            out << "There are no adjacent doors next to the current room" << endl;
            break;
        }

        out << "The following rooms can be accessed from here:" << endl;
        for (unsigned i = 0; i < currPlayer.getCurrRoom()->getAdjacentRooms().size(); ++i) {
            out << to_string(i + 1) << ". " << currPlayer.getCurrRoom()->getAdjacentRooms().at(i)->getName() << endl;
        }

        out << endl << "Enter the corresponding number to move to a room" << endl;
        out << "Enter [Q] to go back" << endl << endl;

        out << "> ";
        in >> userInput;
        out << endl;

        if (0 < int(userInput - '0') && int(userInput - '0') <= 9) {
            if (int(userInput - '0') > currPlayer.getCurrRoom()->getAdjacentRooms().size()) {
                out << "The number is invalid because it is out of the room list range" << endl;
            }
            else {
                currPlayer.setCurrRoom(currPlayer.getCurrRoom()->getAdjacentRooms().at(int(userInput - '0') - 1)->getAdjacentRoom());
            }
            out << endl;
        }
    }
}