#include "../include/gameTerminal.hpp"
#include <typeinfo>

gameTerminal::gameTerminal(const vector<Room*>& importedMap) : currPlayer(importedMap.at(0)), currMap(importedMap) {}

gameTerminal::~gameTerminal() {
    for (auto room : currMap) {
        delete room;
    }
}

void gameTerminal::playGame(ostream& out, istream& in) {
    char userInput = '0';

    while (toupper(userInput) != 'Q') {
        if (currPlayer.getCurrRoom()->getName() == "End Room") {
            proceedToWinScreen(out, in);
            break;
        }
        out << "=====================================================" << endl << endl;
        
        displayCurrRoom(out);

        out << "Enter [F] to examine objects" << endl;
        out << "Enter [I] to open inventory" << endl;
        out << "Enter [M] to move to a different room" << endl;
        out << "Enter [Q] to quit to main menu" << endl << endl;

        out << "> ";
        in >> userInput;
        out << endl;

        if (toupper(userInput) == 'I') {
            proceedToOpenInventory(out, in);
        }
        else if (toupper(userInput) == 'M') {
            proceedToMoveTo(out, in);
        }
        else if (toupper(userInput) == 'F') {
            proceedToExamineRoom(out, in);
        }
    }
}

void gameTerminal::displayCurrRoom(ostream& out) {
    out << currPlayer.getCurrRoom()->getName() << endl << endl;
    out << currPlayer.getCurrRoom()->getDesc() << endl << endl;
}

void gameTerminal::proceedToOpenInventory(ostream& out, istream& in) {
    char userInput = '0';

    while (toupper(userInput) != 'Q') {
        out << "=====================================================" << endl << endl;
        out << "INVENTORY" << endl << endl;

        if (currPlayer.getInventory().itemCount() <= 0) {
            out << "There are no objects in your inventory right now" << endl << endl;
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

    while (toupper(userInput) != 'Q') {
        out << "=====================================================" << endl << endl;
        out << "MOVING TO A DIFFERENT ROOM" << endl << endl;

        out << "You are currently in: " << currPlayer.getCurrRoom()->getName() << endl << endl;

        if (currPlayer.getCurrRoom()->getAdjacentRooms().size() <= 0) {
            break;
        }

        out << "The room contains the following doors to other rooms:" << endl;
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
            else if (currPlayer.getCurrRoom()->getAdjacentRooms().at(int(userInput - '0') - 1)->getOpen()) {
                currPlayer.setCurrRoom(currPlayer.getCurrRoom()->getAdjacentRooms().at(int(userInput - '0') - 1)->getAdjacentRoom());
                out << "You have successfully moved to the adjacent room: " << currPlayer.getCurrRoom()->getName() << endl;
            }
            else {
                out << "You cannot move to the next room since the door is locked" << endl;
            }
            out << endl;
        }
    }
}

void gameTerminal::proceedToExamineRoom(ostream& out, istream& in) {
    char userInput = '0';

    while (toupper(userInput) != 'Q') {
        out << "=====================================================" << endl << endl;
        out << "EXAMINE CURRENT ROOM" << endl << endl;

        out << "You are currently in: " << currPlayer.getCurrRoom()->getName() << endl << endl;

        if (currPlayer.getCurrRoom()->getAllObjects().size() <= 0) {
            out << "There are no objects to observe here" << endl << endl;
            break;
        }

        for (unsigned i = 0; i < currPlayer.getCurrRoom()->getAllObjects().size(); ++i) {
            out << to_string(i + 1) << ". " << currPlayer.getCurrRoom()->getAllObjects().at(i)->getName() << endl;
        }

        out << endl << "Enter the corresponding number to examine an object" << endl;
        out << "Enter [Q] to go back" << endl << endl;

        out << "> ";
        in >> userInput;
        out << endl;

        if (0 < int(userInput - '0') && int(userInput - '0') <= 9) {
            if (int(userInput - '0') > currPlayer.getCurrRoom()->getAllObjects().size()) {
                out << "The number is invalid because it is out of the object list range" << endl;
            }
            else {
                gameObject* currObj = currPlayer.getCurrRoom()->getObject(int(userInput - '0') - 1);
                out << currObj->getDesc() << endl << endl;
                
                if (currObj->getDesc() != currObj->getInteraction()) {
                    out << "Do you want to interact with this object?" << endl << endl;

                    out << "Enter [Y] to interact with the object" << endl;
                    out << "Enter any other key to decline" << endl << endl;

                    out << "> ";
                    in >> userInput;
                    out << endl;

                    if (toupper(userInput) == 'Y') {
                        currObj->interact(out, in);

                        if (typeid(*currObj).name() == typeid(inventoryObject).name()) {
                            currPlayer.getInventory().addItem(dynamic_cast<inventoryObject*>(currObj));
                            currPlayer.getCurrRoom()->takeObject(currPlayer.getCurrRoom()->searchObject(currObj));
                        }

                        out << currObj->getDesc() << endl << endl;
                    }
                }
            }
        }
    }
}

void gameTerminal::proceedToWinScreen(ostream& out, istream& in) {
    char userInput = '0';
    out << "=====================================================" << endl << endl;

    out << "You escaped from the Puzzle Room!" << endl << endl;

    out << "Enter any key to return to the main menu" << endl << endl;

    out << "> ";
    in >> userInput;
    out << endl;

    out << "=====================================================" << endl << endl;
}